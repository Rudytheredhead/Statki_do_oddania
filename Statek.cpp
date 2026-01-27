#include"Punkt.h"
#include <iostream>
#include"Statek.h"
using namespace std;

Statek::Statek(Punkt* p, Punkt* k, int trafienia){
    int start_x = p->get_x();
    int start_y = p->get_y();
    int end_x = k->get_x();
    int end_y = k->get_y();
    bool poziom = false;
    //zamiana jesli poczatek jest dalej niz koniec
    if (start_x > end_x){
        swap(start_x, end_x);

        this -> poczatek = k;
        this -> koniec = p;
    }
    else if (start_y > end_y){
        swap(start_y, end_y);   
        this -> poczatek = k;
        this -> koniec = p;
    }
    else{
        this -> dlugosc = abs(end_x - start_x) +1;
        this -> poczatek = p;
        this -> koniec = k;
    }
    //sprawdzanie czy poziomy czy pionowy i obliczanie dlugosci
    if (start_x == end_x){
        poziom = false;
        this -> dlugosc = abs(end_y - start_y) +1;
    }else{
        poziom = true;
        this -> dlugosc = abs(end_x - start_x) +1;
    }
    //dodawanie pol statku do wektora

    for (int i =0; i<dlugosc;i++){
        int x = poczatek->get_x() + (poziom ? i : 0);
        int y = poczatek->get_y() + (poziom ? 0 : i);
        Punkt* pole = new Punkt(x, y);
        pola.push_back(pole);
    }

    this -> trafienia = trafienia;
};
//sprawdza czy punkt p nalezy do tego statku
bool Statek::sprawdz_trafenie(Punkt* p){
    for (Punkt* pole : pola){
        if (*pole == *p){
            trafienia++;
            
            return true;
        }
    }
   
    
    return false;
}
   
void Statek::opisz_statek(){
    cout<<"Statek polozony miedzy "<<poczatek->na_string()<<" a "<<koniec->na_string() <<endl;
}