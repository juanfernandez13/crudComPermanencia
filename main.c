#include <stdio.h>
#include <stdlib.h>

#include "Funcionarios.h"
#include "Dependentes.h"

/* IFCE - Campus Fortaleza
 * Engenharia de Computação - 1º Semestre

 * Trabalho feito em dupla
 * Juan Pablo e José Edilson

 */
int verificar_letras(char *j,int *t)
{

    if (*j>= 'a' && *j<='z' || *j >= 'A' && *j<='Z')
    {   //Valor aleatorio que nunca vai ser valido no programa
        *t = 156;
    }
    else
    {
        *t = atoi(j);

    }
};
int main()
{
    struct funcionario VFUN;
    struct dependente VDEN;

    FILE *FUN;
    FUN= fopen("funcionario.bin","rb+");
    if(FUN== NULL)
    {
        FUN= fopen("funcionario.bin","wb+");
        if (FUN== NULL)
        {
            printf("Ocorreu um erro na execução do programa\n");
        }
    }

    FILE *DEN;
    DEN = fopen("dependentes.bin","rb+");
    if(DEN == NULL)
    {
        DEN = fopen("dependentes.bin","wb+");
        if (DEN == NULL)
        {
            printf("Ocorreu um erro na execução do programa\n");
        }
    }

    for (int o = 0; o < 1; ++o) {
        int lugar;
        printf("O que voce deseja realizar\n");
        printf("1 - Entrar no menu dos funcionarios\n");
        printf("2 - Entrar no menu dos Dependentes\n");
        printf("3 - Sair\n");
        char p[1];
        scanf("%",&p);
        gets(p);
        verificar_letras(&p[0],&lugar);

        if(lugar == 1)
        {
            int funcao;
            printf("Bem-Vindo ao menu dos funcionario\n");

            do {
                printf("\nO que voce deseja realizar\n");
                printf("Digite 1 - Cadastrar um funcionario\n");
                printf("Digite 2 - Acessar o menu de listagem dos funcionario\n");
                printf("Digite 3 - Alterar os dados de algum funcionario\n");
                printf("Digite 4 - Excluir algum funcionario\n");
                printf("Digite 5 - Para sair\n");
                char p[1];
                scanf("%",&p);
                gets(p);
                verificar_letras(&p[0],&funcao);

                if (funcao == 1)
                {
                    cadastro_funcionario(FUN,DEN,VFUN,VDEN);
                    funcao = 0;
                }
                else if (funcao == 2)
                {
                    imprimir_funcionario(FUN,DEN,VFUN,VDEN);
                    funcao = 0;
                }
                else if (funcao == 3)
                {
                    alterar_funcionario(FUN,DEN,VFUN,VDEN);
                    funcao = 0;
                }
                else if(funcao == 4)
                {
                    excluir_funcionario(FUN,DEN,VFUN,VDEN);
                    funcao = 0;
                }
                else if (funcao == 5)
                {
                    funcao++;
                }
                else
                {
                    printf("Valor invalido\nTente novamente\n");
                    funcao = 0;
                }


            }while(funcao < 1);

            --o;
        }

        else if (lugar == 2)
        {
            int funcao;
            printf("Bem-Vindo ao menu dos dependentes\n");

            do {
                funcao = 0;
                printf("\nO que voce deseja realizar\n");
                printf("Digite 1 - Cadastrar um dependente\n");
                printf("Digite 2 - Acessar o menu de listagem dos dependentes\n");
                printf("Digite 3 - Alterar os dados de algum dependente\n");
                printf("Digite 4 - Excluir algum dependente\n");
                printf("Digite 5 - Para sair\n");

                char p[1];
                scanf("%",&p);
                gets(p);
                verificar_letras(&p[0],&funcao);

                if (funcao == 1)
                {
                    cadastro_dependente(DEN ,FUN,VDEN,VFUN);
                    funcao = 0;
                }
                else if (funcao == 2)
                {
                    imprimir_dependentes(DEN,FUN,VDEN);
                    funcao = 0;
                }
                else if (funcao == 3)
                {
                    alterar_dependentes(DEN,FUN,VDEN,VFUN);
                    funcao = 0;
                }
                else if(funcao == 4)
                {
                    excluir_dependentes(DEN,VDEN);
                    funcao = 0;
                }
                else if (funcao == 5)
                {
                    funcao++;
                }
                else
                {
                    printf("Valor invalido\nTente novamente\n");
                    funcao = 0;

                }


            }while(funcao < 1);


            --o;
        }
        else if(lugar == 3)
        {
            ++o;
        }
        else
        {
            printf("Valor invalido\nTente novamente\n");
            --o;
        }



    }
    fclose(DEN);
    fclose(FUN);

}
