// Sistema de Gerenciamento de Senhas de Atendimento
// Clinica de Especialidades Medicas

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_CADASTROS 100
#define MAX_SENHAS 100

// Estrutura de armazaenagem de cada usuario
typedef struct {
	int id;
	char nome[100];
	int idade;
	char genero;
	char gestante;
	char necessidadeEspecial;
} Usuario;

// Estrutura de armazenagem de cada senha
typedef struct {
    int idUsuario;
    char prioridade;
    int numero;
    char atendida;
    char descricao[500];
} Senha;

// Define e guarda quantidade de Cadastros armazenados durante a execucao
Usuario usuarios[MAX_CADASTROS];
int totalCadastros = 0;

// Define e guarda quantidade de Senhas armazenadas durante a execucao
Senha senhas[MAX_SENHAS];
int totalSenhas = 0;

// Define contadores de senhas por categoria
int totalNormal = 0;
int totalPreferencial = 0;
int totalUrgente = 0;

// Função para Descartar o restante da linha digitada
void limparEntrada(void) {
	int caractere;

	while ((caractere = getchar()) != '\n' && caractere != EOF) {
		// Continua lendo ate encontrar o Enter ou o fim da entrada.
	}
}

// Função de Converter um texto para minusculo
void converterMinusculo(char texto[]) {
	for (int i = 0; texto[i] != '\0'; i++) {
		texto[i] = tolower((unsigned char)texto[i]);
	}
}

// Função para leitura de numero maior que zero padrão
int lerInteiroPositivo(void) {
	int numero;
	int resultado;

	while (1) {
		resultado = scanf("%d", &numero);

		if (resultado == EOF) {
			return 0;
		}

		limparEntrada();

		if (resultado == 1 && numero > 0) {
			return numero;
		}

		printf("Digite um numero inteiro maior que zero: ");
	}
}

// Função de Perguntas de Sim e Nao
char perguntar(void) {
	char resposta[10];

	while (1) {
		printf("Resposta [S/N]: ");

		if (scanf("%9s", resposta) != 1) {
			return '\0';
		}

		limparEntrada();
		converterMinusculo(resposta);

		if (strcmp(resposta, "sim") == 0 ||
		        strcmp(resposta, "s") == 0) {
			return 's';
		}

		if (strcmp(resposta, "nao") == 0 ||
		        strcmp(resposta, "n") == 0) {
			return 'n';
		}

		printf("Resposta invalida! Digite S ou N.\n");
	}
}

// Função de Cadastro de usuario
void cadastro(void) {
	if (totalCadastros >= MAX_CADASTROS) {
		printf("\nLimite de cadastros atingido!\n");
		return;
	}

	Usuario novo = {0};
	char genero[10];

	printf("\n--- Cadastro de usuario ---\n");

	// Nome
	printf("Qual o seu nome: ");

	if (scanf(" %99[^\n]", novo.nome) != 1) {
		return;
	}

	limparEntrada();

	// Idade
	printf("Qual a sua idade: ");
	novo.idade = lerInteiroPositivo();

	if (novo.idade == 0) {
		return;
	}

	// Genero
	while (1) {
		printf("Qual seu genero? [M - Masculino / F - Feminino / O - Outro]: ");

		if (scanf("%9s", genero) != 1) {
			return;
		}

		limparEntrada();
		converterMinusculo(genero);

		if (strcmp(genero, "m") == 0 ||
		        strcmp(genero, "f") == 0 ||
		        strcmp(genero, "o") == 0) {
			novo.genero = genero[0];
			break;
		}

		printf("Opcao invalida! Digite M, F ou O.\n");
	}

	// Gestacao
	novo.gestante = 'n';

	if (novo.genero == 'f') {
		printf("\nVoce esta gestante?\n");
		novo.gestante = perguntar();

		if (novo.gestante == '\0') {
			return;
		}
	}

	// Necessidade especial
	printf("\nVoce possui alguma necessidade especial?\n");
	novo.necessidadeEspecial = perguntar();

	if (novo.necessidadeEspecial == '\0') {
		return;
	}

	// Exibe os dados
	printf("\n--- Dados informados ---\n");
	printf("Nome: %s\n", novo.nome);
	printf("Idade: %d\n", novo.idade);

	if (novo.genero == 'm') {
		printf("Genero: Masculino\n");
	}
	else if (novo.genero == 'f') {
		printf("Genero: Feminino\n");
	}
	else {
		printf("Genero: Outro\n");
	}

	if (novo.genero == 'f') {
		if (novo.gestante == 's') {
			printf("Gestante: Sim\n");
		}
		else {
			printf("Gestante: Nao\n");
		}
	}

	if (novo.necessidadeEspecial == 's') {
		printf("Necessidade especial: Sim\n");
	}
	else {
		printf("Necessidade especial: Nao\n");
	}

	// Gera o ID e registra o usuario
	novo.id = totalCadastros + 1;
	usuarios[totalCadastros] = novo;
	totalCadastros++;

	printf("\nCadastro registrado com sucesso!\n");
	printf("Seu ID e: %d\n", novo.id);
}

