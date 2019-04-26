#include <iostream>
#include "Barco.hpp"
#include "Canoa.hpp"

using namespace std;

Canoa::Canoa(){}

Canoa::~Canoa(){}

int Canoa::Tomar_Dano(int x,int y){
if(get_vida()==0){
		cout << "Essa canoa ja foi abatida\n";
		return 0;
	}
	cout << "CANOA DESTRUÍDA\n";
	set_vida(get_vida()-1);
	return 1;
}
