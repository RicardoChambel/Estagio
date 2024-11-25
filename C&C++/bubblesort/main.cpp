#include <iostream>
using namespace std;

void bubbleSort(int numeros[], int n){
    if(n==1) return;

    for(int i = 0; i < n - 1; i++){
        if(numeros[i] > numeros[i + 1]){
            int j = numeros[i];
            numeros[i] = numeros[i + 1];
            numeros[i + 1] = j;
        }
    }

    bubbleSort(numeros, n-1);
}

void mostrarNumeros(int numeros[], int n){
    for(int i = 0; i < n; i++){
        cout << numeros[i] << " ";
    }
    cout << endl;
}

int main(){
    int n = 7;
    int numeros[] = {2, 34, 25, 90, 22, 11, 12};

    cout << endl;
    cout << "+ Sem bubblesort (recursivo) -> ";
    mostrarNumeros(numeros, n);

    bubbleSort(numeros, n);
    cout << "+ Com bubblesort (recursivo) -> ";
    mostrarNumeros(numeros, n);

    return 0;
}
