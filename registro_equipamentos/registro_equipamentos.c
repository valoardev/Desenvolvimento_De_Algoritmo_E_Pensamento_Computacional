
#include <stdio.h>

int main() {
    // Variáveis
    FILE *arquivo;
    char equipamento[100];
    char linha[100];
    int id;
    int loc;
    char continuar;
    char listar;

    do {
        // Recebe o nome do equipamento
        printf("\nDigite o nome do equipamento: ");
        fgets(equipamento, sizeof(equipamento), stdin);

        // Recebe o ID do equipamento
        printf("\nDigite o código de identificação de 4 dígitos: ");
        while (scanf("%d", &id) != 1 || id <= 999 || id > 9999) {
            printf("\nID inválido! Digite um número de 1000 a 9999: ");
        }

        // Recebe a localização do equipamento
        printf("\nDigite o número da seção do equipamento de 3 dígitos: ");
        while (scanf("%d", &loc) != 1 || loc <= 99 || loc > 999) {
            printf("\nSeção inválida! Digite um número de 100 a 999: ");
        }
        
        // Limpa o Enter que ficou após a leitura da seção
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }

        // Abre o arquivo para acrescentar dados
        arquivo = fopen("equipamentos.txt", "a");

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            return 1;
        }

        // Grava os registros no arquivo
        fprintf(arquivo, "===\n");
        fprintf(arquivo, "Nome: %s", equipamento);
        fprintf(arquivo, "ID: %d\n", id);
        fprintf(arquivo, "Seção: %d\n\n", loc);

        // Fecha o arquivo
        fclose(arquivo);

        printf("\nEquipamento registrado com sucesso!\n");

        // Pergunta se deseja cadastrar outro equipamento
        printf("\nDeseja cadastrar outro equipamento? (s/n): ");
        scanf(" %c", &continuar);
        
        while ((c = getchar()) != '\n' && c != EOF) {
        }

    } while (continuar == 's' || continuar == 'S');

    printf("\nCadastro finalizado!\n");
    printf("Deseja listar os equipamentos cadastrados? (s/n): ");
    scanf(" %c", &listar);
    if (listar == 's' || listar == 'S') {
        // Abre o arquivo para consultar os registros
        arquivo = fopen("equipamentos.txt", "r");

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            return 1;
        } 
        
        printf("\n=== Equipamentos Registrados ===\n\n");
        
        // faz a listagem dos registros
        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
        }
        
        fclose(arquivo);
        printf("\n=== Fim dos Registros ===\n");
    }
    return 0;
}
