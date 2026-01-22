#include<iostream>
#include<string>
#include<vector>
#include <thread> // Biblioteka do obsługi wątków
#include <chrono> // Biblioteka do obsługi jednostek czasu

#include "Punkt.h"
#include "Statek.h"
#include "Gracz.h"
using namespace std;

void ruch(Gracz& obecny, Gracz& przeciwnik){
   
    for (int i =0;i<3;i++){
        for (int k=0;k<100;k++){
            cout<<endl;
        }
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
        this_thread::sleep_for(1s);// Pauza na 1 sekundy
    }
    
}

void dodawanie_statkow(Gracz& g){
    vector<int> dlugosci = {1,1,1,1,2,2,2,3,3,4};
    

    for (int d : dlugosci){
        while (true){
            cout<<"gracz "<<g.get_id()<<endl;
            g.rysuj_plansze(false);
            string p_kordy;
            string k_kordy;
            
            cout<<"Podaj poczatkowe i koncowe wspolrzedne statku o dlugosci "<<d<<" (np. a1 a5, albo a1 dla dlugosci 1): ";
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
    dodawanie_statkow(g1);
    for (int k=0;k<50;k++){
        cout<<endl;
    }
    dodawanie_statkow(g2);
    for (int k=0;k<50;k++){
        cout<<endl;
    }
    while (true){
        ruch(g1, g2);
        if(g2.czy_przegrał()){
            wygrany = "1";
            break;
        }
        ruch(g2, g1);
        if(g1.czy_przegrał()){
            wygrany = "2";
            break;}
    }

   cout<<"Koniec gry! Wygrywa gracz o id: "<<wygrany<<endl;
   cout<<"plansza gracza 1:"<<endl;
   g1.rysuj_plansze(false);
    cout<<"plansza gracza 2:"<<endl;
    g2.rysuj_plansze(false);


   cout<<"Dziekuje za gre!"<<endl;

    return 0;
};