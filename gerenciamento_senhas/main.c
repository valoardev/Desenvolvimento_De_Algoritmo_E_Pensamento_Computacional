// Sistema didatico de gerenciamento de senhas de uma clinica.
// As regras de prioridade desta atividade nao substituem avaliacao clinica.
#include "registro.h"
#include "classificacao.h"
#include "atendimento.h"
#include "painel.h"

int main(void) {
    Sistema sistema = {0};
    int opcao;

    while (1) {
        puts("\n--- Clinica Medica ---");
        puts("1 - Cadastrar usuario");
        puts("2 - Retirar senha");
        puts("3 - Atendimento");
        puts("4 - Mostrar painel de chamada");
        puts("0 - Sair");

        if (!lerInteiro("Opcao: ", 0, INT_MAX, &opcao)) return 0;

        switch (opcao) {
            case 1: cadastrarUsuario(&sistema); break;
            case 2: registrarSenha(&sistema); break;
            case 3: menuAtendimento(&sistema); break;
            case 4: mostrarPainel(&sistema); break;
            case 0: puts("Programa encerrado."); return 0;
            default: puts("Opcao invalida!");
        }
    }
}
