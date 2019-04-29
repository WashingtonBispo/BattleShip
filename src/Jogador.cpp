#include <iostream>
#include <string>
#include "Jogador.hpp"
using namespace std;


Jogador::Jogador(){
        set_nome("  ");
        set_vida(2,1);
	set_vida(4,2);
	set_vida(6,3);
}       

Jogador::~Jogador(){}

string Jogador::get_nome(){
        return nome;
}

void Jogador::set_nome(string nome){
        this -> nome=nome;
}

int Jogador::get_vida(int pos){
	return vida[pos];
}

void Jogador::set_vida(int vida,int pos){
	this ->	vida[pos] = vida;
}

int Jogador::vida_total(){
	return vida[1]+vida[2]+vida[3];
}
