#include <stdio.h>
#include <stdlib.h>
  
/**
 * 
 * Definizione di una struct del nodo singolo
 * 
 * @param key chiave del nodo
 * @param left puntatore del nodo verso il figlio a sinistra
 * @param right puntatore del nodo verso il figlio a destra
*/
struct node {
    int key;
    struct node *left, *right;
};
  
/**
 * Metodo per la definizione di un nuovo BST
 * @param item indice del nuovo root
 * @return un nuovo oggetto struct node 
*/
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/**
 * Metodo per la inserzione di un nuovo elemento
 * in una BST
 * @param node il nodo root nella quale inserire il nuovo elemento
 * @param key l'elemento da inserire all'interno della tree
 * @return il nodo aggiornato con il nuovo elemento
*/
struct node* insert(struct node* node, int key) {
    // Se il nodo è vuoto, senza chaive, richiama il metodo newNode
    if (node == NULL)
        return newNode(key);
  
    // Altrimenti, prosegue con l'inserzione dell'elemento nella tree
    // Se la chiave è minore del nodo, lo inserisce nel nodo di sinistra
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    // Se la chiave è maggiore del nodo, lo inserisco nel nodo di destra 
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    // Se è uguale rimane invariato
    return node;
}

/**
 * Metodo per la stampa della tree in ordine crescente
 * @param root il nodo root da stampare
*/
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void main() {
    // Creiamo il nodo root
    struct node* root = NULL;
    
    // Inseriamo dei valori nella tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    // Stampiamo la tree
    inorder(root);
}