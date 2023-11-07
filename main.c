#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    char name[50];
    int score;
    struct Node *next;
} Node;

Node *head = NULL;

void insertNode(char name[50], int score);
void selectionSort(Node *start);
void displayRanking();
void saveRanking();
int findPlayerAndUpdateScore(char name[50], int score);

int main() {
    int menu;
    char playerName[50];
    int difficulty, numDigits, score;

    srand(time(NULL)); // Seed para gerar números aleatórios

    while (1) {

        printf("\nJogo da Senha:\n");
        printf("1. Iniciar Jogo\n");
        printf("2. Ver Ranking\n");
        printf("3. Encerrar\n");
        scanf("%d", &menu);

        switch (menu) {

            case 1:

                printf("\nInforme seu nome: \n");
                scanf("%s", playerName);
                printf("\nEscolha o grau de dificuldade (número de dígitos na senha): \n");
                scanf("%d", &numDigits);
                difficulty = numDigits;
                score = numDigits * 100;

                int* secretNumber = (int*)malloc(numDigits * sizeof(int));
                for (int i = 0; i < numDigits; i++) {
                    secretNumber[i] = rand() % 10;
                }

                printf("A sequência de números foi gerada. Boa sorte!\n");

                int attempts = 0;
                int* guess = (int*)malloc(numDigits * sizeof(int));
                int corretos_posicao, corretos_errados;

                while (1) {
                    attempts++;
                    corretos_posicao = 0;
                    corretos_errados = 0;

                    printf("Tentativa %d: Digite uma sequência de %d dígitos: ", attempts, numDigits);

                    for (int i = 0; i < numDigits; i++) {
                        scanf("%d", &guess[i]);
                    }

                    for (int i = 0; i < numDigits; i++) {
                        if (guess[i] == secretNumber[i]) {
                            corretos_posicao++;
                        } else {
                            for (int j = 0; j < numDigits; j++) {
                                if (i != j && guess[i] == secretNumber[j]) {
                                    corretos_errados++;
                                }
                            }
                        }
                    }

                    if (corretos_posicao == numDigits) {
                        printf("Parabéns! Você acertou a senha em %d tentativas.\n", attempts);
                        break;
                    } else {
                        printf("Números corretos na posição certa: %d\n", corretos_posicao);
                        printf("Números corretos na posição errada: %d\n", corretos_errados);
                    }
                }

                free(secretNumber);
                free(guess);
                score -= (attempts - 1) * 10; // Penaliza tentativas adicionais

                // Verifica se o jogador já está no ranking, e se estiver, atualiza a pontuação.
                if (findPlayerAndUpdateScore(playerName, score) == 0) {
                    insertNode(playerName, score);
                }
                break;

            case 2:

                selectionSort(head);
                displayRanking();
                break;

            case 3:

                saveRanking();
                printf("Encerrando o jogo.\n");
                return 0;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}


void insertNode(char name[50], int score) {

    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } 
    else {
        Node *current = head;

        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void selectionSort(Node *start) {

    Node *traverse, *min;
    int tempScore;
    char tempName[50];

    for (traverse = start; traverse->next != NULL; traverse = traverse->next) {

        min = traverse;
        for (Node *ptr = traverse->next; ptr != NULL; ptr = ptr->next) {

            if (ptr->score < min->score) {

                min = ptr;
            }
        }

        if (min != traverse) {

            tempScore = traverse->score;
            strcpy(tempName, traverse->name);

            traverse->score = min->score;
            strcpy(traverse->name, min->name);

            min->score = tempScore;
            strcpy(min->name, tempName);
        }
    }
}

void displayRanking() {

    Node *current = head;
    int rank = 1;

    printf("\nRanking:\n");

    while (current != NULL) {

        printf("%d. %s - Score: %d\n", rank, current->name, current->score);
        current = current->next;
        rank++;
    }
}

void saveRanking() {

    FILE *file = fopen("ranking.txt", "w");
    Node *current = head;

    while (current != NULL) {

        fprintf(file, "%s %d\n", current->name, current->score);
        current = current->next;
    }

    fclose(file);
}

int findPlayerAndUpdateScore(char name[50], int score) {
    Node *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            
            current->score += score;
            return 1; 
        }
        current = current->next;
    }

    return 0;
}
