#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "menu.h"

const int ITEM_MAX_SIZE = 30;

int quant_items();

void load_file(char **item, int *quantity, int quant);

void save_file(char **item, int *quantity, int quant);

void print_table(char **item, int *quantity, int quant);

void list_items(char **item, int quant);

void menu();

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
        menu();

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