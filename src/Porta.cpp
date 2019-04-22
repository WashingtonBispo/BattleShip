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


int Porta::Toma_Dano(int evasiva){
return 0;}
;

