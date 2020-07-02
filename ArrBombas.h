#ifndef __ARRBOMBAS_H__
#define __ARRBOMBAS_H__
#include "Bomba.h"
#include <vector>
using namespace std;

class CArrBombas
{
private:
    vector<CBomba*>arregloBombas;
    int totalBombas;
public:
    CArrBombas(){ totalBombas = 1;}
    ~CArrBombas(){}
    void crear_una_bomba(int x, int y){
        if(arregloBombas.size() < totalBombas){
            CBomba* nueva_bomba= new CBomba(x,y);
            arregloBombas.push_back(nueva_bomba);
        }
    }
};


//Aún no termino este xdddd
//Pero igual lo subiré al github

#endif // !__ARRBOMBAS_H__X2222222222222222
