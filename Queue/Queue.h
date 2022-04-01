#pragma once

struct Node
{
	int value;
	Node* prev;
	Node* next;
};
struct NodeList
{
	Node* head{};
	Node* tail{};
};

class Queue
{
private:
	NodeList mNodeList;
public:
	Queue(NodeList& list);
	~Queue();
	void Enqueue(const int value);

	void Dequeue();

	void PrintAllQueueValue() const;

};
