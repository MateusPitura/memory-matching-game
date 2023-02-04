#include <stdio.h>
#include <time.h> //Para o srand
#include <windows.h> //Para o Sleep

#define TAMANHO_TABULEIRO 4
#define CODIGO_ASCII_A 65

int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]={0}; //Inicializa tudo com zero

void inicializarTabuleiro();
int gerarSimboloValido();
int gerarSimboloAleatorio();
int calcularQuantidadeSimbolos(int tamanhoMatriz);
int gerarNumeroAleatorio(int menorNumeroAleatorio, int maiorNumeroAleatorio);
int contarRepeticoesTabuleiro(int simboloProcurado);
void escolherCartas();
void exibirPosicoesCarta();
void exibirCartaEscolhida(int primeiraCartaEscolhida, int segundaCartaEscolhida);
int calcularLinhaEscolhida(int posicaoEscolhida);
int calcularColunaEscolhida(int posicaoEscolhida);

int main(){
    srand(time(NULL));
    inicializarTabuleiro();
    do{
        escolherCarta();
    } while(1==1);
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

void escolherCarta(){
    int primeiraCartaEscolhida;
    int segundaCartaEscolhida;
    exibirPosicoesCarta();
    printf("Escolha a primeira carta: ");
    scanf("%d", &primeiraCartaEscolhida);
    printf("Escolha a segunda carta: ");
    scanf("%d", &segundaCartaEscolhida);
    system("cls");
    exibirCartaEscolhida(primeiraCartaEscolhida, segundaCartaEscolhida);
    Sleep(1000);
    system("cls");
}

void exibirPosicoesCarta(){
    for(int i=1; i<=TAMANHO_TABULEIRO; i++){
        for(int j=1; j<=TAMANHO_TABULEIRO; j++){
            printf("%5d", (i*10)+j); //Suponha i=3, j=4. Irá exibir 34
        }
        printf("\n");
    }
}

void exibirCartaEscolhida(int primeiraCartaEscolhida, int segundaCartaEscolhida){
    int linhaPrimeiraCartaEscolhida=calcularLinhaEscolhida(primeiraCartaEscolhida);
    int colunaPrimeiraCartaEscolhida=calcularColunaEscolhida(primeiraCartaEscolhida);
    int linhaSegundaCartaEscolhida=calcularLinhaEscolhida(segundaCartaEscolhida);
    int colunaSegundaCartaEscolhida=calcularColunaEscolhida(segundaCartaEscolhida);
    for(int i=1; i<=TAMANHO_TABULEIRO; i++){
        for(int j=1; j<=TAMANHO_TABULEIRO; j++){
            if((i==linhaPrimeiraCartaEscolhida && j==colunaPrimeiraCartaEscolhida) || (i==linhaSegundaCartaEscolhida && j==colunaSegundaCartaEscolhida)){
                printf("%5c", tabuleiro[i-1][j-1]); //-1 pois o i e j deveriam começar no 0
            }
            else{
                printf("%5d", (i*10)+j);
            }
        }
        printf("\n");
    }
}

int calcularLinhaEscolhida(int posicaoEscolhida){
    return posicaoEscolhida/10; //Mesmo que a divisão seja um número decimal, apenas a parte inteira retorna por ser int
}

int calcularColunaEscolhida(int posicaoEscolhida){
    return posicaoEscolhida-((posicaoEscolhida/10)*10); //Ex.: 34/10=3 (po ser int a parte decimal é descartada). 3*10=30. 34-30=4
}