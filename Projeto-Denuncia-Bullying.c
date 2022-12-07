#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	int tipoUser, numEst=0, numProf=0;
	
	struct cadastro_estudante{
		int matricula;
		char nome[25];
		char instituicao[25];
		char email[25];
		int telefone;
		int dia_nasc;
		int mes_nasc;
		int ano_nasc;
		int sexo;
		int senha;
	};
	struct cadastro_estudante reg_estudante[numEst];
	
	struct cadastro_professor{
		int matricula;
		char nome[25];
		char instituicao[25];
		char email[25];
		int telefone;
		int dia_nasc;
		int mes_nasc;
		int ano_nasc;
		int sexo;
		int senha;
	};
	struct cadastro_professor reg_professor[numProf];
	
	int i, j, opcaoEst, opcaoProf, opcaoSec, validarSenha, validarMatricula;
	int opcaoLoginEst, opcaoLoginProf, opcaoLoginSec;
	int matriculaProv, senhaProv;
	int denuncias=0;
	int denunciaVer[100];
	char denuncia[100][100];
	
	int idSec, senhaSec, id, idVer;
	
	for(i=0;i<100;i++){
		denunciaVer[i]=0;
	}
	
	do{
		system("cls");
		printf("-------------------------------------------\n");
		printf("|        ESCOLHA SEU TIPO DE USUÁRIO      |\n");
		printf("|                                         |\n");
		printf("| [1] Estudante                           |\n");
		printf("| [2] Professor                           |\n");
		printf("| [3] Secretaria Estudantil               |\n");
		printf("| [0] Encerrar Programa                   |\n");
		printf("-------------------------------------------\n");
		scanf("%d", &tipoUser);
		fflush(stdin);
		
		switch (tipoUser){
			
			case 1:
	
			system("cls");
		
			do{
				printf("----------------------------------------------\n");
				printf("|           NOME PROJETO - ESTUDANTE         |\n");
				printf("|                                            |\n");
				printf("| Escolha uma opção                          |\n");
				printf("|                                            |\n");
				printf("| [1] Cadastro                               |\n");
				printf("| [2] Login                                  |\n");
				printf("| [0] Voltar                                 |\n");
				printf("----------------------------------------------\n\n");
				scanf("%d", &opcaoEst);
				fflush(stdin);
		
			switch(opcaoEst){
			
			case 1:
				
			
				system("cls");
				printf(" -------------------  CADASTRO  ESTUDANTE  -------------------\n\n");
				
				printf("Digite sua matrícula: ");
				scanf("%d", &reg_estudante[numEst].matricula);
				fflush(stdin);
			
				printf("Digite seu nome: ");
				scanf(" %24[^\n]", &reg_estudante[numEst].nome);  
				fflush(stdin);
						
				printf("Digite sua instituição: ");
				scanf(" %24[^\n]", &reg_estudante[numEst].instituicao);
				fflush(stdin);
						
				printf("Digite seu email: ");
				scanf(" %24[^\n]", &reg_estudante[numEst].email);
				fflush(stdin);
			
				printf("Digite seu telefone: ");
				scanf("%d", &reg_estudante[numEst].telefone);
				fflush(stdin);
			
				printf("Digite sua data de nascimento\n");
				
				do{
					printf("Dia: ");
					scanf("%d", &reg_estudante[numEst].dia_nasc);
					fflush(stdin);
					if(reg_estudante[numEst].dia_nasc > 31 || reg_estudante[numEst].dia_nasc < 0)
						printf("\n!!ESSA NÃO É UMA DATA VÁLIDA!!\nPor favor, digite um valor entre 1 e 31.\n");
				}while(reg_estudante[numEst].dia_nasc > 31 || reg_estudante[numEst].dia_nasc < 0);
				
				do{
					printf("Mês: ");
					scanf("%d", &reg_estudante[numEst].mes_nasc);
					fflush(stdin);
					if(reg_estudante[numEst].mes_nasc > 12 || reg_estudante[numEst].mes_nasc < 0)
						printf("\n!!ESSA NÃO É UMA DATA VÁLIDA!!\nPor favor, digite um valor entre 1 e 12.\n");
				}while(reg_estudante[numEst].mes_nasc > 12 || reg_estudante[numEst].mes_nasc < 0);
				
				do{
					printf("Ano: ");
					scanf("%d", &reg_estudante[numEst].ano_nasc);
					fflush(stdin);
					if(reg_estudante[numEst].ano_nasc > 2022 || reg_estudante[numEst].ano_nasc < 1912)
						printf("\n!!ESSA NÃO É UMA DATA VÁLIDA!!\nPor favor, digite um ano válido.\n");
				}while(reg_estudante[numEst].ano_nasc > 2022 || reg_estudante[numEst].ano_nasc < 1912);
			
				printf("Digite sua senha: ");
				scanf("%d", &reg_estudante[numEst].senha);
				fflush(stdin);
			
				do{
					printf(" 1 - Masculino\n 2 - Feminino\nDigite seu sexo: ");
					scanf("%d", &reg_estudante[numEst].sexo);
					fflush(stdin);
					if(reg_estudante[numEst].sexo != 1 && reg_estudante[numEst].sexo != 2)
						printf("\n!!NÚMERO INVÁLIDO!!\nDigite novamente.\n\n");					
				}while(reg_estudante[numEst].sexo != 1 && reg_estudante[numEst].sexo != 2);
				
				printf("\n\nCadastro efetuado com sucesso!\n\n");
				numEst++;
			
				system("pause");
				system("cls");
			
				break;
				
			case 2:
				
				system("cls");
				printf(" -------------------  LOGIN  ESTUDANTE  -------------------\n\n");
				printf("Digite sua matricula: ");
				scanf("%d", &matriculaProv);
				fflush(stdin);
				
				for(i=0; i<numEst; i++){
					if(matriculaProv == reg_estudante[i].matricula){
						do{
							printf("Digite sua senha: ");
							scanf("%d", &senhaProv);
							fflush(stdin);
							if (senhaProv == reg_estudante[i].senha){
								printf("\nLogin efetuado com sucesso!\n\n");
                                system("pause");
                                system("cls");
                                do{
									printf("----------------------------------------------\n");
									printf("|                  ESTUDANTE                 |\n");
									printf("|                                            |\n");
									printf("| Escolha uma opção                          |\n");
									printf("|                                            |\n");
									printf("| [1] Efetuar denúncia                       |\n");
									printf("| [2] Listar denúncias                       |\n");
									printf("| [0] Logout                                 |\n");
									printf("----------------------------------------------\n\n");
									scanf("%d", &opcaoLoginEst);
									fflush(stdin);
									
									switch(opcaoLoginEst){
										case 1:
											system("cls");
											printf("---------------------- EFETUAR DENÚNCIA ----------------------\n\n");
											printf("Digite sua Denúncia: \n\n");
											scanf(" %99[^\n]", &denuncia[denuncias]);
											fflush(stdin);
											printf("\nDenúncia enviada!\n\n");
											system("pause");
											system("cls");
											denuncias++;
											
										break;
										
										case 2:
											system("cls");
											printf("---------------------- LISTA DE DENÚNCIAS ----------------------\n");
											if(denuncias>0){
												for(i=0;i<denuncias;i++){
													printf("ID: %d\n", i);
													printf("Denúncia: %s\n", denuncia[i]);
													if(denunciaVer[i]==0){
														printf("Status: Em andamento\n\n");}
													else printf("Status: Concluída\n\n");
												}
											
												system(" \n\n\n");
												system("pause");
												system("cls");
											}else {
												printf("\nSem denúncias no momento!\n\n");
												system("pause");
												system("cls");
												}
												
										break;
										
										case 0:
										break;
										
										default:
											printf("\nOpção inválida!\n");
											system("pause");
											system("cls");
									}
								}while (opcaoLoginEst!=0);
							}else{
								printf("Senha digitada inválida!\n");
								j=1;
							} 
						}while(j==1);
                    }
						
					else {
						printf("\nMatrícula não registrada!\n\n");
						system("pause");
						}
						
				system("cls");

				}
				
				break;
				
			case 0:
				
				break;
				
			default:
			
				printf("\nOpçãoo inválida.\n\n");
				system("pause");
				system("cls");
				
			}
			}while(opcaoEst!=0);
			
			break;

        
        case 2:

        system("cls");
		
			do{
				printf("----------------------------------------------\n");
				printf("|           NOME PROJETO - PROFESSOR         |\n");
				printf("|                                            |\n");
				printf("| Escolha uma opção                          |\n");
				printf("|                                            |\n");
				printf("| [1] Cadastro                               |\n");
				printf("| [2] Login                                  |\n");
				printf("| [0] Voltar                                 |\n");
				printf("----------------------------------------------\n\n");
				scanf("%d", &opcaoProf);
				fflush(stdin);
		
			switch(opcaoProf){
			
			case 1:
				
			
				system("cls");
				printf(" -------------------  CADASTRO  PROFESSOR  -------------------\n\n");
		
				printf("Digite sua matricula: ");
				scanf("%d", &reg_professor[numProf].matricula);
				fflush(stdin);
			
				printf("Digite seu nome: ");
				scanf(" %24[^\n]", &reg_professor[numProf].nome);
				fflush(stdin);
						
				printf("Digite sua instituicao: ");
				scanf(" %24[^\n]", &reg_professor[numProf].instituicao);
				fflush(stdin);
						
				printf("Digite seu email: ");
				scanf(" %24[^\n]", &reg_professor[numProf].email);
				fflush(stdin);
			
				printf("Digite seu telefone: ");
				scanf("%d", &reg_professor[numProf].telefone);
				fflush(stdin);
			
			printf("Digite sua data de nascimento\n");
				
				do{
					printf("Dia: ");
					scanf("%d", &reg_professor[numProf].dia_nasc);
					fflush(stdin);
					if(reg_professor[numProf].dia_nasc > 31 || reg_professor[numProf].dia_nasc < 0)
						printf("\n!!ESSA NÃO É UMA DATA VÁLIDA!!\nPor favor, digite um valor entre 1 e 31.\n");
				}while(reg_professor[numProf].dia_nasc > 31 || reg_professor[numProf].dia_nasc < 0);
				
				do{
					printf("Mês: ");
					scanf("%d", &reg_professor[numProf].mes_nasc);
					fflush(stdin);
					if(reg_professor[numProf].mes_nasc > 12 || reg_professor[numProf].mes_nasc < 0)
						printf("\n!!ESSA NÃO É UMA DATA VÁLIDA!!\nPor favor, digite um valor entre 1 e 12.\n");
				}while(reg_professor[numProf].mes_nasc > 12 || reg_professor[numProf].mes_nasc < 0);
				
				do{
					printf("Ano: ");
					scanf("%d", &reg_professor[numProf].ano_nasc);
					fflush(stdin);
					if(reg_professor[numProf].ano_nasc > 2022 || reg_professor[numProf].ano_nasc < 1912)
						printf("\n!!ESSA NÃO É UMA DATA VÁLIDA!!\nPor favor, digite um ano válido.\n");
				}while(reg_professor[numProf].ano_nasc > 2022 || reg_professor[numProf].ano_nasc < 1912);
			
				printf("Digite sua senha: ");
				scanf("%d", &reg_professor[numProf].senha);
				fflush(stdin);
			
				do{
					printf(" 1 - Masculino\n 2 - Feminino\nDigite seu sexo: ");
					scanf("%d", &reg_professor[numProf].sexo);
					fflush(stdin);
					if(reg_professor[numProf].sexo != 1 && reg_professor[numProf].sexo != 2)
						printf("\n!!NÚMERO INVÁLIDO!!\nDigite novamente.\n\n");					
				}while(reg_professor[numProf].sexo != 1 && reg_professor[numProf].sexo != 2);
				
				printf("\n\nCadastro efetuado com sucesso!\n\n");
				numProf++;
			
				system("pause");
				system("cls");
			
				break;
				
			case 2:
				
				system("cls");
				printf(" -------------------  LOGIN  PROFESSOR  -------------------\n\n");
				printf("Digite sua matrícula: ");
				scanf("%d", &matriculaProv);
				fflush(stdin);
				
				for(i=0; i<numProf; i++){
					if(matriculaProv == reg_professor[i].matricula){
						do{
							printf("Digite sua senha: ");
							scanf("%d", &senhaProv);
							fflush(stdin);
							if (senhaProv == reg_professor[i].senha){
								printf("\nLogin efetuado com sucesso!\n\n");
                                system("pause");
                                system("cls");
								do{
									printf("----------------------------------------------\n");
									printf("|                  PROFESSOR                 |\n");
									printf("|                                            |\n");
									printf("| Escolha uma opção                          |\n");
									printf("|                                            |\n");
									printf("| [1] Efetuar denúncia                       |\n");
									printf("| [2] Listar denúncias                       |\n");
									printf("| [0] Logout                                 |\n");
									printf("----------------------------------------------\n\n");
									scanf("%d", &opcaoLoginProf);
									fflush(stdin);
									
									switch(opcaoLoginProf){
										case 1:
											system("cls");
											printf("---------------------- EFETUAR DENÚNCIA ----------------------\n\n");
											printf("Digite sua Denúncia: \n\n");
											scanf(" %99[^\n]", &denuncia[denuncias]);
											fflush(stdin);
											printf("\nDenúncia enviada!\n\n");
											system("pause");
											system("cls");
											denuncias++;
											
										break;
										
										case 2:
											system("cls");
											printf("---------------------- LISTA DE DENÚNCIAS ----------------------\n");
											if(denuncias>0){
												for(i=0;i<denuncias;i++){
													printf("ID: %d\n", i);
													printf("Denúncia: %s\n", denuncia[i]);
													if(denunciaVer[i]==0){
														printf("Status: Em andamento\n\n");}
													else printf("Status: Concluída\n\n");
												}
											
												system(" \n\n\n");
												system("pause");
												system("cls");
											}else {
												printf("\nSem denúncias no momento!\n\n");
												system("pause");
												system("cls");
												}
												
										break;
										
										case 0:
										break;
										
										default:
											printf("\nOpção inválida!\n");
											system("pause");
											system("cls");
									}
								}while (opcaoLoginProf!=0);
							}else{
								printf("Senha inválida!\n");
								j=1;
							} 
						}while(j==1);
                    }
						
					else{
                        printf("Matrícula não registrada!\n\n");
						system("pause");
						}
					
				system("cls");

				}
				
			break;
				
			case 0:
				
				break;
				
			default:
			
				printf("\nOpção inválida.\n\n");
				system("pause");
				system("cls");
				
			}
			}while(opcaoProf!=0);
			
			break;
			
			case 3:
				
				system("cls");
				
				do{
					printf("----------------------------------------------\n");
					printf("|           NOME PROJETO - SECRETARIA        |\n");
					printf("|                                            |\n");
					printf("| Escolha uma opção                          |\n");
					printf("|                                            |\n");
					printf("| [1] Login                                  |\n");
					printf("| [0] Voltar                                 |\n");
					printf("----------------------------------------------\n\n");
					scanf("%d", &opcaoSec);
					fflush(stdin);
				
					switch(opcaoSec){
					
					case 1:
							
						system("cls");
						printf(" -------------------  LOGIN  SECRETARIA  -------------------\n\n");
						printf("Digite o ID da instituição: ");
						scanf("%d", &idSec);
						fflush(stdin);
						printf("Digite sua senha: ");
						scanf("%d", &senhaSec);
						fflush(stdin);
						printf("\nLogin efetuado com sucesso!\n\n");
						system("pause");
						system("cls");
							
							do{
								
								printf("----------------------------------------------\n");
								printf("|                  SECRETARIA                |\n");
								printf("|                                            |\n");
								printf("| Escolha uma opção                          |\n");
								printf("|                                            |\n");
								printf("| [1] Efetuar denúncia                       |\n");
								printf("| [2] Listar denúncias                       |\n");
								printf("| [3] Dashboard                              |\n");
								printf("| [4] Analisar Denúncia                      |\n");
								printf("| [0] Logout                                 |\n");
								printf("----------------------------------------------\n\n");
								scanf("%d", &opcaoLoginSec);
								fflush(stdin);
								
								switch (opcaoLoginSec){
									case 1:
										
										system("cls");
											printf("---------------------- EFETUAR DENÚNCIA ----------------------\n\n");
											printf("Digite sua Denúncia: \n\n");
											scanf(" %99[^\n]", &denuncia[denuncias]);
											fflush(stdin);
											printf("\nDenúncia enviada!\n\n");
											system("pause");
											system("cls");
											denuncias++;
											
									break;
									
									case 2:
										
										system("cls");
											printf("---------------------- LISTA DE DENÚNCIAS ----------------------\n");
											if(denuncias>0){
												for(i=0;i<denuncias;i++){
													printf("ID: %d\n", i);
													printf("Denúncia: %s\n", denuncia[i]);
													if(denunciaVer[i]==0){
														printf("Status: Em andamento\n\n");}
													else printf("Status: Concluída\n\n");
												}
											
												system(" \n\n\n");
												system("pause");
												system("cls");
											}else {
												printf("\nSem denúncias no momento!\n\n");
												system("pause");
												system("cls");
												}
										
									break;
									
									case 3:
										
										printf("\n\nFunção Dashboard exclusiva pelo acesso ao site.\n\n");
										system("pause");
										system("cls");
										
									break;
									
									case 4:
										
										system("cls");
										do{
											printf("Digite o ID da denúncia que gostaria de analisar: ");
											scanf("%d", &id);
											fflush(stdin);
											if(id<0 || id>denuncias){
												printf("\n!!ID DIGITADO NÃO ENCONTRADO!!\nPor favor, digite um ID válido.\n");
											}		
										}while(id<0 || id>denuncias);
										
										printf("\nDenúncia: %s\n\n", denuncia[id]);
										do{
											printf("Denúncia apurada e concluida ?\n1 - SIM\n2 - NÃO\n");
											scanf("%d", &idVer);
											if(idVer != 1 && idVer != 2){
												printf("\n!!NÚMERO INVÁLIDO!!\nDigite novamente.\n\n");
											}	
										}while(idVer != 1 && idVer != 2);
										
										if(idVer==1){
											denunciaVer[id]=1;
										}
										printf("\nO status da denúncia foi atualizado!\n\n");
										system("pause");
										system("cls");
										
									break;
									
									default:
										printf("\nOpção inválida!\n\n");
										system("cls");
										system("pause");
								}
								
							}while (opcaoLoginSec!=0);
						}
						
						break;
			
					case 0: 
			
					break;
			
					default:
				
					printf("\nOpção inválida.\n\n");
					system("pause");
					system("cls"); 
				
				}while(opcaoSec!=0);
		} 
	}while(tipoUser!=0);
}
