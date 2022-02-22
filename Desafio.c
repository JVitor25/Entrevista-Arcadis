#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string.h>
//Desenvolvido por Joao Vitor Silva Lima
/* ALgoritmo desenvolvido no compilador Dev-C++*/

/*Declearando as structs dos Pontos, Parâmetros
 e Tabela disponibilizada no .PDF*/
typedef struct{
	char nome_parametro [256];
	float valor_parametro;
	int data_coleta[10];
	char situacao[15];
}dados_parametro;

typedef struct{
	dados_parametro parametro[999];
	char nome_ponto [256];
	int coordenada[2];
	int quantidade_de_parametros_do_ponto;
} dados_ponto;	

typedef struct{
	char nome_p [256];
	char unidade_p[256];
	float limite_aceitavel;
}parametros_tabela;

/* Declarando algumas variaveis globais, sendo elas:
a Struct dos Pontos (aninhada com a dos Parâmetros),
Struct da Tabela, e "i" sendo o contador geral da
quantidade de pontos.*/
dados_ponto dados[100];
parametros_tabela tabela[100];
int i=0;

/*Função void responsável para printar o menu principal
do usuário.*/
void menu_de_opcao (){
	printf("Escolha uma opcao do menu de interface:");
	printf("\n[1] - Cadastro de Pontos;");
	printf("\n[2] - Cadastro de Parametros;");
	printf("\n[3] - Pesquisar pontos;");
	printf("\n[4] - Pesquisar Parametro;");
	printf("\n[5] - Visualizar os pontos que violaram a legislacao;");
	printf("\n[6] - Listar Todos;\n");
	printf("\n[0] - Sair do Programa.\n_____________________");
}

//Preechendo a Struct da tabela com os dados disponibilziados.
void tabela_da_legislacao(){
	strcpy(tabela[1].nome_p,"Aluminio dissolvido");
	strcpy(tabela[1].unidade_p,"mg/l");
	tabela[1].limite_aceitavel = 0.1;
	
	strcpy(tabela[2].nome_p,"Arsenio total");
	strcpy(tabela[2].unidade_p,"mg/l");
	tabela[2].limite_aceitavel = 0.01;
	
	strcpy(tabela[3].nome_p,"Chumbo total");
	strcpy(tabela[3].unidade_p,"mg/l");
	tabela[3].limite_aceitavel = 0.01;
	
	strcpy(tabela[4].nome_p,"Cobre dissolvido");
	strcpy(tabela[4].unidade_p,"mg/l");
	tabela[4].limite_aceitavel = 0.009;
	
	strcpy(tabela[5].nome_p,"Escherichia coli");
	strcpy(tabela[5].unidade_p,"NPM/100ml");
	tabela[5].limite_aceitavel = 1000;
	
	strcpy(tabela[6].nome_p,"Cromo total");
	strcpy(tabela[6].unidade_p,"mg/l");
	tabela[6].limite_aceitavel = 0.05;
	
	strcpy(tabela[7].nome_p,"Cadmio totla");
	strcpy(tabela[7].unidade_p,"mg/l");
	tabela[7].limite_aceitavel = 0.001;
	
	strcpy(tabela[8].nome_p,"DBO");
	strcpy(tabela[8].unidade_p,"mg O2/l");
	tabela[8].limite_aceitavel = 5;
}

/*Função void responsável por limpar a tela nos Sistemas 
Operacionais Windows (32bits e 64bits) e Linux.*/
void limpar(){
	//sleep(1);
	#ifdef _WIN32
	    system("cls");
	    
	#elif _linux_
	    system("clear");
	    
	#endif	
}

/*Função void responsável para limpar o buffer da variável char
utilizada.*/
void limpaBuffer(){
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}

