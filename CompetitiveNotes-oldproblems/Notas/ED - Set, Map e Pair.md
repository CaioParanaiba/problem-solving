# Pair, Set e Map

## 1. Pair

Um contêiner que armazena dois elementos, que podem ser de tipos diferentes.
```c++
pair<int, string> p;
p.first = 1;
p.second = "Maratona";
```

## 2. Set (Conjunto)

É um conjunto que armazena elementos **únicos** e os mantém **sempre ordenados**. Complexidade base: $O(\log N)$.

`set<tipo> nome_do_set;`

- `s.insert(valor)` -> Insere elemento em $O(\log N)$
    
- `s.erase(valor)` -> Remove elemento em $O(\log N)$
    
- `s.erase(iterador)` -> Remove elemento em $O(1)$
    
- `s.find(valor)` -> Retorna o iterador em $O(\log N)$
    
- `s.count(valor)` -> 1 se existe / 0 se não existe em $O(\log N)$
    
- `s.lower_bound(valor)` -> $O(\log N)$ (Detalhado em Vector)
    
- `s.upper_bound(valor)` -> $O(\log N)$
    
- `s.size()` -> Tamanho em $O(1)$
    
- `s.empty()` -> Vazio? $O(1)$
    
- `s.clear()` -> Limpa o set em $O(N)$
    

> [!info] Operações de Conjunto - $O(N+M)$
> 
> - `set_intersection` (Elementos em comum)
>     
> - `set_union` (Pelo menos um)
>     
> - `set_difference` (Elementos diferentes)
>     
> - **Exemplo de uso:** `set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(vetor_destino));`
>     

---

## 3. Map (Dicionário)

É um dicionário que armazena pares chave-valor. As **chaves são únicas e sempre ordenadas**.

`map<tipo_chave, tipo_valor> mapa;`

- **Atribuição:** `mapa[chave] = valor;` -> $O(\log N)$
    
- **Acesso:** `mapa[chave];` -> $O(\log N)$
    

> [!danger] CUIDADO: Criação acidental de chaves!
> 
> Se a chave não existe e você tenta acessá-la via `mapa[chave]`, ela **é criada** com valor zero/vazio. Isso pode causar erro de Memória (MLE) ou Tempo (TLE). Para verificar se existe, use sempre `mapa.count(chave)` ou `mapa.find(chave)`.

- `mapa.erase(chave)` -> $O(\log N)$
    
- `mapa.erase(iterador)` -> $O(1)$
    
- `mapa.count(chave)` -> 1 se existe / 0 se não existe em $O(\log N)$
    
- `mapa.find(chave)` -> Retorna o iterador (Opção mais recomendada) em $O(\log N)$
    
- `mapa.lower_bound(chave)` -> $O(\log N)$
    
- `mapa.upper_bound(chave)` -> $O(\log N)$
    
- `mapa.size()` -> $O(1)$
    
- `mapa.empty()` -> $O(1)$
    
- `mapa.clear()` -> $O(N)$
    

**Como iterar no Map:**

```C++
for(auto ii : mapa) {
    auto chave = ii.first;
    auto valor = ii.second;
}
```
