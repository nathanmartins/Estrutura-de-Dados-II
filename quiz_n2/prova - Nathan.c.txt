#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXN 100

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
    char Nome[10];
    int PosInicial;
} TipoRegistro;

typedef int TipoIndice;

typedef struct {
    TipoRegistro Item[MAXN + 1];
    TipoIndice n;
} TipoTabela;

void Inicializa(TipoTabela *T) {
    T->n = 0;
}

void Insere(TipoRegistro Reg, TipoTabela *T) {
    if (T->n == MAXN)
        printf("Erro: Tabela cheia\n");
    else {
        T->Item[T->n] = Reg;
        T->n++;
    }
}

void ListaTabela(TipoTabela *T) {

    printf("\n");
    printf("%-8s %-15s %-8s\n", "CHAVE", "NOME", "POS INICIAL");
    printf("------------------------------------\n");
    for (int i = 0; i < T->n; i++) {
        printf("%-8d %-15s %-8d\n", T->Item[i].Chave, T->Item[i].Nome, T->Item[i].PosInicial);
    }
    printf("------------------------------------\n\n");
}

void troca(TipoRegistro *left, TipoRegistro *right) {
    TipoRegistro tmp = *right;
    *right = *left;
    *left = tmp;
}


void insertionSort(TipoTabela *T, int inicio, int fim) {
    int i, j;
    TipoRegistro key;

    for (i = inicio; i <= fim; i++) {
        key = T->Item[i];
        j = i - 1;

        while (j >= inicio && T->Item[j].PosInicial > key.PosInicial && T->Item[i].Chave == T->Item[j].Chave) {

//            printf("Matching: %d == %d\n", T->Item[i].Chave, T->Item[j].Chave);

            T->Item[j + 1] = T->Item[j];
            j = j - 1;
        }


        T->Item[j + 1] = key;

    }
}

//void insertionSort(TipoTabela *T, int inicio, int fim) {
//    int i, j;
//    TipoRegistro key;
//
//    for (i = inicio; i <= fim; i++) {
//
//
//        j = i - 1;
//        key = T->Item[i];
//
////        printf("Checking keys: %d == %d\n", T->Item[i].Chave, T->Item[j].Chave);
//
//        if (T->Item[i].Chave == T->Item[j].Chave) {
//
//            printf("Found keys: %d == %d at %d %d\n", T->Item[i].Chave, T->Item[j].Chave, T->Item[i].PosInicial,
//                   T->Item[j].PosInicial);
//
//            if (T->Item[i].PosInicial > T->Item[j].Chave) {
//                printf("Found postions: %d == %d\n\n", T->Item[i].PosInicial, T->Item[j].PosInicial);
//
//                while (j >= inicio && T->Item[j].PosInicial > key.PosInicial) {
//                    T->Item[j + 1] = T->Item[j];
//                    j = j - 1;
//                }
//
//                T->Item[j + 1] = key;
//            }
//
//        }
//
//    }
//}

void quickSort(TipoTabela *T, int inicio, int fim) {


    int i, j, pivo;

    TipoTabela v;

    memcpy(&v.Item, &T->Item, sizeof(T->Item));
    memcpy(&v.n, &T->n, sizeof(T->n));

    i = inicio;
    j = fim;


//    printf("%d, %d \n\n", inicio, fim);
//    printf("%d \n\n", (inicio, fim) / 2);


    pivo = v.Item[(inicio + fim) / 2].Chave;
//    printf("Pivo: %d \n", pivo);

    while (i <= j) {
        while (v.Item[i].Chave < pivo && i < fim) i++;

        while (v.Item[j].Chave > pivo && j > inicio) j--;;

        if (i <= j) {
            troca(&T->Item[i], &T->Item[j]);
            i++;
            j--;
        }
    }
    if (j > inicio) {
        quickSort(T, inicio, j);
    }
    if (i < fim) {
        quickSort(T, i, fim);
    }


}

void inicializaDadosDaTabela(TipoTabela *T) {

    TipoRegistro a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;

    a1.Chave = 10;
    a1.PosInicial = 0;
    strcpy(a1.Nome, "Maria");
    Insere(a1, T);

    a2.Chave = 27;
    a2.PosInicial = 1;
    strcpy(a2.Nome, "Pedro");
    Insere(a2, T);

    a3.Chave = 8;
    a3.PosInicial = 2;
    strcpy(a3.Nome, "Samara");
    Insere(a3, T);

    a4.Chave = 33;
    a4.PosInicial = 3;
    strcpy(a4.Nome, "Joao");
    Insere(a4, T);

    a5.Chave = 4;
    a5.PosInicial = 4;
    strcpy(a5.Nome, "Carla");
    Insere(a5, T);

    a6.Chave = 8;
    a6.PosInicial = 5;
    strcpy(a6.Nome, "Roberta");
    Insere(a6, T);

    a7.Chave = 12;
    a7.PosInicial = 6;
    strcpy(a7.Nome, "Carlos");
    Insere(a7, T);

    a8.Chave = 33;
    a8.PosInicial = 7;
    strcpy(a8.Nome, "Renan");
    Insere(a8, T);

    a9.Chave = 8;
    a9.PosInicial = 8;
    strcpy(a9.Nome, "Ana");
    Insere(a9, T);

    a10.Chave = 40;
    a10.PosInicial = 9;
    strcpy(a10.Nome, "Lucio");
    Insere(a10, T);

    a11.Chave = 33;
    a11.PosInicial = 10;
    strcpy(a11.Nome, "Marcia");
    Insere(a11, T);

    a12.Chave = 8;
    a12.PosInicial = 11;
    strcpy(a12.Nome, "Beatriz");
    Insere(a12, T);
}

void CorrigirInstabilidade(TipoTabela *T, int inicio, int fim) {

    //Descubra as posições de início e fim de cada bloco de chaves duplicadas.

    int j, i, dupi, dupf;
//    printf("\nInicio %d  fim %d\n\n", inicio, fim);
    j = fim;
    i = inicio;
    dupi = -1;
    dupf = -1;


    int seen = 0;


    for (int i = 0; i < fim; ++i) {

//        printf("Checking keys: %d == %d\n", T->Item[i].Chave, T->Item[i - 1].Chave);

        if (T->Item[i].Chave == T->Item[i + 1].Chave) {
            if (!seen) {
                dupi = i;
                seen = 1;
            }
        } else {
            seen = 0;
            if (dupi != -1) {
                dupf = i;
            }
        }

        if (dupi != -1 && dupf != -1) {
            printf("BLOCO ENCONTRADO: Inicio: %d  - FIM: %d\n", dupi, dupf);
            dupi = -1;
            dupf = -1;
        }

    }


    //Realize a ordenação de cada bloco pelo campo POS_INICIAL utilizando o algoritmo InsertionSort().
    insertionSort(T, i, fim);

}

int main(int argc, char *argv[]) {

    TipoTabela tabelaDeAlunos;
    TipoChave chaveDePesquisa;
    TipoIndice indice;

    Inicializa(&tabelaDeAlunos);
    inicializaDadosDaTabela(&tabelaDeAlunos);

    ListaTabela(&tabelaDeAlunos);
    quickSort(&tabelaDeAlunos, 0, tabelaDeAlunos.n - 1);

    ListaTabela(&tabelaDeAlunos);

    CorrigirInstabilidade(&tabelaDeAlunos, 0, tabelaDeAlunos.n - 1);
    ListaTabela(&tabelaDeAlunos);

    return 0;
}

