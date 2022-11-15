#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
    int id;
    char nome[50];
}Filme;

FILE *arquivo;

void abrir_arquivo(char modo[]) {
    if((arquivo = fopen("cadastro_de_filmes", modo)) == NULL) {
        printf("\nErro na abertura do arquivo!\n");
    } else {
        printf("\nArquivo aberto com sucesso!\n");
    }
}

void cadastro() {
    Filme lista;
    system("cls");
    printf("Digite o ID do filme: ");
    scanf("%d", &lista.id);
    fflush(stdin);
    printf("Digite o nome do filme: ");
    fgets(lista.nome, 50, stdin);
    printf("\n%d\n", lista.id);
    puts(lista.nome);
    abrir_arquivo("ab+");
    int count = 1;
    if(fwrite(&lista, sizeof(lista), count, arquivo) == count) {
        printf("\nDados salvos com sucesso!");
        getchar();
    } else {
        printf("Erro na escritura do arquivo!");
        getchar();
    }
    fclose(arquivo);
}

void mostrar() {
    Filme lista;
    system("cls");
	abrir_arquivo("rb");
	rewind(arquivo);
	while(!feof(arquivo)) {
		if(fread(&lista, sizeof(lista), 1, arquivo) == 1) {
			printf("%d - ", lista.id);
			puts(lista.nome);
		}
	}
	fflush(stdin);
	getchar();
}
int main() {
    int opcao;
    while(1) {
        printf("\n");
        printf("\n\t\tOPCOES");
        printf("\n");
        printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Pesquisar\n");
        printf("\nDigite o numero da opcao desejada: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                exit(1);
                break;
            case 1:
                cadastro();
                break;
            case 2:
            	mostrar();
            	break;
        }
    }   
    return 0;
}