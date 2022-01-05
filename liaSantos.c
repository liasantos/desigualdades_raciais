#include "lib.h"

// ****** D A D O S ******

// ~~~~~~ distribuicao ~~~~~~

// *** # total brasil # ***
//int distribuicaoPopulacaoBrasil = 207853;
// *** # total por regiao # ***
int populacaoNorte = 17871; 
int populacaoNordeste = 56618;
int populacaoSudeste = 87691;
int populacaoSuL = 29710;
int populacaoCentroOeste = 15964;
/*// *** # total por cor # ***
float populacaoBranca = 43.1;
float populacaoPreta = 9.3;
float populacaoParda = 46.5;
float populacaoAmarela = 0.7;
float populacaoIndigena = 0.4;*/
// *** # total por cor e regiao # ***
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

// *** # taxa desocupacao +14 anos # ***
float desempregoBrasil = 12.0;
float desempregoBrancas = 9.5;
float desempregoPretas = 14.1;
// *** # taxa desocupacao pop. branca +14 anos por regiao # ***
float desempregoNorteBrancas = 9.7;
float desempregoNordesteBrancas = 11.7;
float desempregoSudesteBrancas = 10.5;
float desempregoSulBrancas = 6.8;
float desempregoCOBrancas = 7.4;
// *** # taxa desocupacao pop. preta +14 anos por regiao # ***
float desempregoNortePretas = 12.9;
float desempregoNordestePretas = 15.3;
float desempregoSudestePretas = 14.9;
float desempregoSulPretas = 10.4;
float desempregoCOPretas = 10.2;
// *** # taxa pop. branca ocupada em cargo gerencial # ***
float cargoLiderBrancasBrasil = 68.6;
float cargoLiderBrancasNorte = 38.7;
float cargoLiderBrancasNordeste = 43.2;
float cargoLiderBrancasSudeste = 73.2;
float cargoLiderBrancasSul = 88.0;
float cargoLiderBrancasCO = 54.6;
// *** # taxa pop. preta ocupada em cargo gerencial # ***
float cargoLiderPretasBrasil = 29.9;
float cargoLiderPretasNorte = 61.1;
float cargoLiderPretasNordeste = 56.3;
float cargoLiderPretasSudeste = 24.4;
float cargoLiderPretasSul = 11.6;
float cargoLiderPretasCO = 44.6;
// *** # rendimento médio real mensal # ***
int rendaMediaMesBrasil = 2163;
int rendaMediaMesNorte = 1667;
int rendaMediaMesNordeste = 1441;
int rendaMediaMesSudeste = 2491;
int rendaMediaMesSul = 2358;
int rendaMediaMesCO = 2415;
// *** # rendimento médio real por hora # ***
float rendaMediaHoraBrasil = 13.3;
float rendaMediaHoraNorte = 10.8;
float rendaMediaHoraNordeste = 9.5;
float rendaMediaHoraSudeste = 15.0;
float rendaMediaHoraSul = 14.5;
float rendaMediaHoraCO = 14.9;
// ~~~~~~ moradia ~~~~~~
// *** # proporcao pessoas sem acesso servicos basicos # ***
float semColetaDeLixoBrasil= 9.7;
float semColetaDeLixoBrancas = 6.0;
float semColetaDeLixoPretas = 12.5;
float semAbastecimentoDeAguaBrasil = 15.1;
float semAbastecimentoDeAguaBrancas = 11.5;
float semAbastecimentoDeAguaPretas = 17.9;
float semEsgoteamentoSanitarioBrasil = 35.7;
float semEsgoteamentoSanitarioBrancas = 26.5;
float semEsgoteamentoSanitarioPretas = 42.8;

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
	printf("  ³             1- Ver todos os dados                      ³\n");
	printf("  ³             2- Comparar regioes                        ³\n");	
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
		menuVoltar();
		
	}else 
		if(select== 2){			
			maiorDistribuicao();
			menorDistribuicao();		
			menuVoltar();
		}
}

void trabalho(){
	int select;
	subMenu();
	select = selectSubMenu();
	
	if(select == 1){
		imprimeArquivo(uf_rendimentos);
		menuVoltar();
	}else 
		if(select== 2){
			printf("tchau");
			menuVoltar();
		}
}

void saneamento(){
	int select;
	subMenu();
	select = selectSubMenu();
	
	if(select == 1){
		printf("oi");
		menuVoltar();
	}else 
		if(select== 2){
			printf("tchau");
			menuVoltar();
		}
		
}

void teste(){
	//printf("%d\n", distribuicaoPopulacaoBrasil);
	//printf("%2.f\n", populacaoBranca);
	//printf("%d\n", porcentParaDecimal(distribuicaoPopulacaoBrasil, populacaoBranca));
	//imprimeArquivo(uf_rendimentos);
}

char referencias(){
	printf("oi");
}
