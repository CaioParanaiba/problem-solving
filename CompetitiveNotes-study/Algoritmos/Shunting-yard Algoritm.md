---
aliases: [Shunting Yard, Infix to Postfix, Expression Parsing]
tags: #cp #algoritmo #parsing #stack #obi #icpc
data_criacao: 2024-01-15
status: consolidado
---

# 📚 Shunting-yard Algorithm

**MOC:** [[MOC - Técnicas e Paradigmas]], [[MOC - Estruturas de Dados]]
**Pré-requisitos:** [[Algoritmos de Parsing]], [[Stack]]
**Autor:** [[Edsger Dijkstra]]

---

> [!abstract] 💡 O que é? (O Insight)
> Expressões posfixas são computacionalmente melhores que as infixas padrões, esse algoritmo converte expressões infixas em posfixas através de uma leitura e armazenamento em uma [[Stack]].

## ⚙️ Como funciona? (Passo a Passo)
1. Se for número -> output;
2. Se for operador -> armazena na stack;
3. Se for bracket aberto -> armazena na stack;
4. Se for bracket fechado -> remove tudo dentro da stack até o ultimo bracket;

---

## ⏱️ Complexidade

* **Tempo:** $O(N)$ 
* **Espaço:** $O(N)$

---

## 💻 Snippet de Ouro

```cpp
#include <bits/stdc++.h>
using namespace std;

bool op(char c){
	if(c =='*' || c =='/' || c == '+' || c == '-')
		return 1;
	return 0;
}

bool bracketO(char c){
	if(c == '(' || c == '{' || c == '[')
		return 1;
	return 0;
}

bool bracketC(char c){
	if(c == ')' || c == '}' || c == ']')
		return 1;
	return 0;
}

string shunting_yard(string infix){
	
	string posfix = "";
	stack<char> st;
	
	for (auto c : infix) {
		if (op(c)) st.push(c);
		else if (bracketO(c)) st.push(c);
		else if (bracketC(c)) {
			while (st.size() && !bracketO(st.top())) {
				posfix+=st.top();
				st.pop();
			}
			st.pop();
		}
		else if (isalnum(c)) posfix+=c;
	}
	
	while(st.size()) {
		posfix+=st.top();
		st.pop();
	}
	
	return posfix;
}
```

---

## ⚠️ Pegadinhas Clássicas e Edge Cases

- [ ] **Precedência de operadores:** Implementação básica não respeita precedência (* e / antes de + e -). Necessário adicionar lógica de prioridade.

- [ ] **Parênteses desbalanceados:** Verificar se há match correto entre abertura e fechamento de brackets.

- [ ] **Caracteres inválidos:** Validar entrada antes de processar para evitar comportamento indefinido.

- [ ] **Stack vazia no pop:** Sempre verificar `!st.empty()` antes de acessar `.top()` ou `.pop()`.

---

## 🎯 Problemas Práticos

| Problema | Juiz | Dificuldade | Status | Notas / Pegadinhas |
| :--- | :--- | :---: | :---: | :--- |
| *(A ser preenchido)* | - | - | - | Parsing de expressões, validação de parênteses |

---

## 🔄 Histórico de Revisão & Erros Comuns
* *Anotações pessoais de erros em simulados.*

