#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include "Funcionarios.h"
#include "Dependentes.h"


/* IFCE - Campus Fortaleza
 * Engenharia de Computação - 1º Semestre

 * Trabalho feito em dupla
 * Juan Pablo e José Edilson

 */

int cadastro_dependente(FILE *DEN,FILE *FUN,struct dependente VDEN,struct funcionario VFUN)
{   fseek(DEN,0,SEEK_END);
    int verificador1;
    char verificador[12];
    char verificador2[100];

    for (int i = 0; i < 1; ++i)
    {


        fseek(DEN,0 , SEEK_SET);
        verificador1 = 1000;
        while (!feof(DEN))
        {
            fread(&VDEN, sizeof(struct dependente), 1, DEN);
            if ( verificador1 <= VDEN.codigo)
            { verificador1 = VDEN.codigo++;}

        }
    }
    printf("O seu codigo e %d\n",verificador1);
    printf("Digite o Nome do Dependente\n");
    fflush(stdin);scanf("%",&VDEN.nome);
    gets(verificador2);


    for (int i = 0; i < 1; ++i)
    {
        printf("Digite o CPF do Dependente\n");
        fflush(stdin); scanf("%", &VDEN.cpf);
        gets(verificador);

        if (strlen(verificador) != 11)
        {
            printf("O CPF deve ter 11 digitos\nInsira seu CPF corretamente\n");
            --i;
        }

        fseek(DEN,0 , SEEK_SET);
        while (!feof(DEN))
        {
            if(feof(DEN))
            {
                break;
            }
            fread(&VDEN, sizeof(struct dependente), 1, DEN);
            if (!feof(DEN) && strcmp(verificador,VDEN.cpf) == 0)
            {
                printf("CPF ja cadastrado\nTente Novamente\n");
                --i;
            }

        }


        fseek(FUN,0 , SEEK_SET);
        while (!feof(FUN))
        {
            if(feof(FUN))
            {
                break;
            }
            fread(&VFUN, sizeof(struct funcionario), 1, FUN);
            if (!feof(FUN) && strcmp(verificador,VFUN.cpf) == 0)
            {
                printf("CPF ja cadastrado\nTente Novamente\n");
                --i;
            }

        }

    }

    for (int i = 0; i < 1; ++i)
    {
        int existe_codigo = 0;
        printf("Digite o Codigo do Funcionario referente ao Dependente\n");
        fflush(stdin);
        scanf("%d", &VDEN.codigo_fun);

        if (VDEN.codigo_fun < 10000)
        {
            printf("O codigo do funcionario invalido\n");
            printf("Tente novamente\n\n");
            --i; continue;

        }

        fseek(FUN,0,SEEK_SET);
        while (!feof(FUN))
        {
            if (feof(FUN))
            {
                break;
            }
            fread(&VFUN, sizeof(struct funcionario), 1, FUN);
            if (VDEN.codigo_fun == VFUN.codigo)
            {
                ++existe_codigo;
            }
        }
        for (int j = 0; j < 1; ++j)
        {
            if (existe_codigo == 0)
            {
                printf("Nenhum funcionario cadastrado com esse codigo\n\n");

                printf("Deseja cadastrar mesmo assim?\n");
                printf("1 - Sim\n2 - Nao\n");
                scanf("%d", &existe_codigo);


                if (existe_codigo == 1)
                {
                    printf("Codigo cadastrado\n");
                    continue;
                }
                else if (existe_codigo == 2)
                {
                    --i;
                    continue;
                }
                else
                {
                    printf("Valor invalido\nTente novamente\n");
                    --i;
                }
            }

        }

    }


    for (int i = 0; i < 1; ++i) {

        printf("Digite o dia de nascimento do dependente\n");
        scanf("%d", &VDEN.dia);

        if (VDEN.dia > 31 || VDEN.dia < 1)
        {
            printf("Data invalida\nTente Novamente\n");
            --i; continue;
        }
        printf("Digite o mes de nascimento do dependente\n");
        scanf("%d", &VDEN.mes);

        if (VDEN.mes > 12 || VDEN.mes < 1)
        {
            printf("Data invalida\nTente Novamente\n");
            --i; continue;
        }

        printf("Digite o ano de nascimento do dependente\n");
        scanf("%d", &VDEN.ano);

        if (VDEN.ano > 2021 || VDEN.ano < 1900)
        {
            printf("Data invalida\nTente Novamente\n");
            --i; continue;
        }
    }



    printf("Digite o valor da ajuda de custo do dependente\n");
    fflush(stdin);scanf("%f",&VDEN.salario);

    for (int p = 0; p < 1 ; ++p) {
        int funcao;
        printf("Voce deseja cadastrar algum dado optativo ao Depedente\n");
        printf("Digite 1 - sim\nDigite 2 - nao\n");
        char x;
        scanf("%",&x);
        gets(x);
        verificar_letras(&x,&funcao);
        if (funcao != 1 && funcao != 2) {
            printf("Valor invalido\nTente novamente\n");
            --p;
            continue;
        }


        strcpy(VDEN.RG, "");
        strcpy(VDEN.endereco, "");
        strcpy(VDEN.sangue, "");
        if (funcao == 1) {

            for (int i = 0; i < 1; ++i) {
                printf("O que voce deseja cadastar ao funcionario\n");
                printf("Digite 1 - para cadastrar todos os dados optativos do dependente\n");
                if (strcmp(VDEN.RG,"") == 0){ printf("Digite 2 - RG do dependente\n"); }
                if (strcmp(VDEN.endereco,"") == 0)printf("Digite 3 - Endereco do dependente\n");
                if (strcmp(VDEN.sangue,"") == 0)printf("Digite 4 - Tipo sanguineo do dependente\n");
                printf("Digite 5 - Voltar ao Menu\n");
                char x[1];
                scanf("%",&x);
                gets(x);
                verificar_letras(&x[0],&funcao);

                if ((funcao == 4 && strcmp(VDEN.sangue,"") != 0) || (funcao == 3 && strcmp(VDEN.endereco,"") != 0) || (funcao == 2 && strcmp(VDEN.RG,"") != 0))
                {
                    printf("Valor invalido\nTente novamente\n\n");
                    --i;
                }

                if ((funcao == 1 || funcao == 2) && strcmp(VDEN.RG,"") == 0) {
                    printf("Digite o RG do funcionario\n");
                    fflush(stdin);
                    scanf("%", &VDEN.RG);
                    gets(VDEN.RG);
                    funcao == 2? printf("RG cadastrado com sucesso\n\n"),--i:printf("");
                }

                if ((funcao == 1 || funcao == 3) && strcmp(VDEN.endereco,"") == 0) {
                    printf("Digite o endereco do funcionario\n");
                    fflush(stdin);
                    scanf("%", &VDEN.endereco);
                    gets(VDEN.endereco);
                    funcao == 3? printf("Endereco cadastrado com sucesso\n\n"),--i:printf("");
                }

                if ((funcao == 1 ||funcao == 4) && strcmp(VDEN.sangue,"") == 0) {
                    for (int j = 0; j < 1; ++j) {
                        int sangue_num;
                        printf("Qual o seu tipo sanguineo?\n");
                        printf("Digite 1 - A+\n");
                        printf("Digite 2 - A-\n");
                        printf("Digite 3 - B+\n");
                        printf("Digite 4 - B-\n");
                        printf("Digite 5 - O+\n");
                        printf("Digite 6 - O-\n");
                        printf("Digite 7 - AB+\n");
                        printf("Digite 8 - AB-\n");
                        char x[1];
                        scanf("%",&x);
                        gets(x);
                        verificar_letras(&x[0],&sangue_num);

                        if (sangue_num == 1) {
                            strcpy(VDEN.sangue, "A+");
                        }
                        if (sangue_num == 2) {
                            strcpy(VDEN.sangue, "A-");
                        }
                        if (sangue_num == 3) {
                            strcpy(VDEN.sangue, "B+");
                        }
                        if (sangue_num == 4) {
                            strcpy(VDEN.sangue, "B-");
                        }
                        if (sangue_num == 5) {
                            strcpy(VDEN.sangue, "O+");
                        }
                        if (sangue_num == 6) {
                            strcpy(VDEN.sangue, "O-");
                        }
                        if (sangue_num == 7) {
                            strcpy(VDEN.sangue, "AB+");
                        }
                        if (sangue_num == 8) {
                            strcpy(VDEN.sangue, "AB-");
                        }
                        if (sangue_num > 8 || sangue_num < 1) {
                            printf("Valor invalido\nTente novamente\n\n");
                            --j;
                        }
                    }
                    funcao == 4? printf("Tipo sanguineo cadastrado com sucesso\n\n"),--i:printf("");

                }
                if (funcao < 1 || funcao > 5)
                {
                    printf("Valor invalido\nTente novamente\n\n");
                    --i;
                }
                if (strcmp(VDEN.sangue,"") != 0 && strcmp(VDEN.endereco,"") != 0 && strcmp(VDEN.RG,"") != 0) {
                    printf("Todos os dados optativos foram cadastrados com sucesso\n\n"); break;}

            }


        }
    }

    VDEN.codigo = verificador1;
    strcpy(VDEN.nome,verificador2);
    strcpy(VDEN.cpf,verificador);

    fseek(DEN,0,SEEK_END);
    fwrite(&VDEN, sizeof (struct dependente), 1, DEN);

}


