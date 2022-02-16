#include <stdio.h>
#include <stdlib.h>

int quant_items()
{
    FILE *pointer;
    pointer = fopen("storage.txt", "r");

    int counter = 0;
    char line[40];

    while (feof(pointer) == 0)
    {
        fscanf(pointer, "%s", line);

        counter += 1;
    }

    fclose(pointer);

    return counter / 2;
}

void load_file(char **item, int *quantity, int quant)
{
    // Carregar os valores do arquivo nas variáveis
    FILE *pointer;
    pointer = fopen("storage.txt", "r");

    for (int i = 0; i < quant; i++)
    {
        fscanf(pointer, "%s", item[i]);
        fscanf(pointer, "%d", &quantity[i]);
    }

    fclose(pointer);
}

void save_file(char **item, int *quantity, int quant)
{
    // Carregar os valores do arquivo nas variáveis
    FILE *pointer;
    pointer = fopen("storage.txt", "w");

    for (int i = 0; i < quant; i++)
    {
        fprintf(pointer, "%s\n", item[i]);
        fprintf(pointer, "%d\n", quantity[i]);
    }

    fclose(pointer);
}

void print_table(char **item, int *quantity, int quant)
{
    printf("--------------------------------------------------\n");
    printf("%-30s%-20s\n", "Nome", "Quantidade");
    for (int i = 0; i < quant; i++)
    {
        printf("%-30s%-20d\n", item[i], quantity[i]);
    }
    printf("--------------------------------------------------\n");
}

void list_items(char **item, int quant)
{
    printf("--------------------------------------------------\n");
    for (int i = 0; i < quant; i++)
    {
        printf("%d - %s\n", i + 1, item[i]);
    }
    printf("--------------------------------------------------\n");
}