#include <stdio.h>

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"
int main(void){

  int i = 0;
  char USER[30];
  FILE *ptr_file;
  char buf [1000];
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
    scanf("%s",USER);
    ptr_file =fopen ("AdminLogin.txt","r");
    while (fgets(buf,1000,ptr_file)!=NULL) {
	if(buf==USER)
	  break;
      }
    if(buf!=USER){
      printf("Utilizador inválido\n");
      printf("1)Voltar ao menu\n");
      printf("2)Tentar novamente\n");
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
  } 
}   
	
