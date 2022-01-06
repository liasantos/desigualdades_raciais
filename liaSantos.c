#include "lib.h"

// ****** D A D O S ******

// ~~~~~~ distribuicao ~~~~~~

int distribPopBrasil = 207853;

int populacaoNorte = 17871; 
int populacaoNordeste = 56618;
int populacaoSudeste = 87691;
int populacaoSuL = 29710;
int populacaoCentroOeste = 15964;

float popNorteBranca = 19.3;
float popNordesteBranca = 24.6;
float popSudesteBranca = 50.7;
float popSulBranca = 73.9;
float popCOBranca = 36.5;

float popNortePretaEParda = 78.9;
float popNordestePretaEParda = 74.5;
float popSudestePretaEParda = 48.2;
float popSulPretaEParda = 25.4;
float popCOPretaEParda = 62.2;

float popNorteAmarelaEIndigena = 1.8;
float popNordesteAmarelaEIndigena = 0.8;
float popSudesteAmarelaEIndigena = 1.1;
float popSulAmarelaEIndigena = 0.7;
float popCOAmarelaEIndigena = 1.3;

// ~~~~~~ trabalho ~~~~~~

float desempregoBrasil = 12.0;
float desempregoBrancas = 9.5;
float desempregoPretas = 14.1;

int empregoBrasil = 92333;
float empregoBrancas =  45.2;
float empregoPretas= 53.7;

int cargoLiderBrasil = 3035;
float cargoLiderBrancasBrasil = 68.6;
float cargoLiderPretasBrasil = 29.9;

//~~~~~~ outros dados ~~~~~~
char tituloDistr[30]="Distribuicao da populacao ";
char geral[15]="no Brasil ";
char cor[10]="por cor";
char regiao[15]="por Regiao";
char e[5]=" e ";

char uf_rendimentos[20]={"uf_rendimentos.txt"};
char total_brasileiros[25]={"total_brasileiros.txt"};
char total_brasileiros_cor[30]={"total_brasileiros_cor.txt"};
char total_brasileiros_uf_cor[30]={"total_brasileiros_uf_cor.txt"};

// ****** F U N C O E S  de  I M P R E S S A O ******

void imprimeArquivo(char endereco[]){
	char c;
	FILE *arquivo;
	arquivo = fopen(endereco, "r");
	if(arquivo == NULL){
		printf("\nErro na leitura do arquivo\n");
	}
	while((c=fgetc(arquivo))!=EOF){
        printf("%c",c);
    }
    fclose(arquivo);
}

void limpaString(char string[]){
	int i=0;
	for(i=0;i<strlen(string);i++){
    	string[i] = 0;
	}
}

void limpaVetor(int vetor[]){
	int i;
	for(i=0; i<5; i++){
		vetor[i]=0;
	}
}

void maiusculas(char minusculas[]){
	int i, tam;
    tam = strlen(minusculas);
    for(i=0; i<tam; i++){
		minusculas[i] = toupper (minusculas[i]);
	}
}

void limpaTela(){
	system("cls");
}

// ****** F U N C O E S  do  M E N U ******

