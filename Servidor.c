#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define GREEN "\x1b[32m"
#define RED "\x1B[31m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"
#define RESET "\x1b[0m"


typedef struct{
  char username[12];
  char password[15];
  char numero[16];
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
		for(;s[i] != ';';i++) peepz[n].numero[j++]=s[i];
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
		j=0;
		for(;s[i]!=';';i++) peepz[n].password[j++]=s[i];
		peepz[n].password[j]='\0';
		i++;
	        for(j = 0; s[i] != ';';i++) peepz[n].numero[j++]=s[i];
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
FILE *fx; char s[80],n=0,i,j;
	fx=fopen("Clientesx.txt","r");
	while(fgets(s,80,fx)){
		for(i=0;s[i]!=';';i++) peepz[n].username[i]=s[i];
		peepz[n].username[i]='\0';
		i++;
		j=0;
		for(;s[i]!=';';i++) peepz[n].password[j++]=s[i];
		peepz[n].password[j]='\0';
		i++;
	        for(j = 0; s[i] != ';';i++) peepz[n].numero[j++]=s[i];
                n++;
	}
	fclose(fx);
	return n;
}


void listar_utilizadores(login peepz[],int n){
  printf("%s \n",peepz[1].numero);
  printf("------------------------------------------------\n");
  printf("---- " YELLOW "Nome " RESET "---------- " YELLOW "Password " RESET "---- " YELLOW "Número " RESET "------\n");
  printf("------------------------------------------------\n");
  for(int i = 0; i < n; i++){
    printf(YELLOW "%d " RESET "-> " CYAN "%s " RESET "--- " CYAN "%s " RESET "--- " YELLOW "%s " RESET "\n",(i+1),peepz[i].username,peepz[i].password,peepz[i].numero);
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
  char str1[40] = "Topics/";
  fx = fopen("Topics.txt","a");
  for(int i = 0;i < n;i++){
    if(strcmp(top[i].topico,stri) == 0){
      x = 1;
    }
  }
  if(x == 0){
    fprintf(fx,"%s;",stri);
    n++;
  }
  fclose(fx);
  strcat(str1,stri);
  mkdir(str1);
  strcat(str1,"/Subtopicos.txt");
  fx = fopen(str1,"w");
  fclose(fx);
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
    memset(clientesx[i].numero, 0, sizeof(clientesx[i].numero));
  }
  n = carregar_utilizadoresx(clientesx);
}


