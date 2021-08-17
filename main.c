#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Gastos{
  float valor;
  int categoria;
  char desc[100];
  char data[12];
};

struct Receita{
  float valor;
  char desc[100];
  char data[12];
};

struct Excluir{
  float valor;
  int categoria;
  char desc[100];
  char data[12];
};

void criaCSS()
{
  FILE* f = fopen("style.css", "w");
  fprintf(f, "@import url('https://fonts.googleapis.com/css2?family=Montserrat:ital,wght@1,500&display=swap');\n");
  fprintf(f, "@import url('https://fonts.googleapis.com/css2?family=Montserrat:ital,wght@1,500&display=swap');\n");
  fprintf(f, "*{margin: 0;padding: 0;outline: 0;}\n");
  fprintf(f, ".filter{ position: absolute; top: 0; left: 0; right: 0; bottom: 0; z-index: 1; opacity: 0.7; background: rgb(173,85,255); background: radial-gradient(circle, rgba(173,85,255,1) 0%%, rgba(5,40,126,1) 100%%);}\n");
  fprintf(f, "h1{position: absolute;font-family: 'Lato', sans-serif;font-size: 40pt;color: #1a237e;top: 200px;left: 600px;word-spacing: 2px;}\n");
  fprintf(f, "table{position: absolute;z-index: 2;left: 50%%;top: 50%%;transform: translate(-50%%, -50%%);width: 60%%;background: white;text-align: center;border-collapse: collapse;border-radius: 15px 15px 15px 15px;overflow: hidden;box-shadow: 5px 5px 12px rgba(32, 32, 32, 0.3);}\n");
  fprintf(f, "th{background: #3f51b5;color: white;text-transform: uppercase;font-family: 'Lato', sans-serif;}\n");
  fprintf(f, "th,td{padding: 10px 15px;}\n");
  fprintf(f, "td{font-family: 'Source Code Pro', sans-serif;}\n");
  fprintf(f, "tr:nth-child(odd){background: #eeeeee;}\n");
  fclose(f);
}

void cadastroReceita()
{
  float valor;
  int i=0;
  char descricao[100];
  int salva=0, dia, mes, ano;
  int valor_aceito=0, descricao_aceito=0, salva_aceito=0;
  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);
  puts("------------------------------------");
  puts("Cadastro de receita");
  while (valor_aceito==0){
    printf("Valor (ou digite 0 para voltar ao menu): ");
    scanf("%f", &valor);
    while (valor < 0){
      printf("O valor nao pode ser negativo.\n");
      printf("Valor: ");
      scanf("%f", &valor);
    }
    if (valor>0){
      valor_aceito=1;
    } else if (valor == 0){
      return;
    }
  }
  while (descricao_aceito==0){
    printf("Descricao: ");
    fflush(stdin);
    fgets(descricao, 100, stdin);
    descricao_aceito=1;
  }
  printf("Data: %d/%d/%d\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900);
  dia = data_hora_atual->tm_mday;
  mes = data_hora_atual->tm_mon+1;
  ano = data_hora_atual->tm_year+1900;
  for (i=0; i < strlen(descricao); i++){
    if (descricao[i]=='\n'){
      descricao[i]=descricao[i+1];
    }
  }
  while (salva_aceito==0){
    printf("Se as informacoes estiverem corretas pressione 1 para salvar, se nao 2 para voltar ao menu: ");
    scanf("%d", &salva);
    if (salva==1){
      FILE *fp;
      fp = fopen("receita.txt", "a");
      fprintf(fp, "%.2f;%s;%d/%d/%d\n", valor, descricao, dia, mes, ano);
      fclose(fp);
      puts("--------------------------------");
      puts("| Receita gravada com sucesso! |");
      puts("--------------------------------");
      salva_aceito=1;
    } else if (salva==2){
      salva_aceito=1;
    }
  }
  return;
}

