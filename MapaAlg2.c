#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Variaveis globais
char nome[200];
char cpf[200];
char sexo[2];
int idade;
int main();

struct elemento {
	char pergunta[256];
	int pontuacao;	
};

struct elemento questoes[] = {
	{ .pergunta = "Tem febre: ", .pontuacao = 5 },
	{ .pergunta = "Tem dor de cabeça: ", .pontuacao = 1 },
	{ .pergunta = "Tem secreção nasal ou espirros: ", .pontuacao = 1 },
	{ .pergunta = "Tem dor/irritação na garganta: ", .pontuacao = 1 },
	{ .pergunta = "Tem tosse seca: ", .pontuacao = 3 },
	{ .pergunta = "Tem dificuldades respiratórias: ", .pontuacao = 10 },
	{ .pergunta = "Tem dores no corpo: ", .pontuacao = 1 },
	{ .pergunta = "Tem diarréia: ", .pontuacao = 1 },
	{ .pergunta = "Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19: ", .pontuacao = 10 },
	{ .pergunta = "Esteve em locais com grande aglomeração: ", .pontuacao = 3 },
	
};

void perguntas() {
	
	setlocale(LC_ALL, "portuguese");
	
	char res;
	int soma = 0;
	int i = 0;
	
	setlocale(LC_ALL, "portuguese");
	
	FILE *arquivoTxt;
	arquivoTxt = fopen("dataBase.txt", "a");
	
	if (arquivoTxt==NULL) 
	{
		printf (" Erro ao criar o arquivo");
	}
	
	system("cls");
	printf ("Responda as perguntas abaixo com S(sim) ou N(não)\n");
	printf ("--------------------------------------------------\n");
	for (i = 0; i < 10; i ++){
		printf ("%s", questoes[i].pergunta);
		scanf ("%c", &res);
		fflush(stdin);
		fprintf(arquivoTxt, "%s: %c\n", questoes[i].pergunta, res);
		if (res == 'S' || res == 's'){
			soma = soma + questoes[i].pontuacao;
		}
		
	}
	fprintf(arquivoTxt, "Pontuação total: %d", soma);
	fclose(arquivoTxt);
	
	system("cls");
	if (soma >= 0 && soma < 10) {
		printf ("Você somou %d pontos e deve se encaminhar para a ala de Baixo Risco\n", soma);	
	}
	if (soma >= 10 && soma < 20) {
		printf ("Você somou %d pontos e deve se encaminhar para a ala de Médio Risco\n", soma);	
	}
	if (soma >= 20) {
		printf ("Você somou %d pontos e deve se encaminhar para a ala de Alto Risco\n", soma);	
	}
	soma = 0;
	
	printf ("Pressione ENTER para voltar ao Menu Principal...");
	getchar();
	main();
}


void cadastrarPaciente() {
	
	setlocale(LC_ALL, "portuguese");
	
	FILE *arquivoTxt;
	arquivoTxt = fopen("dataBase.txt", "a");
	
	if (arquivoTxt==NULL) 
	{
		printf (" Erro ao criar o arquivo");
	}
	
	
	printf ("\nInforme o nome do paciente: ");
	scanf ("%s", nome);
	fflush(stdin);
	
	printf ("\nInforme o CPF do paciente: ");
	scanf ("%s", cpf);
	fflush(stdin);
	
	printf ("\nInforme o Sexo do paciente (M/F): ");
	scanf ("%s", sexo);
	fflush(stdin);
	
	printf ("\nInforme a idade do paciente: ");
	scanf ("%d", &idade);
	fflush(stdin);
	
	fprintf (arquivoTxt, "Nome: %s\nCPF: %s\nSexo: %s\nIdade: %d\n", nome, cpf, sexo, idade);
	fclose(arquivoTxt);
	
	printf ("Dados gravados com sucesso\n");
	getchar();
	perguntas();

}






int main() {
	
	setlocale(LC_ALL, "portuguese");
	
	int opcao;
	
	printf ("----------------MENU---------------- \n");
	printf ("1 - Cadastrar Paciente \n");
	printf ("0 - Sair \n");
	printf ("Por favor, selecione uma opção:\n--> ");
	scanf ("%i", &opcao);
	fflush(stdin);
	
	switch(opcao){
		case 0:
			printf ("\n Finalizando o programa...");		
			break;
		case 1:
			cadastrarPaciente();
			break;
		default:
			break;
	}
	
}

