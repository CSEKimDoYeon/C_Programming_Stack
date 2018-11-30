#include "AppController.h"
#include "AppIO.h"

void AppController_run(AppController* _this) { // ���α׷� ���� �Լ�.
	AppIO_out_startProgram();

	AppController_initCountingChars(_this);
	AppIO_out_newLine();
	char c = AppIO_in_charDirectlyFromKeyboard();
	// Ű����� �Է¹��� ���ڸ� ���� ����.

	while (c != Esc) { // Esc�� �Է� �� �� ���� ����.
		AppController_countInputChars(_this);
		if (isAlpha(c)) {
			AppController_push(_this, c);
			// ���ĺ��ϰ�� ���ÿ� push
		}
		else if (isDigit(c)) {
			int digitValue = c - '0';
			AppController_pops(_this, digitValue);
			// �����ϰ�� ���ڸ�ŭ pop
		}
		else if (c == '-') {
			AppController_pop1(_this);
			// - �� ��� �ϳ��� pop
		}
		else if (c == '#') {
			AppController_showSize(_this);
			// # �� ��� ������ ������ ���.
		}
		else if (c == '/') {
			AppController_showAllFromBottom(_this);
			// '/' �� ��� ������ bottom���� top���� ���.
		}
		else if (c == '\\') {
			AppController_showAllFromTop(_this);
			// \ �� ��� ������ top���� bottom���� ���.
		}
		else if (c == '^') {
			AppController_showTopElement(_this);
			// ^ �� ��� �� ������ top Element ���.
		}
		else {
			AppController_ignore(_this);
			// �̿��� ���ڴ� ���� ó��.
		}
		AppIO_out_newLine();
		c = AppIO_in_charDirectlyFromKeyboard();
	}
	AppController_endInput(_this);
	// ���α׷��� ����Ǹ� ��� ���� ����.
	AppController_showStatistics(_this);
	AppIO_out_endProgram();
}


AppController* AppController_new() {
	// AppController ��ü ����.
	AppController* _this;
	_this = NewObject(AppController);
	_this->_stack = Stack_new();
	return _this;
}

void AppController_delete(AppController* _this) {
	// AppController ��ü ����.
	Stack_delete(_this->_stack);
	free(_this);
}

void AppController_push(AppController* _this, char aChar) {
	// ���ÿ� aChar�� push�ϴ� �Լ�.
	if (Stack_isFull(_this->_stack)) {
		AppIO_out_stackIsFullAgainstPush(aChar);
	} // ������ �� á�� ��쿡�� ���� �ʴ´�.
	else {
		Stack_push(_this->_stack, aChar);
		AppIO_out_pushedElement(aChar);
		AppController_countPushedChars(_this);
	}
}

void AppController_pop1(AppController* _this) {
	// ���ÿ��� �ֻ����� �Ѱ��� ���� pop
	if (Stack_isEmpty(_this->_stack)) {
		AppIO_out_stackIsEmptyAgainstPop1();
	} // ������ ��������� pop���� �ʴ´�.
	else {
		char poppedChar = Stack_pop(_this->_stack);
		AppIO_out_poppedElementByPop1(poppedChar);
	}
}

void AppController_pops(AppController* _this, int numberOfChars) {
	// numberOfChar �Է� �� ��ŭ ���ÿ��� pop ����.
	if (numberOfChars > Stack_size(_this->_stack)) {
		AppIO_out_beginPops(numberOfChars);
		for (int i = 0; (i < numberOfChars) && (!Stack_isEmpty(_this->_stack)); i++)
		{
			char poppedChar = Stack_pop(_this->_stack);
			AppIO_out_poppedElementByPop1(poppedChar);
		}
		AppIO_out_stackIsEmptyAgainstPops();
		// �Է� ���� ������� Ŭ ��� ��� �����ϰ� ������ ����ٴ� �޽��� ���.
	}
	else {
		AppIO_out_beginPops(numberOfChars);
		for (int i = 0; (i < numberOfChars) && (!Stack_isEmpty(_this->_stack)); i++)
		{
			char poppedChar = Stack_pop(_this->_stack);
			AppIO_out_poppedElementByPop1(poppedChar);
		}
		AppIO_out_endPops();
		// �Է� ���� ������� ���� ��� �����ŭ ����.
	}
}

