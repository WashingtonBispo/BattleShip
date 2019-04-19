#include <iostream>
using namespace std;

//Se a função Linha() fosse void o código ficaria maior//

string Linha(){
        cout << "\u2550\u2550\u2550";
        return "";
}


void Grade(){
	
	string Barra= "\u2551";
        string Abre= "\u2560";	
	string Fecha = "\u2563";
	string Cruz = "\u256C";
	string Abre_2 = "\u2566";
	string Fecha_Diagonal ="\u2557";


	cout << "\u2554" << Linha();
	
	for(int x=0;x<12;x++)
		cout << Abre_2 << Linha();
		cout << Fecha_Diagonal << endl ;
	
			
	for(int x=0;x<12;x++){	
		cout  << endl << Abre << Linha();

		for(int y=0;y<12;y++)
			cout << Cruz << Linha();

		cout << Fecha << endl;
	
	}

	cout << endl << "\u255A" << Linha();
	
		
	for(int x=0;x<12;x++)
		cout << "\u2569" << Linha();
	
	cout << "\u255D" << endl;
return;
}
