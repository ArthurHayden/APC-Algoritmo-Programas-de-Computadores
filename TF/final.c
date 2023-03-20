//Arthur
//Fiz o codigo no linux  visual studio code
// gcc -o prog -W -Wall -Wshadow -pedantic TF1_ArthurPrado funcoes.c(compilador)
//sintese
//Objetivo:executar cada uma das opçoes que o usuario escolher,cadastrar,alterar cadastro, listar,listar em uma modalidade,apagar cadastro e fechar o programa
//Entrada:alguma opçao,cadastros,
//Saida:lista de cadastro em ordem crescente ou decresente, lista de cadastro em uma modalidade
#include<stdio_ext.h>
#include<string.h>
#include <stdlib.h>
#include "funcoes.h"
#include <ctype.h>
#define ARQUIVO "cursosProfissionais.bin"
int main(){
    int N=0;
    cad vetor;
    FILE *fl;
    int tamanho;
    int cont=0;
    int cadastro=0;//varivel que imforma cadastro
    int opcao=0;//opcao de alteraçao(2)
    char opcao2='N';
    char resposta2='N';
    int resposta=0;
    
     if ((fl=fopen(ARQUIVO,"a+b"))==NULL){ 
        puts("Arquivo nao pode ser aberto.");
        getchar();
         
    }
    else {
        fclose(fl);
    }
    do {
        telainicial();
        scanf("%d",&N);
        switch (N)
        {
            case 0:
                break;
            case 1:
                system("clear");
                telacadastro();
                printf("digite código numérico de identificação do curso: ");
                scanf("%d",&vetor.cnic);
                vetor.cnic=validaCnic100(vetor.cnic);
                    
                vetor.cnic=validacnic(vetor.cnic,ARQUIVO);
                while (vetor.cnic==0){
                    printf("código numérico de identificação do curso ja cadastrada, digite outra:");
                    scanf("%d",&vetor.cnic);
                    vetor.cnic=validaCnic100(vetor.cnic);
                    vetor.cnic=validacnic(vetor.cnic,ARQUIVO);
                    }
                    
                printf("digite o nome completo do curso: ");
            
                __fpurge(stdin);
                fgets(vetor.curso,18,stdin);
                barrazero(vetor.curso);
                validaNomecurso(vetor.curso);
                tamanho=strlen(vetor.curso);
                for(cont=0;cont<tamanho;cont++){
                    vetor.curso[cont]=tolower(vetor.curso[cont]);
                }
                vetor.curso[0]=toupper(vetor.curso[0]);
                __fpurge(stdin);            
                printf("Digite a sigla da escola:");
                fgets(vetor.escola,MAXSIGLA,stdin);
                barrazero(vetor.escola);
                validaSiglaEscola(vetor.escola);
                tamanho=strlen(vetor.curso);
                for(cont=0;cont<tamanho;cont++){
                    vetor.escola[cont]=tolower(vetor.escola[cont]);
                }
                vetor.escola[0]=toupper(vetor.escola[0]);
                    
                printf("Digite a modalidade do curso P-presencial D-a distancia: ");
                __fpurge(stdin);
                scanf("%c",&vetor.modalidade);
                vetor.modalidade=toupper(vetor.modalidade);
                validadeModalidade(&vetor.modalidade);
                
                if ((fl=fopen(ARQUIVO,"ab"))==NULL){ 
                    puts("Arquivo nao pode ser aberto.");
                    getchar();
                        
                }
                else {
                    
                    fwrite(&vetor,sizeof(cad),1,fl);
                    
                }
                fclose(fl);
                system("clear");
                break;
            case 2:
                do{
                    system("clear");
                    telaAlterar();
                    printf("digite 1 para alterar o cadastro ou 2 para apagar algum cadastro\n");
                    scanf("%d",&resposta);
                    validaOpcao2(&resposta);
                    printf("Digite a código numérico de identificação do curso:");
                    printf("\n==");
                    __fpurge(stdin);
                    scanf("%d",&cadastro);
                    cadastro=validaOpcao(cadastro,ARQUIVO);
                    while(cadastro==0){
                        printf("código numérico de identificação do curso nao encontrada digite novamente:");
                        scanf("%d",&cadastro);
                        cadastro=validaOpcao(cadastro,ARQUIVO);
                    }
                    if(resposta==1){
                        system("clear");
                        telaAlterar();
                        printf("quais imformaçoes voce deseja alterar ?\n 1-nome do curso\n 2-sigla da escola\n 3-modalidade\n :");
                        printf("opcao=");
                        scanf("%d",&opcao);
                        __fpurge(stdin);
                        validaResposta(&opcao);
                        if(opcao==1){
                            mudarnome(ARQUIVO,cadastro);
                        }
                        else if(opcao==2){
                            mudarSigla(ARQUIVO,cadastro);
                        }
                        else if(opcao==3){
                            mudarModalidade(ARQUIVO,cadastro);
                        }
                    }
                    else if(resposta==2){
                        __fpurge(stdin);
                        printf("deseja mesmo apagar o cadastro?s/n:");
                        __fpurge(stdin);
                        scanf("%c",&resposta2);
                        resposta2=toupper(resposta2);
                        validaresposta2(&resposta2);
                        if(resposta2=='S'){
                            apagarMatricula(ARQUIVO,cadastro);
                        }
                        else{
                            printf("CANCELADA OPERACAO!!\n");
                        }
                    }
                    opcao=0;
                    cadastro=0;
                    printf("Deseja alterar mais algum cadastro ou imformaçoes ?digite 'S' para sim e 'N' para nao\n");
                    __fpurge(stdin);
                    scanf("%c",&opcao2);
                    opcao2=toupper(opcao2);
                    validaResposta3(&opcao2);
                    
                    }while(opcao2!='N');
                    system("clear");
                    break;
                case 3:
                    ordenarCurso(ARQUIVO);
                    break;
                case 4:
                    ordenarSigla(ARQUIVO);
                    break;
                case 5:
                    apagar(ARQUIVO);
                    break;
                default:
                    printf("digite um numero valido\n");
        }
    }while(N!=0);
    
    return 0;
}