/*Função void responsável por printar todo dado existente imputados.
Exceto, quando não houver dados imputados (retornando a devida 
reposta para o usuário). Sequência de for e if (com ou sem srtcmp) 
utilizados para formatar (visualmente) os dados de saída.*/
void opcao_6(){
	int j,k,x,z=0;
	
	if(i==0){
		printf("\nNenhum dado foi cadastrado. Voltando para o menu principal\n...\n\n");
		system("pause");
		limpar();
	}else{
	
	printf("\nListagem completa. \n\n=====================\n");
	for(j=1;j<=i;j++){
		printf("Ponto [%i]\nNome: %s\t Coordenada: (%i,%i)\n",j,dados[j].nome_ponto, dados[j].coordenada[0], dados[j].coordenada[1]);
		for(k=1;k<=dados[j].quantidade_de_parametros_do_ponto;k++){
			printf("\t%s\t%.3f",dados[j].parametro[k].nome_parametro,dados[j].parametro[k].valor_parametro);
			for(z=1;z<=8;z++){
				if(strcmp(dados[j].parametro[k].nome_parametro, tabela[z].nome_p) == 0)
					x=z;
			}
			printf("(%s)\tdata:%s \n",tabela[x].unidade_p, dados[j].parametro[k].data_coleta);
		}
		z=0;
		printf("\n\n");
	}
	system ("pause");
	limpar();
	}
}

/*Função void responsável por printar os parâmetros que estirem indo 
contra a legislação vigente. Exceto, quando não houver dados/parâmetros
imputados(retornando a devida reposta para o usuário), ou o usuário 
prescionar '0'. Sequência de for e if (com ou sem srtcmp) utilizados 
para formatar (visualmente) os dados de saída.*/
void opcao_5(){
	int a,y,j,k,x,g,h,s,z=0,r=0;	
	a=0;
			
	for(j=1;j<=i;j++){
		if(dados[j].quantidade_de_parametros_do_ponto>0)
			a++;		
	}

	if(i==0){
		printf("\nNenhum dado foi cadastrado. Voltando para o menu principal\n...\n\n");
		system("pause");
		limpar();

	}else if(a==0){
		printf("\nNenhum parametro foi cadastrado. Voltando para o menu principal\n...\n\n");
		system("pause");
		limpar();
	}else{
	a=0;
	printf("\nListagem de pontos que violam a legislacao. \n\n=====================\n");
	
	for(j=1;j<=i;j++){
		g=0;
		h=0;
		for(y=0;y<=dados[j].quantidade_de_parametros_do_ponto;y++){
			if(strcmp(dados[j].parametro[y].situacao, "reprovado") == 0)
			g++;
		}
		for(k=1;k<=dados[j].quantidade_de_parametros_do_ponto;k++){
			if(strcmp(dados[j].parametro[k].situacao, "reprovado") == 0){
				h++;
				if(r!=j){
					printf("Ponto [%i]\nNome: %s\t Coordenada: (%i,%i)\n",j,dados[j].nome_ponto,dados[j].coordenada[0],dados[j].coordenada[1]);
					r=j;
				}
				printf("\t%s\t%.3f",dados[j].parametro[k].nome_parametro,dados[j].parametro[k].valor_parametro);
				for(z=1;z<=8;z++){
					if(strcmp(dados[j].parametro[k].nome_parametro, tabela[z].nome_p) == 0)
						x=z;
				}
				printf("(%s) -- Concentracao acima do permitido.\n",tabela[x].unidade_p,dados[j].parametro[k].data_coleta);
				a++;
				
				if(h==g)
					printf("\n\n");	
			}	
		}

		z=0;
	}
	if(a==0)
		printf("Nenhum parametro esta violando a legislacao.\n\n\n");
	system ("pause");
	limpar();
	}
}

