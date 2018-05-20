#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct{
  char username[12];
  char password[15];
  char numero[16];
}login;

typedef struct{
  char topico[40];
}topicos;

void ver_sub(topicos subtop[],int i,topicos top[],int j){
  FILE *fx;
  char str1[80] = "Topics/";
  char s[80];
  int c;
  strcat(str1,top[j].topico);
  strcat(str1,"/");
  strcat(str1,subtop[i].topico);
  strcat(str1,".txt");
  fx = fopen(str1,"r");
  while((c = getc(fx)) != EOF)
    putchar(c);
  fclose(fx);
}


void comenta_sub(topicos subtop[], int i,login peepz[],int u,topicos top[],int j){
  FILE *fx;
  char str1[80] = "Topics/";
  char str2[60];
  int x = 1;
  int t = 0;
  strcat(str1,top[j].topico);
  strcat(str1,"/");
  strcat(str1,subtop[i].topico);
  strcat(str1,".txt");
  fx = fopen(str1,"a");
  printf("Pode agora escrever o seu Comentário\n");
  printf("Submeta uma palavra de cada vez\n");
  printf("Coloque um ; quando for para mudar de linha ou terminar");
  fprintf(fx,"%s \n",peepz[u].username);
 Escrever:
  scanf("%s",str2);
  fprintf(fx,"%s",str2);
  fprintf(fx," \n");
  printf("1 -> Continuar \n");
  printf("2 -> Terminar \n");
  printf("A sua Opção:");
  scanf("%d",&x);
  while(x < 1 || x > 2){
    printf("Opção Inválida \n");
    printf("A sua Opção:");
    scanf("%d",&x);
  }
    if(x == 1){
      goto Escrever;
  }
}
void listar_topicos(topicos top[], int n){
  printf("------------------------------\n");
  printf("---- Topicos -----------------\n");
  for(int i = 0; i < n; i++){
    printf("%d -> %s\n",(i+1),top[i].topico);
  }
}

void criar_subtop(topicos subtop[], int i,char stri[],topicos top[]){
  char str1[80] = "Topics/";
  char str2[80] = "Topics/";
  FILE *fx;
  strcat(str1,top[i].topico);
  strcat(str1,"/");
  strcat(str1,stri);
  strcat(str1,".txt");
  fx = fopen(str1,"w");
  fclose(fx);
  strcat(str2,top[i].topico);
  strcat(str2,"/Subtopicos.txt");
  fx = fopen(str2,"a");
  fprintf(fx,"%s;",stri);
  fclose(fx);
}

void recarregar_utilizadores(char str[],login peepz[],int n){
  FILE *fx;
  fx = fopen(str,"w");
  for(int i = 0;i < n;i++){
    fprintf(fx,"%s;%s;%s;\n",peepz[i].username,peepz[i].password,peepz[i].numero);
    }
}

int carregar_subtop(topicos subtopi[],int i,topicos top[]){
  char str1[80] = "Topics/";
  FILE *fx;
  char s[80];
  int l, n = 0;
  strcat(str1,top[i].topico);
  strcat(str1,"/Subtopicos.txt");
  fx = fopen(str1,"r");
  while(fgets(s,80,fx)){
    for(i = 0;s[i] != ';';i++) subtopi[n].topico[i] = s[i];
    n++;
  }
  fclose(fx);
  return n;
}

