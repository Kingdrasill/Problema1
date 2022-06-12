#ifndef LISTA_H 
#define LISTA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef struct Item Item;
typedef struct Block Block;
typedef struct Lista Lista;

struct Item{
	int val;
	float dist;
};

struct Block{
	Item data;
	Block *prox;
};

struct Lista{
	Block *first;
	Block *last;
};


void FLVazia(Lista *l);
void LInsert(Lista *l, Item d);
void LRemove(Lista *l, Item d);
void Swap(Block *a, Block *b);
void LImprime(Lista *l);
void Initialize(Lista *l, int size);
void Initialize2(Lista *l, int size);

void Game(Lista *l1, Lista *l2);

void CountEvenOdd(Lista *l);
void RecursiveCountEvenOdd(Lista *l);
void Recursion(Block *aux, int* count);

Item RemoveFirst(Lista *l);
Item RemoveLast(Lista *l);

void LImprimeDist(Lista *l);
Lista CalculaDist(Lista *L1,Lista *L2);
void Ordena(Lista *L);
void MostrarK(Lista *L,int k);

#endif