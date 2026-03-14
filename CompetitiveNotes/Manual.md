Com certeza! Ter esse manual no seu Obsidian vai te salvar na hora de preencher a coluna "Tópico" do seu Tracker de Problemas, especialmente quando a questão for daquelas que parecem "só raciocínio".

Como combinamos, vou te mandar o texto puro em Markdown para você não ter problemas na hora de copiar e colar. Crie uma nota chamada `[[Guia de Tags - Problemas Base]]` ou algo similar e cole o texto abaixo.

Aqui está o seu manual de treinador:

---

# 🏷️ Manual de Tags: Classificando Problemas "Sem Teoria"

Na Maratona de Programação (Codeforces, AtCoder, Beecrowd), não existe a categoria "Algoritmo Genérico" ou "Lógica Simples". Todo problema segue um padrão mental. Use as tags abaixo para classificar problemas que não dependem de Estruturas de Dados complexas ou Grafos.

## 1. `[[Ad-hoc]]` e `[[Simulação]]`

A categoria mais abrangente. O problema não exige nenhum conhecimento teórico avançado, "apenas" lógica de programação afiada e tradução direta do texto para o código.

- **Quando usar:** Quando o enunciado te dá as regras de um jogo e pede para você reproduzir as jogadas, ou quando é só um monte de `if/else` inteligente e laços de repetição (`for/while`).
    
- **Dica do Monitor:** Problemas Ad-hoc são perigosos porque costumam ter muitos "edge cases" (casos extremos). Leia o enunciado com lupa!
    

## 2. `[[Matemática]]` e `[[Teoria dos Números]]`

Problemas onde o código em si é minúsculo (às vezes 3 linhas), mas a dedução no papel leva 30 minutos.

- **Quando usar:** Envolve paridade (checar se é par ou ímpar), MMC / MDC (LCM / GCD), números primos, aritmética modular (`%`) ou o clássico **Princípio da Casa dos Pombos** (se tenho 5 pombos e 4 gaiolas, pelo menos uma gaiola tem 2 pombos).
    
- **Dica do Monitor:** Se os limites do problema forem ridiculamente grandes, tipo $N \le 10^{18}$, é 99% de chance de ser um problema de Matemática pura, pois um laço de repetição daria _Time Limit Exceeded_ (TLE) imediato. `O(1)` é rei aqui.
    

## 3. `[[Construtivo]]` (Constructive Algorithms)

Você não precisa calcular uma resposta, precisa **inventar** um cenário válido ou provar que é impossível.

- **Quando usar:** O problema te pede para "Construir um array de tamanho $N$ que satisfaça a regra X", ou responder "YES/NO" seguido do array montado. O problema "Bingo Candies" é um exemplo perfeito.
    
- **Dica do Monitor:** Comece sempre resolvendo os casos de teste pequenos no papel ($N=1, N=2, N=3$) para tentar enxergar um padrão visual de como construir a resposta genérica.
    

## 4. `[[Guloso]]` (Greedy)

A arte de ser "fominha". Você toma a decisão que parece ser a melhor agora, sem olhar muito para o futuro, e milagrosamente dá certo.

- **Quando usar:** O problema pede para "maximizar o lucro", "minimizar o custo", "usar o menor número de operações".
    
- **A Receita do Bolo:** 90% dos problemas gulosos começam com você ordenando a entrada. `sort(v.begin(), v.end())` e depois varrendo o vetor pegando os maiores (ou menores) valores disponíveis.
    

## 5. `[[Força Bruta]]` (Brute Force / Complete Search)

Testar absolutamente todas as possibilidades possíveis porque os limites do problema são tão pequenos que o computador aguenta.

- **Quando usar:** Quando você olha para os limites do problema (o input) e vê que $N \le 20$, $N \le 100$, ou a quantidade de estados é minúscula.
    
- **Dica do Monitor:** No C++, seu código consegue rodar na casa de $10^8$ operações por segundo. Se o número de testes aninhados (um `for` dentro de outro `for`) não passar muito de $10^7$, vai na Força Bruta sem medo de ser feliz!
    

---

> [!check] Regra de Ouro do Treinador
> 
> Muitas questões misturam essas tags. A questão "Bingo Candies", por exemplo, é **Matemática** (limite de doces na matriz) + **Construtiva** (avaliar se o cenário "YES" é alcançável). No seu Tracker do Obsidian, não tenha medo de colocar as duas tags na mesma linha!

---
