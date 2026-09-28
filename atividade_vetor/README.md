# 🔢 Análise de Vetor — C

> Leitura de 20 números inteiros e apresentação de cálculos e comparações usando um vetor.

## 🎓 Identificação

- **Aluno:** Gabriel Valois Rodrigues.
- **Disciplina:** Desenvolvimento de Algoritmo e Pensamento Computacional.
- **Professora:** Profa. Karla Sartin.

---

## 🎯 Objetivo

Aplicar **arrays (vetores)**, laços de repetição e estruturas condicionais em C para armazenar e analisar **20 números inteiros** informados pelo usuário.

## ⚙️ Como funciona

1. **⌨️ Ler os valores:** um laço `for` preenche o vetor `numeros[20]`.
2. **➕ Calcular:** outro `for` percorre o vetor e soma os múltiplos de 3. Também soma os pares e conta quantos são, para calcular a média.
3. **🔍 Comparar:** os comandos `if` e `else if` contam positivos e negativos e identificam o maior e o menor valor.
4. **📊 Exibir:** o programa mostra os resultados e todos os elementos na ordem em que foram digitados.

**Média dos pares = soma dos números pares ÷ quantidade de números pares.** A conversão para `double` permite manter as casas decimais na divisão.

O **zero é par**, mas não é positivo nem negativo. Quando não há pares, o programa informa isso e não faz a divisão. O maior e o menor começam com o primeiro elemento do vetor, garantindo a comparação correta mesmo quando todos os valores são negativos.

O código usa apenas `stdio.h`, `main`, `printf`, `scanf`, laços e condicionais. A entrada deve conter inteiros dentro do intervalo aceito por `int`; se `scanf` não conseguir ler um número, o programa encerra com uma mensagem. Não há validação completa de textos misturados com números nem de valores fora desse intervalo.

---

## ▶️ Como executar

Com **GCC** instalado, abra o terminal na pasta do projeto e compile:

```bash
gcc vetor.c -o vetor
```

Execute com `./vetor` no Linux/macOS/WSL ou `.\vetor.exe` no Windows PowerShell.

Digite **20 números inteiros**, pressionando **Enter** após cada um.

## 💻 Exemplo de entrada e saída

**Entrada** — os valores também podem ser separados por espaços:

```text
-9 -6 -3 -2 -1 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
```

**Saída final:**

```text
=== RESULTADOS ===
Soma dos multiplos de 3: 12
Media dos numeros pares: 4.80
Quantidade de positivos: 14
Quantidade de negativos: 5
Maior valor: 14
Menor valor: -9
Elementos do vetor: -9 | -6 | -3 | -2 | -1 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14
```

## ✅ Testes realizados

| Cenário | Resultado conferido |
| --- | --- |
| Positivos, negativos e zero | Resultados iguais aos do exemplo acima. |
| 20 ímpares, de 1 a 39 | Mensagem de ausência de pares, sem divisão por zero. |
| Inteiros de −20 a −1 | 20 negativos, maior −1 e menor −20. |
| 20 zeros | Média 0,00; nenhum positivo ou negativo; maior e menor iguais a zero. |
| 2, 2, 4 e mais 17 valores iguais a 1 | Média dos pares 2,67, preservando a parte decimal. |

## 📸 Evidência de execução

📖 **Evidências:** [`Visualizar →`](./evidencias)

