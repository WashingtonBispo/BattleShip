#include <iostream>
#include "Partida.hpp"
#include "Barco.hpp"
#include "Submarino.hpp"
#include "Porta.hpp"
#include "fstream"
#include "Canoa.hpp"
#include <vector>
#include <stdio.h>

using namespace std;

Partida::Partida(){
	for(int z=0;z<2;z++)
		for(int x=0;x<13;x++)
			for(int y=0;y<13;y++)
				set_m('~',x,y,z);

	for(int z=0;z<2;z++)
                for(int x=0;x<13;x++)
                        for(int y=0;y<13;y++)
       			set_mi('-',x,y,z);
			

	for(int x=0;x<6;x++){
		jone.push_back(new Canoa);
		jtwo.push_back(new Canoa);
	}
	for(int x=0;x<4;x++){
                jone.push_back(new Submarino);
                jtwo.push_back(new Submarino);
	}
	for(int x=0;x<2;x++){
                jone.push_back(new Porta);
                jtwo.push_back(new Porta);
	}



	int x,y;
        char l;
        string t,d;
        ifstream map("doc//map_1.txt");
				
        for(int z=0;z<12;){
                l=map.peek();

               if(l=='#' or l=='\n'){
                        map.ignore(256,'\n');
                        continue;
                }
	
               map >> x >> y >> t >> d;	
               jone[z]->set_x(x);
               jone[z]->set_y(y);
               jone[z]->set_ID(65+z);
               jone[z]->set_direcao(tolower(d[0]));
               Configura_Barco(*jone[z],0);
               z++;
        }

        for(int z=0;z<12;){
                l=map.peek();

                if(l=='#' or l=='\n'){
                        map.ignore(256,'\n');
                        continue;
                }


		

                if(l==EOF)
                        break;

               map >> x >> y >> t >> d;
               jtwo[z]->set_x(x);
               jtwo[z]->set_y(y);
               jtwo[z]->set_ID(65+z);
               jtwo[z]->set_direcao(tolower(d[0]));
                Configura_Barco(*jtwo[z],1);
               z++;
        }

}	

Partida::~Partida(){

}

char Partida::get_m(int x,int y, int z){
	return m[x][y][z];
}

void Partida::set_m(char l,int x,int y,int z){
	this ->	m[x][y][z]=l;
}

char Partida::get_mi(int x,int y, int z){
	return mi[x][y][z];
}

void Partida::set_mi(char l,int x,int y,int z){
	this ->mi[x][y][z]=l;
}

void Partida::preencher(int z){
        printf("%c[%d;%df",0x1B ,2,0);
        string bloco="\u2588";
        for(int x=0;x<13;x++){
                cout << "\u2551";
                for(int y=0;y<13;y++)
                        cout << " " << get_m(x,y,z) <<  " \u2551";
                cout << x << endl << endl;;

                }
	cout << "  ";
	for(int x=0;x<13;x++)
		cout << char(65+x) << "   ";

	cout << endl;
}


void Partida::Configura_Barco(Barco atual,int z){
	int n=1;
	int x,y,tamanho;
	char d,ID;
	
		
	x=atual.get_x();
	y=atual.get_y();
	d=atual.get_direcao();
	ID=atual.get_ID();
	tamanho=atual.get_tamanho();

	if(d=='n'){
                set_mi(ID,x,y,z);
                return;
        }

	if(d=='c' || d=='e')
		n=-1;
	if(d=='c' || d=='b')
		for(int i=0;i<tamanho;i++)
			set_mi(ID,x+(n*i),y,z);
	else
		for(int i=0;i<tamanho;i++)
                        set_mi(ID,x,y+(n*i),z);
}

void Partida::Rodada(int j){
	int x,y;
	char yt;
	char id;
	preencher(j%2);
	cin >> x >> yt;
	yt=toupper(yt);
	y=yt-65;
	id=get_mi(x,y,j%2);
	if(id=='-'){
		cout << "Tiro na agua" << endl;

		return;
	}
	if(j==1)
	jtwo[id-65]->Tomar_Dano(x,y);
	else
	jone[id-65]->Tomar_Dano(x,y);
	
	if(j==1)
        set_m(jtwo[id-65]->get_nome(),x,y,j%2);
        else
        set_m(jone[id-65]->get_nome(),x,y,j%2);


}
	
