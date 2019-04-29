#include <stdio.h>
#include <string.h>

typedef int identificador;

typedef struct {
	identificador matricula;	
	char nome[10];
	int idade;	
} aluno;

int i = 0;
aluno vAluno[100];

void inserir() {

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
		printf("Deseja Inserir Outro Registro (S/N)? ");
 	    scanf(" %c", &flag);
 	    i++;

	} while(flag != 'N');

}

void listar() {
	printf("------------------------------------------------\n");
	printf("%-5s %-15s %-15s %-10s\n", "#", "MATRICULA", "NOME", "IDADE");

	for(int k=0; k<i; k++) {
		printf("%-5d %-15d %-15s %-10d\n", (k+1), vAluno[k].matricula, vAluno[k].nome, vAluno[k].idade);
		
		
	}
	printf("------------------------------------------------\n");
	getchar();
	getchar();
}

void menu_de_opcoes() {

	int opcao;

	do {

		printf("\n--------O P Ç Õ E S----------\n");
		printf("1 - Inserir\n");
		printf("2 - Listar\n");
		printf("3 - Ordenar\n");
		printf("0 - Sair\n");

		printf("Selecione uma opção: ");
	 	scanf(" %d", &opcao);

	 	switch(opcao) {
	 		case 1: inserir(); break;	
	 		case 2: listar(); break;	

	 	}

	 	
	} while(opcao != 0);

}

int main(int argc, char *argv[]) {  

	menu_de_opcoes();

   return 0;
}
