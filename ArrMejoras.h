#ifndef _ARRMEJORAS_H__
#define _ARRMEJORAS_H__
#include "Mejora.h"
#include <vector>
using namespace std;
class CArrMejoras
{
    private:
        vector<CMejora*>vector_mejoras;
    public:
        CArrMejoras();
        ~CArrMejoras();
        void crearMejoras(){//agregar
            CMejora* nueva_mejora=new CMejora();
            vector_mejoras.push_back(nueva_mejora);
        }
        void dibujar(Graphics^g,Bitmap^bmpMejoras,int **matriz){    
            for (int i = 0; i < vector_mejoras.size(); i++)
            {
                vector_mejoras.at(i)->dibujar(g,bmpMejoras,matriz);
                vector_mejoras.at(i)->animar();
            }
        }
        vector<CMejora*> getvector_mejoras(){
            return vector;
        }
};

#endif