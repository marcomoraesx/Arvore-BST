#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

arvore inserir (arvore raiz, int valor){
    if(raiz == NULL) {
        arvore nova = (arvore) malloc(sizeof(struct no));
        nova->valor = valor;
        nova->esq = NULL;
        nova->dir = NULL;
        return nova;
    }
    else {
        if(valor > raiz->valor) {
            raiz->dir = inserir(raiz->dir, valor);
        } else {
            raiz->esq = inserir(raiz->esq, valor);
        }
        return raiz;
    }
}

void preorder(arvore raiz){
    if(raiz != NULL) {
        printf("[%d]", raiz->valor);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}

void inorder(arvore raiz){
    if(raiz != NULL) {
        inorder(raiz->esq);
        printf("[%d]", raiz->valor);
        inorder(raiz->dir);
    }
}

void posorder(arvore raiz) {
    if(raiz != NULL) {
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf("[%d]", raiz->valor);
    }
}

void reverso(arvore raiz){
    if(raiz != NULL) {
        reverso(raiz->dir);
        printf("[%d]", raiz->valor);
        reverso(raiz->esq);
    }
}

int qtde_par(arvore raiz){
    int qtde = 0;
    if(raiz != NULL) {
        if (raiz->valor%2 == 0) {
            qtde += 1;
        }
        qtde += qtde_par(raiz->esq) + qtde_par(raiz->dir);
    }
    return qtde;
}

/*int antecessor(arvore raiz, int n){
    int ant = -1;
    if (raiz != NULL) {
        if (n == raiz->valor){
            ant = antecessor(raiz->esq, n);
        } else if (n < raiz->valor) {
            ant = antecessor(raiz->esq, n);
        } else {
            ant = raiz->valor;
            int result = antecessor(raiz->dir, n);
            if (result != -1) {
                ant = result;
            }
        }
    }
    return ant;
}*/

int antecessor(arvore raiz, int valor) {
    arvore candidato = NULL;
    arvore raiz_atual = raiz;
    while (raiz_atual != NULL) {
        if (valor < raiz_atual->valor) {
            raiz_atual = raiz_atual->esq;
        } else if (valor > raiz_atual->valor) {
            candidato = raiz_atual;
            raiz_atual = raiz_atual->dir;
        } else {
            if (raiz_atual->esq != NULL) {
                return maior_elemento(raiz_atual->esq);
            } else {
                if (candidato != NULL) {
                    return candidato->valor;
                }
                break;
            }
        }
    }
    return -1;
}

int pai(arvore raiz, int n){
    int father = -1;
    if (raiz != NULL) {
        if (n < raiz->valor) {
            if (raiz->esq != NULL && raiz->esq->valor == n) {
                father = raiz->valor;
            } else {
                father = pai(raiz->esq, n);
            }
        }
        if (n > raiz->valor) {
            if (raiz->dir != NULL && raiz->dir->valor == n) {
                father = raiz->valor;
            } else  {
                father = pai(raiz->dir, n);
            }
        }
    }
    return father;
}

int soma_par(arvore raiz) {
    int soma = 0;
    if (raiz != NULL) {
        if (raiz->valor%2 == 0){
            soma += raiz->valor;
        }
        soma += soma_par(raiz->esq) + soma_par(raiz->dir);
    }
    return soma;
}

void dobro(arvore raiz) {
    if (raiz != NULL) {
        raiz->valor = raiz->valor * 2;
        dobro(raiz->esq);
        dobro(raiz->dir);
    }
}

int busca(arvore raiz, int valor) {
    int encontrado = 0;
    if (raiz != NULL) {
        if (raiz->valor == valor) {
            encontrado = 1;
        }
        if (valor < raiz->valor) {
            encontrado = busca(raiz->esq, valor);
        }
        if (valor > raiz->valor) {
            encontrado = busca(raiz->dir, valor);
        }
    }
    return encontrado;
}

void descendentes(arvore raiz, int valor) {
    if (raiz != NULL) {
        if (raiz->valor == valor) {
            if (raiz->esq != NULL) {
                inorder(raiz->esq);
                inorder(raiz->dir);
            } else {
                inorder(raiz->dir);
            }
        }
        if (raiz->valor > valor) {
            descendentes(raiz->esq, valor);
        }
        if (raiz->valor < valor) {
            descendentes(raiz->dir, valor);
        }
    }
}

int altura(arvore raiz) {
    int bigger;
    if (raiz != NULL) {
        int left = altura(raiz->esq);
        int right = altura(raiz->dir);
        if (left > right) {
            bigger = left;
        } else {
            bigger = right;
        }
        return 1 + bigger;
    }
    return 0;
}

int somatorio(arvore raiz){
    int soma = 0;
    if(raiz != NULL) {
        soma += raiz->valor + somatorio(raiz->esq) + somatorio(raiz->dir);
    }
    return soma;
}

arvore podar(arvore raiz, int valor) {
    if (raiz != NULL) {
        if (raiz->valor == valor) {
            if (raiz->esq != NULL) {
                raiz->esq = podar(raiz->esq, raiz->esq->valor);
            } else if (raiz->dir != NULL) {
                raiz->dir = podar(raiz->dir, raiz->dir->valor);
            }
            free(raiz);
            return NULL;
        } else if (valor < raiz->valor) {
            raiz->esq = podar(raiz->esq, valor);
        } else {
            raiz->dir = podar(raiz->dir, valor);
        }
    }
    return raiz;
}

arvore remover(arvore raiz, int valor) {
    if (raiz != NULL) {
        if (raiz->valor == valor) {
            if (raiz->esq == NULL && raiz->dir == NULL) {
                free(raiz);
                return NULL;
            }
            if (raiz->esq != NULL && raiz->dir == NULL) {
                arvore temp = raiz->esq;
                free(raiz);
                return temp;
            }
            if (raiz->dir != NULL && raiz->esq == NULL) {
                arvore temp = raiz->dir;
                free(raiz);
                return temp;
            }
            int menor = menor_elemento(raiz->dir);
            raiz->valor = menor;
            raiz->dir = remover(raiz->dir, menor);
            return raiz;
        } else if (valor < raiz->valor) {
            raiz->esq = remover(raiz->esq, valor);
        } else {
            raiz->dir = remover(raiz->dir, valor);
        }
    }
    return raiz;
}

int maior_elemento(arvore raiz) {
	if(raiz == NULL)
        return -1;
	if(raiz->dir == NULL)
		return raiz->valor;
	else
		return maior_elemento(raiz->dir);
}

int menor_elemento(arvore raiz) {
	if(raiz == NULL)
        return -1;
	if(raiz->esq == NULL)
		return raiz->valor;
	else
		return maior_elemento(raiz->esq);
}
