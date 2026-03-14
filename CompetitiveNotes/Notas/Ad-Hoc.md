# Ad-hoc e Simulação

Não existe algoritmo pronto aqui. É leitura, interpretação e código. Se eu travei numa questão Ad-hoc, devo me perguntar:

## Checklist de Sobrevivência:
- [ ] **Limites extremos:** O que acontece se $N = 1$? E se $N = 0$? E se o array já vier ordenado?
- [ ] **Simulação manual:** Tentei desenhar o problema no papel para os 3 primeiros casos de teste do enunciado passo a passo?
- [ ] **Tipos de dados:** O resultado pode estourar o limite do `int`? Preciso usar `long long`?
- [ ] **Padrão cíclico:** A simulação é muito longa (ex: $10^{18}$ passos)? Tente imprimir os 20 primeiros resultados num `for` e procure se a resposta fica se repetindo (Ciclo/Periodicidade).
