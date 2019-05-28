#include <stdio.h>
#include <string.h>

#define MAXN 23

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
    char Nome[10];
    int Idade;
} TipoRegistro;

typedef int TipoIndice;

typedef struct {
    TipoRegistro Item[MAXN + 1];
    TipoIndice n;
} TipoTabela;

typedef struct {
    int Peso[10];
} TipoPesos;


void ListaTabela(TipoTabela *T) {
    printf("\n");
    printf("%-4s %-8s %-15s %-8s\n", "#", "CODIGO", "NOME", "IDADE");
    printf("------------------------------------\n");
    for (int i = 0; i < MAXN; i++) {
        if (T->Item[i].Chave != -1)
            printf("%-4d %-8d %-15s %-8d\n", i, T->Item[i].Chave, T->Item[i].Nome, T->Item[i].Idade);
        else
            printf("%-4d %-8s %-15s %-8s\n", i, "", "", "");
    }
    printf("------------------------------------\n");
}

void Inicializa(TipoTabela *T) {
    T->n = 0;
    for (int i = 0; i < MAXN; i++) {
        TipoRegistro a = {-1, "", 0};
        T->Item[i] = a;
    }
}

TipoIndice Hash(TipoChave Chave) {
    return (Chave % MAXN);
}

bool Insere(TipoRegistro Reg, TipoTabela *T, int fatorDuploHashing) {
    bool sucesso = false;


    if (T->n == MAXN) {
        return false;
    }

    TipoIndice i = Hash(Reg.Chave);

    if (T->Item[i].Chave == -1) {
        sucesso = true;
    } else {
        //Resolvendo colisoes com duplo hashing
        TipoIndice passo = fatorDuploHashing - (Reg.Chave % fatorDuploHashing);

        do {
            i = (i + passo) % MAXN;
        } while (T->Item[i].Chave != -1);
        sucesso = true;
    }

    T->Item[i] = Reg;
    T->n++;

    return sucesso;
}

void CargaInicialParaTeste(TipoTabela *T) {
    TipoRegistro a1 = {49, "Renan", 32};
    Insere(a1, T, 5);

    TipoRegistro a2 = {58, "Maria", 65};
    Insere(a2, T, 5);

    TipoRegistro a3 = {23, "Carla", 18};
    Insere(a3, T, 5);

    TipoRegistro a4 = {67, "Pedro", 25};
    Insere(a4, T, 5);

    TipoRegistro a5 = {47, "Ricardo", 36};
    Insere(a5, T, 5);

    //ListaTabela(T);

    //// Questao 01
    //// Insira os novos registros na tabela

    TipoRegistro a6 = {72, "Samara", 11};
    Insere(a6, T, 5);


    TipoRegistro a7 = {90, "Mario", 53};
    Insere(a7, T, 5);

    TipoRegistro a8 = {67, "Luana", 47};
    Insere(a8, T, 5);


    ////

    //ListaTabela(T);
}

//Retorna true se as string sao iguais
bool comparaTexto(char *texto1, char *texto2) {
    return (strcmp(texto1, texto2) == 0) ? true : false;
}

int hasCollision(TipoTabela *T, char *nome, int location) {

    if (T->Item[location].Chave == -1) {
        return 0;
    } else if (comparaTexto(T->Item[location].Nome, nome)) {
        printf("Collision at Table[%d]!\n\n", location);
        return 1;
    }

}


int step(int k, int arraySize) {
    return k % arraySize + 1;
}

int applyStep(TipoTabela *T, char *nome, int location) {

    int loc = step(loc, MAXN);

    if (hasCollision(T, nome, loc)) {
        loc = applyStep(T, nome, loc);
    }

    return loc;

}


int openAddressGetPosition(char *nome, TipoChave Chave, TipoTabela *T) {


    int loc = Hash(Chave);

    printf("PASSO: \n");
    printf("CHAVE: %d\n", T->Item[loc].Chave);
    printf("NOME: %s\n", T->Item[loc].Nome);
    printf("IDADE: %d\n", T->Item[loc].Idade);

    if (hasCollision(T, nome, loc)) {
        printf("Colision for Chave(%d) at index: %d\n\n", Chave, loc);
        loc = applyStep(T, nome, loc);
    }


    return loc;
}


void Busca(TipoChave Chave, char *nomeAluno, TipoTabela *T) {


    printf("BUSCANDO POR: ");
    printf("CHAVE: %d ", Chave);
    printf("NOME: %s\n", nomeAluno);


    for (int i = 0; i < MAXN; ++i) {

        int loc = openAddressGetPosition(nomeAluno, Chave, T);

        printf("\n");
        printf("Registro Encontrado:\n");
        printf("Chave: %d\nNome: %s\nIdade: %d", T->Item[loc].Chave, T->Item[loc].Nome,
               T->Item[loc].Idade);
        printf("\n");

//        if(loc == -1){
//            printf("\nITEM NAO ENCONTRADO\n");
//            return;
//        } else {
//
//        }
    }


}


int main(int argc, char *argv[]) {

    TipoTabela tabelaDeAlunos;
    int opcao, fatorDuploHashing = 5;

    Inicializa(&tabelaDeAlunos);

    CargaInicialParaTeste(&tabelaDeAlunos);

    Busca(90, "Mario", &tabelaDeAlunos);


    return 0;
}
