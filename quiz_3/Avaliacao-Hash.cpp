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
			  } while(T->Item[i].Chave != -1);			  
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
	
	ListaTabela(T); 
	
	//// Questao 01
	//// Insira os novos registros na tabela
	

	
	////
	
	ListaTabela(T);  
}

//Retorna true se as string sao iguais
bool comparaTexto(char* texto1, char* texto2) {
	return ( strcmp(texto1, texto2)==0) ? true : false;
}

void Busca(TipoChave Chave, char* nomeAluno, TipoTabela *T) {  
  
  
  printf("BUSCANDO POR: ");
  printf("CHAVE: %d ", Chave);
  printf("NOME: %s\n", nomeAluno);
  
  TipoIndice indice = Hash(Chave);
  if (T->Item[indice].Chave != -1) {
	
	printf("\n");
    printf("Registro Encontrado:\n");
    printf("Chave: %d\nNome: %s\nIdade: %d", T->Item[indice].Chave, T->Item[indice].Nome, T->Item[indice].Idade);
    printf("\n");  
		  		
  }
  else {
  	printf("\nITEM NAO ENCONTRADO\n");
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
