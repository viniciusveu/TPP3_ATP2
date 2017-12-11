#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 8
#define NUMBER 10
#define JUMP printf("\n\n")
#define STRNULL "\0"
typedef char Chain[200];

Chain Str_Cents;

void moneyToArray(int *A, int money);
void moneyInput(long int *Value);
void moneyArrayPrint(int *A, int size);
void analiseNumberOneCase(char *Str, int *A);
void analisarDezena(int *A, int number, char *Str);
void analisarUnidade(int *A, int number, char *Str, int analisator);
void analisarCentena(int number, char *Str);
//====================================================================

void moneyToArray(int *A, int money){
	int i;
	for(i = 0; i < SIZE; i++){
		*(A+i) = money%NUMBER;
		money /= NUMBER;
	}
}

void moneyInput(long int *Value){
	do{
		system("cls");
		printf("Entre com um número até 999.999,99\n");
		scanf("%ld", Value);
	} while(*Value < 1 || *Value >= 99999999  );
}



void analiseCents(char *Str, int *A){
	int i;
	Chain Str_Aux;
	//Dezena
	analisarDezena(A, *(A+1), Str);
	//Unidade
	analisarUnidade(A, *(A), Str, 1);
	strcat(Str, "centavos");
}

void analiseNotCents(char *Str, int *A){
	int i = SIZE-1;
	for(; i >=2; i--){

		switch(i){
			case 2: 
				analisarUnidade(A, *(A+i), Str, 3); 
				strcat(Str, " reais e ");
				break;
			case 3: analisarDezena(A, *(A+i), Str); break;
			case 4: analisarCentena(*(A+i), Str); break;
			case 5: 
				analisarUnidade(A, *(A+i), Str, 6);
				if((*(A+i))){
					if(!(*(A+i+1)))
						strcat(Str, " mil ");
				}
				break;
			case 6: 
				analisarDezena(A ,*(A+i), Str);
				if((*(A+i))){
					if(!(*(A+i+1)) && !(*(A+i-1)))
						strcat(Str, " mil ");
				}
				break;
			case 7: 
				analisarCentena(*(A+i), Str);
				if((*(A+i))){
					if(!(*(A+i-1)) && !(*(A+i-2)))
						strcat(Str, " mil ");
				}
				break;
		}
	}
}

void analisarCentena(int number, char *Str){
		switch(number){
			case 0: break;
			case 1: strcat(Str, "Cento "); break;
			case 2: strcat(Str, "Duzentos "); break;
			case 3: strcat(Str, "Trezentos "); break;
			case 4: strcat(Str, "Quatrocentos "); break;
			case 5: strcat(Str, "Quinhentos "); break;
			case 6: strcat(Str, "Seiscentos "); break;
			case 7:	strcat(Str, "Setecentos "); break;
			case 8:	strcat(Str, "Oitocentos "); break;
			case 9:	strcat(Str, "Novecentos "); break;
		}
}

void analisarDezena(int *A, int number, char *Str){
	switch(number){
		case 0: break;
		case 1: analiseNumberOneCase(Str, A); break;
		case 2: strcat(Str, "Vinte e"); break;
		case 3: strcat(Str, "Trinta e"); break;
		case 4: strcat(Str, "Quarenta e"); break;
		case 5: strcat(Str, "Cinquenta e"); break;
		case 6: strcat(Str, "Sessenta e"); break;
		case 7:	strcat(Str, "Setenta e"); break;
		case 8:	strcat(Str, "Oitenta e"); break;
		case 9:	strcat(Str, "Noventa e"); break;
	}
}

void analisarUnidade(int *A, int number, char *Str, int analisator){
	if(*(A+analisator) != 1){
		switch(number){
			case 0: break;
			case 1: strcat(Str, " Um "); break;
			case 2: strcat(Str, " Dois "); break;
			case 3: strcat(Str, " Tres "); break;
			case 4: strcat(Str, " Quatro ");break;
			case 5: strcat(Str, " Cinco "); break;
			case 6: strcat(Str, " Seis "); break;
			case 7: strcat(Str, " Sete "); break;
			case 8: strcat(Str, " Oito ");	break;
			case 9: strcat(Str, " Nove "); break;
		}
	}
}

void moneyArrayPrint(int *A, int size){
	int i = size-1;
	for(; i >= 0; i--)
		printf("[%d]", *(A+i));
}


void analiseNumberOneCase(char *Str, int *A){
	switch(*(A)){
		case 0: strcat(Str, "dez "); break;
		case 1: strcat(Str, "onze "); break;
		case 2: strcat(Str, "doze "); break;
		case 3: strcat(Str, "treze "); break;
		case 4: strcat(Str, "catorze ");break;
		case 5: strcat(Str, "quinze "); break;
		case 6: strcat(Str, "dezesseis "); break;
		case 7: strcat(Str, "dezessete "); break;
		case 8: strcat(Str, "dezoito ");	break;
		case 9: strcat(Str, "dezenove "); break;
	}
}


int main(){
	Chain Str;

	int i;
	long int m;
	int Money[SIZE];
	
	moneyInput(&m);
	moneyToArray(Money, m);
	moneyArrayPrint(Money, SIZE);

	JUMP;
	analiseNotCents(Str, Money);
	analiseCents(Str, Money);
	puts(Str);
	system("pause");
	return 0;
}
