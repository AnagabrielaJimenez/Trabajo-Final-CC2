#ifndef __CONTROLADORA_H__
#define __CONTROLADORA_H__
#include "Escenario.h"
<<<<<<< HEAD
#include "ArrBombas.h"
#include "Jugador.h"
=======
#include "Jugador.h"
#include "ArrBombas.h"
#include "ArrMejoras.h"
#include "ArrEnemigos.h"
>>>>>>> origin/master
class CControladora
{
	private:
		CControladora *oEscenario;
		CJugador *oJugador;
<<<<<<< HEAD
		CArrBombas* oArrBombas;
=======
		CArrMejoras *oArrMejoras;//agregar
        CArrEnemigos *oArrEnemigos;
		int nivel;
		
		
>>>>>>> origin/master
	public:
		CControladora(){
			oEscenario=new CEscenario();
			oJugador=new CJugador(50,50);
<<<<<<< HEAD
			oArrBombas = new CArrBombas();
=======
			oArrMejoras=new CArrMejoras();
            oArrEnemigos=new CArrEnemigos();
			//agregar
			nivel=1;
>>>>>>> origin/master
		}
		~CControladora(){}
		void CambiarNivel(){//generar mapa
			oEscenario->generarMatriz();
		}
<<<<<<< HEAD
		void agregarBomba() {
			oArrBombas->crear_una_bomba(oJugador->getX(), oJugador->getY());
		}
		void dibujar(Graphics^g,Bitmap^bmpBase,Bitmap^bmpSolido, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, Bitmap^bmpDestruible){
=======
		
		void disminuir_Vidas_Por_Enemigo(){
			for(int i=0;i< oArrBonbas->getarreglo().size();i++)
			{
				
				if(oJugador->retornarRectangulo().IntersectsWith(oArrEnemigos->getarregloEnemigos().at(i)->retornarRectangulo()))
					oJugador->disminuirvidas();
					
			}
			
		}
		void disminuir_Vidas_Por_Bomba(){
			int PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;
		
			for(int i=0;i< oArrBonbas->getarregloBombas().size();i++)
			{
				PuntaIzquierda= OArrBombas->getarregloBombas().at(i)->getX()-100;
				PuntaDerecha= OArrBombas->getarregloBombas().at(i)->getX()+150;
				PuntaSuperior= OArrBombas->getarregloBombas().at(i)->getY()-100;
				PuntaIferior= OArrBombas->getarregloBombas().at(i)->getX()+150;
				CentroInicioY = OArrBombas->getarregloBombas().at(i)->getY();
				CentroInicioX = OArrBombas->getarregloBombas().at(i)->getX();
				CentroFinalX = OArrBombas->getarregloBombas().at(i)->getX() + 50 ;
				CentroFinalY = OArrBombas->getarregloBombas().at(i)->getX() + 50;
			
				if(OArrBombas->getarregloBombas().at(i)->getEstado()== Estado::explocion)
				{
					oJugador->disminuirvidas(PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY,PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX)
				}
			}

		}
		void dibujar(Graphics^g,Bitmap^bmpBase,Bitmap^bmpSolido,Bitmap^bmpDestruible,Bitmap^bmpMejoras, Bitmap^bmpEnemigo){
>>>>>>> origin/master
			oEscenario->PintarBase(g,bmpBase);
			oArrMejoras->dibujar(g,bmpMejoras,oEscenario->getmatriz());
			oEscenario->PintarMatriz(g,Bitmap^bmpSolido,Bitmap^bmpDestruible);
<<<<<<< HEAD
			oJugador->moverJugador(g, bmpJugador, oEscenario->getmatriz()); 
			oArrBombas->dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador->getX(), oJugador->getY(), oEscenario->getmatriz());
=======
			
			oJugador->moverJugador(g, bmpJugador, oEscenario->getmatriz());
			oArrEnemigos->dibujar(g,bmpEnemigo,oEscenario->getmatriz());
			oArrBombas->dibujar_una_bomba(g,bmpBomba,bmpExplosion,oJugador->getX(),oJugador->getY(),oEscenario->getmatriz())
			disminuir_vidas_Por_Bomba();
			disminuir_vidas_Por_Enemigo();
>>>>>>> origin/master
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
		
		
		void agarrarMejoras(){
			for(int i=0 ; i < oArrMejoras->getvector_mejoras().size();i++)
			{
				if(oJugador->retornarRectangulo().IntersectsWith(oArrMejoras->getvector_mejoras().at(i)->))
				{
					switch(oArrMejoras->gervector_mejoras().at->getTipo_de_mejora()){
						case 1://agregar una bomba
							oArrBombas->setBombas(oArrBombas->getBombas()+1);
							break;
						case 2://mover una bomba
				
				
							break;
						case 3://calabera
								oJugador->setVidas(oJugador->getVidas() - 1);
				
							break;
						case 4://patines
				
							Jugador->setAcelerar(oJugador->getAcelerar() + 3);
				
							break;
						case 5://vidas
							oJugador->setVidas(oJugador->getVidas() + 1);
							break;
						default:
							break;
					}
				}
			}
		}
		
};
#endif//falta private
