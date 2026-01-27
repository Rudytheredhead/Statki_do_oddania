#include<iostream>
#include<string>
#include<vector>
#include <thread> // Biblioteka do obsługi wątków
#include <chrono> // Biblioteka do obsługi jednostek czasu

#include "Punkt.h"
#include "Statek.h"
#include "Gracz.h"
#include "Tryb_gry.h"
using namespace std;

void ruch(Gracz& obecny, Gracz& przeciwnik,int liczba_strzalow){
   
    for (int i =0;i<liczba_strzalow;i++){
        
        //rozpoczyecie tury gracza - czyszczenie ekranu i wyswietlenie plansz
        cout<<"Plansza obecnego gracza:"<<endl;
        obecny.rysuj_plansze(false);
        cout<<"Plansza przeciwnika:"<<endl;
        przeciwnik.rysuj_plansze(true);

    
        string wspolrzedne;
        cout<<"gracz: "<<obecny.get_id()<<endl;
        cout<<"Podaj wspolrzedne strzalu (np. a5): ";
        cin>>wspolrzedne;
        while (true){
        Punkt* p = new Punkt(wspolrzedne);
            if (!p->poprawnosc()){
                cout<<"blad: strzal poza plansza, podaj wspolrzedne ponownie: ";
                cin>>wspolrzedne;

                }
            else if(!obecny.strzal(p, przeciwnik)){
                cin>>wspolrzedne;

            }
            else{delete p; break;}
            
            }
            if (przeciwnik.czy_przegrał()){
                
                return;
        }
        if(i==2){cout<<"oddano juz trzy strzaly. Zmiana gracza";}
        else{cout<<"oddano "<<i+1<<" strzal. Zostalo "<<2-i<<" strzalow";}
        cout<<endl;
        this_thread::sleep_for(1s);// Pauza na 1 sekundy 
    }
    
}

void dodawanie_statkow(Gracz& g,vector<int> statki){
    
    cout<<"Rozpoczynanie ukladania statkow gracza "<<g.get_id()<<endl;

    for (int d : statki){
        while (true){
            cout<<"Ustawia statek gracz "<<g.get_id()<<endl;
            g.rysuj_plansze(false);
            string p_kordy;
            string k_kordy;
            
            cout<<"Podaj poczatkowe i koncowe wspolrzedne statku o dlugosci "<<d<<" (np. a1 a5, albo a1 dla dlugosci 1): "<<endl;
            if (d==1) {
                cin>>p_kordy;
                k_kordy = p_kordy;
            }else{
                cin>>p_kordy>>k_kordy;
            }
            Punkt* p = new Punkt(p_kordy);
            Punkt* k = new Punkt(k_kordy);
            if (!p->poprawnosc() || !k->poprawnosc()){
                cout<<"blad: statek poza plansza, podaj wspolrzedne ponownie."<<endl;
                delete p;
                delete k;
                continue;
            }
            Statek* s = new Statek(p,k);
            if (!g.dodaj_statek(s)){
                cout<<"blad: kolizja z innym statkiem podaj wspolrzedne ponownie."<<endl;
                delete s;
                continue;
            }
            if (s->get_dlugosc() != d){
                cout<<"blad: zla dlugosc statku, podaj wspolrzedne ponownie."<<endl;
                delete s;
                continue;
            }
            break;
           
        }
    }
}


int main(){
    string wygrany;
    Gracz g1(1);
    Gracz g2(2);
    Tryb_gry gra;
    this_thread::sleep_for(1s);
    dodawanie_statkow(g1,gra.get_statki());
    cout<<"ustawiono wszystkie statki. Czas na kolejnego gracza"<<endl;
    this_thread::sleep_for(1s);
    for (int k=0;k<50;k++){
        cout<<endl;
    }
    dodawanie_statkow(g2,gra.get_statki());
    cout<<"obaj gracze ustawili swoje statki. Czas na gre!";
    this_thread::sleep_for(1s);
    for (int k=0;k<50;k++){
        cout<<endl;
    }
    
    while (true){
        ruch(g1, g2,gra.get_liczba_strzalow());
        if(g2.czy_przegrał()){
            wygrany = "1";
            break;}
        for (int k=0;k<100;k++){
            cout<<" "<<endl;
        }
        
        g2.opisz_poprzednia_runde(g1);
        this_thread::sleep_for(1s);
        ruch(g2, g1,gra.get_liczba_strzalow());
        if(g1.czy_przegrał()){
            wygrany = "2";
            break;}
        for (int k=0;k<100;k++){
            cout<<" "<<endl;
        }
        g1.opisz_poprzednia_runde(g2);
        this_thread::sleep_for(1s);
        
    }

   cout<<"Koniec gry! Wygrywa gracz o id: "<<wygrany<<endl;
   cout<<"plansza gracza 1:"<<endl;
   g1.rysuj_plansze(false);
    cout<<"plansza gracza 2:"<<endl;
    g2.rysuj_plansze(false);


   cout<<"Dziekuje za gre!"<<endl;

    return 0;
};