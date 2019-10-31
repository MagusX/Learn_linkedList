// linkedListDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"

int main()
{
	Node* pHead = NULL;

	addTail(pHead, 1);

	delAt(pHead, 0);
	printList(pHead);
}