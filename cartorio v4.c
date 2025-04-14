#include <stdio.h> //comunica��o com o usu�rio
#include <stdlib.h> //alocar espa�o de mem�ria
#include <locale.h> //alo��es de texto por regi�o
#include <string.h> //biblioteca das strings hehe

//fun��o de registro
int registro(){
	
	setlocale(LC_ALL, "Portuguese");
	
//variaveis
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
//inserir cpf
	printf("Insira o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); //copiar o dado da string
	
	FILE *file; //criando o arquivo
	file = fopen(arquivo, "w"); //criando o arquivo (w, de write)
	fprintf(file,cpf);
	fclose(file);
	
	//inserindo a virgula
	file = fopen(arquivo, "a"); //editando o arquivo (a, de atualiza��o)
	fprintf(file, ",");
	fclose(file);
	
//inserir nome
	printf("Insira o nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	//inserindo a v�rgula
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
//inserir o sobrenome
	printf("Insira o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	//inserindo a virgula
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
//inserindo o cargo
	printf("Insira o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

//fun��o para consultar
int consulta(){
	
	setlocale(LC_ALL, "Portuguese");
	
//variaveis
	char cpf [40];
	char conteudo [200];
	
//consultando o cpf
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //abrindo o arquivo
	file = fopen (cpf, "r"); //fun��o para ler o arquivo cpf (r, de read)
	
	
	//caso n�o seja poss�vel abrir
	if (file == NULL){
		printf("N�o foi poss�vel abrir\nArquivo n�o localizado....\n");
	}
	
	//vaida��o do enquanto
	while (fgets(conteudo, 200, file) != NULL){
		
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	
	system("pause");
	
}

//fun��o para deletar
int deletar (){
	
	char cpf [40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	//consultar
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL) {
		printf ("Usu�rio n�o encontrado no sistema!. \n");
		
	}
	else{
		printf ("Usu�rio deletado com sucesso!! \n");
	}
	
	remove(cpf);
	
	system ("pause");
	
}

//fun��o principal do c�digo
int main(){
	
	//vari�veis
	int menu = 0;
	int repeticao = 1;
	
	for(repeticao = 1; repeticao = 1;){
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //informando ao computador o idioma portugu�s (p/ aceitar acentos)
	
	
		printf("-*-*-*-*-* Cart�rio da EBAC *-*-*-*-*-\n\n");
		printf("Escolha a op��o desejada do menu:\n\n"); //inserindo a parte "gr�fica" do menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-\n\n");
		printf("Op��o: ");
	
		scanf("%d", &menu); //armazena a escolha feita 
	
		system("cls"); //comando para "limpar" a tela do cmd ap�s a escolha

		//com base na op��o armazenada, retorna a desejada	
		switch(menu){
			case 1:
				registro();
				printf("O indiv�duo foi registrado!!!");
				break;
			
			case 2: 
				consulta();
				break;
			
			case 3:
				deletar();
				break;
			
			//minimizando os poss�veis erros
			default: 
				printf("OPS!!\nOp��O InV�LiDa, TeNtE NoVaMeNtE!\n");
				system("pause");
				break;
		}
	printf("\n\nEsse Software � de uso livre");
	
	}
	
	
	

}

