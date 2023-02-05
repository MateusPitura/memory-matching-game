#include <stdio.h>
#include <time.h> //Para o srand
#include <windows.h> //Para o Sleep

#define TAMANHO_TABULEIRO 4
#define CODIGO_ASCII_A 65
#define POSICAO_MENOR_CARTA 11

int tabuleiroCartas[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]={0}; //Inicializa tudo com zero
int tabuleiroPosicoes[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

void exibirMenuPrincipal(void);
void jogarJogoMemoria(void);
void escolherNivelJogo(void);
void inicializarTabuleiroCartas(void);
int gerarSimboloValido(void);
int gerarSimboloAleatorio(void);
int calcularQuantidadeSimbolos(int tamanhoMatriz);
int gerarNumeroAleatorio(int menorNumeroAleatorio, int maiorNumeroAleatorio);
int contarRepeticoesMatriz(int matriz[][TAMANHO_TABULEIRO], int simboloProcurado);
void inicializarTabuleiroPosicoes(void);
void escolherCarta(void);
void exibirCartasTabuleiro(int primeiraCartaEscolhida, int segundaCartaEscolhida);
int calcularLinhaEscolhida(int posicaoEscolhida);
int calcularColunaEscolhida(int posicaoEscolhida);
int verificarCartasEscolhidas(int primeiraCartaEscolhida, int segundaCartaEscolhida);

int main(void){
    srand(time(NULL));
    exibirMenuPrincipal();
    return 0;
}

void exibirMenuPrincipal(void){
    int opcaoMenuJogador;
    system("cls");
    printf("1 - Jogar\n2 - Nivel\n3 - Continuar\n4 - Rank\n5 - Sair\nEscolha uma opcao: ");
    scanf("%d", &opcaoMenuJogador);
    switch(opcaoMenuJogador){
    case 1:
        jogarJogoMemoria();
        break;
    case 2:
        escolherNivelJogo();
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        exit(0);
        break;
    default: 
        printf("Escolha invalida");
        break;
    }
    exibirMenuPrincipal();
}

void jogarJogoMemoria(){
    int tentativasJogador=0;
    inicializarTabuleiroCartas();
    inicializarTabuleiroPosicoes();
    while(contarRepeticoesMatriz(tabuleiroPosicoes, 0)<(TAMANHO_TABULEIRO*TAMANHO_TABULEIRO)){
        escolherCarta();
        tentativasJogador++;
    }
    printf("Tentativas: %d\n", tentativasJogador);
    system("pause");
}

void escolherNivelJogo(void){
    int opcaoNivelJogador;
    system("cls");
    printf("1 - Facil\n2 - Medio\n3 - Dificil\nEscolha um nivel: ");
    scanf("%d", &opcaoNivelJogador);
}

void inicializarTabuleiroCartas(){
    for(int i=0; i<TAMANHO_TABULEIRO; i++){
        for(int j=0; j<TAMANHO_TABULEIRO; j++){
            tabuleiroCartas[i][j]=gerarSimboloValido();
        }
    }
}

int gerarSimboloValido(){
    int simboloAleatorio;
    do{
        simboloAleatorio=gerarSimboloAleatorio();
    }while(contarRepeticoesMatriz(tabuleiroCartas, simboloAleatorio)>=2); //2 é a quantidade de vezes que um numero deve se repetir
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

int contarRepeticoesMatriz(int matriz[][TAMANHO_TABULEIRO], int simboloProcurado){
    int count=0;
    for(int i=0; i<TAMANHO_TABULEIRO; i++){
        for(int j=0; j<TAMANHO_TABULEIRO; j++){
            if(matriz[i][j]==simboloProcurado){
                count++;
            }
        }
    }
    return count;
}

void inicializarTabuleiroPosicoes(){
    for(int i=0; i<TAMANHO_TABULEIRO; i++){
        for(int j=0; j<TAMANHO_TABULEIRO; j++){
            tabuleiroPosicoes[i][j]=((i+1)*10)+(j+1);
        }
    }
}

void escolherCarta(){ //Refatorar
    int primeiraCartaEscolhida;
    int segundaCartaEscolhida;
    do{
        system("cls");
        exibirCartasTabuleiro(0, 0);
        printf("Escolha a primeira carta: ");
        scanf("%d", &primeiraCartaEscolhida);
        printf("Escolha a segunda carta: ");
        scanf("%d", &segundaCartaEscolhida);
    }while(verificarCartasEscolhidas(primeiraCartaEscolhida, segundaCartaEscolhida)==0);
    system("cls");
    exibirCartasTabuleiro(primeiraCartaEscolhida, segundaCartaEscolhida);
    Sleep(1000);
}

void exibirCartasTabuleiro(int primeiraCartaEscolhida, int segundaCartaEscolhida){
    for(int i=0; i<TAMANHO_TABULEIRO; i++){
        for(int j=0; j<TAMANHO_TABULEIRO; j++){
            if(tabuleiroPosicoes[i][j]==primeiraCartaEscolhida || tabuleiroPosicoes[i][j]==segundaCartaEscolhida || tabuleiroPosicoes[i][j]==0){
                printf("%5c", tabuleiroCartas[i][j]);
            }
            else{
                printf("%5d", tabuleiroPosicoes[i][j]);
            }
        }
        printf("\n");
    }
}

int verificarCartasEscolhidas(int primeiraCartaEscolhida, int segundaCartaEscolhida){
    int linhaPrimeiraCartaEscolhida=calcularLinhaEscolhida(primeiraCartaEscolhida);
    int colunaPrimeiraCartaEscolhida=calcularColunaEscolhida(primeiraCartaEscolhida);
    int linhaSegundaCartaEscolhida=calcularLinhaEscolhida(segundaCartaEscolhida);
    int colunaSegundaCartaEscolhida=calcularColunaEscolhida(segundaCartaEscolhida);
    if(primeiraCartaEscolhida==segundaCartaEscolhida){
        printf("A mesma carta foi escolhida duas vezes\n");
    }
    else if(primeiraCartaEscolhida<POSICAO_MENOR_CARTA || segundaCartaEscolhida<POSICAO_MENOR_CARTA){
        printf("Essa carta nao existe\n");
    }
    else if(linhaPrimeiraCartaEscolhida>=TAMANHO_TABULEIRO || colunaPrimeiraCartaEscolhida>=TAMANHO_TABULEIRO || linhaSegundaCartaEscolhida>=TAMANHO_TABULEIRO || colunaSegundaCartaEscolhida>=TAMANHO_TABULEIRO){
        printf("Essa carta nao existe\n");
    }
    else if(tabuleiroPosicoes[linhaPrimeiraCartaEscolhida][colunaPrimeiraCartaEscolhida]==0 || tabuleiroPosicoes[linhaSegundaCartaEscolhida][colunaSegundaCartaEscolhida]==0){
        printf("Essa carta ja foi revelada\n");        
    }
    else if(tabuleiroCartas[linhaPrimeiraCartaEscolhida][colunaPrimeiraCartaEscolhida]==tabuleiroCartas[linhaSegundaCartaEscolhida][colunaSegundaCartaEscolhida]){
        tabuleiroPosicoes[linhaPrimeiraCartaEscolhida][colunaPrimeiraCartaEscolhida]=0;
        tabuleiroPosicoes[linhaSegundaCartaEscolhida][colunaSegundaCartaEscolhida]=0;
        return 1; //Em caso de acerto
    }
    else{
        return 1; //Em caso de erro
    }
    system("pause");
    return 0; //Entrada de cartas invalidas
}

int calcularLinhaEscolhida(int posicaoEscolhida){
    return (posicaoEscolhida/10)-1; //Mesmo que a divisão seja um número decimal, apenas a parte inteira retorna por ser int. -1 pois a matriz começa em 0
}

int calcularColunaEscolhida(int posicaoEscolhida){
    return (posicaoEscolhida-((posicaoEscolhida/10)*10))-1; //Ex.: 34/10=3 (po ser int a parte decimal é descartada). 3*10=30. 34-30=4. -1 pois a matriz começa em 0
}