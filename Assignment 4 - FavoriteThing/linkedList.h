#pragma once

class linkedList
{
	struct Node
	{
		int data;
		Node *next;

		Node(int x) : data{ x }, next{ nullptr } {}
	};

	Node *head;
	Node *tail;

public:
	linkedList();
	void addNodeToEnd(Node *ptr);
	int removeNode(int i);
	void showList();
	//Node *findItem(int i);

};

//Questions:
//Would the SLL be its own separate class or integrated into the class that it is a list of?
//what is the definition of node(int x)?





//linked list example

