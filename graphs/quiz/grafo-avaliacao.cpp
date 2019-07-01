#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERT 20

typedef struct {
    char ID[2];
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

void ImprimeTituloVertice() {
    printf("%-3s %-5s %-5s\n", "#","ID", "VISITADO?");
}

void ImprimeVertice(TipoVertice *v){
    printf("%-3d %-5s %-3d\n",v->Ordem, v->Item.ID, v->FoiVisitado);
}

void ListaPilha(TipoPilha* Pilha) {
    ImprimeTituloVertice();
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
    ImprimeTituloVertice();
    for(int i=0; i < Grafo->n; i++) {
        ImprimeVertice(&(Grafo->ListaVertices[i]));
    }
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
    ImprimeVertice(vInicio);
    Empilha(&(Grafo->Pilha), vInicio);
    
    while(!PilhaVazia(&(Grafo->Pilha))) {
        
        TipoVertice *topo = VerTopo(&(Grafo->Pilha));
        TipoVertice *v = AdjNaoVisitado(Grafo, topo);
        
        if (v == NULL) {
            Desempilha(&(Grafo->Pilha));
        } else {
            v->FoiVisitado = 1;
            ImprimeVertice(v);
            Empilha(&(Grafo->Pilha), v);
        }
    }
    
    ZerarFlagsVisitado(Grafo);
    
}

void InserirItensParaTeste(TipoGrafo* Grafo) {
    TipoRegistro a0 = {"A"};
    adicionaVertice(Grafo, a0);
    
    TipoRegistro a1 = {"B"};
    adicionaVertice(Grafo, a1);
           
    adicionarAresta(Grafo, 0, 1);
	
	//Inserir aqui: vertices e arestas   
}

void VerticesSemAdjacencia(TipoGrafo* Grafo) {
    //
}

void RemoverAresta(TipoGrafo* Grafo, int inicio, int fim) {
	//
}

int main(int argc, char *argv[]) {
    
    TipoGrafo Grafo;
    InicializaGrafo(&Grafo);
    
    //Item A
    InserirItensParaTeste(&Grafo);    
    ListaGrafo(&Grafo);    
    BuscaEmProfundidade(&Grafo);
        
    //Item B    
    /*
	VerticesSemAdjacencia(&Grafo);
    */
    
    //Item C
    /*
	RemoverAresta(&Grafo, 1, 4); //Aresta BE        
    RemoverAresta(&Grafo, 5, 7); //Aresta FH  
    printf("\n\nGrafo apos Remocacao das Arestas BE e FH\n");
    ListaGrafo(&Grafo);
    VerticesSemAdjacencia(&Grafo);    
    */
    
    return 0;
}
