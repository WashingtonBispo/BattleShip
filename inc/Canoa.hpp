#ifndef CANOA_HPP
#define CANOA_HPP


class Canoa :public Barco{	
	public:
		Canoa();
		~Canoa();
		
		int Tomar_Dano(int x,int y);
};
#endif
