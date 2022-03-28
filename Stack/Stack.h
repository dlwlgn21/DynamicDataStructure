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

void Push(nodeList& list, int value);

void Pop(nodeList& list);

void PrintAllStackValue(const nodeList& head);

void DestoryStack(nodeList& head);
