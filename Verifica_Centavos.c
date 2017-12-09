void Verifica_Centavos(int Valor, char *Str_cent) {
 int  num = (Valor%100);
 Cadeia str_u,    // string associada a unidade
	    str_d;    // string associada a dezena

 strcpy(Str_cent,NULA);
 strcpy(str_u,NULA);
 strcpy(str_d,NULA);

 if ( !Verifica_Dezena(num, str_d) )      // algarismo da dezena e igual a zero
    {
      if ( Verifica_Unidade(num, str_u) )
	     if ( num%10 == 1) strcat(str_u," centavo");
	     else strcat(str_u," centavos");

      strcpy(str_cent,str_u);
    }
 else   // algarismo da dezena diferente de zero
   {
	 strcpy(str_u,NULA);
	 if ( Verifica_Unidade(Valor, str_u) == 0 ){
	     strcat(str_u,"  centavos");
	     strcat(str_d , str_u);
	     strcpy(Str_cent,str_d);
	    } //if
	 else {
	    if ( num/10 != 1) {
		   strcat(str_d, " e ");
		   strcat(str_d, str_u);
        }
	    strcat(str_d," centavos");
	    strcpy(Str_cent,str_d);
     }	// else mais interno
  }	// else mais externo

}  // Verifica_Centavos