void AppController_showAllFromBottom(AppController* _this) {
	// ������ Bottom���� Top���� ������� ���Ҹ� ���.
	char stackElement;
	AppIO_out_bottomOfStack();
	for (int i = 0; i < Stack_size(_this->_stack); i++) {
		stackElement = Stack_elementAt(_this->_stack, i);
		AppIO_out_element(stackElement);
	}
	AppIO_out_topOfStack();
	AppIO_out_newLine();
}

void AppController_showAllFromTop(AppController* _this) {
	// ������ Top���� Bottom���� ������� ���Ҹ� ���.
	char stackElement;
	AppIO_out_topOfStack();
	for (int i = Stack_size(_this->_stack) - 1; i >= 0; i--) {
		stackElement = Stack_elementAt(_this->_stack, i);
		AppIO_out_element(stackElement);
	}
	AppIO_out_bottomOfStack();
	AppIO_out_newLine();
}

void AppController_initCountingChars(AppController* _this)
{
	// �Է¼�, ������ ��, Ǫ���� ���� ���� �� ������ ī����.
	_this->_inputChars = 0;
	_this->_ignoredChars = 0;
	_this->_pushedChars = 0;
}

void AppController_countInputChars(AppController* _this)
{
	// �Է��� ������ ���� �߰����ش�.
	_this->_inputChars++;
}

void AppController_countIgnoredChars(AppController* _this)
{
	// ������ ������ ���� �߰����ش�.
	_this->_ignoredChars++;
}

void AppController_countPushedChars(AppController* _this)
{
	// Ǫ���� ������ ���� �߰����ش�.
	_this->_pushedChars++;
}

int AppController_numberOfInputChars(AppController* _this)
{
	//�Է��� ������ ���� �߰����ش�.
	return (_this->_inputChars);
}

int AppController_numberOfNormallyProcessedChars(AppController* _this)
{
	// ���� �Էµ� ������ ������ ��ȯ�Ѵ�.
	return (_this->_inputChars - _this->_ignoredChars);
}

int AppController_numberOfIgnoredChars(AppController* _this)
{
	// ������ ������ ���� ��ȯ�Ѵ�.
	return (_this->_ignoredChars);
}

int AppController_numberOfPushedChars(AppController* _this)
{
	// Ǫ���� ������ ���� ��ȯ�Ѵ�.
	return (_this->_pushedChars);
}

void AppController_showStatistics(AppController* _this)
{
	// ���ݱ����� ��踦 �������� ��� �ڷ���� ��� ����Ѵ�.
	AppIO_out_newLine();
	AppIO_out_numberOfInputChars(AppController_numberOfInputChars(_this));
	AppIO_out_numberOfNormallyProcessedChars(AppController_numberOfNormallyProcessedChars(_this));
	AppIO_out_numberOfIgnoredChars(AppController_numberOfIgnoredChars(_this));
	AppIO_out_numberOfPushedChars(AppController_numberOfPushedChars(_this));
}

void AppController_endInput(AppController* _this) {
	// Esc�� �ԷµǾ� ����Ǹ� ��� ������ ���ҵ��� ������.
	char Elements;
	AppIO_out_endInput();
	for (int i = Stack_size(_this->_stack) - 1; i >= 0; i--) {
		Elements = Stack_elementAt(_this->_stack, i);
		AppIO_out_poppedElementByEndInput(Elements);
	}
}

void AppController_showSize(AppController* _this) {
	// �� ������ size�� ����Ѵ�.
	int size = Stack_size(_this->_stack);
	AppIO_out_numberOfElements(size);
}

void AppController_showTopElement(AppController* _this) {
	// �� ������ �ֻ����� �ִ� Element�� ����Ѵ�.
	char anElements = Stack_topElement(_this->_stack);
	AppIO_out_topElement(anElements);
}

void AppController_ignore(AppController* _this) {
	// ������ ���� �̿��� ���� ��ȿó���Ѵ�.
	AppIO_out_ignoredChar();
	AppController_countIgnoredChars(_this);
}