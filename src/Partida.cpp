#include <iostream>
#include "Partida.hpp"

using namespace std;

Partida::Partida(){
	for(int z=0;z<2;z++)
		for(int x=0;x<13;x++)
			for(int y=0;y<13;y++)
				set_m('-',x,y,z);

	for(int z=0;z<2;z++)
                for(int x=0;x<13;x++)
                        for(int y=0;y<13;y++)
                                set_mi('A',x,y,z);
}

Partida::~Partida(){}

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

void Partida::Configura_Barco(int x,int y,int z,char d,char ID,int tamanho){
	int n=1;
	if(d=='c' || d=='e')
		n=-1;
	if(d=='c' || d=='b')
		for(int i=0;i<tamanho;i++)
			set_mi(ID,x+(n*i)-1,y-1,z);
	else
		for(int i=0;i<tamanho;i++)
                        set_mi(ID,x-1,y+(n*i)-1,z);
}
