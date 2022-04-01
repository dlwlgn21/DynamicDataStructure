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
class Stack
{
private:
	NodeList mNodeList;
public:
	Stack(NodeList& list);
	~Stack();
	void Push(const int value);

	void Pop();

	void PrintAllStackValue() const;

};