void cadastroGasto()
{
  char descricao[100];
  float valor=0;
  int valor_aceito=0, descricao_aceito=0, salva_aceito=0, categoria_aceito=0;
  int dia=0, mes=0, ano=0, salva=0;
  int categoria=0;
  int i=0;
  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);
  puts("------------------------------------");
  puts("Cadastro de gastos");
  while (valor_aceito==0){
    printf("Valor (ou digite 0 para voltar ao menu): ");
    scanf("%f", &valor);
    while (valor < 0){
      printf("O valor n�o pode ser negativo.\n");
      printf("Valor: ");
      scanf("%f", &valor);
    }
    if (valor>0){
      valor_aceito=1;
    } else if (valor == 0){
      return;
    }
  }
  while (categoria_aceito==0){
    printf("Categoria (Moradia = 1, Estudos = 2, Transporte = 3, Alimentacao = 4, Trabalho = 5 ou Nenhuma = 0): ");
    scanf("%d", &categoria);
    categoria_aceito=1;
  }
  while (descricao_aceito==0){
    printf("Descricao: ");
    fflush(stdin);
    fgets(descricao, 100, stdin);
    descricao_aceito=1;
  }
  printf("Data: %d/%d/%d\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900);
  dia = data_hora_atual->tm_mday;
  mes = data_hora_atual->tm_mon+1;
  ano = data_hora_atual->tm_year+1900;
  for (i=0; i<strlen(descricao); i++){
    if (descricao[i]=='\n'){
      descricao[i]=descricao[i+1];
    }
  }
  while (salva_aceito==0){
    printf("Se as informacoes estiverem corretas pressione 1 para salvar, se nao 2 para voltar ao menu: ");
    scanf("%d", &salva);
    if (salva==1){
      FILE *fp;
      fp = fopen("gastos.txt", "a");
      fprintf(fp, "%.2f;%d;%s;%d/%d/%d\n", valor, categoria, descricao, dia, mes, ano);
      fclose(fp);
      puts("--------------------------------");
      puts("|  Gasto gravado com sucesso!  |");
      puts("--------------------------------");
      salva_aceito=1;
    } else if (salva==2){
      salva_aceito=1;
    }
  }
  return;
}

void relatorioMeses()
{
  int i=0, j=0, t=0;
  char *aux, *gasto, linha[90];
  int resposta_aceita=0;
  char data[100];
  int ano_registrado=0;
  char ano_verifica[5];
  int ano_verifica_aux = 0;
  struct Gastos p[100];
  FILE* fr=fopen("gastos.txt", "r");
  FILE* f=fopen("relatorioMeses.html", "w");
  criaCSS();
  fputs("<html>", f);
  fputs("<head>", f);
  fputs("<link rel=stylesheet href=style.css>", f);
  fputs("</head>", f);

  while (resposta_aceita == 0){
    printf("Insira o ano que deseja ver o relatorio: ");
    scanf("%d", &ano_registrado);
    fflush(stdin);
    resposta_aceita = 1;
  }
  fputs("<body>", f);
  fputs("<div class= 'filter'>", f);
  fputs("</div>", f);
  fprintf(f, "<h1>RELAT�RIO DO ANO %d</h1>", ano_registrado);
  fputs("<table border=1", f);
  fputs("<tr>", f);
  fputs("<th>Data</th>", f);
  fputs("<th>Categoria</th>", f);
  fputs("<th>Descri��o</th>", f);
  fputs("<th>Valor</th>", f);
  fputs("<tr>", f);

  for (i=0; !feof(fr); i++){
    aux = fgets(linha, 90, fr);
    if (aux!=NULL){
      if (aux){
        gasto = strtok(aux, ";");
      }
      for (j=0; gasto != NULL; j++){
        if (j==0){
          p[i].valor = atof(gasto);
        } else if (j==1){
          p[i].categoria = atoi(gasto);
        } else if (j==2){
          strcpy(p[i].desc, gasto);
        } else if (j==3){
          strcpy(data, gasto);
        }
        gasto = strtok(NULL, ";");
      }

      t = 0;

      for (j=0; data[j] != 0; j++){
        if (j == 6 || j == 7 || j == 8 || j == 9){
          ano_verifica[t] = data[j];
          t++;
        } else {
          continue;
        }
      }

      ano_verifica_aux = atoi(ano_verifica);
      if (ano_registrado == ano_verifica_aux){
        fputs("<tr>", f);
        fprintf(f, "<td>%s</td>\n", data);
        if (p[i].categoria == 1){
          fputs("<td>Moradia</td>", f);
        } else if (p[i].categoria == 2){
          fputs("<td>Estudos</td>", f);
        } else if (p[i].categoria == 3){
          fputs("<td>Transporte</td>", f);
        } else if (p[i].categoria == 4){
          fputs("<td>Alimenta��o</td>", f);
        } else if (p[i].categoria == 5){
          fputs("<td>Trabalho</td>", f);
        } else {
          fputs("<td>Nenhuma</td>", f);
        }
        fprintf(f, "<td>%s</td>\n", p[i].desc);
        fprintf(f, "<td>R$%.2f</td>\n", p[i].valor);
        fputs("</tr>", f);
        } else {
          continue;
        }
    }
  }
  fputs("</table>", f);
  fputs("</body>", f);
  fputs("</html>", f);
  fclose(fr);
  fclose(f);
  return;
}

