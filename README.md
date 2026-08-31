# Calculadora Universal — Flowgorithm

## Título da atividade
Calculadora no Flowgorithm — Desenvolvimento de Algoritmo e Pensamento Computacional

## Nome do aluno
_(preencha aqui com seu nome completo)_

## Objetivo do programa
Desenvolver, utilizando o Flowgorithm, uma calculadora com 20 funções diferentes, aplicando os conceitos de lógica de programação, entrada e saída de dados, variáveis, operadores e estruturas de decisão e repetição.

## Descrição resumida do funcionamento
Ao ser executado, o programa exibe um **menu principal** com 20 opções de cálculo, numeradas de 1 a 20, mais a opção `0` para encerrar o programa. O usuário digita o número da operação desejada; o valor é validado (o programa repete a pergunta caso o número esteja fora do intervalo permitido). Em seguida, o programa solicita os dados necessários para aquele cálculo específico (com validações extras quando aplicável, como impedir divisão por zero), processa a operação escolhida e mostra o resultado formatado na tela (usando `ToFixed` para exibir os números com casas decimais controladas). Ao final de cada operação o fluxo retorna ao fim do programa (é possível rodar novamente escolhendo a opção desejada ao reabrir o fluxograma).

## Relação das 20 funções implementadas

| # | Função | Observação |
|---|--------|------------|
| 1 | **Cálculo do IMC** (Índice de Massa Corporal) | ✅ **Função obrigatória** — calcula o IMC e classifica o resultado (abaixo do peso, peso normal, sobrepeso, obesidade grau I, II ou III) |
| 2 | **Cálculo de área de figuras geométricas** | ✅ **Função obrigatória** — quadrado, triângulo, círculo, losango e retângulo |
| 3 | Operações aritméticas básicas | Soma, subtração, multiplicação, divisão (com validação de divisor zero) e potência |
| 4 | Par ou ímpar | Identifica se um número inteiro é par ou ímpar |
| 5 | Comparação entre valores | Compara dois valores e informa qual é maior, menor ou se são iguais |
| 6 | Média aritmética | Calcula a média de três notas |
| 7 | Porcentagem | Calcula quanto vale um percentual de um valor |
| 8 | Regra de três simples | Regra de três direta (A está para B, assim como C está para X) |
| 9 | Juros simples | Calcula juros e montante final a partir de capital, taxa e tempo |
| 10 | Desconto | Calcula o valor do desconto e o preço final |
| 11 | Conversão de temperatura | Celsius ↔ Fahrenheit e Celsius → Kelvin |
| 12 | Conversor de unidades | Comprimento, área, volume, massa e capacidade |
| 13 | Trigonometria | Seno, cosseno e tangente de um ângulo em graus |
| 14 | Cálculo de perímetro | Quadrado, retângulo, círculo e triângulo equilátero |
| 15 | Cálculo de volume | Cubo, esfera, cilindro e paralelepípedo |
| 16 | Velocidade média | A partir de distância e tempo |
| 17 | Consumo de combustível (autonomia) | Km rodados por litro consumido |
| 18 | Cálculo de idade | A partir do ano de nascimento e do ano atual |
| 19 | Fatorial de um número | Usa estrutura de repetição (`while`) para calcular o fatorial |
| 20 | Verificação de número primo | Usa estrutura de repetição e decisão para testar se um número é primo |

> **Observação sobre o texto do programa:** os textos de saída foram escritos sem acentuação gráfica (ex.: "calculo" em vez de "cálculo") para evitar qualquer problema de codificação de caracteres ao abrir o arquivo `.fprg` em diferentes versões do Flowgorithm. O funcionamento e a lógica do programa não são afetados por isso.

## Instruções básicas para execução do programa
1. Baixe/instale o [Flowgorithm](http://www.flowgorithm.org/) (gratuito).
2. Abra o arquivo `calculadora.fprg` no Flowgorithm (`Arquivo > Abrir`).
3. Clique em **Executar** (ícone de "play" ou tecla `F5`) para rodar o fluxograma.
4. Digite o número da operação desejada quando o menu aparecer no console e siga as instruções exibidas na tela.
5. Para sair do programa, digite `0` quando o menu principal for exibido.

## Estrutura do repositório
```
desenvolvimento-de-algoritmo-e-pensamento-computacional/
└── calculadora-flowgorithm/
    ├── calculadora.fprg
    └── README.md
```

## Requisitos atendidos
- [x] 20 funções/operações diferentes
- [x] Cálculo de IMC (obrigatório)
- [x] Cálculo de área (obrigatório)
- [x] Menu de opções
- [x] Entrada de dados pelo usuário
- [x] Processamento dos dados
- [x] Apresentação dos resultados (saída formatada com `ToFixed`)
- [x] Uso adequado de variáveis
- [x] Uso de estruturas condicionais (`if`) e de repetição (`while`) quando necessário
- [x] Comentários explicando os principais blocos do fluxograma
- [x] Fluxograma organizado por função, com validação de entradas
