#include <stdio.h>
#include "InfixCalculator.h"

int main(void)     // ���� �����Լ�
{
	char exp1[100];

	printf("��Ģ ������ �Է��Ͻÿ�(���� ǥ�������): ");
	scanf("%s",exp1);
	printf("\n");

	printf("�����: %s = %d \n", exp1, EvalInfixExp(exp1));
	
	return 0;
}