#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud de la liste
typedef struct Node {
    int data;
    struct Node* next;
}Node;

// Fonction pour ajouter un nœud à la liste
void addNode(Node** head, int data){
    // On alloue un nouveau nœud
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // On ajoute l'élement en tête de liste
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

// Fonction principale
int main() {
    // Initialisation de la liste
    Node* head = NULL;

    // Code pour manipuler la liste...

    return 0;
}
