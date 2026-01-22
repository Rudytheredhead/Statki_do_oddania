#ifndef punkt_h
#define punkt_h
#include <string>
using namespace std;
class Punkt{
    private:
        int x;
        int y;
    public:
        Punkt(string wspolrzedne);
        Punkt(int x_, int y_): x(x_), y(y_){};
        ~Punkt(){};
        bool poprawnosc();
        int get_x(){return x;};
        int get_y(){return y;};
        bool operator==(const Punkt& other) const {return (x == other.x) && (y == other.y);};
};
#endif