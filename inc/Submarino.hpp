#ifndef SUBMARINO_HPP
#define SUBMARINO_HPP


using namespace std;

class Submarino : public Barco {
	private:
		string segmentos;
	public:
		Submarino(int x,int y,char direcao);
		Submarino();
		~Submarino();
		
		string get_segmentos();
		void set_segmentos(string segmento);

		int Tomar_Dano(int x,int y);
};
#endif
