/* 
* NOME: Jadson Pereira
* MATRICULA: 20142BSI0429
*
*NOME: Tadeu da Penha Moraes Junior
*MATRICULA: 20142BSI0119
*/

#include <stdio.h>
#include <stdlib.h>
#include "TadListaDE.h"



/*aloca o nó da lista */
PNo criaNo(PInfo elem) {
	PNo novo = NULL;
	
	novo = (PNo) malloc (1 * sizeof(TNo));
	if (novo != NULL) {
		novo->ante = NULL;
		novo->prox = NULL;
		novo->info = elem;
	} else {
		fprintf(stderr,"Erro: aloca TNo");
	}
	return novo;
}

/*aloca e configura o cabeçalho descritor da lista */
PLista inicLista(void){
	PLista lst = NULL;
	lst = (PLista) malloc (1 * sizeof(TLista));
	if (lst != NULL) {
		lst->prim = NULL;
		lst->atual = NULL;
		lst->ulti = NULL;
		lst->tam = 0;
	} else {
		fprintf(stderr,"Erro: aloca TLista");
	}
	return lst;
}

/* Posiciona a janela no nó de posição pos */
PLista posicionaJanelaInt(PLista lst, int pos){
	int i;
	for (lst->atual = lst->prim,i=1 ; i < pos ; i++) {
		lst->atual = lst->atual->prox;
	}
	return lst;
}

/* Posiciona a janela no nó de endereço end */
PLista posicionaJanelaEnd(PLista lst, PNo end){
	lst->atual = end;
	return lst;
}

/* Retorna um inteiro que representa em que nó da
 * lista a janela está situada */
int consultaPosJan(PLista lst){
	int i;
	PNo aux;
	for (aux = lst->prim,i=1 ; (aux != lst->atual && i<=lst->tam) ; i++) {
		aux = aux->prox;
	}
	return i;
}

/* Retorna um inteiro que representa em que nó da
 * lista a janela está situada */
PNo consultaJanela(PLista lst){
	return lst->atual;
}

/* Retorna um inteiro que representa o tamanho da lista */
int consultaTamLista(PLista lst) {
	return lst->tam;
}

/* Retorna um inteiro diferente de 0 se lista está vazia
 * 0 caso contrário */
int vaziaLista(PLista lst) {
	return (lst->tam==0);
}

/* adiciona um novo nó após o último nó da lista pode estar:
 * - vazia
 * - com a janela apontando para o último nó
 * - com a janela apontando para um nó intermediário */
PLista anxLista(PLista lst, PInfo elem) {
	PNo novo;
	
	novo = criaNo(elem);
	
	/* lista está vazia */
	if (vaziaLista(lst)) {
		lst->prim = novo;
	} else {
		/* lista não está vazia: colocar a janela apontando 
		 * para ou último nó da lista */
		lst->ulti->prox = novo;
		novo->ante = lst->ulti;
	}
	lst->atual = novo;
	lst->ulti = novo;
	lst->tam ++;
	return lst;
}


/* adiciona um novo nó na posição pos */
/* se pos < 1 - insere novo nó na posição 1*/
/* se pos > tamanho atual da lista - insere novo nó no final da lista */
PLista insLista(PLista lst, PInfo elem, int pos){
	
	PNo novo;
	
	novo = criaNo(elem);
	
	
	/* COMPLETE O CÓDIGO*/ 
	if(pos <= 1){
		lst = posicionaJanelaInt(lst, 1);
		
		lst->prim = novo;
		novo->ante = NULL;
		novo->prox = lst->atual;
		lst->atual->ante = novo;
		lst->tam++;

	}else if(pos >= lst->tam){
		lst = anxLista(lst,elem);
		

	}else{
		lst = posicionaJanelaInt(lst,pos-1);
		novo->ante = lst->atual;
		novo->prox = lst->atual->prox;
		lst->atual->prox = novo;
		lst->tam++;

	}

	

	return lst;
}

/* remove da lista lst o primeiro nó contendo a
   informação elem, se existir elem na lista */

/* remove da lista lst o nó que ocupa a posição pos, 
   se tal posição existir na lista */
PLista elmListaPos(PLista lst, int pos){
	
	lst = posicionaJanelaInt(lst,pos);

	
	if(pos==1){ // se for a primeira posição da lista
		
		lst->prim = lst->prim->prox;
		lst->atual->prox->ante = NULL;
		free(lst->atual->info);
		free(lst->atual);
		lst->tam--;

	}else if(pos>=lst->tam){// se for a ultima posição
		
		lst->ulti = lst->ulti->ante;
		lst->ulti->prox = NULL;
		free(lst->atual->info);
		free(lst->atual);
		lst->tam--;
		
	}else{//qualquer posição da lista

		lst->atual->ante->prox = lst->atual->prox;
		lst->atual->prox->ante = lst->atual->ante;
		free(lst->atual->info);
		free(lst->atual);
		lst->tam--;
	}

	return lst;	

}






/* Dada uma lista lst, crie uma nova lista que é 
   uma cópia idêntica da lista lst */ 
PLista copiaLista(PLista lst){
	PLista novaLista = inicLista();
	lst = posicionaJanelaInt(lst,1);
	
	while(lst->atual != NULL){
		novaLista = anxLista(novaLista,lst->atual->info);
		lst->atual = lst->atual->prox;

	}


	return novaLista;
}

/* retorna um valor inteiro que presenta o
   tamanho atual da lista */
int tamLista(PLista lst){
	return lst->tam;
}

