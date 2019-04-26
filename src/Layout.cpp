#include "Layout.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Layout::Layout(){}

Layout::~Layout(){}


void Layout::gotoxy(int x,int y){
	printf("%c[%d;%df",0x1B ,y,x);
}

string Layout::Linha(){
        cout << "\u2550\u2550\u2550";
        return "";
}

void Layout::grade(){
	gotoxy(0,0);
	string Barra= "\u2551";
        string Abre= "\u2560";
	string Fecha = "\u2563";
	string Cruz = "\u256C";
	string Abre_2 = "\u2566";
	string Fecha_Diagonal ="\u2557";


	cout << "\u2554" << Linha();

	for(int x=0;x<12;x++){
		cout << Abre_2 << Linha();
	}
		cout << Fecha_Diagonal << endl ;


	for(int x=0;x<12;x++){
		cout  << endl << Abre << Linha();

		for(int y=0;y<12;y++)
			cout << Cruz << Linha();

		cout << Fecha  << endl;
		cout << "  "; 
		for(int x=0;x<13;x++)
			cout << x << "   ";
	}

	cout << endl << "\u255A" << Linha();


	for(int x=0;x<12;x++)
		cout << "\u2569" << Linha();

	cout << "\u255D" << endl;
}

void Layout::Faz_Retangulo(int x, int y){
	gotoxy(1,2);
		cout << "\u2554";
		for(int i=0;i<x;i++)
			cout << "\u2550";
		cout << "\u2557" << endl;

		for(int i=0;i<y;i++){
			cout << "\u2551";
			gotoxy(x+2,3+i);
			cout << "\u2551" << endl;
		}

		cout << "\u255A";

		for(int i=0;i<x;i++)
                        cout << "\u2550";
		cout << "\u255D";
}

int Layout::menu(){
	int opc;
	gotoxy(8,5);

	cout << "BATALHA" << endl << "        NAVAL"<<  "\n\n    MORRA  INSETO";
	
	gotoxy(5,11);
        
	cout << "--> Jogar\n";
        cout << "        Comandos\n";
        cout << "\n\n\n	KONAMI";
	
	gotoxy(1,1);
	
	Faz_Retangulo(19,15);
        
	gotoxy(30,30);
	
	scanf("%d",&opc);
	return opc;
}