int carregar_utilizadores(login peepz[]){
FILE *fx; char s[80],n=0,i,j;
	fx=fopen("Clientes.txt","r");
	while(fgets(s,80,fx)){
	  for(i=0;s[i]!=';';i++) peepz[n].username[i]=s[i];
	  peepz[n].username[i]='\0';
	  i++;
	  for(j = 0;s[i]!=';';i++) peepz[n].password[j++]=s[i];
	  peepz[n].password[j]='\0';
	  i++;
	  for(j = 0; s[i] != ';';i++) peepz[n].numero[j++]=s[i];
	  n++;
	}
	fclose(fx);
	return n;
}
int adicionar_utilizador(login peepz[],int n,char User[],char Userpass[],char Usernum[]){
  FILE *fx;
  fx=fopen("Clientesx.txt","a");
  fprintf(fx,"%s;%s;%s;\n",User,Userpass,Usernum);
  n++;
  for(int i = 0;i < 12;i++)
    peepz[n].username[i] = User[i];
  for(int i = 0; i < strlen(Userpass); i++)
    peepz[n].password[i] = Userpass[i];
  for(int i = 0; i < strlen(Usernum); i++)
    peepz[n].numero[i] = Usernum[i];
}

int carregar_topicos(topicos top[]){
  FILE *fx;
  char s[40];
  int n=0, i;
  fx=fopen("Topics.txt","r");
    while(fgets(s,40,fx)){
      for(i = 0; s[i] != ';';i++){
	top[n].topico[i] = s[i];
      }
      n++;
    }
    return n;
}

