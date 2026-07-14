**MOC**: [[MOC - Matemática e Teoria dos Números]]

$$ log_b(x)=\dfrac{log(x)}{log(b)}$$
```c++
// 1. O básico (Mudança de Base)
double logb = log(x) / log(b); 

// 2. Se precisar de log na base 2 ou 10, prefira as nativas (mais precisas/rápidas):
double l2 = log2(x);
double l10 = log10(x);

// 3. RECUPERANDO INTEIROS COM SEGURANÇA (Prevenindo WA por truncamento)
// Se x for uma potência exata de b e você precisa do expoente inteiro:
long long expoente = round(log(x) / log(b)); 

// Se precisar do log base 2 de um inteiro truncado para baixo (ex: log2(10) = 3)
// Use manipulação de bits! Imune a erros de precisão:
long long int_log2 = 63 - __builtin_clzll(x);
```
