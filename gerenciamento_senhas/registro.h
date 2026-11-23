#ifndef REGISTRO_H
#define REGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include "classificacao.h"

// Modulo 1: entrada, cadastro e emissao de senhas.
#define MAX_CADASTROS 100
#define MAX_SENHAS 100

typedef enum { AGUARDANDO, EM_ATENDIMENTO, FINALIZADA } EstadoSenha;

typedef struct {
    int idUsuario;
    char prioridade;
    int numero;
    EstadoSenha estado;
    char descricao[500];
} Senha;

typedef struct {
    Usuario usuarios[MAX_CADASTROS];
    Senha senhas[MAX_SENHAS];
    int totalCadastros;
    int totalSenhas;
    int totalNormal;
    int totalPreferencial;
    int totalUrgente;
} Sistema;

// Le uma linha completa, retira espacos das pontas e rejeita texto longo.
// Retorna 0 apenas quando a entrada termina (EOF ou erro de leitura).
int lerTexto(const char *mensagem, char texto[], int tamanho) {
    while (1) {
        printf("%s", mensagem);
        fflush(stdout);
        if (fgets(texto, tamanho, stdin) == NULL) return 0;

        if (strchr(texto, '\n') == NULL) {
            int c = getchar();
            if (c != '\n' && c != EOF) {
                while ((c = getchar()) != '\n' && c != EOF) {}
                printf("Texto muito longo! Limite: %d caracteres.\n", tamanho - 1);
                continue;
            }
        }

        size_t inicio = 0;
        size_t fim = strlen(texto);
        while (inicio < fim && isspace((unsigned char)texto[inicio])) inicio++;
        while (fim > inicio && isspace((unsigned char)texto[fim - 1])) fim--;
        memmove(texto, texto + inicio, fim - inicio);
        texto[fim - inicio] = '\0';
        if (texto[0] != '\0') return 1;
        puts("O campo nao pode ficar vazio.");
    }
}

int lerInteiro(const char *mensagem, int minimo, int maximo, int *numero) {
    char texto[64];
    char *fim;
    while (lerTexto(mensagem, texto, sizeof(texto))) {
        errno = 0;
        long valor = strtol(texto, &fim, 10);
        if (errno != ERANGE && fim != texto && *fim == '\0' &&
            valor >= minimo && valor <= maximo) {
            *numero = (int)valor;
            return 1;
        }
        printf("Digite um inteiro entre %d e %d.\n", minimo, maximo);
    }
    return 0;
}

void converterMinusculo(char texto[]) {
    for (int i = 0; texto[i] != '\0'; i++) {
        texto[i] = (char)tolower((unsigned char)texto[i]);
    }
}

char perguntar(const char *mensagem) {
    char resposta[16];
    while (lerTexto(mensagem, resposta, sizeof(resposta))) {
        converterMinusculo(resposta);
        if (strcmp(resposta, "s") == 0 || strcmp(resposta, "sim") == 0) return 's';
        if (strcmp(resposta, "n") == 0 || strcmp(resposta, "nao") == 0) return 'n';
        puts("Resposta invalida! Digite S ou N.");
    }
    return '\0';
}

int buscarUsuario(const Sistema *sistema, int id) {
    for (int i = 0; i < sistema->totalCadastros; i++) {
        if (sistema->usuarios[i].id == id) return i;
    }
    return -1;
}

// Emite para um cadastro existente, sem alterar os dados do usuario.
// Retorna -1 para ID inexistente/limite e -2 para senha ainda ativa.
int gerarSenha(Sistema *sistema, int idUsuario) {
    int usuario = buscarUsuario(sistema, idUsuario);
    if (usuario == -1 || sistema->totalSenhas >= MAX_SENHAS) return -1;

    for (int i = 0; i < sistema->totalSenhas; i++) {
        if (sistema->senhas[i].idUsuario == idUsuario &&
            sistema->senhas[i].estado != FINALIZADA) return -2;
    }

    Senha nova = {0};
    nova.idUsuario = idUsuario;
    nova.prioridade = classificarPrioridade(sistema->usuarios[usuario]);
    nova.estado = AGUARDANDO;

    if (nova.prioridade == 'U') nova.numero = ++sistema->totalUrgente;
    else if (nova.prioridade == 'P') nova.numero = ++sistema->totalPreferencial;
    else nova.numero = ++sistema->totalNormal;

    int posicao = sistema->totalSenhas;
    sistema->senhas[sistema->totalSenhas++] = nova;
    return posicao;
}

void cadastrarUsuario(Sistema *sistema) {
    if (sistema->totalCadastros >= MAX_CADASTROS) {
        puts("\nLimite de cadastros desta execucao atingido!");
        return;
    }

    Usuario novo = {0};
    char genero[16];
    puts("\n--- Cadastro de usuario ---");
    if (!lerTexto("Nome do paciente: ", novo.nome, sizeof(novo.nome))) return;
    if (!lerInteiro("Idade em anos completos: ", 0, INT_MAX, &novo.idade)) return;

    while (1) {
        if (!lerTexto("Genero [M - Masculino / F - Feminino / O - Outro]: ",
                      genero, sizeof(genero))) return;
        converterMinusculo(genero);
        if (strcmp(genero, "m") == 0 || strcmp(genero, "f") == 0 ||
            strcmp(genero, "o") == 0) {
            novo.genero = genero[0];
            break;
        }
        puts("Opcao invalida! Digite M, F ou O.");
    }

    novo.gestante = 'n';
    // Para F ou O, permite informar gestacao quando aplicavel.
    if (novo.genero != 'm') {
        novo.gestante = perguntar("Gestante? [S/N; N se nao se aplica]: ");
        if (novo.gestante == '\0') return;
    }
    novo.lactante = perguntar("Lactante? [S/N]: ");
    if (novo.lactante == '\0') return;
    novo.necessidadeEspecial = perguntar("Possui necessidade especial? [S/N]: ");
    if (novo.necessidadeEspecial == '\0') return;
    novo.obesidade = perguntar("Possui condicao de obesidade? [S/N]: ");
    if (novo.obesidade == '\0') return;

    novo.id = sistema->totalCadastros + 1;
    sistema->usuarios[sistema->totalCadastros++] = novo;
    printf("\nUsuario cadastrado: %s | ID: %d\n", novo.nome, novo.id);
    puts("Use este ID na opcao 2 - Retirar senha do menu principal.");
}

void registrarSenha(Sistema *sistema) {
    if (sistema->totalCadastros == 0) {
        puts("\nNenhum usuario cadastrado. Use a opcao 1 do menu principal.");
        return;
    }

    int id;
    puts("\n--- Retirada de senha ---");
    if (!lerInteiro("ID do usuario cadastrado: ", 1, INT_MAX, &id)) return;
    int usuario = buscarUsuario(sistema, id);
    if (usuario == -1) {
        puts("Usuario nao encontrado. Confira o ID ou cadastre-se na opcao 1.");
        return;
    }

    int posicao = gerarSenha(sistema, id);
    if (posicao == -2) {
        puts("Este usuario ja possui uma senha aguardando ou em atendimento.");
        return;
    }
    if (posicao == -1) {
        puts("Nao foi possivel registrar a senha: limite atingido.");
        return;
    }
    Senha senha = sistema->senhas[posicao];
    printf("\nPaciente: %s | ID: %d\n",
           sistema->usuarios[usuario].nome, senha.idUsuario);
    printf("Senha emitida: %c%03d | Categoria: %s\n",
           senha.prioridade, senha.numero, nomeCategoria(senha.prioridade));
    puts("Aguarde ser chamado.");
}

#endif
