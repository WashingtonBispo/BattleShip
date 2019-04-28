#include <iostream>
#include <string>
#include "Jogador.hpp"
using namespace std;


Jogador::Jogador(){
        set_nome("  ");
        set_vida(24);
}       

Jogador::~Jogador(){}

string Jogador::get_nome(){
        return nome;
}

void Jogador::set_nome(string nome){
        this -> nome=nome;
}

int Jogador::get_vida(){
	return vida;
}

void Jogador::set_vida(int vida){
	this ->vida =vida;
}

