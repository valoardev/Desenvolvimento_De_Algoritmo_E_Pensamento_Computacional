# 💻 Desenvolvimento de Algoritmo e Pensamento Computacional

Repositório destinado às atividades, exercícios e projetos desenvolvidos durante a disciplina de **Desenvolvimento de Algoritmo e Pensamento Computacional**.

## 📚 Sobre o repositório

Este repositório reúne os trabalhos realizados ao longo da disciplina, com o objetivo de aplicar na prática conceitos fundamentais de programação e desenvolvimento de algoritmos.

Entre os principais conceitos trabalhados estão:

* 🧠 Lógica de programação
* 🔢 Variáveis e tipos de dados
* ⌨️ Entrada e saída de dados
* ➕ Operadores aritméticos e lógicos
* 🔀 Estruturas condicionais
* 🔁 Estruturas de repetição
* 🔢 Arrays (vetores)
* 📊 Processamento e manipulação de dados
* 🧩 Desenvolvimento e organização de algoritmos

## 📂 Projetos

### 🧮 Calculadora — Flowgorithm

Projeto de uma calculadora desenvolvida utilizando o **Flowgorithm**, contendo 20 funções e operações diferentes.

O projeto aborda conceitos como:

* Operações matemáticas;
* Cálculo de IMC;
* Cálculo de áreas e perímetros;
* Porcentagem;
* Regra de três;
* Juros simples e compostos;
* Conversão de unidades e temperaturas;
* Velocidade média;
* Consumo de combustível;
* Cálculo de idade;
* Fatorial;
* Entre outras operações.

📁 **Pasta:** [`calculadora_em_flowgorithm/`](./calculadora_em_flowgorithm/)
📖 **README do projeto:** [`Ver documentação →`](./calculadora_em_flowgorithm/README.md)

---

### 💻 Calculadora — C

Projeto de uma calculadora desenvolvida em **linguagem C**, utilizando funções para organizar diferentes operações e cálculos.

O projeto aborda conceitos como:

* Funções;
* Operações matemáticas;
* Cálculo de IMC;
* Cálculo de áreas;
* Conversão de temperatura;
* Verificação de números pares e ímpares;
* Cálculo de descontos;
* Comparação de valores;
* Conversão de unidades;
* Estruturas condicionais;
* Estrutura `switch`;
* Entrada e saída de dados.

📁 **Pasta:** [`calculadora_em_c/`](./calculadora_em_c/)
📖 **README do projeto:** [`Ver documentação →`](./calculadora_em_c/README.md)

---

### 🌡️ Monitoramento Industrial — C

Simulação de um sensor de temperatura em **linguagem C**, com até **20 leituras aleatórias** e encerramento por proteção após **três temperaturas consecutivas acima do limite** definido pelo usuário.

O projeto aborda conceitos como:

* 🔁 Laços `while` e `do...while`;
* 🧩 Organização do código em funções;
* ⌨️ Validação do limite informado;
* 🎲 Geração de temperaturas aleatórias;
* 🚨 Contagem de alertas consecutivos;
* 📊 Relatório com média, maior e menor temperatura, quantidade de leituras e quantidade e percentual acima do limite.

📁 **Pasta:** [`desafio_monitoramento/`](./desafio_monitoramento/)  
📖 **README do projeto:** [`Ver documentação →`](./desafio_monitoramento/README.md)

---

### 🔢 Análise de Vetor — C

Programa em **linguagem C** que lê e armazena **20 números inteiros** em um vetor, realiza cálculos e apresenta os resultados de forma organizada.

O projeto aborda conceitos como:

* 🔢 Arrays (vetores) de inteiros;
* 🔁 Laços `for` para preencher e percorrer o vetor;
* ➕ Soma dos elementos múltiplos de 3;
* 📊 Média dos números pares, evitando divisão por zero;
* 🔍 Contagem de positivos e negativos, sem incluir o zero;
* ↕️ Identificação do maior e do menor valor;
* 📋 Exibição de todos os elementos armazenados.

📁 **Pasta:** [`atividade_vetor/`](./atividade_vetor/)  
📖 **README do projeto:** [`Ver documentação →`](./atividade_vetor/README.md)

