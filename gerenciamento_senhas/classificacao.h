#ifndef CLASSIFICACAO_H
#define CLASSIFICACAO_H

// Modulo 2: dados do paciente e regras didaticas de classificacao.
typedef struct {
    int id;
    char nome[100];
    int idade;
    char genero;
    char gestante;
    char lactante;
    char necessidadeEspecial;
    char obesidade;
} Usuario;

char classificarPrioridade(Usuario usuario) {
    // A urgencia por idade sempre prevalece sobre as outras condicoes.
    if (usuario.idade > 80) {
        return 'U';
    }

    if (usuario.gestante == 's' || usuario.lactante == 's' ||
        usuario.necessidadeEspecial == 's' || usuario.obesidade == 's' ||
        (usuario.genero == 'f' && usuario.idade >= 60) ||
        (usuario.genero == 'm' && usuario.idade >= 65)) {
        return 'P';
    }

    return 'N';
}

const char *nomeCategoria(char prioridade) {
    if (prioridade == 'U') return "Urgente";
    if (prioridade == 'P') return "Preferencial";
    return "Normal";
}

#endif
