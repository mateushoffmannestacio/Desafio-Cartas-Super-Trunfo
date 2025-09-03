#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[50];
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    float area;
    long long int pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
};

void lerCarta(struct Carta *carta) {
    printf("Digite o nome do estado: ");
    scanf(" %[^\n]", carta->estado);
    printf("Digite o codigo da carta: ");
    scanf(" %[^\n]", carta->codigo);
    printf("Digite o nome da carta: ");
    scanf(" %[^\n]", carta->nome);
    printf("Digite a populacao (unsigned long int): ");
    scanf("%lu", &carta->populacao);
    printf("Digite a area (float): ");
    scanf("%f", &carta->area);
    printf("Digite o PIB (long long int): ");
    scanf("%lld", &carta->pib);
    printf("Digite o numero de pontos turisticos (int): ");
    scanf("%d", &carta->pontos_turisticos);
}

void calcularAtributos(struct Carta *carta) {
    if (carta->area > 0) {
        carta->densidade_populacional = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;
    }

    if (carta->populacao > 0) {
        carta->pib_per_capita = (float)carta->pib / carta->populacao;
    } else {
        carta->pib_per_capita = 0;
    }
}

void calcularSuperPoder(struct Carta *carta) {
    float inverso_densidade = 0;
    if (carta->densidade_populacional > 0) {
        inverso_densidade = 1.0f / carta->densidade_populacional;
    }

    carta->super_poder = (float)carta->populacao + carta->area + (float)carta->pib +
                         (float)carta->pontos_turisticos + carta->pib_per_capita +
                         inverso_densidade;
}

void exibirResultadoComparacao(const char *atributo, int resultado) {
    if (resultado == 1) {
        printf("%s: Carta 1 venceu (%d)\n", atributo, resultado);
    } else {
        printf("%s: Carta 2 venceu (%d)\n", atributo, resultado);
    }
}

int main() {
    struct Carta carta1, carta2;

    printf("--- Cadastro da Carta 1 ---\n");
    lerCarta(&carta1);
    calcularAtributos(&carta1);
    calcularSuperPoder(&carta1);

    printf("\n--- Cadastro da Carta 2 ---\n");
    lerCarta(&carta2);
    calcularAtributos(&carta2);
    calcularSuperPoder(&carta2);

    printf("\n--- Comparacao de Cartas ---\n");

    exibirResultadoComparacao("Populacao", carta1.populacao > carta2.populacao);
    
    exibirResultadoComparacao("Area", carta1.area > carta2.area);

    exibirResultadoComparacao("PIB", carta1.pib > carta2.pib);

    exibirResultadoComparacao("Pontos Turisticos", carta1.pontos_turisticos > carta2.pontos_turisticos);

    exibirResultadoComparacao("Densidade Populacional", carta1.densidade_populacional < carta2.densidade_populacional);

    exibirResultadoComparacao("PIB per Capita", carta1.pib_per_capita > carta2.pib_per_capita);

    exibirResultadoComparacao("Super Poder", carta1.super_poder > carta2.super_poder);

    return 0;
}