int imprimir_dependentes(FILE *DEN,FILE *FUN,struct dependente VDEN)
{
    /////////////////////////////////////////////////////////////////////////////////////////////
    /*Area que verifica se existe algum dependente cadastrado
     * Se baseia em uma verificação na quantidade de digitos do CPF
     * Caso nao exista nenhum cadastrado o CPF deve ter uma quantidade de caracteres diferente de 11
     * tendo em vista que no cadastro só é possível cadastrar um CPF com 11 digitos*/
    fseek(DEN,0,SEEK_SET);
    fread(&VDEN, sizeof(struct dependente),1,DEN);
    if( strlen(VDEN.cpf) !=11)
    {
        printf("Nao e possivel realizar essa operacao\nNenhum dependente cadastrado\n");
    }
        /////////////////////////////////////////////////////////////////////////////////////////////

    else {
        int funcao;
        do {

            printf("O que voce deseja realizar? \n");
            printf("1 - Listar os dados de um Dependentes \n");
            printf("2 - Listar todos os Dependentes \n");
            printf("3 - Listar todos os Dependentes em ordem alfabetica\n");
            printf("4 - Voltar ao Menu\n");
            char x[1];
            scanf("%",&x);
            gets(x);
            verificar_letras(&x[0],&funcao);

            if (funcao == 1) {
                int verificador;
                printf("Digite o codigo do cliente\n");
                fflush(stdin);
                char x[1];
                scanf("%",&x);
                gets(x);
                verificar_letras(&x[0],&verificador);

                fseek(DEN, 0, SEEK_SET);
                while (!feof(DEN)) {
                    if (feof(DEN)) {
                        break;
                    }
                    fread(&VDEN, sizeof(struct dependente), 1, DEN);
                    if (!feof(DEN) && verificador == VDEN.codigo) {
                        funcao = 1;
                        printf("\nNome do Dependente: %s\nCodigo do Dependente: %d\n", VDEN.nome, VDEN.codigo);
                        printf("CPF do Dependente: " );
                        for (int i = 0; i < 11; ++i) {
                            if (i<9)
                            {
                                printf("%c",VDEN.cpf[i]);
                                if ((i+1)%3 == 0 && i !=8)
                                {
                                    printf(".");
                                }
                            }
                            if (8<i)
                            {
                                if (i == 9){
                                    printf("-");
                                }
                                printf("%c",VDEN.cpf[i]);
                            }
                        }
                        printf("\nCodigo do Funcionario: %d\n", VDEN.codigo_fun);
                        printf("Data de nascimento: ");
                        VDEN.dia < 10? printf("0%d/", VDEN.dia) : printf("%d/", VDEN.dia);
                        VDEN.mes < 10? printf("0%d/", VDEN.mes) : printf("%d/", VDEN.mes);
                        printf("%d\n", VDEN.ano);
                        printf("Auxilio de custo do Dependente: %.2f\n", VDEN.salario);
                        if (strcmp(VDEN.RG, "") != 0) { printf("RG do Dependente: %s\n", VDEN.RG); }
                        if (strcmp(VDEN.endereco, "") != 0) { printf("Endereco do Dependente: %s\n", VDEN.endereco); }
                        if (strcmp(VDEN.sangue, "") != 0) { printf("Tipo sanguineo do Dependente: %s\n", VDEN.sangue); }
                        printf("\n"); break;
                    }
                    else
                    {
                        funcao = 0;
                    }
                }
                if (funcao == 0)
                {
                    printf("Codigo nao cadastrado\nVoce sera redirecionado ao menu\n\n");
                }
                //A variavel funcao é zerada para manter o lanço do-while
                funcao = 0;

            } else if (funcao == 2) {
                fseek(DEN, 0, SEEK_SET);
                while (!feof(DEN)) {
                    fread(&VDEN, sizeof(struct dependente), 1, DEN);
                    if (feof(DEN)) {
                        break;
                    }
                    printf("\nNome do Dependente: %s\nCodigo do Dependente: %d\n", VDEN.nome, VDEN.codigo);
                    printf("CPF do Dependente: " );
                    for (int i = 0; i < 11; ++i) {
                        if (i<9)
                        {
                            printf("%c",VDEN.cpf[i]);
                            if ((i+1)%3 == 0 && i !=8)
                            {
                                printf(".");
                            }
                        }
                        if (8<i)
                        {
                            if (i == 9){
                                printf("-");
                            }
                            printf("%c",VDEN.cpf[i]);
                        }
                    }
                    printf("\nCodigo do Funcionario: %d\n", VDEN.codigo_fun);
                    printf("Data de nascimento: ");
                    VDEN.dia < 10? printf("0%d/", VDEN.dia) : printf("%d/", VDEN.dia);
                    VDEN.mes < 10? printf("0%d/", VDEN.mes) : printf("%d/", VDEN.mes);
                    printf("%d\n", VDEN.ano);
                    printf("Auxilio de custo do Dependente: %.2f\n", VDEN.salario);
                    if (strcmp(VDEN.RG, "") != 0) { printf("RG do Dependente: %s\n", VDEN.RG); }
                    if (strcmp(VDEN.endereco, "") != 0) { printf("Endereco do Dependente: %s\n", VDEN.endereco); }
                    if (strcmp(VDEN.sangue, "") != 0) { printf("Tipo sanguineo do Dependente: %s\n", VDEN.sangue); }
                    printf("\n");
                }
                funcao = 0;
            } else if (funcao == 3) {
                int posicao = 0;

                fseek(DEN, 0, SEEK_SET);
                //serve apenas para saber quantos nomes existem
                for (int i = 0; i < feof(DEN) + 1; ++i) {
                    if (feof(DEN)) {
                        break;
                    }
                    fread(&VDEN, sizeof(struct dependente), 1, DEN);
                    if (!feof(DEN)) {
                        --i;
                        posicao++;
                    }
                }

                char nome[posicao][255];
                int codigo[posicao];
                //Depois de descobrir a quantidade de nomes
                //essa parte serve para tirar os nomes do arquivo e colocar na ram
                fseek(DEN, 0, SEEK_SET);
                for (int i = 0; i < posicao; ++i) {
                    if (feof(DEN)) {
                        break;
                    }
                    fread(&VDEN, sizeof(struct dependente), 1, DEN);
                    if (!feof(DEN)) {
                        strcpy(nome[i], VDEN.nome);
                        codigo[i] = VDEN.codigo;
                    }
                }

                // Ordenando os nomes
                for (int i = 0; i < posicao; ++i) {
                    for (int j = 0; j < posicao - 1; ++j) {
                        //Usando o comando toupper para que o primeiro caractere fique maiusculo e assim a
                        //no momento da verificação o fator de letras maiusculas e minusculas não atrapalhem na ordenação
                        nome[i][0] = toupper(nome[i][0]);
                        nome[j][0] = toupper(nome[j][0]);
                        if (strcmp(nome[i], nome[j]) < 0) {
                            char auxiliar[255];
                            strcpy(auxiliar, nome[j]);
                            strcpy(nome[j], nome[i]);
                            strcpy(nome[i], auxiliar);

                        }
                    }
                }
                //imprimindo os nomes
                for (int i = 0; i < posicao; ++i) {
                    printf("Nome do Funcionario: %s\n", nome[i]);
                }
                //A variavel funcao é zerada para manter o lanço do-while
                funcao = 0;
            } else if (funcao == 4) {
                //A variavel funcao é incrementada para quebrar o lanço do-while
                funcao++;
            } else {
                printf("Valor invalido\nTente novamente\n");
                //A variavel funcao é zerada para manter o lanço do-while
                funcao = 0;
            }

        } while (funcao < 1);
    }
}


