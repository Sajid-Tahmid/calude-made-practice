#include <stdio.h>
#include <stdlib.h>

typedef struct object{
    int data;
    struct object *link;
} Node;

Node* createNode(int value)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->link = NULL;

    return newNode;
}

/* The thing about double pointer is, only when the head or root changes we need to use it. Or, we can use pointer returning function.
   In simple words, where we do not need to modify head at the last, we can just use void with a single pointer */

void display(Node* root)
{
    Node *temp = root;
    while(root != NULL){
        printf("%d ", root->data);
        temp = temp->link;
    }
}

Node* insertBeginning(Node* root, int value)
{
    Node *newNode = createNode(value);
    newNode->link = root;
    root = newNode;

    return root;
}

Node* insertEnd(Node* root, int value)
{
    Node *newNode = createNode(value);
    if(root == NULL) return newNode;

    Node *temp = root;
    while(temp->link != NULL){
        temp = temp->link;
    }

    temp->link = newNode;

    return root;
}

Node* insertSpecific(Node* root, int value, int pos)
{
    if(pos == 1) return insertBeginning(root, value);
    else
    {
        Node *newNode = createNode(value);
        Node *temp = root;
        for(int i=1; i<pos-1; i++){
            temp = temp->link;
        }
        newNode->link = temp->link;
        temp->link = newNode;
    }
    return root;
}

Node* deleteBeginning(Node *root)
{
    Node *temp = root;
    root = root->link;
    free(temp);

    return root;
}

Node* deleteEnd(Node* root)
{
    Node *temp = root;
    while (temp->link->link != NULL){
        temp = temp->link;
    }
    temp->link = NULL;

    return root;
}

Node* deleteSpecific(Node* root, int position)
{
    Node* temp = root;
    for(int i=1; i<position-1; i++){
        temp = temp->link;
    }
    Node* del = temp->link;
    temp->link = del->link;
    free(del);

    return root;
}

Node* reverse(Node* root)
{
    Node *current = root;
    Node *prev  = NULL;
    Node *next = NULL;

    while(current != NULL){
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    root = prev;

    return root;
}

Node* reverseRecursion(Node *root)
{
    if(root == NULL || root->link == NULL) return root;

    Node *newNode = reverse(root->link);
    root->link->link = root;
    root->link = NULL;
    return newNode;
}

Node* reverseInGroup(Node* root, int k)
{
    if(root == NULL || k<=1) return root;

    Node *prevGroupEnd = NULL;
    Node *groupStart = root;

    while(groupStart != NULL){
        Node *temp = groupStart;
        int count = 0;

        while(temp != NULL && count<k){
            temp = temp->link;
            count++;
        }

        if(count < k) break;

        Node *current = groupStart;
        Node *prev = NULL;
        Node *next = NULL;

        for(int i=0; i<k; i++){
            next = current->link;
            current->link = prev;
            prev = current;
            current = next;
        }

        if(prevGroupEnd == NULL){
            root = prev;
        }
        else{
            prevGroupEnd->link = prev;
        }
        groupStart->link = current;
        prevGroupEnd = groupStart;
        groupStart = current;
    }
    return root;
}

Node* removeDuplicate(Node *root)
{
    Node *temp = root;
    int i = 2;
    while(temp != NULL && temp->link != NULL){
        if(temp->data == temp->link->data){
            deleteSpecific(root, i);
        }
        else{
            temp = temp->link;
            i++;
        }
    }
    return root;
}

void removeDuplicate2(Node *root)
{
    Node *temp = root;
    while(temp != NULL && temp->link != NULL){
        if(temp->data == temp->link->data){
            Node *duplicate = temp->link;
            temp->link = duplicate->link;
            free(duplicate);
        }
        else{
            temp = temp->link;
        }
    }
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

    first->link = second;
    second->link = third;
    third->link = fourth;
    fourth->link = NULL;


    printf("\n");
    reverse(first);

    Node* temp2 = fourth;
    while(temp2 != NULL){
        printf("%d ", temp2->data);
        temp2 = temp2->link;
    }

    printf("\n");
    reverseRecursion(fourth);

    Node* temp1 = first;
    while(temp1 != NULL){
        printf("%d ", temp1->data);
        temp1 = temp1->link;
    }
}