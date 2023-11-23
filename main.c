#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodo {
    int valor;
    struct Nodo* der;
    struct Nodo* izq;
};


struct Nodo* crear_nodo(int value){
    //Asigna el espacio en la memoria del tamano de la estructura;
    struct Nodo* nodo = (struct Nodo*) malloc(sizeof (struct Nodo));
    nodo ->valor = value;
    nodo ->der = nodo ->izq = NULL;
    return nodo;
}
struct Nodo* Insert(struct Nodo* tree, int n){
    if(tree == NULL){
        return crear_nodo(n);
    }
    if(n < tree->valor){

        tree->izq=Insert(tree->izq,n);
    } else{
       tree->der=Insert(tree->der,n);
    }
    return tree;
}

struct Nodo * faketree(struct Nodo* tree){

    tree = Insert(tree,10);
    Insert(tree, 7);
    Insert(tree, 6);
    Insert(tree, 8);
    Insert(tree, 6);
    Insert(tree, 13);
    Insert(tree, 16);
    Insert(tree, 17);
    //arbol correcto example
}
int validate(struct Nodo* tree, int Min, int Max){
    if (tree == NULL){
        return 1;
    }
    if(tree->valor<Min||tree->valor>Max){
        return 0;
    }
    return validate(tree->izq,Min,tree->valor - 1) && validate(tree->der,tree->valor+1, Max);
};
void resultado(struct Nodo *tree){
    if(validate(tree,6,17)==1){//el min es el valor minimo que esta en el arbol binario y el maximo el es
        printf("That is a correct binary search tree\n");
    }else{
        printf("That is incorrect binary search tree\n");
    }
}
void inOrder(struct Nodo *tree){
    if(tree == NULL){
        return;
    }else{
        inOrder(tree->izq);
        printf("%d,",tree->valor);
        inOrder(tree->der);
    }
}
void preOrder(struct Nodo *tree){
    if(tree == NULL){
        return;
    }else{
        printf("%d,",tree->valor);
        preOrder(tree->izq);
        preOrder(tree->der);
    }
}

void postOrder(struct Nodo *tree){
    if(tree == NULL){
        return;
    }else{
        postOrder(tree->izq);
        postOrder(tree->der);
        printf("%d,",tree->valor);
    }
}
struct Node* Find(struct Nodo *tree,int valor){
    if(tree== NULL || tree->valor == valor){
        return tree;
    }
    if(valor < tree->valor){
        Find(tree->izq,valor);
    } else{
        Find(tree->der,valor);
    }
}
struct Nodo* addNodes(struct Nodo* tree){
    int value;
    printf("Enter a value:\n");
    scanf("%d",&value);
    tree = Insert(tree,value);
    int choice;
    printf("Do you want add other node?\n 1) Yes\n 2) No \n");
    scanf("%d",&choice);
    if(choice==1){
        addNodes(tree);
    }
    return tree;
}

void BST(struct Nodo* raiz, struct Nodo* nodo_s){
    int orden;
    int option;
    int nodoSS = 0;
    int response = 0;

    printf("Whatyd' want to do?\n");
    printf("1.Insert\n2.Display\n3.Find\n");
    scanf("%d", &option);
    switch (option) {
        case 1:

            raiz = faketree(raiz);
            resultado(raiz);

            break;
        case 2:
            printf("1.Inorder\n2.Preorder\n3.Postorder\n");
            scanf("%d", &orden);
            switch (orden) {
                case 1:
                    printf("Transversal Display > ");
                    inOrder(raiz);
                    printf("\n");
                    break;
                case 2:
                    printf("Transversal Display > \n");
                    preOrder(raiz);
                    printf("\n");
                    break;
                case 3:
                    printf("Transversal Display > \n");
                    postOrder(raiz);
                    printf("\n");
                    break;

                default:
                    printf("Wrong Option, Please use other");
                    break;
            }
            break;
        case 3:
            printf("Enter the value \n");
            scanf("%d", &nodoSS);//asigno trae el valor a la memoria
            nodo_s = Find(raiz, nodoSS);
            if (nodo_s != NULL) {
                printf("Memory_Direction:=%p, =%d, Left=%d, Right=%d\n", (void *) nodo_s, nodo_s->valor,
                       (nodo_s->izq != NULL) ? nodo_s->izq->valor : -1,
                       (nodo_s->der != NULL) ? nodo_s->der->valor : -1);
            } else {
                printf("The node wasn't on the list\n");
            }
            break;
        case 4:
            faketree(raiz);
            preOrder(raiz);
            break;
        default:

            printf("Wrong Opcion");

            break;
    }
    printf("Continue?\n 1) Yes\n 2) No \n");
    scanf("%d", &response);
    if (response == 1){
        BST(raiz,nodo_s);
    }else{
        return;
    }

}


int main() {
    printf("Binary Search Tree \n");
    struct Nodo* raiz = NULL;
    struct Nodo* nodo_s = NULL;

    BST(raiz,nodo_s);

    return 0;
}


