#include <stdio.h>
#include <locale>

#define T_SIZE 3

void mostrarJogo(char (*tabuleiro)[T_SIZE]){
    printf("\n--- Jogo do Galo ---\n");
    printf("\n");
    for(int i = 0; i < T_SIZE; i++){ // i é a linha
        for(int j = 0; j < T_SIZE; j++){ // j é a coluna
            printf(" %c ", tabuleiro[i][j]);
            if (j < T_SIZE - 1) printf("|");
        }
        printf(" <- Linha %d", i+1);
        printf("\n");
        if(i < T_SIZE - 1){
            printf("---|---|---\n");
        }
    }
    printf("\n");
}
void mostrarJogoLinha(char (*tabuleiro)[T_SIZE], int linha){
    printf("\n--- Jogo do Galo ---\n");
    printf("\n");
    for(int i = 0; i < T_SIZE; i++){ // i é a linha
        for(int j = 0; j < T_SIZE; j++){ // j é a coluna
            if(i == linha && tabuleiro[i][j]==' '){
                printf(" %d ", j+1);
                if(j < T_SIZE-1){
                    printf("|");
                }
            }
            else{
                printf(" %c ", tabuleiro[i][j]);
                if(j < T_SIZE-1){
                    printf("|");
                }
            }
        }
        if(i == linha){
            printf(" <-");
        }
        printf("\n");
        if(i < T_SIZE-1){
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

char checkVencedor(char (*tabuleiro)[T_SIZE]){
    //Linhas
    for(int i = 0; i < T_SIZE; i++){
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' '){
            return tabuleiro[i][0];
        }
    }
    //Colunas
    for(int i = 0; i < T_SIZE; i++){
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' '){
            return tabuleiro[0][i];
        }
    }
    //Diagonais
    if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' '){
        return tabuleiro[0][0];
    }
    if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' '){
        return tabuleiro[0][2];
    }

    return ' ';
}

bool checkEmpate(char (*tabuleiro)[T_SIZE]){
    for(int i = 0; i < T_SIZE; i++){
        for(int j = 0; j < T_SIZE; j++){
            if (tabuleiro[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

void setJogador(char *jogadorAtual){
    *jogadorAtual = (*jogadorAtual == 'X') ? 'O' : 'X';
}

void jogar(){
    char jogo[T_SIZE][T_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int linha, coluna;
    char jogadorAtual = 'X';
    char vencedor = ' ';

    while (vencedor==' ' && !checkEmpate(jogo)) {

        mostrarJogo(jogo);

        printf("> Jogador %c\n", jogadorAtual);

        printf("Linha  (1-3) -> ");
        scanf("%d", &linha);
        system("cls");
        mostrarJogoLinha(jogo, linha-1);

        printf("> Jogador %c\n", jogadorAtual);
        printf("Coluna (1-3) -> ");
        scanf("%d", &coluna);

        linha = linha-1;
        coluna = coluna-1;

        //Verificar se os inputs são uma coordenada válida
        if(linha < 0 || linha >= T_SIZE || coluna < 0 || coluna >= T_SIZE || jogo[linha][coluna] != ' '){
            system("cls");
            printf("\n\n- Coordenada inválida! -\n\n");
            continue;
        }else{
            system("cls");
        }

        jogo[linha][coluna] = jogadorAtual;

        vencedor = checkVencedor(jogo);

        setJogador(&jogadorAtual);
    }

    if(vencedor!= ' '){
        printf("\n- Vencedor! -\n");
        printf("\n> jogador %c !\n", vencedor);
    }else{
        printf("\n- Empate! -\n\n");
    }
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    char again;

    do {
        jogar();

        printf("\n\n- Jogar outra vez? (s/n) -\n");
        printf("> ");
        scanf(" %c", &again);
        system("cls");
    } while (again == 's' || again == 'S');

    printf("\n--- Até à próxima! ---\n");
    return 0;
}
