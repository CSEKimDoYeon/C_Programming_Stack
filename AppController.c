#include "AppController.h"
#include "AppIO.h"

void AppController_run(AppController* _this) { // 프로그램 실행 함수.
	AppIO_out_startProgram();

	AppController_initCountingChars(_this);
	AppIO_out_newLine();
	char c = AppIO_in_charDirectlyFromKeyboard();
	// 키보드로 입력받은 문자를 직접 삽입.

	while (c != Esc) { // Esc가 입력 될 때 까지 진행.
		AppController_countInputChars(_this);
		if (isAlpha(c)) {
			AppController_push(_this, c);
			// 알파벳일경우 스택에 push
		}
		else if (isDigit(c)) {
			int digitValue = c - '0';
			AppController_pops(_this, digitValue);
			// 숫자일경우 숫자만큼 pop
		}
		else if (c == '-') {
			AppController_pop1(_this);
			// - 일 경우 하나를 pop
		}
		else if (c == '#') {
			AppController_showSize(_this);
			// # 일 경우 스택의 사이즈 출력.
		}
		else if (c == '/') {
			AppController_showAllFromBottom(_this);
			// '/' 일 경우 스택의 bottom부터 top까지 출력.
		}
		else if (c == '\\') {
			AppController_showAllFromTop(_this);
			// \ 일 경우 스택의 top부터 bottom까지 출력.
		}
		else if (c == '^') {
			AppController_showTopElement(_this);
			// ^ 일 경우 현 스택의 top Element 출력.
		}
		else {
			AppController_ignore(_this);
			// 이외의 문자는 무시 처리.
		}
		AppIO_out_newLine();
		c = AppIO_in_charDirectlyFromKeyboard();
	}
	AppController_endInput(_this);
	// 프로그램이 종료되면 모든 원소 삭제.
	AppController_showStatistics(_this);
	AppIO_out_endProgram();
}


AppController* AppController_new() {
	// AppController 객체 생성.
	AppController* _this;
	_this = NewObject(AppController);
	_this->_stack = Stack_new();
	return _this;
}

void AppController_delete(AppController* _this) {
	// AppController 객체 삭제.
	Stack_delete(_this->_stack);
	free(_this);
}

void AppController_push(AppController* _this, char aChar) {
	// 스택에 aChar를 push하는 함수.
	if (Stack_isFull(_this->_stack)) {
		AppIO_out_stackIsFullAgainstPush(aChar);
	} // 스택이 꽉 찼을 경우에는 넣지 않는다.
	else {
		Stack_push(_this->_stack, aChar);
		AppIO_out_pushedElement(aChar);
		AppController_countPushedChars(_this);
	}
}

void AppController_pop1(AppController* _this) {
	// 스택에서 최상위의 한개의 원소 pop
	if (Stack_isEmpty(_this->_stack)) {
		AppIO_out_stackIsEmptyAgainstPop1();
	} // 스택이 비어있으면 pop하지 않는다.
	else {
		char poppedChar = Stack_pop(_this->_stack);
		AppIO_out_poppedElementByPop1(poppedChar);
	}
}

void AppController_pops(AppController* _this, int numberOfChars) {
	// numberOfChar 입력 수 만큼 스택에서 pop 실행.
	if (numberOfChars > Stack_size(_this->_stack)) {
		AppIO_out_beginPops(numberOfChars);
		for (int i = 0; (i < numberOfChars) && (!Stack_isEmpty(_this->_stack)); i++)
		{
			char poppedChar = Stack_pop(_this->_stack);
			AppIO_out_poppedElementByPop1(poppedChar);
		}
		AppIO_out_stackIsEmptyAgainstPops();
		// 입력 수가 사이즈보다 클 경우 모두 삭제하고 스택이 비었다는 메시지 출력.
	}
	else {
		AppIO_out_beginPops(numberOfChars);
		for (int i = 0; (i < numberOfChars) && (!Stack_isEmpty(_this->_stack)); i++)
		{
			char poppedChar = Stack_pop(_this->_stack);
			AppIO_out_poppedElementByPop1(poppedChar);
		}
		AppIO_out_endPops();
		// 입력 수가 사이즈보다 작을 경우 사이즈만큼 삭제.
	}
}

void AppController_showAllFromBottom(AppController* _this) {
	// 스택의 Bottom부터 Top까지 순서대로 원소를 출력.
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
	// 스택의 Top부터 Bottom까지 순서대로 원소를 출력.
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
	// 입력수, 무시한 수, 푸쉬한 수를 실행 될 때마다 카운팅.
	_this->_inputChars = 0;
	_this->_ignoredChars = 0;
	_this->_pushedChars = 0;
}

void AppController_countInputChars(AppController* _this)
{
	// 입력한 문자의 수를 추가해준다.
	_this->_inputChars++;
}

void AppController_countIgnoredChars(AppController* _this)
{
	// 무시한 문자의 수를 추가해준다.
	_this->_ignoredChars++;
}

void AppController_countPushedChars(AppController* _this)
{
	// 푸쉬한 문자의 수를 추가해준다.
	_this->_pushedChars++;
}

int AppController_numberOfInputChars(AppController* _this)
{
	//입력한 문자의 수를 추가해준다.
	return (_this->_inputChars);
}

int AppController_numberOfNormallyProcessedChars(AppController* _this)
{
	// 순수 입력된 문자의 개수를 반환한다.
	return (_this->_inputChars - _this->_ignoredChars);
}

int AppController_numberOfIgnoredChars(AppController* _this)
{
	// 무시한 문자의 수를 반환한다.
	return (_this->_ignoredChars);
}

int AppController_numberOfPushedChars(AppController* _this)
{
	// 푸쉬한 문자의 수를 반환한다.
	return (_this->_pushedChars);
}

void AppController_showStatistics(AppController* _this)
{
	// 지금까지의 통계를 바탕으로 통계 자료들을 모두 출력한다.
	AppIO_out_newLine();
	AppIO_out_numberOfInputChars(AppController_numberOfInputChars(_this));
	AppIO_out_numberOfNormallyProcessedChars(AppController_numberOfNormallyProcessedChars(_this));
	AppIO_out_numberOfIgnoredChars(AppController_numberOfIgnoredChars(_this));
	AppIO_out_numberOfPushedChars(AppController_numberOfPushedChars(_this));
}

void AppController_endInput(AppController* _this) {
	// Esc가 입력되어 종료되면 모든 스택의 원소들을 꺼낸다.
	char Elements;
	AppIO_out_endInput();
	for (int i = Stack_size(_this->_stack) - 1; i >= 0; i--) {
		Elements = Stack_elementAt(_this->_stack, i);
		AppIO_out_poppedElementByEndInput(Elements);
	}
}

void AppController_showSize(AppController* _this) {
	// 현 스택의 size를 출력한다.
	int size = Stack_size(_this->_stack);
	AppIO_out_numberOfElements(size);
}

void AppController_showTopElement(AppController* _this) {
	// 현 스택의 최상위에 있는 Element를 출력한다.
	char anElements = Stack_topElement(_this->_stack);
	AppIO_out_topElement(anElements);
}

void AppController_ignore(AppController* _this) {
	// 지정된 문자 이외의 것을 무효처리한다.
	AppIO_out_ignoredChar();
	AppController_countIgnoredChars(_this);
}