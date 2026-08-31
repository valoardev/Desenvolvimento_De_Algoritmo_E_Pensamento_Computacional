# 🧮 Calculadora Universal — Flowgorithm

> Projeto desenvolvido para a disciplina de **Desenvolvimento de Algoritmo e Pensamento Computacional**, utilizando o **Flowgorithm** para aplicar conceitos fundamentais de lógica de programação e construção de algoritmos.

---

## 📌 Sobre o projeto

A **Calculadora Universal** é um programa desenvolvido em **Flowgorithm** que reúne **20 funções e operações diferentes** em um único fluxograma.

O projeto foi desenvolvido com o objetivo de praticar conceitos como:

* 🧠 Lógica de programação
* 🔢 Variáveis e tipos de dados
* ⌨️ Entrada e saída de dados
* ➕ Operadores matemáticos e lógicos
* 🔀 Estruturas condicionais
* 🔁 Estruturas de repetição
* ✅ Validação de entradas
* 📊 Processamento e apresentação de resultados

---

## 🎯 Objetivo

Desenvolver uma calculadora capaz de realizar diferentes tipos de cálculos, aplicando na prática os conhecimentos de **algoritmos e pensamento computacional**.

O programa possui um **menu interativo** com 20 opções de operações, além da opção de encerramento.

---

## ⚙️ Funcionamento

Ao iniciar o programa, o usuário encontra um menu com as operações disponíveis:

```text
========== CALCULADORA UNIVERSAL ==========

1  - Calculo do IMC
2  - Areas de figuras geometricas
3  - Operacoes aritmeticas
4  - Par ou impar
5  - Comparacao entre valores
...
19 - Fatorial
20 - Numero primo

0  - Sair
============================================
```

Após selecionar uma opção, o programa solicita os dados necessários, realiza o processamento e apresenta o resultado.

O programa também possui **validações de entrada**, incluindo verificações específicas para situações como divisão por zero e valores inválidos.

---

## 🧮 20 funções implementadas

|    #   | Função                       | Descrição                                          |
| :----: | ---------------------------- | -------------------------------------------------- |
| **01** | 🧍 **Cálculo do IMC**        | Calcula e classifica o Índice de Massa Corporal    |
| **02** | 📐 **Áreas geométricas**     | Quadrado, triângulo, círculo, losango e retângulo  |
| **03** | ➕ **Operações aritméticas**  | Soma, subtração, multiplicação, divisão e potência |
| **04** | 🔢 **Par ou ímpar**          | Identifica se um número inteiro é par ou ímpar     |
| **05** | ⚖️ **Comparação**            | Compara dois valores                               |
| **06** | 📊 **Média aritmética**      | Calcula a média de três notas                      |
| **07** | 💯 **Porcentagem**           | Calcula um percentual de determinado valor         |
| **08** | 📏 **Regra de três**         | Realiza uma regra de três simples                  |
| **09** | 💰 **Juros simples**         | Calcula juros e montante                           |
| **10** | 🏷️ **Desconto**             | Calcula desconto e preço final                     |
| **11** | 🌡️ **Temperatura**          | Celsius, Fahrenheit e Kelvin                       |
| **12** | 📦 **Conversor de unidades** | Comprimento, área, volume, massa e capacidade      |
| **13** | 📐 **Trigonometria**         | Seno, cosseno e tangente                           |
| **14** | 📏 **Perímetro**             | Quadrado, retângulo, círculo e triângulo           |
| **15** | 📦 **Volume**                | Cubo, esfera, cilindro e paralelepípedo            |
| **16** | 🚗 **Velocidade média**      | Calcula velocidade a partir de distância e tempo   |
| **17** | ⛽ **Consumo de combustível** | Calcula quilômetros por litro                      |
| **18** | 🎂 **Cálculo de idade**      | Calcula a idade a partir do ano de nascimento      |
| **19** | 🔢 **Fatorial**              | Calcula o fatorial utilizando repetição            |
| **20** | 🔍 **Número primo**          | Verifica se um número é primo                      |

---

## 🧠 Conceitos aplicados

Durante o desenvolvimento foram utilizados diversos conceitos fundamentais de programação:

### 🔀 Estruturas condicionais

Utilizadas para tomar decisões de acordo com os dados fornecidos pelo usuário.

### 🔁 Estruturas de repetição

Utilizadas principalmente em cálculos que precisam executar uma determinada operação várias vezes, como o **fatorial** e a **verificação de números primos**.

### ✅ Validação de dados

O programa verifica entradas que poderiam gerar resultados inválidos, como:

* Divisão por zero;
* Opções inexistentes no menu;
* Valores inadequados para determinadas operações.

### 📊 Formatação de resultados

Os resultados numéricos utilizam `ToFixed` quando necessário para controlar a quantidade de casas decimais apresentadas.

---

## 📁 Estrutura do projeto

```text
calculadora-flowgorithm/
│
├── 📄 calculadora.fprg
└── 📖 README.md
```

O arquivo `.fprg` contém todo o fluxograma desenvolvido no **Flowgorithm**.

---

## ▶️ Como executar

### 1. Instale o Flowgorithm

Baixe gratuitamente o [Flowgorithm](http://www.flowgorithm.org/).

### 2. Abra o projeto

Abra o arquivo:

```text
calculadora.fprg
```

no Flowgorithm.

### 3. Execute

Clique em **Executar** ou pressione:

```text
F5
```

### 4. Escolha uma operação

Digite o número correspondente à operação desejada e siga as instruções apresentadas pelo programa.

Para encerrar, escolha:

```text
0 - Sair
```

---

## ✅ Requisitos atendidos

* [x] 20 funções/operações diferentes
* [x] Cálculo de IMC
* [x] Cálculo de áreas
* [x] Menu de opções
* [x] Entrada de dados pelo usuário
* [x] Processamento dos dados
* [x] Apresentação dos resultados
* [x] Utilização adequada de variáveis
* [x] Estruturas condicionais
* [x] Estruturas de repetição
* [x] Validação de entradas
* [x] Comentários nos principais blocos
* [x] Organização do fluxograma por função

---

## ⚠️ Observação

Os textos exibidos pelo programa foram escritos **sem acentuação gráfica** para reduzir possíveis problemas de codificação de caracteres ao abrir o arquivo `.fprg` em diferentes versões do Flowgorithm.

Essa escolha não interfere no funcionamento ou na lógica do programa.

---

## 👨‍💻 Autor

**Gabriel Valois Rodrigues**

🎓 **Curso:** Análise e Desenvolvimento de Sistemas
📚 **Disciplina:** Desenvolvimento de Algoritmo e Pensamento Computacional
📅 **Ano:** 2026

---

⭐ *Projeto desenvolvido como parte das atividades acadêmicas da disciplina de Desenvolvimento de Algoritmo e Pensamento Computacional.*