void menuPrincipal(){
	
	printf("\n  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Menu Principal ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	printf("  ²                                                        ³\n");
	printf("  ³             1- Distribuicao da populacao               ³\n");
	printf("  ³             2- Trabalho e Renda                        ³\n");
	printf("  ³             3- Saneamento Basico                       ³\n");	
	printf("  ³                                                        ³\n");
	printf("  ³             0- Sair                                    ³\n");
	printf("  ³                                                        ²\n");
	printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
	
}

void selectMenu(){
	int select;
	scanf("%d", &select);
	switch(select){
		case 0: 
			break;
		case 1:
			limpaTela();
			distribuicao();
			break;
		case 2:
			limpaTela();
			trabalho();
			break;
		case 3:
			limpaTela();
			saneamento();
			break;
		default:
			limpaTela(); 
			printf("\n       Selecione uma opcao valida ou digite 0 para sair\n");
			printf("  À                                                        Ù\n");
			menuPrincipal();
			selectMenu();
		}
}

void subMenu(){
	
	printf("\n  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ O que gostaria de fazer ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	printf("  ²                                                        ³\n");
	printf("  ³             1- Ver dados                               ³\n");
	printf("  ³             2- Ver comparacoes                         ³\n");	
	printf("  ³                                                        ³\n");
	printf("  ³             0- Voltar ao menu principal                ³\n");
	printf("  ³                                                        ²\n");
	printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
	

}

int selectSubMenu(){
	int select;
	scanf("%d", &select);
	switch(select){
		case 0:
			limpaTela();
			menuPrincipal();
			selectMenu();
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		default:
			limpaTela();
			printf("\n       Selecione uma opcao valida ou digite 0 para voltar\n");
			printf("  À                                                        Ù\n");
			subMenu();
			selectSubMenu();
	}
}

void menuVoltar(){	
	int opcao;
	printf("\n\n         Selecione uma opcao abaixo:   \n");
	printf("  À                                       Ù\n");
	printf("\n         1- Voltar ao menu principal\n         0- Sair\n");	
	printf("  À                                       Ù\n");
	scanf("%d", &opcao);
	switch(opcao){
			case 0:
				break;
			case 1:
				limpaTela();
				menuPrincipal();
				selectMenu();
				break;
			default:
				limpaTela();
				menuVoltar();				
		}
}

void menuServicos(){	
	printf("\n  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ  O que gostaria de ver  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	printf("  ²                                                        ³\n");
	printf("  ³             1- Coleta de Lixo                          ³\n");
	printf("  ³             2- Abastecimento de Agua                   ³\n");	
	printf("  ³             3- Esgoteamento Sanitario                  ³\n");
	printf("  ³                                                        ³\n");
	printf("  ³             0- Voltar                                  ³\n");
	printf("  ³                                                        ²\n");
	printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
}

void referencias(){
	printf("\n\n Referencias de dados: \n");
	printf("\n -> IBGE - Instituto Brasileiro de Geografia e Estatistica\n");
	printf("   Disponivel em: www.ibge.gov.br/estatisticas/sociais/populacao/25844-desigualdades-sociais-por-cor-ou-raca.html\n");
	printf("\n -> Nota: \n");
	printf("  Os dados sao referentes ao ano de 2018, de acordo com o ultimo censo realizado pelo IBGE.\n");
	printf(" Apos 2018 nao foram realizados novos censos.");
}

// ****** F U N C O E S  de  D A D O S ******

int porcentParaDecimal(int a, float b){
	int numeroTotal;
	float porcentagem;
	porcentagem = (b / 100);
	numeroTotal = a * 1000;		
	numeroTotal *= porcentagem;
		
	return numeroTotal;			
}

int retornaPosicaoEMaiorValor(int vetor[]) {
    int maior = vetor[0], i;
    int posicao = 0;
    for (i = 0; i < 5; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            posicao = i;
        }
    }
    return posicao;
}

int retornaPosicaoEMenorValor(int vetor[]) {
    int menor = vetor[0], i;
    int posicao = 0;
    for (i = 0; i < 5; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
            posicao = i;
        }
    }
    return posicao;
}

void maiorDistribuicao(){
	int regioes[5], i, pos;
			
			regioes[0]=porcentParaDecimal(populacaoNorte, popNorteBranca);
			regioes[1]=porcentParaDecimal(populacaoNordeste, popNordesteBranca);
			regioes[2]=porcentParaDecimal(populacaoSudeste, popSudesteBranca);
			regioes[3]=porcentParaDecimal(populacaoSuL, popSulBranca);
			regioes[4]=porcentParaDecimal(populacaoCentroOeste, popCOBranca);
			
			printf("\n -> Embora aproximadamente %2.1f %% da populacao da regiao Sul seja branca,", popSulBranca);
			
			pos=retornaPosicaoEMaiorValor(regioes);
			
			if(pos==0){
				printf("\n eh a regiao Norte que concentra o maior numero de pessoas brancas ");
				printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[0], popNorteBranca);				
			}else
				if(pos==1){
					printf("\n eh a regiao Nordeste que concentra o maior numero de pessoas brancas ");
					printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[1], popNordesteBranca);					
				}else
					if(pos==2){
						printf("\n eh a regiao Sudeste que concentra o maior numero de pessoas brancas ");
						printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[2], popSudesteBranca);						
					}else
						if(pos==3){
							printf("\n eh a regiao Sul que concentra o maior numero de pessoas brancas ");
							printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[3], popSulBranca);							
						}else
							if(pos==4){
								printf("\n eh a regiao Centro-Oeste que concentra o maior numero de pessoas brancas ");
								printf("totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[4], popCOBranca);								
							}
												
			limpaVetor(regioes);
			
			regioes[0]=porcentParaDecimal(populacaoNorte, popNortePretaEParda);
			regioes[1]=porcentParaDecimal(populacaoNordeste, popNordestePretaEParda);
			regioes[2]=porcentParaDecimal(populacaoSudeste, popSudestePretaEParda);
			regioes[3]=porcentParaDecimal(populacaoSuL, popSulPretaEParda);
			regioes[4]=porcentParaDecimal(populacaoCentroOeste, popCOPretaEParda);
			
			printf("\n");
			printf("\n -> Embora aproximadamente %2.1f %% da populacao da regiao Norte seja preta ou parda,", popNortePretaEParda);
			
			pos=retornaPosicaoEMaiorValor(regioes);
			
			if(pos==0){
				printf("\n eh a regiao Norte que concentra o maior numero de pessoas pretas ou pardas ");
				printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[0], popNortePretaEParda);				
			}else
				if(pos==1){
					printf("\n eh a regiao Nordeste que concentra o maior numero de pessoas pretas ou pardas ");
					printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[1], popNordestePretaEParda);					
				}else
					if(pos==2){
						printf("\n eh a regiao Sudeste que concentra o maior numero de pessoas pretas ou pardas ");
						printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[2], popSudestePretaEParda);						
					}else
						if(pos==3){
							printf("\n eh a regiao Sul que concentra o maior numero de pessoas pretas ou pardas ");
							printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[3], popSulPretaEParda);							
						}else
							if(pos==4){
								printf("\n eh a regiao Centro-Oeste que concentra o maior numero de pessoas pretas ou pardas ");
								printf("totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[4], popCOPretaEParda);								
							}
			
			limpaVetor(regioes);
			
			regioes[0]=porcentParaDecimal(populacaoNorte, popNorteAmarelaEIndigena);
			regioes[1]=porcentParaDecimal(populacaoNordeste, popNordesteAmarelaEIndigena);
			regioes[2]=porcentParaDecimal(populacaoSudeste, popSudesteAmarelaEIndigena);
			regioes[3]=porcentParaDecimal(populacaoSuL, popSulAmarelaEIndigena);
			regioes[4]=porcentParaDecimal(populacaoCentroOeste, popCOAmarelaEIndigena);
			
			
			printf("\n");
			printf("\n -> Embora aproximadamente %2.1f %% da populacao da regiao Norte seja amarela ou indigena,", popNorteAmarelaEIndigena);
			
			pos=retornaPosicaoEMaiorValor(regioes);
			
			if(pos==0){
				printf("\n eh a regiao Norte que concentra o maior numero de pessoas amarelas ou indigenas ");
				printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[0], popNorteAmarelaEIndigena);				
			}else
				if(pos==1){
					printf("\n eh a regiao Nordeste que concentra o maior numero de pessoas amarelas ou indigenas ");
					printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[1], popNordesteAmarelaEIndigena);					
				}else
					if(pos==2){
						printf("\n eh a regiao Sudeste que concentra o maior numero de pessoas amarelas ou indigenas ");
						printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[2], popSudesteAmarelaEIndigena);						
					}else
						if(pos==3){
							printf("\n eh a regiao Sul que concentra o maior numero de pessoas amarelas ou indigenas ");
							printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[3], popSulAmarelaEIndigena);							
						}else
							if(pos==4){
								printf("\n eh a regiao Centro-Oeste que concentra o maior numero de pessoas amarelas ou indigenas ");
								printf("totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[4], popCOAmarelaEIndigena);								
							}
	
}

