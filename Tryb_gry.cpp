#include"Tryb_gry.h"
#include <vector>
#include <string>
#include<iostream>
using namespace std;



Tryb_gry::Tryb_gry(){
    int tryb;
    while(true){
        cout<<"Wybierz tryb gry"<<endl<<"Opcja 1. Klasyczna (wpisz 1) - 1 statek o dlugosci 4, 2 statki o dlugosci 3, 3 statki o dlugosci 2 i 4 o dlugosci 1. Kazdy z graczy ma po 3 strzaly na ture"<<endl;
        cout<<"Opcja 2. Dlugie statki (wpisz 2) - jeden statek o dlugosci 5, po 2 statki o dlugosci 4 i 3. 3 strzaly na ture"<<endl;
        cout<<"Opcja 3. Szybka gra (wpisz 3) - jeden statek o dlugosci 2 i dwa o dlugosci 1. Jeden strzal na ture" <<endl;
        cout<<"Opcja 4. Wlasna gra (wpisz 4) - wlasne zasady - ustawiasz wlasne ilosci statkow i strzalow"<<endl;
        
        cin>>tryb;
        if (tryb>0 && tryb <5){break;}
        cout<<"wybierz poprawny tryb (wpisz liczba od 1 do 4)"<<endl;
    }
    if (tryb ==1){
        statki = {4,3,3,2,2,2,1,1,1,1};
        liczba_strzalow = 3;
    }
    else if (tryb ==2){
        statki = {5,4,4,3,3};
        liczba_strzalow = 3;
    }
    else if (tryb ==3){
        statki = {2,1,1};
        liczba_strzalow = 1;
    }
    else if (tryb ==4)
    {
        int ilosc;
        for (int i =5; i>0;i--){
            cout<<"Podaj ilosc statkow o dlugosci "<<i<<endl;
            cin>>ilosc;
            statki.push_back(ilosc);
        }
        cout<<"Podaj ilosc strzalow na ture"<<endl;
        cin>>ilosc;
        liczba_strzalow = ilosc;
    }
    cout<<"Wybrano tryb "<<tryb<<endl<<"Roczpoczynam rozgrywke"<<endl;
    



}