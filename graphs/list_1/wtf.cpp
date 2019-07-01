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

struct node
{
    TipoVertice vertex;
    struct node* next;
};


typedef struct {
	TipoVertice ListaVertices[MAX_VERT];   
	int MatrizAdj[MAX_VERT][MAX_VERT];
	TipoPilha Pilha;
	struct node** adjLists;
	int* visited;
	int n;
} TipoGrafo;


struct queue {
    TipoVertice Items[50];  
    int front;
    int rear;
};




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

  	int vertices = 6;
   
    //Grafo->adjLists = malloc(vertices * sizeof(struct node*));
    //Grafo->visited = malloc(vertices * sizeof(int));
    
 
    int i;
    for (i = 0; i < vertices; i++) {
        Grafo->adjLists[i] = NULL;
        Grafo->visited[i] = 0;
    }
   
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

// void BuscaEmProfundidade(TipoGrafo* Grafo) {

// 	printf("\nDFS\n");
// 	TipoVertice* vInicio = &(Grafo->ListaVertices[0]);
// 	vInicio->FoiVisitado = 1;
// 	//ImprimeVertice(vInicio);
// 	Empilha(&(Grafo->Pilha), vInicio);

// 	printf("\n------- Pilha visitada inicial --------------\n");
// 	ListaPilha(&(Grafo->Pilha));
// 	printf("\n-----------------------------------\n");

		
// 	while(!PilhaVazia(&(Grafo->Pilha))) {
		
// 		TipoVertice *topo = VerTopo(&(Grafo->Pilha));			
// 		TipoVertice *v = AdjNaoVisitado(Grafo, topo);
		
// 		 if (v == NULL) {
// 		 	Desempilha(&(Grafo->Pilha));
// 		 } else {
// 		 	v->FoiVisitado = 1;
// 		 	//ImprimeVertice(v);
// 		 	Empilha(&(Grafo->Pilha), v);

// 			printf("\n------- Pilha visitada --------------\n");
// 			ListaPilha(&(Grafo->Pilha));
// 			printf("\n-----------------------------------\n");
		 	
// 		 }	
		


// 	}

// 	ZerarFlagsVisitado(Grafo);
	 
// }

int isEmpty(struct queue* q) {
    if(q->rear == -1) 
        return 1;
    else 
        return 0;
}


void enqueue(struct queue* q, TipoVertice* value){
    if(q->rear == 50-1)
        printf("\nQueue is Full!!");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->Items[q->rear] = *value;
    }
}

TipoVertice* dequeue(struct queue* q){
    TipoVertice* item;
   
    item = &q->Items[q->front];
    
    q->front++;

    if(q->front > q->rear){
        printf("Resetting queue\n");
        q->front = q->rear = -1;
    }
    
    return item;
}


void bfs(TipoGrafo* Grafo, queue* q) {


    printf("\nBFS\n");
	TipoVertice* vInicio = &(Grafo->ListaVertices[0]);
	vInicio->FoiVisitado = 1;
   
    enqueue(q, vInicio);
    
    while(!isEmpty(q)){

    	ListaGrafo(Grafo);
		TipoVertice* currentVertex = dequeue(q);
      	
        printf("Visited: \n");
        ImprimeVertice(currentVertex);
    
        //struct node* temp = Grafo->adjLists[currentVertex];
    
       // while(temp) {
       //      TipoVertice adjVertex* = temp->vertex;
       //      if(Grafo->visited[adjVertex] == 0){
       //          Grafo->visited[adjVertex] = 1;
       //          enqueue(q, adjVertex);
       //      }
       //      temp = temp->next;
       // }

  
    }
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


	adicionarAresta(Grafo, 0, 3);
	adicionarAresta(Grafo, 0, 4);
	adicionarAresta(Grafo, 0, 5);
	adicionarAresta(Grafo, 1, 3);
	adicionarAresta(Grafo, 1, 4);
	adicionarAresta(Grafo, 1, 5);
	adicionarAresta(Grafo, 2, 3);
	adicionarAresta(Grafo, 2, 4);
	adicionarAresta(Grafo, 2, 5);

}

int main(int argc, char *argv[]) {
 	
 	TipoGrafo Grafo;	 

 	queue q;

    q.front = -1;
    q.rear = -1;

	InicializaGrafo(&Grafo);
	
	InserirItensParaTeste(&Grafo);	
		 	
 	ListaGrafo(&Grafo);
 	bfs(&Grafo, &q);

 	
	return 0;
}
