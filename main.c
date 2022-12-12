// Integrantes da equipe: Matheus Macedo Gomes (20211045050330) e João Vitor Abreu Castro (20211045050446)

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* proximo;};

struct Node *novoNodulo(int);
void empurrar(struct Node**, int);
long long multiplicarDuasListas (struct Node*, struct Node*);
void printLista(struct Node *);

int main(){
    struct Node* Prim = NULL;
    struct Node* Seg = NULL;
    int PrimNum1;
    int PrimNum2;
    int PrimNum3;
    int SegNum1;
    int SegNum2;
    int SegNum3;
   
    printf("Digite o primeiro número: ");
    scanf("%d", &PrimNum1);
    empurrar(&Prim, PrimNum1);
    printf("Digite o segundo número: ");
    scanf("%d", &PrimNum2);
    empurrar(&Prim, PrimNum2);
    printf("Digite o terceiro número: ");
    scanf("%d", &PrimNum3);
    empurrar(&Prim, PrimNum3);
    printf("\nA primeira lista é: ");
    printLista(Prim);
   
    printf("\nDigite o primeiro número: ");
    scanf("%d", &SegNum1);
    empurrar(&Seg, SegNum1);
    printf("Digite o segundo número: ");
    scanf("%d", &SegNum2);
    empurrar(&Seg, SegNum2);
    printf("Digite o terceiro número: ");
    scanf("%d", &SegNum3);
    empurrar(&Seg, SegNum3);
    
    printf("\nA segunda lista é: ");
    printLista(Seg);
   
    printf("\nO resultado é: ");
    long long Resposta = multiplicarDuasListas(Prim, Seg);
    printf("%lld",Resposta);
   
    return 0;
}

struct Node *novoNodulo(int data){
    struct Node *novo_nodulo = (struct Node *) malloc(sizeof(struct Node));
    novo_nodulo->data = data;
    novo_nodulo->proximo = NULL;
    return novo_nodulo;}

void empurrar(struct Node** ref_cabeca, int nova_data){
    struct Node* novo_nodulo = novoNodulo(nova_data);
   
    novo_nodulo->proximo = (*ref_cabeca);
   
    (*ref_cabeca) = novo_nodulo;}
   
long long multiplicarDuasListas (struct Node* primeiro,struct Node* segundo){
    long long Numero= 1000000007;
    long long Num1 = 0, Num2 = 0;
    while (primeiro || segundo){
         
        if(primeiro){
            Num1 = ((Num1)*10)%Numero + primeiro->data;
            primeiro = primeiro->proximo;}
         
        if(segundo){
            Num2 = ((Num2)*10)%Numero + segundo->data;
            segundo = segundo->proximo;}
         
    }
    return ((Num1%Numero)*(Num2%Numero))%Numero;}
   

void printLista(struct Node *nodulo){
    while(nodulo != NULL){
        printf("%d",nodulo->data);
        if(nodulo->proximo)
            printf("->");
        nodulo = nodulo->proximo;}
    printf("\n");}
   