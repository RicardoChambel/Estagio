#include <iostream>
#include <string>
#include <locale>
#include <vector>

#define MAX_CONTACTOS 100

using namespace std;

struct Contacto{
    string nome;
    string telefone;
};

struct Listacontactos{
    vector<Contacto> contactos;
};

void addContacto(Listacontactos& lista, const string& nome, const string& telefone){
    if(lista.contactos.size() < MAX_CONTACTOS){
        Contacto novoContacto;
        novoContacto.nome = nome;
        novoContacto.telefone = telefone;
        lista.contactos.push_back(novoContacto);
    }else{
        cout << "Lista de contactos cheia!\n";
    }
}

Contacto* findContacto(Listacontactos& lista, const string& nome){
    for(int i = 0; i < lista.contactos.size(); i++){
        if(lista.contactos[i].nome == nome){
            return &lista.contactos[i];
        }
    }
    return NULL;
}

void mostrarContactos(Listacontactos& lista){
    for(int i = 0; i < lista.contactos.size(); i++){
        cout << "Nome - " << lista.contactos[i].nome << " | Telefone - " << lista.contactos[i].telefone << endl;
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    Listacontactos listaContactos;

    // ADICIONAR CONTACTOS ------------------------------
    addContacto(listaContactos, "Ricardo", "12356789");
    addContacto(listaContactos, "José", "987654321");
    addContacto(listaContactos, "João", "192837465");

    // DAR PRINT A LISTA DE CONTACTOS ------------------------------
    cout << "\n- Lista de Contactos -\n";
    mostrarContactos(listaContactos);

    // PROCURAR CONTACTO ------------------------------
    cout << "\n- Procurar Contacto -\n";
    string nomeProcurado = "Ricardo"; // Nome para procurar
    Contacto* contactoEncontrado = findContacto(listaContactos, nomeProcurado);

    if(contactoEncontrado){
        cout << "\nContacto encontrado!\nNome - " << contactoEncontrado->nome << " | Telefone - " << contactoEncontrado->telefone << endl;
    }else{
        cout << "Contacto " << nomeProcurado << " não encontrado!\n";
    }

    return 0;
}