/*Função void responsável por printar parâmetros filtrados pela busca por
nome. Exceto quando não houver parâmetros imputados(retornando a devida 
reposta para o usuário), ou o usuário prescionar '0'. Sequência de for e 
if (com ou sem srtcmp) utilizados para formatar (visualmente) os dados de saída.*/
void opcao_4(){
	int qnt_total_de_parametros_geral,y,a=0,j,k,x,n,g,h,z=0;
	char parametro_pesquisado[256];
	y=0;
	
	for(j=1;j<=i;j++){
		if(dados[j].quantidade_de_parametros_do_ponto>0)
			y++;		
	}
	
	if(y==0){
		printf("\nNenhum parametro foi cadastrado. Voltando para o menu principal\n...\n\n");
		system("pause");
		limpar();
	}else{
		printf("\nPesquisa de parametros.");
		printf("\nInsira o nome do parametro que deseja pesquisar.\n");
		printf("\n[0] - Voltar para o menu principal.");
		printf("\n_____________________\nEscolha --> ");
		scanf("\n%[^\n]",parametro_pesquisado);
	
		if(strcmp(parametro_pesquisado, "0") != 0){
			for(n=1;n<=8;n++){
			if(strcmp(parametro_pesquisado, tabela[n].nome_p) == 0)
				x=n;
			}
			printf("\n=====================\nParametro pesquisado:\n\n");
			for(j=1;j<=i;j++){
				g=0;
				h=0;
				for(y=0;y<=dados[j].quantidade_de_parametros_do_ponto;y++){
					if(strcmp(parametro_pesquisado, dados[j].parametro[y].nome_parametro) == 0)
					g++;
				}
				for(k=1;k<=dados[j].quantidade_de_parametros_do_ponto;k++){
					if(strcmp(parametro_pesquisado, dados[j].parametro[k].nome_parametro) == 0){
						h++;
						a++;
						if(z!=j){
							printf("Ponto %i --> Nome: %s\t Coordenada: (%i,%i)\n",j,dados[j].nome_ponto,dados[j].coordenada[1],dados[j].coordenada[2]);
							z=j;
						}
						printf("\t%s\t%.3f(%s)\tdata:(%s)\n",dados[j].parametro[k].nome_parametro,dados[j].parametro[k].valor_parametro,tabela[x].unidade_p,dados[j].parametro[k].data_coleta);
						
						if(h==g)
							printf("\n\n");				
					}	
				}
				
				z=0;
			}
			if(a==0){
				printf("*Nenhum parametro encontrado com a informacao imputada*.\n...\n\n\n");
			}
			system ("pause");
			limpar();
		}else{
			limpar();
			
		}	
	}
}

/*Função void responsável por printar parâmetros filtrados pela busca por
nome. Exceto quando não houver pontos imputados(retornando a devida 
reposta para o usuário), ou o usuário prescionar '0'. Sequência de for 
e if (com ou sem srtcmp) utilizados para formatar (visualmente) os dados 
de saída.*/
void opcao_3(){
	int j,z,k,x,y=0;
	char ponto_pesquisado[256];
	
	if(i==0){
		printf("\nNenhum ponto foi cadastrado. Voltando para o menu principal\n...\n\n");
		system("pause");
		limpar();
		
	}else{
		printf("\nPesquisa de pontos.");
		printf("\nInsira o nome do ponto que deseja pesquisar:.\n");
		printf("\n[0] - Voltar para o menu principal.");
		printf("\n_________\n-->");
		
		scanf("\n%[^\n]",ponto_pesquisado);
		
		if(strcmp(ponto_pesquisado, "0") != 0){
			printf("\n=====================\nPonto pesquisado:");
			for(j=1;j<=i;j++){
				
				if(strcmp(ponto_pesquisado, dados[j].nome_ponto) == 0){
					y++;
					printf("\n\nPonto [%i]\nNome: %s\t Coordenada: (%i,%i)\n",j,dados[j].nome_ponto,dados[j].coordenada[1],dados[j].coordenada[2]);
					for(k=1;k<=dados[j].quantidade_de_parametros_do_ponto;k++){
						printf("\t%s\t%.3f",dados[j].parametro[k].nome_parametro,dados[j].parametro[k].valor_parametro);
						for(z=1;z<=8;z++){
							if(strcmp(dados[j].parametro[k].nome_parametro, tabela[z].nome_p) == 0)
								x=z;
						}
						printf("(%s)\tdata:%s\n",tabela[x].unidade_p, dados[j].parametro[k].data_coleta);
					}
				}
			}
			if(y==0){
				printf("\n\n*Nenhum ponto encontrado com a informacao imputada*.\n...\n");
			}
			printf("\n\n");
			system ("pause");
			limpar();
			
		}else{
			limpar();	
		}
	}
}

