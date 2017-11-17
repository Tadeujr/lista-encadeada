/* 
* NOME: Jadson Pereira
* MATRICULA: 20142BSI0429
*
*NOME: Tadeu da Penha Moraes Junior
*MATRICULA: 20142BSI0119
*/


#ifndef Tad_Lista_DE
#define Tad_Lista_DE


typedef void * PInfo;

typedef struct No {
	struct No * ante;
	PInfo info;
	struct No * prox;
	
} TNo, *PNo;

typedef struct {
	PNo prim;
	PNo ulti;
	PNo atual;
	int tam;
} TLista, *PLista;


PLista inicLista(void);

void imprimeLista(PLista lst);

PLista posicionaJanelaInt(PLista lst, int pos);

PLista anxLista(PLista lst, PInfo elem);

PLista insLista(PLista lst, PInfo elem, int pos);

PLista inicLista(void);

PLista elmListaElem(PLista lst, PInfo elem);

PLista elmListaPos(PLista lst, int pos);

PLista carregaLista(PLista lst, FILE * arq);

void salvaLista(PLista lst, FILE * arq);

PLista copiaLista(PLista lst);

int vaziaLista(PLista lst);
PLista elmListaPos(PLista lst, int pos);
int tamLista(PLista lst);
#endif

 