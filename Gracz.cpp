#include"Punkt.h"
#include <iostream>
#include <vector>
#include <utility>

#include"Statek.h"
#include"Gracz.h"
using namespace std;
bool Gracz::dodaj_statek(Statek* s){
    //sprawdzanie czy statek koliduje z innymi statkami
     
    for (Punkt* p : s->get_pola()){
        if (plansza[p->get_y()][p->get_x()] == "*"){
            cout<<"blad: w to pole juz zostal oddany strzal"<<endl;
            return false;
        }else if (plansza[p->get_y()][p->get_x()] != " "){
            cout<<"blad: statek koliduje z innym statkiem"<<endl;
            return false;
        }
        
              
              

        }
    
    statki.push_back(s);
    //oznaczanie pol statku na planszy
    for (Punkt* p : s->get_pola()){
        plansza[p->get_y()][p->get_x()] = "O";
    }
    //dodawanie zajetych pol do wektora
     for (Punkt* p : s->get_pola()){
        for (int x=-1;x<=1;x++){
            for (int y=-1;y<=1;y++){

                int x_spr = p->get_x() + x;
                int y_spr = p->get_y() + y;
                if (x_spr < 0 || y_spr < 0 || x_spr > 9 || y_spr > 9){
                    continue;
                }
                if (plansza[y_spr][x_spr] == " "){
                    plansza[y_spr][x_spr] = "nie_dostepne"; //pola w ktorych nie moze byc nowego statku, ale nie wyswietlaja sie jakos zajete podczas rozgrywki
                }


            }
        }
    }
    return true;
}

bool Gracz::strzal(Punkt* p, Gracz& przeciwnik){
    
    if (!p->poprawnosc()){
        cout<<"blad: strzal poza plansza"<<endl;
        return false;
    }
    if ( przeciwnik.plansza[p->get_y()][p->get_x()] == "X" || przeciwnik.plansza[p->get_y()][p->get_x()] == "*"|| przeciwnik.plansza[p->get_y()][p->get_x()] == "ulatwione"){
        cout<<"to pole bylo juz trafione, oddaj strzal ponownie"<<endl;
        return false;
    }
    for (Statek* s : przeciwnik.statki){
        if (s->sprawdz_trafenie(p)){
            cout<<"trafiony !"<<endl;
            
            przeciwnik.plansza[p->get_y()][p->get_x()] = "X";
            
            przeciwnik.nowe_punkty.push_back({p->na_string(),"trafienie"});
            

            
            if(s->czy_zatopiony()){
                cout<<"zatopiony!"<<endl;
                //oznaczanie pol wokol statku jako trafione
                for (Punkt* p_statku : s->get_pola()){
                    for (int x=-1;x<=1;x++){
                        for (int y=-1;y<=1;y++){

                            int x_spr = p_statku->get_x() + x;
                            int y_spr = p_statku->get_y() + y;
                            if (x_spr < 0 || y_spr < 0 || x_spr > 9 || y_spr > 9){
                                continue;
                            }
                            if (przeciwnik.plansza[y_spr][x_spr] == " " || przeciwnik.plansza[y_spr][x_spr] == "nie_dostepne"){
                                przeciwnik.plansza[y_spr][x_spr] = "ulatwione"; //pola obok statku ktore bede widoczne jakby gracz oddal w nie juz strzal w celu ulatwienia rozgrywki. Nie pokazuja sie na swojej planszy
                            }
                        }       
                    }
                }
                
            }
            return true;
        }
        
    }
    cout<<"pudlo!"<<endl;

    przeciwnik.plansza[p->get_y()][p->get_x()] = "*";
    przeciwnik.nowe_punkty.push_back({p->na_string(),"pudlo"});
    return true;
}
bool Gracz::czy_przegrał(){
    for (Statek* s : statki){
        if (!s->czy_zatopiony()){
            return false;
        }
    }
    return true;
}

void Gracz::rysuj_plansze(bool ukryj_statki){
    cout<<endl;
    for (int i = 0;i<30;i++){
        cout<<"_";
    }
    
    cout<<"  ";
    cout<<endl;
    for (int i=0;i<10;i++){
        cout<<" "<<char(i+'a');
    }
    cout<<endl;
    for (int j =0;j<10;j++){
        int k =0;
        if (j+1==10){
            cout<<10;
        }
        else{cout<<char(j+'1')<<" ";}
        
        for (int i =0;i<10;i++){
            string a;
            if (plansza[j][i]==" "){
                a=" ";
            }else if(plansza[j][i]=="*"){
                a="*";
            }else if(plansza[j][i]=="X"){
                a="X";
            }else if(plansza[j][i]=="O"){
                if (ukryj_statki){
                    a=" ";
                }else{a="O";}
            }
            else if(plansza[j][i]=="nie_dostepne"){
                a = " ";
                
            }
            else if(plansza[j][i]=="ulatwione"){
                if (ukryj_statki){
                    a="*";
                }else{a=" ";}
            }  
            if(k==9){
                cout<<"|"<<a<<"|";
            }
            else{cout<<"|"<<a;}
            k++;
        }
        cout<<endl;

    }
    for (int i = 0;i<30;i++){
        cout<<"_";
    }
    cout<<endl;
}


void Gracz::opisz_poprzednia_runde(Gracz& przeciwnik){
    
    vector<int> trafienia;
    vector<int> pudla;

    
    cout<<"w poprzednim ruchu gracz "<<przeciwnik.id<<" :"<<endl;
    for(Statek* s:nowo_zatopione_statki){
        cout<<"Zatopil ";
        s->opisz_statek();

    }

    for (int i = 0; i<nowe_punkty.size();i++){
        
        if( nowe_punkty[i].second == "trafienie"){
            trafienia.push_back(i);
        }
        if( nowe_punkty[i].second == "pudlo"){
            pudla.push_back(i);
        }
    }
    if(trafienia.size()==0){cout<<"nie trafil rzadnego statku"<<endl;}
    else{
        cout<<"tarfil "<<trafienia.size()<<" statki na polach: ";
        for (int idx:trafienia){
            cout<<nowe_punkty[idx].first<<" ";
        }
        cout<<endl;
    }
    cout<<"strzelil nie celnie "<<pudla.size()<<" razy, na polach: ";
    for (int idx:pudla){
        cout<<nowe_punkty[idx].first<<" ";
    }
    cout<<endl;
    trafienia.clear();
    pudla.clear();
    nowe_punkty.clear();




}