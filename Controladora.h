#ifndef __CONTROLADORA_H__
#define __CONTROLADORA_H__
#include "Escenario.h"
#include "Jugador.h"
#include "ArrBombas.h"
#include "ArrMejoras.h"
#include "ArrEnemigos.h"
class CControladora
{
	private:
		CControladora *oEscenario;
		CJugador *oJugador;
		CArrMejoras *oArrMejoras;//agregar
        CArrEnemigos *oArrEnemigos;
		int nivel;
	public:
		CControladora(){
			oEscenario=new CEscenario();
			oJugador=new CJugador(50,50);
			oArrMejoras=new CArrMejoras();
            oArrEnemigos=new CArrEnemigos();
			//agregar
			nivel=1;
		}
		~CControladora(){}
		void CambiarNivel(){//generar mapa
			oEscenario->generarMatriz();
		}
		void dibujar(Graphics^g,Bitmap^bmpBase,Bitmap^bmpSolido,Bitmap^bmpDestruible,Bitmap^bmpMejoras, Bitmap^bmpEnemigo){
			oEscenario->PintarBase(g,bmpBase);
			oArrMejoras->dibujar(g,bmpMejoras,oEscenario->getmatriz());
			oEscenario->PintarMatriz(g,Bitmap^bmpSolido,Bitmap^bmpDestruible);
			
			oJugador->moverJugador(g, bmpJugador, oEscenario->getmatriz());
			oArrEnemigos->dibujar(g,bmpEnemigo,oEscenario->getmatriz());
			oArrBombas->dibujar_una_bomba(g,bmpBomba,bmpExplosion,oJugador->getX(),oJugador->getY(),oEscenario->getmatriz()) 
		}
		void crear_enemigos_y_mejoras(){
            oArrEnemigos->crearEnemigos();
            oArrMejoras->crearMejoras();
        }
		CJugador *getoJugador(){
			return oJugador;
		}

		CArrMejoras *getoArrMejoras(){
            return oArrMejoras;
        }
		CArrEnemigos * getoArrEnemigos(){
			return  oArrEnemigos;
		}
		int getNivel(){
			return nivel;
		}
		
};
#endif
