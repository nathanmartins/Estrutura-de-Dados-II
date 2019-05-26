#include <stdio.h>
#include <stdlib.h>

#define MAXN 13

typedef int TipoChave;

typedef struct TipoRegistro {
  TipoChave Chave;  
  char Nome[10];
  int Idade;  
} TipoRegistro;

typedef struct TipoCelula {
  TipoRegistro Registro;
  TipoCelula* Prox;
} TipoCelula;

typedef struct TipoLista {
  int Qtde;
  TipoCelula* Primeiro;
} TipoLista;

typedef int TipoIndice;

typedef struct TipoTabela {
  TipoLista Item[MAXN]; 
} TipoTabela;

void Inicializa (TipoTabela *T) {     
  for (int i=0; i<MAXN; i++) {      
      T->Item[i].Qtde = 0;
      T->Item[i].Primeiro = NULL;
    }
}

TipoIndice Hash(TipoRegistro Reg) { 
  return (Reg.Chave % MAXN); 
} 

void Insere(TipoRegistro Reg, TipoTabela* T) {
  TipoIndice i = Hash(Reg);
 
  TipoCelula* item = (TipoCelula*) malloc (sizeof(TipoCelula));
  item->Registro = Reg;
  item->Prox = NULL;

  if (T->Item[i].Primeiro != NULL) {
    item->Prox = T->Item[i].Primeiro;
  } 
    
  T->Item[i].Primeiro = item;
  T->Item[i].Qtde++;
}


void Imprime(TipoTabela *T) {  
  int k;
  printf("\n    %-4s %-8s %-15s %-8s\n", "#", "CODIGO", "NOME", "IDADE");

  for(int i=0; i<MAXN; i++) {
    
    printf("(%d)------------------------------------\n", i);

    TipoCelula* Aux;
    Aux = T->Item[i].Primeiro;  

    k = 0;
    while(Aux != NULL) {
      printf("    %-4d %-8d %-15s %-8d\n", ++k, Aux->Registro.Chave, Aux->Registro.Nome, Aux->Registro.Idade);
      Aux = Aux->Prox;
    }        
  }
  printf("\n");
}

int LerOpcaoMenu() {
  int opcao;
    
  printf("\n1: Listar\n");
  printf("2: Pesquisar\n");
  printf("3: Inserir\n");
  printf("4: Remover\n");

  printf("Escolha uma opção, ou -1 para sair: ");
  scanf("%d", &opcao);
  return opcao;

}

void CargaInicialParaTeste(TipoTabela *T) {
  TipoRegistro a1 = {49, "Renan", 32};
  Insere(a1, T);

  TipoRegistro a2 = {58, "Maria", 65};
  Insere(a2, T);  

  /*
  * Colisão. 
  */
  TipoRegistro a3 = {23, "Carla", 18};
  Insere(a3, T);

  TipoRegistro a4 = {67, "Pedro", 25};
  Insere(a4, T);
}

void OpcaoInserirRegistro(TipoTabela *T) {
  TipoRegistro a;
  
  printf("Digite a Chave: ");
  scanf("%d", &a.Chave);

  printf("Digite o Nome: ");
  scanf("%s", a.Nome);

  printf("Digite a Idade: ");
  scanf("%d", &a.Idade);

  printf("\n------------------------------------\n");
  
  Insere(a, T);
  printf("O registro foi inserido com sucesso.");
  
  
  printf("\n------------------------------------");

  getchar();
  getchar();

}

int main(int argc, char *argv[]) {
 	int opcao;
  TipoTabela Tabela;

  Inicializa(&Tabela);
  CargaInicialParaTeste(&Tabela); 

  do {
    opcao = LerOpcaoMenu();

    switch(opcao) {    
   //  case 2: OpcaoPesquisarRegistro(&Tabela); break;   
     case 3: OpcaoInserirRegistro(&Tabela); break;
   //  case 4: OpcaoExcluirRegistro(&Tabela); break;
     default: Imprime(&Tabela);  
    }

  } while (opcao != -1);  

	return 0;
}
