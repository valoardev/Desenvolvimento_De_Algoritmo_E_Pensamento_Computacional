#include <stdio.h>

int main(void) {
    int numeros[20];
    int i;
    int somaMultiplosDe3 = 0;
    int somaPares = 0;
    int quantidadePares = 0;
    int positivos = 0;
    int negativos = 0;
    int maior, menor;
    double mediaPares;

    printf("=== ANALISE DE 20 NUMEROS INTEIROS ===\n\n");

    // Primeiro, vamos guardar os 20 numeros no vetor.
    for (i = 0; i < 20; i++) {
        printf("Digite o %dº numero: ", i + 1);
        if (scanf("%d", &numeros[i]) != 1) {
            printf("\nEntrada invalida. Execute novamente e digite apenas inteiros.\n");
            return 1;
        }
    }

    // Comecamos pelo primeiro numero, porque ele ja esta no vetor.
    // Assim, a comparacao funciona mesmo se todos forem negativos.
    maior = numeros[0];
    menor = numeros[0];

    for (i = 0; i < 20; i++) {
        // Se a divisao por 3 nao deixa resto, somamos esse numero.
        if (numeros[i] % 3 == 0) {
            somaMultiplosDe3 += numeros[i];
        }

        // Guardamos a soma e a quantidade dos pares para tirar a media depois.
        if (numeros[i] % 2 == 0) {
            somaPares += numeros[i];
            quantidadePares++;
        }

        // O zero fica de fora das duas contagens.
        if (numeros[i] > 0) {
            positivos++;
        } else if (numeros[i] < 0) {
            negativos++;
        }

        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    printf("\n=== RESULTADOS ===\n");
    printf("Soma dos multiplos de 3: %d\n", somaMultiplosDe3);

    // So fazemos a divisao se apareceu pelo menos um numero par.
    if (quantidadePares > 0) {
        mediaPares = (double) somaPares / quantidadePares;
        printf("Media dos numeros pares: %.2f\n", mediaPares);
    } else {
        printf("Media dos numeros pares: nao ha numeros pares.\n");
    }

    printf("Quantidade de positivos: %d\n", positivos);
    printf("Quantidade de negativos: %d\n", negativos);
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    // Por ultimo, mostramos tudo na mesma ordem em que foi digitado.
    printf("Elementos do vetor: ");
    for (i = 0; i < 20; i++) {
        printf("%d", numeros[i]);
        if (i < 19) {
            printf(" | ");
        }
    }
    printf("\n");

    return 0;
}
