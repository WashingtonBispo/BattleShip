#ifndef JOGADOR_HPP     
#define JOGADOR_HPP

#include <string>
using namespace std;

class Jogador{
        private:
                int vida;
                string nome;

        public:
                Jogador();
                ~Jogador();

                int get_vida();
                void set_vida(int vida);

                string get_nome();
                void set_nome(string nome);
};

#endif


