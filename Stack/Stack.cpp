#include <assert.h>
#include <iostream>
#include "Stack.h"

void Push(nodeList& list, const int value)
{
	node* newNode{ new node };
	assert(newNode != nullptr);
	newNode->value = value;

	if (list.head == nullptr && list.tail == nullptr)
	{
		list.head = newNode;
		newNode->prev = nullptr;
	}
	else if (list.head != nullptr)
	{
		list.tail->next = newNode;
		newNode->prev = list.tail;
	}
	newNode->next = nullptr;
	list.tail = newNode;

}
void Pop(nodeList& list)
{
	assert(&list != nullptr);
	if (list.tail == nullptr)
	{
		std::cout << "Stack is EMPTY!!" << std::endl;
		std::cout << "Can't POP Anymore" << std::endl;
		std::cout << "You must push value" << std::endl;
		return;
	}

	std::cout << list.tail->value << " Poped!" << std::endl;

	if (list.tail == list.head) {
		delete list.tail;
		list.tail = nullptr;
		list.head = nullptr;
		return;
	}

	node* curNode = list.tail;
	list.tail = list.tail->prev;
	list.tail->next = nullptr;
	delete curNode;
}
void PrintAllStackValue(const nodeList& list)
{
	assert(&list != nullptr);

	node* p{ list.head };
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
void DestoryStack(nodeList& list)
{
	assert(&list != nullptr);
	node* p{ list.head };
	while (p != nullptr)
	{
		node* next = p->next;
		delete p;
		p = next;
	}
	std::cout << "destory Stack Succes." << std::endl;
}
