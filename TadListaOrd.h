/* 
* NOME: Jadson Pereira
* MATRICULA: 20142BSI0429
*
*NOME: Tadeu da Penha Moraes Junior
*MATRICULA: 20142BSI0119
*/

#ifndef TADLISTAORD_H_INCLUDED
#define TADLISTAORD_H_INCLUDED

#include "TadListaDE.h"


typedef void * PInfo;
typedef PLista  PPol;

void imprimeListaPol(PPol lst);

PPol inserirEmOrdem(PPol pol, PInfo t);
PPol liberarPolinomio(PPol pol);
PPol somarPolinomio(PPol pol1, PPol pol2);
PPol multiplicarPolinomio (PPol pol1, PPol pol2);

PPol derivarPolinomio (PPol pol);

PPol carregaPolinomio(PPol pol, FILE* arq);

void salvaPolinomio(PPol pol, FILE* arq);
PPol limpaPoli(PPol pol);

#endif
