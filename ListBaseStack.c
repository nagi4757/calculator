#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack)     // 스택 초기화
{
	pstack->head = NULL;     // 포인터 변수 head는 NULL로 초기화한다.
}

int SIsEmpty(Stack * pstack)     // 스택이 비었는지 확인
{
	if(pstack->head == NULL)     // 스택이 비면 head에는 NULL이 저장된다.
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)     // 스택의 push 연산
{
	Node * newNode = (Node*)malloc(sizeof(Node));     // 새 노드 생성

	newNode->data = data;     // 새 노드에 데이터를 저장
	newNode->next = pstack->head;     // 새 노드가 최근에 추가된 노드를 가리킨다.

	pstack->head = newNode;     // 포인터 변수 head가 새 노드를 가리킨다.
}

Data SPop(Stack * pstack)     // 스택의 pop 연산
{
	Data rdata;
	Node * rnode;

	if(SIsEmpty(pstack))     // 스택이 비워져 있으면
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;     // 삭제할 노드의 데이터를 임시로 저장한다.
	rnode = pstack->head;     // 삭제할 노드의 주소 값을 임시로 저장한다.

	pstack->head = pstack->head->next;     // 삭제할 노드의 다음 노드를 head가 가리킨다.
	free(rnode);     // 노드를 삭제 한다.
	
	return rdata;     // 삭제된 노드의 데이터를 반환한다. 
}

Data SPeek(Stack * pstack)     // 스택의 peek 연산
{
	if(SIsEmpty(pstack))     // 스택이 비워져 있으면
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;     // head가 가리키는 노드에 저장된 데이터를 반환한다.
}

void PrintStack(Stack * pstack)     // 스택의 과정을 출력하는 함수
{
	Node * phead = (Node*)malloc(sizeof(Node));     // phead 생성     

	phead = pstack->head;     // phead는 스택의 head를 가리킨다.

	while(phead != NULL)     // phead가 NULL이 아닐 때까지 반복
	{
		if(phead->data == NULL)     // phead의 데이터가 NULL이면 빠져나간다.
		{
			return;
		}
		printf("%c ", phead->data);
		phead = phead->next;     // phead는 phead의 다음 가리키는 부분을 가리킨다.
	}
}