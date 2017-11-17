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
#include <math.h>
#include "TadPolinomio.h"
#include "TadListaOrd.h"

int InPoli(PPol lst, unsigned int elem){
	while (lst->atual != NULL){
		if((elem == consultaGrauTermo(lst->atual->info))){
			return 1;
		}
		lst->atual = lst->atual->prox;	
	}
	return 0;	
}	

long double pot(double base, double exp){
	int i = exp;
	long double total;
	total = 1.0;

	while(i > 0){
		
		total = total * base;
		i--;
	}
	return total;
}

//  criar um termo (alocar memória para um termo)
//  Não passa parametro e retorna um Ponteiro para Termo. 
PTermo criaTermo(){
	PTermo novo;
	novo = (PTermo) malloc(1*sizeof(TTermo));
	return novo; 
}	
//  inicializar um termo
void inicTermo(PTermo novo, unsigned int grau, double coef){
	novo->grau = grau ;
	novo ->coef = coef;
}	

//get
double consultaCoefTermo(PTermo t){
	return t->coef;
}

unsigned int consultaGrauTermo(PTermo t){
	return t->grau;
}		

// ler do console (grau e coeficiente, um em cada linha nesta ordem)
PTermo leTermo(PTermo t){
	printf("Entre com o grau: ");
	scanf("%u",&t->grau);
	printf("Entre com o coef: ");
	scanf("%lf",&t->coef);	
	return t;
}	

// ler do arquivo texto (grau e coeficiente, um em cada linha nesta ordem)
PTermo carregaTermo(PTermo t, FILE * arq){
	fscanf(arq,"%u",&t->grau);
	fscanf(arq,"%lf",&t->coef);
	
	return t;
}

//escrever no console (grau e coeficiente, um em cada linha nesta ordem)
void escreveTermo(PTermo t){
	printf("%u\n",t->grau);
	printf("%lf\n",t->coef);
}	
//escrever no arquivo texto (grau e coeficiente, um em cada linha nesta ordem)
void salvaTermo(PTermo t,FILE * arq){
	fprintf(arq,"%u\n",t->grau);
	fprintf(arq,"%.2lf\n",t->coef);
}	

//comparar dois termos pelo grau. Retona -1 se t1 < t2; 0 se t1 = t2; 1 se t1 > t2
int comparaTermo(PTermo t1, PTermo t2){
	
	if ((t1->grau > t2->grau)){
		return 1;
	}else if((t1->grau < t2->grau)){
		return -1;
	}
	
	return 0;
		
}	

// 'converter um termo para sua representação em string:
string toString(PTermo t){

	char * poli = (string) malloc(128 * sizeof(char));
	double num;

	if(t->grau == 0){

		if(t->coef < 0){
			num = (t->coef) * (-1);

			sprintf(poli," - %.2lf",num);
		}else{
			sprintf(poli," + %.2lf",t->coef);
		}	
	}else if(t->coef < 0){
		num = (t->coef) * (-1);
		sprintf(poli," - %.2lf x ^ %u",num,t->grau);
	}else{
		sprintf(poli," + %.2lf x ^ %u",t->coef,t->grau);
	}	
	
	return poli;
}
// Else, o que fazer quando os termos forem diferentes? sei que nada sei.

// Somar dois termos
PTermo somarTermo(PTermo t1, PTermo t2){
	PTermo novo;
	novo = criaTermo();
	if (t1->grau == t2->grau){
		novo->coef = t1->coef + t2->coef;
		novo ->grau = t1->grau;
	}else{
		return NULL;
	}	
		
	return novo;	
}	
//Multiplicar dois termos
PTermo multiplicarTermo(PTermo t1, PTermo t2){
	PTermo novo;
	novo = criaTermo();
	novo->coef = t1->coef * t2->coef;
	novo->grau = t1->grau + t2->grau;


	return novo;
}

// deriva um Polinomio
PTermo derivada(PTermo t){
	PTermo novo;
	novo = criaTermo();
	if( t->grau == 0 && t->coef != 0.0){
		novo->coef = 0.0;
		novo->grau = 0;
	}else{
		novo->coef = t->coef * t->grau;
		novo->grau = t->grau - 1;
	}

	return novo;
}


//- Calcula o valor do polinômio para um dado valor de x
double avaliarPolinomio ( PPol pol, double valorx){
	
	double resultado = 0.0;
	pol = posicionaJanelaInt(pol,1);
	
	while(pol->atual!= NULL){
		
		resultado = resultado + (pow(valorx,consultaGrauTermo(pol->atual->info)) * consultaCoefTermo(pol->atual->info));
		pol->atual = pol->atual->prox;
	}	
	return resultado;
}	

string converterPolinomio(PPol pol){
	pol = limpaPoli(pol);
	string elem = NULL; 
	elem = (string) malloc(256 * sizeof(char));

	pol = posicionaJanelaInt(pol,1);
	
	while(pol->atual != NULL){
		elem = strcat(elem,toString(pol->atual->info));
			
		pol->atual = pol->atual->prox;
	
	}
	
	return elem;
	
} 

PTermo liberaTermo(PTermo t){
	free(t);
	
	return NULL;
}
