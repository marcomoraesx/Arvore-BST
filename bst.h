#ifndef BST_H
#define BST_H

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} no;

typedef no* arvore;

arvore inserir (arvore raiz, int valor) ;

void preorder(arvore raiz);
void inorder(arvore raiz);
void posorder(arvore raiz);
void reverso(arvore raiz);

int qtde_par(arvore raiz);
int antecessor(arvore raiz, int n);
int pai(arvore raiz, int n);
int soma_par(arvore raiz);
void dobro(arvore raiz);
int busca(arvore raiz, int valor);
void descendentes(arvore raiz, int valor);
int altura(arvore raiz);
arvore podar(arvore raiz, int valor);
arvore remover(arvore raiz, int valor);
int menor_valor(arvore raiz);

int somatorio(arvore raiz);
void mesclar (arvore raiz1, arvore raiz2);
void ascendentes(arvore raiz, int valor);

#endif
