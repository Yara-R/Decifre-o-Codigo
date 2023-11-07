#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "MyLibs.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main(){
    system("color 1F");
    system("clear"); // limpar a tela
    printf("\n\n");
    printf("      ██████╗ ███████╗ ██████╗██╗███████╗██████╗ ███████╗\n");
    printf("      ██╔══██╗██╔════╝██╔════╝██║██╔════╝██║  ██╗██╔════╝\n");
    printf("      ██║  ██║█████╗  ██║     ██║███████╗███████║█████╗  \n");
    printf("      ██║  ██║██╔══╝  ██║     ██║██╔════╝██╔═██╔╝██╔══╝  \n");
    printf("      ██████╔╝███████╗╚██████╗██║██║     ██║ ╚██║███████╗\n");
    printf("      ╚═════╝ ╚══════╝ ╚═════╝╚═╝╚═╝     ╚═╝  ╚═╝╚══════╝\n");
    printf("\n\n");
    printf("                        ██████╗ \n");
    printf("                       ██╔═══██╗\n");
    printf("                       ██║   ██║\n");
    printf("                       ██║   ██║\n");
    printf("                       ╚██████╔╝\n");
    printf("                        ╚═════╝ \n");
    printf("\n\n\n\n");
    printf("       ██████╗ ██████╗ ██████╗ ██╗ ███████╗ ██████╗ \n");
    printf("      ██╔════╝██╔═══██╗██╔══██╗██║██╔═════╝██╔═══██╗\n");
    printf("      ██║     ██║   ██║██║  ██║██║██║  ███╗██║   ██║\n");
    printf("      ██║     ██║   ██║██║  ██║██║██║   ██║██║   ██║\n");
    printf("      ╚██████╗╚██████╔╝██████╔╝██║╚██████╔╝╚██████╔╝\n");
    printf("      ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝ ╚═════╝  ╚═════╝ \n");
    printf("\n\n");

    #ifdef _WIN32
        Sleep(5000);  // Espera 5 segundos (Windows)
    #else
        sleep(5);  // Espera 5 segundos (Unix)
    #endif

    mainMenu();


}