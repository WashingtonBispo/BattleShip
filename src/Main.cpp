#include "Partida.hpp"
#include <iostream>
#include "Layout.hpp"
using namespace std;

int main(){
	system("clear");
	Partida jogo;
	Layout tela;
	tela.grade();
	jogo.preencher(0);
	jogo.Rodada(0);
	jogo.Rodada(0);
	jogo.Rodada(0);
	jogo.Rodada(0);
	jogo.Rodada(0);
	          
return 0;
}
