#include <stdio.h>
#include <stdlib.h>

const int ITEM_MAX_SIZE = 30;

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

int main()
{
    int quant = quant_items();

    // Alocar todos os items e quantidades
    char **item;
    int *quantity;

    item = (char **)malloc(quant * sizeof(char *));
    for (int i = 0; i < quant; i++)
    {
        item[i] = (char *)malloc(ITEM_MAX_SIZE * sizeof(char));
    }

    quantity = (int *)malloc(quant * sizeof(int));

    load_file(item, quantity, quant);

    int operation;
    int leave = 0;

    int selected_item = 0;
    int selected_quantity = 0;

    printf("Bem vindo ao sistema de controle de estoque\n");
    while (1)
    {
        printf("Selecione uma operacao\n");
        printf("1 - Listar items\n");
        printf("2 - Adicionar items\n");
        printf("3 - Remover items\n");
        printf("4 - Sair\n");

        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
            print_table(item, quantity, quant);
            break;
        case 2:
            printf("Qual item voce gostaria de adicionar?\n");
            list_items(item, quant);
            scanf("%d", &selected_item);
            printf("Quantos items voce quer adicionar?\n");
            scanf("%d", &selected_quantity);
            quantity[selected_item - 1] += selected_quantity;
            save_file(item, quantity, quant);
            break;
        case 3:
            printf("Qual item voce gostaria de remover?\n");
            list_items(item, quant);
            scanf("%d", &selected_item);
            printf("Quantos items voce quer remover?\n");
            scanf("%d", &selected_quantity);
            quantity[selected_item - 1] -= selected_quantity;
            save_file(item, quantity, quant);
            break;
        case 4:
            leave = 1;
            break;
        }

        if (leave == 1)
        {
            break;
        }
    }
}