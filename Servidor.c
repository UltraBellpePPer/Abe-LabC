#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

typedef struct{
  char username[12];
  char password[15];
  int tipo;
  }login;

typedef struct{
  char topico[40];
}topicos;

// O carrega_utilizadores serve para carregar o TXT para a struct login que está definida em cima
int carrega_admin(login peepz[]){
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

int carregar_utilizadoresx(login peepz[]){
FILE *fx; char s[40],n=0,i,j;
	fx=fopen("Clientesx.txt","r");
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


void listar_utilizadores(login peepz[],int n){
  printf("------------------------------------\n");
  printf("---- Nome ---------- Password ------\n");
  printf("------------------------------------\n");
  for(int i = 0; i < n; i++){
    printf("%d -> %s --- %s\n",(i+1),peepz[i].username,peepz[i].password);
  }
}


int adicionar_utilizador(login clientes[],login clientesx[],int i,int n){
  FILE *fx;
  int x= 0;
  fx = fopen("Clientes.txt","a");
  for(int j = 0; j < n; j++){
    if(strcmp(clientes[j].username,clientesx[i].username) == 0)
      x = 1;
  }
  if(strlen(clientesx[i].username) > 0 && x == 0)
    fprintf(fx,"%s;%s;1\n",clientesx[i].username,clientesx[i].password);
  fclose(fx);
  n = carregar_utilizadores(clientes);
  return n;
}


int adicionar_topico(topicos top[], char stri[25],int n){
  FILE *fx;
  int x = 0;
  fx = fopen("Topics.txt","a");
  for(int i = 0;i < n;i++){
    if(strcmp(top[i].topico,stri) == 0){
      x = 1;
    }
  }
  if(x == 0){
    fprintf(fx,"%s.txt;",stri);
    n++;
  }
  return n;
}


int atualizar_clientesx(login clientesx[],int n,int l){
  FILE *fx;
  fx = fopen("Clientesx.txt","w");
  for(int i = 0; i < n;i++){
    if(i != l && strlen(clientesx[i].username) == 11)
      fprintf(fx,"%s;%s;1\n",clientesx[i].username,clientesx[i].password);
  }
  fclose(fx);
  for(int i = 0; i<n;i++){
    memset(clientesx[i].username, 0, sizeof(clientesx[i].username));
    memset(clientesx[i].password, 0, sizeof(clientesx[i].password));
    clientesx[i].tipo = 0;
  }
  n = carregar_utilizadoresx(clientesx);
}


void listar_topicos(topicos top[], int n){
  printf("-----------------------------\n");
  printf("---- Topicos -----------------\n");
  for(int i = 0; i< n; i++){
    printf("%d -> %s\n",(i+1),top[i].topico);
  }
}

int remover_topicos(topicos top[] , int i, int n){
  FILE *fx;
  fx = fopen("Topics.txt","w");
  for(int j = 0; j < n;j++){
    if(j != i)
      fprintf(fx,"%s;\n",top[i].topico);
  }
  fclose(fx);
  n = carregar_topicos(top);
  return n;
}

int main(void){
  char stri[25];
  int n3;
  topicos top[100];
  n3 = carregar_topicos(top);
  int i = 0;
  char User[20];
  char paswrd[20];
  login peepz[5];
  login clientes[1000];
  login clientesx[1000];
  int n,n1,n2;
  n1 = carrega_admin(peepz);
  n = carregar_utilizadores(clientes);
  n2 = carregar_utilizadoresx(clientesx);
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
    printf("Password:");
    scanf("%s", paswrd);
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
 menu_principal:
    printf("**Menu Principal**\n");
    printf("1)Gerir Tópicos\n");
    printf("2)Gerir Utilizadores\n");
    printf("3)Ver Estatísticas\n");
    printf("4)Logout\n");
    printf("A Sua Opção: ");
    scanf("%d",&i);
    while(i <= 0 || i > 4){
      printf("Opção não válida \n");
      printf("A Sua Opção: ");
      scanf("%d", &i);
    }
    if(i==1){//Gerir Tópicos
      printf("1) Listar Tópicos \n");
      printf("2) Criar novo Tópico \n");
      printf("3) Remover Tópic0 \n");
      printf("A sua Opção:");
      scanf("%d",&i);
      while(i < 1 || i > 3){
	printf("Opção Inválida \n");
	printf("A sua Opção:");
	scanf("%d",&i);
      }
      if(i == 1){//Listar Topicos
	listar_topicos(top,n3);
      }
      if(i == 2){//Adicionar Tópicos
	menu_top:
	printf("Indique o nome do seu tópico\n");
	printf("O Tópico pode ter no máximo 20 caracteres\n");
	printf("Não pode conter caracteres especiais\n");
	printf("Tópico :");
	scanf("%s",stri);
	if(strlen(stri) > 20){
	  printf("Tópico excede o número de caracteres");
	  goto menu_top;
	}
	n3 = adicionar_topico(top,stri,n3);
	n++;
	printf("1) Adicionar novo tópico \n");
	printf("2) Voltar ao menu \n");
	printf("A sua Opção:");
	scanf("%d",&i);
	while(i < 1 || i > 2){
	  printf("Opção Invalída \n");
	  printf("A sua Opção:");
	  scanf("%d",&i);
	}
	if(i == 1){
	  goto menu_top;
	}
	if(i == 2){
	  goto menu_principal;
	}
      }
      if(i == 3){//remover topicos;
	while(i > 0){
	  listar_topicos(top,n3);
	  printf("Indique os Tópicos a remover\n");
	  printf("Pressione 0 para terminar o processo de escolha\n");
	  printf("A sua Opção:");
	  scanf("%d",&i);
	  n3 = remover_topicos(top,(i-1),n3);
	  }
      }
      goto menu_principal;
    }
    if(i==2){//Gerir Utilizadores
      printf("1) Listar utilizadores \n");
      printf("2) Validar novos utilizadores \n");
      printf("3) Recusar novos utilizadores \n");
      printf("A sua Opção:");
      scanf("%d",&i);
      while(i < 1 || i > 3){
	printf("Opção Invalída\n");
	printf("A sua Opção:");
	scanf("%d",&i);
      }
      if(i == 1){//Listar utilizadores
	listar_utilizadores(clientes,n);
      }
      if(i == 2){//Validar utilizadores
	while(i != 0){
	  listar_utilizadores(clientesx,n2);
	  printf("Indique os utilizadores que quer adicionar\n");
	  printf("Pressione 0 para terminar o processo de escolha\n");
	  printf("A sua Opção:");
	  scanf("%d",&i);
	  if(i != 0){
	    n = adicionar_utilizador(clientes,clientesx,(i-1),n);
	  }
	  atualizar_clientesx(clientesx,n2,(i-1));
	}
      }
      if(i == 3){//Recusar utilizadores
	while(i != 0){
	  listar_utilizadores(clientesx,n2);
	  printf("Indique os utilizadores que quer adicionar\n");
	  printf("Pressione 0 para terminar o processo de escolha\n");
	  printf("A sua Opção:");
	  scanf("%d",&i);
	  atualizar_clientesx(clientesx,n2,(i-1));
	}
      }
      goto menu_principal;
    }
    if(i==3){//Estatisticas
      printf("1) Número de utilizadores \n");
      printf("2) Número de tópicos \n");
      printf("A sua Opção:");
      scanf("%d",&i);
      while(i < 1 || i > 2){
	printf("Opção Invalída\n");
	printf("A sua Opção:");
	scanf("%d",&i);
      }
      if(i == 1){//Número de utilizadores
	printf("*----------------------*\n");
	printf("|Existem %d utilizadores|\n",n);
	printf("*----------------------*\n");
	goto menu_principal;
      }
      if(i == 2){//Número de Tópicos
	printf("-----------------\n");
	printf("Existem %d Tópicos\n",n3);
	printf("-----------------\n");
	goto menu_principal;
      }
    }
    if(i==4){//Logout
      goto menu;
    }
    return 0;
}
