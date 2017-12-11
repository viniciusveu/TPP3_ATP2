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

Cadeia Str_cent;
Cadeia Str_reais;
Cadeia Str_mil;
Cadeia Str_final;

//SCOPO=========================================================================

void  Leitura_Valor(long int *Valor);
short Reais(int Valor, char *Str);
void  Centavos(long int Valor, char *Str);
short Unidade(int Valor, char *Str);
short Dezena(int Valor, char *Str);
short Centena(int Valor, char *Str);
short Milhar(int Valor, char *Str);

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

short Reais(int Valor, char *Str)  {
  Cadeia Str_cent, Str_unid, Str_deze;
  int reais = (Valor%1000);

  strcpy(Str_cent, NULA);
  strcpy(Str_unid, NULA);
  strcpy(Str_deze, NULA);

  if(reais) {
    if( Centena(reais, Str_cent) ) {
      if( Dezena(reais, Str_deze) )  {
        strcat(Str_cent, " e ");
        if(Unidade(reais, Str_unid)) {
          strcat(Str_cent, Str_deze);
          strcat(Str_cent, " e ");
          strcat(Str_cent, Str_unid);
          strcpy(Str, Str_cent);
          strcat(Str, " reais ");
        }
        else {
          strcat(Str_cent, Str_deze);
          strcpy(Str, Str_cent);
          strcat(Str, " real ");
        }
      }
      else {
        if(Unidade(reais, Str_unid)){
          strcat(Str_cent, " e ");
          strcat(Str_cent, Str_unid);
          strcpy(Str, Str_cent);
          strcat(Str, " reais ");
        }
        else {
          if((reais/100) == 1) strcpy(Str_cent, " cem reais ");
          strcat(Str_cent, " reais ");
          strcpy(Str, Str_cent);
        }
      }
    }
    else  {
      strcpy(Str_cent, NULA);
      if( Dezena(reais, Str_deze) )  {
        if(Unidade(reais, Str_unid)) {
          strcat(Str_cent, Str_deze);
          strcat(Str_cent, " e ");
          strcat(Str_cent, Str_unid);
          strcpy(Str, Str_cent);
          strcat(Str, " reais ");
        }
        else {
          strcat(Str_cent, Str_deze);
          strcpy(Str, Str_cent);
          strcat(Str, " reais ");
        }
      }
      else {
        if( Unidade(reais, Str_unid) ) {
          strcat(Str_cent, Str_unid);
          strcpy(Str, Str_cent);
          strcat(Str, " reais ");
        }
        else {
          if( (reais/100) == 1 ) strcpy(Str_cent, " cem ");
          strcat(Str_cent, " reais ");
        }
      }
    }
    return 1;
  }
  else return 0;
} //Reais

//==============================================================================

void Centavos( long int Valor, char *Str)  {

  int cent = (Valor%100);
  Cadeia Str_unid, Str_deze;

  strcpy(Str_unid, NULA);
  strcpy(Str_deze, NULA);

  if( !Dezena(cent, Str_deze) )  {
    if( Unidade(cent, Str_unid) )
      if( cent%DEZ == 1 ) strcat(Str_unid, " centavo ");
      else strcat(Str_unid, " centavos ");
    strcpy(Str, Str_unid);
  }
  else  {
    strcpy(Str_unid, NULA);
    if( Unidade(Valor, Str_unid) == 0 )  {
      strcat(Str_unid, " centavos ");
      strcat(Str_deze, Str_unid);
      strcpy(Str, Str_deze);
    }
    else  {
      if ( ((cent/DEZ) != 1 ) ) {
        strcat(Str_deze, " e ");
        strcat(Str_deze, Str_unid);
      }
      strcat(Str_deze, " centavos ");
      strcpy(Str, Str_deze);
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

//==============================================================================

short Milhar(int Valor, char *Str) {

  Cadeia Str_cent, Str_unid, Str_deze;
  int milhar = (Valor/1000);

  strcpy(Str_cent, NULA);
  strcpy(Str_unid, NULA);
  strcpy(Str_deze, NULA);

  if(milhar) {
    if( Centena(milhar, Str_cent) ) {
      if( Dezena(milhar, Str_deze) )  {
        strcat(Str_cent, " e ");
        if(Unidade(milhar, Str_unid)) {
          strcat(Str_cent, Str_deze);
          strcat(Str_cent, " e ");
          strcat(Str_cent, Str_unid);
          strcpy(Str, Str_cent);
          strcat(Str, " mil ");
        }
        else {
          strcat(Str_cent, Str_deze);
          strcpy(Str, Str_cent);
          strcat(Str, " mil ");
        }
      }
      else {
        if(Unidade(milhar, Str_unid)){
          strcat(Str_cent, " e ");
          strcat(Str_cent, Str_unid);
          strcpy(Str, Str_cent);
          strcat(Str, " mil ");
        }
        else {
          if((milhar/100) == 1) strcpy(Str_cent, " cem mil ");
          strcat(Str_cent, " mil ");
          strcat(Str, Str_cent);
        }
      }
    }
    else  {
      strcpy(Str_cent, NULA);
      if( Dezena(milhar, Str_deze) )  {
        if(Unidade(milhar, Str_unid)) {
          strcat(Str_cent, Str_deze);
          strcat(Str_cent, Str_unid);
          strcpy(Str, Str_cent);
          strcat(Str, " mil ");
        }
        else {
          strcat(Str_cent, Str_deze);
          strcpy(Str, Str_cent);
          strcat(Str, " mil ");
        }
      }
      else {
        if( Unidade(milhar, Str_unid) ) {
          strcat(Str_cent, Str_unid);
          strcpy(Str, Str_cent);
          strcat(Str, " mil ");
        }
        else {
          if( (milhar/100) == 1 ) strcpy(Str_cent, " cem ");
          strcat(Str_cent, " mil ");
          strcpy(Str, Str_cent);
        }
      }
    }
    return 1;
  }
  else return 0;
} //Centena

//MAIN==========================================================================

int main(void) {

  setlocale(LC_ALL, "");

  long int Valor;

  Leitura_Valor(&Valor);

  int reais = (Valor/100);


  printf("O valor lido é: \n");
  if(Milhar(reais, Str_mil))  {
    if(Reais(reais, Str_reais)){
      Centavos(Valor, Str_cent);
      strcat(Str_mil, ",");
      strcat(Str_mil, Str_reais);
      strcat(Str_mil, "e");
      strcat(Str_mil, Str_cent);
      strcpy(Str_final, Str_mil);
    }
    else {
      Centavos(Valor, Str_cent);
      strcat(Str_mil, "e");
      strcat(Str_mil, Str_cent);
      strcpy(Str_final, Str_mil);
    }
  }
  else  {
    if(Reais(reais, Str_reais)) {
      Centavos(Valor, Str_cent);
      strcat(Str_reais, "e");
      strcat(Str_reais, Str_cent);
      strcpy(Str_final, Str_reais);
    }
    else {
      Centavos(Valor, Str_cent);
      strcpy(Str_final, Str_cent);
    }
  }

  PULA;
  puts(Str_final);
  PULA;

  return 0;
}
