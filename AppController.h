#pragma once
#include "Stack.h"

#define Esc 27
#define isDigit(CHAR) (('0'<= CHAR) && (CHAR <='9'))
#define isAlpha(CHAR) ((('a' <= CHAR) && (CHAR <= 'z')) || (('A' <= CHAR) && (CHAR <= 'Z')))

typedef struct _AppController AppController;

struct _AppController {
	Stack* _stack;
	int _inputChars; // 입력된 문자의 개수
	int _ignoredChars; // 무시된 문자의 개수
	int _pushedChars; // 스택에 넣은 문자의 개수
};

void AppController_run(AppController* _this);
AppController* AppController_new();
void AppController_delete(AppController* _this);
void AppController_push(AppController* _this, char aChar);
void AppController_pop1(AppController* _this);
void AppController_pops(AppController* _this, int numberOfChars);
void AppController_showAllFromBottom(AppController* _this);
void AppController_showAllFromTop(AppController* _this);
void AppController_initCountingChars(AppController* _this);
void AppController_countInputChars(AppController* _this);
void AppController_countIgnoredChars(AppController* _this);
void AppController_countPushedChars(AppController* _this);
int AppController_numberOfInputChars(AppController* _this);
int AppController_numberOfNormallyProcessedChars(AppController* _this);
int AppController_numberOfIgnoredChars(AppController* _this);
int AppController_numberOfPushedChars(AppController* _this);
void AppController_showStatistics(AppController* _this);
void AppController_endInput(AppController* _this);
void AppController_showSize(AppController* _this);
void AppController_showTopElement(AppController* _this);
void AppController_ignore(AppController* _this);





