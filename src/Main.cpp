#include "Partida.hpp"
#include <iostream>
#include "Layout.hpp"
using namespace std;

int main(){
	int opc;
	system("clear");
	Layout tela;	
	opc=tela.menu();
		
	if(opc==1){
		system("clear");
		Partida jogo;
		tela.grade();
		jogo.Jogo();
		return 0;
	}
	if(opc==2) cout << "Entao pq abriu o programa?" << endl;
	          
return 0;
}
