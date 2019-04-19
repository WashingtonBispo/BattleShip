#include <iostream>
#include "Layout_Jogo.cpp"
#include "Utilidade.cpp"
#include "Barco.hpp"
#include "Submarino.hpp"

int main(){
	int d;
	Barco canoa1(1,2,'m');
	d= canoa1.Toma_Dano(canoa1.get_vida());
	cout << d;
return 0;
}
