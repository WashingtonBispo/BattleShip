#include "Barco.hpp"
#include <iostream>

using namespace std;

Barco::Barco(int x, int y,char direcao){
	set_x(x);
	set_y(y);
	set_direcao(direcao);
	set_ID('C');
	set_vida(1);
	set_tamanho(1);

}


Barco::~Barco(){
}

int Barco::get_x(){
	return x;
}

void Barco::set_x(int x){
	this -> x=x;
}

int Barco::get_y(){
	return y;
}

void Barco::set_y(int y){
	this -> y=y;
}	

char Barco::get_ID(){
	return ID;
}
	
void Barco::set_ID(char ID){
	this -> ID=ID;
}

int Barco::get_tamanho(){
	return tamanho;
}
		
void Barco::set_tamanho(int tamanho){
	this -> tamanho=tamanho;
}

char Barco::get_direcao(){
	return direcao;
}

void Barco::set_direcao(char direcao){
	this -> direcao=direcao;
}

int Barco::get_vida(){
	return vida;
}

void Barco::set_vida(int vida){
	this -> vida=vida;
}
		
int Barco::Toma_Dano(int vida){
	cout << "CANOA DESTRUÍDA\n";
	vida =get_vida()-1;
	return vida;
}


