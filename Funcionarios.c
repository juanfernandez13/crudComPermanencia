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

int cadastro_funcionario(FILE *FUN,FILE *DEN,struct funcionario VFUN,struct dependente VDEN)
{   fseek(FUN,0,SEEK_END);
    int verificador1;
    char verificador[12];
    char verificador2[100];

    for (int i = 0; i < 1; ++i)
    {


        fseek(FUN,0 , SEEK_SET);
        verificador1 = 10000;
        while (!feof(FUN))
        {
            fread(&VFUN, sizeof(struct funcionario), 1, FUN);
            if ( verificador1 <= VFUN.codigo)
            { verificador1 = VFUN.codigo++;}

        }
    }
    printf("O seu codigo e %d\n",verificador1);
    printf("Digite o Nome do funcionario\n");
    fflush(stdin);scanf("%",&VFUN.nome);
    gets(verificador2);
/////////////////////////////////////////////////////////////////////////////////////////////
    /*Area de Verificar CPF
     * Se baseia na verificação do cpf digitado pelo usuário
     * caso exista algum CPF repetido no arquivo dos funcionario ou dependentes
     * sera anulado o incremento na variavel i
     * Desse modo, será realizado mais uma interação por conta do comando for
     * */
    /////////////////////////////////////////////////////////////////////////////////////////////


    for (int i = 0; i < 1; ++i) {
        printf("Digite o CPF do funcionario\n");
        fflush(stdin); scanf("%", &VFUN.cpf);
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

    printf("Digite o salario do funcionario\n");
    scanf("%f",&VFUN.salario);



    for (int i = 0; i < 1; ++i) {

        printf("Digite o dia de nascimento do funcionario\n");
        scanf("%d", &VFUN.dia);

        if (VFUN.dia > 31 || VFUN.dia < 1)
        {
            printf("Data invalida\nTente Novamente\n");
            --i; continue;
        }
        printf("Digite o mes de nascimento do funcionario\n");
        scanf("%d", &VFUN.mes);

        if (VFUN.mes > 12 || VFUN.mes < 1)
        {
            printf("Data invalida\nTente Novamente\n");
            --i; continue;
        }

        printf("Digite o ano de nascimento do funcionario\n");
        scanf("%d", &VFUN.ano);

        if (VFUN.ano > 2021 || VFUN.ano < 1900)
        {
            printf("Data invalida\nTente Novamente\n");
            --i; continue;
        }
    }


    for (int p = 0; p < 1 ; ++p) {
        int funcao;
        printf("Voce deseja cadastrar algum dado optativo ao Funcionario\n");
        printf("Digite 1 - sim\nDigite 2 - nao\n");
        char x[1];
        scanf("%",&x);
        gets(x);
        verificar_letras(&x[0],&funcao);
        if (funcao != 1 && funcao != 2) {
            printf("Valor invalido\nTente novamente\n");
            --p;
            continue;
        }


        strcpy(VFUN.RG, "");
        strcpy(VFUN.endereco, "");
        strcpy(VFUN.sangue, "");
        if (funcao == 1) {
            for (int i = 0; i < 1; ++i) {
                printf("O que voce deseja cadastar ao funcionario\n");
                printf("Digite 1 - para cadastrar todos os dados optativos do funcionario\n");
                if (strcmp(VFUN.RG,"") == 0){ printf("Digite 2 - RG do funcionario\n"); }
                if (strcmp(VFUN.endereco,"") == 0)printf("Digite 3 - Endereco do funcionario\n");
                if (strcmp(VFUN.sangue,"") == 0)printf("Digite 4 - Tipo sanguineo do funcionario\n");
                printf("Digite 5 - Voltar ao Menu\n");
                char x[1];
                scanf("%",&x);
                gets(x);
                verificar_letras(&x[0],&funcao);
                if ((funcao == 4 && strcmp(VFUN.sangue,"") != 0) || (funcao == 3 && strcmp(VFUN.endereco,"") != 0) || (funcao == 2 && strcmp(VFUN.RG,"") != 0))
                {
                    printf("Valor invalido\nTente novamente\n\n");
                    --i;
                }

                if ((funcao == 1 || funcao == 2) && strcmp(VFUN.RG,"") == 0) {
                    printf("Digite o RG do funcionario\n");
                    fflush(stdin);
                    scanf("%", &VFUN.RG);
                    gets(VFUN.RG);
                    funcao == 2? printf("RG cadastrado com sucesso\n\n"),--i:printf("");
                }

                 if ((funcao == 1 || funcao == 3) && strcmp(VFUN.endereco,"") == 0) {
                    printf("Digite o endereco do funcionario\n");
                    fflush(stdin);
                    scanf("%", &VFUN.endereco);
                    gets(VFUN.endereco);
                    funcao == 3? printf("Endereco cadastrado com sucesso\n\n"),--i:printf("");
                }

                 if ((funcao == 1 ||funcao == 4) && strcmp(VFUN.sangue,"") == 0) {
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
                            strcpy(VFUN.sangue, "A+");
                        }
                        if (sangue_num == 2) {
                            strcpy(VFUN.sangue, "A-");
                        }
                        if (sangue_num == 3) {
                            strcpy(VFUN.sangue, "B+");
                        }
                        if (sangue_num == 4) {
                            strcpy(VFUN.sangue, "B-");
                        }
                        if (sangue_num == 5) {
                            strcpy(VFUN.sangue, "O+");
                        }
                        if (sangue_num == 6) {
                            strcpy(VFUN.sangue, "O-");
                        }
                        if (sangue_num == 7) {
                            strcpy(VFUN.sangue, "AB+");
                        }
                        if (sangue_num == 8) {
                            strcpy(VFUN.sangue, "AB-");
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
                if (strcmp(VFUN.sangue,"") != 0 && strcmp(VFUN.endereco,"") != 0 && strcmp(VFUN.RG,"") != 0) {
                    printf("Todos os dados optativos foram cadastrados com sucesso\n\n"); break;}
            }
        }
    }

    VFUN.codigo = verificador1;
    strcpy(VFUN.nome,verificador2);
    strcpy(VFUN.cpf,verificador);

    fseek(FUN,0,SEEK_END);
    fwrite(&VFUN, sizeof (struct funcionario), 1, FUN);

}

int imprimir_funcionario(FILE *FUN,FILE *DEN,struct funcionario VFUN,struct dependente VDEN) {
    /////////////////////////////////////////////////////////////////////////////////////////////
    /*Area que verifica se existe algum funcionario cadastrado
     * Se baseia em uma verificação na quantidade de digitos do CPF
     * Caso nao exista nenhum cadastrado o CPF deve ter uma quantidade de caracteres diferente de 11
     * tendo em vista que no cadastro só é possível cadastrar um CPF com 11 digitos*/
    fseek(FUN,0,SEEK_SET);
    fread(&VFUN, sizeof(struct funcionario),1,FUN);
    if( strlen(VFUN.cpf) !=11)
    {
        printf("Nao e possivel realizar essa operacao\nNenhum funcionario cadastrado\n");
    }
        /////////////////////////////////////////////////////////////////////////////////////////////
    else {

        int funcao;
        do {

            printf("O que voce deseja realizar? \n");
            printf("1 - Listar os dados de um funcionario \n");
            printf("2 - Listar todos os funcionario \n");
            printf("3 - Listar todos os funcionario em ordem alfabetica\n");
            printf("4 - Voltar ao Menu\n");
            char x[1];
            scanf("%",&x);
            gets(x);
            verificar_letras(&x[0],&funcao);

            if (funcao == 1) {
                int verificador;
                printf("Digite o codigo do funcionario\n");
                fflush(stdin);

                char x[1];
                scanf("%",&x);
                gets(x);
                verificar_letras(&x[0],&verificador);

                fseek(FUN, 0, SEEK_SET);
                while (!feof(FUN)) {
                    if (feof(FUN)) {
                        break;
                    }
                    fread(&VFUN, sizeof(struct funcionario), 1, FUN);
                    //quando for encontrado um codigo no arquivos funcionarios.bin
                    //igual ao digitado na variavel verificador, sera impresso todas as informaçôes do funcionario
                    //Além disso, a variavel funcao vai ser incrementada para sinalizar que o codigo digitado pelo usuario
                    //existe no arquivo
                    if (!feof(FUN) && verificador == VFUN.codigo) {
                        funcao = 1;
                        printf("\nNome do funcionario: %s\nCodigo do funcionario: %d\n", VFUN.nome, VFUN.codigo);
                        printf("CPF do Funcionario: " );
                        for (int i = 0; i < 11; ++i) {
                            if (i<9)
                            {
                                printf("%c",VFUN.cpf[i]);
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
                                printf("%c",VFUN.cpf[i]);
                            }
                        }
                        printf("\nSalario do funcionario: %.2f\n", VFUN.salario);
                        printf("Data de nascimento: ");
                        VFUN.dia < 10? printf("0%d/", VFUN.dia) : printf("%d/", VFUN.dia);
                        VFUN.mes < 10? printf("0%d/", VFUN.mes) : printf("%d/", VFUN.mes);
                        printf("%d\n", VFUN.ano);

                        VFUN.auxilio = 0;
                        int quantidade_dep = 0;
                        fseek(DEN, 0, SEEK_SET);
                        while (!feof(DEN)) {
                            if (feof(DEN)) {
                                break;
                            }

                            fread(&VDEN, sizeof(struct dependente), 1, DEN);
                            if (!feof(DEN) && VDEN.codigo_fun == VFUN.codigo) {
                                VFUN.auxilio = VFUN.auxilio + VDEN.salario;
                                ++quantidade_dep;
                            }
                        }

                        printf("Quantidade de dependentes: %d\n", quantidade_dep);
                        printf("Total da ajuda de custo: %.2f\n", VFUN.auxilio);
                        if (strcmp(VFUN.RG, "") != 0) { printf("RG do funcionario: %s\n", VFUN.RG); }
                        if (strcmp(VFUN.endereco, "") != 0) { printf("Endereco do funcionario: %s\n", VFUN.endereco); }
                        if (strcmp(VFUN.sangue, "") != 0) {
                            printf("Tipo sanguineo do funcionario: %s\n", VFUN.sangue);
                        }
                        printf("\n"); break;
                    }
                    else{funcao = 0;}
                }
                if (funcao == 0)
                {
                    printf("Codigo nao cadastrado\nVoce sera redirecionado ao menu\n\n");
                }
                //A variavel funcao é zerada para manter o lanço do-while
                funcao = 0;
            }

            else if (funcao == 2) {
                float gastos_dep = 0;
                int quant_dependentes = 0;
                int quant_funcionarios = 0;
                float gastos_sal = 0;
                //imprime todos os funcionarios da empresa
                fseek(FUN, 0, SEEK_SET);
                while (!feof(FUN)) {
                    fread(&VFUN, sizeof(struct funcionario), 1, FUN);
                    if (feof(FUN)) {
                        break;
                    }
                    printf("\nNome do funcionario: %s\nCodigo do funcionario: %d\n", VFUN.nome, VFUN.codigo);
                    printf("CPF do Funcionario: " );
                    for (int i = 0; i < 11; ++i) {
                        if (i<9)
                        {
                            printf("%c",VFUN.cpf[i]);
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
                            printf("%c",VFUN.cpf[i]);
                        }
                    }
                    printf("\nSalario do funcionario: %.2f\n", VFUN.salario);
                    //soma o valor de todos os salarios e descobre a quantidade de funcionarios na empresa
                    gastos_sal = gastos_sal + VFUN.salario;
                    ++quant_funcionarios;
                    printf("Data de nascimento: ");
                    VFUN.dia < 10? printf("0%d/", VFUN.dia) : printf("%d/", VFUN.dia);
                    VFUN.mes < 10? printf("0%d/", VFUN.mes) : printf("%d/", VFUN.mes);
                    printf("%d\n", VFUN.ano);

                    //Nessa parte sera verificado todos os dependentes
                    //e sera somado o valor de custo de cada dependemte que possuir o codigo do funcionario
                    //igual ao do funcionario que sera impresso

                    // caso não tenha nenhum dependente, sera impresso o valor zero

                    VFUN.auxilio = 0;
                    int quantidade_dep = 0;
                    fseek(DEN, 0, SEEK_SET);
                    while (!feof(DEN)) {
                        if (feof(DEN)) {
                            break;
                        }
                        //utilidades dessa parte
                        /* descobrir quantos dependentes um funcionario possui e qual o valor da ajuda de custo que esse
                         * funcionario recebe
                         * somar todos as ajudas de custos e descobrir quantos dependentes existem na empresa.
                         * */
                        fread(&VDEN, sizeof(struct dependente), 1, DEN);
                        if (!feof(DEN) && VDEN.codigo_fun == VFUN.codigo) {
                            VFUN.auxilio = VFUN.auxilio + VDEN.salario;
                            ++quantidade_dep;

                        }
                    }

                    printf("Quantidade de dependentes: %d\n", quantidade_dep);
                    printf("Total da ajuda de custo: %.2f\n", VFUN.auxilio);

                    if (strcmp(VFUN.RG, "") != 0) { printf("RG do funcionario: %s\n", VFUN.RG); }
                    if (strcmp(VFUN.endereco, "") != 0) { printf("Endereco do funcionario: %s\n", VFUN.endereco); }
                    if (strcmp(VFUN.sangue, "") != 0) { printf("Tipo sanguineo do funcionario: %s\n", VFUN.sangue); }
                    printf("\n");
                }
                fseek(DEN,0,SEEK_SET);
                while (!feof(DEN))
                {fread(&VDEN,sizeof (struct dependente),1,DEN);
                    if (feof(DEN))
                    {
                        break;
                    }

                    else
                    {
                        ++quant_dependentes;
                        gastos_dep = VDEN.salario + gastos_dep;
                    }
                }
                //A variavel funcao é zerada para manter o lanço do-while
                funcao = 0;
                //informações economicas da empresa
                printf("\n                Despesas da empresa\n");
                printf("\nDespesas com auxilios de custo de %d dependentes = %.2f\n",quant_dependentes,gastos_dep);
                printf("Despesas com salarios de %d funcionarios = %.2f\n\n",quant_funcionarios,gastos_sal);
                printf("Despesas totais da empresa = %.2f\n\n",gastos_sal+gastos_dep);


            } else if (funcao == 3) {
                int posicao = 0;

                fseek(FUN, 0, SEEK_SET);
                //serve apenas para saber quantos nomes existem
                for (int i = 0; i < feof(FUN) + 1; ++i) {
                    if (feof(FUN)) {
                        break;
                    }
                    fread(&VFUN, sizeof(struct funcionario), 1, FUN);
                    if (!feof(FUN)) {
                        --i;
                        posicao++;
                    }
                }

                char nome[posicao][255];
                //Depois de descobrir a quantidade de nomes
                //essa parte serve para tirar os nomes do arquivo e colocar na ram
                fseek(FUN, 0, SEEK_SET);
                for (int i = 0; i < posicao; ++i) {
                    if (feof(FUN)) {
                        break;
                    }
                    fread(&VFUN, sizeof(struct funcionario), 1, FUN);
                    if (!feof(FUN)) {
                        strcpy(nome[i], VFUN.nome);
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

                for (int i = 0; i < posicao; ++i) {
                    printf("Nome do Funcionario: %s\n", nome[i]);
                }
                //A variavel funcao é zerada para manter o lanço do-while
                funcao = 0;
            }
            else if (funcao == 4) {
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


int alterar_funcionario(FILE *FUN,FILE *DEN,struct funcionario VFUN,struct dependente VDEN)
{
    /*Area que verifica se existe algum funcionario cadastrado
        * Se baseia em uma verificação na quantidade de digitos do CPF
        * Caso nao exista nenhum cadastrado o CPF deve ter uma quantidade de caracteres diferente de 11
        * tendo em vista que no cadastro só é possível cadastrar um CPF com 11 digitos*/

    fseek(FUN,0,SEEK_SET);
    fread(&VFUN, sizeof(struct funcionario),1,FUN);
    if( strlen(VFUN.cpf) !=11)
    {
        printf("Nao e possivel realizar essa operacao\nNenhum funcionario cadastrado\n");
    }
        /////////////////////////////////////////////////////////////////////////////////////////////
    else {
        int indicador = 0;
        int verificando;
        printf("digite o codigo do funcionario\n");
        char x[1];
        scanf("%",&x);
        gets(x);
        verificar_letras(&x[0],&verificando);
        fseek(FUN, 0, SEEK_SET);

        while (!feof(FUN)) {
            if (feof(FUN)) {
                break;
            }
            fread(&VFUN, sizeof(struct funcionario), 1, FUN);

            if (!feof(FUN) && verificando == VFUN.codigo) {
                fseek(FUN, -1 * sizeof(struct funcionario), SEEK_CUR);
                for (int i = 0; i < 1; ++i)
                 {
                     char nome[100];
                     char CPF[12];
                     float salario;
                     int dia, mes, ano;
                     char RG[15];
                     char endereco[255];
                     char sangue[4];
                    //Menu da parte de alterar os dados de um funcionario

                    printf("O que voce deseja alterar no funcionario?\n");
                    printf("Digite 1 - para alterar todos os dados de um funcionario\n");
                    printf("Digite 2 - para alterar o nome do funcionario\n");
                    printf("Digite 3 - para alterar o CPF do funcionario\n");
                    printf("Digite 4 - para alterar o salario funcionario\n");
                    printf("Digite 5 - para alterar a data de nascimento do funcionario\n");

                    printf("Digite 6 - para ");
                    //Caso não exista nenhuma informação para o RG o programa vai dar a opção de inserir um dado
                    //se ele existir o programa vai dar a opção de alterar
                    //isso também vale para os outros dados optativos
                    strcmp(VFUN.RG,"")!= 0? printf("alterar") : printf("inserir");
                    printf(" o RG do funcionario\n");

                     printf("Digite 7 - para ");
                     strcmp(VFUN.endereco,"")!= 0? printf("alterar") : printf("inserir");
                     printf(" o endereco do funcionario\n");

                     printf("Digite 8 - para ");
                     strcmp(VFUN.sangue,"")!= 0? printf("alterar") : printf("inserir");
                    printf(" o tipo sanguineo do funcionario\n");

                    printf("Digite 9 - para sair\n");
                     char x[1];
                     scanf("%",&x);
                     gets(x);
                     verificar_letras(&x[0],&indicador);

                    if (indicador == 1 || indicador == 2) {
                        printf("Digite o novo nome do funcionario\n");
                        scanf("%", &nome);
                        gets(nome);

                        //Caso o usuario altere apenas o nome, será impresso uma mensagem sinalizando a alteração
                        indicador == 2? printf("\nNome alterado com sucesso\n"),--i: printf("");

                    }
                    if (indicador == 1 || indicador == 3)
                    {
                        for (int j = 0; j < 1; ++j) {
                            int p = 0;
                            printf("Digite o novo CPF do funcionario\n");
                            scanf("%", &VFUN.cpf);
                            gets(CPF);

                            if (strlen(CPF) != 11)
                            {   p = 1;
                                printf("O CPF deve ter 11 digitos\nInsira seu CPF corretamente\n");
                                --j;continue;
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
                                    --j; p = 1;
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
                                    --j; p = 1;
                                    break;
                                }

                            }
                            //Caso o usuario altere apenas o CPF, será impresso uma mensagem sinalizando a alteração
                            indicador == 3  && p == 0? printf("\nCPF alterado com sucesso\n"),--i  : printf("");


                        }

                    }
                    if (indicador == 1 || indicador == 4)
                    {
                        printf("Digite o salario do funcionario\n");
                        scanf("%f",&salario);
                        //Caso o usuario altere apenas o salario, será impresso uma mensagem sinalizando a alteração
                        indicador == 4? printf("\nSalario alterado com sucesso\n"), --i  : printf("");

                    }
                    if (indicador == 1 || indicador == 5)
                    {
                        for (int i = 0; i < 1; ++i)
                        {
                            printf("Digite o dia do nascimento do funcionario\n");
                            fflush(stdin);
                            scanf("%d", &dia);

                            if (dia > 31 || dia < 1)
                            {
                                printf("Data invalida\nTente Novamente\n");
                                --i; continue;
                            }

                            printf("Digite o mes do nascimento do funcionario\n");
                            fflush(stdin);
                            scanf("%d", &mes);

                            if (mes > 12 || mes < 1)
                            {
                                printf("Data invalida\nTente Novamente\n");
                                --i; continue;
                            }

                            printf("Digite o ano do nascimento do funcionario\n");
                            fflush(stdin);
                            scanf("%d", &ano);
                            if (ano > 2021 || ano < 1900)
                            {
                                printf("Data invalida\nTente Novamente\n");
                                --i; continue;
                            }
                        }
                        //Caso o usuario altere apenas o data de nascimento, será impresso uma mensagem sinalizando a alteração
                        indicador == 5? printf("\nData de nascimento alterada com sucesso\n"), --i  : printf("");

                    }
                    if ((indicador == 1 && strcmp(VFUN.RG,"")!= 0 || indicador == 6) )
                    {
                        printf("Digite o RG do funcionario\n");
                        fflush(stdin);scanf("%",&VFUN.RG);
                        gets(RG);
                        // Se existir alguma informação na variavel VFUN.RG sera impresso uma mensagem informado o RG foi alterado
                        //Caso contrario sera impresso que o RG foi inserido
                        indicador == 6? strcmp(VFUN.RG,"")== 0? printf("\nRG inserido com sucesso\n"), --i : printf("\nRG alterado com sucesso\n"), --i  : printf("");

                    }
                     if ((indicador == 1 && strcmp(VFUN.endereco,"") != 0 || indicador == 7) )
                     {
                         printf("Digite o endereco do funcionario\n");
                         scanf("%",&VFUN.endereco);
                         gets(endereco);
                         // Se existir alguma informação na variavel VFUN.endereco sera impresso uma mensagem informado o endereço foi alterado
                         //Caso contrario sera impresso que o endereço foi inserido
                         indicador == 7? strcmp(VFUN.endereco,"") == 0?  printf("\nendereco inserido com sucesso\n"), --i : printf("\nendereco alterado com sucesso\n"), --i  : printf("");
                         //indicador == 7? printf("\nendereco alterado com sucesso\n"), --i  : printf("");

                     }

                     if ((indicador == 1  && strcmp(VFUN.sangue,"") != 0 || indicador == 8))
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
                              // Se existir alguma informação na variavel VFUN.sangue sera impresso uma mensagem informado o sangue foi alterado
                             //Caso contrario sera impresso que o sangue foi inserido
                             indicador == 8?strcmp(VFUN.sangue,"") == 0?  printf("\nTipo sanguineo inserido com sucesso\n"), --i : printf("\nTipo sanguineo alterado com sucesso\n"), --i  : printf("");
                         }
                     }
                     indicador == 1?  printf("\nDados alterados com sucesso\n"): printf("");

                        /*Area responsavel por escrever as informações que o usuario digitou no arquivo
                         * funcionarios.bin
                         * */
                         fseek(FUN, 0, SEEK_SET);
                         while (!feof(FUN)) {
                             if (feof(FUN)) {
                                 break;
                             }
                             fread(&VFUN, sizeof(struct funcionario), 1, FUN);
                             if (!feof(FUN) && verificando == VFUN.codigo) {
                                 fseek(FUN, -1 * sizeof(struct funcionario), SEEK_CUR);
                                 if (indicador == 1 || indicador == 2) {strcpy(VFUN.nome, nome);}

                                 if (indicador == 1 || indicador == 3) {strcpy(VFUN.cpf, CPF);}

                                 if (indicador == 1 || indicador == 4) {VFUN.salario = salario;}

                                 if (indicador == 1 || indicador == 5){VFUN.dia = dia; VFUN.mes = mes; VFUN.ano = ano;}

                                 if ((indicador == 1 && strcmp(VFUN.RG,"") != 0 || indicador == 6) ){strcpy(VFUN.RG, RG);}

                                 if ((indicador == 1 && strcmp(VFUN.endereco,"") != 0 || indicador == 7) ){strcpy(VFUN.endereco,endereco);}

                                 if ((indicador == 1 && strcmp(VFUN.sangue,"") != 0 || indicador == 8) ){strcpy(VFUN.sangue, sangue);}

                                 fwrite(&VFUN, sizeof(struct funcionario), 1, FUN);
                                 break;

                         }
                     }


                    if (indicador == 1 || indicador == 9) { break; }
                    if(indicador > 9 || indicador < 1){printf("Valor invalido\nTente novamente\n\n");--i;}
                 } break;
            }

        }

        if (indicador == 0)
        {
            printf("Codigo nao cadastrado\nVoce sera redirecionado ao menu\n");
        }
    }



}

int excluir_funcionario(FILE *FUN,FILE *DEN,struct funcionario VFUN,struct dependente VDEN)
{
    /*Area que verifica se existe algum funcionario cadastrado
* Se baseia em uma verificação na quantidade de digitos do CPF
* Caso nao exista nenhum cadastrado o CPF deve ter uma quantidade de caracteres diferente de 11
* tendo em vista que no cadastro só é possível cadastrar um CPF com 11 digitos*/
                   fseek(FUN, 0, SEEK_SET);
                   fread(&VFUN, sizeof(struct funcionario), 1, FUN);
                   if (strlen(VFUN.cpf) != 11) {
                       printf("Nao e possivel realizar essa operacao\nNenhum funcionario cadastrado\n");
                   }

                   else
                   {
                           int indicador = 0;
                           int verificando;
                           printf("digite o codigo do funcionario\n");
                           char x[1];
                           scanf("%",&x);
                           gets(x);
                           verificar_letras(&x[0],&verificando);
                           int salvar_verificador = verificando;
                           fseek(FUN, 0, SEEK_SET);
                           while (!feof(FUN))
                           {
                               if (feof(FUN))
                               {
                                   break;
                               }

                               fread(&VFUN, sizeof(struct funcionario), 1, FUN);

                               if (!feof(FUN) && verificando == VFUN.codigo)
                               {
                                   //Posiciona o ponteiro do arquivo
                                   ++indicador;
                                   break;
                               }

                           }

                       if (indicador != 0)
                       {
                           fseek(FUN, -1 * sizeof(struct funcionario), SEEK_CUR);
                           fread(&VFUN, sizeof(struct funcionario), 1, FUN);

                           for (int i = 0; i < 1; ++i)
                           {
                               //Menu da area responsavel pela exclusão de dados
                               printf("Digite 1 - para excluir todos os dados do funcionario\n");
                               //A opção de excluir dados optativos so aparece caso o funcionario tenha pelo menos 1
                               //dado optativo cadastrado
                               if (strcmp(VFUN.sangue,"") !=0 || strcmp(VFUN.RG,"") !=0 || strcmp(VFUN.endereco,"") !=0 ) {
                                   printf("Digite 2 - para excluir algum dado optativo do funcionario \n");
                               }
                               printf("Digite 3 - para sair\n");
                               char x[1];
                               scanf("%",&x);
                               gets(x);
                               verificar_letras(&x[0],&indicador);

                               if (indicador == 1) {   //Para excluir um novo arquivo é criado
                                   //após isso, todas as informações do arquivo de funcionario são copiados para o arquivo auxiliar
                                   //com exceção do arquivo que deve ser excluido
                                   //depois disso o arquivo dos funcionario é fechado e aberto utilizando o wb+
                                   //todas as informações do arquivo auxiliar vão para o arquivo de funcionarios(assim eliminando o funcionario desejado)
                                   //por fim, o arquivo auxiliar é zerado utilizando o mesmo processo.
                                   FILE *a;
                                   struct dados {
                                       char nome[100];
                                       int codigo;
                                       char cpf[12];
                                       int dia;
                                       int mes;
                                       int ano;
                                       float salario;
                                       int cod_fun;
                                       float auxilio;
                                       char RG[15];
                                       char endereco[255];
                                       char sangue[4];
                                   } dados;
                                   a = fopen("auxiliar.bin", "wb+");
                                   fseek(FUN, 0, SEEK_SET);
                                   fseek(a, 0, SEEK_END);

                                   while (!feof(FUN)) {
                                       if (feof(FUN)) {
                                           break;

                                       } else {
                                           fread(&VFUN, sizeof(struct funcionario), 1, FUN);
                                           if (!feof(FUN) && salvar_verificador != VFUN.codigo) {
                                               strcpy(dados.nome, VFUN.nome);
                                               dados.codigo = VFUN.codigo;
                                               strcpy(dados.cpf, VFUN.cpf);
                                               dados.salario = VFUN.salario;
                                               dados.dia = VFUN.dia;
                                               dados.mes = VFUN.mes;
                                               dados.ano = VFUN.ano;
                                               dados.auxilio = VFUN.auxilio;
                                               strcpy(dados.RG, VFUN.RG);
                                               strcpy(dados.endereco, VFUN.endereco);
                                               strcpy(dados.sangue, VFUN.sangue);
                                               fwrite(&dados, sizeof(struct dados), 1, a);
                                           }
                                       }
                                   }
                                   fclose(FUN);
                                   FUN = fopen("funcionario.bin", "wb+");

                                   fseek(a, 0, SEEK_SET);
                                   fseek(FUN, 0, SEEK_END);

                                   while (!feof(a)) {

                                       if (feof(a)) {
                                           break;
                                       }
                                       fread(&dados, sizeof(struct dados), 1, a);
                                       if (!feof(a)) {

                                           strcpy(VFUN.nome, dados.nome);
                                           VFUN.codigo = dados.codigo;
                                           strcpy(VFUN.cpf, dados.cpf);
                                           VFUN.salario = dados.salario;
                                           VFUN.dia = dados.dia;
                                           VFUN.mes = dados.mes;
                                           VFUN.ano = dados.ano;
                                           VFUN.auxilio = dados.auxilio;
                                           strcpy(VFUN.RG, dados.RG);
                                           strcpy(VFUN.endereco, dados.endereco);
                                           strcpy(VFUN.sangue, dados.sangue);
                                           fwrite(&VFUN, sizeof(struct funcionario), 1, FUN);
                                       }
                                   }


                                   fclose(a);
                                   a = fopen("auxiliar.bin", "wb+");
                                   fclose(a);

                                   printf("Funcionario excluido com sucesso\n");

                                   //Opção de excluir os dependentes do funcionario
                                   //Caso o usuario deseje excluir os dependentes
                                   //o processo é bem similar com a exclusão de um funcionario
                                   //mas aqui o programa utiliza a variavel VDEN.codigo_fun para saber quem deve ser copiado
                                   //para o arquivo auxiliar

                                   //Se o usuario desejar não excluir os dependentes do funcionario
                                   //Na variavel VDEN.codigo_fun vai receber o valor 0, ja que o funcionario vai ser excluido
                                   // e o mesmo codigo poderá ser utilizado novamente em algum momento
                                   //Será impresso uma mensagem indicando ao usuario para atualizar o cadastrado dos dependentes dessa funcionario
                                   //caso o usuario deseje realizar esse processo
                                   indicador = 0;

                                   fseek(DEN,0,SEEK_SET);
                                   while (!feof(DEN)) {
                                       if (feof(DEN)) {
                                           break;
                                       }
                                       fread(&VDEN, sizeof(struct dependente), 1, DEN);
                                       if (salvar_verificador == VDEN.codigo_fun) {
                                           //Existe um dependente para o funcionario
                                           indicador = 1;
                                       }
                                   }
                                    //Esse menu so vai aparecer caso exista um dependente para o funcionario
                                   if (indicador == 1) {
                                       for (int j = 0; j < 1; ++j) {
                                           printf("Deseja excluir os dados dos dependentes relacionados ao funcionario?\n");
                                           printf("Digite 1 - Sim\nDigite 2 - Nao\n");
                                           char x[1];
                                           scanf("%",&x);
                                           gets(x);
                                           verificar_letras(&x[0],&indicador);

                                           if (indicador == 1) {
                                               a = fopen("auxiliar.bin", "wb+");
                                               fseek(DEN, 0, SEEK_SET);
                                               fseek(a, 0, SEEK_END);
                                               while (!feof(DEN)) {
                                                   if (feof(DEN)) {
                                                       break;

                                                   } else {
                                                       fread(&VDEN, sizeof(struct dependente), 1, DEN);
                                                       //identifica quem deve ser copiado para o arquivo auxiliar
                                                       if (!feof(DEN) && salvar_verificador != VDEN.codigo_fun) {
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
                                               //zera as informações do arquivo dependentes.bin
                                               DEN = fopen("dependentes.bin", "wb+");

                                               //posiciona os ponteiros
                                               fseek(a, 0, SEEK_SET);
                                               fseek(DEN, 0, SEEK_END);

                                               while (!feof(a)) {

                                                   if (feof(a)) {
                                                       break;
                                                   }
                                                   // copia as informaçoes do arquivo auxiliar para dependentes.bin
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
                                               printf("Todos os dependentes do funcionario %d foram excluidos",verificando);
                                           } else if (indicador == 2) {


                                               int quantidade = 0;
                                               //descobre quantos dependentes o funcionario possui
                                               fseek(DEN, 0, SEEK_SET);
                                               while (!feof(DEN)) {
                                                   if (feof(DEN)) {
                                                       break;
                                                   }
                                                   fread(&VDEN, sizeof(struct dependente), 1, DEN);
                                                   if (!feof(DEN) && salvar_verificador == VDEN.codigo_fun) {
                                                       ++quantidade;
                                                       fwrite(&VDEN, sizeof(struct dependente), 1, DEN);
                                                   }
                                               }

                                               //o processo de copiar 0 para a variavel VDEN.codigo_fun deve se repetir
                                               //"quantidade" vezes
                                               for (int j = 0; j < quantidade; ++j) {
                                                   fseek(DEN, 0, SEEK_SET);
                                                   while (!feof(DEN)) {
                                                       if (feof(DEN)) {
                                                           break;
                                                       }
                                                       fread(&VDEN, sizeof(struct dependente), 1, DEN);
                                                       if (!feof(DEN) && salvar_verificador == VDEN.codigo_fun) {
                                                           fseek(DEN, -1 * sizeof(struct dependente), SEEK_CUR);
                                                           VDEN.codigo_fun = 0;
                                                           fwrite(&VDEN, sizeof(struct dependente), 1, DEN);
                                                           fseek(DEN, 1 * sizeof(struct dependente), SEEK_CUR);
                                                       }
                                                   }
                                               }
                                               printf("O codigo %d foi excluido de todos os dependentes\nLembre-se de atualizar os dados de cada dependente se for necessario\n",
                                                      salvar_verificador);
                                           }

                                           if (indicador < 1 || indicador > 2) {
                                               printf("Valor invalido\nTente novamente\n");
                                               --j;
                                           }

                                       }
                                   }
                               }

                               else if (indicador == 2 && (strcmp(VFUN.sangue,"") !=0 || strcmp(VFUN.RG,"") !=0 || strcmp(VFUN.endereco,"") !=0 ))
                               {
                                   for (int j = 0; j < 1; ++j)
                                   {   char RG[15];
                                       char endereco[255];
                                       char sangue[4];
                                       //So sera impresso as opções de excluir apenas as informações que o funcionario possuir
                                       printf("Digite 1 - para excluir todos os dados optativos do funcionario\n");
                                       if(strcmp(VFUN.RG,"") !=0 ){ printf("Digite 2 - para excluir o RG do funcionario\n"); }
                                       if (strcmp(VFUN.endereco,"") !=0){ printf("Digite 3 - para excluir o endereco do funcionario\n"); }
                                       if (strcmp(VFUN.sangue,"") !=0){ printf("Digite 4 - para excluir o tipo sanguineo do funcionario\n"); }
                                       printf("Digite 5 - para sair\n");
                                       char x[1];
                                       scanf("%",&x);
                                       gets(x);
                                       verificar_letras(&x[0],&indicador);

                                       if((indicador == 1 || indicador == 2)  && strcmp(VFUN.RG,"") !=0 )
                                       {
                                           strcpy(RG,"\0");
                                           indicador == 2? printf("RG do funcionario foi excluido\n"), --j : printf("");

                                       }
                                       else if((indicador == 1 || indicador == 3 ) && strcmp(VFUN.endereco,"") !=0)
                                       {
                                           strcpy(endereco,"\0");
                                           indicador == 3? printf("endereco do funcionario foi excluido\n"), --j : printf("");
                                       }
                                       else if((indicador == 1 || indicador == 4 ) && strcmp(VFUN.sangue,"") !=0)
                                       {
                                           strcpy(sangue,"\0");
                                           indicador == 4? printf("Tipo sanguineo do funcionario foi excluido\n"), --j : printf("");
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

                                       indicador == 1? printf("todos os dados optativos do funcionario foram excluidos\n"):printf("");

                                       fseek(FUN, 0, SEEK_SET);
                                       while (!feof(FUN)) {
                                           if (feof(FUN)) {
                                               break;
                                           }
                                           //Area responsavel por copiar "\0" para a variavel que for excluida
                                           fread(&VFUN, sizeof(struct funcionario), 1, FUN);
                                           if (!feof(FUN) && verificando == VFUN.codigo) {
                                               fseek(FUN, -1 * sizeof(struct funcionario), SEEK_CUR);
                                               if ((indicador == 1 || indicador == 2) && strcmp(VFUN.RG,"\0") !=0 ) {strcpy(VFUN.RG, RG);}

                                               if ((indicador == 1 || indicador == 3) && strcmp(VFUN.endereco,"\0") !=0 ) {strcpy(VFUN.endereco,"\0");}

                                               if ((indicador == 1 || indicador == 4) && strcmp(VFUN.sangue,"\0") !=0 ) {strcpy(VFUN.sangue,sangue);}

                                               fwrite(&VFUN, sizeof(struct funcionario), 1, FUN);
                                               break;

                                           }
                                       }

                                   }
                                   ++i;
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
                           printf("Codigo nao cadastrado\nVoce sera redirecionado ao menu\n");
                       }
                   }
}