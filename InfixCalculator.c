#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[])     // ���� ǥ����� ��� �� ����� ������ ��ȯ
{
	int len = strlen(exp);
	int ret;
	char * expcpy = (char*)malloc(len+1);     // ���ڿ� ������� ����
	strcpy(expcpy, exp);     // exp�� expcpy�� ����

	ConvToRPNExp(expcpy);     // ���� ǥ����� �������� ��ȯ�ϴ� �Լ�
	ret = EvalRPNExp(expcpy);     // ��ȯ�� ������ ���

	printf("���� ǥ���: %s \n", expcpy);

	free(expcpy);     // ���ڿ� ������� ����
	return ret;     // ����� ��ȯ
}

