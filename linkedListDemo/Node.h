#pragma once
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* create(int x);

void printList(Node* pHead);

void addHead(Node* &pHead, int x);

void addTail(Node* &pHead, int x);

void addAt(Node* &pHead, int x, int k);

void delHead(Node*& pHead);

void delTail(Node*& pHead);

void delAt(Node*& pHead, int k);
