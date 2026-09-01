# 🧮 Calculadora — C

> Projeto desenvolvido em **linguagem C** para a disciplina de **Desenvolvimento de Algoritmo e Pensamento Computacional**, com foco na aplicação prática de funções, estruturas condicionais, operadores matemáticos, entrada e saída de dados.

---

## 📌 Sobre o projeto

A **Calculadora em C** é um programa desenvolvido para praticar conceitos fundamentais da linguagem C por meio de diferentes cálculos e operações.

O programa possui um **menu principal** que permite ao usuário escolher entre diferentes funcionalidades, direcionando a execução para a função correspondente.

O projeto utiliza funções independentes para organizar cada operação, tornando o código mais estruturado e facilitando sua compreensão e manutenção.

---

## ⚙️ Funcionalidades

Atualmente, o programa conta com **8 funcionalidades principais**:

|    #   | Função                           | Descrição                                                     |
| :----: | -------------------------------- | ------------------------------------------------------------- |
| **01** | 📐 **Cálculo de área**           | Calcula a área de quadrilátero, triângulo, círculo ou losango |
| **02** | ⚖️ **Cálculo de IMC**            | Calcula o IMC e apresenta sua classificação                   |
| **03** | ➕ **Calculadora simples**        | Soma, subtração, multiplicação, divisão e potenciação         |
| **04** | 🌡️ **Conversor de temperatura** | Converte Celsius para Kelvin ou Fahrenheit                    |
| **05** | 🔢 **Par ou ímpar**              | Verifica se um número inteiro é par ou ímpar                  |
| **06** | 🏷️ **Calculadora de desconto**  | Calcula o valor final de um produto após um desconto          |
| **07** | ⚖️ **Comparador de valores**     | Identifica qual de dois números é maior ou se são iguais      |
| **08** | 📏 **Conversor de unidades**     | Converte metros para diferentes unidades de comprimento       |

---

## 🧠 Conceitos de programação utilizados

O desenvolvimento do projeto utiliza diversos conceitos fundamentais da linguagem C:

* 🔢 Declaração e utilização de variáveis
* ⌨️ Entrada de dados com `scanf`
* 🖥️ Saída de dados com `printf`
* 🧩 Criação e utilização de funções
* 🔀 Estruturas condicionais `if`, `else if` e `else`
* 🔀 Estrutura de seleção `switch`
* ➕ Operadores aritméticos
* `%` **Operador de módulo**
* 📐 Funções matemáticas da biblioteca `math.h`
* 📦 Constantes com `#define`
* 🔤 Tipos de dados como `int`, `double` e `char`

---

## 🧩 Organização do código

Cada funcionalidade é implementada em uma função própria.

Entre elas estão:

```c
calcularArea()
calcularImc()
calculadoraSimples()
conversorTemperatura()
parOuImpar()
calcularDesconto()
numeroMaiorOuMenor()
conversorDeUnidades()
```

A função `main()` apresenta o menu e utiliza uma estrutura `switch` para direcionar o usuário para a funcionalidade escolhida.

---

## 📐 Cálculo de área

A função de áreas permite escolher entre quatro figuras geométricas:

* Quadrilátero
* Triângulo
* Círculo
* Losango

Para o cálculo do círculo, o programa utiliza a constante:

```c
#define PI 3.14
```

## e a função `pow()` disponibilizada pela biblioteca `math.h`.

## ⚖️ Cálculo de IMC

O programa recebe a **altura** e o **peso** informados pelo usuário e calcula o IMC.

Após o cálculo, o resultado é classificado em diferentes categorias:

* Abaixo do Peso Normal
* Peso Normal
* Excesso de Peso
* Obesidade Classe I
* Obesidade Classe II
* Obesidade Classe III

---

## ➕ Calculadora simples

A calculadora simples oferece cinco operações:

```text
1 → Soma
2 → Subtração
3 → Multiplicação
4 → Divisão
5 → Potenciação
```

A divisão possui uma verificação para impedir a divisão por zero.

---

## 🌡️ Conversor de temperatura

Permite converter uma temperatura inicialmente informada em **Celsius** para:

* 🇺🇸 Fahrenheit
* 🌡️ Kelvin

A escolha da conversão é realizada por meio de uma opção informada pelo usuário.

---

## 📏 Conversor de unidades

A partir de um valor informado em **metros**, o programa realiza conversões para:

* Milímetros
* Centímetros
* Decímetros
* Hectômetros
* Quilômetros

---

## 🛡️ Validação

O programa possui algumas validações para evitar operações inválidas.

Um exemplo é a divisão por zero:

```c
if (b == 0) {
    printf("Erro: Nao eh possivel dividir por zero!\n");
}
```

Também existe uma opção padrão no `switch` principal para tratar escolhas que não correspondem às funcionalidades disponíveis.

---

## ▶️ Como executar

### 1. Pré-requisitos

É necessário possuir um compilador C instalado, como **GCC**, ou utilizar uma IDE que ofereça suporte à linguagem C.

### 2. Compilar

No terminal, dentro da pasta do projeto:

```bash
gcc calculadora.c -o calculadora -lm
```

> A flag `-lm` é utilizada para realizar o link com a biblioteca matemática `math.h`.

### 3. Executar

No Windows:

```bash
calculadora.exe
```

No Linux/macOS:

```bash
./calculadora
```

---

## 📁 Estrutura do projeto

```text
calculadora_em_c/
│
├── 📄 calculadora.c
└── 📖 README.md
```

---

## 🎯 Objetivo acadêmico

O projeto tem como objetivo aplicar os conhecimentos adquiridos na disciplina de **Desenvolvimento de Algoritmo e Pensamento Computacional**, utilizando a linguagem C para desenvolver soluções simples e organizadas para diferentes problemas matemáticos e lógicos.

Além dos cálculos, o projeto busca praticar a **organização do código por meio de funções**, permitindo que cada funcionalidade possua sua própria implementação.

---

## 👥 Integrantes

* **Bernardo Kopp**
* **Gabriel Valois**
* **Piêtro Bitencourt**
* **Zamorano Fragoso**

---

## 📚 Disciplina

**Desenvolvimento de Algoritmo e Pensamento Computacional**

**Curso:** Análise e Desenvolvimento de Sistemas
**Ano:** 2026

---

⭐ *Projeto desenvolvido para fins acadêmicos e de aprendizado da linguagem C.*

