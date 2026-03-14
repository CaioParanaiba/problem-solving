Geralmente o limite é gigantesco ($N = 10^{18}$) e a solução é $O(1)$ ou $O(\log N)$.

## Checklist de Sobrevivência:
- [ ] **Paridade:** A soma / diferença preserva paridade? (Par + Par = Par, etc).
- [ ] **Princípio da Casa dos Pombos (Pigeonhole):** Se eu tenho $X$ caixas e $X+1$ itens, pelo menos uma caixa terá 2 itens. Qual é o limite máximo antes de estourar a regra?
- [ ] **Aritmética Modular:** Lembrete: `(A + B) % M = ((A % M) + (B % M)) % M`.
- [ ] **Fatoração:** Preciso achar os divisores? Um laço até $\sqrt{N}$ resolve em $O(\sqrt{N})$.
