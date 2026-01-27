#ifndef gracz_h
#define gracz_h
#include <string>
#include <vector>
#include <utility>
#include "Statek.h"
#include"Punkt.h"


//klasa Gracz - przechowuje informajcje o id i statkach
using namespace std;
class Gracz{
private:
    int id;
    vector<Statek*> statki;
    vector<vector<string>> plansza;
    vector<Statek*> nowo_zatopione_statki;
    vector<pair<string,string>> nowe_punkty;

    
    
public:
    Gracz(int id_): id(id_),plansza(10, vector<string>(10, " ")) {};
    ~Gracz(){for (Statek* s : statki) { delete s; }} ;
    bool dodaj_statek(Statek* s);
    bool strzal(Punkt* p, Gracz& przeciwnik);
    bool czy_przegrał();
    void rysuj_plansze(bool ukryj_statki);
    int get_id(){return id;};
    void opisz_poprzednia_runde(Gracz& przeciwnik);
    

};
#endif