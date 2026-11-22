#include <stdio.h>
#include <stdlib.h>

typedef struct object{
    int data;
    struct object *next, *prev;
} Node;

Node* createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return NULL;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

Node* insertBeginning(Node *root, int value)
{
    Node *newNode = createNode(value);
    if (newNode == NULL) return NULL;

    if(root == NULL){
        root = newNode;
        return root;
    }
    else{
        newNode->next = root;
        root->prev = newNode;
        root = newNode;
    }
   
    return root;
}

Node* insertSpecific(Node *root, int value, int pos)
{
    if(pos == 1) return insertBeginning(root, value);
    else
    {
        Node *newNode = createNode(value);
        if(newNode == NULL) return NULL;

        Node *temp = root;
        for(int i=1; i<pos-1; i++){
            temp = temp->next;
        }

        newNode->prev = temp;
        newNode->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = newNode; //NULL doesnt point towaed anything, only Node points to NULL
        }
        temp->next = newNode;
    }
    return root;
}

Node* reverse(Node *root)
{
    Node *current = root;
    Node *next = NULL;
    Node *prev = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        current->prev = next;

        prev = current;
        current = next;
    }

    return root;
}


int main()
{
    Node *first, *second, *third, *fourth;

    first = malloc(sizeof(Node));
    second= malloc(sizeof(Node));
    third = malloc(sizeof(Node));
    fourth = malloc(sizeof(Node));

    first->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    fourth->prev = third;
    third->prev = second;
    second->prev = first;
    first->prev = NULL;

    Node *temp = first;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
    reverse(first);

    Node *temp1 = fourth;
    while(temp1 != NULL){
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }

}