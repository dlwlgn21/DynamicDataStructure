#include <assert.h>
#include <iostream>
#include "Stack.h"
Stack::Stack(NodeList& list) : mNodeList{ list }
{

}
Stack::~Stack()
{
	Node* p{ mNodeList.head };
	while (p != nullptr)
	{
		Node* next = p->next;
		delete p;
		p = next;
	}
	std::cout << "destory Stack Succes." << std::endl;
}

void Stack::Push(const int value)
{
	Node* newNode{ new Node };
	assert(newNode != nullptr);
	newNode->value = value;

	if (mNodeList.head == nullptr && mNodeList.tail == nullptr)
	{
		mNodeList.head = newNode;
		newNode->prev = nullptr;
	}
	else if (mNodeList.head != nullptr)
	{
		mNodeList.tail->next = newNode;
		newNode->prev = mNodeList.tail;
	}
	newNode->next = nullptr;
	mNodeList.tail = newNode;

}
void Stack::Pop()
{
	if (mNodeList.tail == nullptr)
	{
		std::cout << "Can't POP Anymore" << std::endl;
		std::cout << "You must push value" << std::endl;
		return;
	}

	std::cout << mNodeList.tail->value << " Poped!" << std::endl;

	if (mNodeList.tail == mNodeList.head) {
		delete mNodeList.tail;
		mNodeList.tail = nullptr;
		mNodeList.head = nullptr;
		return;
	}

	Node* curNode = mNodeList.tail;
	mNodeList.tail = mNodeList.tail->prev;
	mNodeList.tail->next = nullptr;
	delete curNode;
}
void Stack::PrintAllStackValue() const
{
	Node* p{ mNodeList.head };
	int count{};
	if (p == nullptr)
	{
		std::cout << "Stack is EMPTY!!" << std::endl;
		return;
	}

	while (p != nullptr)
	{
		std::cout << ++count << "th Stack element [" << p->value << "]" << std::endl;
		p = p->next;
	}

}

