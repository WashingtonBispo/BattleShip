#ifndef PARTIDA_HPP
#define PARTIDA_HPP

using namespace std;

class Partida{
	private:
		char m[13][13][2];
		char mi[13][13][2];
	public:
		Partida();
		~Partida();

		char get_m(int x,int y, int z);
		void set_m(char l,int x,int y,int z);

		char get_mi(int x,int y, int z);
		void set_mi(char l,int x,int y,int z);
		
		void Configura_Barco(int x,int y,int z,char d,char ID,int tamanho);
};

#endif


