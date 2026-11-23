#ifndef PAINEL_H
#define PAINEL_H

#include "atendimento.h"

// Modulo 4: painel textual, sem alterar as senhas.
void mostrarPainel(const Sistema *sistema) {
    const char prioridades[] = {'U', 'P', 'N'};
    int quantidades[3] = {0};
    int atual = buscarEmAtendimento(sistema);

    puts("\n========== PAINEL DE CHAMADA ==========");
    if (atual == -1) {
        puts("Senha atualmente chamada: nenhuma.");
        puts("Categoria do atendimento: nenhuma.");
    } else {
        const Senha *senha = &sistema->senhas[atual];
        printf("Senha atualmente chamada: %c%03d\n", senha->prioridade, senha->numero);
        printf("Categoria do atendimento: %s\n", nomeCategoria(senha->prioridade));
    }

    puts("\nProximas senhas (ordem de chamada):");
    for (int categoria = 0; categoria < 3; categoria++) {
        for (int i = 0; i < sistema->totalSenhas; i++) {
            const Senha *senha = &sistema->senhas[i];
            if (senha->estado == AGUARDANDO && senha->prioridade == prioridades[categoria]) {
                printf("%c%03d | %s\n", senha->prioridade,
                       senha->numero, nomeCategoria(senha->prioridade));
                quantidades[categoria]++;
            }
        }
    }
    int total = quantidades[0] + quantidades[1] + quantidades[2];
    if (total == 0) puts("Nenhuma senha aguardando chamada.");
    printf("\nEm espera: U = %d | P = %d | N = %d | Total = %d\n",
           quantidades[0], quantidades[1], quantidades[2], total);
    printf("Total emitido: %d | U = %d | P = %d | N = %d\n",
           sistema->totalSenhas, sistema->totalUrgente,
           sistema->totalPreferencial, sistema->totalNormal);
    puts("======================================");
}

#endif
