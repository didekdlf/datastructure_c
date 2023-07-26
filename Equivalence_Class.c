#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Linked_list{
    int count;
    Node head;
}Llist;

typedef struct Equivalence_Class
{
    int count;
    Llist* eclass;
}Eclass;

void addlist(Llist* li, int data){
    if (li->count ==0){
        li->head.data=data;
        li->head.next=NULL;
    }
    else{
        Node* n= (Node*)malloc(sizeof(Node));
        Node* pre=&(li->head);
        for (int i=0; i<li->count;i++){
            pre = pre->next;
        }
        n->data=data;
        pre->next = n;
    }

    li->count++;
}

int findlist(Llist* li, int inp){
    Node* np=(&li->head);
    for (int i=0; i<li->count;i++){
        if(np->next==inp){
            return 1;
        }
        np=np->next;
    }
    return 0;
}

void makeEC(Eclass* ec){
    ec->eclass = (Eclass*)malloc(sizeof(ec->eclass));

}

void addEC(Eclass* ec,int inp1,int inp2){
    if(ec->count=0){

    }
}






void Ch_4(){

}





void main(){
    Ch_4();

}