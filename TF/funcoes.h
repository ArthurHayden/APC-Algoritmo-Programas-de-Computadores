#pragma once
#include<string.h>
#include <stdlib.h>
#include<stdio_ext.h>
#include"struct.h"
#include <ctype.h>
void telainicial();
void telacadastro();
void telaAlterar();
void telalistar();
void telaconsulta();
void barrazero(char *palavra);
void espacoEmBranco(char *branco);
int validacnic(int cnic, char ARQUIVO[30]);
int validaCnic100(int cnic);
void validaNomecurso(char *curso);
void validaSiglaEscola(char *Sescola);
void validadeModalidade(char *modalidade);
void validaResposta4(char *res2);
void validaResposta3(char *opcao3);
void validaresposta2(char *resposta2);
void validaResposta(int *opcao2);
int validaOpcao(int opcao, char ARQUIVO[30]);
void ordenarCurso(char ARQUIVO[30]);
void ordenarSigla(char ARQUIVO[30]);
void apagar(char ARQUIVO[30]);
void validaOpcao2(int *opcao4);
void mudarnome(char ARQUIVO[30], int cadastro);
void mudarSigla(char ARQUIVO[30], int cadastro);
void mudarModalidade( char ARQUIVO[30],int cadastro);
void apagarMatricula(char ARQUIVO[30], int cadastro);
    

