#include <stdio.h>

int i= 0;
menu_aut:
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
if(i == 1){
 login:
   printf("Nome de utilizador: ");
   scanf("%s",USER);

   // Aqui falta a parte de confirmar a autenticação. Depois se a seguir n for buf!=USER , altera também :)//
   
   if(buf!=USER){
     printf("Utilizador inválido\n");
     printf("1)Voltar ao menu\n");
     printf("2)Tentar novamente\n");
     scanf("%d", &i);
     while (i <= 0 || i > 2){
       printf("Opção inválida \n");
       printf("A Sua Opção: ");
       scanf("%d", &i);
     }
     if(i==1)
       goto menu_aut;
     if (i==2)
       goto login;
   }
 }
   //aposto q me esqueci de umas chavetas pqp//
   //vou fazer a parte do menu principal,vou fazer o tal atalho, por isso quando conseguires fazer o login mandas a cena para lá,//
    //btw se souberes como fazer a parte do registo diz como q eu faço//
if(i == 2){
  char utilizador[50], utilizador2[50];
 menu_registo:
  printf("Novo nome de utilizador: \n");
  scanf("%s", &utilizador)
  printf("Confirm utilizador
  scanf("
  if(strcmp(utilizador, utilizador2) == 0 ){
  //
   
    
