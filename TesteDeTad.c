#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TadPolinomio.h"


 
 int main(int argc, char **argv)
 {
	 PPol pol1, pol2, polsoma, polderivada, polmult;
	 double x;
	 char * poltexto=NULL;
	 FILE *arqIn, *arqOut;
	 
	 pol1 = pol2 = polsoma = polmult = polderivada = NULL;
	 
	 
	 //Carrega o polinômio 1
	 arqIn = fopen(argv[1],"r");
	 pol1 = carregaPolinomio(pol1, arqIn);
	 fclose(arqIn);
	 poltexto = converterPolinomio (pol1);
	 printf("\npol1 = %s",poltexto);
	 free(poltexto);
	 poltexto=NULL; 
	 
	 // Calcula o valor do polinômio para um dado valor de x.
	 x = 0;
	 while (x < 5) {
		 printf("\nValor pol1 para x = %.2lf: %.2lf",x,avaliarPolinomio(pol1,x));
		 x += 0.5;
	 }
	 
	 //Carrega o polinômio 2
	 arqIn = fopen(argv[2],"r");
	 pol2 = carregaPolinomio(pol1,arqIn);
	 fclose(arqIn);	
	 poltexto = converterPolinomio (pol2);
	 printf("\npol2 = %s",poltexto);
	 free(poltexto);
	 poltexto=NULL; 
		 
	 // Calcula o valor do polinômio para um dado valor de x.
	 x = 0;
	 while (x < 5) {
		 printf("\nValor pol2 para x = %.2lf: %0.2lf",x,avaliarPolinomio(pol2,x));
		 x += 0.5;
	 }
 
	 //Somar: cria e retorna um novo polinômio que
	 //é resultante da soma de pol1 e pol2.
	 polsoma = somarPolinomio(pol1, pol2);
	 
	 poltexto = converterPolinomio (pol1);
	 printf("\npol1 = %s",poltexto);
	 free(poltexto);
	 poltexto=NULL;
	 poltexto = converterPolinomio (pol2);
	 printf("\npol2 = %s",poltexto);
	 free(poltexto);
	 poltexto=NULL;
	 poltexto = converterPolinomio (polsoma);
	 printf("\npolsoma = %s",poltexto);
	 free(poltexto);
	 poltexto=NULL;
	 
	 
	 // Calcula o valor do polinômio para um dado valor de x.
	 x = 0;
	 while (x < 5) {
		 printf("\nValor polsoma para x = %.2lf: %0.2lf",x,avaliarPolinomio(polsoma,x));
		 x += 0.5;
	 }
 
	 //Multiplicar: cria e retorna um novo polinômio
	 //que resultante da multiplicação de pol1 e pol2.
	 polmult = multiplicarPolinomio (pol1, pol2);
	 poltexto = converterPolinomio (pol1);
	 printf("\npol1 = %s",poltexto);
	 free(poltexto);
	 poltexto=NULL;
	 poltexto = converterPolinomio (pol2);
	 printf("\npol2 = %s",poltexto);
	 free(poltexto);
	 poltexto=NULL;
	 poltexto = converterPolinomio (polmult);
	 printf("\npolmult = %s",poltexto);
	 free(poltexto);
	 poltexto=NULL;
	 
	 // Calcula o valor do polinômio para um dado valor de x.
	 x = 0;
	 while (x < 5) {
		 printf("\nValor polmult para x = %.2lf: % 0.2lf",x,avaliarPolinomio(polmult,x));
		 x += 0.5;
	 }
	 
 
	 //Derivar: cria e retorna um novo polinômio que
	 //é resultante da derivação em x de pol.
	 polderivada = derivarPolinomio (pol1);
	 poltexto = converterPolinomio (pol1);
	 printf("\npol1 = %s",poltexto);
	 free(poltexto);
	 poltexto=NULL;
	 poltexto = converterPolinomio (polderivada);
	 printf("\nderivada de pol1 = %s",poltexto);
	 free(poltexto);
	 poltexto=NULL;
	 // Calcula o valor do polinômio para um dado valor de x.
	 x = 0;
	 while (x < 5) {
		 printf("\nValor polderivada para x = %.2lf: %0.2lf\n",x,avaliarPolinomio(polderivada,x));
		 x += 0.5;
		 
	}
	
	 //Escreve os dados do polinômio num arquivo texto arq.
	 //Use a função salva termo para fazer a escrita dos termos do polinômio.
	 arqOut = fopen(argv[3],"w");
	 salvaPolinomio(pol1, arqOut);
	 fclose(arqOut);
	 
	 arqOut = fopen(argv[4],"w");
	 salvaPolinomio(pol2, arqOut);
	 fclose(arqOut);
	 
	 arqOut = fopen(argv[5],"w");
	 salvaPolinomio(polsoma, arqOut);
	 fclose(arqOut);
 
	 arqOut = fopen(argv[6],"w");
	 salvaPolinomio(polmult, arqOut);
	 fclose(arqOut);
 
	 arqOut = fopen(argv[7],"w");
	 salvaPolinomio(polderivada, arqOut);
	 fclose(arqOut);
	 
 
	//Libera a área alocada para o polinômio e retorna NULL.
	pol1 = liberarPolinomio(pol1);
	pol2 = liberarPolinomio(pol2);
	polsoma = liberarPolinomio(polsoma);
	polmult = liberarPolinomio(polmult);
	polderivada = liberarPolinomio(polderivada);
	printf("%d\n", polderivada == NULL);
 
	 return 0;
 }
 