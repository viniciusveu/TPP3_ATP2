/* Elaborar um programa em C que seja capaz de
ler uma entrada numérica (INICIALMENTE UMA STRING) a partir da linha de
comandos do tipo ddd.ddd,dd (0 < d < 9) e convertê-la para a string alfabética
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
#include <ctype.h>

#define PULA printf("\n\n")
#define DEZ 10
#define NULA "\0"

typedef char Cadeia[200];

//VARIAVEIS_GLOBAIS==============================================================

Cadeia str_cent;
Cadeia Str_reais;
Cadeia Str_final;

//SCOPO=========================================================================

void  Leitura_Valor(long int *Valor);
void  Reais(int Valor, char *Str_reais);
void  Centavos(int Valor, char *Str_cent);
short Unidade(int Valor, char *Str);
short Dezena(int Valor, char *Str);

//FUNÇÔES=======================================================================

void Leitura_Valor( long int *Valor) {
  do {
    printf(">Entre com um valor de 1 até 999 999 99: \n");
    scanf("%ld", Valor);
  }
  while (*Valor < 1 || *Valor > 99999999 );
  return;
}//Leitura_Valor

//==============================================================================

void Reais(int Valor, char *Str_reais)  {

  reais = (Valor/100);
  Cadeia Str_mil, Str_cent, Str_unid, Str_deze;

  strcpy(Str_reais, NULA);
  strcpy(Str_mil, NULA);
  strcpy(Str_cent, NULA);
  strcpy(Str_unid, NULA);
  strcpy(Str_deze, NULA);

  if(!Centena(reais, Str_cent)) {
    if(Dezena(reais, Str_deze))
  }
  if( !Dezena(reais, Str_deze) )  {
    if( Unidade(reais, Str_unid) )
      if( reais%DEZ == 1 ) strcat(Str_unid, " reais ");
      else strcat(Str_unid, " reais ");
    strcpy(Str_cent, Str_unid);
  }
  else  {
    strcpy(Str_unid, NULA);
    if( Unidade(Valor, Str_unid) == 0 )  {
      strcat(Str_unid, " reais ");
      strcat(Str_deze, Str_unid);
      strcpy(Str_cent, Str_deze);
    }
    else  {
      if ( ((reais/DEZ) != 1 ) ) {
        strcat(Str_deze, " e ");
        strcat(Str_deze, Str_unid);
      }
      strcat(Str_deze, " reais ");
      strcpy(Str_cent, Str_deze);
    }
  }
  return;
} //Reais

//==============================================================================

void Centavos(int Valor, char *Str_cent)  {

  int cent = (Valor%100);
  Cadeia Str_unid, Str_deze;

  strcpy(Str_cent, NULA);
  strcpy(Str_unid, NULA);
  strcpy(Str_deze, NULA);
  
  if( !Dezena(cent, Str_deze) )  {
    if( Unidade(cent, Str_unid) )
      if( cent%DEZ == 1 ) strcat(Str_unid, " centavo ");
      else strcat(Str_unid, " centavos ");
    strcpy(Str_cent, Str_unid);
  }
  else  {
    strcpy(Str_unid, NULA);
    if( Unidade(Valor, Str_unid) == 0 )  {
      strcat(Str_unid, " centavos ");
      strcat(Str_deze, Str_unid);
      strcpy(Str_cent, Str_deze);
    }
    else  {
      if ( ((cent/DEZ) != 1 ) ) {
        strcat(Str_deze, " e ");
        strcat(Str_deze, Str_unid);
      }
      strcat(Str_deze, " centavos ");
      strcpy(Str_cent, Str_deze);
    }
  }
  return;
} //Centavos

//==============================================================================

short Unidade(int Valor, char *Str) {

  int unidade = Valor%DEZ;

  if(unidade) {
    switch (unidade) {
      case 1 : strcat(Str, " um ");     break;
      case 2 : strcat(Str, " dois ");   break;
      case 3 : strcat(Str, " três ");   break;
      case 4 : strcat(Str, " quatro "); break;
      case 5 : strcat(Str, " cinco ");  break;
      case 6 : strcat(Str, " seis ");   break;
      case 7 : strcat(Str, " sete ");   break;
      case 8 : strcat(Str, " oito ");   break;
      case 9 : strcat(Str, " nove ");   break;
    }
    return 1;
  }
  else return 0;
} //Unidade

//==============================================================================

short Dezena(int Valor, char *Str)  {

  int unidade, dezena;

  dezena = (Valor/DEZ)%DEZ;

  if(!dezena) return 0;
  else if(dezena == 1)  {
    unidade = Valor%DEZ;

    switch (unidade) {
      case 0 :  strcat(Str, " dez");        break;
      case 1 :  strcat(Str, " onze");       break;
      case 2 :  strcat(Str, " doze");       break;
      case 3 :  strcat(Str, " treze");      break;
      case 4 :  strcat(Str, " quatorze");   break;
      case 5 :  strcat(Str, " quinze");     break;
      case 6 :  strcat(Str, " dezesseis");  break;
      case 7 :  strcat(Str, " dezessete");  break;
      case 8 :  strcat(Str, " dezoito");    break;
      case 9 :  strcat(Str, " dezenove");   break;
    }
    return 1;
  }
  else  {
    switch (dezena) {
      case 2 : strcat(Str, " vinte ");        break;
      case 3 : strcat(Str, " trinta ");       break;
      case 4 : strcat(Str, " quarenta ");     break;
      case 5 : strcat(Str, " cinquenta ");    break;
      case 6 : strcat(Str, " sessenta ");     break;
      case 7 : strcat(Str, " setenta ");      break;
      case 8 : strcat(Str, " oitenta ");      break;
      case 9 : strcat(Str, " noventa ");      break;
    }
    return 2;
  }
} // Dezena

//==============================================================================

short Centena(int Valor, char *Str) {

  int centena = (Valor%1000)/100;

  if(centena) {
    switch (centena) {
      case 1 : strcat(Str, " cento ");        break;
      case 2 : strcat(Str, " duzentos ");     break;
      case 3 : strcat(Str, " trezentos ");    break;
      case 4 : strcat(Str, " quatrocentos "); break;
      case 5 : strcat(Str, " quinhentos ");   break;
      case 6 : strcat(Str, " seiscentos ");   break;
      case 7 : strcat(Str, " setecentos ");   break;
      case 8 : strcat(Str, " oitocentos ");   break;
      case 9 : strcat(Str, " novecentos ");   break;
    }
    return 1;
  }
  else return 0;
} //Centena

//MAIN==========================================================================

int main(void) {

  setlocale(LC_ALL, "");

  long int valor;

  Leitura_Valor(&valor);
  
  Reais(valor, Str_reais);
  strcat(Str_final, Str_reais);
  Centavos(valor, Str_cent);
  strcat(str_final, Str_cent);

  PULA;
  puts(str_final);
  PULA;

  return 0;
}






