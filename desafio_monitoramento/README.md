# 🌡️ Sistema Inteligente de Monitoramento Industrial — C

> Simulação de um sensor de temperatura com alertas, encerramento por proteção e relatório final.

## 🎓 Identificação

- **Aluno:** Gabriel Valois Rodrigues.
- **Disciplina:** Desenvolvimento de Algoritmo e Pensamento Computacional.
- **Professora:** Profa. Karla Sartin.

---

## 🎯 Objetivo

Monitorar a temperatura de uma máquina e interromper a simulação ao detectar **três temperaturas consecutivas acima do limite**, aplicando funções, validação de entradas e laços de repetição em C.

## ⚙️ Como funciona

1. **⌨️ Definir o limite:** o usuário informa um número finito maior ou igual a **−273,15 °C**, usando ponto nas casas decimais.
2. **🛡️ Validar a entrada:** letras, valores abaixo do zero absoluto, `50abc`, `50,5`, `nan` e `inf` são rejeitados. O programa solicita outro valor; se a entrada terminar, encerra sem iniciar o sensor.
3. **🌡️ Captar temperaturas:** `captaTemperatura()` gera até **20 leituras**, usando `rand()` e `log()`, independentemente do limite informado. A fórmula já produz temperaturas finitas acima do zero absoluto.
4. **🚨 Verificar alertas:** cada leitura mostra se ficou acima do limite. Uma leitura igual ou inferior a ele **zera o contador de consecutivas**, preservando o total acumulado acima do limite.
5. **🏁 Encerrar:** três leituras consecutivas acima do limite provocam a parada por proteção. Caso contrário, o programa conclui as 20 leituras normalmente.

Em caso de proteção, o terminal exibe:

```text
O sistema identificou 3 temperaturas consecutivas acima do limite.
O programa foi finalizado como forma de proteção.
```

## 📊 Relatório final

Nos dois tipos de encerramento, são apresentados **limite, quantidade de leituras, média, maior e menor temperatura, quantidade e percentual acima do limite**.

- **Média:** soma das temperaturas ÷ quantidade de leituras realizadas.
- **Percentual:** quantidade acima do limite × 100 ÷ quantidade de leituras realizadas.

A leitura que provoca a parada também entra nos cálculos. As funções `verificaMaior()`, `verificaMenor()` e `verificaLimite()` organizam as comparações; `calculaMedia()` e `apresentaRelatorio()` completam o relatório.

## 🔁 Estruturas de repetição

| Estrutura | Uso no programa |
| --- | --- |
| `do...while` | Solicitar o limite ao menos uma vez e repetir enquanto inválido; gerar leituras até completar 20 ou alcançar três alertas consecutivos. |
| `while` | Verificar e retirar os caracteres restantes da linha digitada antes da próxima entrada. |

São utilizados somente **`while` e `do...while`** como laços de repetição.

---

## ▶️ Como executar

Com **GCC** instalado, abra o terminal na pasta do projeto e compile:

```bash
gcc monitoramento.c -o monitoramento -lm
```

Execute com `./monitoramento` no Linux/macOS/WSL ou `.\monitoramento.exe` no Windows PowerShell. A opção `-lm` inclui a biblioteca matemática necessária para `log()`.

Digite o limite e pressione **Enter**; as leituras seguintes são automáticas.

## ✅ Testes realizados

| Cenário | Entrada e resultado observado |
| --- | --- |
| **1 — Entradas inválidas** | `abc`, `-300`, `50abc`, `50,5` e `inf` foram rejeitados. Após informar `100`, o programa concluiu 20 leituras. |
| **2 — Acima, sem três consecutivas** | Com limite `100`, as leituras 1, 2, 8 e 11 ficaram acima. As seguintes zeraram a sequência: encerramento normal, média **13,59 °C** e **20%** acima do limite. |
| **3 — Parada por proteção** | Com limite `20`, as leituras 7, 8 e 9 formaram três alertas consecutivos. Parada na 10ª leitura, média **17,96 °C** e **44,44%** acima do limite. |

📁 **Evidências:** [`evidencias/`](./evidencias/)

---

## 💭 Reflexão final

Escolhi combinar as duas estruturas. O `do...while` garante uma primeira tentativa de entrada e uma primeira leitura do sensor; depois verifica se deve repetir. Na captação, isso permite atualizar os contadores antes de decidir pela próxima leitura. Já o `while` testa a condição antes de processar os caracteres restantes da entrada, evitando continuar quando encontra a quebra de linha ou o fim dos dados.
