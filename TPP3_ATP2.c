/* Elaborar um programa em C que seja capaz de
ler uma entrada numérica (INICIALMENTE UMA STRING) a partir da linha de
comandos do tipo ddd.ddd,dd (0  d  9) e convertê-la para a string alfabética
correspondente.
-Vinícius Vedovotto
-João Pedro Silva Baptista
Trabalho Prático de Programação 3
ATP II - FCT/UNESP */

//CÓDIGO========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define PULA printf("\n\n\n\n\n");
#define DEZ 10
#define NULA "\0"

typedef char Cadeia[200];

Cadeia str_cent;

//SCOPO=========================================================================

void Leitura_Valor(long int *Valor);

//MAIN==========================================================================

int main(void) {
  long int valor;
  Leitura_Valor(&valor);
  PULA;
  printf("Valor lido:  %ld\n", valor);

  return 0;
}

//FUNÇÔES=======================================================================

void Leitura_Valor(long int *Valor) {
  do {
    printf(">Entre com um valor de 1 até 99 999 99: \n");
    scanf("%ld", Valor);
  }
  while (*Valor < 1 || *Valor > 9999999);
  return;
}//Leitura_Valor