void relatorioCategoria()
{
  int i=0, j=0;
  char *aux, *gasto, linha[90];
  int resposta_aceita=0;
  int categoria_registrado=0;
  int categoria_verifica=0;
  struct Gastos p[100];
  FILE* fr=fopen("gastos.txt", "r");
  FILE* f=fopen("relatorioCategoria.html", "w");
  criaCSS();
  fputs("<html>", f);
  fputs("<head>", f);
  fputs("<link rel=stylesheet href=style.css>", f);
  fputs("</head>", f);

  while (resposta_aceita == 0){
    printf("Insira a categoria que deseja (Moradia = 1, Estudos = 2, Transporte = 3, Alimentacao = 4, Trabalho = 5 ou Nenhuma = 0): ");
    scanf("%d", &categoria_registrado);
    fflush(stdin);
    resposta_aceita = 1;
  }

  fputs("<body>", f);
  fputs("<div class= 'filter'>", f);
  fputs("</div>", f);
  fputs("<h1>RELAT�RIO DE CATEGORIA</h1>", f);
  fputs("<table border=1", f);
  fputs("<tr>", f);
  fputs("<th>Data</th>", f);
  fputs("<th>Categoria</th>", f);
  fputs("<th>Descri��o</th>", f);
  fputs("<th>Valor</th>", f);
  fputs("<tr>", f);

  for (i=0; !feof(fr); i++){
    aux = fgets(linha, 90, fr);
    if (aux!=NULL){
      if (aux){
        gasto = strtok(aux, ";");
      }
      for (j=0; gasto != NULL; j++){
        if (j==0){
          p[i].valor = atof(gasto);
        } else if (j==1){
          p[i].categoria = atoi(gasto);
        } else if (j==2){
          strcpy(p[i].desc, gasto);
        } else if (j==3){
          strcpy(p[i].data, gasto);
        }
        gasto = strtok(NULL, ";");
      }

      if (p[i].categoria == 1){
        categoria_verifica = 1;
      } else if (p[i].categoria == 2){
        categoria_verifica = 2;
      } else if (p[i].categoria == 3){
        categoria_verifica = 3;
      } else if (p[i].categoria == 4){
        categoria_verifica = 4;
      } else if (p[i]. categoria == 5){
        categoria_verifica = 5;
      } else {
        categoria_verifica = 0;
      }

      if (categoria_registrado == categoria_verifica){
        fputs("<tr>", f);
        fprintf(f, "<td>%s</td>\n", p[i].data);
        if (p[i].categoria == 1){
          fputs("<td>Moradia</td>", f);
        } else if (p[i].categoria == 2){
          fputs("<td>Estudos</td>", f);
        } else if (p[i].categoria == 3){
          fputs("<td>Transporte</td>", f);
        } else if (p[i].categoria == 4){
          fputs("<td>Alimenta��o</td>", f);
        } else if (p[i].categoria == 5){
          fputs("<td>Trabalho</td>", f);
        } else {
          fputs("<td>Nenhuma</td>", f);
        }
        fprintf(f, "<td>%s</td>\n", p[i].desc);
        fprintf(f, "<td>R$%.2f</td>\n", p[i].valor);
        fputs("</tr>", f);
      } else {
        continue;
      }
    }
  }
  fputs("</table>", f);
  fputs("</body>", f);
  fputs("</html>", f);
  fclose(fr);
  fclose(f);
}

