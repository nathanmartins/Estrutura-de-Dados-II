#include <stdio.h>

#define MAXN 13

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

typedef struct {
  int Peso[10]; 
} TipoPesos;


void ListaTabela(TipoTabela *T) {  
  printf("\n");
  printf("%-4s %-8s %-15s %-8s\n", "#", "CODIGO", "NOME", "IDADE");
  printf("------------------------------------\n");   
  for(int i=0; i<MAXN; i++) {    
    if (T->Item[i].Chave != -1)
      printf("%-4d %-8d %-15s %-8d\n", i, T->Item[i].Chave, T->Item[i].Nome, T->Item[i].Idade);
    else
      printf("%-4d %-8s %-15s %-8s\n", i, "", "", "");
  }
  printf("------------------------------------\n");
}

void Inicializa (TipoTabela *T) {   
  T->n = 0; 
  for (int i=0; i<MAXN; i++) {
      TipoRegistro a = {-1, "", 0};
      T->Item[i] = a;
    }
}

TipoIndice Hash(TipoChave Chave) { 
  return (Chave % MAXN); 
} 

/*
* Implementação básica, sem previsão de colisões
*/
bool Insere(TipoRegistro Reg, TipoTabela *T) {     
  bool sucesso = false;
  TipoIndice i = Hash(Reg.Chave);
 
  if (T->Item[i].Chave == -1) {
    T->Item[i] = Reg;
    T->n++;
    sucesso = true;
  }

  return sucesso;
} 

TipoIndice Busca(TipoChave Chave, TipoTabela *T) {  
  TipoIndice indice = Hash(Chave);
  return (T->Item[indice].Chave != -1) ? indice : -1;
}

bool Exclui(TipoChave Chave, TipoTabela *T) {
  bool sucesso = false;
  TipoIndice indice = Busca(Chave, T);

   if (T->Item[indice].Chave == Chave) {    
    TipoRegistro a = {-1, "", 0};
    T->Item[indice] = a;
    T->n--;
    sucesso = true;
  }

  return sucesso;
}

void CargaInicialParaTeste(TipoTabela *T) {
  TipoRegistro a1 = {49, "Renan", 32};
  Insere(a1, T);

  TipoRegistro a2 = {58, "Maria", 65};
  Insere(a2, T);  

  /*
  * Colisão. Esta implementação básica
  * não vai inserir o registro.
  */
  TipoRegistro a3 = {23, "Carla", 18};
  Insere(a3, T);

  TipoRegistro a4 = {67, "Pedro", 25};
  Insere(a4, T);
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

void OpcaoInserirRegistro(TipoTabela *T) {
  TipoRegistro a;
  
  printf("Digite a Chave: ");
  scanf("%d", &a.Chave);

  printf("Digite o Nome: ");
  scanf("%s", a.Nome);

  printf("Digite a Idade: ");
  scanf("%d", &a.Idade);

  printf("\n------------------------------------\n");
  
  if (Insere(a, T))
    printf("O registro foi inserido com sucesso.");
  else
    printf("Não foi possível inserir o registro.");
  
  printf("\n------------------------------------");

  getchar();
  getchar();

}

void OpcaoPesquisarRegistro(TipoTabela *T) {
  TipoChave chaveDePesquisa;
  printf("Digite a chave de pesquisa: ");
  scanf("%d", &chaveDePesquisa);

  TipoIndice indice = Busca(chaveDePesquisa, T);

  if (T->Item[indice].Chave == chaveDePesquisa) {
    printf("\n------------------------------------\n");
    printf("Registro Encontrado:\n");
    printf("Chave: %d\nNome: %s\nIdade: %d", T->Item[indice].Chave, T->Item[indice].Nome, T->Item[indice].Idade);
    printf("\n------------------------------------");       
  } else {
    printf("\n---------------------------------------------------------\n");
    printf("Nao foi encontrado nenhum registro com a chave informada.");
    printf("\n---------------------------------------------------------");  
  }
  getchar(); getchar();  

}

bool OpcaoExcluirRegistro(TipoTabela *T) {  
  TipoChave chaveDePesquisa;

  printf("Digite a chave de pesquisa: ");
  scanf("%d", &chaveDePesquisa);

  bool sucesso = Exclui(chaveDePesquisa, T);

  if (sucesso) {
    printf("\n------------------------------------\n");
    printf("O Registro foi Excluído.");   
    printf("\n------------------------------------");       
  } else {
    printf("\n---------------------------------------------------------\n");
    printf("Nao foi encontrado nenhum registro com a chave informada.");
    printf("\n---------------------------------------------------------");  
  }
  getchar(); getchar(); 
}



int main(int argc, char *argv[]) {
 	  
  TipoTabela tabelaDeAlunos;  
  int opcao;

  Inicializa(&tabelaDeAlunos);
    
  CargaInicialParaTeste(&tabelaDeAlunos);


  do {
    opcao = LerOpcaoMenu();

    switch(opcao) {    
     case 2: OpcaoPesquisarRegistro(&tabelaDeAlunos); break;   
     case 3: OpcaoInserirRegistro(&tabelaDeAlunos); break;
     case 4: OpcaoExcluirRegistro(&tabelaDeAlunos); break;
     default: ListaTabela(&tabelaDeAlunos);  
    }

  } while (opcao != -1);

	return 0;
}
