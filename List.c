#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* nextNode;
}Node;
typedef struct LinkedList {
	int CurCount;
	Node headNode;
}LinkedList;

LinkedList* addlist(LinkedList* li, int data,int pos) {
	Node* n=(Node*)malloc(sizeof(Node));//새로운 노드
	Node* nad = &(li->headNode);
	Node* next;
	printf("curcount = %d,data = %d, pos = %d\n", li->CurCount, data, pos);
	if (li->CurCount == 0) {
		li->headNode.data = data;
	}
	else 
	{
		if (li->CurCount < pos) {
			pos = li->CurCount;
		}
		for (int i = 1; i < pos; i++)//탐색
		{
			printf("%dst %d\n", i, nad->data);
			nad = nad->nextNode;
			
		}
		printf("\n");
		next = nad->nextNode;
		n->data = data;
		nad->nextNode = n;

		n->nextNode=next;

	}

	
	li->CurCount++;
	return li;
}

LinkedList* removelist(LinkedList* li, int pos) {
	Node* n=&(li->headNode);
	Node* pre;
	Node* next;
	for (int i = 2; i < pos; i++)//탐색
	{
		n = n->nextNode;
	}
	//삭제
	pre = n;
	Node* now = n->nextNode;
	pre->nextNode = n->nextNode->nextNode;
	free(now);
	li->CurCount--;

	return li;
}


void Ch_2(void) {
	//make list
	LinkedList* lili = (LinkedList*)malloc(sizeof(LinkedList));
	Node* na = &(lili->headNode);
	lili->headNode.nextNode = &(lili->headNode);
	lili->CurCount = 0;
	lili = addlist(lili, 1,1);
	lili = addlist(lili, 5,2);
	lili = addlist(lili, 2,2);
	lili = addlist(lili, 3,3);
	lili = addlist(lili, 4,4);
	lili = addlist(lili, 2, 5);
	lili = addlist(lili, 9, 5);
	lili = addlist(lili, 5, 5);
	lili = removelist(lili, 5);
	na = &(lili->headNode);
	printf("\n결과\n");
	for (int i = 0; i < lili->CurCount; i++) {
		printf("%d ", na->data);
		na = na->nextNode;
	}
	printf("\n");

}

void main(void){
    Ch_2();
}