// Função de Busca usuario pelo ID
int buscarUsuario(int id) {
	for (int i = 0; i < totalCadastros; i++) {
		if (usuarios[i].id == id) {
			return i;
		}
	}

	return -1;
}

// Funcao de classificacao de prioridade
char classificarPrioridade(Usuario usuario) {
    if (usuario.idade > 80) {
        return 'U';
    }
    else if (usuario.gestante == 's' ||
             usuario.necessidadeEspecial == 's') {
        return 'P';
    }
    else {
        return 'N';
    }
}

// Funcao de geracao de senha conforme a prioridade
void gerarSenha(Usuario usuario) {
    if (totalSenhas >= MAX_SENHAS) {
        printf("\nLimite de senhas atingido!\n");
        return;
    }

    Senha nova = {0};

    nova.idUsuario = usuario.id;
    nova.prioridade = classificarPrioridade(usuario);
    nova.atendida = 'n';

    if (nova.prioridade == 'U') {
        totalUrgente++;
        nova.numero = totalUrgente;
    }
    else if (nova.prioridade == 'P') {
        totalPreferencial++;
        nova.numero = totalPreferencial;
    }
    else {
        totalNormal++;
        nova.numero = totalNormal;
    }

    // Guarda a senha na proxima posicao disponivel
    senhas[totalSenhas] = nova;
    totalSenhas++;

    printf("\n--- Senha de Atendimento ---\n");
    printf("Paciente: %s\n", usuario.nome);
    printf("Codigo de espera: %c%03d\n",
           nova.prioridade, nova.numero);
    printf("Aguarde ser chamado.\n");
}

// Funcao de print da fila e retorna a posicao da primeira senha pendente
int mostrarFila(void) {
    int normais = 0;
    int preferenciais = 0;
    int urgentes = 0;
    int proxima = -1;

    char prioridades[3] = {'U', 'P', 'N'};

    // Conta somente as senhas que ainda aguardam atendimento
    for (int i = 0; i < totalSenhas; i++) {
        if (senhas[i].atendida == 'n') {
            if (senhas[i].prioridade == 'U') {
                urgentes++;
            }
            else if (senhas[i].prioridade == 'P') {
                preferenciais++;
            }
            else {
                normais++;
            }
        }
    }

    printf("\n--- Resumo das Senhas ---\n");
    printf("Total emitido: %d\n", totalSenhas);
    printf("Emitidas: U = %d | P = %d | N = %d\n",
           totalUrgente, totalPreferencial, totalNormal);

    printf("\nAguardando atendimento: %d\n",
           urgentes + preferenciais + normais);
    printf("Urgentes: %d\n", urgentes);
    printf("Preferenciais: %d\n", preferenciais);
    printf("Normais: %d\n", normais);

    printf("\n--- Fila de Atendimento ---\n");

    // Percorre primeiro U, depois P e por ultimo N
    for (int categoria = 0; categoria < 3; categoria++) {
        for (int i = 0; i < totalSenhas; i++) {
            if (senhas[i].atendida == 'n' &&
                senhas[i].prioridade == prioridades[categoria]) {

                printf("Senha: %c%03d | ID do usuario: %d\n",
                       senhas[i].prioridade,
                       senhas[i].numero,
                       senhas[i].idUsuario);

                // Guarda a primeira senha encontrada na fila
                if (proxima == -1) {
                    proxima = i;
                }
            }
        }
    }

    if (proxima == -1) {
        printf("Nenhuma senha aguardando atendimento.\n");
    }

    return proxima;
}