void relatorioMesEspecifico()
{
  int i=0, j=0, t=0, k=0;
  char *aux, *gasto, linha[90];
  int mes_aceito=0, ano_aceito=0;
  char data[100];
  int ano_registrado=0, mes_registrado=0;
  char ano_verifica[5], mes_verifica[5];
  int ano_verifica_aux = 0, mes_verifica_aux = 0;
  struct Gastos p[100];
  FILE* fr=fopen("gastos.txt", "r");
  FILE* f=fopen("relatorioMesEspecifico.html", "w");
  criaCSS();
  fputs("<html>", f);
  fputs("<head>", f);
  fputs("<link rel=stylesheet href=style.css>", f);
  fputs("</head>", f);

  while (mes_aceito == 0){
    printf("Insira o mes que deseja ver o relatorio: ");
    scanf("%d", &mes_registrado);
    mes_aceito = 1;
  }

  while (ano_aceito == 0){
    printf("Insira o ano do mes que deseja ver o relatorio: ");
    scanf("%d", &ano_registrado);
    ano_aceito = 1;
  }
  fputs("<body>", f);
  fputs("<div class= 'filter'>", f);
  fputs("</div>", f);
  fprintf(f, "<h1>RELAT�RIO DO MES %d/%d</h1>", mes_registrado, ano_registrado);
  fputs("<table border=1", f);
  fputs("<tr>", f);
  fputs("<th>Data</th>", f);
  fputs("<th>Categoria</th>", f);
  fputs("<th>Descri��o</th>", f);
  fputs("<th>Valor</th>", f);
  fputs("<tr>", f);

  for (i=0; !feof(fr); i++){
    aux = fgets(linha, 90, fr);
    if (aux != NULL){
      if (aux){
        gasto = strtok(aux, ";");
      }
      for (j=0; gasto != NULL; j++){
        if (j==0){
          p[i].valor = atof(gasto);
        } else if (j==1){
          p[i].categoria = atoi(gasto);
        } else if (j==2){
          strcpy(p[i].desc, gasto);
        } else if (j==3){
          strcpy(data, gasto);
        }
        gasto = strtok(NULL, ";");
      }

      t = 0;
      k = 0;

      for (j=0; data[j] != 0; j++){
        if (j==6 || j == 7 || j==8 || j==9){
          ano_verifica[t] = data[j];
          t++;
        } else if (j==3 || j==4){
          mes_verifica[k] = data[j];
          k++;
        } else{
          continue;
        }
      }

      mes_verifica_aux = atoi(mes_verifica);
      ano_verifica_aux = atoi(ano_verifica);

      if (ano_registrado == ano_verifica_aux && mes_registrado == mes_verifica_aux){
        fputs("<tr>", f);
        fprintf(f, "<td>%s</td>\n", data);
        if (p[i].categoria == 1){
          fputs("<td>Moradia</td>", f);
        } else if (p[i].categoria == 2){
          fputs("<td>Estudos</td>", f);
        } else if (p[i].categoria == 3){
          fputs("<td>Transporte</td>", f);
        } else if (p[i].categoria == 4){
          fputs("<td>Alimenta��o</td>", f);
        } else if (p[i].categoria == 5){
          fputs("<td>Trabalho</td>", f);
        } else {
          fputs("<td>Nenhuma</td>", f);
        }
        fprintf(f, "<td>%s</td>\n", p[i].desc);
        fprintf(f, "<td>R$%.2f</td>\n", p[i].valor);
        fputs("</tr>", f);
      } else{
        continue;
      }
    }
  }
  fputs("</table>", f);
  fputs("</body>", f);
  fputs("</html>", f);
  fclose(fr);
  fclose(f);
  return;
}

