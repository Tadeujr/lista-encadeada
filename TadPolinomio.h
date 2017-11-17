/* 
* NOME: Jadson Pereira
* MATRICULA: 20142BSI0429
*
*NOME: Tadeu da Penha Moraes Junior
*MATRICULA: 20142BSI0119
*/

#ifndef TADPOLI_H_INCLUDED
#define TADPOLI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TadListaOrd.h"
#include <math.h>

typedef char * string;


typedef struct Termo{
  unsigned int grau;
  double coef;
} TTermo, *PTermo;



PTermo criaTermo();

void inicTermo(PTermo novo, unsigned int grau, double coef);

PTermo leTermo(PTermo t);

PTermo carregaTermo(PTermo t,FILE * arq);

void escreveTermo(PTermo t);

void salvaTermo(PTermo t,FILE * arq);

int comparaTermo(PTermo t1, PTermo t2);

string toString(PTermo t); 

PTermo somarTermo(PTermo t1, PTermo t2);

PTermo multiplicarTermo(PTermo t1, PTermo t2);

double avaliarPolinomio ( PPol pol, double valorx);

string converterPolinomio (PPol pol);

PTermo liberaTermo(PTermo t);

long double pot(double base, double exp);

PTermo derivada(PTermo t);

double consultaCoefTermo(PTermo t);

unsigned int consultaGrauTermo(PTermo t);

int InPoli(PPol lst, unsigned int elem);

PPol liberarPolinomio(PPol pol);
#endif
