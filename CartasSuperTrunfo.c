#include <stdio.h>


typedef struct {
    char estado[30]; // Nome do estado
    char codigo[10]; // Código da carta
    char nome[50]; // Nome da cidade
    int populacao; // Número de habitantes
    float area; // Tamanho da cidade em km²
    float pib; // Produto Interno Bruto (dinheiro que a cidade gera)
    int pontos_turisticos; // Quantidade de lugares famosos
    float densidade_populacional; // População dividida pela área
    float pib_per_capita; // PIB dividido pela população
} Carta;

void calcular_indicadores(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}


void mostrar_carta(Carta carta) {
    printf("Cidade: %s (%s)\n", carta.nome, carta.estado);
    printf("População: %d pessoas\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per capita: %.2f\n", carta.pib_per_capita);
    printf("-----------------------------\n");
}

int main() {
   
    Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.11, 2300.50, 50};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1200.27, 1200.75, 40};

   
    calcular_indicadores(&carta1);
    calcular_indicadores(&carta2);

    
    printf("Dados das cartas:\n");
    mostrar_carta(carta1);
    mostrar_carta(carta2);

    char atributo_escolhido[] = "PIB";
    float valor1 = carta1.pib;
    float valor2 = carta2.pib;

    printf("Comparação de cartas (Atributo: %s):\n\n", atributo_escolhido);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, valor2);

    if (valor1 > valor2) {
        printf("\nResultado: A carta 1 (%s) venceu!\n", carta1.nome);
    } else if (valor2 > valor1) {
        printf("\nResultado: A carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("\nResultado: Deu empate!\n");
    }

    return 0;
}
