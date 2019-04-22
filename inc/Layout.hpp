#ifndef LAYOUT_HPP
#define LAYOUT_HPP
#include <string>

using namespace std;
class Layout{
	private:
	public:
		Layout();
		~Layout();
	
		void gotoxy(int x,int y);
		void grade();
		void Faz_Retangulo(int x,int y);
		string Linha();
		int  menu();

};

#endif
