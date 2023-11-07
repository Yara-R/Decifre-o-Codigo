#include <stdio.h>
#include <stdlib.h>
#include "MyLibs.h"


int mainMenu(){
  int option = 10;

  while (option != 0) {
      system("clear"); // limpa a tela

      printf("███████████████████████████████████████████████████████\n");
      printf("████████████████████████ JOGO █████████████████████████\n");
      printf("███████████████████████████████████████████████████████\n");
      printf("█████████████████ DECIFRE O CODIGO ████████████████████\n");     
      printf("███████████████████████████████████████████████████████\n\n");    


      printf("Digite a opção desejada: \n\n1 - JOGAR \n2 - CLASSIFICAÇÃO \n3 - REGRAS DO JOGO \n0 - SAIR JOGO\n");
      printf("\n");
      scanf("%d", &option);

      switch (option) {
          case 1: 
              mainJogo();
              break;
          case 2: 
              mainRanking();
              break;
          case 3: 
              regrasJogo();
              break;
          case 0: 
              printf("Obrigada por jogar!");
              system("clear"); // limpar a tela
              return 0;
          default:
              printf("Opção Inválida. Digite novamente: ");
              scanf("%d", &option); 
              getchar();
              break;
      }
  }
  return 0;

}