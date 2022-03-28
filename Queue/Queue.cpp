#include <assert.h>
#include <iostream>
#include "Queue.h"

void Enqueue(nodeList& list, const int value)
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
void Dequeue(nodeList& list)
{
	assert(&list != nullptr);
	if (list.tail == nullptr)
	{
		std::cout << "Queue is EMPTY!!" << std::endl;
		std::cout << "Can't Dequeue Anymore" << std::endl;
		std::cout << "You must Enqueue value" << std::endl;
		return;
	}

	std::cout << list.head->value << " Dequeued!!" << std::endl;

	if (list.tail == list.head) {
		delete list.tail;
		list.tail = nullptr;
		list.head = nullptr;
		return;
	}

	node* curNode = list.head;
	list.head = list.head->next;
	list.head->prev = nullptr;
	delete curNode;
}
void PrintAllQueueValue(const nodeList& list)
{
	assert(&list != nullptr);

	node* p{ list.head };
	int count{};
	if (p == nullptr)
	{
		std::cout << "Queue is EMPTY!!" << std::endl;
		return;
	}

	while (p != nullptr)
	{
		std::cout << ++count << "th Queue element [" << p->value << "]" << std::endl;
		p = p->next;
	}

}
void DestoryQueue(nodeList& list)
{
	assert(&list != nullptr);
	node* p{ list.head };
	while (p != nullptr)
	{
		node* next = p->next;
		delete p;
		p = next;
	}
	std::cout << "destory Queue Succes." << std::endl;
}