int alterar_dependentes(FILE *DEN,FILE *FUN,struct dependente VDEN,struct funcionario VFUN)
{
    /*Area que verifica se existe algum dependente cadastrado
    * Se baseia em uma verificação na quantidade de digitos do CPF
    * Caso nao exista nenhum cadastrado o CPF deve ter uma quantidade de caracteres diferente de 11
    * tendo em vista que no cadastro só é possível cadastrar um CPF com 11 digitos*/

            fseek(DEN,0,SEEK_SET);
            fread(&VDEN, sizeof(struct dependente),1,DEN);
            if( strlen(VDEN.cpf) !=11)
            {
                printf("Nao e possivel realizar essa operacao\nNenhum funcionario cadastrado\n");
            }
                /////////////////////////////////////////////////////////////////////////////////////////////
            else {
                int indicador = 0;
                int verificando;
                printf("digite o codigo do dependente\n");
                char x[1];
                scanf("%",&x);
                gets(x);
                verificar_letras(&x[0],&verificando);
                int salva_verificador = verificando;

                fseek(DEN, 0, SEEK_SET);

                while (!feof(DEN)) {
                    if (feof(DEN)) {
                        break;
                    }
                    fread(&VDEN, sizeof(struct dependente), 1, DEN);

                    if (!feof(DEN) && verificando == VDEN.codigo) {
                        fseek(DEN, -1 * sizeof(struct dependente), SEEK_CUR);
                        for (int i = 0; i < 1; ++i)
                        {
                            char nome[100];
                            char CPF[12];
                            float salario;
                            int dia, mes, ano;
                            char RG[15];
                            char endereco[255];
                            char sangue[4];
                            int cod_fun;
                            //Menu da parte de alterar os dados de um funcionario

                            printf("O que voce deseja alterar no dependente?\n");
                            printf("Digite 1 - para alterar todos os dados de um dependente\n");
                            printf("Digite 2 - para alterar o nome do dependente\n");
                            printf("Digite 3 - para alterar o CPF do dependente\n");
                            printf("Digite 4 - para alterar a ajuda de custo do dependente\n");
                            printf("Digite 5 - para alterar a data de dependente\n");


                            printf("Digite 6 - para ");
                            //Caso não exista nenhuma informação para o RG o programa vai dar a opção de inserir um dado
                            //se ele existir o programa vai dar a opção de alterar
                            //isso também vale para os outros dados optativos
                            strcmp(VDEN.RG,"")!= 0? printf("alterar") : printf("inserir");
                            printf(" o RG do dependente\n");

                            printf("Digite 7 - para ");
                            strcmp(VDEN.endereco,"")!= 0? printf("alterar") : printf("inserir");
                            printf(" o endereco do dependente\n");

                            printf("Digite 8 - para ");
                            strcmp(VDEN.sangue,"")!= 0? printf("alterar") : printf("inserir");
                            printf(" o tipo sanguineo do dependente\n");

                            printf("Digite 9 - para alterar o codigo do funcionario referente ao dependente\n");

                            printf("Digite 10 - para sair\n");
                            char x[1];
                            scanf("%",&x);
                            gets(x);
                            verificar_letras(&x[0],&indicador);
                            if (indicador == 1 || indicador == 2) {
                                printf("Digite o novo nome do dependente\n");
                                scanf("%", &nome);
                                gets(nome);
                                //Caso o usuario altere apenas o nome, será impresso uma mensagem sinalizando a alteração
                                indicador == 2? printf("\nNome alterado com sucesso\n"),--i: printf("");

                            }
                            if (indicador == 1 || indicador == 3)
                            {
                                for (int j = 0; j < 1; ++j) {
                                    int p = 0;
                                    printf("Digite o novo CPF do dependente\n");
                                    scanf("%", &VDEN.cpf);
                                    gets(CPF);

                                    if (strlen(CPF) != 11)
                                    {
                                        printf("O CPF deve ter 11 digitos\nInsira seu CPF corretamente\n");
                                        --j;  p = 1; continue;
                                    }
                                    //Verifica a existencia de um cpf repetido
                                    //caso exista um cpf repetido o programa vai pedir para inserir novamente
                                    fseek(DEN,0 , SEEK_SET);
                                    while (!feof(DEN))
                                    {
                                        if(feof(DEN))
                                        {
                                            break;
                                        }
                                        fread(&VDEN, sizeof(struct dependente), 1, DEN);
                                        if (!feof(DEN) && strcmp(CPF,VDEN.cpf) == 0)
                                        {
                                            printf("CPF ja cadastrado\nTente Novamente\n");
                                            --j;  p = 1;
                                            break;
                                        }

                                    }

                                    fseek(FUN,0 , SEEK_SET);
                                    while (!feof(FUN))
                                    {
                                        if(feof(FUN))
                                        {
                                            break;
                                        }
                                        fread(&VFUN, sizeof(struct funcionario), 1, FUN);
                                        if (!feof(FUN) && strcmp(CPF,VFUN.cpf) == 0)
                                        {
                                            printf("CPF ja cadastrado\nTente Novamente\n");
                                            --j;  p = 1;
                                            break;
                                        }

                                    }
                                    //Caso o usuario altere apenas o CPF, será impresso uma mensagem sinalizando a alteração
                                    indicador == 3 && p == 0? printf("\nCPF alterado com sucesso\n"), --i  : printf("");


                                }


                            }
                            if (indicador == 1 || indicador == 4)
                            {
                                printf("Digite o valor da ajuda de custo do dependente\n");
                                scanf("%f",&salario);
                                //Caso o usuario altere apenas o salario, será impresso uma mensagem sinalizando a alteração
                                indicador == 4? printf("\nAjuda de custo alterada com sucesso\n"), --i  : printf("");

                            }
                            if (indicador == 1 || indicador == 5)
                            {
                                for (int j = 0; j < 1; ++j)
                                {
                                    printf("Digite o dia do nascimento do dependente\n");
                                    fflush(stdin);
                                    scanf("%d", &dia);

                                    if (dia > 31 || dia < 1)
                                    {
                                        printf("Data invalida\nTente Novamente\n");
                                        --j; continue;
                                    }

                                    printf("Digite o mes do nascimento do dependente\n");
                                    fflush(stdin);
                                    scanf("%d", &mes);

                                    if (mes > 12 || mes < 1)
                                    {
                                        printf("Data invalida\nTente Novamente\n");
                                        --j; continue;
                                    }

                                    printf("Digite o ano do nascimento do dependente\n");
                                    fflush(stdin);
                                    scanf("%d", &ano);
                                    if (ano > 2021 || ano < 1900)
                                    {
                                        printf("Data invalida\nTente Novamente\n");
                                        --j; continue;
                                    }
                                }
                                //Caso o usuario altere apenas o data de nascimento, será impresso uma mensagem sinalizando a alteração
                                indicador == 5? printf("\nData de nascimento alterada com sucesso\n"), --i  : printf("");
                            }
                            if ((indicador == 1 && strcmp(VDEN.RG,"")!= 0 || indicador == 6) )
                            {
                                printf("Digite o RG do dependente\n");
                                fflush(stdin);scanf("%",&VDEN.RG);
                                gets(RG);
                                // Se existir alguma informação na variavel VDEN.RG sera impresso uma mensagem informado o RG foi alterado
                                //Caso contrario sera impresso que o RG foi inserido
                                indicador == 6? strcmp(VDEN.RG,"")== 0? printf("\nRG inserido com sucesso\n"), --i : printf("\nRG alterado com sucesso\n"), --i  : printf("");
                            }
                            if ((indicador == 1 && strcmp(VDEN.endereco,"") != 0 || indicador == 7) )
                            {
                                printf("Digite o endereco do dependente\n");
                                scanf("%",&VDEN.endereco);
                                gets(endereco);
                                // Se existir alguma informação na variavel VDEN.endereco sera impresso uma mensagem informado o endereço foi alterado
                                //Caso contrario sera impresso que o endereço foi inserido
                                indicador == 7? strcmp(VDEN.endereco,"") == 0?  printf("\nendereco inserido com sucesso\n"), --i : printf("\nendereco alterado com sucesso\n"), --i  : printf("");
                            }

                            if ((indicador == 1 && strcmp(VDEN.sangue,"") != 0|| indicador == 8) )
                            {

                                for (int j = 0; j < 1; ++j) {
                                    int sangue_num;
                                    printf("Qual o seu tipo sanguineo?\n");
                                    printf("Digite 1 - A+\n");
                                    printf("Digite 2 - A-\n");
                                    printf("Digite 3 - B+\n");
                                    printf("Digite 4 - B-\n");
                                    printf("Digite 5 - O+\n");
                                    printf("Digite 6 - O-\n");
                                    printf("Digite 7 - AB+\n");
                                    printf("Digite 8 - AB-\n");
                                    char x[1];
                                    scanf("%",&x);
                                    gets(x);
                                    verificar_letras(&x[0],&sangue_num);
                                    if (sangue_num == 1) {
                                        strcpy(sangue, "A+");
                                    }
                                    if (sangue_num == 2) {
                                        strcpy(sangue, "A-");
                                    }
                                    if (sangue_num == 3) {
                                        strcpy(sangue, "B+");
                                    }
                                    if (sangue_num == 4) {
                                        strcpy(sangue, "B-");
                                    }
                                    if (sangue_num == 5) {
                                        strcpy(sangue, "O+");
                                    }
                                    if (sangue_num == 6) {
                                        strcpy(sangue, "O-");
                                    }
                                    if (sangue_num == 7) {
                                        strcpy(sangue, "AB+");
                                    }
                                    if (sangue_num == 8) {
                                        strcpy(sangue, "AB-");
                                    }
                                    if (sangue_num < 1 || sangue_num > 8) {
                                        printf("Valor invalido\nTente novamente\n");
                                        --j;
                                    }
                                    // Se existir alguma informação na variavel VDEN.sangue sera impresso uma mensagem informado o sangue foi alterado
                                    //Caso contrario sera impresso que o sangue foi inserido
                                    indicador == 8 ? strcmp(VDEN.sangue,"") == 0?  printf("\nTipo sanguineo inserido com sucesso\n"), --i : printf("\nTipo sanguineo alterado com sucesso\n"), --i  : printf("");
                                }
                            }

                            if (indicador == 1 || indicador == 9)
                            {
                                for (int k = 0; k < 1; ++k)
                                {
                                    int existe_codigo = 0;
                                    printf("Digite o Codigo do Funcionario referente ao Dependente\n");
                                    fflush(stdin);
                                    scanf("%d", &cod_fun);

                                    if (cod_fun < 10000)
                                    {
                                        printf("O codigo do funcionario invalido\n");
                                        printf("Tente novamente\n\n");
                                        --k; continue;

                                    }

                                    fseek(FUN,0,SEEK_SET);
                                    while (!feof(FUN))
                                    {
                                        if (feof(FUN))
                                        {
                                            break;
                                        }
                                        fread(&VFUN, sizeof(struct funcionario), 1, FUN);
                                        if (cod_fun == VFUN.codigo)
                                        {
                                            ++existe_codigo;
                                        }
                                    }
                                    for (int j = 0; j < 1; ++j)
                                    {
                                        if (existe_codigo == 0)
                                        {
                                            printf("Nenhum funcionario cadastrado com esse codigo\n\n");

                                            printf("Deseja cadastrar mesmo assim?\n");
                                            printf("1 - Sim\n2 - Nao\n");
                                            char x[1];
                                            scanf("%",&x);
                                            gets(x);
                                            verificar_letras(&x[0],&existe_codigo);

                                            if (existe_codigo == 1)
                                            {

                                                continue;
                                            }
                                            else if (existe_codigo == 2)
                                            {
                                                --k;
                                                continue;
                                            }
                                            else
                                            {
                                                printf("Valor invalido\nTente novamente\n");
                                                --k;
                                            }
                                        }

                                    }

                                }

                                indicador == 9? printf("Codigo do funcionario referente ao dependente foi alterado com sucesso\n"),--i:printf("");

                            }
                            indicador == 1?  printf("\nDados alterados com sucesso\n"): printf("");

                            /*Area responsavel por escrever as informações que o usuario digitou no arquivo dependentes.bin */
                            fseek(DEN, 0, SEEK_SET);
                            while (!feof(DEN)) {
                                if (feof(DEN)) {
                                    break;
                                }
                                fread(&VDEN, sizeof(struct dependente), 1, DEN);
                                if (!feof(DEN) && salva_verificador == VDEN.codigo) {
                                    fseek(DEN, -1 * sizeof(struct dependente), SEEK_CUR);
                                    if (indicador == 1 || indicador == 2) {strcpy(VDEN.nome, nome);}

                                    if (indicador == 1 || indicador == 3) {strcpy(VDEN.cpf, CPF);}

                                    if (indicador == 1 || indicador == 4) {VDEN.salario = salario;}

                                    if (indicador == 1 || indicador == 5){VDEN.dia = dia; VDEN.mes = mes; VDEN.ano = ano;}

                                    if ((indicador == 1 && strcmp(VDEN.RG,"") != 0 || indicador == 6) ){strcpy(VDEN.RG, RG);}

                                    if ((indicador == 1 && strcmp(VDEN.endereco,"") != 0 || indicador == 7) ){strcpy(VDEN.endereco,endereco);}

                                    if ((indicador == 1 && strcmp(VDEN.sangue,"") != 0 || indicador == 8) ){strcpy(VDEN.sangue, sangue);}

                                    if (indicador == 1 || indicador == 9){VDEN.codigo_fun = cod_fun;}

                                    fwrite(&VDEN, sizeof(struct dependente), 1, DEN);
                                    break;

                                }
                            }


                            if (indicador == 1 || indicador == 10) { break; }
                            if(indicador > 10 || indicador < 1){printf("Valor invalido\nTente novamente\n\n");--i;}
                        } break;
                    }

                }

                if (indicador == 0)
                {
                    printf("Codigo nao cadastrado\n");
                }
            }
}



