#include <iostream>
#include <locale>

using namespace std;

class Carro {

private:
    string marca;
    string cor;
    bool eletrico;

public:
    // Construtores ------------------------------------------------------------------
    // Sem atributos
    Carro() : marca("Indefinida"), cor("Indefinida"), eletrico(false) {}

    // com atributos
    Carro(string marcaInput, string corInput, bool eletricoInput) : marca(marcaInput), cor(corInput), eletrico(eletricoInput) {}

    // Set's ------------------------------------------------------------------
    void setMarca(string marcaInput) {
        marca = marcaInput;
    }
    void setCor(string corInput) {
        cor = corInput;
    }
    void setEletrico(bool eletricoInput) {
        eletrico = eletricoInput;
    }

    // Get's ------------------------------------------------------------------
    string getMarca() {
        return marca;
    }
    string getCor() {
        return cor;
    }
    bool isEletrico() {
        return eletrico;
    }

    // Método para mostrar a info do carro ------------------------------------
    void mostrarInfo() {
        cout << "| Marca -> " << marca << endl;
        cout << "| Cor -> " << cor << endl;
        cout << "| É elétrico -> " << (eletrico ? "Sim" : "Não") << endl;
        cout << "" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    cout << "--- Carros 4 All ---" << endl;
    cout << "\n--- Carros registados ---" << endl;
  
    // EXEMPLOS ------------------------------------------------------------------
    // Tesla
    Carro tesla("Tesla", "Vermelho", true);
    tesla.mostrarInfo();

    // Sem atributos
    Carro semAtributos;
    semAtributos.mostrarInfo();

    // Com input ---------------------------------
    string marca;
    string cor;
    string eletricoInput;
    bool eletrico;

    cout << "\n--- Novo carro ---\n" << endl;
    cout << "Marca: ";
    cin >> marca;
    cout << "Cor: ";
    cin >> cor;
    cout << "É elétrico (Sim - Nao): ";
    cin >> eletricoInput;
    if(eletricoInput=="Sim" || eletricoInput=="sim"){
        eletrico = true;
    }
    if(eletricoInput=="Nao" || eletricoInput=="nao"){
        eletrico = false;
    }else{
        eletrico = false;
    }

    Carro novo(marca,cor,eletrico);
    cout << "\n--- Info do novo carro ---" << endl;
    novo.mostrarInfo();

    return 0;
}
