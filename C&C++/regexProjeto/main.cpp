#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <locale>

using namespace std;

// VALIDAÇÕES ------------------------------------------
bool isValidNome(string& nome) {
    regex regexNome("^[A-Z][a-z]*( [A-Z][a-z]*)*$");
    //[A-Z] -> Começa com uma letra maiúscula
    //[a-z]* -> PODE(*) ser seguido de 0 ou mais letras minúsculas
    //( [A-Z][a-z]*)* -> PODE ter 0 ou mais nomes. Começam com um espaço e uma letra maiúscula, seguida de 0 ou mais letras minúsculas
    return regex_match(nome, regexNome);
}

bool isValidData(string& data) {
    regex dateRegex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/[0-9]{4}$");
    //(0[1-9]|[12][0-9]|3[01]) -> Dia de 01 a 09 OU 10 a 19 OU 20 a 29 OU 30 a 31
    //(0[1-9]|1[0-2]) -> Mês de 01 a 09 OU 10 a 12
    //[0-9]{4} -> Ano com 4 dígitos de 0 a 9 (ex: 2024)
    return regex_match(data, dateRegex);
}

// GUARDAR NO FICHEIRO ------------------------------------------
void guardarDados(string& nome, string& dataNascimento, string& bi) {
    FILE* ficheiro = fopen("C:/Windows/Temp/dados.txt", "a");

    if (ficheiro != nullptr) {
        fprintf(ficheiro, "----\n");
        fprintf(ficheiro, "> Nome: %s\n", nome.c_str());
        fprintf(ficheiro, "> Data de Nascimento(DD/MM/AAAA): %s\n", dataNascimento.c_str());
        fprintf(ficheiro, "> BI: %s\n", bi.c_str());
        fclose(ficheiro);
        cout << "\n- Informações guardadas com sucesso! -\n" << endl;
    } else {
        cout << "\n- Erro ao escrever no ficheiro! -\n" << endl;
    }
}

// LER DO FICHEIRO ------------------------------------------
void carregarDados(vector<string>& nomes, vector<string>& datasNascimento, vector<string>& bis) {
    FILE* ficheiro = fopen("C:/Windows/Temp/dados.txt", "r");
    char buffer[256];
    string nome, dataNascimento, bi;

    if (ficheiro != nullptr) {
        while (fgets(buffer, sizeof(buffer), ficheiro)) {
            string line(buffer);
            if (line.back() == '\n') {
                line.pop_back();
            }

            if(line.find("> Nome:")==0){

                nome = line.substr(8); // Tirar o "> Nome: "

            }else if(line.find("> Data de Nascimento(DD/MM/AAAA):")==0){

                dataNascimento = line.substr(34); // Tirar o "> Data de Nascimento(DD/MM/AAAA): "

            }else if(line.find("> BI:")==0){

                bi = line.substr(6); // Tirar o "> BI: "

            }else if(line == "----"){ // Como estas linhas são os separadores, então agora posso adicionar aos arrays o nome, a data de nascimento e o bi
                if(!nome.empty() && !dataNascimento.empty() && !bi.empty()){
                    nomes.push_back(nome);
                    datasNascimento.push_back(dataNascimento);
                    bis.push_back(bi);
                }
                // E agora limpo as variaveis
                nome.clear();
                dataNascimento.clear();
                bi.clear();
            }
        }

        if(!nome.empty() && !dataNascimento.empty() && !bi.empty()){
            nomes.push_back(nome);
            datasNascimento.push_back(dataNascimento);
            bis.push_back(bi);
        }

        fclose(ficheiro);
        cout << "\n- Dados do ficheiro guardados nos respetivos arrays -\n" << endl;

    } else{
        FILE* ficheiro = fopen("C:/Windows/Temp/dados.txt", "w");
        fclose(ficheiro);
        cout << "\n- Ficheiro novo criado -\n" << endl;
    }
}

// MOSTRAR DADOS DOS ARRAYS -----------------------------
void mostrarDados(vector<string>& nomes, vector<string>& datasNascimento, vector<string>& bis) {
    if(nomes.empty()){
        cout << "\n- Não há dados guardados! -\n" << endl;
        return;
    }

    cout << "\n- Dados atuais:\n" << endl;
    for(int i = 0; i < nomes.size(); ++i){
        cout << "=-=" << endl;
        cout << "Nome -> " << nomes[i] << endl;
        cout << "Data de Nascimento -> " << datasNascimento[i] << endl;
        cout << "BI -> " << bis[i] << endl;

        if(i==(nomes.size()-1)){
            cout << "=-=" << endl;
        }
    }

}

void novosDados(vector<string>& nomes, vector<string>& datasNascimento, vector<string>& bis){

    string nome="", dataNascimento="", bi="";

    // NOVO NOME -----------------
    do{
        cout << "> Novo nome (ex: Afonso Henriques): ";
        getline(cin, nome);

        if(!isValidNome(nome)){
            system("cls");
            cout << "\n- Nome inválido! Tem de começar com uma letra maiúscula!\n" << endl;
            nome="";
        }else{
            system("cls");
        }
    }while(nome=="");

    // NOVA DATA DE NASCIMENTO -----------------
    do{
        cout << "Nome -> " << nome << endl;
        cout << "> Nova data de nascimento (DD/MM/AAAA): ";
        getline(cin, dataNascimento);

        if(!isValidData(dataNascimento)){
            system("cls");
            cout << "\n- Data de nascimento inválida! Formato válido: DD/MM/AAAA!\n" << endl;
            dataNascimento="";
        }else{
            system("cls");
        }

    }while(dataNascimento=="");

    // NOVO BI -----------------
    do{
        cout << "Nome -> " << nome << endl;
        cout << "Data de nascimento -> " << dataNascimento << endl;
        cout << "> Novo número de BI: ";
        getline(cin, bi);

        system("cls");
    }while(bi=="");

    system("cls");

    // GUARDAR DADOS (no ficheiro e nos arrays) ------------------
    guardarDados(nome, dataNascimento, bi);
    nomes.push_back(nome);
    datasNascimento.push_back(dataNascimento);
    bis.push_back(bi);

}

int main() {
    setlocale(LC_ALL, "Portuguese");

    vector<string> nomes, datasNascimento, bis;
    carregarDados(nomes, datasNascimento, bis);

    do{
        string escolha;

        cout << "\n= Projeto Dados & Ficheiros =\n" << endl;
        cout << "[1] Adicionar novos dados" << endl;
        cout << "[2] Mostrar dados guardados" << endl;
        cout << "[3] Mostrar ficheiro de dados no explorador de ficheiros" << endl;
        cout << "[-1] Sair" << endl;
        cout << "> ";
        getline(cin, escolha);
        system("cls");
        if(escolha=="1"){
            novosDados(nomes, datasNascimento, bis);
        }else if(escolha=="2"){
            mostrarDados(nomes, datasNascimento, bis);
        }else if(escolha=="3"){
            system("explorer C:\\Windows\\Temp");
        }else if(escolha=="-1"){
            cout << "\n> Até à próxima\n" << endl;
            break;
        }

    }while(true);



    return 0;
}
