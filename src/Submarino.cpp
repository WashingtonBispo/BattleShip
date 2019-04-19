#include "Submarino.hpp"
#include "Barco.hpp"


#include <iostream>
#include <string>

using namespace std;

Submarino::Submarino(int x,int y,char direcao) : Barco(x,y,direcao){
	set_x(x);
	set_y(y);
	set_ID('S');
	set_direcao(direcao);
	set_tamanho(2);
	set_vida(2);
	set_segmentos("22");
}

Submarino::~Submarino(){}

int Submarino :: Poder(int vida){
	return vida*2;
}

string Submarino::get_segmentos(){
	return segmentos;
}

void Submarino::set_segmentos(string segmentos){
	this -> segmentos=segmentos;
}
	
int Submarino::Toma_Dano(int vida){
}
