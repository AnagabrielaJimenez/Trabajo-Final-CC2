#ifndef __CONTROLADORA_H__
#define __CONTROLADORA_H__
#include "Mapa.h"
class CControladora
{
	private:
		CControladora *oEscenario;
		CJugador *oJugador;
	public:
		CControladora(){
			oEscenario=new CEscenario();
			oJugador=new CJugador(50,50);
		}
		~CControladora(){}
		void CambiarNivel(){//generar mapa
			oEscenario->generarMatriz();
		}
		void dibujar(Graphics^g,Bitmap^bmpBase,Bitmap^bmpSolido,Bitmap^bmpDestruible){
			oEscenario->PintarBase(g,bmpBase);
			oEscenario->PintarMatriz(g,Bitmap^bmpSolido,Bitmap^bmpDestruible);
			oJugador->moverJugador(g, bmpJugador, oEscenario->getmatriz()); 
		}
		CJugador *getoJugador(){
			return oJugador;
		}
		
};
#endif
