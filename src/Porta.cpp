#include "Barco.hpp"
#include "Porta.hpp"
#include <iostream>
#include <string>

using namespace std;

Porta::Porta(int x,int y,char direcao) : Barco(x,y,direcao){
	set_nome('P');
	set_ID('P');
	set_tamanho(4);
	set_vida(4);
	set_segmentos("1111");
}

Porta::Porta(){
	set_nome('P');
	set_x(1);
	set_y(1);
	set_direcao('N');
        set_ID('P');
        set_tamanho(4);
        set_vida(4);
        set_segmentos("1111");
}

Porta::~Porta(){}

string Porta::get_segmentos(){
	return segmentos;
}

void Porta::set_segmentos(string segmentos){
	this -> segmentos=segmentos;
}

int Porta::get_evasiva(){
	return evasiva;
}

void Porta::set_evasiva(int evasiva){
	this -> evasiva=evasiva;
}


int Porta::Tomar_Dano(int x,int y){
	srand(time(0));
	if(rand()%4==0){
	cout <<"PORTA-AVIOES INTERCEPTOU O TIRO" << endl;
	return 0;
	    }
	else{
	
	int d;
        string pal;
        d = abs(get_x()+get_y()-y-x);
        pal=get_segmentos();

        if(get_vida()==0){
                cout << "PORTA-AVIOES JA DESTRUIDO";
                return 0;
        }

        if(pal[d]=='0'){
                cout << "SEGMENTO DO PORTA JA DESTRUIDO\n";
                return 0;
        }

        set_vida(get_vida()-1);
        pal[d]--;
        set_segmentos(pal);
	
        if(get_vida()!=0 and pal[d]=='0')
        cout << "SEGMENTO DO PORTA DESTRUIDO\n";

        else{
        cout << "PORTA-AVIOES DESTRUIDO\n";
	return 1;
	}	

return 0;
}

}
