#include <iostream>
#include <string>
#include <locale>
#include "Pessoa.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Pessoa aluno;
    aluno.SetAltura(177);
    aluno.SetIdade(16);
    aluno.SetMorada("Sesimbra, Alfarim, 17");
    aluno.SetNome("Ricardo");
    cout << "Nome do aluno: " << aluno.GetNome() << endl;
    cout << "Idade do aluno: " << aluno.GetIdade() << endl;
    cout << "Altura do aluno: " << aluno.GetAltura() << " cm" << endl;
    cout << "Morada do aluno: " << aluno.GetMorada() << endl;

    return 0;
}
