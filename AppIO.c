#include "AppIO.h"

#include <stdio.h>
#include <conio.h>

char AppIO_in_charDirectlyFromKeyboard()
{ // 사용자의 키보드로부터 입력받은 문자를 엔터 필요없이 바로 저장한다.
	printf("문자를 입력하시오 : ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppIO_out_newLine();
	return charDirectlyFromKeyboard;
}

char getCharDirectlyFromKeyboard(void)
{ /*기존 엔터를 누르는 방식이 아닌 키보드에서
  누르는 순간 바로 인식하도록 하는 함수*/
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}


void AppIO_out_stackIsFullAgainstPush(char anElementForPush)
{
	printf("[Push: Full] 스택이 꽉 차서 원소 \'%c\' 는 삽입이 불가능합니다.\n", anElementForPush);
}
void AppIO_out_pushedElement(char anElement)
{
	printf("[Push] 삽입된 원소는 \'%c\' 입니다.\n", anElement) ;
}
void AppIO_out_stackIsEmptyAgainstPop1()
{
	printf("[Pop1:Empty] 스택에 삭제할 원소가 없습니다.\n");
}
void AppIO_out_poppedElementByPop1(char anElement)
{
	printf("[Pop1] 삭제된 원소는 \'%c\' 입니다.\n", anElement);
}
void AppIO_out_beginPops(int numberOfElements)
{
	printf("[Pops] % d 개의 원소를 삭제하려고 합니다 : \n", numberOfElements);
}
void AppIO_out_endPops()
{
	printf("[Pops] 삭제를 종료합니다. \n");
}
void AppIO_out_stackIsEmptyAgainstPops()
{
	printf("[Pops: Empty] 스택에 더 이상 삭제할 원소가 없습니다.\n") ;
}
void AppIO_out_topElement(char anElement)
{
	printf("[Top] Top 원소는 \'%c\' 입니다.\n", anElement);
}
void AppIO_out_noTopElement()
{
	printf("[Top:Empty] 현재 스택은 비어 있습니다.\n");
}

void AppIO_out_bottomOfStack()
{
	printf("<Bottom of Stack>");
}
void AppIO_out_element(char anElement)
{
	printf("%c", anElement);
}
void AppIO_out_topOfStack()
{
	printf("<Top of Stack>");
}
void AppIO_out_newLine()
{
	printf("\n");
}
void AppIO_out_stackSize(int stackSize)
{
	printf("[Size] 현재 스택의 크기는 %d 입니다.\n", stackSize);
}
void AppIO_out_ignoredChar()
{
	printf("[Ignore] 의미 없는 문자가 입력되었습니다.\n");
}
void AppIO_out_endInput()
{
	printf("[End Input] 입력을 종료하며, 스택의 모든 원소를 삭제합니다 : \n");
}
void AppIO_out_poppedElementByEndInput(char anElement)
{
	printf(" - End Input : 삭제된 원소는 \'%c\' 입니다.\n", anElement);
}

void AppIO_out_numberOfInputChars(int numberOfChars)
{
	printf("……입력된 문자는 모두 %d 개 입니다.\n", numberOfChars);
}
void AppIO_out_numberOfNormallyProcessedChars(int numberOfChars)
{
	printf("……정상으로 처리된 문자는 %d 개 입니다.\n", numberOfChars);
}
void AppIO_out_numberOfIgnoredChars(int numberOfChars)
{
	printf("……무시된 문자는 %d 개 입니다.\n", numberOfChars);
}
void AppIO_out_numberOfPushedChars(int numberOfChars)
{
	printf("……스택에 넣은 문자는 %d 개 입니다.\n ", numberOfChars);
}
void AppIO_out_startProgram()
{
	printf("<< < 스택 처리 프로그램을 시작합니다 >> >\n ");
	AppIO_out_newLine();
}
void AppIO_out_endProgram()
{
	AppIO_out_newLine();
	printf(" << < 스택 처리 프로그램을 종료합니다 >> >\n ");
}

void AppIO_out_numberOfElements(int numberOfChars) {
	printf("[size] 스택에는 현재 %d개의 원소가 있습니다.\n", numberOfChars);
}
