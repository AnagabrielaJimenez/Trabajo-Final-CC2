#ifndef _MEJOR_H__
#define _MEJOR_H__
#include <ctime>
#include <stdlib.h>
using namespace System::Drawing;

class CMejora
{
    private:
        int i,j;
        int indiceX,  indiceY;
        int ancho, alto;
        int tipo_de_mejora;
        bool ubicado;
    public:
        CMejora(){
            srand(time(NULL));//cambie el rand
            tipo_de_mejora=rand()%5+1;//de 1 a 5
            ubicado=false;
            this->i=rand()%13+1;
            this->j=rand()%15+1;
            this->ancho=128/8;//8=cantidad de figuras
            this->alto=96/6;
            this->indiceX=0;
            this->indiceY=0;
        }
        ~CMejora(){
    	
        }
        
        Rectangle devolcerR(){
			return Rectangle(j* 50 , i * 50 ,ancho*3.125, alto*3.125);
		}
        void dibujar(Graphics^g,Bitmap^bmpMejoras,int **matriz){
            Rectangle porcionAUsar=Rectangle(indiceX*ancho,indiceY*alto,ancho,alto);
            
            while (ubicado==false){//ubicacion a evaluar segun la matriz
                if(matriz[i][j]==3){//si esta en un bloque destructible
                    ubicado=true;
                }
                else{
                    if(j<17){//buscar por filas
                        i++;
                        if(i==14){//ultimo
                            i=0;
                            j++;
                        }
                    }
                }
            }

            Rectangle aumento=Rectangle(j*50,i*50,ancho*3.125,ancho*3.125);//*50 
            g->DrawImage(bmpMejoras,aumento,porcionAUsar,GraphicsUnit::Pixel);
        }
        void animar(){
            switch (tipo_de_mejora)
            {
                case 1://bonba adicinal
                    indiceX=0;
                    if(indiceY>=0 && indiceY<1)
                        indiceY++;
                    else 
                        indiceY=0;
                    break;
                case 2: //mover bonba
                    indiceX=4;
                    if(indiceY>=0 && indiceY<1)
                        indiceY++;
                    else 
                        indiceY=0;
                    break;
                case 3: //calavera , perder vidas
                    indiceX=5;
                    if(indiceY>=0 && indiceY<1)
                        indiceY++;
                    else 
                        indiceY=0;
                    break;            
                case 4: //patines
                    indiceX=8;
                    if(indiceY>=0 && indiceY<1)
                        indiceY++;
                    else 
                        indiceY=0;
                    break;
                case 5: //vidas
                    indiceX=9;
                    if(indiceY>=0 && indiceY<1)
                        indiceY++;
                    else 
                        indiceY=0;
                    break;
            }
        }
        int getTipo_de_mejora(){
			return tipo_de_mejora;
		}
};


#endif
