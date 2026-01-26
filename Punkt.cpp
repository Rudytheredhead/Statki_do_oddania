#include"Punkt.h"
#include <iostream>
using namespace std;
//zmiana stringu wprowadzanego przez uzytkowanika na int x,y
Punkt::Punkt(string wspolrzedne){
   int x = wspolrzedne[0]-'a';
   int y = wspolrzedne[1]-'1';
   if (wspolrzedne.length()==3 && wspolrzedne[2]=='0'){
       y=9;
   }
   this -> x = x;
   this -> y = y;   
}
//sprawdzania czy punkt jest poprawny(czy znajduja sie na planszy)
bool Punkt::poprawnosc(){
    
    if ((x<0 || x>9)||(y<0 || y>9)){
        return false;
    }else{
        return true;
    }
}
