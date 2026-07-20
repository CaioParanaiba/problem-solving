---
aliases: [Subarray Sum K, Prefix Sum Hash]
tags: #cp #algoritmo #array #hash #prefix_sum #obi #icpc
data_criacao: 2024-01-15
status: consolidado
---

# 📚 Subarray Sum Equals K

**MOC:** [[MOC - Técnicas e Paradigmas]]
**Pré-requisitos:** [[unordered_map]], [[Prefixo 1D]], [[arrays]]

---

> [!abstract] 💡 O que é? (O Insight)
> Quando precisamos achar quantas vezes (times) o sub-arrays que sua soma resulta em um valor K existem.

## ⚙️ Como funciona? (Passo a Passo)
1. Criamos um hash-map, pra armazenar o prefixo e as vezes que ele apareceu
2. Interamos em ordem os valores do array:
	1. Calculando o `prefixo atual`;
	2. Calculando o `prefixo - K`;
3. Verificamos se o `prefixo - K` já existe na nossa hash-map se ja existe adicionamos a sua repetição em `times`.

![[Pasted image 20260508183115.png|1000]]

---

## ⏱️ Complexidade

* **Tempo:** $O(N)$ 
* **Espaço:** $O(N)$

---

## 💻 Snippet de Ouro

```cpp
#include <bits/stdc++.h>
using namespace std;

int SubArraySum(int *num,int n,int k) {
	int prefix = 0, times=0;
	unordered_map<int,int> m;
	
	m[0]=1;
	
	for (int i=0;i<n;i++) {
		prefix += num[i];
		
		int prefix_k = prefix - k;
		
		if(m.contains(prefix_k)) times+=m[prefix_k];
		
		m[prefix]++;
	}
	
	return times;
}
```

---

## ⚠️ Pegadinhas Clássicas e Edge Cases

- [ ] **Inicialização do mapa:** Sempre inicializar `m[0] = 1` para capturar subarrays que começam no índice 0.

- [ ] **Overflow:** Com valores grandes ou arrays longos, usar `long long` para prefix e k.

- [ ] **Anti-Hash TLE:** Se usar `unordered_map` em competições, considerar custom hash (ver nota em [[unordered_map]]).

- [ ] **Ordem de operações:** Importante somar `m[prefix_k]` **antes** de incrementar `m[prefix]++` para evitar contar o próprio elemento.

---

## 🎯 Problemas Práticos

| Problema | Juiz | Dificuldade | Status | Notas / Pegadinhas |
| :--- | :--- | :---: | :---: | :--- |
| [[OBI 2022.1 DChuva]] | OBI | 🟡 Média | 🔲 Pra fazer | Aplicação direta do conceito |

---

## 🔄 Histórico de Revisão & Erros Comuns
* *Anotações pessoais de erros em simulados.*