/*Função void responsável por conferir se o parâmetro imputado está contido 
no banco de dados (tabela disponibilizada), e fazer o prenchimento adequando 
das structs parâmetros e pontos (aninhadas). Está função está muito 
correlacionada com a função void 'opcao_2' estrututura mais abaixo. Preenchimento 
como: unidade de medida adequada, o próprio parâmetro, o grau de concentração, 
a data da coleta e a contagem de parâmetro do ponto cadastrado (tal recurso foi 
muito utilizado para limitar alguns dos comandos de repetição utilizados.*/
void conferir_tabela(int ponto_associado){
	int j,k,aux=0,g=0;
	char parametro_analisado[256];
	printf("Lista dos parametros salvos no banco de dados\n_________");
	for(j=1;j<=8;j++){
		printf("\n* %s",tabela[j].nome_p);
	}
	dados[ponto_associado].quantidade_de_parametros_do_ponto++;	
	g = dados[ponto_associado].quantidade_de_parametros_do_ponto;
	
	do{
		printf("\n_________\n\nInforme o nome do parametro: ");	
		scanf("\n%[^\n]", dados[ponto_associado].parametro[g].nome_parametro);	
		for(j=1;j<=8;j++){
			if(strcmp(dados[ponto_associado].parametro[g].nome_parametro, tabela[j].nome_p) == 0){
				aux=1;
				printf("Insira os valores (em %s): ", tabela[j].unidade_p);
				scanf("%f",&dados[ponto_associado].parametro[g].valor_parametro);
				k=j;
				j=8;
				if(dados[ponto_associado].parametro[g].valor_parametro> tabela[k].limite_aceitavel){
					strcpy(dados[ponto_associado].parametro[g].situacao, "reprovado");
				}else{
					strcpy(dados[ponto_associado].parametro[g].situacao,"aprovado");
				}
			}	
		}
		if(aux!=1)
			printf("\n\nParametro informado nao existe na lista.\nPor favor, insira um parametro existente.");	
	}while(aux !=1);
	
	printf("Insira a data de acordo com o seguinte modelo '01/01/2022'");
	printf("\ndata: ");
	scanf("%s", dados[ponto_associado].parametro[g].data_coleta);
	limpar();
}

/*Função void reponsável pelo cadastro dos pontos. Cadastro como: nome do ponto 
e suas coordenadas. Barrando o cadastro de pontos com os mesmos nomes, ou as 
mesmas coordenadas*/
void opcao_1 (){
	int j,z=0;
	i++;
	printf("\nCadastrando o Ponto %i\n", i);
	printf("Insira o nome: ");
	scanf("\n%[^\n]",dados[i].nome_ponto);
	
	if(i!=1){
		for(j=1;j<i;j++){
			if(strcmp(dados[i].nome_ponto,dados[j].nome_ponto) == 0)
				z=1;		
		}
		
	}
	if(z==1){
		printf("\n=====================\nNao eh posssivel cadastrar o mesmo ponto duas vezes. \nJa existe um ponto cadastrado com esse nome.\n\nVoltando para o menu principal\n...\n\n");
				i--;
				system("pause");
				limpar();
				
	}else{		
	printf("Insira as coordenadas X,Y\n");
	printf("X: ");
	scanf("%i",&dados[i].coordenada[0]);
	printf("Y: ");
	scanf("%i",&dados[i].coordenada[1]);
	
	z=0;
	if(i!=1){
		for(j=1;j<i;j++){
			if((dados[i].coordenada[0]==dados[j].coordenada[0]) && (dados[i].coordenada[1]==dados[j].coordenada[1]))
				z=1;		
		}
	}
	if(z==1){
		printf("\n=====================\nNao eh posssivel cadastrar o mesmo ponto duas vezes. \nJa existe um ponto cadastrado com essas coordenadas.\n\nVoltando para o menu principal\n...\n\n");
				i--;
				system("pause");
				limpar();
				
	}else{
		
	dados[i].quantidade_de_parametros_do_ponto = 0;
	limpar();
	}
	}
}

