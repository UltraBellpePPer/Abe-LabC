#include <stdio.h>

int main(void){
  int i = 0;
  String str;
  menu:
  printf("**Menu de registo** \n");
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
    
    printf("Nome de utilizador:");
    scanf("")
  }
}
