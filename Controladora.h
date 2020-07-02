#ifndef __CONTROLADORA_H__
#define __CONTROLADORA_H__
#include "Escenario.h"
#include "ArrBombas.h"
#include "Jugador.h"
class CControladora
{
	private:
		CControladora *oEscenario;
		CJugador *oJugador;
		CArrBombas* oArrBombas;
	public:
		CControladora(){
			oEscenario=new CEscenario();
			oJugador=new CJugador(50,50);
			oArrBombas = new CArrBombas();
		}
		~CControladora(){}
		void CambiarNivel(){//generar mapa
			oEscenario->generarMatriz();
		}
		void agregarBomba() {
			oArrBombas->crear_una_bomba(oJugador->getX(), oJugador->getY());
		}
		void dibujar(Graphics^g,Bitmap^bmpBase,Bitmap^bmpSolido, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, Bitmap^bmpDestruible){
			oEscenario->PintarBase(g,bmpBase);
			oEscenario->PintarMatriz(g,Bitmap^bmpSolido,Bitmap^bmpDestruible);
			oJugador->moverJugador(g, bmpJugador, oEscenario->getmatriz()); 
			oArrBombas->dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador->getX(), oJugador->getY(), oEscenario->getmatriz());
		}
		CJugador *getoJugador(){
			return oJugador;
		}
		
};
#endif
