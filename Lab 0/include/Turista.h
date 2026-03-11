#include <string>
#include <set>
#include <iostream>


using namespace std;

class Turista
{
private:
    string ci, nombre, email;
public:
    Turista(string, string, string);
    
    string toString();
    set<String> listarExperiencias(DTFecha desde, float min, float max);

    ~Turista();
};
