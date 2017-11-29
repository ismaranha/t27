# t27
#include <stdio.h>
#include <string.h>
#define NUM 11
#define STRMAX 100
#define MAX 100
#define MAXTURMA 50

struct TURMA{
	char numTurma[NUM], disciplina[STRMAX], nomeProf[STRMAX];
	int qtdAluno;
	struct Aluno al[MAX];
	//al -> struct Aluno;
};
struct ALUNO{
	char numMat[NUM], nomeAluno[STRMAX];
	double g1,g2,g3;
};
int cadastraTurma(int qtdCad, struct TURMA *t){
	//struct Turma t[MAXTURMA];
	int i;

	for(i = 0; i<qtdCad;i++){
		printf("\n# --- Turma [%i] ---",i);
		
		printf("\n# Codigo da turma");
		fgets(t[i].al.numTurma,STRMAX,stdin);
		
		printf("\n# Nome da disciplina: ");
		fgets(t[i].disciplina,STRMAX,stdin);
		
		printf("\n# Nome do professor");
		fgets(t[i].nomeProf,STRMAX,stdin);
		
		printf("\n# Quantos alunos tem na turma (0 a %i)?",MAX);
		scanf("%i",&t[i].qtdAluno);
	}
}
int cadastraAluno(struct TURMA *t){
	//struct Turma t[MAX];
	int i;
	for(i = 0; i < MAX;i++){
		printf("\n# Numero de matricula: ");
		fgets(t[i].(*al[i]).numMat,STRMAX,stdin);
		
		printf("\n# Nome do aluno: ");
		fgets(t[i].al[i].nomeAluno,STRMAX,stdin);
		
		printf("\n# Nota G1: ");
		scanf("%lf",&t[i].al[i].g1);
		
		printf("\n# Nota G2: ");
		scanf("%lf",&t[i].al[i].g2);
		
		printf("\n# Nota G3: ");
		scanf("%lf",&t[i].al[i].g3);
	}
}
int main(){
	int qtdCad;
	struct TURMA *tddd;
	
	printf("#Quantas turmas voce quer cadastrar ? (1 até 50)");
	scanf("%i",&qtdCad);
	printf("\n");
	cadastraTurma(qtdCad,tddd);
}
