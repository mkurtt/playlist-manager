#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{

    char title[50];
    char artist[50];
    int duration; 
    struct Node *next;
    struct Node *prev;
} Node;

Node *newNode(char *title, char *artist, int duration){

    Node *node = malloc(sizeof(Node));
    strcpy(node->title, title);
    strcpy(node->artist, artist);
    node->duration = duration;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void addFirst(Node **head, char *title, char *artist, int duration);
void addLast(Node **head, char *title, char *artist, int duration);
void addAt(Node **head, char *title, char *artist, int duration, int index);
void deleteSong(Node **head, char *title);
void printForward(Node *head);
void printBackward(Node *head);
void totalDuration(Node *head);


int main(){
    Node *head = NULL;
    addFirst(&head,"name1","artist_name",5);
    addFirst(&head,"name2","artist_name",6);
    addFirst(&head,"name3","artist_name",7);
    addFirst(&head,"name4","artist_name",8);
    addFirst(&head,"name5","artist_name",9);
    addAt(&head, "name6", "artist_name", 10,3);
    printForward(head);
    printBackward(head);
    deleteSong(&head,"name4");
    printForward(head);
    totalDuration(head);
    return 0;
}


void addFirst(Node **head, char *title, char *artist, int duration){

    Node *temp = *head;
    Node *new = newNode(title,artist,duration);

    if(temp == NULL){
        *head = new;
        return;
    }
    new->next =temp;
    temp->prev = new;
    *head = new;
}

void addLast(Node **head, char *title, char * artist, int duration){

    Node *temp = *head;
    Node *new = newNode(title,artist,duration);

    while(temp!=  NULL && temp->next != NULL){ // 10 20 30
        temp = temp->next;
    }
    if( temp == NULL){
        addFirst(head,title,artist,duration);
    }
    else{
        new->prev =temp;
        temp->next = new;
    }
}

void addAt(Node **head, char* title, char *artist, int duration, int index){

    Node *temp = *head;
    Node *new = newNode(title,artist,duration);
    int i = 0;
    if( index == 0){
        addFirst(head,title,artist,duration);
        return;
    }
    while( i< index-1 && temp!= NULL){ // 10 20 (40) 30
        temp = temp->next;
        i++;
    }
    if ( temp == NULL){
        printf("Geçersiz.");
        return;
    }
    new->next = temp->next;
    new->prev = temp;
    if(temp->next != NULL){ // 10 20 30
        temp->next->prev = new;
    }
    temp->next= new;

}

void deleteSong(Node **head, char *title){

    Node *temp = *head;
    Node *temp2;

    if(strcmp((*head)->title, title) == 0){

        *head = (*head)->next;
        if(*head != NULL){
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    while(temp!= NULL && temp->next != NULL){
        if(strcmp(temp->title, title) == 0){
            temp2->next = temp->next;
            if(temp->next != NULL){
                temp->next->prev =temp2;
            }
            Node *sonraki = temp->next;
            free(temp);
            temp = sonraki;
        }
        else{
            temp2 = temp;
            temp = temp->next;
        }
    }
}

void printForward(Node *head){

    Node *temp = head;

    while(temp!= NULL){ // 10 20 30 
        printf("Title: %s | Artist: %s | Duration: %d\n ", temp->title,temp->artist,temp->duration);
        temp = temp->next;
    }
    printf("NULL\n");

}

void printBackward(Node *head){
    Node *temp = head;
    while(temp->next != NULL){  // 10 20 30 40
        temp = temp->next;
    }
    while(temp!= NULL){
        printf("Title: %s | Artist: %s | Duration: %d\n", temp->title, temp->artist,temp->duration);
        temp = temp->prev;
    }
    printf("NULL\n");

}

void totalDuration(Node *head){
    Node *temp = head;
    int sum = 0;

    while(temp!=NULL){ // 10 20 30 40
        sum+= temp->duration;
        temp =temp->next;
    }
    printf("Total Duration: %d\n", sum);
}