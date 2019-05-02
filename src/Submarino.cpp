#include "Submarino.hpp"
#include "Barco.hpp"
#include <iostream>
#include <string>

using namespace std;

Submarino::Submarino(int x,int y,char direcao){
	set_nome('S');
	set_x(x);
	set_y(y);
	set_ID('S');
	set_direcao(direcao);
	set_tamanho(2);
	set_vida(4);
	set_segmentos("22");
}

Submarino::Submarino(){
       	set_nome('S');
       	set_x(1);
        set_y(1);
        set_ID('S');
        set_direcao('N');
        set_tamanho(2);
        set_vida(4);
        set_segmentos("22");
}


Submarino::~Submarino(){}


string Submarino::get_segmentos(){
	return segmentos;
}

void Submarino::set_segmentos(string segmentos){
	this -> segmentos=segmentos;
}
	
int Submarino::Tomar_Dano(int x,int y){
	int d;
	string pal;
	d = abs((get_x()-x)+(get_y()-y));
	pal=get_segmentos();
	if(get_vida()==0){
		cout << "SUBMARINO JA DESTRUIDO";
		return 0;
	}

	if(pal[d]=='0'){
		cout << "SEGMENTO JA DESTRUIDO\n";
		return 0;
	}
	set_vida(get_vida()-1);
	pal[d]=pal[d]-1;
	set_segmentos(pal);
	if(get_vida()!=0 and pal[d]!='0')
	cout  << "SUBMARINO ALVEJADO\n";

	else if(get_vida()!=0 and pal[d]=='0')
	cout << "SEGMENTO DE SUBMARINO DESTRUIDO\n";
	
	else{
	cout << "SUBMARINO DESTRUIDO\n";
	return 2;
		}
return 0;
}
