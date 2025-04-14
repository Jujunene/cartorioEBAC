#include <stdio.h> //comunicação com o usuário
#include <stdlib.h> //alocar espaço de memória
#include <locale.h> //aloções de texto por região
#include <string.h> //biblioteca das strings hehe

//função de registro
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
	file = fopen(arquivo, "a"); //editando o arquivo (a, de atualização)
	fprintf(file, ",");
	fclose(file);
	
//inserir nome
	printf("Insira o nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	//inserindo a vírgula
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

//função para consultar
int consulta(){
	
	setlocale(LC_ALL, "Portuguese");
	
//variaveis
	char cpf [40];
	char conteudo [200];
	
//consultando o cpf
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //abrindo o arquivo
	file = fopen (cpf, "r"); //função para ler o arquivo cpf (r, de read)
	
	
	//caso não seja possível abrir
	if (file == NULL){
		printf("Não foi possível abrir\nArquivo não localizado....\n");
	}
	
	//vaidação do enquanto
	while (fgets(conteudo, 200, file) != NULL){
		
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	
	system("pause");
	
}

//função para deletar
int deletar (){
	
	char cpf [40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	//consultar
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL) {
		printf ("Usuário não encontrado no sistema!. \n");
		
	}
	else{
		printf ("Usuário deletado com sucesso!! \n");
	}
	
	remove(cpf);
	
	system ("pause");
	
}

//função principal do código
int main(){
	
	//variáveis
	int menu = 0;
	int repeticao = 1;
	
	for(repeticao = 1; repeticao = 1;){
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //informando ao computador o idioma português (p/ aceitar acentos)
	
	
		printf("-*-*-*-*-* Cartório da EBAC *-*-*-*-*-\n\n");
		printf("Escolha a opção desejada do menu:\n\n"); //inserindo a parte "gráfica" do menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-\n\n");
		printf("Opção: ");
	
		scanf("%d", &menu); //armazena a escolha feita 
	
		system("cls"); //comando para "limpar" a tela do cmd após a escolha

		//com base na opção armazenada, retorna a desejada	
		switch(menu){
			case 1:
				registro();
				printf("O indivíduo foi registrado!!!");
				break;
			
			case 2: 
				consulta();
				break;
			
			case 3:
				deletar();
				break;
			
			//minimizando os possíveis erros
			default: 
				printf("OPS!!\nOpÇãO InVáLiDa, TeNtE NoVaMeNtE!\n");
				system("pause");
				break;
		}
	printf("\n\nEsse Software é de uso livre");
	
	}
	
	
	

}

