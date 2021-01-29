#ifndef NODELIST_H
#define NODELIST_H

#include"Node.h"

class NodeList
{
public:
	NodeList() :headptr(NULL), tail(NULL) {
		Node* head = new Node();
		headptr = head;
		tail = head;
	};
	void pushnode(int);
	void insertnode(int, int);
	void deletenode(int);
	void destroylist();
	int getlength() { return length; };
private:
	Node* headptr;
	Node* tail;
	int length;
};

void NodeList::pushnode(int a) {
	Node* latestnode = new Node();
	latestnode->inputvalue(a);
	tail->nextptr = latestnode->nextptr;
	tail = latestnode;
	length++;
}
void NodeList::insertnode(int index, int a) {
	Node* temp = headptr;
	if (index > length)
		pushnode(a);
	else {
		for (int i = 1; i < index; ++i)
			temp = headptr->nextptr;
		Node* latestnode = new Node();
		latestnode->inputvalue(a);
		latestnode->nextptr = temp->nextptr;
		temp->nextptr = latestnode;
	}
	length++;
}
void NodeList::deletenode(int index) {
	if (index > length)
		return;
	Node* temp = headptr;
	Node* x;
	for (int i = 1; i < index; ++i)
		temp = headptr->nextptr;
	x = temp->nextptr;
	temp->nextptr = x->nextptr;
	delete x;
	length--;
}
void NodeList::destroylist() {
	Node* temp = headptr;
	Node* x;
	for (int i = 1; i < length; ++i) {
		x = temp->nextptr;
		delete temp;
		temp = x;
	}
}

#endif