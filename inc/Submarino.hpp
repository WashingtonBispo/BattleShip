#ifndef SUBMARINO_HPP
#define SUBMARINO_HPP

#include "Barco.hpp"
#include <string>

using namespace std;

class Submarino : public Barco {
	private:
		string segmentos;
	public:
		Submarino(int x,int y,char direcao);
		~Submarino();
		
		string get_segmentos();
		void set_segmentos(string segmento);

		int Poder(int vida);
		int Toma_Dano(int vida);
};
#endif
