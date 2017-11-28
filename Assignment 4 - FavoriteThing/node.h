#pragma once
class node
{
	int data;
	node *next;

public:
	node(int x);
	friend class linkedList;
};

