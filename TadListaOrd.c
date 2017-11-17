/* 
* NOME: Jadson Pereira
* MATRICULA: 20142BSI0429
*
*NOME: Tadeu da Penha Moraes Junior
*MATRICULA: 20142BSI0119
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TadListaOrd.h"
#include "TadListaDE.h"
#include "TadPolinomio.h"


// Imprime a listaDE dos polinômios
void imprimeListaPol (PPol lst) {
	if (lst == NULL || lst->tam == 0){
		printf("Lista Vazia\n");
	}else{
		
		string  novo = "" ;
		lst = posicionaJanelaInt(lst,1);
		
		while(lst->atual != NULL){
			
			novo = toString(lst->atual->info);
			printf("%s",novo);
			lst->atual = lst->atual->prox;

		}
		printf("\n");
	}
	
}

PPol limpaPoli(PPol pol){
	int i = 1;
	pol = posicionaJanelaInt(pol,1);

	while(pol->atual != NULL){
		
		if (consultaCoefTermo((PTermo)pol->atual->info)==0.0){
			pol->atual->info = liberaTermo((PTermo)pol->atual->info);
			pol = elmListaPos(pol, i);
			
		}
		i++;
		pol->atual = pol->atual->prox;	
	}	
	
	return pol;
}

// Insere em forma ordenada.
PPol inserirEmOrdem(PPol lst, PInfo elem){
	int i = 1;
	if(vaziaLista(lst) == 1){
		
		lst = anxLista(lst, elem);
		
	
	}else if(comparaTermo((PTermo)elem , (PTermo)lst->prim->info) == 1){

		lst = insLista(lst,elem,-1);
		
	}else if(comparaTermo((PTermo)elem ,(PTermo)lst->ulti->info) == -1){
		lst = insLista(lst,elem, lst->tam+1);
	}else{	
		lst = posicionaJanelaInt(lst,1);
		
		while(lst->atual != NULL && comparaTermo((PTermo)elem,(PTermo)lst->atual->info) == -1){
			lst->atual = lst->atual->prox;
			i++;

		}

		if (comparaTermo(elem,lst->atual->info) == 0 ){

			lst->atual->info = somarTermo(elem,(PInfo)lst->atual->info);
			
		}else{
			lst = insLista(lst,elem,i);
		}
	
		
	}
	return lst;
}

//- Cria e retorna um novo polinômio que resultante da derivação em x de pol
PPol derivarPolinomio (PPol pol){
	PPol novo;
	novo = (PPol)inicLista();
	pol = posicionaJanelaInt(pol,1);
	while(pol->atual != NULL){
		novo = inserirEmOrdem(novo,derivada(pol->atual->info));
		pol->atual = pol->atual->prox;
	}	
	return novo;
}	

//- Cria e retorna um novo polinômio que resultante da multiplicação de pol1 e pol2
PPol multiplicarPolinomio (PPol pol1, PPol pol2){
	PPol novo;
	novo = (PPol)inicLista();
	PInfo total;
	pol1 = posicionaJanelaInt(pol1,1);
	
	while(pol1->atual != NULL){
		pol2 = posicionaJanelaInt(pol2,1);
		while(pol2->atual != NULL){
			total = multiplicarTermo(pol1->atual->info,pol2->atual->info);
			novo = inserirEmOrdem(novo,total);			
			pol2->atual = pol2->atual->prox;
		}
		pol1->atual = pol1->atual->prox;
		
	}	
	return novo;	
}

//- Soma cria e retorna um novo polinômio que é resultante da soma de pol1 e pol2
PPol somarPolinomio(PPol pol1, PPol pol2){
	PPol novo;
	novo = (PPol)inicLista();

	pol1 = posicionaJanelaInt(pol1,1);
	while(pol1->atual != NULL){
		pol2 = posicionaJanelaInt(pol2,1);
		while(pol2->atual != NULL){
			if (comparaTermo(pol1->atual->info,pol2->atual->info)==0){
				novo = inserirEmOrdem(novo,somarTermo((PTermo)pol1->atual->info,(PTermo)pol2->atual->info));			
			}
			pol2->atual = pol2->atual->prox;
		}
		pol1->atual = pol1->atual->prox;
	}		
	return novo;	
}

PPol carregaPolinomio(PPol pol, FILE * arq){
	
	PTermo poli;
	pol = inicLista();

	while(!feof(arq)){
		poli = criaTermo();		
		poli = carregaTermo(poli, arq);
		
		if(consultaCoefTermo(poli)!= 0){
			pol = inserirEmOrdem(pol,poli);
		}
	}


	return pol;
}

void salvaPolinomio(PPol pol, FILE* arq){
	pol = limpaPoli(pol);

	pol = posicionaJanelaInt(pol,1);
	
	while(pol->atual != NULL){
		salvaTermo(pol->atual->info,arq);
		
		pol->atual = pol->atual->prox;
	}
}


PPol liberarPolinomio(PPol pol){
	
	pol = posicionaJanelaInt(pol,1);

	while(pol->atual != NULL){
		pol->atual->info = liberaTermo((PTermo)pol->atual->info);
		free(pol->atual);
		pol->atual = pol->atual->prox;
		
	}
	
	free(pol);

	
	return NULL;
}	