int excluir_dependentes(FILE *DEN,struct dependente VDEN)
{
    /*Area que verifica se existe algum dependente cadastrado
* Se baseia em uma verificação na quantidade de digitos do CPF
* Caso nao exista nenhum cadastrado o CPF deve ter uma quantidade de caracteres diferente de 11
* tendo em vista que no cadastro só é possível cadastrar um CPF com 11 digitos*/

    fseek(DEN,0,SEEK_SET);
    fread(&VDEN, sizeof(struct dependente),1,DEN);
    if( strlen(VDEN.cpf) !=11)
    {
        printf("Nao e possivel realizar essa operacao\nNenhum dependente cadastrado\n");
    }
        /////////////////////////////////////////////////////////////////////////////////////////////
    else
    {
        int excluido; int indicador = 0;
        printf("digite o codigo do dependente que sera excluido\n");
        scanf("%d",&excluido);
        int salvar_excluido = excluido;

        fseek(DEN,0,SEEK_SET);
        while (!feof(DEN))
        {
            if (feof(DEN))
            {
                break;

            }
            else
            {
                fread(&VDEN, sizeof(struct dependente), 1, DEN);
                if (!feof(DEN) && excluido == VDEN.codigo) { ++indicador; break;}
            }
        }

        if (indicador != 0)
        {
            for (int i = 0; i < 1; ++i)
            {
                //Menu da area responsavel pela exclusão de dados
                printf("O que voce deseja excluir?\n");
                printf("Digite 1 - para excluir todos os dados do dependente\n");
                //A opção de excluir dados optativos so aparece caso o dependente tenha pelo menos 1
                //dado optativo cadastrado
                if (strcmp(VDEN.sangue,"") !=0 || strcmp(VDEN.RG,"") !=0 || strcmp(VDEN.endereco,"") !=0 ) {
                    printf("Digite 2 - para excluir algum dado optativo do dependente \n");
                }
                //para sair é usado um incremento na variavel i para quebrar o laço for
                printf("Digite 3 - para sair\n");
                char x[1];
                scanf("%",&x);
                gets(x);
                verificar_letras(&x[0],&indicador);

                if (indicador == 1)
                {
                    //Para excluir um novo arquivo é criado
                    //após isso, todas as informações do arquivo de dependentes são copiados para o arquivo auxiliar
                    //com exceção do dependente que deve ser excluido
                    //depois disso o arquivo dos dependentes é fechado e aberto utilizando o wb+
                    //todas as informações do arquivo auxiliar vão para o arquivo de dependentes (assim eliminando o dependente desejado)
                    //por fim, o arquivo auxiliar é zerado utilizando o mesmo processo.
                    FILE *a;
                    struct dados {
                        int cod_fun;
                        char nome[100];
                        int codigo;
                        char cpf[12];
                        int dia;
                        int mes;
                        int ano;
                        float salario;
                        char RG[15];
                        char endereco[255];
                        char sangue[4];
                    } dados;
                    a = fopen("auxiliar.bin", "wb+");
                    fseek(DEN, 0, SEEK_SET);
                    fseek(a, 0, SEEK_END);

                    while (!feof(DEN)) {
                        if (feof(DEN)) {
                            break;

                        } else {
                            fread(&VDEN, sizeof(struct dependente), 1, DEN);
                            if (!feof(DEN) && salvar_excluido != VDEN.codigo) {
                                dados.cod_fun = VDEN.codigo_fun;
                                strcpy(dados.nome, VDEN.nome);
                                dados.codigo = VDEN.codigo;
                                strcpy(dados.cpf, VDEN.cpf);
                                dados.dia = VDEN.dia;
                                dados.mes = VDEN.mes;
                                dados.ano = VDEN.ano;
                                dados.salario = VDEN.salario;
                                strcpy(dados.RG, VDEN.RG);
                                strcpy(dados.endereco, VDEN.endereco);
                                strcpy(dados.sangue, VDEN.sangue);
                                fwrite(&dados, sizeof(struct dados), 1, a);
                            }
                        }
                    }
                    fclose(DEN);
                    DEN = fopen("dependentes.bin", "wb+");

                    fseek(a, 0, SEEK_SET);
                    fseek(DEN, 0, SEEK_END);

                    while (!feof(a)) {

                        if (feof(a)) {
                            break;
                        }
                        fread(&dados, sizeof(struct dados), 1, a);
                        if (!feof(a)) {

                            VDEN.codigo_fun = dados.cod_fun;
                            strcpy(VDEN.nome, dados.nome);
                            VDEN.codigo = dados.codigo;
                            strcpy(VDEN.cpf, dados.cpf);
                            VDEN.dia = dados.dia;
                            VDEN.mes = dados.mes;
                            VDEN.ano = dados.ano;
                            VDEN.salario = dados.salario;
                            strcpy(VDEN.RG, dados.RG);
                            strcpy(VDEN.endereco, dados.endereco);
                            strcpy(VDEN.sangue, dados.sangue);
                            fwrite(&VDEN, sizeof(struct dependente), 1, DEN);
                        }

                    }

                    fclose(a);
                    a = fopen("auxiliar.bin", "wb+");
                    fclose(a);
                    printf("\nDependente excluido com sucesso\n");
                }

                else if (indicador == 2 && (strcmp(VDEN.sangue,"") != 0 || strcmp(VDEN.RG,"") != 0 || strcmp(VDEN.endereco,"") != 0 ))
                {
                    for (int j = 0; j < 1; ++j)
                    {
                        char RG[15];
                        char endereco[255];
                        char sangue[4];
                        printf("O que voce deseja excluir?\n");
                        printf("Digite 1 - para excluir todos os dados optativos do dependente\n");
                        //So sera impresso as opções de excluir apenas as informações que o funcionario possuir
                        if(strcmp(VDEN.RG,"") !=0 ){ printf("Digite 2 - para excluir o RG do dependente\n"); }
                        if (strcmp(VDEN.endereco,"") !=0){ printf("Digite 3 - para excluir o endereco do dependente\n"); }
                        if (strcmp(VDEN.sangue,"") !=0){ printf("Digite 4 - para excluir o tipo sanguineo do dependente\n"); }
                        printf("Digite 5 - para sair\n");
                        char x[1];
                        scanf("%",&x);
                        gets(x);
                        verificar_letras(&x[0],&indicador);

                        if((indicador == 1 || indicador == 2)  && strcmp(VDEN.RG,"") !=0 )
                        {
                            strcpy(RG,"\0");
                            indicador == 2? printf("RG do dependente foi excluido\n"), --j : printf("");

                        }
                        else if((indicador == 1 || indicador == 3 ) && strcmp(VDEN.endereco,"") !=0)
                        {
                            strcpy(endereco,"\0");
                            indicador == 3? printf("endereco do dependente foi excluido\n"), --j : printf("");
                            strcpy(VDEN.endereco,"\0");
                        }
                        else if((indicador == 1 || indicador == 4 ) && strcmp(VDEN.sangue,"") !=0)
                        {
                            strcpy(sangue,"\0");
                            indicador == 4? printf("Tipo sanguineo do dependente foi excluido\n"), --j : printf("");
                        }
                        else if (indicador == 5)
                        {
                            ++j;
                        }
                        else
                        {
                            printf("Valor invalido\nTente novamnete\n");
                            --j;
                        }

                        indicador == 1? printf("todos os dados optativos do dependente foram excluidos\n"):printf("");

                        fseek(DEN, 0, SEEK_SET);
                        while (!feof(DEN)) {
                            if (feof(DEN)) {
                                break;
                            }
                            //Area responsavel por copiar "\0" para a variavel que for excluida
                            fread(&VDEN, sizeof(struct dependente), 1, DEN);
                            if (!feof(DEN) && salvar_excluido == VDEN.codigo) {
                                fseek(DEN, -1 * sizeof(struct dependente), SEEK_CUR);
                                if ((indicador == 1 || indicador == 2) && strcmp(VDEN.RG,"\0") !=0 ) {strcpy(VDEN.RG, RG);}

                                if ((indicador == 1 || indicador == 3) && strcmp(VDEN.endereco,"\0") !=0 ) {strcpy(VDEN.endereco,"\0");}

                                if ((indicador == 1 || indicador == 4) && strcmp(VDEN.sangue,"\0") !=0 ) {strcpy(VDEN.sangue,sangue);}

                                fwrite(&VDEN, sizeof(struct dependente), 1, DEN);
                                break;

                            }
                        }
                    }
                }
                else if (indicador == 3)
                {
                    ++i;
                }
                else
                {
                    printf("Valor invalido\nTente novamente\n");
                    --i;
                }
            }
        }
        else
        {
            printf("\nCodigo nao cadastrado\nVoce sera redirecionado ao menu\n");
        }

    }

}
