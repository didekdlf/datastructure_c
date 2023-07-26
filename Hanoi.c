#include <stdio.h>
#include<stdlib.h>

int Hanoi(int n, char start, char middle, char end,int count)
{
	count++;
	char position[3];
	int result;
	position[0] = start;
	position[1] = middle;
	position[2] = end;
	if (n >1)
		count=Hanoi(n - 1, position[0], position[2], position[1],count);//middle로 n-1 보내기
	printf("%d from %cto %c\n", n,start, end);//end로 맨 밑에 것 보내기
	if (n > 1)
		count=Hanoi(n - 1, position[1], position[0], position[2],count);
	return count;
}

void Ch_1(void) {
	int c;
	c = Hanoi(3, 'A', 'B', 'C', 0);
	printf("%d", c);
	
}

void main(void){
	printf("hello world");
}