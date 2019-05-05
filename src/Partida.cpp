#include <iostream>
#include "Jogador.hpp"
#include "Partida.hpp"
#include "Barco.hpp"
#include "Submarino.hpp"
#include "Porta.hpp"
#include "fstream"
#include "Canoa.hpp"
#include <vector>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

using namespace std;

Partida::Partida(){
	string provisorio;
	cout << "Digite o nome do primeiro jogador:";
	cin >> provisorio;
	jog[0].set_nome(provisorio);
	cout << "\nDigite o nome do segundo jogador:";
	cin >> provisorio;
	jog[1].set_nome(provisorio);
		
printf("%c[%d;%df",0x1B ,0,0);
	
	for(int z=0;z<2;z++)
		for(int x=0;x<13;x++)
			for(int y=0;y<13;y++)
				set_m(' ',x,y,z);

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
	int c;
	srand(time(0));
	c=rand()%3+49;
	Configura_Lista(jtwo,Configura_Lista(jone,0,1,c),0,c);
	}	

Partida::~Partida(){

}

char Partida::get_m(int x,int y, int z){
	return m[x][y][z];
}

void Partida::set_m(char l,int x,int y,int z){
	m[x][y][z]=l;
}

char Partida::get_mi(int x,int y, int z){
	return mi[x][y][z];
}

void Partida::set_mi(char l,int x,int y,int z){
	mi[x][y][z]=l;
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
	
	int y=1;
	
	for(int x=4;x<9;x+=2){
		printf("%c[%d;%df",0x1B ,x,96);
		cout << jog[0].get_vida(y);
		
		printf("%c[%d;%df",0x1B ,x+9,96);
                cout << jog[1].get_vida(y);
		y++;
	}
		
			
	printf("%c[%d;%df",0x1B ,2,75);
	cout << jog[z].get_nome();
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

int Partida::Configura_Lista(vector<Barco*>j,int a,int lugar,int c){
int x,y;
        char l;
        string t,d,mapa="doc//map_2.txt";
	mapa[9]=char(c);
	
 	ifstream map(mapa);
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
	string entrada;
	char id,yt;
	
inicio:
	Limpar();
	preencher(j);
	
	printf("%c[%d;%df",0x1B ,5,78);	
	cin >> entrada;
	x=stoi(entrada);
	printf("%c[%d;%df",0x1B ,8,79);
	cin  >> yt;
	
	yt=toupper(yt);
	y=yt-65;
	
	if(x>12 or x<0 or y>12 or y<0){
	cout << "\a";
	goto inicio;
	}

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
        set_m(jone[id-65]->get_nome(),x,y,j%2);
        else
        set_m(jtwo[id-65]->get_nome(),x,y,j%2);	
	
	preencher(j);	
	printf("%c[%d;%df",0x1B ,12,60);
	
	if(j==1)
	return jone[id-65]->Tomar_Dano(x,y);
	else
	return jtwo[id-65]->Tomar_Dano(x,y);

	
}

vector<Barco*> Partida::get_jone(){
	return jone;
}

vector<Barco*>Partida::get_jtwo(){
	return jtwo;
}

void Partida::Jogo(){
        int jogada=0;
	int tipo;
	string pausa;
	while(true){
		tipo=Rodada(jogada);
                jogada++;
                jogada%=2;
		jog[jogada].set_vida(jog[jogada].get_vida(tipo)-1,tipo);
		preencher((jogada+1)%2);

                if(jog[0].vida_total()==0){
			system("clear");
                        cout << "JOGADOR 2 GANHOU!!!!!"<< endl;
                        break;
                }

                if(jog[1].vida_total()==0){
			system("clear");
                        cout <<"JOGADOR 1 GANHOU !!!!!" << endl;
                        break;
                }
		printf("%c[%d;%df",0x1B ,38,38);
		system("sleep 3");
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

	
