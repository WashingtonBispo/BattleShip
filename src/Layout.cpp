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
	for(int x=1;x<8;x+=3)
	Faz_Retangulo(33,1,59,x);

	Faz_Retangulo(33,2,59,10);
	Faz_Retangulo(33,12,59,14);
	
	Faz_Retangulo(33,15,95,1);
	preencher();
}

void Layout::Faz_Retangulo(int x, int y,int x2, int y2){
	gotoxy(x2,y2);

        cout << "\u2554";

        for(int i=0;i<x;i++)
                cout << "\u2550";

        cout << "\u2557" << endl;

        for(int i=1;i<=y;i++){
                gotoxy(x2,y2+i);
                cout << "\u2551";
                gotoxy(x2+x+1,y2+i);
                cout << "\u2551";
        }

        gotoxy(x2,y2+y+1);
        cout << "\u255A";

        for(int i=0;i<x;i++)
                cout << "\u2550";
        cout << "\u255D";

}

void Layout::preencher(){
	gotoxy(60,2);
	cout << "VEZ DO JOGADOR:";
	gotoxy(60,5);
	cout << "LINHA PARA ATAQUE: ";
	gotoxy(60,8);
	cout << "COLUNA PARA ATAQUE: ";
	gotoxy(60,11);
	cout << "RELATORIO DE DISPARO:";
	
	gotoxy(60,15);
	cout << "SIMBOLOS";
	
	gotoxy(60,16);
	cout << "~ -> TERRENO DESCONHECIDO";
	
	gotoxy(60,17);
	cout << "- -> AGUA";
	
	gotoxy(60,18);
	cout << "P -> PORTA_AVIAO";
	
	gotoxy(60,19);
	cout << "S -> SUBMARINO";
	
	gotoxy(60,20);
	cout << ("C -> CANOA");

	gotoxy(60,22);
	cout << "PODER - PORTA-AVIAO";
	gotoxy(60,23);
	cout << "PODE INTERCEPTAR DISPAROS";

	 gotoxy(60,25);
        cout << "PODER - SUBMARINO";
        gotoxy(60,26);
        cout << "2 VIDAS POR SEGMENTO";
	
return;
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
	
	Faz_Retangulo(19,15,1,1);
        
	gotoxy(30,30);
	
	scanf("%d",&opc);
	return opc;
}

 
