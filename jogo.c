#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

//#define COD_LENGTH 4

/* Função que gera um código randomico de 4 dígitos */
void gerarCodigo(int codigo, int tamCodigo) {
    srand(time(NULL));  
    for (int i = 0; i < tamCodigo; i++) {
        codigo[i] = rand() % 10;
    }
}

/* Função para verificar se o jogador decifrou o código  */
int checkCodigo(int codigo[], int decifraCodigo[], int *okCount, int tamCodigo){
    int resultado[tamCodigo]; 
    int quaseCount = 0;

    for (int i = 0; i < tamCodigo; i++) {
        if (decifraCodigo[i] == codigo[i]) {
            resultado[i] = 1; // Marca como OK
            (*okCount)++;
        }
    }

    for (int i = 0; i < tamCodigo; i++) {
        if (resultado[i] == 0) {
            for (int j = 0; j < tamCodigo; j++) {
                if (resultado[j] == 0 && decifraCodigo[i] == codigo[j]) {
                    resultado[j] = -1; // Marca como Quase
                    quaseCount++;
                    break;
                }
            }
        }
    }

     for (int i = 0; i < tamCodigo; i++) {
        if (resultado[i] == 1) {
            printf("OK ");
        } else if (resultado[i] == -1) {
            printf("Quase ");
        } else {
            printf("NOK ");
        }
    }
    printf("\n");

    if (*okCount == tamCodigo) {
        return 1; // Retorna 1 se o código estiver correto
    }
    return 0; 
}

int mainJogo(){
    int decifraCodigo[COD_LENGTH];
    int tentativa = 0;
    char nomeJogador[20];
    int okCount = 0;
    int nivelJogo = 0, tamCodigo;

    printf("Bem-vindo ao jogo: Decifre o código!\n");
    printf("Digite o seu nome: ");
    scanf("%s", nomeJogador);
    printf("\nEscolha o nível do jogo: 1-Facil, 2-Médio, 3-Dificil");
    scanf("%d", &nivelJogo);

    switch (nivelJogo) {
        case 1:
            tamCodigo = 4;
            break;
        case 2:
              tamCodigo = 5;
            break;
        case 3:
              tamCodigo = 6;
            break;
        default:
            printf("Nível inválido. O jogo será configurado como fácil (4 dígitos).\n");
              tamCodigo = 4;
    }

    int codigo[tamCodigo];
    gerarCodigo(codigo, tamCodigo);

    while (1) {
        tentativa++;
        printf("Tentativa %d - Digite uma senha de 4 dígitos: ", tentativa);
        for (int i = 0; i < tamCodigo; i++) {
            scanf("%1d", &decifraCodigo[i]);
        }

        if (checkCodigo(codigo, decifraCodigo, &okCount) == 1) {
            printf("Parabéns, %s! Você decifrou o código com %d tentativas.\n", nomeJogador, tentativa);
            sleep(5);
            /* Salvar resultado no arquivo */
            FILE *file = fopen("resultados.txt", "a");
            if (file != NULL) {
                fprintf(file, "%s, %d\n", nomeJogador, tentativa);
                fclose(file);
            } else {
                printf("Erro ao salvar o resultado.\n");
            }
            break;
        }
      
       
    }
    return 0;
}