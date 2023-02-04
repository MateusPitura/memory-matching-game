#include <stdio.h>
#include <time.h>

#define TAMANHO_TABULEIRO 4
#define CODIGO_ASCII_A 65

int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]={0}; //Inicializa tudo com zero

void inicializarTabuleiro();
int gerarSimboloValido();
int gerarSimboloAleatorio();
int calcularQuantidadeSimbolos(int tamanhoMatriz);
int gerarNumeroAleatorio(int menorNumeroAleatorio, int maiorNumeroAleatorio);
int contarRepeticoesTabuleiro(int simboloProcurado);
void exibirTabela();

int main(){
    srand(time(NULL));
    inicializarTabuleiro();
    exibirTabela();
    return 0;
}

void inicializarTabuleiro(){
    for(int i=0; i<TAMANHO_TABULEIRO; i++){
        for(int j=0; j<TAMANHO_TABULEIRO; j++){
            tabuleiro[i][j]=gerarSimboloValido();
        }
    }
}

int gerarSimboloValido(){
    int simboloAleatorio;
    do{
        simboloAleatorio=gerarSimboloAleatorio();
    }while(contarRepeticoesTabuleiro(simboloAleatorio)>=2); //2 é a quantidade de vezes que um numero deve se repetir
    return simboloAleatorio;
}

int gerarSimboloAleatorio(){
    int quantidadeSimbolosDiferentes=calcularQuantidadeSimbolos(TAMANHO_TABULEIRO);
    return gerarNumeroAleatorio(CODIGO_ASCII_A, CODIGO_ASCII_A+quantidadeSimbolosDiferentes-1); //-1 pois o A também entra na contagem
}

int calcularQuantidadeSimbolos(int tamanhoMatriz){
    return (tamanhoMatriz*tamanhoMatriz)/2;
}

int gerarNumeroAleatorio(int menorNumeroAleatorio, int maiorNumeroAleatorio){
    return menorNumeroAleatorio+rand()%(maiorNumeroAleatorio-menorNumeroAleatorio+1);
}

int contarRepeticoesTabuleiro(int simboloProcurado){
    int count=0;
    for(int i=0; i<TAMANHO_TABULEIRO; i++){
        for(int j=0; j<TAMANHO_TABULEIRO; j++){
            if(tabuleiro[i][j]==simboloProcurado){
                count++;
            }
        }
    }
    return count;
}

void exibirTabela(){
    for(int i=0; i<TAMANHO_TABULEIRO; i++){
        for(int j=0; j<TAMANHO_TABULEIRO; j++){
            printf("%5c", tabuleiro[i][j]);
        }
        printf("\n");
    }
}