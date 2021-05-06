#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

typedef struct NO
{
int info;
struct NO *esquerda, *direita;
} node, *arvore;
arvore root = NULL;


arvore pesquisar(arvore, int);
int proxmaior(int);
void inserir(arvore *, int);
void imprimir(arvore, int);
int range(arvore );
void percorre_preordem(node *);
void percorre_posordem(node *);
void percorre_emordem(node *);
int maior(node * );
int menor(node * );
 int main(void)
{
int x,opcao;


do
{
system("COLOR 3F");
printf("\nEntre com a opcao");
printf("\n ---1:inserir numero");
printf("\n ---2:Mostrar todos os numeros ordenados");
printf("\n ---3:Mostrar o maior numero");
printf("\n ---4:Mostrar o menor numero");
printf("\n ---5:Mostrar a quantidade de nos da arvore");
printf("\n ---6:sair do programa\n");
printf("\n->");
fflush(stdin);
scanf("%d", &opcao);
switch(opcao)
{
case 1:
{
    printf("\n Informe o valor ->");
scanf("%d", &x);
inserir(&root, x);
imprimir(root, 0);
break;
}

case 2:
{
printf("\nPercorrendo em ordem ->");
percorre_emordem(root);
printf("\nPercorrendo em pre ordem ->");
percorre_preordem(root);
printf("\nPercorrendo em pos ordem ->");
percorre_posordem(root);
break;
}
case 3:
{
printf("\nMaior = %d", maior(root));

break;
}
case 4:
{

printf("\nMenor = %d", menor(root));
break;
}
case 5:
{
printf("\n nos da arvore = %d", range(root) );

break;
}

}
} while(opcao!=6);
}
arvore pesquisar(arvore v, int chave)
{
if( v == NULL)
{
return NULL;
}
if(v->info == chave)
{
return v;
}
else if(v->info < chave)
{
return pesquisar(v->direita, chave);
}
else
{
return pesquisar(v->esquerda, chave);
}
}
/* maior no próximo elemento informado */
int proxmaior(int chave)
{
arvore p=NULL, v;
v = root;
while( v != NULL && v->info != chave)
{
if(v->info < chave)
{
v = v->direita;
}
else
{
p = v;
v = v->esquerda;
}
}
if(v == NULL)
{
printf("\n Elemento nao encontrado");
return -1;
}
if( v->direita != NULL )
{
v = v->direita;
while(v->esquerda != NULL)
{
v = v->esquerda;
}
return v->info;
}
if(p != NULL)
{
return p->info;
}
else
{
return -1;
}
}
void inserir(arvore *p, int chave)
{
if( *p == NULL )
{
*p = (arvore) malloc(sizeof(node));
(*p)->info = chave;
(*p)->esquerda = NULL;
(*p)->direita = NULL;
}
else if((*p)->info < chave)
{
    inserir(&((*p)->direita), chave);
}
else
{
inserir(&((*p)->esquerda), chave);
}
return;
}
void imprimir(arvore v, int nivel)
{
int i;
if( v != NULL )
{
imprimir(v->esquerda, nivel+1);
for(i=0; i<nivel; i++)
{
printf(" ");
}
printf("%d\n", v->info);
imprimir(v->direita, nivel+1);
}
return;
}
/*retornar a quantidade dos nos da arvore*/
int range(arvore v)
{
if( v == NULL )
{
return 0;
}

else {
    int countEsq = range(v->esquerda);
    int countDir = range(v->direita );
    return countDir+countEsq +1;
}
}

/* percorrer uma árvore utilizando o algoritmo de pré-ordem */
void percorre_preordem(node * arvore)
{
if( arvore == NULL )
{
return;
}
printf(" %d", arvore->info);
percorre_preordem(arvore->esquerda);
percorre_preordem(arvore->direita);
return;
}
/* percorrer uma árvore utilizando o algoritmo de pós-ordem */
void percorre_posordem(node * arvore)
{
    if( arvore == NULL )
{
return;
}
percorre_posordem(arvore->esquerda);
percorre_posordem(arvore->direita);
printf(" %d", arvore->info);
return;
}
/* percorrer uma árvore utilizando no modo em-ordem */
void percorre_emordem(node * arvore)
{
if( arvore == NULL )
{
return;
}
percorre_emordem(arvore->esquerda);
printf(" %d", arvore->info);
percorre_emordem(arvore->direita);
return;
}
/* pesquisa do maior elemento na árvore */
int maior(node * arvore )
{
int maior;
maior = arvore->info;

while( arvore != NULL )
{
maior = arvore->info;
arvore = arvore->direita;
}
return maior;
}
/* pesquisa do menor elemento na árvore */
int menor(node * arvore)
{
int menor;
menor = arvore->info;
while( arvore != NULL )
    {
menor = arvore->info;
arvore = arvore->esquerda;
}
return menor;
}
