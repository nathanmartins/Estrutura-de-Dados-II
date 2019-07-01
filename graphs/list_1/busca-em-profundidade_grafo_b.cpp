#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERT 20

typedef struct {
	char Letra[2];	  
} TipoRegistro;

typedef struct {
	int Ordem; 
	TipoRegistro Item;
	int FoiVisitado;
} TipoVertice;

typedef struct {
	TipoVertice Reg[50];    
	int n;
} TipoPilha;

typedef struct {
	TipoVertice ListaVertices[MAX_VERT];   
	int MatrizAdj[MAX_VERT][MAX_VERT];
	TipoPilha Pilha;
	int n;
} TipoGrafo;

void InicializaPilha (TipoPilha *Pilha) {   
  Pilha->n = 0;
}


void ImprimeVertice(TipoVertice *v){
	printf("Ordem: %-3d Letra: %s \n",v->Ordem, v->Item.Letra); 
}



void ListaPilha(TipoPilha* Pilha) {
	for(int i = Pilha->n-1; i >=0; i--) {
	    ImprimeVertice(&(Pilha->Reg[i]));		
	}
}


int PilhaVazia(TipoPilha* Pilha) {
	if (Pilha->n > 0) 
		return 0;
	else return 1;	
}

void Empilha(TipoPilha* Pilha, TipoVertice* v) {
	Pilha->Reg[Pilha->n] = *v;	
	Pilha->n++;	
}

TipoVertice* Desempilha(TipoPilha* Pilha) {
	TipoVertice* reg = NULL;
	if (Pilha->n > 0) {
		Pilha->n--;
		reg = &Pilha->Reg[Pilha->n];
	}
	return reg;
}

TipoVertice* VerTopo(TipoPilha* Pilha) {
	TipoVertice* reg = NULL;
	if (Pilha->n > 0) {
		reg = &Pilha->Reg[Pilha->n-1];
	}
	return reg;
}

void InicializaGrafo (TipoGrafo *Grafo) {   
  InicializaPilha(&(Grafo->Pilha));
  Grafo->n = 0;  
  
	for(int i=0; i<MAX_VERT; i++) {
		for(int j=0; j<MAX_VERT; j++) {
			Grafo->MatrizAdj[i][j] = 0;
		}
	}	  
}

void adicionaVertice(TipoGrafo *Grafo, TipoRegistro Reg) {
	
	TipoVertice v;
	v.Ordem = Grafo->n;
	v.Item = Reg;
	v.FoiVisitado = 0;
	
	Grafo->ListaVertices[Grafo->n] = v;
	Grafo->n++;
}

void ListaGrafo(TipoGrafo* Grafo) {
	
	printf("\nGRAFO\n");	
	// ImprimeTituloVertice();
	// for(int i=0; i < Grafo->n; i++) {
	//     ImprimeVertice(&(Grafo->ListaVertices[i]));
	// }
	printf("----------------------------------------------------------------------------\n");
	
	printf("%-3s", "");
	for(int i=0; i<Grafo->n; i++) {
		printf("%-3d", Grafo->ListaVertices[i].Ordem);
	}
	printf("\n");
	
	for(int i=0; i<Grafo->n; i++) {
		printf("%-3d", Grafo->ListaVertices[i].Ordem);
		for(int j=0; j<Grafo->n; j++) {
			printf("%-3d", Grafo->MatrizAdj[i][j]);
		}
		printf("\n");
	}

	printf("----------------------------------------------------------------------------\n");
	
	
}

void adicionarAresta(TipoGrafo* Grafo, int inicio, int fim) {
	Grafo->MatrizAdj[inicio][fim] = 1;
	Grafo->MatrizAdj[fim][inicio] = 1;
}

TipoVertice* AdjNaoVisitado(TipoGrafo* Grafo, TipoVertice* v) {

	for(int j=0; j<Grafo->n; j++) {
		if ( (Grafo->MatrizAdj[v->Ordem][j] == 1) && (Grafo->ListaVertices[j].FoiVisitado == 0) ) {
			return &(Grafo->ListaVertices[j]);
		}
	}
	
	return NULL;
}

void ZerarFlagsVisitado(TipoGrafo* Grafo) {
	for(int j=0; j<Grafo->n; j++) {
		Grafo->ListaVertices[j].FoiVisitado = 0;		
	}
}

