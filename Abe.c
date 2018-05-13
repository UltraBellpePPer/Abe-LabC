#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct{
  char username[12];
  char password[15];
  int tipo;
}login;

int carregar_utilizadores(login peepz[]){
FILE *fx; char s[40],n=0,i,j;
	fx=fopen("Clientes.txt","r");
	while(fgets(s,40,fx)){
		for(i=0;s[i]!=';';i++) peepz[n].username[i]=s[i];
		peepz[n].username[i]='\0';
		i++;
		j=0;
		for(;s[i]!=';';i++) peepz[n].password[j++]=s[i];
		peepz[n].password[j]='\0';
		i++;
		j=0;
		peepz[i].tipo=atoi(&s[i]);
                n++;
	}
	fclose(fx);
	return n;
}


int main(void){
  int i= 0,n,j = 0,y = 0,z = 0;
  char User[12];
  login peepz[1000];
  FILE *fx;
  char Userpass[16];
 menu_aut:
  n = carregar_utilizadores(peepz);
  printf("**Menu de autenticação** \n");
  printf("1)Login: \n");
  printf("2)Pedido de registo de novo utilizador \n");
  printf("3)Sair \n");
  printf("A Sua Opcão: ");
  scanf("%d",&i);
  while(i <= 0 || i > 3){
    printf("Opção inválida \n");
    printf("A Sua Opção: ");
    scanf("%d", &i);
  }
  if(i == 3){
  return 0;
  }
  if(i == 2){
    menu_reg:
    printf("Indique agora o seu nome de utilizador. \n");
    printf("O seu nome de utilizador deve ser o seu número mecanográfico. Por exemplo up201705687. \n");
    printf("O seu nome:");
    scanf("%s",User);
    printf("Indique agora a sua password.");
    printf("Regras: 1 -> Deve conter no mínimo 4 caracteres e no máximo 15");
    printf("        2 -> Não pode conter ; e deve ter no minimo uma letra e um algarismo");
    printf("A sua Password:");
    scanf("%s",Userpass);
    for(int x = 0;x < Userpass.length;x++){
      if('0' <= Userpass[x] && Userpass[x] >= '9'){
        y = 1;
      }
      if('a' )
  }
  if(i == 1){
  menu_login:
    printf("Nome de utilizador:");
    scanf("%s",User);
    for(i = 0; i < n;i++){
      if(strcmp(User,peepz[i].username) == 0){
	j = 1;
	break;
      }
    }
    printf("%s\n",peepz[i].username);
    if(j == 0){
      printf("Utilizador inválido\n");
      printf("1)Voltar ao menu\n");
      printf("2)Tentar novamente\n");
      printf("A sua Opção:");
      scanf("%d", &i);
      while(i <= 0 || i > 2){
	printf("Opção não válida \n");
	printf("A Sua Opção: ");
	scanf("%d", &i);
      }
      if (i==1)
	goto menu_aut;
      if (i==2)
	goto menu_login;
    }
  }
  else{
    return 0;
  }
}
