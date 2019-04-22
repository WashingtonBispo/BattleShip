#ifndef PARTIDA_HPP
#define PARTIDA_HPP
#include "Barco.hpp"
#include "Submarino.hpp"
#include "Porta.hpp"
#include <vector>
using namespace std;

class Partida {
	private:
		char m[13][13][2];
		char mi[13][13][2];
		vector <Barco*> jone;
		vector <Barco*> jtwo;	
	public:
		Partida();
		~Partida();

		char get_m(int x,int y, int z);
		void set_m(char l,int x,int y,int z);

		char get_mi(int x,int y, int z);
		void set_mi(char l,int x,int y,int z);
		
		void preencher(int z);

		void Configura_Barco(Barco atual,int z);
		void Rodada(int n);
	};

#endif


