#include "stdafx.h"
#include "linkedList.h"
#include <iostream>


linkedList::linkedList() : head{ new Node(0) }, tail{ head }
{
	//head = NULL;
	//tail = NULL;
}

void linkedList::addNodeToEnd(Node * ptr)
{
	//if list is empty
	if (head == NULL)
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		tail->next = ptr;
		tail = ptr;
	}
}

int linkedList::removeNode(int i)
{
	Node *ptr = head;
	if (ptr == NULL) //empty list
		return -1;

	//if node at head
	if (head->data == i)
	{
		//only 1 node in list
		if (head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else
			head = head->next;
		delete ptr;
		return 0;
	}

	while (ptr != NULL)
	{
		if (ptr->next && (ptr->next)->data == i)
		{
			if (tail == ptr->next)
				tail = ptr;
			Node *tbd = ptr->next;
			ptr->next = (ptr->next)->next;
			delete tbd;
			return 0;
		}
		ptr = ptr->next;
	}
	return -1;
}

void linkedList::showList()
{
	Node *ptr;
	ptr = head;
	std::cout << "***Favorite TV Shows***" << std::endl;
	if (ptr == NULL)
	{
		std::cout << "list is empty" << std::endl;
		return;
	}
	std::cout << "(head is " << head->data << " tail is " << tail->data << ")" << std::endl;
	while (ptr != NULL)
	{
		std::cout << "data is " << ptr->data << std::endl;
		ptr = ptr->next;
	}
}

//Node * linkedList::findItem(int i)
//{
//	Node *ptr = head;
//	
//	while (ptr != NULL)
//	{
//		if (ptr->data == i)
//		{
//			std::cout << "found it!" << std::endl;
//			return ptr;
//		}
//		ptr = ptr->next;
//	}
//
//	std::cout << "Not found" << std::endl;
//	return NULL;
//}

