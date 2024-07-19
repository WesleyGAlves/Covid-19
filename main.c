#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#define SIZE 200

char nome[SIZE][50];
char cpf[SIZE];
char telefone[SIZE][50];
char rua[SIZE][50];
char numerocasa[SIZE][50];
char bairro[SIZE][50];
char cidade[SIZE][50];
char estado[SIZE][50];
char cep[SIZE][50];
char idade[SIZE][50];
char email[SIZE][50];
char diadiagnostico[SIZE][50];
char comorbidade[SIZE][50];
int op;
void login();
void cadastro();
void pesquisa();
void lista();

int main() {

    login();
    cadastro();
    lista();
    pesquisa();

    do{
        system("cls");
        printf("\n-----Menu-----\n1 - Cadastrar\n2 - Lista Pacientes\n3 - Pesquisa\n4 - Sair");
        scanf("%d", &op);
        switch(op){
            case 1:
                cadastro();
                break;
            case 2:
                lista();
                break;
            case 3:
                pesquisa();
                break;
            case 4:
                system("exit");
                break;
            default:
                printf("Opcao invalida");
                getchar();
                getchar();
                break;
        }
    }while(op!=4);
}

void lista(){
    int i;
    system("cls");
    printf("\n\t ------Menu Lista ------\n");
    for(i=0;i<SIZE;i++){
        if(cpf[i]!=0){
            printf("\n Nome: %s\n",nome[i]);
            printf(" Cpf: %d \n",cpf[i]);
            printf(" Telefone: %s \n",telefone[i]);
            printf(" Rua: %s \n",rua[i]);
            printf(" NumeroCasa: %s \n",numerocasa[i]);
            printf(" Bairro: %s \n",bairro[i]);
            printf(" Cidade: %s \n",cidade[i]);
            printf(" Estado: %s \n",estado[i]);
            printf(" Cep: %s \n",cep[i]);
            printf(" Idade: %s \n",idade[i]);
            printf(" Email: %s \n",email[i]);
            printf(" Diadiagnostico: %s \n",diadiagnostico[i]);
            printf(" Comorbidade: %s \n",comorbidade[i]);

        }else{
            break;
        }
        printf("\n DIGITE 1 para continuar");
        scanf("%d",&op);
    }
    getchar();
    getchar();
}

void cadastro() {
    static int linha;
    int i;
    FILE *covid;
    covid = fopen("pacientes.txt","a");
    FILE *secretaria;
    secretaria = fopen("grupo de risco.txt","a");
    system("cls");
    do {

        printf("\n\t-----MENU CADASTRO-----: \n");

        printf("\n Informe o NOME: ");
        scanf("%s", &nome[linha],50);

        printf("\n Digite o CPF: ");
        scanf("%d", &cpf[linha]);

        printf("\n Informe o TELEFONE: ");
        scanf("%s", &telefone[linha]);

        printf("\n Informe a RUA: ");
        scanf("%s", &rua[linha],50);

        printf("\n Informe o NUMERO DA CASA: ");
        scanf("%s", &numerocasa[linha]);

        printf("\n Informe o BAIRRO: ");
        scanf("%s", &bairro[linha],50);

        printf("\n Informe a CIDADE: ");
        scanf("%s", &cidade[linha],50);

        printf("\n Informe o ESTADO: ");
        scanf("%s", &estado[linha],50);

        printf("\n Informe o CEP: ");
        scanf("%s", &cep[linha]);

        printf("\n Informe a IDADE: ");
        scanf("%s", &idade[linha]);
        if(idade>65){
            fprintf(secretaria,"%s",&idade);
        }

        printf("\n Informe o EMAIL: ");
        scanf("%s", &email[linha],50);

        printf("\n Informe o DIA DO DIAGNOSTICO, DD/MM/AAAA: ");
        scanf("%s", &diadiagnostico[linha],50);

        printf("\n Informe a COMORBIDADE: ");
        scanf("%s", &comorbidade[linha],50);
        if(comorbidade!=0){
            fprintf(secretaria,"%s",&comorbidade);
            fprintf(secretaria,"%s",&cep);
        }

        printf("\n Digite 1 para continuar ou outro valor pra sair: ");
        scanf("%s",&op);

        fprintf(covid,"%s",&nome);
        fprintf(covid,"%d",&cpf);
        fprintf(covid,"%s",&telefone);
        fprintf(covid,"%s",&rua);
        fprintf(covid,"%s",&numerocasa);
        fprintf(covid,"%s",&bairro);
        fprintf(covid,"%s",&cidade);
        fprintf(covid,"%s",&estado);
        fprintf(covid,"%s",&cep);
        fprintf(covid,"%s",&idade);
        fprintf(covid,"%s",&email);
        fprintf(covid,"%s",&diadiagnostico);
        fprintf(covid,"%s",&comorbidade);
        fclose(covid);

        return 1;

        linha++;
    }while(op==1);
}//fim funcão cadastro

