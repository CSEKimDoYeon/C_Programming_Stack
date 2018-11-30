#include "Stack.h"

#define DEFAULT_STACK_CAPACITY 4

Stack* Stack_new()
{
	Stack* _this;
	_this = NewObject(Stack); // ���� �ڷ��� �Ҵ�.
	_this->_elements = NewVector(Element, DEFAULT_STACK_CAPACITY);
	// ������ �迭�� Capacity ��ŭ �Ҵ�.
	_this->_capacity = DEFAULT_STACK_CAPACITY;
	// ������ �ִ� ũ��
	_this->_top = -1;
	return _this;
} // Stack ��ü ����.

void Stack_delete(Stack* _this)
{ // ������ �������ִ� �Լ�.
	free(_this->_elements);
	// elements �迭 ���� �����Ѵ�.
	free(_this);
}

Boolean Stack_isEmpty(Stack* _this)
{ // ������ ����ִ��� ���θ� Ȯ��.
	return ((_this->_top) < 0);
	// top �� ������ -1�̸� ����ִ°��̴�.
}

Boolean Stack_isFull(Stack* _this)
{ // ������ ���� �� �ִ��� Ȯ��.
	return ((_this->_top) == (_this->_capacity - 1));
}

void Stack_push(Stack* _this, Element anElement)
{ // ������ ������ �ʾҴٸ� anElement�� �߰����ش�.
	if (!Stack_isFull(_this)) {
		_this->_top++;
		_this->_elements[_this->_top] = anElement;
	} // Stack�� empty�̸� push�� �����Ѵ�.
}

Element Stack_pop(Stack* _this)
{ // ������ empty�� �ƴ� ��쿡 pop���ش�.
	Element poppedElement;
	poppedElement = _this->_elements[_this->_top];
	_this->_top--;
	return poppedElement;
}

int Stack_size(Stack* _this)
{ // ������ ����� ��ȯ�Ѵ�.
	return (_this->_top + 1);
}

Element Stack_topElement(Stack* _this)
{ // ������ �ֻ��� Element�� ��ȯ�Ѵ�.
	return (_this->_elements[_this->_top]);
}

Element Stack_elementAt(Stack* _this, int anOrder) {
	return _this->_elements[anOrder]; 
	// ���ÿ��� anOrder ��ġ�� �ش��ϴ� ���Ҹ� ��ȯ�Ѵ�.
}