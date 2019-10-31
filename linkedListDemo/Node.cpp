#include "Node.h"

Node* create(int x) {
	Node * pNode = new Node;
	pNode->data = x;
	pNode->next = NULL;
	return pNode;
}

void printList(Node* pHead) {
	Node* pNode = pHead;
	while (pNode != NULL) {
		cout << pNode->data << ", ";
		pNode = pNode->next;
	}
	cout << endl;
}

void addHead(Node* &pHead, int x) {
	Node* pNode = pHead;
	if (pHead == NULL) pHead = create(x);
	else {
		pHead = create(x);
		pHead->next = pNode;
	}
}

void addTail(Node* &pHead, int x) {
	Node* pNode = pHead;
	if (pHead == NULL) pHead = create(x);
	else {
		while (pNode->next != NULL) {
			pNode = pNode->next;
		}
		pNode->next = create(x);
	}
}

void addAt(Node*& pHead, int x, int k) {
	Node* pNode = pHead;
	if (k == 0) addHead(pHead, x);
	else {
		int pos = 0;
		while (pNode->next != NULL && pos < k - 1) {
			pNode = pNode->next;
			pos++;
		}
		Node* t = pNode->next;
		pNode->next = create(x);
		pNode->next->next = t;
	}
}

void delHead(Node* &pHead) {
	Node* pNode = pHead;
	if (pHead == NULL) return;
	pHead = pHead->next;
	delete pNode;
	pNode = NULL;
	return;
}

void delTail(Node* &pHead) {
	Node* pNode = pHead;
	if (pHead == NULL) return;
	if (pHead->next == NULL) {
		delete pHead;
		pHead = NULL;
		return;
	}
	while (pNode->next != NULL) {        //      cur->nxt->nxt
		if (pNode->next->next == NULL) { //  a -> b -> c ->null
			delete pNode->next;          //       ^    ^ 
			pNode->next = NULL;          //      cur  del
			return;
		}
		pNode = pNode->next;
	}
}

void delAt(Node*& pHead, int k) {
	Node* pNode = pHead;
	if (pHead == NULL) return;
	if (k == 0) {
		delHead(pHead);
		return;
	}
	int pos = 0;
	while (pNode->next != NULL && pos < k - 1) {
		if (pNode->next->next == NULL) { //  a -> b -> c ->null
			delete pNode->next;          //       ^    ^
			pNode->next = NULL;          //      cur  del 
			return;
		}
		pNode = pNode->next;
		pos++;
	}
	Node* t = pNode->next;
	pNode->next = t->next;
	delete t;
	t = NULL;
}