---

### 🖥️ Registro de Equipamentos — C

Programa desenvolvido em **linguagem C** para cadastrar equipamentos, armazenando o nome, o código de identificação (ID) e o número da seção em que cada equipamento está localizado.

Os registros são salvos no arquivo de texto `equipamentos.txt`, permitindo preservar os cadastros anteriores e consultar os equipamentos registrados.

O projeto aborda conceitos como:

- 📝 Cadastro de equipamentos com nome, ID e seção;
- 🔢 Validação do ID, aceitando números entre 1000 e 9999;
- 📍 Validação do número da seção, aceitando valores entre 100 e 999;
- ⌨️ Entrada de dados com `scanf()`, `fgets()` e `getchar()`;
- 🔁 Estruturas de repetição `while` e `do...while`;
- 🔀 Estruturas condicionais `if`;
- 💾 Manipulação de arquivos com `FILE`, `fopen()`, `fprintf()` e `fclose()`;
- 📖 Leitura e exibição dos registros armazenados com `fgets()`;
- 🛡️ Verificação de erros na abertura de arquivos.

📁 **Pasta:** [`registro_equipamentos/`](./registro_equipamentos/)  
📖 **README do projeto:** [`Ver documentação →`](./registro_equipamentos/README.md)

---

### 🏥 Gerenciamento de Senhas de Atendimento — C

Sistema desenvolvido em **linguagem C** para simular o atendimento em uma clínica de especialidades médicas, com cadastro de usuários, emissão de senhas, painel de chamada e organização da fila por prioridade.

O **cadastro é separado da retirada de senha**: o usuário recebe um ID e pode reutilizá-lo para novas retiradas após a finalização do atendimento. As consultas, chamadas, finalizações e o histórico ficam reunidos em um **submenu de atendimento**.

O projeto aborda conceitos como:

* 🧱 Estruturas `struct`, tipos definidos com `typedef` e estados com `enum`;
* 🔢 Vetores para armazenar usuários e senhas durante a execução;
* 📍 Passagem de dados por ponteiros, reunidos na estrutura `Sistema`;
* 🔍 Cadastro e consulta de usuários por ID, sem recadastrar na retirada de senha;
* 🎟️ Emissão de senhas normais, preferenciais e urgentes conforme idade e condições cadastradas;
* 🚦 Atendimento na ordem **U → P → N**, preservando a ordem de emissão dentro de cada categoria (FIFO);
* 🔄 Controle dos estados **aguardando**, **em atendimento** e **finalizada**;
* 🛡️ Bloqueio de senhas simultâneas para o mesmo usuário e de mais de um atendimento ativo;
* 🩺 Chamada de pacientes, registro da descrição e finalização dos atendimentos;
* 🖥️ Painel com senha atual, próximas senhas e contadores por categoria;
* 📋 Consulta de atendimentos concluídos, preservando o histórico;
* 🧩 Modularização em `main.c`, `registro.h`, `classificacao.h`, `atendimento.h` e `painel.h`;
* ⌨️ Leitura com `fgets()`, conversão com `strtol()` e validação das entradas;
* 🔁 Laços `for` e `while`, condições e menus com `switch/case`;
* 🧪 Cinco cenários de teste documentados com imagens de saídas reais da versão atual.

**Menu principal:** cadastrar usuário, retirar senha, atendimento, mostrar painel de chamada e sair.

**Testes documentados:** cadastro, ID inexistente, fila por prioridade, registro de atendimento e consulta do histórico.

**Armazenamento:** até **100 cadastros** e **100 senhas por execução**, com limites independentes. Os dados ficam apenas na memória e são perdidos ao encerrar o programa.

📁 **Pasta:** [`gerenciamento_senhas/`](./gerenciamento_senhas/)  
📖 **README do projeto:** [`Ver documentação →`](./gerenciamento_senhas/README.md)

## 🎯 Objetivo

Utilizar os conhecimentos adquiridos na disciplina para desenvolver soluções computacionais de forma organizada, aplicando conceitos de lógica, algoritmos e pensamento computacional.
