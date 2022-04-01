#include <assert.h>
#include <iostream>
#include "Queue.h"

Queue::Queue(NodeList& list) : mNodeList{ list }
{
}

void Queue::Enqueue(const int value)
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
void Queue::Dequeue()
{
	if (mNodeList.tail == nullptr)
	{
		std::cout << "Can't Dequeue Anymore" << std::endl;
		std::cout << "You must Enqueue value" << std::endl;
		return;
	}

	std::cout << mNodeList.head->value << " Dequeued!!" << std::endl;

	if (mNodeList.tail == mNodeList.head) {
		delete mNodeList.tail;
		mNodeList.tail = nullptr;
		mNodeList.head = nullptr;
		return;
	}

	Node* curNode = mNodeList.head;
	mNodeList.head = mNodeList.head->next;
	mNodeList.head->prev = nullptr;
	delete curNode;
}
void Queue::PrintAllQueueValue() const
{
	Node* p{ mNodeList.head };
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
Queue::~Queue()
{
	Node* p{ mNodeList.head };
	while (p != nullptr)
	{
		Node* next = p->next;
		delete p;
		p = next;
	}
	std::cout << "destory Queue Succes." << std::endl;
}
