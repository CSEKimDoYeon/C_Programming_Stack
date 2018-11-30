#include "Stack.h"

#define DEFAULT_STACK_CAPACITY 4

Stack* Stack_new()
{
	Stack* _this;
	_this = NewObject(Stack); // 스택 자료형 할당.
	_this->_elements = NewVector(Element, DEFAULT_STACK_CAPACITY);
	// 원소의 배열을 Capacity 만큼 할당.
	_this->_capacity = DEFAULT_STACK_CAPACITY;
	// 스택의 최대 크기
	_this->_top = -1;
	return _this;
} // Stack 객체 정의.

void Stack_delete(Stack* _this)
{ // 스택을 삭제해주는 함수.
	free(_this->_elements);
	// elements 배열 먼저 삭제한다.
	free(_this);
}

Boolean Stack_isEmpty(Stack* _this)
{ // 스택이 비어있는지 여부를 확인.
	return ((_this->_top) < 0);
	// top 이 여전히 -1이면 비어있는것이다.
}

Boolean Stack_isFull(Stack* _this)
{ // 스택이 가득 차 있는지 확인.
	return ((_this->_top) == (_this->_capacity - 1));
}

void Stack_push(Stack* _this, Element anElement)
{ // 스택이 꽉차지 않았다면 anElement를 추가해준다.
	if (!Stack_isFull(_this)) {
		_this->_top++;
		_this->_elements[_this->_top] = anElement;
	} // Stack이 empty이면 push를 무시한다.
}

Element Stack_pop(Stack* _this)
{ // 스택이 empty가 아닐 경우에 pop해준다.
	Element poppedElement;
	poppedElement = _this->_elements[_this->_top];
	_this->_top--;
	return poppedElement;
}

int Stack_size(Stack* _this)
{ // 스택의 사이즈를 반환한다.
	return (_this->_top + 1);
}

Element Stack_topElement(Stack* _this)
{ // 스택의 최상위 Element를 반환한다.
	return (_this->_elements[_this->_top]);
}

Element Stack_elementAt(Stack* _this, int anOrder) {
	return _this->_elements[anOrder]; 
	// 스택에서 anOrder 위치에 해당하는 원소를 반환한다.
}