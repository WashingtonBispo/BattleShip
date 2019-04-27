#ifndef PARTIDA_HPP
#define PARTIDA_HPP
#include "Barco.hpp"
#include <vector>
using namespace std;

class Partida {
	private:
		char m[13][13][2];
		char mi[13][13][2];
			
		vector <Barco*> jtwo;
		vector <Barco*> jone;

	public:
		Partida();
		~Partida();
		
		vector <Barco*> get_jtwo();
		vector <Barco*> get_jone();
			
		char get_m(int x,int y, int z);
		void set_m(char l,int x,int y,int z);

		char get_mi(int x,int y, int z);
		void set_mi(char l,int x,int y,int z);
		
		void preencher(int z);

		void Configura_Barco(Barco atual,int z);
		int Configura_Lista(vector<Barco*> j,int a,int lugar);
		void Rodada(int n);
	};

#endif


