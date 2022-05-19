/* IFCE - Campus Fortaleza
 * Engenharia de Computação - 1º Semestre

 * Trabalho feito em dupla
 * Juan Pablo e José Edilson

 */

struct funcionario
{
    char nome[100];
    int codigo;
    char cpf[12];
    int dia;
    int mes;
    int ano;
    float salario;
    float auxilio;
    char RG[15];
    char endereco[255];
    char sangue[4];

};

struct dependente
{
    char nome[100];
    int codigo;
    int codigo_fun;
    char cpf[12];
    int dia;
    int mes;
    int ano;
    float salario;
    int auxilio;
    char RG[15];
    char endereco[255];
    char sangue[4];

};

int cadastro_funcionario(FILE *FUN,FILE *DEN,struct funcionario VFUN,struct dependente VDEN);
int imprimir_funcionario(FILE *FUN,FILE *DEN,struct funcionario VFUN,struct dependente VDEN);
int alterar_funcionario(FILE *FUN,FILE *DEN,struct funcionario VFUN,struct dependente VDEN);
int excluir_funcionario(FILE *FUN,FILE *DEN,struct funcionario VFUN,struct dependente VDEN);
int verificar_letras(char *j,int *t);