int main(void){
  int i= 0,n,j = 0,y = 0,z = 0,u;
  char User[12];
  login peepz[1000];
  FILE *fx;
  char Userpass[16];
  char paswrd[16];
  char Usernum[16];
  topicos top[100];
  int n3;
  int n2;
  topicos subtops[40];
  char stri[40];
 menu_aut:
  n = carregar_utilizadores(peepz);
  n3 = carregar_topicos(top);
  printf("**Menu de autenticação** \n");
  printf("1)Login \n");
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
    printf("O seu nome de utilizador deve ser o seu número mecanográfico.\n");
    printf("Por exemplo up201705687. \n");
    printf("O seu nome:");
    scanf("%s",User);
    for(i = 0; i < n;i++){
      if(strcmp(User,peepz[i].username) == 0){
	i = -1;
	break;
      }
    } 
    if(strlen(User) != 11 || i == -1){
      printf("Username Inválido ou Já Existente\n");
      printf("1) Tentar Novamente \n");
      printf("2) Voltar ao menu \n");
      printf("A sua Opção:");
      scanf("%d" , &i);
      while(i <= 0 || i > 2){
	printf("Opção inválida \n");
	printf("A Sua Opção: ");
	scanf("%d", &i);
    }
      if(i == 1){
	goto menu_reg;
      }
      if(i == 2){
	goto menu_aut;
      }
    }
    printf("Indique agora a sua password.\n");
    printf("Regras: 1 -> Deve conter no mínimo 4 caracteres e no máximo 15\n");
    printf("        2 -> Não pode conter ; e deve ter no minimo uma letra e um algarismo\n");
    printf("A sua Password:");
    scanf("%s",Userpass);
    for(int x = 0;x < strlen(Userpass);x++){
      if(isdigit(Userpass[x])){
        y = 1;
      }
      if(isalpha(Userpass[x])){
	z = 1;
      }
      if(y == 1 && z == 1){
	break;
      }
    }
    if(!(y == 1 && z == 1 && (strlen(Userpass) >= 4 && strlen(Userpass) <= 15))){
      printf("Password Inválida \n");
      printf("1) Tentar Novamente \n");
      printf("2) Voltar ao menu \n");
      printf("A sua Opção:");
      scanf("%d" , &i);
      while(i <= 0 || i > 2){
	printf("Opção inválida \n");
	printf("A Sua Opção: ");
	scanf("%d", &i);
    }
      if(i == 1){
	goto menu_reg;
      }
      if(i == 2){
	goto menu_aut;
      }
    }
    else{
      printf("Indique agora o seu número de telefone\n");
      printf("O seu número:");
      scanf("%s",Usernum);
      n = adicionar_utilizador(peepz,n,User,Userpass,Usernum);
    }
    printf("Para iniciar o seu login tem que esperar que os Admins aceitem o seu pedido\n");
    goto menu_aut;
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
 password:
  u = i;
  printf("Password:");
  scanf("%s",paswrd);
  if(strcmp(paswrd,peepz[i].password) != 0){
      printf("Password inválida\n");
      printf("1)Voltar ao menu\n");
      printf("2)Tentar novamente\n");
      printf("A sua Opção:");
      scanf("%d", &i);
      while(i <= 0 || i > 2){
	printf("Opção não válida \n");
	printf("A Sua Opção: ");
	scanf("%d", &i);
      }
      if(j==1)
	goto menu_aut;
      if(j==2)
	goto password;
  }
 menu_principal:
  printf("1 -> Gestão  de conta.\n");
  printf("2 -> Ver Tópicos\n");
  printf("3 -> Estatisticas\n");
  printf("4 -> Logout \n");
  printf("A sua Opção:");
  scanf("%d",&i);
  while(i < 1 || i > 4){
    printf("Opção Inválida \n");
    printf("A sua Opção");
    scanf("%d",&i);
  }
  if(i == 1){//Gestão de Conta
  menu_gestao:
    printf("1 -> Alterar Utilizador \n");
    printf("2 -> Alterar Password \n");
    printf("3 -> Alterar Número \n");
    printf("A sua Opção:");
    scanf("%d",&i);
    while(i < 1 || i > 3){
      printf("Opção Inválida \n");
      printf("A sua Opção:");
      scanf("%d",&i);
    }
    if(i == 1){ // Alterar Utilizador
      char NewUser[12];
      printf("Indique o novo nome de utilizador \n");
      printf("Nome :");
      scanf("%s",NewUser);
      if(strlen(NewUser) == 11){
	  for(int h = 0;h < strlen(NewUser);h++){
	    peepz[u].username[h] = NewUser[h];
	  }
      }
      printf("1 -> Voltar ao menu de gestão da conta \n");
      printf("2 -> Voltar ao menu principal \n");
      printf("A sua Opção:");
      scanf("%d",&j);
      while( j < 1 || j > 2){
	printf("Opção Inválida \n");
	printf("A sua Opção:");
	scanf("%d",&j);
      }
      if(j == 1){
	goto menu_gestao;
      }
      if(j == 2){
	recarregar_utilizadores("Clientes.txt",peepz,n);
	goto menu_principal;
      }
    }
    if(i == 2){ // Alterar password
      char NewUserpass[16];
      printf("Indique a nova password\n");
      printf("Regras: 1 -> Deve conter no mínimo 4 caracteres e no máximo 15\n");
      printf("        2 -> Não pode conter ; e deve ter no minimo uma letra e um algarismo\n");
      printf("Password: ");
      scanf("%s",NewUserpass);
      y = 0;
      z = 0;
      for(int x = 0;x < strlen(NewUserpass);x++){
	if(isdigit(NewUserpass[x])){
	  y = 1;
	}
	if(isalpha(NewUserpass[x])){
	  z = 1;
	}
	if(y == 1 && z == 1){
	  break;
	}
      }
      if(!(y == 1 && z == 1 && (strlen(NewUserpass) >= 4 && strlen(NewUserpass) <= 15))){
	printf("Password Inválida \n");
	printf("1) Tentar Novamente \n");
	printf("2) Voltar ao menu \n");
	printf("A sua Opção:");
	scanf("%d" , &i);
	while(i <= 0 || i > 2){
	  printf("Opção inválida \n");
	  printf("A Sua Opção: ");
	  scanf("%d", &i);
	}
	if(i == 1){
	  goto menu_gestao;
	}
	if(i == 2){
	  recarregar_utilizadores("Clientes.txt",peepz,n);
	  goto menu_principal;
	}
      }
      memset(peepz[u].password,0,sizeof(peepz[u].password));
      for(int h = 0;h < strlen(NewUserpass);h++){
	peepz[u].password[h] = NewUserpass[h];
      }
      printf("1 -> Voltar ao menu de gestão da conta \n");
      printf("2 -> Voltar ao menu principal \n");
      printf("A sua Opção:");
      scanf("%d",&j);
      while( j < 1 || j > 2){
	printf("Opção Inválida \n");
	printf("A sua Opção:");
	scanf("%d",&j);
      }
      if(j == 1){
	goto menu_gestao;
      }
      if(j == 2){
	recarregar_utilizadores("Clientes.txt",peepz,n);
	goto menu_principal;
      }
    }
    if(i == 3){ // Alterar Número
      char NewUsernum[16];
      printf("Indique o seu novo Número \n");
      printf("Numero:");
      scanf("%s",NewUsernum);
      for(int h = 0; h < strlen(NewUsernum);h++){
	peepz[u].numero[h] = NewUsernum[h];
      }
      printf("1 -> Voltar ao menu de gestão da conta \n");
      printf("2 -> Voltar ao menu principal \n");
      printf("A sua Opção:");
      scanf("%d",&j);
      while( j < 1 || j > 2){
	printf("Opção Inválida \n");
	printf("A sua Opção:");
	scanf("%d",&j);
      }
      if(j == 1){
	goto menu_gestao;
      }
      if(j == 2){
	recarregar_utilizadores("Clientes.txt",peepz,n);
	goto menu_principal;
      }
    }
  }
  if(i == 2){// Tudo sobre Tópicos
  menu_top:
    printf("Escolha um dos seguintes tópicos \n");
    listar_topicos(top,n3);
    printf("A sua Opção:");
    scanf("%d",&i);
    n2 = carregar_subtop(subtops,(i-1),top);
    listar_topicos(subtops,n2);
    printf("\n");
    printf("   ***Tópicos***   \n");
    printf("1 -> Criar SubTópicos\n");
    printf("2 -> Comentar SubTópico\n");
    printf("3 -> Ver SubTópico\n");
    printf("4 -> Voltar ao Menu Principal\n");
    printf("5 -> Voltar ao Menu de Tópicos\n");
    printf("A sua Opção:");
    scanf("%d",&j);
    while(j < 1 || j > 5){
      printf("Opção Inválida \n");
      printf("A sua Opção:");
      scanf("%d",&j);
    }
    if(j == 1){//Criar novo Subtópico
      printf("Indique o nome do seu Subtópico:");
      scanf("%s",stri);
      criar_subtop(subtops,(i-1),stri,top);
      goto menu_top;
	}
    if(j == 2){//Comentar Tópico
      printf("Indique o subtopico pretendido");
      printf("A sua Opção");
      scanf("%d",&j);
      while(j < 1 || j > n2){
	printf("Opção Inválida");
	printf("A sua Opção");
      }
      comenta_sub(subtops,(j-1),peepz,u,top,(i-1));
    }
    if(j == 3){//Ver Subtopico
      printf("Indique o subtopico pretendido");
      printf("A sua Opção");
      scanf("%d",&j);
      while(j < 1 || j > n2){
	printf("Opção Inválida");
	printf("A sua Opção");
      }
      ver_sub(subtops,(j-1),top,(i-1));
    }
    if(j == 4){//Voltar ao menu principal
      goto menu_principal;
    }
    if(j == 5){//Voltar ao menu de Tópicos
      goto menu_top;
    }
  }
  if(i == 3){//Estatisticas
    printf("1 -> Número de utilizadores");
    printf("2 -> Número de tópicos");
    while(i < 1 || i > 2){
      printf("Opção Inválida \n");
      printf("A sua Opção:");
      scanf("%d",&i);
    }
    if(i == 1){// Número de utilizadores
      printf("*----------------------*\n");
      printf("|Existem %d utilizadores|\n",n);
      printf("*----------------------*\n");
      goto menu_principal;
    }
    if(i == 2){// Número de tópicos
      printf("-----------------\n");
      printf("Existem %d Tópicos\n",n3);
      printf("-----------------\n");
      goto menu_principal;
    }
  }
  if(i == 4){
    goto menu_aut;
  }
  return 0;
}
      
