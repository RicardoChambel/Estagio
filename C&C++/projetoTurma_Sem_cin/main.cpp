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
        printf("> Nome: %s, Turma: %s, Número: %d\n",aluno.nome.c_str(),aluno.turma.c_str(), aluno.numero);
    }
    printf("\n");
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

    char buffer[200]; // * Novamente a variavel buffer

    printf("Nome do aluno -> ");
    scanf(" %[^\n]", buffer);
    nome = buffer;

    printf("Turma do aluno -> ");
    scanf(" %[^\n]", buffer);
    turma = buffer;

    printf("Número do aluno -> ");
    scanf("%d", &numero);

    if (!numeroDisponivel(alunos, turma, numero)) {
        int mudar;
        system("cls");
        printf("\n- Já existe um aluno com o número %d na turma %s !\n\n", numero, turma.c_str());
        int numeroBefore = numero;
        do{
            if(numeroDisponivel(alunos,turma,numero)){
                printf("É possível alterar o numero para: %d \n", numero);
                printf("[1] - Alterar de %d para %d \n", numeroBefore, numero);
                printf("[2] - Cancelar\n");
                printf("-> ");
                scanf("%d", &mudar);
                if(mudar==1){
                    break;
                }
                else{
                    system("cls");
                    printf("\n- Cancelado!\n\n");
                    return;
                }
            }else{
                numero++;
            }
        }while(1==1);
    }

    alunos.push_back(Aluno(nome,turma,numero));
    system("cls");
    printf("\n- Aluno adicionado com sucesso !! -\n\n");
    printf("> Nome -> %s\n", nome.c_str());
    printf("> Turma -> %s\n", turma.c_str());
    printf("> Numero -> %d\n", numero);
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    vector<Aluno> alunos;
    string nome, turma;
    int numero;

    string escolha;
    char buffer[200]; // TIve de fazer esta variavel porque o scanf não limpa os caracteres do buffer após um input.
    // Também fiz a variavel noutras partes do código

    do{
        printf("-- Programa de Turmas --\n");
        printf("[1] - Adicionar Aluno\n");
        printf("[2] - Ordenar por nome\n");
        printf("[3] - Ordenar por numero\n");
        printf("[4] - Ordenar por turma\n");
        printf("[0] - Sair\n");
        printf("Escolha -> ");
        scanf("%[^\n]", buffer);
        escolha = buffer;
        system("cls");
        if(escolha=="1"){
            printf("-- Adicionar Aluno --\n");
            addAluno(alunos);
        }
        else if(escolha=="2"){
            if(!alunos.empty()){
                printf("-- Alunos ordenados por nome --\n");
                ordenarPorNome(alunos);
                mostrarAlunos(alunos);
            }
            else{
                printf("\n- Ainda não existem alunos!\n\n");
            }
        }
        else if(escolha=="3"){
            if(!alunos.empty()){
                printf("--  Alunos ordenados por numero --\n");
                ordenarPorNumero(alunos);
                mostrarAlunos(alunos);
            }
            else{
                printf("\n- Ainda não existem alunos!\n\n");
            }
        }
        else if(escolha=="4"){
            if(!alunos.empty()){
                printf("--  Alunos ordenados por turma --\n");
                ordenarPorTurma(alunos);
                mostrarAlunos(alunos);
            }
            else{
                printf("\n- Ainda não existem alunos!\n\n");
            }
        }
        else if(escolha=="0"){
            printf("\n- Até à próxima !!\n(ENTER para fechar)\n\n--------\n");
        }
        else{
            printf("\n- Opção inválida !!\n\n");
        }
        cin.ignore(1000, '\n');
    }while(escolha != "0");

    return 0;
}
