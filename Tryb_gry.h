#ifndef gra_h
#define gra_h
#include <string>
#include <vector>

using namespace std;

class Tryb_gry{
private:
    vector<int> statki;
    int liczba_strzalow;
public:
    Tryb_gry();
    vector<int> get_statki(){return statki;};
    int get_liczba_strzalow(){return liczba_strzalow;};

};
#endif