void pesquisa() {

int emailpesquisa;
int cpfPesquisa;
int i;
    do {
        system("cls");
        printf("\n\t ------Menu Pesquisar ------\n");
        printf("\n\n Digite 1 para pesquisar por CPF ou 2 para pesquisar por email: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("\n Digite o cpf : ");
                scanf("%d",&cpfPesquisa);
                for(i=0;i<SIZE;i++) {
                    if(cpf[i]==cpfPesquisa){
                        printf("\n Nome: %s",nome[i]);
                        printf(" Cpf: %d \n",cpf[i]);
                        printf(" Telefone: %s \n",telefone[i]);
                        printf(" Rua: %s \n",rua[i]);
                        printf(" NumeroCasa: %s \n",numerocasa[i]);
                        printf(" Bairro: %s \n",bairro[i]);
                        printf(" Cidade: %s \n",cidade[i]);
                        printf(" Estado: %s \n",estado[i]);
                        printf(" Cep: %s \n",cep[i]);
                        printf(" Idade: %s \n",idade[i]);
                        printf(" Email: %s \n",email[i]);
                        printf(" Diadiagnostico: %s \n",diadiagnostico[i]);
                        printf(" Comorbidade: %s \n",comorbidade[i]);
                    }
                }
            break;
            case 2:
                printf("\n Digite o email : ");
                scanf("%s", emailpesquisa);
                for(i=0;i<SIZE;i++){
                    if(strcmp(email[i], emailpesquisa)==0){
                        printf("\n Nome: %s",nome[i]);
                        printf(" Cpf: %d \n",cpf[i]);
                        printf(" Telefone: %s \n",telefone[i]);
                        printf(" Rua: %s \n",rua[i]);
                        printf(" NumeroCasa: %s \n",numerocasa[i]);
                        printf(" Bairro: %s \n",bairro[i]);
                        printf(" Cidade: %s \n",cidade[i]);
                        printf(" Estado: %s \n",estado[i]);
                        printf(" Cep: %s \n",cep[i]);
                        printf(" Idade: %s \n",idade[i]);
                        printf(" Email: %s \n",email[i]);
                        printf(" Diadiagnostico: %s \n",diadiagnostico[i]);
                        printf(" Comorbidade: %s \n",comorbidade[i]);
                        }
                    }
                break;
        default:
        printf("\n Erro, tente novamente! \n");
        break;
    }
    printf("\n DIGITE 1 para continuar ou outro numero para finalizar \n");
    scanf("%d",&op);

  }while(op==1);

}
void login(){

char login[SIZE] = "covid";
char login1[SIZE];
char senha[SIZE] = "unip";
char senha1[SIZE];
int login_efetuado = 0;

        while(!login_efetuado){
            printf("\nBEM VINDO DOUTOR: \n");

            printf("\n--Digite o Login: ");
            scanf("%s", login1);

            printf("\n--Digite a Senha: ");
            scanf("%s", senha1);

            if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0){
                printf("\n\nLOGADO!\n\n");
                login_efetuado = 1;
            }
            else
                printf("\n\nDADOS INVALIDOS!\n\n");
        }

    }


