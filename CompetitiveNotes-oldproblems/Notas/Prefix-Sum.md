A soma de prefixo é interessante quando trabalhamos somas dentro de um array, dessa forma podemos sempre manipular o array e calcular sua nova soma sem ter que percorrer todo o array $O(n)$, tornando apenas as operações $O(1)$.

![[soma_de_prefixo.png]]
```c++
for (int i=0;i<n;i++)
{
	S[i+1]=S[i]+A[i];
}
```

- **Soma de uma parte do array:** dado o intervalo $i$ e $j$ do meu array, a soma é dada: `S[j]-S[i];` 
