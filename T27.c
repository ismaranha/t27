#include <stdio.h>
#include <string.h>
#define NUM 11
#define STRMAX 100
#define MAX 100
#define MAXTURMA 50

struct ALUNO{
	char numMat[NUM], nomeAluno[STRMAX];
	double g1,g2,g3;
};
struct TURMA{
	char numTurma[NUM], disciplina[STRMAX], nomeProf[STRMAX];
	int qtdAluno;
	struct ALUNO al[MAX];

};

int cadastraTurma(int qtdCad){
	struct TURMA t[MAXTURMA];
	int i;

	for(i = 0; i<qtdCad;i++){
	    
		printf("\n# --- Turma [%i] --- ",i);
		
		printf("\n# Codigo da turma: ");
		do{
		    fgets(t[i].numTurma,STRMAX,stdin);
		}while(strlen(t[i].numTurma)<3);
		printf("\n# Nome da disciplina: ");
		fgets(t[i].disciplina,STRMAX,stdin);
		
		printf("\n# Nome do professor");
		fgets(t[i].nomeProf,STRMAX,stdin);
		
		printf("\n# Quantos alunos tem na turma (0 a %i)?",MAX);
		scanf("%i",&t[i].qtdAluno);
		
		cadastraAluno(t,i);
	}
}
int cadastraAluno(struct TURMA *t, int n){
	
	int i;
	
	for(i = 0; i < MAX;i++){
		printf("\n# Numero de matricula: ");
		    do{
		        fgets(t[i].al[n].numMat,STRMAX,stdin);
	        }while(strlen(t[i].al[n].numMat)<3);
	        
		printf("\n# Nome do aluno: ");
		    do{
	        	fgets(t[i].al[n].nomeAluno,STRMAX,stdin);
	    	}while(strlen(t[i].al[n].nomeAluno)<3);
		
		printf("\n# Nota G1: ");
		scanf("%lf",&t[i].al[n].g1);
		
		printf("\n# Nota G2: ");
		scanf("%lf",&t[i].al[n].g2);
		
		printf("\n# Nota G3: ");
		scanf("%lf",&t[i].al[n].g3);
	}
}
int main(){
	int qtdCad;
	
	printf("#Quantas turmas voce quer cadastrar ? (1 até 50)");
	scanf("%i",&qtdCad);
	
	cadastraTurma(qtdCad);
	
}
