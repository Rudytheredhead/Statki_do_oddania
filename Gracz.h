#ifndef gracz_h
#define gracz_h
#include <string>
#include <vector>
#include "Statek.h"
#include"Punkt.h"
using namespace std;
class Gracz{
private:
    int id;
    vector<Statek*> statki;
    vector<vector<string>> plansza;
    
public:
    Gracz(int id_): id(id_),plansza(10, vector<string>(10, " ")) {};
    ~Gracz(){for (Statek* s : statki) { delete s; }} ;
    bool dodaj_statek(Statek* s);
    bool strzal(Punkt* p, Gracz& przeciwnik);
    bool czy_przegrał();
    void rysuj_plansze(bool ukryj_statki);
    int get_id(){return id;};
    

};
#endif