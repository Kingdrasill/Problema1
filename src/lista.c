#include "lista.h"

void Swap(Block *a, Block *b){
	Item aux;
	aux = a->data;
	a->data = b->data;
	b->data = aux;
	
}

void FLVazia(Lista *l){
	l->first = (Block*) malloc (sizeof(Block));
	l->last  = l->first;
	l->first->prox = NULL;
}

void LInsert(Lista *l, Item d){
	l->last->prox = (Block*) malloc (sizeof(Block));
	l->last = l->last->prox;
	l->last->data = d;
	l->last->prox = NULL;
}

void LRemove(Lista *l, Item d){
	Block *aux, *tmp;

	if(l->first == l->last || l == NULL || l->first->prox == NULL){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	aux = l->first;
	while(aux->prox != NULL){
		if (aux->prox->data.val == d.val){
			tmp = aux;
			aux = aux->prox;
			tmp->prox = aux->prox;
			if (aux == l->last) {
				l->last = tmp;
            }
			free(aux);
		}
		else
			aux = aux->prox;
	}
}


void LImprime(Lista *l){
	Block *aux;

	aux = l->first->prox;
	while(aux != NULL){
		printf("%d\t", aux->data.val);
		aux = aux->prox;
	}
    printf("\n");
}

void Initialize(Lista *l, int size) {
    Item aux;

    for(int i=0; i<size; i++) {
        aux.val = rand()%100;
        LInsert(l, aux);
    }
}

void Initialize2(Lista *l, int size) {
    Item aux;
	
    for(int i=0; i<size; i++) {
        aux.val = rand()%13+1;
        LInsert(l, aux);
    }
}

void Game(Lista *l1, Lista *l2) {
	Block *aux1, *aux2;
	int number=0, soma1=0, soma2=0, i=0;

	number = rand()%13+1;
	printf("\nNumero a ser subtraido: %d\n", number);

	aux1 = l1->first->prox;
	aux2 = l2->first->prox;

	while(aux1 != NULL && aux2 != NULL) {
		printf("\nL1[%d] = %d \t L2[%d] = %d", i, aux1->data.val, i, aux2->data.val);

		soma1 += (aux1->data.val - number);
		soma2 += (aux2->data.val - number);
		
		aux1 = aux1->prox;
		aux2 = aux2->prox;
		i++;
	}

	if(soma1 > soma2)
		printf("\n\nA lista 1 ganhou!\n");
	else if(soma2 > soma1)
		printf("\n\nA lista 2 ganhou!\n");
	else
		printf("\n\nAs listas empataram!\n");
}

void CountEvenOdd(Lista *l) {
	Block *aux;
    int even=0, odd=0;

	aux = l->first->prox;
	while(aux != NULL){
        if(aux->data.val % 2 == 0)
            even++;
        else
            odd++;
		aux = aux->prox;
	}

    printf("\nNumero de pares: %d\nNumero de Impares: %d\n", even, odd);
}

void RecursiveCountEvenOdd(Lista *l) {
    Block *aux;
    int count[] = {0,0};

    aux = l->first->prox;
    if(aux != NULL) {
        Recursion(aux, count);
    }

    printf("\nNumero de pares: %d\nNumero de Impares: %d\n", count[0], count[1]);
}

void Recursion(Block *aux, int* count) {
    if(aux == NULL)
        return;
    else {
        if(aux->data.val % 2 == 0)
            count[0]++;
        else
            count[1]++;
        Recursion(aux->prox, count);
    }
}

Item RemoveFirst(Lista *l) {
	Block *aux, *tmp;
	Item first;

	tmp = l->first;
	aux = tmp->prox;
	first = aux->data;
	tmp->prox = aux->prox;
	free(aux);

	return first;
}

Item RemoveLast(Lista *l) {
	Block *aux, *tmp;
	Item last;

	aux = l->last;
	last = aux->data;
	tmp = l->first;

	while(tmp->prox != aux) {
		tmp = tmp->prox;
	}
	tmp->prox = aux->prox;
	l->last = tmp;
	free(aux);

	return last;
}

void LImprimeDist(Lista *l){
	Block *aux;

	aux = l->first->prox;
	while(aux != NULL){
		printf("%f\t", aux->data.dist);
		aux = aux->prox;
	}
    printf("\n");

}

Lista CalculaDist(Lista *L1,Lista *L2){
	Lista Laux;
	Item dist;
	FLVazia(&Laux);

	Block *aux,*aux2;
	aux = L1->first;
	aux2 = L2->first;

	while(aux->prox != NULL && aux2->prox !=NULL){
		aux = aux->prox;
		aux2 = aux2->prox;

		dist.dist = sqrt(pow(aux->data.val,2)+pow(aux2->data.val,2));
		LInsert(&Laux,dist);

	}

	return Laux;	
}
void Ordena(Lista *L){
	bool swapped;
	Block *ptr1;
	Block *lptr = NULL;

	do{
		swapped = false;
		ptr1 = L->first->prox;
		while (ptr1->prox != lptr){
			if (ptr1->data.dist > ptr1->prox->data.dist){ 
				Swap(ptr1, ptr1->prox);
				swapped = true;
			}
			ptr1 = ptr1->prox;
		}
		lptr = ptr1;
	}
	while (swapped);	
}

void MostrarK(Lista *L , int k){
	Block *aux;

	aux = L->first->prox;
	for(int i = 1 ; i <= k; i++){
		printf("%f\t", aux->data.dist);
		aux = aux->prox;
	}
    printf("\n");
}