#include "menu.h"

void Menu() {
	Lista l1, l2;
    int opcao;
    bool cont=true;

    while(cont) {
        printf("\n1 - Contar par e ímpares em uma lista\n2 - Mini jogo\n3 - Juntar duas listas\n4 - Achar os k pares de coordenadas mais próximos\n5 - Sair\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                OptionCountEvenOdd(&l1);
                break;
            
            case 2:
                OptionGame(&l1, &l2);
                break;
            
            case 3:
                OptionConcatenate(&l1, &l2);
                break;

            case 4:
                OptionFindK(&l1, &l2);
                break;

            case 5:
                cont = false;
                break;

            default:
                printf("Opcao Invalida!");
                break;
        }
    }
}

void OptionGame(Lista *l1, Lista *l2) {
    int size=0;
	srand(1);

	FLVazia(l1);
	FLVazia(l2);

    printf("\nTamanho das listas: ");
    scanf("%d", &size);

    Initialize2(l1, size);
    Initialize2(l2, size);
    
    Game(l1, l2);
}

void OptionCountEvenOdd(Lista *l) {
    int size = 0;
	srand(42);

	FLVazia(l);

    printf("\nTamnaho da lista: ");
    scanf("%d", &size);

    Initialize(l, size);
    
    LImprime(l);

    printf("\nNão recursivo:\n");
    CountEvenOdd(l);
    printf("\nRecursivo:\n");
    RecursiveCountEvenOdd(l);
}

void OptionConcatenate(Lista *l1, Lista *l2) {
    Lista2 l3;
    int size=0;
	srand(42);

	FLVazia(l1);
	FLVazia(l2);
    FL2Vazia(&l3);

    printf("\nTamanho das listas: ");
    scanf("%d", &size);

    Initialize(l1, size);
    Initialize(l2, size);
    
    printf("\nLista x: ");
    LImprime(l1);
    printf("\nLista y: ");
    LImprime(l2);

    l3 = Concatenate(l1, l2);
    printf("\nListas Concatenadas: ");
    L2Imprime(&l3);
    
    printf("\nLista x: ");
    LImprime(l1);
    printf("\nLista y: ");
    LImprime(l2);
}

void OptionFindK(Lista *l1, Lista *l2) {
     
	Lista Laux;
    Item aux,aux2;
    int num=0,k=0;

    FLVazia(l1);
    FLVazia(l2);
    FLVazia(&Laux);

    printf("\nTamanho das listas: ");
    scanf("%d",&num);   
    printf("\n");
    for(int i=0; i < num ;i++){
        printf("Informe os valores da Lista 1: ");
        scanf("%d",&aux.val);
        LInsert(l1,aux);
    }
    printf("\n");
    for(int j=0; j < num ;j++){
        printf("Informe os valores da Lista 2: ");
        scanf("%d",&aux2.val);
        LInsert(l2,aux2);
    }
    
    printf("\nLista 1: ");
    LImprime(l1);
    printf("\nLista 2: ");
    LImprime(l2);

    printf("\nInforme o valor de K: ");
    scanf("%d",&k);

    
    printf("\nDistancias: ");
    Laux = CalculaDist(l1,l2);
    LImprimeDist(&Laux);
    printf("\nK valores mais proximos: ");
    Ordena(&Laux);
    MostrarK(&Laux,k);
}