/*Função void responvável por fazer o direcionamento dos parâmetros aos seus 
devidos pontos (em coordenação com a função 'conferir_tabela'. Assim como 
também, verifica se existe algum ponto cadastrado antes de cadastrar o primeiro 
parametro. Cajo não haja, ela reedireciona o usuario para o cadastramento de 
pontos (chmando a função void 'opcao_1' '*/
void opcao_2 (){
	int ponto_associado, j,k;
	if(i==0){
		printf("\nNenhum ponto ainda informado. Por favor, cadastre o primeiro ponto.\n...\n\n ");
		opcao_1();
	}
	printf("\nEste Parametro esta associado a qual ponto?\n\n", i);

	for(j=1;j<=i;j++){
		printf("Ponto [%i]\nNome: %s\t Coordenada: (%i,%i)\n\n",j,dados[j].nome_ponto, dados[j].coordenada[0], dados[j].coordenada[1]);
	}
	
	printf("[0] - Corresponde a nenhum ponto. Voltar para o menu principal.\n");
	printf("_____________________\nEscolha --> ");
	scanf("%i",&ponto_associado);
	
	if(ponto_associado != 0){
		limpar();
		tabela_da_legislacao();
		conferir_tabela(ponto_associado);	
	}else{
		limpar();
	}
}

/*Função inteira responvável por chamar a maior parte das funções anteriormente 
citadas, atraváves da seleção do usuário. Retornadno um valor para a função int 
'main'. Este valor é responsável por garantir que o código ainda continue rodando 
caso haja um preenchimento incoerente do menu principal*/
int exec_menu (){
	int x;
	char opcao;
	menu_de_opcao();
	printf("\nEscolha --> ");
	scanf("\n%c", &opcao);
	limpaBuffer();
	
	switch(opcao){
		case '1': 	
			limpar();
			printf("_____________________\nOpcao 1 selecionada\n_____________________");
			opcao_1();
			break;
		case '2': 
			limpar();
			printf("_____________________\nOpcao 2 selecionada\n_____________________");
			opcao_2();
			break;
		case '3': 
			limpar();
			printf("_____________________\nOpcao 3 selecionada\n_____________________");
			opcao_3();
			break;
		case '4': 
			limpar();
			printf("_____________________\nOpcao 4 selecionada\n_____________________");
			opcao_4();
			break;
		case '5': 
			limpar();
			printf("_____________________\nOpcao 5 selecionada\n_____________________");
			opcao_5();
			break;
		case '6': 
			limpar();
			printf("_____________________\nOpcao 6 selecionada\n_____________________");
			opcao_6();
			break;
		case '0': 
			limpar();
			printf("_____________________\nEncerrado...\n_____________________\n");
			x = 0;
			return 1;
		default : 
			limpar();
			printf("_____________________\nOpcao nao identificada. \nPor favor, insira uma opcao valida.\n_____________________\n\n");
	}
	return x;
}

int main(){
	int x;
	do{
		x = exec_menu();
	}while(x == 0);
	
	return 0;
  }
