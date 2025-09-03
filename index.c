#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta
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

// Função para ler os dados de uma carta
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

// Função para calcular atributos derivados (densidade e PIB per capita)
void calcularAtributos(struct Carta *carta) {
    // Calculando a densidade populacional
    if (carta->area > 0) {
        carta->densidade_populacional = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;
    }

    // Calculando o PIB per capita
    if (carta->populacao > 0) {
        carta->pib_per_capita = (float)carta->pib / carta->populacao;
    } else {
        carta->pib_per_capita = 0;
    }
}

// Função para calcular o Super Poder
void calcularSuperPoder(struct Carta *carta) {
    // Super Poder: população + área + PIB + pontos turísticos + PIB per capita + inverso da densidade
    float inverso_densidade = 0;
    if (carta->densidade_populacional > 0) {
        inverso_densidade = 1.0f / carta->densidade_populacional;
    }

    carta->super_poder = (float)carta->populacao + carta->area + (float)carta->pib +
                         (float)carta->pontos_turisticos + carta->pib_per_capita +
                         inverso_densidade;
}

// Função para exibir o resultado da comparação
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

    // Comparação de População
    exibirResultadoComparacao("Populacao", carta1.populacao > carta2.populacao);
    
    // Comparação de Área
    exibirResultadoComparacao("Area", carta1.area > carta2.area);

    // Comparação de PIB
    exibirResultadoComparacao("PIB", carta1.pib > carta2.pib);

    // Comparação de Pontos Turísticos
    exibirResultadoComparacao("Pontos Turisticos", carta1.pontos_turisticos > carta2.pontos_turisticos);

    // Comparação de Densidade Populacional (menor valor vence)
    exibirResultadoComparacao("Densidade Populacional", carta1.densidade_populacional < carta2.densidade_populacional);

    // Comparação de PIB per Capita
    exibirResultadoComparacao("PIB per Capita", carta1.pib_per_capita > carta2.pib_per_capita);

    // Comparação de Super Poder
    exibirResultadoComparacao("Super Poder", carta1.super_poder > carta2.super_poder);

    return 0;
}
