#include <stdio.h>
#include <string.h>

#define MAXN 100

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
    char Nome[10];
    int Idade;
} TipoRegistro;

typedef int TipoIndice;

typedef struct {
    TipoRegistro Item[MAXN + 1] ;
    TipoIndice n;
} TipoTabela;

void Inicializa (TipoTabela *T) {
    T->n = 0;
}

TipoIndice PesquisaSequencial(TipoChave x , TipoTabela *T) {
    int i ;
    
    T->Item[0].Chave = x;
    i = T->n + 1;
    
    do {
        i--;
    } while (T->Item[i].Chave != x);
    
    return i ;
}

void Insere(TipoRegistro Reg, TipoTabela *T) {
    if (T->n == MAXN)
        printf ("Erro: Tabela cheia\n");
    else {
        T->n++;
        T->Item[T->n] = Reg;
    }
}

TipoIndice PesquisaBinaria(TipoChave x , TipoTabela *T) {
    TipoIndice i , Esq, Dir ;
    
    if (T->n == 0)
        return 0;
    else {
        Esq = 1;
        Dir = T->n;
        do {
            
            i = (Esq + Dir ) / 2;
            
            if (x > T->Item[i].Chave)
                Esq = i + 1;
            else Dir = i - 1;
            
        } while (x != T->Item[i].Chave && Esq <= Dir );
        
        if (x == T->Item[i].Chave)
            return i ;
        else
            return 0;
    }
}

void ListaTabela(TipoTabela *T) {
    
    printf("\n");
    printf("%-8s %-15s %-8s\n", "CHAVE", "NOME", "IDADE");
    printf("------------------------------------\n");
    for(int i=1; i<=T->n; i++) {
        printf("%-8d %-15s %-8d\n", T->Item[i].Chave, T->Item[i].Nome, T->Item[i].Idade);
    }
    printf("------------------------------------\n\n");
}

void insertionSort(TipoTabela *T) {
    int i, j;
    TipoRegistro Key;
    
    for(int i=1; i<=T->n; i++) {
        
        Key = T->Item[i];
        j = i-1;
        
        while (j >= 1 && T->Item[j].Chave > Key.Chave) {
            T->Item[j+1] = T->Item[j];
            j = j-1;
        }
        T->Item[j+1] = Key;
    }
}

int main(int argc, char *argv[]) {
    
    TipoTabela tabelaDeAlunos;
    TipoChave chaveDePesquisa;
    TipoIndice indice;
    
    Inicializa(&tabelaDeAlunos);
    
    TipoRegistro a1, a2, a3, a4, a5;
    
    a1.Chave = 10; a1.Idade = 32; strcpy(a1.Nome, "Maria");
    Insere(a1, &tabelaDeAlunos);
    
    a2.Chave = 31; a2.Idade = 21; strcpy(a2.Nome, "Pedro");
    Insere(a2, &tabelaDeAlunos);
    
    a3.Chave = 8; a3.Idade = 15; strcpy(a3.Nome, "Samara");
    Insere(a3, &tabelaDeAlunos);
    
    a4.Chave = 15; a4.Idade = 41; strcpy(a4.Nome, "Joao");
    Insere(a4, &tabelaDeAlunos);
    
    a5.Chave = 4; a5.Idade = 27; strcpy(a5.Nome, "Carla");
    Insere(a5, &tabelaDeAlunos);
    
    
    insertionSort(&tabelaDeAlunos);
    
    do {
        
        ListaTabela(&tabelaDeAlunos);
        printf("Digite a chave de pesquisa ou -1 para sair: ");
        scanf("%d", &chaveDePesquisa);
        
        if (chaveDePesquisa != -1) {
            //indice = PesquisaSequencial(chaveDePesquisa, &tabelaDeAlunos);
            indice = PesquisaBinaria(chaveDePesquisa, &tabelaDeAlunos);
            
            if (indice != 0) {
                printf("\n------------------------------------\n");
                printf("Registro Encontrado:\n");
                printf("Chave: %d\nNome: %s\nIdade: %d", tabelaDeAlunos.Item[indice].Chave, tabelaDeAlunos.Item[indice].Nome, tabelaDeAlunos.Item[indice].Idade);
                printf("\n------------------------------------\n");
            } else {
                printf("\n---------------------------------------------------------\n");
                printf("Nao foi encontrado nenhum registro com a chave informada.");
                printf("\n---------------------------------------------------------\n");
            }
            getchar(); getchar();
        }
    } while (chaveDePesquisa != -1);
    
    return 0;
}
