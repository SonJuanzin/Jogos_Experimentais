#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define as constantes para cada classe
#define MAGO 1
#define ARQUEIRO 2
#define GUERREIRO 3

// Define as constantes para cada inimigo
#define GOBLIN 1
#define ORC 2
#define DRAGAO 3

// Define as constantes para cada ataque
#define ATAQUE_MAGIA 1
#define ATAQUE_FLECHA 2
#define ATAQUE_ESPADA 3

// Define as constantes de saúde e dano
#define SAUDE_MAXIMA 100
#define DANO_MINIMO 10
#define DANO_MAXIMO 20
#define SAUDE_BOSS 150
#define DANO_BOSS_MINIMO 20
#define DANO_BOSS_MAXIMO 30

// Função para imprimir as opções do menu
void imprimir_menu() {
    printf("Escolha uma opcao:\n");
    printf("1. Atacar com magia\n");
    printf("2. Atacar com flecha\n");
    printf("3. Atacar com espada\n");
    printf("Opcao: ");
}

// Função para imprimir a mensagem de fim de jogo
void imprimir_fim_de_jogo(int vitoria) {
    if (vitoria) {
        printf("Voce venceu! Parabens!\n");
    } else {
        printf("Voce perdeu! Tente novamente!\n");
    }
}

int main() {
    int classe, inimigo, ataque;
    int saude = SAUDE_MAXIMA;
    int dano_minimo, dano_maximo;
    int saude_inimigo, dano_inimigo_minimo, dano_inimigo_maximo;
    int vitoria = 1;

    // Usa o tempo como semente para gerar números aleatórios
    srand(time(NULL));

    printf("Bem-vindo ao RPG!\n");

    // Escolhe a classe do personagem
    printf("Escolha sua classe:\n");
    printf("1. Mago\n");
    printf("2. Arqueiro\n");
    printf("3. Guerreiro\n");
    printf("Classe: ");
    scanf("%d", &classe);

    // Define as informações de acordo com a classe escolhida
    switch (classe) {
        case MAGO:
            printf("Voce escolheu a classe Mago!\n");
            dano_minimo = DANO_MINIMO + 5;
            dano_maximo = DANO_MAXIMO + 5;
            break;
        case ARQUEIRO:
            printf("Voce escolheu a classe Arqueiro!\n");
            dano_minimo = DANO_MINIMO + 3;
            dano_maximo = DANO_MAXIMO + 3;
            break;
        case GUERREIRO:
            printf("Voce escolheu a classe Guerreiro!\n");
            dano_minimo = DANO_MINIMO + 1;
            dano_maximo = DANO_MAXIMO + 1;
            break;
        default:
            printf("Classe invalida!\n");
            return 0;
    }

    // Enfrenta cada inimigo em ordem
    for (inimigo = GOBLIN; inimigo <= DRAGAO; inimigo++) {

            // Define as informações de acordo com o inimigo atual
        switch (inimigo) {
            case GOBLIN:
                printf("Voce encontrou um Goblin!\n");
                saude_inimigo = SAUDE_MAXIMA / 2;
                dano_inimigo_minimo = DANO_MINIMO / 2;
                dano_inimigo_maximo = DANO_MAXIMO / 2;
                break;
            case ORC:
                printf("Voce encontrou um Orc!\n");
                saude_inimigo = SAUDE_MAXIMA * 3 / 4;
                dano_inimigo_minimo = DANO_MINIMO * 3 / 4;
                dano_inimigo_maximo = DANO_MAXIMO * 3 / 4;
                break;
            case DRAGAO:
                printf("Voce encontrou um Dragao!\n");
                saude_inimigo = SAUDE_MAXIMA;
                dano_inimigo_minimo = DANO_MINIMO;
                dano_inimigo_maximo = DANO_MAXIMO;
                break;
        }

        // Luta contra o inimigo atual
        while (saude > 0 && saude_inimigo > 0) {
            // Imprime a saúde atual dos combatentes
            printf("Sua saude: %d\n", saude);
            printf("Saude do inimigo: %d\n", saude_inimigo);

            // Pede para o usuário escolher um ataque
            imprimir_menu();
            scanf("%d", &ataque);

            // Executa o ataque escolhido
            switch (ataque) {
                case ATAQUE_MAGIA:
                    printf("Voce usou magia!\n");
                    saude_inimigo -= rand() % (dano_maximo - dano_minimo + 1) + dano_minimo;
                    break;
                case ATAQUE_FLECHA:
                    printf("Voce usou flecha!\n");
                    saude_inimigo -= rand() % (dano_maximo - dano_minimo + 1) + dano_minimo;
                    break;
                case ATAQUE_ESPADA:
                    printf("Voce usou espada!\n");
                    saude_inimigo -= rand() % (dano_maximo - dano_minimo + 1) + dano_minimo;
                    break;
                default:
                    printf("Ataque invalido!\n");
                    break;
            }

            // O inimigo ataca de volta
            if (saude_inimigo > 0) {
                printf("O inimigo ataca!\n");
                saude -= rand() % (dano_inimigo_maximo - dano_inimigo_minimo + 1) + dano_inimigo_minimo;
            }
        }

        // Checa se o personagem venceu a luta
        if (saude > 0) {
            printf("Voce venceu o inimigo!\n");
        } else {
            printf("Voce foi derrotado pelo inimigo!\n");
            vitoria = 0;
            break;
        }

        // Restaura a saúde do personagem para a próxima luta
        saude = SAUDE_MAXIMA;
    }

    // Luta contra o chefe final
    if (vitoria) {
        printf("Voce chegou ao chefao final!\n");

        // Define as informações do chefe final
        saude_inimigo =         printf("Saude do chefao final: %d\n", SAUDE_MAXIMA * 2);
        dano_inimigo_minimo = DANO_MINIMO * 2;
        dano_inimigo_maximo = DANO_MAXIMO * 2;

        // Luta contra o chefe final
        while (saude > 0 && saude_inimigo > 0) {
            // Imprime a saúde atual dos combatentes
            printf("Sua saude: %d\n", saude);
            printf("Saude do chefao final: %d\n", saude_inimigo);

            // Pede para o usuário escolher um ataque
            imprimir_menu();
            scanf("%d", &ataque);

            // Executa o ataque escolhido
            switch (ataque) {
                case ATAQUE_MAGIA:
                    printf("Voce usou magia!\n");
                    saude_inimigo -= rand() % (dano_maximo - dano_minimo + 1) + dano_minimo;
                    break;
                case ATAQUE_FLECHA:
                    printf("Voce usou flecha!\n");
                    saude_inimigo -= rand() % (dano_maximo - dano_minimo + 1) + dano_minimo;
                    break;
                case ATAQUE_ESPADA:
                    printf("Voce usou espada!\n");
                    saude_inimigo -= rand() % (dano_maximo - dano_minimo + 1) + dano_minimo;
                    break;
                default:
                    printf("Ataque invalido!\n");
                    break;
            }

            // O chefe final ataca de volta
            if (saude_inimigo > 0) {
                printf("O chefao final ataca!\n");
                saude -= rand() % (dano_inimigo_maximo - dano_inimigo_minimo + 1) + dano_inimigo_minimo;
            }
        }

        // Checa se o personagem venceu o jogo
        if (saude > 0) {
            printf("Parabens, voce venceu o jogo!\n");
        } else {
            printf("Voce foi derrotado pelo chefao final!\n");
        }
    }

    return 0;
}

