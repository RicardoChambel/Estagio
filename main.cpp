#include <iostream>

using namespace std;

namespace nameSpace1 {
    int valor = 10;
}

namespace nameSpace2 {
    int valor = 20;
}

int main() {

    cout << "Valor no nameSpace1: " << nameSpace1::valor << endl;
    cout << "Valor no nameSpace2: " << nameSpace2::valor << endl;

    nameSpace1::valor += 5;
    nameSpace2::valor += 10;

    cout << "\n---- Depois de mudar os valores ----\n" << endl;

    cout << "Valor em nameSpace1: " << nameSpace1::valor << endl;
    cout << "Valor em nameSpace2: " << nameSpace2::valor << endl;


    return 0;

}