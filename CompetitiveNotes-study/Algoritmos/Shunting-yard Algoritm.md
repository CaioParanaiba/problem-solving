**Tags:** #cp4 #algoritmo 
**Pré-requisitos:** [[Algoritmos de Parsing]], [[Stack]]
**Autor:** [[Disjktra]]

> [!abstract] 💡 O que é? (O Insight)
> Expressões posfixas são computacionalmente melhores que as infixas padrões, esse algoritmo converte expressões infixas em posfixas através de uma leitura e armazenamento em uma [[Stack]].

## ⚙️ Como funciona? (Passo a Passo)
1. Se for número -> output;
2. Se for operador -> armazena na stack;
3. Se for bracket aberto -> armazena na stack;
4. Se for bracket fechado -> remove tudo dentro da stack até o ultimo bracket;

## ⏱️ Complexidade
* **Tempo:** $O(N)$ 
* **Espaço:** $O(N)$

## 💻 Código Base

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
^code

## 🎯 Problemas Práticos
- [ ] Nome do Problema (Link pro Codeforces/CSES) - **Status:** Feito / Pra fazer
- Onde falhei: (Anotar a pegadinha do problema)

