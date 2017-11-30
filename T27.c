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
	//char fnumTurma[NUM];
	int i;
    int quantidadeAlunos;
    
	for(i = 0; i<qtdCad;i++){
	    
		printf("\n# --- Turma [%i] --- ",i);
		
		printf("\n# Codigo da turma: ");
		do{
		    fgets(t[i].numTurma,STRMAX,stdin);
		}while(strlen(t[i].numTurma)<3);
		 
		//strcpy ( fnumTurma, t[i].numTurma);

		printf("\n# Nome da disciplina: ");
		fgets(t[i].disciplina,STRMAX,stdin);
		
		printf("\n# Nome do professor");
		fgets(t[i].nomeProf,STRMAX,stdin);
		do{
			printf("\n# Quantos alunos tem na turma (0 a %i) ? ",MAX);
			scanf("%i",&t[i].qtdAluno);
			quantidadeAlunos = t[i].qtdAluno;
		}while(quantidadeAlunos > MAX);
		
		cadastraAluno(t,i,quantidadeAlunos);//vai cadastrar todos os alunos da turma, e depois pula pra próxima turma      
	}
}
int cadastraAluno(struct TURMA *t, int n, int qtdAluno){
	
	int i;
	 
	double fg1,fg2,fg3, m1, m2,media,mediaFinal;
	for(i = 0; i < qtdAluno;i++){
	    
	    //printf("# ------- ALUNO [%i] da turma %i ",i, numeroTurma);
		printf("\n# Numero de matricula do ALUNO: ");
		    do{
		        fgets(t[i].al[n].numMat,STRMAX,stdin);
            }while(strlen(t[i].al[n].numMat)<3);
        
		printf("\n# Nome do aluno: ");
		    do{
	        	fgets(t[i].al[n].nomeAluno,STRMAX,stdin);
	    	}while(strlen(t[i].al[n].nomeAluno)<3);
		
		printf("\n# Nota G1: ");
		scanf("%lf",&t[i].al[n].g1);
		fg1 = t[i].al[n].g1;
		
		printf("\n# Nota G2: ");
		scanf("%lf",&t[i].al[n].g2);
		fg2 = t[i].al[n].g2;
		
		media = (fg1 + (2* fg2))/3.0;
		
		if(media < 6.0){
			printf("\n# Nota G3: ");
			scanf("%lf",&t[i].al[n].g3);
			fg3 = t[i].al[n].g3;
			
			m1 = (fg3 + (2*fg2)) /3.0; 
			m2 = (fg1 + (2*fg3)) /3.0;
			if(m1>m2){
			    mediaFinal = m1;
			}else{
			    mediaFinal = m2;
			}
		}else{
		    fg3=0.0;
		    mediaFinal = media;// se n fizer g3, a media final sera a propria media 
		}
		
	}
}
int main(){
	int qtdCad;
	do{
	printf("#Quantas turmas voce quer cadastrar ? (1 até %i)",MAXTURMA);
	scanf("%i",&qtdCad);
	}while(qtdCad > MAXTURMA);
	
	cadastraTurma(qtdCad);
	
}
