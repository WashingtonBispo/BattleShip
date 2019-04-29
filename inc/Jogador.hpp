#ifndef JOGADOR_HPP     
#define JOGADOR_HPP

#include <string>
using namespace std;

class Jogador{
        private:
                int vida[4];
                string nome;

        public:
                Jogador();
                ~Jogador();

                int get_vida(int pos);
                void set_vida(int vida,int pos);

                string get_nome();
                void set_nome(string nome);
		int vida_total();
};

#endif


