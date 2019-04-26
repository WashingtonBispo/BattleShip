#ifndef PORTA_HPP
#define PORTA_HPP

#include <string>

using namespace std;

class Porta : public Barco {
	private:
		string segmentos;
		int evasiva;
	public:
		Porta(int x,int y,char direcao);
		Porta();
		~Porta();
		
		string get_segmentos();
		void set_segmentos(string segmentos);
		
		int get_evasiva();
		void set_evasiva(int evasiva);

		int Tomar_Dano(int x, int y);
};

#endif
