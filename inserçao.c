#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo;
    struct no *esquerda;
    struct no *direita;
    int tamanho;
} No;

typedef struct
{
    No *raiz;
} ArvB;

void inserir(ArvB *arv, int valor)
{
    if (arv->raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo;
    }
    else
    {
        if (valor < arv->raiz->conteudo)
        {
            return inserir(&(arv->raiz->esquerda), valor);
        }
        else
        {
            return inserir(&(arv->raiz->direita), valor);
        }
    }
}

// contador de nós da arvore
int tamanho(No *raiz)
{
    if (raiz == NULL)
        return 0;

    else
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}

int buscar(No *raiz, int chave)
{
    if (raiz == NULL)
    {
        return -1;
    }
    else
    {
        if (raiz->conteudo == chave)
        {
            return raiz->conteudo;
        }
        else
        {
            if (chave < raiz->conteudo)
            {
                return buscar(raiz->esquerda, chave);
            }
            else
            {
                return buscar(raiz->direita, chave);
            }
        }
    }
}

void imprimir(No *raiz)
{
    if (raiz != NULL)
    {
        imprimir(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

No *remover(No *raiz, int chave)
{
    if (raiz == NULL)
        return NULL;
    else
    {
        if (raiz->conteudo == chave)
        {
            if (raiz->esquerda == NULL && raiz->direita == NULL)
                free(raiz);
            return NULL;
        }
        else
        {
            if (chave < raiz->conteudo)
            {
                raiz->esquerda = remover(raiz->esquerda, chave);
            }
            else
            {
                raiz->direita = remover(raiz->direita, chave);
            }
            return raiz;
        }
    }
}

int main()
{
    int op, valor;
    ArvB arv;
    arv.raiz = NULL;
    int chave;

    do
    {
        printf("\n0 - sair\n1 - inserir\n2- imprimir\n3-tamanho\n4-buscar\n5-Remover\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("saindo");
            break;
        case 1:
            printf("digite um valor");
            scanf("%d", &valor);
            inserir(&arv, valor);
            break;
        case 2:
            printf("\n Impressao da arvore binaria ");
            imprimir(arv.raiz);
            break;
        case 3:
            printf("tamanho da nossa arvore: ");
            int a = tamanho(arv.raiz);
            printf("%d", a);
            break;
        case 4:

            printf("digite um numero que deseja buscar");
            scanf("%d", &chave);
            if (buscar(arv.raiz, chave) == -1)
            {
                printf("este numero nao existe na arvore");
            }
            else
            {
                printf("resultado da busca %d", buscar(arv.raiz, chave));
            }
            break;
        case 5:
            printf("digite um valor");
            scanf("%d", &valor);
            inserir(&arv, valor);
            break;
        }
    } while (op != 0);
}