void BuscaEmProfundidade(TipoGrafo* Grafo) {

	printf("\nDFS\n");
	TipoVertice* vInicio = &(Grafo->ListaVertices[0]);
	vInicio->FoiVisitado = 1;
	//ImprimeVertice(vInicio);
	Empilha(&(Grafo->Pilha), vInicio);

	printf("\n------- Pilha visitada inicial --------------\n");
	ListaPilha(&(Grafo->Pilha));
	printf("\n-----------------------------------\n");

		
	while(!PilhaVazia(&(Grafo->Pilha))) {
		
		TipoVertice *topo = VerTopo(&(Grafo->Pilha));			
		TipoVertice *v = AdjNaoVisitado(Grafo, topo);
		
		 if (v == NULL) {
		 	Desempilha(&(Grafo->Pilha));
		 } else {
		 	v->FoiVisitado = 1;
		 	//ImprimeVertice(v);
		 	Empilha(&(Grafo->Pilha), v);

			printf("\n------- Pilha visitada --------------\n");
			ListaPilha(&(Grafo->Pilha));
			printf("\n-----------------------------------\n");
		 	
		 }	
		


	}

	ZerarFlagsVisitado(Grafo);
	 
}

void InserirItensParaTeste(TipoGrafo* Grafo) {
	TipoRegistro a1 = {"A"};
	adicionaVertice(Grafo, a1);
 	
 	TipoRegistro a2 = {"B"};
	adicionaVertice(Grafo, a2);

	TipoRegistro a3 = {"C"};
	adicionaVertice(Grafo, a3);

	TipoRegistro a4 = {"D"};
	adicionaVertice(Grafo, a4);

	TipoRegistro a5 = {"E"};
	adicionaVertice(Grafo, a5);

	TipoRegistro a6 = {"F"};
	adicionaVertice(Grafo, a6);

	TipoRegistro a7 = {"G"};
	adicionaVertice(Grafo, a7);

	TipoRegistro a8 = {"H"};
	adicionaVertice(Grafo, a8);

	TipoRegistro a9 = {"I"};
	adicionaVertice(Grafo, a9);

	TipoRegistro a10 = {"J"};
	adicionaVertice(Grafo, a10);



	// Letra A
	adicionarAresta(Grafo, 0, 1);    // A->B
	adicionarAresta(Grafo, 0, 4);    // A->E
	adicionarAresta(Grafo, 0, 5);    // A->F
	adicionarAresta(Grafo, 1, 0);    // B->A
	adicionarAresta(Grafo, 4, 0);    // E->A
	adicionarAresta(Grafo, 5, 0);    // F->A


	// Letra B
	adicionarAresta(Grafo, 1, 2);    // B->C
	adicionarAresta(Grafo, 1, 6);    // B->G
	adicionarAresta(Grafo, 2, 1);    // C->B
	adicionarAresta(Grafo, 6, 1);     //G->B


	// Letra C
	adicionarAresta(Grafo, 2, 1);    // C->B
	adicionarAresta(Grafo, 2, 3);    // C->D
	adicionarAresta(Grafo, 2, 7);    // C->H
	adicionarAresta(Grafo, 3, 2);    // D->C
	adicionarAresta(Grafo, 7, 2);    // H->C


	// Letra D
	adicionarAresta(Grafo, 3, 4);    // D->E
	adicionarAresta(Grafo, 3, 8);    // D->I
	adicionarAresta(Grafo, 4, 3);    // E->D
	adicionarAresta(Grafo, 8, 3);    // I->D


	// Letra E
	adicionarAresta(Grafo, 4, 9);    // E->J
	adicionarAresta(Grafo, 9, 4);    // J->E


	// Letra F
	adicionarAresta(Grafo, 5, 7);    // F->H
	adicionarAresta(Grafo, 5, 8);    // F->I
	adicionarAresta(Grafo, 7, 5);    // H->F
	adicionarAresta(Grafo, 8, 5);    // I->F


	// Letra G
	adicionarAresta(Grafo, 6, 8);    // G->I
	adicionarAresta(Grafo, 6, 9);    // G->J
	adicionarAresta(Grafo, 8, 6);    // I->G
	adicionarAresta(Grafo, 9, 6);    // J->G


	// Letra H
	adicionarAresta(Grafo, 7, 9);    // H->J
	adicionarAresta(Grafo, 9, 7);    // J->H


}

int main(int argc, char *argv[]) {
 	
 	TipoGrafo Grafo;	 
	InicializaGrafo(&Grafo);
	
	InserirItensParaTeste(&Grafo);	
		 	
 	ListaGrafo(&Grafo);
 	
 	BuscaEmProfundidade(&Grafo);
 	
	return 0;
}