void menorDistribuicao(){
	int regioes[5], i, pos;
			
			regioes[0]=porcentParaDecimal(populacaoNorte, popNorteBranca);
			regioes[1]=porcentParaDecimal(populacaoNordeste, popNordesteBranca);
			regioes[2]=porcentParaDecimal(populacaoSudeste, popSudesteBranca);
			regioes[3]=porcentParaDecimal(populacaoSuL, popSulBranca);
			regioes[4]=porcentParaDecimal(populacaoCentroOeste, popCOBranca);
			
			pos=retornaPosicaoEMenorValor(regioes);
			
			if(pos==0){
				printf("\n -> Eh a regiao Norte que concentra o menor numero de pessoas brancas ");
				printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[0], popNorteBranca);				
			}else
				if(pos==1){
					printf("\n -> Eh a regiao Nordeste que concentra o menor numero de pessoas brancas ");
					printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[1], popNordesteBranca);					
				}else
					if(pos==2){
						printf("\n -> Eh a regiao Sudeste que concentra o menor numero de pessoas brancas ");
						printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[2], popSudesteBranca);						
					}else
						if(pos==3){
							printf("\n -> Eh a regiao Sul que concentra o menor numero de pessoas brancas ");
							printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[3], popSulBranca);							
						}else
							if(pos==4){
								printf("\n -> Eh a regiao Centro-Oeste que concentra o menor numero de pessoas brancas ");
								printf("totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[4], popCOBranca);								
							}
												
			limpaVetor(regioes);
			
			regioes[0]=porcentParaDecimal(populacaoNorte, popNortePretaEParda);
			regioes[1]=porcentParaDecimal(populacaoNordeste, popNordestePretaEParda);
			regioes[2]=porcentParaDecimal(populacaoSudeste, popSudestePretaEParda);
			regioes[3]=porcentParaDecimal(populacaoSuL, popSulPretaEParda);
			regioes[4]=porcentParaDecimal(populacaoCentroOeste, popCOPretaEParda);
			
			printf("\n");
			
			pos=retornaPosicaoEMenorValor(regioes);
			
			if(pos==0){
				printf("\n -> Eh a regiao Norte que concentra o menor numero de pessoas pretas ou pardas ");
				printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[0], popNortePretaEParda);				
			}else
				if(pos==1){
					printf("\n -> Eh a regiao Nordeste que concentra o menor numero de pessoas pretas ou pardas ");
					printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[1], popNordestePretaEParda);					
				}else
					if(pos==2){
						printf("\n -> Eh a regiao Sudeste que concentra o menor numero de pessoas pretas ou pardas ");
						printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[2], popSudestePretaEParda);						
					}else
						if(pos==3){
							printf("\n -> Eh a regiao Sul que concentra o menor numero de pessoas pretas ou pardas ");
							printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[3], popSulPretaEParda);							
						}else
							if(pos==4){
								printf("\n -> Eh a regiao Centro-Oeste que concentra o menor numero de pessoas pretas ou pardas ");
								printf("totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[4], popCOPretaEParda);								
							}
			
			limpaVetor(regioes);
			
			regioes[0]=porcentParaDecimal(populacaoNorte, popNorteAmarelaEIndigena);
			regioes[1]=porcentParaDecimal(populacaoNordeste, popNordesteAmarelaEIndigena);
			regioes[2]=porcentParaDecimal(populacaoSudeste, popSudesteAmarelaEIndigena);
			regioes[3]=porcentParaDecimal(populacaoSuL, popSulAmarelaEIndigena);
			regioes[4]=porcentParaDecimal(populacaoCentroOeste, popCOAmarelaEIndigena);
			
			
			printf("\n");
			
			pos=retornaPosicaoEMenorValor(regioes);
			
			if(pos==0){
				printf("\n -> Eh a regiao Norte que concentra o menor numero de pessoas amarelas ou indigenas ");
				printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[0], popNorteAmarelaEIndigena);				
			}else
				if(pos==1){
					printf("\n -> Eh a regiao Nordeste que concentra o menor numero de pessoas amarelas ou indigenas ");
					printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[1], popNordesteAmarelaEIndigena);					
				}else
					if(pos==2){
						printf("\n -> Eh a regiao Sudeste que concentra o menor numero de pessoas amarelas ou indigenas ");
						printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[2], popSudesteAmarelaEIndigena);						
					}else
						if(pos==3){
							printf("\n -> Eh a regiao Sul que concentra o menor numero de pessoas amarelas ou indigenas ");
							printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[3], popSulAmarelaEIndigena);							
						}else
							if(pos==4){
								printf("\n -> Eh a regiao Centro-Oeste que concentra o menor numero de pessoas amarelas ou indigenas ");
								printf("\n totalizando %d pessoas (aprox. %2.1f %% da regiao). \n", regioes[4], popCOAmarelaEIndigena);								
							}	
}

