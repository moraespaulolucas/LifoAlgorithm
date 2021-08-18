#include <stdio.h>
#include <stdlib.h>

int size;
int *list;

int *init(int sz);
void printList();
void printMenu();
void push();
void pop();

void main()
{
    size = 0;
    int n, x;
    do
    {
        printList();
        printf("=============\n");
        printMenu();
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Number: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        default:
            if (n)
                printf("Input error\n");
        }
        printf("=============\n");
    } while (n);
    if (list)
        free(list);
}

void printList()
{
    if (size)
        for (int i = 0; i < size; i++)
            printf("[%d] - %d\n", i, list[i]);
}

void printMenu()
{
    printf("1- Push\n");
    printf("2- Pop\n");
    printf("0- Exit\n");
}

int *init(int sz)
{
    int *p;
    p = malloc(sz * sizeof(int));
    if (!p)
        printf("Memory allocation error\n");
    return p;
}

void push(int n)
{
    int newSize = size + 1;
    int *aux = init(newSize);
    if (size)
    {
        for (int i = 0; i < size; i++)
            aux[i] = list[i];
        free(list);
    }
    aux[size] = n;
    size = newSize;
    list = aux;
}

void pop()
{
    if (!size)
    {
        printf("List is already empty\n");
    }
    else
    {
        int newSize = size - 1;
        int *aux = init(newSize);
        for (int i = 0; i < newSize; i++)
            aux[i] = list[i];
        free(list);
        size = newSize;
        list = aux;
    }
}
