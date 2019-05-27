#include <stdio.h>
#include <stdlib.h>
#define MAXN 17

typedef struct {
  int Chave;
  char Nome[10];
  int Idade;
} TipoRegistro;


typedef struct {
  TipoRegistro Item[MAXN + 1] ;
  int n;
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

int Hash(int Chave) { 
  return (Chave % MAXN); 
} 

int sondagemLinear(int pos, int i){
    return (pos + i) % MAXN;
}

int InsereSemColidirAberto(TipoTabela *T, TipoRegistro Reg){
    if(T == NULL || T->n == MAXN){
        return 0;
    }

    int chave = Reg.Chave;

    int i; 
	int pos, newPos;
    pos = Hash(chave);
    for(i=0; i < MAXN; i++){
        newPos = sondagemLinear(pos,i);
        printf("\n newPos = %d\ti = %d \n", newPos, i);
        //newPos = sondagemQuadratica(pos,i);
        //newPos = duploHash(pos,chave,i);
        if(T->Item[newPos].Chave == -1){
            TipoRegistro* novo;
            novo = (TipoRegistro*) malloc(sizeof(TipoRegistro));
            if(novo == NULL){
                return 0;
            }else{
	            *novo = Reg;
	            T->Item[newPos]=*novo;
	            T->n++;
	            return 1;
	        }
        }
    }
    return 0;
}

bool Insere(TipoRegistro Reg, TipoTabela *T) {     
  bool sucesso = false;
  int i = Hash(Reg.Chave);
 
  if (T->Item[i].Chave == -1) {
    T->Item[i] = Reg;
    T->n++;
    sucesso = true;
  }

  return sucesso;
} 

int Busca(int Chave, TipoTabela *T) {  
  int indice = Hash(Chave);
  return (T->Item[indice].Chave != -1) ? indice : -1;
}

bool Exclui(int Chave, TipoTabela *T) {
  bool sucesso = false;
  int indice = Busca(Chave, T);

   if (T->Item[indice].Chave == Chave) {    
    TipoRegistro a = {-1, "", 0};
    T->Item[indice] = a;
    T->n--;
    sucesso = true;
  }

  return sucesso;
}

/*void CargaInicialParaTeste(TipoTabela *T) {
  TipoRegistro a1 = {36, "Renan", 32};
  Insere(a1, T);

  TipoRegistro a2 = {53, "Maria", 65};
  Insere(a2, T);  

  /*
  * Colisão. Esta implementação básica
  * não vai inserir o registro.
  
  36, 53, 70, 87, 54, 37, 71 e 40
  */
  /*
  TipoRegistro a3 = {70, "Carla", 18};
  Insere(a3, T);

  TipoRegistro a4 = {87, "Pedro", 25};
  Insere(a4, T);
  
  TipoRegistro a5 = {54, "Pedro", 25};
  Insere(a5, T);
  
  TipoRegistro a6 = {37, "Pedro", 25};
  Insere(a6, T);
  
  TipoRegistro a7 = {71, "Pedro", 25};
  Insere(a7, T);
  
  TipoRegistro a8 = {40, "Pedro", 25};
  Insere(a8, T);
}
*/

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
  
  if (InsereSemColidirAberto(T, a))
    printf("O registro foi inserido com sucesso.");
  else
    printf("Não foi possível inserir o registro.");
  
  printf("\n------------------------------------");

  getchar();
  getchar();

}

void OpcaoPesquisarRegistro(TipoTabela *T) {
  int chaveDePesquisa;
  printf("Digite a chave de pesquisa: ");
  scanf("%d", &chaveDePesquisa);

  int indice = Busca(chaveDePesquisa, T);

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
  int chaveDePesquisa;

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
    
  //CargaInicialParaTeste(&tabelaDeAlunos);


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
/*

1) Suponha uma tabela hash armazenar valores de chaves. Insira as seguintes chaves nessa tabela: 36,
53, 70, 87, 54, 37, 71 e 40, nessa ordem. Considere os diferentes métodos:
a) Endereçamento Aberto (tabela hash de tamanho 17)
• Exploração linear: Passo(k) = k % arraySize+ 1
• Exploração quadrática: Passo(k) = k % arraySize + i2
• Hash duplo: h1(k) = k % arraySize; h2(k) = 5 - (k % 5)
b) Encadeamento separado (tabela hash de tamanho 5)]

*/
