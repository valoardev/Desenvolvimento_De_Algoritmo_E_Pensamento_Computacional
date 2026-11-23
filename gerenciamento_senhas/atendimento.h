#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include "registro.h"

// Modulo 3: consulta, chamada, finalizacao e historico.
int buscarEmAtendimento(const Sistema *sistema) {
    for (int i = 0; i < sistema->totalSenhas; i++) {
        if (sistema->senhas[i].estado == EM_ATENDIMENTO) return i;
    }
    return -1;
}

int buscarProximaSenha(const Sistema *sistema) {
    const char prioridades[] = {'U', 'P', 'N'};
    for (int categoria = 0; categoria < 3; categoria++) {
        // O vetor mantem a ordem de emissao: a primeira pendente e a mais antiga.
        for (int i = 0; i < sistema->totalSenhas; i++) {
            if (sistema->senhas[i].estado == AGUARDANDO &&
                sistema->senhas[i].prioridade == prioridades[categoria]) return i;
        }
    }
    return -1;
}

void exibirDadosSenha(const Sistema *sistema, int posicao) {
    const Senha *senha = &sistema->senhas[posicao];
    int usuario = buscarUsuario(sistema, senha->idUsuario);
    printf("Senha: %c%03d | Categoria: %s\n", senha->prioridade,
           senha->numero, nomeCategoria(senha->prioridade));
    if (usuario != -1) {
        printf("Paciente: %s | ID: %d | Idade: %d\n",
               sistema->usuarios[usuario].nome, senha->idUsuario,
               sistema->usuarios[usuario].idade);
    }
}

void consultarProximaSenha(const Sistema *sistema) {
    int posicao = buscarProximaSenha(sistema);
    puts("\n--- Proxima senha aguardando ---");
    if (posicao == -1) puts("Nenhuma senha aguardando atendimento.");
    else exibirDadosSenha(sistema, posicao);
}

void consultarEmAtendimento(const Sistema *sistema) {
    int posicao = buscarEmAtendimento(sistema);
    puts("\n--- Senha em atendimento ---");
    if (posicao == -1) puts("Nenhuma senha em atendimento.");
    else exibirDadosSenha(sistema, posicao);
}

void chamarPaciente(Sistema *sistema) {
    if (buscarEmAtendimento(sistema) != -1) {
        puts("\nFinalize o atendimento atual antes de chamar outro paciente.");
        return;
    }
    int posicao = buscarProximaSenha(sistema);
    if (posicao == -1) {
        puts("\nNenhuma senha aguardando atendimento.");
        return;
    }
    sistema->senhas[posicao].estado = EM_ATENDIMENTO;
    puts("\n--- Paciente chamado ---");
    exibirDadosSenha(sistema, posicao);
}

void finalizarAtendimento(Sistema *sistema) {
    int posicao = buscarEmAtendimento(sistema);
    if (posicao == -1) {
        puts("\nNenhum atendimento em andamento para finalizar.");
        return;
    }
    Senha *senha = &sistema->senhas[posicao];
    exibirDadosSenha(sistema, posicao);
    if (!lerTexto("Descreva o atendimento: ", senha->descricao,
                  sizeof(senha->descricao))) return;

    // Finalizadas permanecem no historico e nunca voltam a AGUARDANDO.
    senha->estado = FINALIZADA;
    printf("\nAtendimento da senha %c%03d finalizado!\n",
           senha->prioridade, senha->numero);
    // A consulta recalcula a fila considerando apenas as senhas aguardando.
    consultarProximaSenha(sistema);
}

void consultarAtendimentos(const Sistema *sistema) {
    int concluidos = 0;
    puts("\n--- Atendimentos concluidos ---");
    for (int i = 0; i < sistema->totalSenhas; i++) {
        if (sistema->senhas[i].estado == FINALIZADA) {
            exibirDadosSenha(sistema, i);
            printf("Descricao: %s\n\n", sistema->senhas[i].descricao);
            concluidos++;
        }
    }
    printf("Total de atendimentos concluidos: %d\n", concluidos);
}

// Reune as operacoes de atendimento em uma unica opcao do menu principal.
void menuAtendimento(Sistema *sistema) {
    int opcao;

    while (1) {
        puts("\n--- Atendimento ---");
        puts("1 - Consultar proxima senha");
        puts("2 - Chamar proximo paciente");
        puts("3 - Consultar senha em atendimento");
        puts("4 - Finalizar atendimento");
        puts("5 - Consultar atendimentos concluidos");
        puts("0 - Voltar ao menu principal");

        if (!lerInteiro("Opcao: ", 0, INT_MAX, &opcao)) return;

        switch (opcao) {
            case 1: consultarProximaSenha(sistema); break;
            case 2: chamarPaciente(sistema); break;
            case 3: consultarEmAtendimento(sistema); break;
            case 4: finalizarAtendimento(sistema); break;
            case 5: consultarAtendimentos(sistema); break;
            case 0: return;
            default: puts("Opcao invalida!");
        }
    }
}

#endif
