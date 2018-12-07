#include <stdio.h>
#include "InfixCalculator.h"

int main(void)     // 계산기 메인함수
{
	char exp1[100];

	printf("사칙 연산을 입력하시오(중위 표기법으로): ");
	scanf("%s",exp1);
	printf("\n");

	printf("계산결과: %s = %d \n", exp1, EvalInfixExp(exp1));
	
	return 0;
}