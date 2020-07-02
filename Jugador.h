#ifndef _JUGADOR_H_
#define _JUGADOR_H_

class CJugador
{
	public:
		CJugador(int x,int y){
			this->x=x;
			this->y=y;
			
			dx=0;
			dy=0;
			
			ancho=18;
			alto=26;
			
			indiceX=0;
			indiceY=0;
			
			direccion=Direcciones::Ninguna;
			ultima=Direcciones::Abajo;
		}
		~CJugador(){}
		void setDireccion(Direcciones direccion){
			this->direccion=direccion;
		}
		
		void dibujarJugador(Graphics^g,Bitmap^bmpJugador){
			Rectangle PorcionAUsar=Rectangle(indiceX*ancho,indiceY*alto,ancho, alto);
			Rectangle Aumento=Rectangle(x,y,ancho*3,alto*3);
			g->DrawImage(bmpJugador,Aumento,PorcionUsar,GraphicsUnit::Pixel);
			x+=dx;
			y+=dy;
		}	
		
		void moverJugador(Graphics^g,Bitmap^bmpJugador){
			direccion==Arriba ? ancho=17 : ancho=18;
			switch(direccion)
			{
				case Direcciones::Arriba:
					indiceY=0;
					if(indiceX>=1 && indiceX<3)
						indiceX++;
					else
						indiceX=1;
					dx=0;
					dy=-10;
					ultima=Arriba;
					break;
				case Direcciones::Abajo:
					indiceX=0;
					if(indiceY >=1 && indiceY <3)
						indiceY++;
					else
						indiceY=1;
					dx=0;
					dy=10;
					ultima=Abajo;
					break;
				case Direcciones::Izuierda:
					indiceY=3;
					if(indiceX >=1 && indiceX <3)
						indiceX++;
					else
						indiceX=1;
					dx=-10;
					dy=0;
					ultima=Izquierda;
					break;
				case Direcciones::Derecha:
					indiceY=3;
					if(indiceX >=1 && indiceX <3)
						indiceX++;
					else
						indiceX=1;
					dx=10;
					dy=0;
					ultima=Derecha;
					break;
				case Direcciones::Ninguna:
					dx=dy=0;
					if(ultima==Direcciones::Abajo){
						indiceX=0;
						indiceY=2;
					}
					if(ultima==Direcciones::Arriba){
						indiceX=0;
						indiceY=0;
					}
					if(ultima==Direcciones::Derecha){
						indiceX=1;
						indiceY=1;
					}
					if(ultima==Direcciones::Iizquierda){
						indiceX=1;
						indiceY=3;
					}
					break;
				default:
					break;
			}
			dibujarJugador(g,bmpJugador);
		}
	
	private:
		int x;
		int y;
		int x;
		int dx;
		int dy;
		int ancho;
		int alto;
		int indiceX;
		Direcciones direccion;
		Direcciones ultima;		
		
}
