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


// O carrega_utilizadores serve para carregar o TXT para a struct login que está definida em cima
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
		peepz[i].tipo=atoi(&s[i]);
                n++;
	}
	fclose(fx);
	return n;
	 	
}
int main(void){
  int i = 0;
  char User[20];
  char paswrd[20];
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
    if(strcmp(User,peepz[0].username) != 0){ // O strcmp serve para comparar duas Strings. As duas Strings são iguais quando o resulatado é 0
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
      goto password;
    }
  }
 password:
    printf("%s\n",peepz[0].password);
    printf("Password:");
    scanf("%s", paswrd);
    printf("%s\n",paswrd);
    if(strcmp(paswrd,peepz[0].password) != 0){
      printf("Password inválida\n");
      printf("1)Voltar ao menu\n");
      printf("2)Tentar novamente\n");
      printf("A Sua Opção:");
      scanf("%d", &i);
      while(i <= 0 || i > 2){
	printf("Opção não válida \n");
	printf("A Sua Opção: ");
	scanf("%d", &i);   
      }
	if(i==1)
	  goto menu;
	if(i==2)
	  goto password;
    }
    else{
      printf("ISTO ESTÁ A FUNCIONAR");
    }
    /*
 menu_principal:
    printf("**Menu Principal**\n");
    printf("1)Criar Novo Tópico\n");
    printf("2)Gerir Tópicos\n");
    printf("3)Gerir Utilizadores\n");
    printf("4)Ver Estatísticas\n");
    printf("5)Logout\n");
    printf("A Sua Opção: ");
    scanf("%d",&i);
    while(i <= 0 || i > 5){
      printf("Opção não válida \n");
      printf("A Sua Opção: ");
      scanf("%d", &i);
    }
    if(i==1)
      goto criar_tópicos;
    if(i==2)
      goto gestão_de_tópicos;
    if(i==3)
      goto gestão_de_utilizadores;
    if(i==4)
      goto estatísticas;
    if(i==5)
      return 0;
    */
}                      
