#include <stdio.h>
#include <string.h>
#define MAX 100

//VARIÁVEL PARA REPRESENTAR O CADASTRO DE UM ALUNO.
struct Aluno{
	char nome[100];
	float nota;
	float freq;
	char RA[10];
	char ativo;
};

int N=0; // ARMAZENA QUANTOS REGISTROS ESTÃO ATIVOS NO VETOR, OU SEJA, QUANTOS ALUNOS ESTÃO CADASTRADOS.
//VETOR DE ESTRUTURAS RESPONSÁVEL POR ARMAZENAR TODOS OS CADASTROS
struct Aluno Alunos[MAX];

//IMPRIME AS INFORMAÇÕES DE UM ALUNO EM ESPECÍFICO.
void ImprimirRegistro(int id){
	printf("\n\n=====================\n");
	if (Alunos[id].ativo && id<MAX){
		printf("\nRegistro %d\n", id+1);
		printf("\tNome: %s\n", Alunos[id].nome);
		printf("\tRA: %s\n", Alunos[id].RA);
		printf("\tNota: %.1f\n", Alunos[id].nota);
		printf("\tFrequencia: %.2f\n\n", Alunos[id].freq);
	}
	printf("\n=====================\n");
}

//RETORNA A POSIÇÃO EM QUE UM ALUNO ESTÁ CADASTRADO NO VETOR.
int BuscaRegistro(char nome[]){
	int i;
	for (i=0; i<MAX ; i++){
		// BUSCA STRINGS IGUAIS
		if (strcmp(nome,Alunos[i].nome)==0){
			// ENCONTROU IGUALDADE NA POSIÇÃO i.
			return i;
		}
	}

	// CASO NÃO ENCONTRE NADA
	return -1;
}

//GERANDO UM NOVO CADASTRO DE ALUNO
void InsereRegistro(){
	int i, pos;
	char lixo[2];

	if (N>=MAX){
		printf("Registro Cheio\n");
	}
	else {
		for (i=0 ; i<MAX ; i++){
			// BUSCA POR UMA POSIÇÃO DE CADASTRO LIVRE
			if (Alunos[i].ativo == 0) {
				pos = i;
				break;
			}
		}

		gets(lixo); // gambiarra....
		printf("Digite o nome do aluno: ");
		gets(Alunos[pos].nome);
		printf("Digite RA: ");
		gets(Alunos[pos].RA);
		printf("Digite a nota: ");
		scanf("%f", &(Alunos[pos].nota));
		printf("Digite a frequencia: ");
		scanf("%f", &(Alunos[pos].freq));
		Alunos[pos].ativo = 1;
		N++;
	}
}

//EXCLUINDO UM CADASTRO. NOTE QUE A INFORMAÇÃO AINDA FICA REGISTRADA NOS CAMPOS OCUPANDO A MEMÓRIA
//PORÉM SEU ESTADO PASSA A ESTAR DESATIVADO, INDICANDO QUE ESSES DADOS PODEM SER SOBREESCRITOS PARA GERAR UM
//NOVO CADASTRO
void RemoveRegistro(){
	char nome[100], lixo[2];
	int id, conf=0;
	gets(lixo);
	printf("Digite o nome: ");
	gets(nome);
	id = BuscaRegistro(nome);
	if (id==-1) {
		printf("\n\nRegistro inexistente\n\n");
	}
	else {
		printf("\n\n=====================\n");
		ImprimirRegistro(id);
		printf("\nConfirma Exclusao?\n");
		printf("\t[1] - SIM\n");
		printf("\t[0] - NAO\n");
		scanf("%d",&conf);
		if (conf==1){
			Alunos[id].ativo = 0;
			N--; // contagem de registros ativos
			printf("\n\nRegistro Excluido\n\n");
		}
		else{
			printf("\n\nRegistro Nao Excluido\n\n");
		}
	}

}

//IMPRIME AS INFORMAÇÕES DE UM REGISTRI EM ESPECÍFICO
void ConsultaRegistro(){
	char nome[100], lixo[2];
	int id;
	gets(lixo);
	printf("Digite o nome: ");
	gets(nome);
	id = BuscaRegistro(nome);
	if (id==-1)
		printf("\n\nRegistro inexistente\n\n");
	else
		ImprimirRegistro(id);
}

//MOSTRA QUAIS OS DADOS ATUALMENTE CADATRADOS EM UM DETERMINADO REGISTRO E PERMITE QUE ATUALIZEMOS.
void AlteraRegistro(){
	char nome[100], lixo[2];
	int id;
	gets(lixo);
	printf("Digite o nome: ");
	gets(nome);
	id = BuscaRegistro(nome);
	if (id==-1) {
		printf("\n\nRegistro inexistente\n\n");
	}
	else {
		printf("Dados Atuais: ");
		ImprimirRegistro(id);
		printf("Digite o novo nome do aluno: ");
		gets(Alunos[id].nome);
		printf("Digite o novo RA: ");
		gets(Alunos[id].RA);
		printf("Digite a nova nota: ");
		scanf("%f", &(Alunos[id].nota));
		printf("Digite a nova frequencia: ");
		scanf("%f", &(Alunos[id].freq));
	}

}

//LISTA TODOS OS REGISTROS CADASTRADOS
void ListaRegistros(){
	int i;
	printf("\n\n=====================\n");
	for (i=0 ; i<MAX ; i++){
		if (Alunos[i].ativo){
			printf("\nRegistro %d\n", i+1);
			printf("\tNome: %s\n", Alunos[i].nome);
			printf("\tRA: %s\n", Alunos[i].RA);
			printf("\tNota: %.1f\n", Alunos[i].nota);
			printf("\tFrequencia: %.2f\n\n", Alunos[i].freq);
		}
	}
	printf("\n=====================\n");
}

//APRESENTA UM MENU DE OPÇÕES DO NOSSO SISTEMINHA DE CRUD E RETORNA A OPÇÃO SELECIONADA PELO USUÁRIO.
int Menu(){
	int op;
	printf("Selecione uma opcao:\n");
	printf("\t [1] - Inserir\n");
	printf("\t [2] - Consultar\n");
	printf("\t [3] - Alterar\n");
	printf("\t [4] - Excluir\n");
	printf("\t [5] - Listar Todos\n");
	printf("\t [6] - Sair\n");
	printf("\n\tOpcao: ");
	scanf("%d", &op);
	return op;
}

int main(){
	int opcao;
	do{
		opcao = Menu();
		switch(opcao){
			case 1: InsereRegistro(); break;
			case 2: ConsultaRegistro(); break;
			case 3: AlteraRegistro(); break;
			case 4: RemoveRegistro(); break;
			case 5: ListaRegistros(); break;
		}
	} while (opcao != 6);
}


