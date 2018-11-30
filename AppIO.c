#include "AppIO.h"

#include <stdio.h>
#include <conio.h>

char AppIO_in_charDirectlyFromKeyboard()
{ // ������� Ű����κ��� �Է¹��� ���ڸ� ���� �ʿ���� �ٷ� �����Ѵ�.
	printf("���ڸ� �Է��Ͻÿ� : ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppIO_out_newLine();
	return charDirectlyFromKeyboard;
}

char getCharDirectlyFromKeyboard(void)
{ /*���� ���͸� ������ ����� �ƴ� Ű���忡��
  ������ ���� �ٷ� �ν��ϵ��� �ϴ� �Լ�*/
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}


void AppIO_out_stackIsFullAgainstPush(char anElementForPush)
{
	printf("[Push: Full] ������ �� ���� ���� \'%c\' �� ������ �Ұ����մϴ�.\n", anElementForPush);
}
void AppIO_out_pushedElement(char anElement)
{
	printf("[Push] ���Ե� ���Ҵ� \'%c\' �Դϴ�.\n", anElement) ;
}
void AppIO_out_stackIsEmptyAgainstPop1()
{
	printf("[Pop1:Empty] ���ÿ� ������ ���Ұ� �����ϴ�.\n");
}
void AppIO_out_poppedElementByPop1(char anElement)
{
	printf("[Pop1] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}
void AppIO_out_beginPops(int numberOfElements)
{
	printf("[Pops] % d ���� ���Ҹ� �����Ϸ��� �մϴ� : \n", numberOfElements);
}
void AppIO_out_endPops()
{
	printf("[Pops] ������ �����մϴ�. \n");
}
void AppIO_out_stackIsEmptyAgainstPops()
{
	printf("[Pops: Empty] ���ÿ� �� �̻� ������ ���Ұ� �����ϴ�.\n") ;
}
void AppIO_out_topElement(char anElement)
{
	printf("[Top] Top ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}
void AppIO_out_noTopElement()
{
	printf("[Top:Empty] ���� ������ ��� �ֽ��ϴ�.\n");
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
	printf("[Size] ���� ������ ũ��� %d �Դϴ�.\n", stackSize);
}
void AppIO_out_ignoredChar()
{
	printf("[Ignore] �ǹ� ���� ���ڰ� �ԷµǾ����ϴ�.\n");
}
void AppIO_out_endInput()
{
	printf("[End Input] �Է��� �����ϸ�, ������ ��� ���Ҹ� �����մϴ� : \n");
}
void AppIO_out_poppedElementByEndInput(char anElement)
{
	printf(" - End Input : ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}

void AppIO_out_numberOfInputChars(int numberOfChars)
{
	printf("�����Էµ� ���ڴ� ��� %d �� �Դϴ�.\n", numberOfChars);
}
void AppIO_out_numberOfNormallyProcessedChars(int numberOfChars)
{
	printf("������������ ó���� ���ڴ� %d �� �Դϴ�.\n", numberOfChars);
}
void AppIO_out_numberOfIgnoredChars(int numberOfChars)
{
	printf("�������õ� ���ڴ� %d �� �Դϴ�.\n", numberOfChars);
}
void AppIO_out_numberOfPushedChars(int numberOfChars)
{
	printf("�������ÿ� ���� ���ڴ� %d �� �Դϴ�.\n ", numberOfChars);
}
void AppIO_out_startProgram()
{
	printf("<< < ���� ó�� ���α׷��� �����մϴ� >> >\n ");
	AppIO_out_newLine();
}
void AppIO_out_endProgram()
{
	AppIO_out_newLine();
	printf(" << < ���� ó�� ���α׷��� �����մϴ� >> >\n ");
}

void AppIO_out_numberOfElements(int numberOfChars) {
	printf("[size] ���ÿ��� ���� %d���� ���Ұ� �ֽ��ϴ�.\n", numberOfChars);
}