void listar_topicos(topicos top[], int n){
  printf("-----------------------------\n");
  printf("---- " YELLOW "Topicos " RESET "-----------------\n");
  for(int i = 0; i< n; i++){
    printf(YELLOW "%d " RESET "-> " YELLOW "%s" RESET "\n",(i+1),top[i].topico);
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
  printf(GREEN "          **Menu de autenticação**" RESET "\n");
  printf(BLUE "1)  " CYAN "Login / autenticação" RESET "\n");
  printf(BLUE "2)  " CYAN "Sair" RESET "\n");
  printf(CYAN "A Sua Opção: " RESET);
  scanf("%d", &i);
  while(i <= 0 || i > 2){
    printf(RED "Opção não válida" RESET "\n");
    printf(CYAN "A Sua Opção: " RESET);
    scanf("%d", &i);
  }
  if(i == 2){
    return 0;
  }
  else{
  login:
    printf(CYAN "Nome de utilizador:" RESET);
    scanf("%s",User);
    if(strcmp(User,peepz[0].username) != 0){ // O strcmp serve para comparar duas Strings. As duas Strings são iguais quando o resulatado é 0
      printf(RED "Utilizador inválido" RESET "\n");
      printf(BLUE "1)  " CYAN "Voltar ao menu" RESET "\n");
      printf(BLUE "2)  " CYAN "Tentar novamente\n");
      printf("A sua Opção:" RESET);
      scanf("%d", &i);
      while(i <= 0 || i > 2){
	printf(RED "Opção não válida" RESET "\n");
	printf(CYAN "A Sua Opção: " RESET);
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
    printf(CYAN "Password:" RESET);
    scanf("%s", paswrd);
    if(strcmp(paswrd,peepz[0].password) != 0){
      printf(RED "Password inválida" RESET "\n");
      printf(BLUE "1)  " CYAN "Voltar ao menu" RESET "\n");
      printf(BLUE "2)  " CYAN "Tentar novamente" RESET "\n");
      printf(CYAN "A Sua Opção:" RESET);
      scanf("%d", &i);
      while(i <= 0 || i > 2){
	printf(RED "Opção não válida" RESET "\n");
	printf(CYAN "A Sua Opção: " RESET);
	scanf("%d", &i);   
      }
	if(i==1)
	  goto menu;
	if(i==2)
	  goto password;
    }
 menu_principal:
    printf(GREEN "          **Menu Principal**" RESET "\n");
    printf(BLUE "1)  " CYAN "Gerir Tópicos" RESET "\n");
    printf(BLUE "2)  " CYAN "Gerir Utilizadores" RESET "\n");
    printf(BLUE "3)  " CYAN "Ver Estatísticas" RESET "\n");
    printf(BLUE "4)  " CYAN "Logout" RESET "\n");
    printf(CYAN "A Sua Opção: " RESET);
    scanf("%d",&i);
    while(i <= 0 || i > 4){
      printf(RED "Opção não válida" RESET "\n");
      printf(CYAN "A Sua Opção: " RESET);
      scanf("%d", &i);
    }
    if(i==1){//Gerir Tópicos
      printf(GREEN "          **Gerir Tópicos**" RESET "\n"); 
      printf(BLUE "1)  " CYAN "Listar Tópicos" RESET "\n");
      printf(BLUE "2)  " CYAN "Criar novo Tópico" RESET "\n");
      printf(BLUE "3)  " CYAN "Remover Tópico" RESET "\n");
      printf(CYAN "A sua Opção:" RESET);
      scanf("%d",&i);
      while(i < 1 || i > 3){
	printf(RED "Opção Inválida" RESET "\n");
	printf(CYAN "A sua Opção:" RESET);
	scanf("%d",&i);
      }
      if(i == 1){//Listar Topicos
	printf(GREEN "          **Lista de Tópicos**" RESET "\n");
	listar_topicos(top,n3);
      }
      if(i == 2){//Adicionar Tópicos
	menu_top:
	printf(GREEN "          **Adicionar Tópicos**\n" RESET);
	printf(CYAN "Indique o nome do seu tópico" RESET "\n");
	printf(MAGENTA  " O Tópico pode ter no máximo 20 caracteres"  RESET "\n");
	printf(MAGENTA " Não pode conter caracteres especiais" RESET "\n");
	printf(CYAN "Tópico :"RESET);
	scanf("%s",stri);
	if(strlen(stri) > 20){
	  printf(RED "Tópico excede o número de caracteres" RESET);
	  goto menu_top;
	}
	n3 = adicionar_topico(top,stri,n3);
	n++;
	printf(BLUE "1)  " CYAN "Adicionar novo tópico" RESET "\n");
	printf(BLUE "2)  " CYAN "Voltar ao menu" RESET "\n");
	printf(CYAN "A sua Opção:" RESET);
	scanf("%d",&i);
	while(i < 1 || i > 2){
	  printf(RED "Opção Invalída" RESET "\n");
	  printf(CYAN "A sua Opção:" RESET);
	  scanf("%d",&i);
	}
	if(i == 1){
	  goto menu_top;
	}
	if(i == 2){
	  goto menu_principal;
	}
      }
      if(i == 3){//remover topicos
	printf(GREEN "          **Remover tópicos**" RESET "\n");
	while(i > 0){
	  listar_topicos(top,n3);
	  printf(CYAN "Indique os Tópicos a remover" RESET "\n");
	  printf(MAGENTA "Pressione 0 para terminar o processo de escolha"RESET "\n");
	  printf(CYAN "A sua Opção:" RESET);
	  scanf("%d",&i);
	  n3 = remover_topicos(top,(i-1),n3);
	  }
       }
      goto menu_principal;
    }
    if(i==2){//Gerir Utilizadores
      printf(GREEN "          **Gestão de Utilizadores**" RESET "\n");
      printf(BLUE "1)  " CYAN "Listar utilizadores" RESET "\n");
      printf(BLUE "2)  " CYAN "Validar novos utilizadores" RESET "\n");
      printf(BLUE "3)  " CYAN "Recusar novos utilizadores" RESET "\n");
      printf(CYAN "A sua Opção:" RESET);
      scanf("%d",&i);
      while(i < 1 || i > 3){
	printf(RED "Opção Invalída" RESET "\n");
	printf(CYAN "A sua Opção:" RESET);
	scanf("%d",&i);
      }
      if(i == 1){//Listar utilizadores
	printf(GREEN "          **Lista de Utilizadores**" RESET "\n");
	listar_utilizadores(clientes,n);
      }
      if(i == 2){//Validar utilizadores
	printf(GREEN "          **Validação de Utilizadores**" RESET "\n");
	while(i != 0){
	  listar_utilizadores(clientesx,n2);
	  printf(CYAN "Indique os utilizadores que quer adicionar" RESET "\n");
	  printf(MAGENTA "Pressione 0 para terminar o processo de escolha" RESET "\n");
	  printf(CYAN "A sua Opção:" RESET);
	  scanf("%d",&i);
	  if(i != 0){
	    n = adicionar_utilizador(clientes,clientesx,(i-1),n);
	  }
	  atualizar_clientesx(clientesx,n2,(i-1));
	}
      }
      if(i == 3){//Recusar utilizadores
	printf(GREEN "          **Recusar Utilizadores" RESET);
	while(i != 0){
	  listar_utilizadores(clientesx,n2);
	  printf(CYAN "Indique os utilizadores que quer adicionar" RESET "\n");
	  printf(MAGENTA "Pressione 0 para terminar o processo de escolha" RESET "\n");
	  printf(CYAN "A sua Opção:" RESET);
	  scanf("%d",&i);
	  atualizar_clientesx(clientesx,n2,(i-1));
	}
      }
      goto menu_principal;
    }
    if(i==3){//Estatisticas
      printf(GREEN "          **Estatísticas**\n" RESET);
      printf(BLUE "1)  " CYAN "Número de utilizadores" RESET "\n");
      printf(BLUE "2)  " CYAN "Número de tópicos" RESET "\n");
      printf(CYAN "A sua Opção:" RESET);
      scanf("%d",&i);
      while(i < 1 || i > 2){
	printf(RED "Opção Invalída" RESET "\n");
	printf(CYAN "A sua Opção:" RESET);
	scanf("%d",&i);
      }
      if(i == 1){//Número de utilizadores
	printf(GREEN "          **Número de utilizadores**\n" RESET);
	printf("*----------------------*\n");
	printf(CYAN"|Existem %d utilizadores|" RESET "\n",n);
	printf("*----------------------*\n");
	goto menu_principal;
      }
      if(i == 2){//Número de Tópicos
	printf(GREEN "          **Número de Tópicos**\n" RESET);
	printf("-----------------\n");
	printf(CYAN "Existem %d Tópicos" RESET "\n",n3);
	printf("-----------------\n");
	goto menu_principal;
      }
    }
    if(i==4){//Logout
      goto menu;
    }
    return 0;
}
