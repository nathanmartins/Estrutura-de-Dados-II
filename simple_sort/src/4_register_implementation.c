#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 100

typedef int identificador;

typedef struct {
    identificador matricula;
    char nome[10];
    int idade;
} aluno;

int i = 0;
aluno vAluno[ARR_SIZE];

void insert() {

    char flag;

    do {

        printf("-----------------------------\n");

        printf("Digite a Matrícula: ");
        scanf("%d", &vAluno[i].matricula);

        printf("Digite o nome: ");
        scanf("%s", vAluno[i].nome);

        printf("Digite a idade: ");
        scanf("%d", &vAluno[i].idade);

        printf("-----------------------------\n");
        printf("Deseja insert Outro Registro (S/N)? ");
        scanf(" %c", &flag);
        i++;

    } while (flag != 'N');

}

void list() {
    printf("------------------------------------------------\n");
    printf("%-5s %-15s %-15s %-10s\n", "#", "MATRICULA", "NOME", "IDADE");

    for (int k = 0; k < i; k++) {
        printf("%-5d %-15d %-15s %-10d\n", (k + 1), vAluno[k].matricula, vAluno[k].nome, vAluno[k].idade);


    }
    printf("------------------------------------------------\n");
//    getchar();
//    getchar();
}

char randomLetter() {
    return 'A' + (random() % 26);
}

void prePopulate(int size) {
    for (i = 0; i < size; i++) {

        char buf[10];
        sprintf(buf, "Aluno #%c", randomLetter());

        vAluno[i].matricula = rand() % ARR_SIZE + 1;
        vAluno[i].idade = rand() % 50;
        strcpy(vAluno[i].nome, buf);
    }
}

void pointerSwap(aluno *x, aluno *y) {
    aluno t = *x;
    *x = *y;
    *y = t;
}

void bubble(aluno arr[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {

            aluno a1, a2;

            a1 = arr[j];
            a2 = arr[j + 1];

            if (a1.matricula != 0 && a2.matricula != 0) {

                //printf("A1: %d, A2: %d \n", a1.matricula, a2.matricula);

                if (a1.matricula > a2.matricula) {
                    pointerSwap(&arr[j], &arr[j + 1]);
                }
            }
        }
    }

    list();
}

void selection(aluno arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {

            aluno a1, a2;

            a1 = arr[j];
            a2 = arr[min_idx];

            if (a1.matricula != 0 && a2.matricula != 0) {
                int res = strcmp(arr[j].nome, arr[min_idx].nome);
//                printf("Comparing %s and %s  == %d\n", a1.nome, a2.nome, res);
                if (res < 0) {
                    min_idx = j;
                }
            }

        }
        pointerSwap(&arr[min_idx], &arr[i]);
    }

    list();
}

void insertion(aluno arr[], int n) {

    int j;
    for (int i = 1; i < n; i++) {

        j = i;

        while (j > 0 && arr[j].matricula > 0 && arr[j - 1].matricula > 0 && arr[j].idade < arr[j - 1].idade) {
            pointerSwap(&arr[j], &arr[j - 1]);
            j--;
        }
    }

    list();
}

void menu_de_opcoes() {

    int opcao;

    //prePopulate(10);
    //list();
    //bubble(vAluno, ARR_SIZE);
    //selection(vAluno, ARR_SIZE);
    //insertion(vAluno, ARR_SIZE);

    do {

        printf("\n--------O P Ç Õ E S----------\n");
        printf("1 - insert\n");
        printf("2 - list\n");
        printf("3 - Método da Bolha para ordenar pelo campo “identificação”\n");
        printf("4 - Ordenação por Seleção para ordenar pelo campo “nome”.\n");
        printf("5 - Ordenação por Inserção para ordenar pelo campo “idade”.\n");
        printf("6 - Prepopular banco de dados.\n");
        printf("0 - Sair\n");

        printf("Selecione uma opção: ");
        scanf(" %d", &opcao);

        switch (opcao) {
            case 1:
                insert();
                break;
            case 2:
                list();
                break;
            case 3:
                bubble(vAluno, ARR_SIZE);
                break;
            case 4:
                selection(vAluno, ARR_SIZE);
                break;
            case 5:
                insertion(vAluno, ARR_SIZE);
                break;
            case 6:
                prePopulate(20);
                break;
        }


    } while (opcao != 0);

}

int main(int argc, char *argv[]) {

    menu_de_opcoes();

    return 0;
}
