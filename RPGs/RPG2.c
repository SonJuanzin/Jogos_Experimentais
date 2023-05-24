#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int saude = 100;
    int inimigo_saude = 100;
    int opcao;

    // usar o tempo como semente para gerar numeros aleatorios
    srand(time(NULL));

    printf("Bem-vindo ao RPG\n");

    while (saude > 0 && inimigo_saude > 0) {
        printf("Sua saude: %d\n", saude);
        printf("Saude do inimigo: %d\n", inimigo_saude);
        printf("Escolha uma opcao:\n");
        printf("1. Atacar\n");
        printf("2. Defender\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Voce atacou o inimigo!\n");
                inimigo_saude -= rand() % 20 + 10; // causar dano aleatorio
                break;
            case 2:
                printf("Voce se defendeu!\n");
                saude += rand() % 10 + 5; // curar-se aleatoriamente
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

        if (inimigo_saude <= 0) {
            printf("Voce venceu!\n");
        } else {
            printf("O inimigo atacou!\n");
            saude -= rand() % 15 + 10; // causar dano aleatorio
        }
    }

    if (saude <= 0) {
        printf("Voce perdeu!\n");
    }
}
