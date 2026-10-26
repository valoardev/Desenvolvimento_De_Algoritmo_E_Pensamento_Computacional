# 🖥️ Registro de Equipamentos — C

> Projeto desenvolvido em **linguagem C** para a disciplina de **Desenvolvimento de Algoritmo e Pensamento Computacional**, com foco na aplicação prática de entrada e saída de dados, estruturas de repetição, validações e manipulação de arquivos.

---

## 📌 Sobre o projeto

O **Registro de Equipamentos em C** é um programa que permite cadastrar equipamentos, armazenando o **nome**, o **código de identificação** e o **número da seção** em que cada equipamento está localizado.

Os dados são salvos em um arquivo de texto chamado `equipamentos.txt`, possibilitando consultar registros de execuções anteriores. O programa também permite cadastrar vários equipamentos em sequência e, ao finalizar o cadastro, escolher se deseja visualizar os registros armazenados.

---

## ⚙️ Funcionalidades

O programa conta com **5 funcionalidades principais**:

| # | Funcionalidade | Descrição |
| :---: | --- | --- |
| **01** | 📝 **Cadastro de equipamentos** | Recebe o nome, o ID e o número da seção de cada equipamento. |
| **02** | 🔢 **Validação do ID** | Aceita códigos numéricos de **4 dígitos**, entre 1000 e 9999. |
| **03** | 📍 **Validação da seção** | Aceita números de seção de **3 dígitos**, entre 100 e 999. |
| **04** | 💾 **Armazenamento em arquivo** | Acrescenta os cadastros ao arquivo `equipamentos.txt` sem apagar os anteriores. |
| **05** | 📋 **Listagem de equipamentos** | Ao encerrar os cadastros, permite exibir o conteúdo do arquivo no terminal. |

---

## 🧠 Conceitos de programação utilizados

O desenvolvimento do projeto utiliza conceitos fundamentais da linguagem C:

* 🔤 Variáveis dos tipos `int` e `char`
* ⌨️ Entrada de dados com `scanf()`, `fgets()` e `getchar()`
* 🖥️ Saída de dados com `printf()`
* 🔁 Estruturas de repetição `while` e `do while`
* 🔀 Estruturas condicionais `if`
* ➕ Operadores relacionais e lógicos, como `<=`, `>`, `||` e `!=`
* 📂 Manipulação de arquivos com `FILE`, `fopen()`, `fprintf()` e `fclose()`
* 📖 Leitura de arquivos com `fgets()`
* 🛡️ Verificação de erros ao abrir arquivos

---

## 🧩 Organização do código

Toda a lógica está organizada dentro da função `main()` no arquivo `registro_equipamentos.c`.

O funcionamento segue esta sequência:

1. Solicita o nome do equipamento.
2. Solicita e valida o ID de 4 dígitos.
3. Solicita e valida o número da seção de 3 dígitos.
4. Abre `equipamentos.txt` no modo de acréscimo e grava o registro.
5. Pergunta se o usuário deseja cadastrar outro equipamento.
6. Após o encerramento do cadastro, oferece a opção de listar os equipamentos registrados.

---

## 📝 Cadastro de equipamentos

O programa solicita três informações para cada equipamento:

* **Nome:** texto informado pelo usuário.
* **ID:** número inteiro entre 1000 e 9999.
* **Seção:** número inteiro entre 100 e 999.

O nome é lido utilizando `fgets()`:

```c
fgets(equipamento, sizeof(equipamento), stdin);
```

Essa função permite receber nomes com espaços, respeitando o tamanho reservado para a variável.

---

## 🛡️ Validação dos dados

O programa utiliza estruturas `while` para verificar se o ID e a seção estão dentro dos intervalos definidos.

**Validação do ID:**

```c
while (scanf("%d", &id) != 1 || id <= 999 || id > 9999) {
    printf("\nID inválido! Digite um número de 1000 a 9999: ");
}
```

**Validação da seção:**

```c
while (scanf("%d", &loc) != 1 || loc <= 99 || loc > 999) {
    printf("\nSeção inválida! Digite um número de 100 a 999: ");
}
```

Essas condições impedem que números fora dos intervalos permitidos sejam aceitos. **Observação:** na versão atual, entradas não numéricas podem deixar o programa repetindo a mensagem de erro, pois o caractere inválido não é removido do buffer dentro desses laços.

---

## 💾 Armazenamento em arquivo

Os dados são gravados no arquivo `equipamentos.txt`, utilizando o modo **`"a"`** (append):

```c
arquivo = fopen("equipamentos.txt", "a");
```

Esse modo permite **adicionar novos registros sem apagar os já existentes**. Após a gravação com `fprintf()`, o arquivo é fechado com `fclose()`.

Um registro armazenado terá um formato semelhante a este:

```text
===
Nome: Impressora
ID: 1234
Seção: 205
```

O arquivo será criado automaticamente na pasta de execução do programa, caso ainda não exista e a abertura seja bem-sucedida.

---

## 🔁 Cadastro de múltiplos equipamentos

Após cada cadastro, o usuário pode escolher se deseja continuar:

```text
Deseja cadastrar outro equipamento? (s/n):
```

Ao digitar `s` ou `S`, o programa inicia um novo cadastro. Qualquer outra resposta encerra essa etapa.

---

## 📋 Listagem dos registros

Depois de finalizar os cadastros, o programa pergunta:

```text
Deseja listar os equipamentos cadastrados? (s/n):
```

Se a resposta for `s` ou `S`, o arquivo é aberto no modo de leitura (`"r"`), e o conteúdo é exibido linha por linha no terminal:

```c
while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    printf("%s", linha);
}
```

---

## ▶️ Como executar

### 1. Pré-requisitos

É necessário possuir um compilador C instalado, como **GCC**, ou utilizar uma IDE com suporte à linguagem C.

### 2. Compilar

No terminal, dentro da pasta do projeto:

```bash
gcc registro_equipamentos.c -o registro_equipamentos
```

### 3. Executar

**Windows (PowerShell):**

```powershell
.\registro_equipamentos.exe
```

**Linux/macOS:**

```bash
./registro_equipamentos
```

> Não é necessário utilizar `-lm`, pois o programa não utiliza a biblioteca matemática `math.h`.

---

## 📁 Estrutura do projeto

```text
registro_equipamentos/
│
├── 📄 registro_equipamentos.c
├── 📖 README.md
└── 📋 equipamentos.txt         # Criado durante a execução
```

---

## 🎯 Objetivo acadêmico

O projeto tem como objetivo aplicar os conhecimentos adquiridos na disciplina de **Desenvolvimento de Algoritmo e Pensamento Computacional**, utilizando a linguagem C para construir um sistema simples de registro e consulta de equipamentos.

Além de praticar **entrada e saída de dados**, o programa trabalha com **validação de valores**, **estruturas de repetição** e **leitura e escrita em arquivos**, permitindo manter os cadastros mesmo após o encerramento da execução.

---

## 📚 Disciplina

**Desenvolvimento de Algoritmo e Pensamento Computacional**  
**Curso:** Análise e Desenvolvimento de Sistemas  
**Ano:** 2026

---

⭐ *Projeto desenvolvido para fins acadêmicos e de aprendizado da linguagem C.*
