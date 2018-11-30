
char AppIO_in_charDirectlyFromKeyboard();
char getCharDirectlyFromKeyboard(void);

void AppIO_out_stackIsFullAgainstPush(char anElementForPush);
void AppIO_out_pushedElement(char anElement);
void AppIO_out_stackIsEmptyAgainstPop1();
void AppIO_out_poppedElementByPop1(char anElement);
void AppIO_out_beginPops(int numberOfElements);
void AppIO_out_endPops();
void AppIO_out_stackIsEmptyAgainstPops();
void AppIO_out_topElement(char anElement);
void AppIO_out_noTopElement();
void AppIO_out_bottomOfStack();
void AppIO_out_element(char anElement);
void AppIO_out_topOfStack();
void AppIO_out_newLine();
void AppIO_out_stackSize(int stackSize);
void AppIO_out_ignoredChar();
void AppIO_out_endInput();
void AppIO_out_poppedElementByEndInput(char anElement);
void AppIO_out_numberOfInputChars(int numberOfChars);
void AppIO_out_numberOfNormallyProcessedChars(int numberOfChars);
void AppIO_out_numberOfIgnoredChars(int numberOfChars);
void AppIO_out_numberOfPushedChars(int numberOfChars);
void AppIO_out_startProgram();
void AppIO_out_endProgram();
void AppIO_out_numberOfElements(int numberOfChars);