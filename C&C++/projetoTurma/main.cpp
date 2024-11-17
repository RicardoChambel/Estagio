#include <iostream>
#include <string>
#include <locale>
#include <vector>

using namespace std;

struct Aluno {
    string nome;
    string turma;
    int numero;

    Aluno(string nomeInput, string turmaInput, int numeroInput): nome(nomeInput), turma(turmaInput), numero(numeroInput) {}
};

void mostrarAlunos(vector<Aluno> &alunos) {
    for (auto &aluno : alunos) {
        cout << "> Nome: " << aluno.nome << ", Turma: " << aluno.turma << ", Número: " << aluno.numero << endl;
    }
    cout << endl;
}

void ordenarPorTurma(vector<Aluno> &alunos) {
    for (int i = 0; i < alunos.size(); ++i) {
        for (int j = i + 1; j < alunos.size(); ++j) {
            if (alunos[i].turma > alunos[j].turma) {
                swap(alunos[i], alunos[j]);
            }
        }
    }
}

void ordenarPorNumero(vector<Aluno> &alunos) {
    for (int i = 0; i < alunos.size(); ++i) {
        for (int j = i + 1; j < alunos.size(); ++j) {
            if (alunos[i].numero > alunos[j].numero) {
                swap(alunos[i], alunos[j]);
            }
        }
    }
}

void ordenarPorNome(vector<Aluno> &alunos) {
    for (int i = 0; i < alunos.size(); ++i) {
        for (int j = i + 1; j < alunos.size(); ++j) {
            if (alunos[i].nome > alunos[j].nome) {
                swap(alunos[i], alunos[j]);
            }
        }
    }
}

bool numeroDisponivel(vector<Aluno> &alunos, string &turma, int numero) {
    for (auto &aluno : alunos) {
        if (aluno.turma == turma && aluno.numero == numero) {
            return false;
        }
    }
    return true;
}

void addAluno(vector<Aluno> &alunos){
    char adicionarAluno;
    string nome;
    string turma;
    int numero;

    cout << "Nome do aluno -> ";
    cin >> nome;
    cin.clear();

    cout << "Turma do aluno -> ";
    cin >> turma;
    cin.clear();

    cout << "Numero do aluno -> ";
    cin >> numero;
    cin.clear();

    if (!numeroDisponivel(alunos, turma, numero)) {
        char mudar;
        system("cls");
        cout << "\n- Já existe um aluno com o número " << numero << " na turma " << turma << "!\n\n";
        numero++;
        do{
            if(numeroDisponivel(alunos,turma,numero)){
                cout << "É possível alterar o numero para: " << numero << endl;
                cout << "[1] - Alterar para " << numero << endl;
                cout << "[2] - Cancelar" << endl;
                cin >> mudar;
                if(mudar=='1'){
                    cin.clear();
                    break;
                }
                else{
                    cin.clear();
                    system("cls");
                    cout << "\n- Cancelado!\n" << endl;
                    return;
                }
            }else{
                numero++;
            }
        }while(1==1);
    }

    alunos.push_back(Aluno(nome,turma,numero));
    system("cls");
    cout << "\n- Aluno adicionado com sucesso !! -\n\n";
    cout << "> Nome -> " << nome << endl;
    cout << "> Turma -> " << turma << endl;
    cout << "> Numero -> " << numero << endl;
    cout << endl;
}

int main() {
    cin.clear();
    setlocale(LC_ALL, "Portuguese");

    vector<Aluno> alunos;
    string nome, turma;
    int numero;

    string escolha;

    do{
        cout << "-- Programa de Turmas --" << endl;
        cout << "[1] - Adicionar Aluno" << endl;
        cout << "[2] - Ordenar por nome" << endl;
        cout << "[3] - Ordenar por numero" << endl;
        cout << "[4] - Ordenar por turma" << endl;
        cout << "[0] - Sair" << endl;
        cout << "Escolha -> ";
        cin >> escolha;
        if(escolha=="1"){
            cin.clear();
            system("cls");
            cout << "-- Adicionar Aluno --" << endl;
            addAluno(alunos);
        }
        else if(escolha=="2"){
            cin.clear();
            system("cls");
            if(!alunos.empty()){
                cout << "-- Alunos ordenados por nome --" << endl;
                ordenarPorNome(alunos);
                mostrarAlunos(alunos);
            }
            else{
                cout << "\n- Ainda não existem alunos!\n" << endl;
            }
        }
        else if(escolha=="3"){
            cin.clear();
            system("cls");
            if(!alunos.empty()){
                cout << "--  Alunos ordenados por numero --" << endl;
                ordenarPorNumero(alunos);
                mostrarAlunos(alunos);
            }
            else{
                cout << "\n- Ainda não existem alunos!\n" << endl;
            }
        }
        else if(escolha=="4"){
            cin.clear();
            system("cls");
            if(!alunos.empty()){
                cout << "--  Alunos ordenados por turma --" << endl;
                ordenarPorTurma(alunos);
                mostrarAlunos(alunos);
            }
            else{
                cout << "\n- Ainda não existem alunos!\n" << endl;
            }
        }
        else if(escolha=="0"){
            cin.clear();
            system("cls");
            cout << "\n- Até à próxima !!\n";
        }
        else{
            cin.clear();
            system("cls");
            cout << "\n- Opção inválida !!\n\n";
        }
    }while(escolha != "0");

    return 0;
}
