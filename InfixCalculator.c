#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[])     // 후위 표기법의 출력 및 계산한 수식을 반환
{
	int len = strlen(exp);
	int ret;
	char * expcpy = (char*)malloc(len+1);     // 문자열 저장공간 마련
	strcpy(expcpy, exp);     // exp를 expcpy에 복사

	ConvToRPNExp(expcpy);     // 후위 표기법의 수식으로 변환하는 함수
	ret = EvalRPNExp(expcpy);     // 변환된 수식의 계산

	printf("후위 표기법: %s \n", expcpy);

	free(expcpy);     // 문자열 저장공간 해제
	return ret;     // 계산결과 반환
}

