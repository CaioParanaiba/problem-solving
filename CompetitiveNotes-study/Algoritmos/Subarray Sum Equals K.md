
**Tags:** #cp4 #algoritmo 
**Pré-requisitos:** [[hash-map]], [[prefix-sum]], [[arrays]]
**MOC**: [[MOC - Técnicas e Paradigmas]]

> [!abstract] 💡 O que é? (O Insight)
> Quando precisamos achar quantas vezes (times) o sub-arrays que sua soma resulta em um valor K existem.

## ⚙️ Como funciona? (Passo a Passo)
1. Criamos um hash-map, pra armazenar o prefixo e as vezes que ele apareceu
2. Interamos em ordem os valores do array:
	1. Calculando o `prefixo atual`;
	2. Calculando o `prefixo - K`;
3. Verificamos se o `prefixo - K` já existe na nossa hash-map se ja existe adicionamos a sua repetição em `times`.

![[Pasted image 20260508183115.png|1000]]

## ⏱️ Complexidade
* **Tempo:** $O(N)$ 
* **Espaço:** $O(N)$

## 💻 Código Base
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
^code

## 🎯 Problemas Práticos
- [ ] [[OBI 2022.1 DChuva]] - **Status:** Feito / Pra fazer
- [ ] Onde falhei: (Anotar a pegadinha do problema)