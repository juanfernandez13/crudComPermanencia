/* IFCE - Campus Fortaleza
 * Engenharia de Computação - 1º Semestre

 * Trabalho feito em dupla
 * Juan Pablo e José Edilson

 */

int cadastro_dependente(FILE *DEN,FILE *FUN,struct dependente VDEN,struct funcionario VFUN);
int imprimir_dependentes(FILE *DEN,FILE *FUN,struct dependente VDEN);
int alterar_dependentes(FILE *DEN,FILE *FUN,struct dependente VDEN,struct funcionario VFUN);
int excluir_dependentes(FILE *DEN,struct dependente VDEN);
