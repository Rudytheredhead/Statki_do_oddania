#include"Punkt.h"
#include <iostream>
#include <string>
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
string Punkt::na_string(){
    
    char znak  = x + 'a';
    char znak2 = y + '1';
    
    string text;
    text += znak;
    text += znak2;
    
    return text;

}

