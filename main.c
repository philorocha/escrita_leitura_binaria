#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

int main()
{
    Pessoa p;

    /*printf("Digite seu nome: ");
    fflush(stdin);
    gets(p.nome);

    printf("Digite sua idade: ");
    scanf("%d", &p.idade);

    FILE *f = fopen("pessoas.bin", "ab");

    fwrite(&p, sizeof(Pessoa), 1, f);

    fclose(f);*/

    FILE *f = fopen("pessoas.bin", "rb");

    if (!f) {
        printf("Erro ao tentar ler o arquivo.\n");
        exit(1);
    }

    while(fread(&p, sizeof(Pessoa), 1, f)) {
        printf("Olá %s, você tem %d anos.\n", p.nome, p.idade);
    }

    fclose(f);

    return 0;
}
