#ifndef BARCO_HPP
#define BARCO_HPP

class Barco{
	private:
		int x;
		int y;
		char ID;
		int tamanho;
		char direcao;
		int vida;

	public:
		Barco(int x,int y,char direcao);
		~Barco();
		
		int get_x();
		void set_x(int x);

		int get_y();
		void set_y(int y);

		char get_ID();
		void set_ID(char ID);

		int get_tamanho();
		void set_tamanho(int tamanho);
		
		char get_direcao();
		void set_direcao(char direcao);

		int get_vida();
		void set_vida(int vida);

		int Toma_Dano(int vida);
		
};

#endif

		