void saldoTotal()
{
  int i=0, j=0;
  char *aux, *receita, *gasto;
  char linha[50];
  float receitaTotal=0, gastoTotal=0, saldo=0;
  struct Receita p[100];
  FILE* f = fopen("receita.txt", "r");
  for (i=0; !feof(f); i++){
    aux = fgets(linha, 90, f);
    if (aux != NULL){
      if (aux){
        receita = strtok(aux, ";");
      }
      for (j=0; receita != NULL; j++){
        if (j==0){
          p[i].valor = atof(receita);
        } else if (j==1){
          strcpy(p[i].desc, receita);
        } else if (j==2){
          strcpy(p[i].data, receita);
        }
        receita = strtok(NULL, ";");
      }
      receitaTotal += p[i].valor;
    }
  }
  struct Gastos t[100];
  FILE* fr = fopen("gastos.txt", "r");
  for (i=0; !feof(fr); i++){
    aux = fgets(linha, 90, fr);
    if (aux != NULL){
      if (aux){
        gasto = strtok(aux, ";");
      }
      for (j=0; gasto != NULL; j++){
        if (j==0){
          t[i].valor = atof(gasto);
        } else if (j==1){
          t[i].categoria = atoi(gasto);
        } else if (j==2){
          strcpy(t[i].desc, gasto);
        } else if (j==3){
          strcpy(p[i].data, gasto);
        }
        gasto = strtok(NULL, ";");
      }
      gastoTotal += t[i].valor;
    }
  }
  saldo = receitaTotal - gastoTotal;
  puts(" ");
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("Saldo Total: R$%.2f\n", saldo);
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

void excluirRelatorio()
{
  int i=0, j=0, n=0;
  char *aux, *gasto, linha[90];
  int resposta_aceita=0, qtdLinha=0;
  struct Excluir p[100];
  FILE* fr=fopen("gastos.txt", "r");

  for (i=0; i<=100; i++){
    p[i].valor = 0;
    p[i].categoria = 0;
    strcpy(p[i].desc, "0");
    strcpy(p[i].data, "0");
  }

  for (i=0; !feof(fr); i++){
    aux = fgets(linha, 90, fr);
    qtdLinha++;
    if (aux!=NULL){
      if (aux){
        gasto = strtok(aux, ";");
      }
      for (j=0; gasto != NULL; j++){
        if (j==0){
          p[i].valor = atof(gasto);
        } else if (j==1){
          p[i].categoria = atoi(gasto);
        } else if (j==2){
          strcpy(p[i].desc, gasto);
        } else if (j==3){
          strcpy(p[i].data, gasto);
        }
        gasto = strtok(NULL, ";");
      }

      printf("======= ITEM %d =======\n", i+1);
      printf("Data: %s", p[i].data);
      if (p[i].categoria == 1){
        printf("Categoria: Moradia\n");
      } else if (p[i].categoria == 2){
        printf("Categoria: Estudos\n");
      } else if (p[i].categoria == 3){
        printf("Categoria: Transporte\n");
      } else if (p[i].categoria == 4){
        printf("Categoria: Alimentacao\n");
      } else if (p[i].categoria == 5){
        printf("Categoria: Transporte\n");
      } else {
        printf("Categoria: Nenhuma\n");
      }
      printf("Descricao: %s\n", p[i].desc);
      printf("Valor: R$%.2f\n\n", p[i].valor);
    }
  }
  while (resposta_aceita==0){
    printf("Insira o numero do item que deseja excluir: ");
    scanf("%d", &n);
    while (n<=0){
      printf("Numero de relatorio inexistente.\n");
      printf("Insira o numero do relatorio que deseja excluir: ");
      scanf("%d", &n);
    }
    if (n > 0){
      resposta_aceita = 1;
    }
  }
  fclose(fr);
  FILE* f = fopen("gastos.txt", "w");
  for (i=0; i<=qtdLinha; i++){
    if (i != n-1){
      if (p[i].valor != 0){
        fprintf(f, "%.2f;%d;%s;%s", p[i].valor, p[i].categoria, p[i].desc, p[i].data);
      } else{
        continue;
      }
    } else{
      continue;
    }
  }
  fclose(f);
  puts(" ");
  puts("--------------------------------");
  puts("|  Gasto apagado com sucesso!  |");
  puts("--------------------------------");
  return;
}

int menu()
{
  int n = -1;
  while (n != 0){
    do {
      puts("");
      puts("====================================");
      puts("~~~~~~~~~~~~ TRABALHO ~~~~~~~~~~~~~~");
      puts("====================================");
      puts("1 - Cadastro de receitas");
      puts("2 - Cadastro de gastos");
      puts("3 - Relatorio de ultimos 12 meses");
      puts("4 - Relatorio de categoria");
      puts("5 - Relatorio do mes especifico");
      puts("6 - Saldo Total");
      puts("7 - Excluir gasto");
      puts("0 - Sair  ");
      puts("====================================");
      printf("opcao => ");
      scanf("%d", &n);
    } while (n<0 || n>7);
    if (n==1){
      cadastroReceita();
    } else if (n==2){
      cadastroGasto();
    } else if (n==3){
      relatorioMeses();
    } else if (n==4){
      relatorioCategoria();
    } else if (n==5){
      relatorioMesEspecifico();
    } else if (n==6){
      saldoTotal();
    } else if (n==7){
      excluirRelatorio();
    } else if (n==0){
      break;
    }
  }
  return n;
}

int main()
{
  menu();
  return 0;
}
