#include <stdio.h> 

#define MAX 20000

int len (char vet[]){
	int i;
	for (i=0;vet[i];i++);
	return (i);
}

int limpa_string(char string[]){//RETIRA CARACTERES INVALIDOS 
	int i,j;

	for(i=0;i<len(string);i++){
		if (((string[i]<65)||(string[i]>90)) && ((string[i]<97)||(string[i]>122))){
			for(j=i;j<len(string);j++){
				string[j]=string[j+1];
			}
			i--;
		} 
	}
	return(1);
}

int upper(char string[]){//TRANSFORMA EM MAIUSCULA
	int i;

	for(i=0;i<len(string);i++){
		if((string[i]>=97)&&(string[i]<=122)) {
			string[i]=string[i]-32;
		}
	} 
	return(1);
}

int cifrar(char fFrase[]){//
	int cars_dig;
	
	cars_dig=len(fFrase); // Variavel armazena numero de caracteres antes das alterações :) 
	limpa_string(fFrase);
	
	upper(fFrase);
	


	printf("# modo cifragem ativado\n");

	return(1);
}

int decifrar(){
	int cars_dig ;

	printf("# modo decifragem ativado\n");
}
	

int main( int argc, char *argv[ ] ){

	int Qtd_strings, i;
	char frases[1][MAX];
	
	if(1==1) { // FALTA VALIDAR OQUE CHEGA NO MAIN
		printf("# Quantas frases voce quer digitar?\n");
		scanf("%i",&Qtd_strings);
	} else{
		Qtd_strings= *argv[1];
	}

	printf("# Digite %i frases com ate 20000 cars para cifrar ou decifrar.\n# Insira '$' no inicio se for para decifrar:\n",Qtd_strings); //VERIFICA EM QUAL ESTADO A STRING ESTÁ E DIRECIONA PARA A FUNÇÃO CORRESPONDENTE 
	for(i=0;i<Qtd_strings;i++){
		do{
			fgets(frases[i],MAX,stdin);
		}while(len(frases[i])<2);
	
		if (frases[i][1]!="$"){
			cifrar(frases[i]);
		}else{
			decifrar(frases[i]);
		}
	}
	system("pause");
return(0);
}



