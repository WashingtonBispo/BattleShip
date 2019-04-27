#include "Partida.hpp"
#include <iostream>
#include "Layout.hpp"
using namespace std;

int main(){
	system("clear");
	Partida jogo;
	Layout tela;
	tela.grade();
	jogo.Rodada(0);
	jogo.Rodada(1);
	jogo.Rodada(1);
	jogo.Rodada(0);
	jogo.Rodada(1);
	          
return 0;
}
