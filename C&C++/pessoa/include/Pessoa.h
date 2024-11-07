#include <iostream>
#include <string>

#ifndef PESSOA_H
#define PESSOA_H

using namespace std;

class Pessoa
{
    public:
        Pessoa();
        virtual ~Pessoa();

        string GetNome() { return Nome; }
        void SetNome(string val) { Nome = val; }

        string GetMorada() { return Morada; }
        void SetMorada(string val) { Morada = val; }

        int GetIdade() { return Idade; }
        void SetIdade(int val) { Idade = val; }

        float GetAltura() { return Altura; }
        void SetAltura(float val) { Altura = val; }

    protected:

    private:
        string Nome;
        string Morada;
        int Idade;
        float Altura;
};

#endif
