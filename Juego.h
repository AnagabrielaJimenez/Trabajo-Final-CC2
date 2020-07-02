#pragma once
#include "Controladora.h"
namespace JuegoBomberman{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	public ref class Juego:public System::Windows::Forms
	{
	private:
		CControladora *oControladora;
		Bitmap^bmpSolido=gcnew Bitmap("Imagenes\\bmpSolido.png");
		Bitmap^bmpDestruible=gcnew Bitmap("Imagenes\\bmpDestruible.png");
		Bitmap^bmpSuelo=gcnew Bitmap("Imagenes\\bmpSuelo.png");
		Bitmap^bmpJugador=gcnew Bitmap("Imagenes\\jugador.png");
		Bitmap^bmpBomba=gcnew Bitmap("Imagenes\\bomba.png");
		Bitmap^bmpExprosion=gcnew Bitmap("Imagenes\\exposion.png");
		Bitmap^bmpMejoras=gcnew Bitmap("Imagenes\\bmpMejoras.png");
		Bitmap^bmpEnemigo=gcnew Bitmap("Imagenes\\bmpEnemigo.png");
	public:
		Juego(void){

			InitialieComponent();
			oControladora=new CControladora();
			//falta bomba
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(0,0));
			bmpEnemigo->MakeTransparent(bmpEnemigo->GetPixel(0,0));
			
		}	
	}
	protected:
		<sumary>
		</sumary>
		~Juego(){
			if(components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbNivel;
	private: System::Windows::Forms::ProgressBar^ pbCarga;
	private: System::Windows::Forms::Timer^ trcarga;
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContanier^ components;
	
	private:
		<sumary>
		</sumary>
		
		void InitializeComponent(void){
			this->components=(gcnew System::ComponentModel::Container());
			this->timer1=(gcnew System::Windows::Form::Timer(this->components));
			this->SuspendLayout();
			
			this->timer1->Enabled=true;
			this->timer1->Tick +=gcnew System::EventHandler(this,&Juego::timer1_Tick);
		
			this->AutoScaleDimensions=System::Drawing::SizeF(6,13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize=System::Drawing::Size(450,402);
			this->Name=L"Juego";
			this->Text=L"Juego";
			this->Load+= gcnew System::EventNandler(this,&Juego::Juego_Load);
		}	this->ResumeLayout(false);

	#pragma endregion
		private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e){
			Graphics ^g=this->CreateGraphics();
			BufferedGraphicsContext^espacio= BufferedGraphicsManager::Current;
			BufferedGraphics^buffer= espacio->Allocate(g,this->ClientRectangle);
			
			oControladora->dibujar(buffer->Graphics,bmpSuelo,bmpSolido,bmpDestruible,bmpJugador,bmpMejoras,bmpEnemigo);
			this->Text=""+oControladora->getojugador()->getVidas();
			buffer->Render(g);
			delete buffer, espacio, g;
		}	
		private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e){
			lblNivel->Text="Nivel: "+ oControladores->getNivel();
			oControladora->CambiarNivel();
		}
		private:System::Void MantenerTecla(System::Object^ sender,System::Windows::Forms::KeyEventArgs^ e){
			swich(e->KeyCode)
			{
			case Keys::Up:
				oControladora->getoJugador()->setDireccion(Direcciones::Arriba);
				break;
			case Keys::Down:
				oControladora->getoJugador()->setDireccion(Direcciones::Abajo);
				break;
			case Keys::Left:
				oControladora->getoJugador()->setDireccion(Direcciones::Izquierda);
				break;
			case Keys::Right:
				oControladora->getoJugador()->setDireccion(Direcciones::Derecha);
				break;
			default:
				break;
			}
		}
		private: System::Void UltimaTeclaPresionada(System::Object^ sender,System::Windows::Forms::KeyEventArgs^ e){
			switch(e->KeyCode)
			{
				default:
					oControladora->getoJugador()->setDireccion(Direcciones::Ninguna);
					break;
			}
		}
		/* //
		lblNivel->Text="Nivel: "+ oControladores->getNivel();
		pbCarga->Increment(10);
		if(trCarga->Interval ==2500 && oControladora->getoArrMejoras()->getvector_mejoras().size()<oControladora->getNivel()){
			oControladora->crear_enemigos_y_mejoras();
		}
		else {
			trCarga->Enabled=false;
		
		}
		*/
};

		
		
		
		
		
		
		

