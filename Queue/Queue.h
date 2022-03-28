#pragma once
struct node
{
	int value;
	node* prev;
	node* next;
};
struct nodeList
{
	node* head{};
	node* tail{};
};

void Enqueue(nodeList& list, int value);

void Dequeue(nodeList& list);

void PrintAllQueueValue(const nodeList& head);

void DestoryQueue(nodeList& head);
