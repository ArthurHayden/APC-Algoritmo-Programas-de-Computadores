#include "funcoes.h"
#define MAX 100
//sintese
//Objetivo:mostrar a tela inicial
//Parâmetros:nenhum
//Retorno: Nenhum
void telainicial(){
    printf("____________________________________________________________\n");
    printf("|         Digite 1 para registrar novo curso               |");
    printf("\n|         Digite 2 para alterar dados do curso             |");
    printf("\n|         Digite 3 para listar todos os cursos cadastrados |");
    printf("\n|         Digite 4 para consultar cursos em uma modalidade |");
    printf("\n|         Digite 5 para apagar o arquivo                   |");
    printf("\n|         Digite 0 para encerrar o programa                |");
    printf("\n____________________________________________________________");
    printf("\nopçao: ");
}
//sintese
//Objetivo:mostrar a tela de cadastro
//Parâmetros:nenhum
//Retorno: Nenhum
void telacadastro(){
    printf("----------------------------------------\n");
    printf("CADASTRO\n");
    printf("----------------------------------------\n");
}
//sintese
//Objetivo:mostrar de alterar cadastro
//Parâmetros:nenhum
//Retorno: Nenhum
void telaAlterar(){
    printf("----------------------------------------\n");
    printf("ALTERAÇAO DE DADOS CADASTRADOS\n");
    printf("----------------------------------------\n");
}
//sintese
//Objetivo:mostrar tela de listar cadastros
//Parâmetros:nenhum
//Retorno: Nenhum
void telalistar(){
    printf("----------------------------------------\n");
    printf("LISTAR CADASTROS\n");
    printf("----------------------------------------\n");
}
//sintese
//Objetivo:mostrar tela de consultar cadastros
//Parâmetros:nenhum
//Retorno: Nenhum
void telaconsulta(){
    printf("----------------------------------------\n");
    printf("CONSULTAR CADASTROS\n");
    printf("----------------------------------------\n");
}
//sintese
//Objetivo:colocar o '\0' no final da string
//Parâmetros:uma palavra
//Retorno:nenhum
void barrazero(char *palavra){
    if(palavra[strlen(palavra)-1]=='\n'){
       palavra[strlen(palavra)-1]='\0';
    }
}
//sintese
//Objetivo:verificar se o usuario digitou um espaço no inicio da sigla
//Parâmetros:uma palavra
//Retorno:nenhum
void espacoEmBranco(char *branco){
    while(branco[0]==' ' || branco[0]=='\n' || branco[0]=='\0'){
        printf("a sigla nao pode começar com espaço em branco, digite outra:");
        __fpurge(stdin);
        fgets(branco,MAXSIGLA,stdin);
        barrazero(branco);
    }
}
//sintese
//Objetivo:validar o cnic
//Parâmetros:A matricula e o nome do arquivo
//retorno:código numérico de identificação do curso
int validacnic(int cnic, char ARQUIVO[30]){
    cad vetor;
    FILE *fl;
    if((fl=fopen(ARQUIVO,"rb"))==NULL){
        puts("Arquivo nao pode ser aberto");
        getchar();
    
    }
    else
    { 
        while(fread(&vetor,sizeof(cad),1,fl)){
            if(cnic==vetor.cnic){
                return 0;
            }
        }
        
        
    }
    fclose(fl);
    return cnic;
    
}
//sintese
//Objetivo:verificar se a matricula é maior que 100
//Parâmetros:a matricula
//Retorno:código numérico de identificação do curso
int validaCnic100(int cnic){
    while(cnic<=MAX){
        printf("digite um código numérico de identificação do curso maior que 100 :");
        
        scanf("%d",&cnic);
    }
    return cnic;
}
//sintese
//Objetivo:validar o nome do curso
//Parâmetros:uma palavra
//retorno:Nenhum
 void validaNomecurso(char *curso){
    int tamanho=0;
    tamanho=strlen(curso);
    while(tamanho<5 || tamanho>18){
        printf("digite um nome entre 5 e 18 caracteres  :");
        __fpurge(stdin);
        fgets(curso,18,stdin);
        barrazero(curso);
        tamanho=strlen(curso);
    }
}
//sintese
//Objetivo:validar a sigla da escola
//Parâmetros:uma palavra
//Retorno:Nenhum
void validaSiglaEscola(char *Sescola){
    int tamanho=0;
    tamanho=strlen(Sescola);
    espacoEmBranco(Sescola);
    while(tamanho<2 || tamanho>MAXSIGLA){
        printf("digite uma sigla valida :");
        __fpurge(stdin);
        fgets(Sescola,MAXSIGLA,stdin);
        barrazero(Sescola);
        espacoEmBranco(Sescola);
        tamanho=strlen(Sescola);
        
    }
}
//sintese
//Objetivo:validar a modalidade
//Parâmetros:a modalidade
//Retorno:Nenhum
void validadeModalidade(char *modalidade){
    
    while(*modalidade!='P' && *modalidade!='D'){
        printf("Caracter invalido, digite P ou D :");
        __fpurge(stdin);
        scanf("%c",modalidade);
        *modalidade=toupper(*modalidade);
    }
    
}
//sintese
//Objetivo:validar a opçao do case 2, 1 para alterar cadastro e 2 para apagar o cnic
//Parâmetros:uma opçao 
//Retorno:Nenhum
void validaOpcao2(int *opcao4){
    while(*opcao4!=1 && *opcao4!=2){
        printf("Digite 1 ou 2:");
        scanf("%d",opcao4);
    }
}
// //sintese
// //Objetivo:verificar se a matricula  existe
// //Parâmetros:matricula a ser procurada
// //Retorno:a matricula
int validaOpcao(int opcao, char ARQUIVO[30]){
    FILE *fl;
    cad vetor;
    if((fl=fopen(ARQUIVO,"rb"))==NULL){
    puts("Arquivo nao pode ser aberto");
    getchar();
    }
    else
    { 
        while(fread(&vetor,sizeof(cad),1,fl)){
            if(opcao==vetor.cnic){
                return opcao;
            }
        }
        
        
    }
    fclose(fl);
    return 0;
}
//sintese
//Objetivo:validar a opçao 1 para alterar o nome do curso 2 para alterar a sigla e 3 para alterar a modalidade
//Parâmetros:opçao escolhida
//Retorno:Nenhum
void validaResposta(int *opcao2){
    while(*opcao2!=1 && *opcao2!=2 && *opcao2!=3){
        printf("digite uma opcao valida\n");
        printf("opcao= ");
        __fpurge(stdin);
        scanf("%d",opcao2);

        }
    
}
//sintese
//Objetivo:validar a resposta, sim ou nao para a alteraçao de algum cadastro
//Parâmetros:um caracter  para sim ou nao
//Retorno:Nenhum
void validaResposta3(char *opcao3){
    while(*opcao3!='S' && *opcao3!='N'){
        printf("opcao invalida! digite 'S' ou 'N'\n");
        __fpurge(stdin);
        scanf("%c",opcao3);
        
        *opcao3=toupper(*opcao3);
    }
}
//sintese
//Objetivo:validar a resposta, sim ou nao para apagar um o cadastro
//Parâmetros:um caracter  para sim ou nao
//Retorno:Nenhum
void validaresposta2(char *resposta2){
    while(*resposta2!='S' && *resposta2!='N'){
        printf("opcao invalida! digite 'S' ou 'N'\n");
        __fpurge(stdin);
        scanf("%c",resposta2);
        *resposta2=toupper(*resposta2);
    }
}
//sintese
//Objetivo:validar a opçao crescente ou descente
//Parâmetros:opçao escolhida 
//Retorno:Nenhum
void validaResposta4(char *res2){
    while(*res2!='C' && *res2!='D'){
        printf("Resposta invalida! Digite 'C' ou 'D':");
        __fpurge(stdin);
        scanf("%c",res2);
        *res2=toupper(*res2);
    }
}
//sintese
//Objetivo:Ordenar o nome do curso
//Parâmetros:nome do arquivo
//Retorno:Nenhum
void ordenarCurso(char ARQUIVO[30]){
    int tamanho=0;
    int r=0;
    int size=0;
    int cont3=0;
    int cont4=0;
    int cont2=0;
    FILE *fl;
    cad vetor;
    char res;
    cad auxiliar;
    system("clear");
    telalistar();
    printf("Deseja listar os cursos de A-Z(crescente) ou Z-A(decrescente)? digite 'C' para A-Z e 'D' para Z-A\n");
    __fpurge(stdin);
    scanf("%c",&res);
    res=toupper(res);
    validaResposta4(&res);
    if ((fl=fopen(ARQUIVO,"rb"))==NULL){ 
        puts("Arquivo nao pode ser aberto.");
        getchar();
        
    }
    else {
        fseek(fl,0,SEEK_END);
        size=ftell(fl);
        tamanho=size/sizeof(cad);
        cad auxiliar2[tamanho];
        rewind(fl);
        while(fread(&vetor,sizeof(cad),1,fl)){
            auxiliar2[cont4].cnic=vetor.cnic;
            strcpy(auxiliar2[cont4].curso,vetor.curso);
            strcpy(auxiliar2[cont4].escola,vetor.escola);
            auxiliar2[cont4].modalidade=vetor.modalidade;
            cont4++;
        }
                
        fclose(fl);
        if(res=='C'){
            
            for(cont2=0;cont2<tamanho;cont2++){
                for(cont3=cont2+1;cont3<tamanho;cont3++){
                    r=strcmp(auxiliar2[cont2].curso,auxiliar2[cont3].curso);
                    if(r>0){
                        strcpy(auxiliar.curso,auxiliar2[cont2].curso);//
                        auxiliar.cnic=auxiliar2[cont2].cnic;
                        strcpy(auxiliar.escola,auxiliar2[cont2].escola);
                        auxiliar.modalidade=auxiliar2[cont2].modalidade;
                        strcpy(auxiliar2[cont2].curso,auxiliar2[cont3].curso);//
                        auxiliar2[cont2].cnic=auxiliar2[cont3].cnic;
                        strcpy(auxiliar2[cont2].escola,auxiliar2[cont3].escola);
                        auxiliar2[cont2].modalidade=auxiliar2[cont3].modalidade;
                        strcpy(auxiliar2[cont3].curso,auxiliar.curso);//
                        auxiliar2[cont3].cnic=auxiliar.cnic;
                        strcpy(auxiliar2[cont3].escola,auxiliar.escola);
                        auxiliar2[cont3].modalidade=auxiliar.modalidade;
                            
                    }
                }
            }
        }
        else if(res=='D'){
            
            for(cont2=0;cont2<tamanho;cont2++){
                for(cont3=cont2+1;cont3<tamanho;cont3++){
                    r=strcmp(auxiliar2[cont2].curso,auxiliar2[cont3].curso);
                    if(r<0){
                        strcpy(auxiliar.curso,auxiliar2[cont2].curso);//
                        auxiliar.cnic=auxiliar2[cont2].cnic;
                        strcpy(auxiliar.escola,auxiliar2[cont2].escola);
                        auxiliar.modalidade=auxiliar2[cont2].modalidade;
                        strcpy(auxiliar2[cont2].curso,auxiliar2[cont3].curso);//
                        auxiliar2[cont2].cnic=auxiliar2[cont3].cnic;
                        strcpy(auxiliar2[cont2].escola,auxiliar2[cont3].escola);
                        auxiliar2[cont2].modalidade=auxiliar2[cont3].modalidade;
                        strcpy(auxiliar2[cont3].curso,auxiliar.curso);//
                        auxiliar2[cont3].cnic=auxiliar.cnic;
                        strcpy(auxiliar2[cont3].escola,auxiliar.escola);
                        auxiliar2[cont3].modalidade=auxiliar.modalidade;
                            
                    }
                }
            }
        }
        system("clear");
        telalistar();
        printf("Cnic==\t  nome do curso==\tsigla da escola==\tmodalidade\t\n");
                    
        for(cont2=0;cont2<tamanho;cont2++){
            printf("%d\t  %-18s\t\t%-10s",auxiliar2[cont2].cnic,auxiliar2[cont2].curso,auxiliar2[cont2].escola);
            if(auxiliar2[cont2].modalidade=='P'){
                printf("\tPresencial\n");
            }
            else if(auxiliar2[cont2].modalidade=='D'){
                printf("\tDistancia\n");
            }
        }
        printf("\n");      
    }
}
//sintese
//Objetivo:Ordenar a sigla do curso 
//Parâmetros:nome do arquivo
//Retorno:Nenhum
void ordenarSigla(char ARQUIVO[30]){
    int tamanho=0;
    int r=0;
    int size=0;
    int cont3=0;
    int cont4=0;
    int cont2=0;
    int cont5=0;
    FILE *fl;
    cad vetor;
    char opcaom;
    cad auxiliar;
    system("clear");
    telaconsulta();
    printf("Deseja consultar os cadastros na modalidade presencial ou a distancia?digite P ou D\n");
    __fpurge(stdin);
    scanf("%c",&opcaom);
    opcaom=toupper(opcaom);
    validadeModalidade(&opcaom);
    if(opcaom=='P'){
        if ((fl=fopen(ARQUIVO,"rb"))==NULL){ 
            puts("Arquivo nao pode ser aberto.");
            getchar();
        }
        else {
            fseek(fl,0,SEEK_END);
            size=ftell(fl);
            tamanho=size/sizeof(cad);
            cad auxiliar3[tamanho];
            cad auxiliar2[tamanho];
            rewind(fl);
            while(fread(&vetor,sizeof(cad),1,fl)){
                auxiliar3[cont4].cnic=vetor.cnic;
                strcpy(auxiliar3[cont4].curso,vetor.curso);
                strcpy(auxiliar3[cont4].escola,vetor.escola);
                auxiliar3[cont4].modalidade=vetor.modalidade;
                cont4++;
            }
            
            fclose(fl);
            for(cont4=0;cont4<tamanho;cont4++){
                if(auxiliar3[cont4].modalidade=='P'){
                    auxiliar2[cont5].cnic=auxiliar3[cont4].cnic;
                    strcpy(auxiliar2[cont5].curso,auxiliar3[cont4].curso);
                    strcpy(auxiliar2[cont5].escola,auxiliar3[cont4].escola);
                    auxiliar2[cont5].modalidade=auxiliar3[cont4].modalidade;
                    cont5++;
                }
            }   
            for(cont2=0;cont2<cont5;cont2++){
                for(cont3=cont2+1;cont3<cont5;cont3++){
                    r=strcmp(auxiliar2[cont2].escola,auxiliar2[cont3].escola);
                    if(r>0){
                        strcpy(auxiliar.escola,auxiliar2[cont2].escola);//
                        auxiliar.cnic=auxiliar2[cont2].cnic;
                        strcpy(auxiliar.curso,auxiliar2[cont2].curso);
                        auxiliar.modalidade=auxiliar2[cont2].modalidade;
                        strcpy(auxiliar2[cont2].escola,auxiliar2[cont3].escola);//
                        auxiliar2[cont2].cnic=auxiliar2[cont3].cnic;
                        strcpy(auxiliar2[cont2].curso,auxiliar2[cont3].curso);
                        auxiliar2[cont2].modalidade=auxiliar2[cont3].modalidade;
                        strcpy(auxiliar2[cont3].escola,auxiliar.escola);//
                        auxiliar2[cont3].cnic=auxiliar.cnic;
                        strcpy(auxiliar2[cont3].curso,auxiliar.curso);
                        auxiliar2[cont3].modalidade=auxiliar.modalidade;
                                
                    }
                }
            }
            system("clear");
            telaconsulta();
            printf("Cnic==\t  nome do curso==\tsigla da escola==\tmodalidade\t\n");          
                for(cont2=0;cont2<cont5;cont2++){
                    printf("%d\t  %-18s\t\t%-10s",auxiliar2[cont2].cnic,auxiliar2[cont2].curso,auxiliar2[cont2].escola);
                    if(auxiliar2[cont2].modalidade=='P'){
                        printf("\tPresencial\n");
                    }
                }
            printf("\n");
                
        }
    
    }
    else if(opcaom=='D'){
        if ((fl=fopen(ARQUIVO,"rb"))==NULL){ 
            puts("Arquivo nao pode ser aberto.");
            getchar();
            
        }
        else {
            fseek(fl,0,SEEK_END);
            size=ftell(fl);
            tamanho=size/sizeof(cad);
            cad auxiliar3[tamanho];
            cad auxiliar2[tamanho];
            rewind(fl);
            while(fread(&vetor,sizeof(cad),1,fl)){
                auxiliar3[cont4].cnic=vetor.cnic;
                strcpy(auxiliar3[cont4].curso,vetor.curso);
                strcpy(auxiliar3[cont4].escola,vetor.escola);
                auxiliar3[cont4].modalidade=vetor.modalidade;
                cont4++;
                }
            
            fclose(fl);
            for(cont4=0;cont4<tamanho;cont4++){
                if(auxiliar3[cont4].modalidade=='D'){
                    auxiliar2[cont5].cnic=auxiliar3[cont4].cnic;
                    strcpy(auxiliar2[cont5].curso,auxiliar3[cont4].curso);
                    strcpy(auxiliar2[cont5].escola,auxiliar3[cont4].escola);
                    auxiliar2[cont5].modalidade=auxiliar3[cont4].modalidade;
                    cont5++;
                }
            } 
            for(cont2=0;cont2<cont5;cont2++){
                for(cont3=cont2+1;cont3<cont5;cont3++){
                    r=strcmp(auxiliar2[cont2].escola,auxiliar2[cont3].escola);
                    if(r>0){
                        strcpy(auxiliar.escola,auxiliar2[cont2].escola);//
                        auxiliar.cnic=auxiliar2[cont2].cnic;
                        strcpy(auxiliar.curso,auxiliar2[cont2].curso);
                        auxiliar.modalidade=auxiliar2[cont2].modalidade;
                        strcpy(auxiliar2[cont2].escola,auxiliar2[cont3].escola);//
                        auxiliar2[cont2].cnic=auxiliar2[cont3].cnic;
                        strcpy(auxiliar2[cont2].curso,auxiliar2[cont3].curso);
                        auxiliar2[cont2].modalidade=auxiliar2[cont3].modalidade;
                        strcpy(auxiliar2[cont3].escola,auxiliar.escola);//
                        auxiliar2[cont3].cnic=auxiliar.cnic;
                        strcpy(auxiliar2[cont3].curso,auxiliar.curso);
                        auxiliar2[cont3].modalidade=auxiliar.modalidade;        
                    }
                }
            }
            system("clear");
            telaconsulta();
            printf("Cnic==\t  nome do curso==\tsigla da escola==\tmodalidade\t\n");          
                for(cont2=0;cont2<cont5;cont2++){
                    printf("%d\t  %-18s\t\t%-10s",auxiliar2[cont2].cnic,auxiliar2[cont2].curso,auxiliar2[cont2].escola);
                    if(auxiliar2[cont2].modalidade=='D'){
                        printf("\tDistancia\n");
                    }
                }
        printf("\n");
              
        
        }
    }
}
//sintese
//Objetivo:apagar o arquivo
//Parâmetros:nome do arquivo
//Retorno:Nenhum
void apagar(char ARQUIVO[30]){
    char confirmar;
    FILE *fl;
    system("clear");
    printf("----------------------------------------\n");
    printf("APAGAR ARQUIVOS\n");
    printf("----------------------------------------\n");
    printf("Deseja realmente apagar todos os arquivos?s/n:");
    __fpurge(stdin);
    scanf("%c",&confirmar);
    confirmar=toupper(confirmar);
    validaResposta3(&confirmar);
    if(confirmar=='S'){
        if((fl=fopen(ARQUIVO,"wb"))==NULL){
        puts("Arquivo nao pode ser aberto");
        getchar();
        
        }
        else
        {
            fclose(fl);
            system("clear");
            printf("Arquivos apagados com sucesso\n");  
        }
    }
    else{
        printf("CANCELADA OPERACAO!!\n");
    }
}
//sintese
//Objetivo:alterar o nome do cadastro
//Parâmetros:nome do arquivo e a matricula do cadastro
//Retorno:Nenhum
void mudarnome(char ARQUIVO[30], int cadastro){
    FILE *fl;
    cad vetor;
    int tamanho=0;
    int cont=0;
    int posicao=0;
    // int x=0;
    // int z=0;
    // int y=0;
    cad auxiliar;
    if((fl=fopen(ARQUIVO,"r+b"))==NULL){
    puts("Arquivo nao pode ser aberto");
    getchar();
    
    }
    else
    { 
        while(fread(&vetor,sizeof(cad),1,fl)){
            if(cadastro==vetor.cnic){
                posicao=ftell(fl);
                auxiliar.cnic=vetor.cnic;
                strcpy(auxiliar.curso,vetor.curso);
                strcpy(auxiliar.escola,vetor.escola);
                auxiliar.modalidade=vetor.modalidade;  
                        
            }
              
        }
        rewind(fl);
        fseek(fl,posicao,SEEK_SET);
        
        fseek(fl,-sizeof(cad),SEEK_CUR);
       
        printf("digite o novo nome do curso:");
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
        barrazero(vetor.curso);
        vetor.cnic=auxiliar.cnic;
        strcpy(vetor.escola,auxiliar.escola);
        vetor.modalidade=auxiliar.modalidade;
        fwrite(&vetor,sizeof(cad),1,fl);
        fclose(fl);             
             
    }
}
//sintese
//Objetivo:Alterar a sigla da escola
//Parâmetros:nome do arquivo e a matricula do curso
//Retorno:Nenhum
void mudarSigla(char ARQUIVO[30], int cadastro){
    FILE *fl;
    cad vetor;
    int tamanho=0;
    int cont=0;
    cad auxiliar;
    int posicao=0;
    if((fl=fopen(ARQUIVO,"r+b"))==NULL){
    puts("Arquivo nao pode ser aberto");
    getchar();
    
    }
    else
    { 
        while(fread(&vetor,sizeof(cad),1,fl)){
            if(cadastro==vetor.cnic){
                posicao=ftell(fl);
                auxiliar.cnic=vetor.cnic;
                strcpy(auxiliar.curso,vetor.curso);
                strcpy(auxiliar.escola,vetor.escola);
                auxiliar.modalidade=vetor.modalidade;  
                
            }
              
        }
        rewind(fl);
        
        fseek(fl,posicao,SEEK_SET);
        
        fseek(fl,-sizeof(cad),SEEK_CUR);
        
        printf("Digite a nova sigla da escola:");
        __fpurge(stdin);
        fgets(vetor.escola,MAXSIGLA,stdin);
        barrazero(vetor.escola);
        validaSiglaEscola(vetor.escola);
        tamanho=strlen(vetor.curso);
        for(cont=0;cont<tamanho;cont++){
            vetor.escola[cont]=tolower(vetor.escola[cont]);
        }
        vetor.escola[0]=toupper(vetor.escola[0]);
        __fpurge(stdin);
        barrazero(vetor.escola);
        vetor.cnic=auxiliar.cnic;
        strcpy(vetor.curso,auxiliar.curso);
        vetor.modalidade=auxiliar.modalidade;
        fwrite(&vetor,sizeof(cad),1,fl);
        fclose(fl);   
    }
}
//sintese
//Objetivo:Alterar a modalidade
//Parâmetros:nome do arquivo matrucla do curso
//Retorno:Nenhum
void mudarModalidade( char ARQUIVO[30], int cadastro){
    FILE *fl;
    cad vetor;
    
    cad auxiliar;
    int posicao=0;
    if((fl=fopen(ARQUIVO,"r+b"))==NULL){
    puts("Arquivo nao pode ser aberto");
    getchar();
    
    }
    else
    {
         while(fread(&vetor,sizeof(cad),1,fl)){
            if(cadastro==vetor.cnic){
                posicao=ftell(fl);
                auxiliar.cnic=vetor.cnic;
                strcpy(auxiliar.curso,vetor.curso);
                strcpy(auxiliar.escola,vetor.escola);
                auxiliar.modalidade=vetor.modalidade;         
            }
              
        }
        rewind(fl);
        
        fseek(fl,posicao,SEEK_CUR);
        
        fseek(fl,-sizeof(cad),SEEK_CUR);
        printf("Digite a nova modalidade:");
        __fpurge(stdin);
        scanf("%c",&vetor.modalidade);
        vetor.modalidade=toupper(vetor.modalidade);
        validadeModalidade(&vetor.modalidade);
        vetor.cnic=auxiliar.cnic;
        strcpy(vetor.curso,auxiliar.curso);
        strcpy(vetor.escola,auxiliar.escola);
        fwrite(&vetor,sizeof(cad),1,fl);
        fclose(fl);
    }
}
//sintese
//Objetivo:Apagar a matricula
//Parâmetros:nome do arquivo matrucla do curso
//Retorno:Nenhum
void apagarMatricula(char ARQUIVO[30], int cadastro){
    FILE *fl;
    FILE *f;
    cad vetor;
     if ((fl=fopen(ARQUIVO,"rb"))==NULL){ 
        puts("Arquivo nao pode ser aberto.");
        getchar();
        
    }
    else {
        
        while(fread(&vetor,sizeof(cad),1,fl)){
            if(vetor.cnic!=cadastro){
                if((f=fopen("temporario.bin","ab"))==NULL){
                    puts("Arquivo nao pode ser aberto");
                    getchar();
                    
                }
                else{
                
                    fwrite(&vetor,sizeof(cad),1,f);
                    fclose(f);
                }
            }
        }
        fclose(fl);
        remove(ARQUIVO);
    }
    rename("temporario.bin",ARQUIVO);
}

       
     