void distribuicao(){
	int select, voltar;
	char titulo[35]="";
	subMenu();
	select = selectSubMenu();
	
	if(select == 1){
		strcat(titulo, tituloDistr);
		strcat(titulo, geral);
		maiusculas(titulo);
		printf("\n");
		printf(" %s\n\n", titulo);
		imprimeArquivo(total_brasileiros);
		limpaString(titulo);
		strcat(titulo, tituloDistr);
		strcat(titulo, cor);
		maiusculas(titulo);
		printf("\n\n");
		printf(" %s\n\n", titulo);
		imprimeArquivo(total_brasileiros_cor);
		strcat(titulo, e);
		strcat(titulo, regiao);
		maiusculas(titulo);
		printf("\n\n");
		printf(" %s\n\n", titulo);
		imprimeArquivo(total_brasileiros_uf_cor);
		referencias();
		menuVoltar();
		
	}else 
		if(select== 2){			
			maiorDistribuicao();
			menorDistribuicao();
			referencias();		
			menuVoltar();
		}
}

void trabalho(){
	int select;
	subMenu();
	select = selectSubMenu();	
	if(select == 1){
		int auxiliar = porcentParaDecimal(distribPopBrasil, desempregoBrasil);
		int auxiliar1=0;
		
		printf("\n -> Taxas de desocupacao \n");
			
		printf("\n * A taxa de desemprego no Brasil, considerando pessoas acima de 14 anos, eh de %2.1f %%\n",desempregoBrasil);
		printf("totalizando uma media de %d pessoas.\n",auxiliar);
		
		auxiliar1 = (desempregoBrancas/100) * auxiliar;
		
		printf("\n * A taxa de desemprego de pessoas brancas, considerando pessoas acima de 14 anos, eh de %2.1f %%\n",desempregoBrancas);
		printf("totalizando uma media de %d pessoas.\n",auxiliar1);
		
		auxiliar1 = (desempregoPretas/100) * auxiliar;
			
		printf("\n * A taxa de desemprego de pessoas pretas ou pardas, considerando pessoas acima de 14 anos, eh de %2.1f %%\n",desempregoPretas);
		printf("totalizando uma media de %d pessoas.\n",auxiliar);
		
		printf("\n -> Taxas de ocupacao \n");
		
		auxiliar = porcentParaDecimal(distribPopBrasil, empregoBrasil);
		
		printf("\n * A taxa de empregos ocupados no Brasil, considerando pessoas acima de 14 anos, eh de %2.1f %%\n",empregoBrasil);
		printf("totalizando uma media de %d pessoas.\n",auxiliar);
		
		auxiliar1 = (empregoBrancas/100) * auxiliar;
		
		printf("\n * A taxa de empregos ocupados por pessoas brancas, considerando pessoas acima de 14 anos, eh de %2.1f %%\n",empregoBrancas);
		printf("totalizando uma media de %d pessoas.\n",auxiliar1);
		
		auxiliar1 = (empregoPretas/100) * auxiliar;
			
		printf("\n * A taxa de empregos ocupados por pessoas pretas ou pardas, considerando pessoas acima de 14 anos, eh de %2.1f %%\n",empregoPretas);
		printf("totalizando uma media de %d pessoas.\n",auxiliar);
		
		printf("\n -> Cargos Gerenciais \n");
			
		auxiliar = cargoLiderBrasil * 1000;
		
		printf("\n * O numero medio de brasileiros em cargos gerenciais, considerando pessoas acima de 14 anos, eh de %d.\n", auxiliar);
		
		printf("\n * A taxa de pessoas brancas em cargos gerenciais, considerando pessoas acima de 14 anos, eh de %2.1f %%\n",cargoLiderBrancasBrasil);
		printf("totalizando uma media de %d pessoas.\n",porcentParaDecimal(cargoLiderBrasil, cargoLiderBrancasBrasil));
		
		printf("\n * A taxa de pessoas pretas ou pardas em cargos gerenciais, considerando pessoas acima de 14 anos, eh de %2.1f %%\n",cargoLiderPretasBrasil);
		printf("totalizando uma media de %d pessoas.\n",porcentParaDecimal(cargoLiderBrasil, cargoLiderPretasBrasil));
			
		referencias();
		menuVoltar();
	}else 
		if(select== 2){
			imprimeArquivo(uf_rendimentos);
			referencias();
			menuVoltar();
		}
}
	
void saneamento(){	
	int opcoes;	
	menuServicos();
	scanf("%d", &opcoes);
	if(opcoes==1){
		printf("\n-> Coleta de lixo:\n\n");
		imprimeArquivo("coleta_lixo.txt");
		referencias();
		menuVoltar();
	}else 
		if(opcoes==2){
			printf("\n-> Abastecimento de Agua:\n\n");
			imprimeArquivo("abastecimento_agua.txt");
			referencias();
			menuVoltar();
		}else 
			if(opcoes==3){
				printf("\n-> Esgotemento Sanitario:\n\n");
				imprimeArquivo("esgoteamento.txt");
				referencias();
				menuVoltar();
			}else if(opcoes==0){
				limpaTela();
				subMenu();
				selectSubMenu();
			}
}
