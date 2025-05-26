#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    int matricula;
    float cr;
    int ocupado;
} Aluno;

typedef Aluno* Hash;

void inicializar(Hash *tab, int m) {
    for (int i = 0; i < m; i++) {
        tab[i] = (Aluno*)malloc(sizeof(Aluno));
        tab[i]->ocupado = 0;
    }
}

int hash(int mat, int tam) {
    return mat % tam;
}

int encontrar_posicao(Hash *tab, int m, int mat, int *encontrado) {
    int h = hash(mat, m);
    for (int i = 0; i < m; i++) {
        int pos = (h + i*i) % m;
        if (tab[pos]->ocupado == 0) {
            *encontrado = 0; // não achou, espaço livre
            return pos;
        } else if (tab[pos]->ocupado == 1 && tab[pos]->matricula == mat) {
            *encontrado = 1; // achou
            return pos;
        }
    }
    return -1; // Tabela cheia
}

void inserir(Hash *tab, int m, int mat, float cr) {
    int encontrado;
    int pos = encontrar_posicao(tab, m, mat, &encontrado);
    if (pos == -1) {
        printf("Tabela cheia!\n");
        return;
    }

    if (encontrado) {
        printf("Matrícula já cadastrada!\n");
    } else {
        tab[pos]->matricula = mat;
        tab[pos]->cr = cr;
        tab[pos]->ocupado = 1;
    }
}

Aluno* buscar(Hash *tab, int m, int mat) {
    int h = hash(mat, m);
    for (int i = 0; i < m; i++) {
        int pos = (h + i*i) % m;
        if (tab[pos]->ocupado == 0) return NULL; // nunca esteve ocupado
        if (tab[pos]->ocupado == 1 && tab[pos]->matricula == mat)
            return tab[pos];
    }
    return NULL;
}

void remover(Hash *tab, int m, int mat) {
    int h = hash(mat, m);
    for (int i = 0; i < m; i++) {
        int pos = (h + i*i) % m;
        if (tab[pos]->ocupado == 0) {
            printf("Matrícula não cadastrada!\n");
            return;
        }
        if (tab[pos]->ocupado == 1 && tab[pos]->matricula == mat) {
            printf("mat = %d , cr = %.1f foi removido!\n", tab[pos]->matricula, tab[pos]->cr);
            tab[pos]->ocupado = -1;
            return;
        }
    }
    printf("Matrícula não cadastrada!\n");
}

void imprimir(Hash *tab, int m) {
    for (int i = 0; i < m; i++) {
        printf("tab[%d]: ", i);
        if (tab[i]->ocupado == 1)
            printf("mat = %d , cr = %.1f\n", tab[i]->matricula, tab[i]->cr);
        else if (tab[i]->ocupado == -1)
            printf("REMOVIDO\n");
        else
            printf("NULL\n");
    }
}

int main(void) {
    int n, m;
    printf("Digite o valor de m (tamanho da tabela hash): ");
    scanf("%d", &m);
    printf("Digite o valor de n (quantidade de matriculas): ");
    scanf("%d", &n);

    Hash tab[m];
    inicializar(tab, m);

    int i, mat;
    float cr;
    for (i = 0; i < n; i++) {
        printf("Digite a matricula do aluno %d: ", i+1);
        scanf("%d", &mat);
        printf("Digite o CR do aluno %d: ", i+1);
        scanf("%f", &cr);
        inserir(tab, m, mat, cr);
    }

    imprimir(tab, m);
    char resposta;

    do {
        printf("Digite a matricula que deseja procurar: ");
        scanf("%d", &mat);
        Aluno* p = buscar(tab, m, mat);
        if (p == NULL)
            printf("Matrícula não encontrada!\n");
        else 
            printf("Encontrou mat = %d , cr = %.1f\n", p->matricula, p->cr);
        printf("Quer procurar outra matrícula? (s/n) ");
        scanf(" %c", &resposta);
    } while ((resposta != 'N') && (resposta != 'n'));

    imprimir(tab, m);

    do {
        printf("Digite a matricula que deseja remover: ");
        scanf("%d", &mat);
        remover(tab, m, mat);
        imprimir(tab, m);
        printf("Quer remover outra matrícula? (s/n) ");
        scanf(" %c", &resposta);
    } while ((resposta != 'N') && (resposta != 'n'));

    for (i = 0; i < m; i++) {
        free(tab[i]);
    }

    return 0;
}
