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
		jtwo.push_back(new Canoa);
		jone.push_back(new Canoa);
	}
	for(int x=0;x<4;x++){
                jone.push_back(new Submarino);
                jtwo.push_back(new Submarino);
	}
	for(int x=0;x<2;x++){
                jone.push_back(new Porta);
                jtwo.push_back(new Porta);
	}

	Configura_Lista(jtwo,Configura_Lista(jone,0,1),0);
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
                cout << x << endl << endl;

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

int Partida::Configura_Lista(vector<Barco*>j,int a,int lugar){
int x,y;
        char l;
        string t,d;
 	ifstream map("doc//map_1.txt");
	map.seekg(a);
        for(int z=0;z<12;){
                l=map.peek();

               if(l=='#' or l=='\n'){
                        map.ignore(256,'\n');
                        continue;
                }
	
               map >> x >> y >> t >> d;	
               j[z]->set_x(x);
               j[z]->set_y(y);
               j[z]->set_ID(65+z);
               j[z]->set_direcao(tolower(d[0]));
               Configura_Barco(*j[z],lugar);
               z++;
        }  	
	int ola=map.tellg();
	map.close();
	return ola;
}

int Partida::Rodada(int j){
	int x,y;
	char yt;
	char id;
	preencher(j%2);
	printf("%c[%d;%df",0x1B ,5,78);	
	cin >> x;
	printf("%c[%d;%df",0x1B ,8,79);
	cin  >> yt;
	yt=toupper(yt);
	y=yt-65;
	id=get_mi(x,y,j%2);


	if(id=='-'){
		printf("%c[%d;%df",0x1B ,12,60);
		cout << "TIRO NA AGUA" << endl;

	if(j==1)
        set_m('-',x,y,j%2);
        else
        set_m('-',x,y,j%2);

		return 0;
	}
	
	else if(j==1)
        set_m(jtwo[id-65]->get_nome(),x,y,j%2);
        else
        set_m(jone[id-65]->get_nome(),x,y,j%2);	
	
	preencher(j%2);	
	printf("%c[%d;%df",0x1B ,12,60);	
	
	if(j==1)
	return jtwo[id-65]->Tomar_Dano(x,y);
	else
	return jone[id-65]->Tomar_Dano(x,y);
}

vector<Barco*> Partida::get_jone(){
	return jone;
}

vector<Barco*>Partida::get_jtwo(){
	return jtwo;
}

void Partida::Jogo(){
        int vida[2]={24,24};
        int jogada=0;
	char whatever;
        while(true){
		Limpar();
                vida[(jogada+1)%2]-=Rodada(jogada);
                jogada++;
                jogada%=2;
		cout << vida[0] << " " << vida[1]<< endl;
                if(vida[0]==0){
                        cout << "JOGADOR 2 GANHOU!!!!!"<< endl;
                        break;
                }

                if(vida[1]==0){
                        cout <<"JOGADOR ! GANHOU !!!!!" << endl;
                        break;
                }
		fflush(stdin);
		scanf("%c",&whatever);
       }
}

void Partida::Limpar(){
	printf("%c[%d;%df",0x1B ,2,75);
	cout << "                  ";
	 printf("%c[%d;%df",0x1B ,5,78);
	cout << "               ";
	printf("%c[%d;%df",0x1B ,8,79);	
	cout << "              ";
	printf("%c[%d;%df",0x1B ,12,60);
	cout << "                                 "; 
}

	