// Atende as senhas seguindo a ordem da fila
void registrarAtendimento(void) {
    printf("\n--- Registro de Atendimento ---\n");

    while (1) {
        int posicaoSenha = mostrarFila();

        // Volta ao menu quando nao houver senhas pendentes
        if (posicaoSenha == -1) {
            return;
        }

        int id = senhas[posicaoSenha].idUsuario;
        int posicaoUsuario = buscarUsuario(id);

        if (posicaoUsuario == -1) {
            printf("\nCadastro do usuario nao encontrado.\n");
            return;
        }

        printf("\n--- Proximo Atendimento ---\n");
        printf("Senha: %c%03d\n",
               senhas[posicaoSenha].prioridade,
               senhas[posicaoSenha].numero);

        printf("ID: %d\n", usuarios[posicaoUsuario].id);
        printf("Nome: %s\n", usuarios[posicaoUsuario].nome);
        printf("Idade: %d\n", usuarios[posicaoUsuario].idade);

        printf("Genero [M/F/O]: %c\n",
               usuarios[posicaoUsuario].genero);
        printf("Gestante [S/N]: %c\n",
               usuarios[posicaoUsuario].gestante);
        printf("Necessidade especial [S/N]: %c\n",
               usuarios[posicaoUsuario].necessidadeEspecial);

        printf("\nDescreva o atendimento: ");

        if (scanf(" %499[^\n]",
                  senhas[posicaoSenha].descricao) != 1) {
            return;
        }

        limparEntrada();

        // Finaliza o atendimento dessa senha
        senhas[posicaoSenha].atendida = 's';

        printf("\nAtendimento da senha %c%03d finalizado!\n",
               senhas[posicaoSenha].prioridade,
               senhas[posicaoSenha].numero);

        printf("\nContinuar atendimento?\n");
        char resposta = perguntar();

        if (resposta != 's') {
            return;
        }
    }
}

// Consulta as senhas que ja foram atendidas
void consultarAtendimentos(void) {
    int totalConcluidos = 0;

    printf("\n--- Atendimentos Concluidos ---\n");

    for (int i = 0; i < totalSenhas; i++) {
        if (senhas[i].atendida == 's') {
            int posicaoUsuario = buscarUsuario(senhas[i].idUsuario);

            printf("\nSenha: %c%03d\n",
                   senhas[i].prioridade, senhas[i].numero);
            printf("ID do usuario: %d\n", senhas[i].idUsuario);

            if (posicaoUsuario != -1) {
                printf("Paciente: %s\n", usuarios[posicaoUsuario].nome);
            }
            else {
                printf("Cadastro do usuario nao encontrado.\n");
            }

            printf("Descricao: %s\n", senhas[i].descricao);
            totalConcluidos++;
        }
    }

    if (totalConcluidos == 0) {
        printf("Nenhum atendimento concluido.\n");
    }
    else {
        printf("\nTotal de atendimentos concluidos: %d\n", totalConcluidos);
    }
}

// Funcao principal
int main(void) {
	int opcao;

	while (1) {
		printf("\n--- Clinica Medica ---\n");
		printf("1 - Retirar Senha\n");
		printf("2 - Registrar Atendimento\n");
		printf("3 - Cadastrar Usuario\n");
		printf("4 - Consultar Atendimentos Concluidos\n");
		printf("5 - Sair\n");
		printf("Opcao: ");

		opcao = lerInteiroPositivo();

		if (opcao == 0) {
			return 0;
		}

		switch (opcao) {
		case 1: {
            printf("\nVoce possui cadastro?\n");
            char resposta = perguntar();
        
            if (resposta == '\0') {
                return 0;
            }
        
            if (resposta == 'n') {
                int quantidadeAntes = totalCadastros;
        
                cadastro();
        
                // Se nenhum cadastro foi registrado, volta ao menu
                if (totalCadastros == quantidadeAntes) {
                    break;
                }
            }
        
            printf("\n--- Retirada de Senha ---\n");
            printf("Informe seu ID: ");
            int id = lerInteiroPositivo();
        
            if (id == 0) {
                return 0;
            }
        
            int posicao = buscarUsuario(id);
        
            if (posicao != -1) {
                printf("\nCadastro encontrado!\n");
                printf("ID: %d\n", usuarios[posicao].id);
                printf("Nome: %s\n", usuarios[posicao].nome);
                printf("Idade: %d\n", usuarios[posicao].idade);
        
                gerarSenha(usuarios[posicao]);
            }
            else {
                printf("\nCadastro nao encontrado para esse ID.\n");
            }
        
            break;
        }

		case 2:
			registrarAtendimento();
			break;

		case 3:
			cadastro();
            break;
			
		case 4:
		    consultarAtendimentos();
			break;

		case 5:
			printf("\nPrograma encerrado.\n");
			return 0;

		default:
			printf("\nOpcao invalida!\n");
		}
	}
}
