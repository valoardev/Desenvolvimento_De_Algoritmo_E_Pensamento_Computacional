#include <stdio.h>  // inclui funções de entrada e saída
#include <stdlib.h> // inclui rand() e srand()
#include <time.h>   // inclui time()
#include <math.h>   // inclui log() e isfinite()

// Função para calcular a média das temperaturas realmente captadas
double calculaMedia(double soma, int quantidade) {
    double media;

    media = soma / quantidade;

    return media;
}

// Função para verificar qual é a maior temperatura
double verificaMaior(double temperatura, double maior) {
    if (temperatura > maior) {
        maior = temperatura;
    }

    return maior;
}

// Função para verificar qual é a menor temperatura
double verificaMenor(double temperatura, double menor) {
    if (temperatura < menor) {
        menor = temperatura;
    }

    return menor;
}

// Função para identificar se a temperatura ficou acima do limite
int verificaLimite(double temperatura, double tempMax) {
    if (temperatura > tempMax) {
        return 1;
    } else {
        return 0;
    }
}

// Função para apresentar o relatório final do monitoramento
void apresentaRelatorio(double tempMax, double soma, int quantidade,
                        double maior, double menor, int acimaLimite) {
    double media;
    double percentual;

    printf("\n========== RELATÓRIO FINAL ==========\n");
    printf("Limite de temperatura definido: %.2f °C\n", tempMax);
    printf("Quantidade de temperaturas válidas: %d\n", quantidade);

    // Evita a divisão por zero caso não existam temperaturas válidas
    if (quantidade > 0) {
        media = calculaMedia(soma, quantidade);
        percentual = (acimaLimite * 100.0) / quantidade;

        printf("Média das temperaturas: %.2f °C\n", media);
        printf("Maior temperatura captada: %.2f °C\n", maior);
        printf("Menor temperatura captada: %.2f °C\n", menor);
        printf("Quantidade acima do limite: %d\n", acimaLimite);
        printf("Percentual acima do limite: %.2f%%\n", percentual);
    } else {
        printf("Nenhuma temperatura válida foi captada.\n");
    }
}

// Função de geração e monitoramento das temperaturas aleatórias
void captaTemperatura(double tempMax) {
    double soma = 0;
    int contador = 0;
    double temperatura;
    double aleatorio;
    double maior = 0;
    double menor = 0;
    int acimaLimite = 0;
    int consecutivas = 0;

    do {
        // Gera um número aleatório maior que 0 e menor que 1
        aleatorio = (rand() + 1.0) / (RAND_MAX + 2.0);

        // Converte o número aleatório em temperatura,
        // respeitando o limite mínimo de -273.15 °C
        temperatura = -273.15 + (-log(aleatorio) * 300.0);

        // Soma as temperaturas e conta as leituras realizadas
        soma += temperatura;
        contador++;

        // Usa a primeira leitura válida para iniciar o maior e o menor
        if (contador == 1) {
            maior = temperatura;
            menor = temperatura;
        } else {
            maior = verificaMaior(temperatura, maior);
            menor = verificaMenor(temperatura, menor);
        }

        // Exibe a temperatura com duas casas decimais
        printf("Leitura %d: | %.2f °C | ", contador, temperatura);

        // Identifica e conta as temperaturas acima do limite
        if (verificaLimite(temperatura, tempMax) == 1) {
            acimaLimite++;
            consecutivas++;
            printf("Acima do limite | Consecutivas: %d\n", consecutivas);
        } else {
            // Uma leitura igual ou abaixo do limite reinicia a sequência
            consecutivas = 0;
            printf("Dentro do limite | Consecutivas: 0\n");
        }
    } while (contador < 20 && consecutivas < 3);

    // Informa o motivo do encerramento antes de apresentar o relatório
    if (consecutivas == 3) {
        printf("\nO sistema identificou 3 temperaturas consecutivas acima do limite.\n");
        printf("O programa foi finalizado como forma de proteção.\n");
    } else {
        printf("\nAs 20 leituras foram concluídas.\n");
        printf("O programa foi finalizado normalmente.\n");
    }

    // Apresenta os resultados usando somente as leituras realizadas
    apresentaRelatorio(tempMax, soma, contador, maior, menor, acimaLimite);
}

// Função principal
int main(void) {
    double tempMax = 0;
    int leitura;
    int entradaValida;
    int caractere;

    // Inicializa o gerador de números aleatórios uma vez por execução
    srand(time(NULL));

    printf("Use ponto para separar as casas decimais.\n");

    // Solicita o limite pelo menos uma vez e repete enquanto for inválido
    do {
        printf("Digite a temperatura máxima em °C suportada para o sistema: ");
        leitura = scanf("%lf", &tempMax);

        // Encerra caso a entrada termine antes de receber um limite válido
        if (leitura == EOF) {
            printf("\nEntrada encerrada. O monitoramento não foi iniciado.\n");
            return 0;
        }

        entradaValida = 1;

        // Limpa o restante da linha e rejeita conteúdos como 50abc ou 50,5
        caractere = getchar();
        while (caractere != '\n' && caractere != EOF) {
            if (caractere != ' ' && caractere != '\t' && caractere != '\r') {
                entradaValida = 0;
            }
            caractere = getchar();
        }

        // Verifica se foi digitado um número finito e maior ou igual ao zero absoluto
        if (leitura != 1 || !isfinite(tempMax) || tempMax < -273.15) {
            entradaValida = 0;
        }

        if (entradaValida == 0) {
            printf("\nEntrada inválida! Digite um número maior ou igual a -273.15 °C.\n");
        }
    } while (entradaValida == 0);

    printf("\nAs temperaturas captadas foram:\n");

    // Chama a função que capta as temperaturas e apresenta o relatório
    captaTemperatura(tempMax);

    return 0;
}
