#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

typedef struct{
  char username[20];
  char password[10];
  int tipo;
  }login;

int carrega_utilizadores(login peepz[]){
FILE *fx; char s[40],n=0,i,j=0;
	fx=fopen("AdminLogin.txt","r");
	while(fgets(s,40,fx)){
		for(i=0;s[i]!=';';i++) peepz[n].username[i]=s[i];
		peepz[n].username[i]='\0';
		i++;
		j=0;
		for(;s[i]!=';';i++) peepz[n].password[j++]=s[i];
		peepz[n].password[j]='\0';
		i++;
		j=0;
                n++;
	}
	fclose(fx);
	return n;
}
int main(void){
  int i = 0;
  char User[20];
  login peepz[5];
  int n;
  n = carrega_utilizadores(peepz);
  menu:
  printf(ANSI_COLOR_GREEN"**Menu de autenticação**" ANSI_COLOR_RESET "\n");
  printf("1) Login / autenticação \n");
  printf("2) Sair \n");
  printf("A Sua Opção: ");
  scanf("%d", &i);
  while(i <= 0 || i > 2){
    printf("Opção não válida \n");
    printf("A Sua Opção: ");
    scanf("%d", &i);
  }
  if(i == 2){
    return 0;
  }
  else{
  login:
    printf("Nome de utilizador:");
    scanf("%s",User);
    if(strcmp(User,peepz[0].username) != 0){
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
	goto menu;
      if (i==2)
	goto login;
    }
    else{
      return 0;
    }
  } 
}
