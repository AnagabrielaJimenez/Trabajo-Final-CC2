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
		CControladora *oControladora=new CControladora();
		Bitmap^bmpSolido=gcnew Bitmap("Imagenes\\bmpSolido.png");
		Bitmap^bmpDestruible=gcnew Bitmap("Imagenes\\bmpDestruible.png");
		Bitmap^bmpSuelo=gcnew Bitmap("Imagenes\\bmpSuelo.png");
		Bitmap^bmpJugador=gcnew Bitmap("Imagenes\\jugador.png");
		Bitmap^bmpBomba = gcnew Bitmap("Imagenes\\bomba.png");
		Bitmap^ bmpExplosion = gcnew Bitmap("Imagenes\\explosion.png");
	public:	
		Juego(void){
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(0,0));
			bmpBomba->MakeTransparent(bmpBomba->GetPixel(0, 0));
			bmpExplosion->MakeTransparent(bmpExplosion->GetPixel(0, 0));
			InitialieComponent();
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
	private: System::Windows::Form::Timer^ timer1;
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
			
			oControladora->dibujar(buffer->Graphics,bmpSuelo,bmpSolido, bmpBomba, bmpExplosion,bmpDestruible,bmpJugador);
			buffer->Render(g);
			delete buffer, espacio, g;
		}	
		private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e){
			oControladora->CambiarNivel();
		}
		private:System::Void MantenerTecla(System::Object^ sender,System::Windows::Forms::KeyEventArgs^ e){
			swich(e->KeyCode)
			{
			case Keys::Space:
				oControladora->agregarBomba();
				break;
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
	};
}
		
		
		
		
		
		
		
}
