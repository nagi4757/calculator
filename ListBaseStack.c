#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack)     // ���� �ʱ�ȭ
{
	pstack->head = NULL;     // ������ ���� head�� NULL�� �ʱ�ȭ�Ѵ�.
}

int SIsEmpty(Stack * pstack)     // ������ ������� Ȯ��
{
	if(pstack->head == NULL)     // ������ ��� head���� NULL�� ����ȴ�.
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)     // ������ push ����
{
	Node * newNode = (Node*)malloc(sizeof(Node));     // �� ��� ����

	newNode->data = data;     // �� ��忡 �����͸� ����
	newNode->next = pstack->head;     // �� ��尡 �ֱٿ� �߰��� ��带 ����Ų��.

	pstack->head = newNode;     // ������ ���� head�� �� ��带 ����Ų��.
}

Data SPop(Stack * pstack)     // ������ pop ����
{
	Data rdata;
	Node * rnode;

	if(SIsEmpty(pstack))     // ������ ����� ������
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;     // ������ ����� �����͸� �ӽ÷� �����Ѵ�.
	rnode = pstack->head;     // ������ ����� �ּ� ���� �ӽ÷� �����Ѵ�.

	pstack->head = pstack->head->next;     // ������ ����� ���� ��带 head�� ����Ų��.
	free(rnode);     // ��带 ���� �Ѵ�.
	
	return rdata;     // ������ ����� �����͸� ��ȯ�Ѵ�. 
}

Data SPeek(Stack * pstack)     // ������ peek ����
{
	if(SIsEmpty(pstack))     // ������ ����� ������
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;     // head�� ����Ű�� ��忡 ����� �����͸� ��ȯ�Ѵ�.
}

void PrintStack(Stack * pstack)     // ������ ������ ����ϴ� �Լ�
{
	Node * phead = (Node*)malloc(sizeof(Node));     // phead ����     

	phead = pstack->head;     // phead�� ������ head�� ����Ų��.

	while(phead != NULL)     // phead�� NULL�� �ƴ� ������ �ݺ�
	{
		if(phead->data == NULL)     // phead�� �����Ͱ� NULL�̸� ����������.
		{
			return;
		}
		printf("%c ", phead->data);
		phead = phead->next;     // phead�� phead�� ���� ����Ű�� �κ��� ����Ų��.
	}
}