#ifndef statek_h
#define statek_h
#include <string>
#include <vector>
#include "Punkt.h"
using namespace std;
//klasa statek - przechowuje informajce jakie pola statek zajmuje, jaka ma dlugosc i czy zostal zatopiony
class Statek{
private:
    int dlugosc;
    Punkt* poczatek;
    Punkt* koniec;
   
    int trafienia;
    vector<Punkt*> pola;
public:
    Statek(Punkt* poczatek, Punkt* koniec, int trafienia_=0);
    ~Statek(){for (Punkt* p : pola) { delete p; }delete poczatek; delete koniec;}; ;
    bool czy_zatopiony(){return trafienia >= dlugosc; } ;
    int get_dlugosc(){return dlugosc;};
    bool sprawdz_trafenie(Punkt* p);
    vector<Punkt*> get_pola(){return pola;};
    void opisz_statek();
   

};
#endif