#### Determine a complexidade assintótica do algoritmo Insertion Sort, apresentado a seguir,no pior caso (ordem inversa).

``` c
//Insertion-Sort(A)
for j = 2 to n 
    chave = a[j]
// insere chave na sequência ordenada A[l.,j-l]
    i= j-1
    while i>0 e a[i] > chave
        a[i+1] = a[i]
        i = i-1
    a[i+1] = chave
```
#### Análise:

##### 1) for j = 2 to n  
Aqui vamos de 2 até N vezes logo é um O(n)

##### 2) while i>0 e a[i] > chave
Aqui no pior caso [ordem inversa] percorreremos todo o array logo é um O(n)

##### 3) Todas as outras operações
As operações dentro dos loops (atribuições e comparações) são todas O(1)

##### 4) Conclusão 
O(n) X O(n) =  O(\(n^{2}\))

**Insertion-Sort é O(\(n^{2}\))**