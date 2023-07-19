#include <stdio.h>
#include<stdlib.h>

typedef struct Snode {
	int data;
	struct Snode* nextNode;
}Snode;

typedef struct Stack {
	int Curcount;
	struct Snode* TopNode;
}Stack;

void Push(Stack* s, int data) {
	Snode* ns = (Snode*)malloc(sizeof(Snode));
	ns->nextNode = NULL;
	if (s->Curcount != 0) {
		ns->data = s->TopNode->data;
		ns->nextNode = s->TopNode->nextNode;
		s->TopNode->nextNode = ns;
		
	}
	s->TopNode->data = data;
	s->Curcount++;

}
int Pop(Stack* s) {
	int top=0;
	if (s->Curcount != 0) {
		top= s->TopNode->data;
		s->TopNode = s->TopNode->nextNode;
	}
	else {
		s->TopNode->data = 0;
		s->TopNode->nextNode = NULL;
		//printf("%d\n\n", s->TopNode->data);
	}
	s->Curcount--;
	return top;
}
void deleteS(Stack* s) {
	Snode *ss, *ds;
	ss = s->TopNode;
	for (int i = 0; i < s->Curcount; i++) {
		ds = ss;
		free(ds);
		ss = ss->nextNode;
	}
	free(s);
}

void Ch_3_1(void) {
	//stack
	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->TopNode = (Snode*)malloc(sizeof(Snode));
	s->TopNode->nextNode = NULL;
	s->Curcount = 0;

	Push(s, 1);
	Push(s, 2);
	Push(s, 3);
	Push(s, 5);
	Push(s, 2);

	printf("%d ", Pop(s));
	printf("%d ", Pop(s));
	printf("%d ", Pop(s));
	printf("%d ", Pop(s));
	printf("%d ", Pop(s));

	deleteS(s);
}