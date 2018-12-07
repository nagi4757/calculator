#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrec(char op)     // �������� ���� �켱���� ������ ��ȯ
{
	switch(op)
	{
	case '*':
	case '/':
		return 5;     // ���� ���� ������ �켱����
	case '+':
	case '-':
		return 3;     // 5���� �۰� 1���� ���� ������ �켱����
	case '(':
		return 1;     // ���� ���� ������ �켱����
	}

	return -1;   // ��ϵ��� ���� ������
}

int WhoPrecOp(char op1, char op2)     // �켱���� ��
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if(op1Prec > op2Prec)     // op1�� �켱������ �� ���ٸ�
		return 1;
	else if(op1Prec < op2Prec)     // op2�� �켱������ �� ���ٸ�
		return -1;
	else     // op1�� op2�� �켱������ ���ٸ�
		return 0;     
}

void ConvToRPNExp(char exp[])     // ���� ǥ����� �������� ��ȯ
{
	Stack stack;
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen+1);     // ��ȯ�� ������ ���� ���� ����

	int i, idx=0, j;
	char tok, popOp;


	memset(convExp, 0, sizeof(char)*expLen+1);     // �Ҵ�� �迭�� 0���� �ʱ�ȭ
	StackInit(&stack);

	for(i=0; i<expLen; i++)
	{
		tok = exp[i];     // exp�� ���޵� ������ �� ���ھ� tok�� ����
		if(isdigit(tok))     // tok�� ����� ���ڰ� �������� Ȯ��
		{
			convExp[idx++] = tok;     // �����̸� �迭 convExp�� ����
			
		}
		else     // ���ڰ� �ƴϸ�(�������� ���)
		{
			switch(tok)
			{
			case '(':     // ���� �Ұ�ȣ�̸�
				SPush(&stack, tok);     // ���ÿ� �״´�.
				break;

			case ')':     // �ݴ� �Ұ�ȣ�̸�
				while(1)     // �ݺ�
				{
					popOp = SPop(&stack);     // ���ÿ� �����ڸ� ������.
					if(popOp == '(')     // ������ '('�� ������ �������´�.
						break;
					convExp[idx++] = popOp;     // �迭 convExp�� �����Ѵ�.
				}
				break;

			case '+': case '-':     // ��Ģ������ ���
			case '*': case '/':
				while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)     
					convExp[idx++] = SPop(&stack); 

				SPush(&stack, tok);     // ���ÿ� �״´�.
				break;
			}
		}
		printf("����: ");
		PrintStack(&stack);
		printf("\n");
		
		printf("��ȯ�� ������ ��ġ�� �ڸ�: ");
		for(j=0; j<idx; j++)
		{
				printf("%c ", convExp[j]);
		}
		printf("\n\n");
	}

	while(!SIsEmpty(&stack))     // ���ÿ� ���� �ִ� ��� �����ڸ�,
		convExp[idx++] = SPop(&stack);     // �迭 convExp�� �̵�
	
	printf("����: ");
	PrintStack(&stack);
	printf("\n");

	printf("��ȯ�� ������ ��ġ�� �ڸ�: ");
	for(j=0; j<idx; j++)
	{
		printf("%c ", convExp[j]);
	}
		printf("\n\n");	
		
		strcpy(exp, convExp);     // ��ȯ�� ������ exp�� �����Ѵ�.
		free(convExp);     // convExp�� �Ҹ��Ų��.
}