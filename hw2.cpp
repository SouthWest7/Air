#include<iostream>

using namespace std;

class Node
{
public:
	friend class NodeList;
	Node() :nextptr(nullptr), value(0) {}
	void setvalue(int a) { value = a; }
private:
	Node* nextptr;
	int value;
};
class NodeList
{
public:
	NodeList() :headptr(NULL), tail(NULL),length(0) {
		Node* head = new Node();
		headptr = head;
		tail = head;
	};
	void pushnode(int a) {
		Node* latestnode = new Node();
		latestnode->setvalue(a);
		tail->nextptr = latestnode;
		tail = latestnode;
		length++;
	}
	void insertnode(int index, int a) {
		Node* temp = headptr;
		if (index > length)
			pushnode(a);
		else {
			for (int i = 1; i < index; ++i)
				temp = temp->nextptr;
			Node* latestnode = new Node();
			latestnode->setvalue(a);
			latestnode->nextptr = temp->nextptr;
			temp->nextptr = latestnode;
		}
		length++;
	}
	void deletenode(int index) {
		if (index > length)
			return;
		Node* temp = headptr;
		Node* x = NULL;
		for (int i = 1; i < index; ++i) {
			x = temp->nextptr;
			temp = x;
		}
		x = temp->nextptr;
		temp->nextptr = x->nextptr;
		delete x;
		length--;
	}
	void destroylist() {
		Node* temp = headptr;
		Node* x = NULL;
		for (int i = 0; i <= length; ++i) {
			x = temp->nextptr;
			delete temp;
			temp = x;
		}
	}
	void transposelist() {
		Node* temp = headptr;
		Node* x = NULL;
		for (int i = 0; i < length / 2; i++) {
			int a;
			a = temp->nextptr->value;
			x = temp;
			for (int j = i; j < (length - i); j++)
				x = x->nextptr;
			temp->nextptr->value = x->value;
			x->value = a;
			temp = temp->nextptr;
		 }
	}
	void setlength(int a) {
		length = a;
	}
	int getlength() { return length; }
	void display() {
		Node* temp = this->headptr->nextptr;
		for (int i = 0; i < length; ++i) {
			cout << temp->value << " ";
			temp = temp->nextptr;
		}
		cout << endl;
	}
	~NodeList() {
		destroylist();
	}
private:
	Node* headptr;
	Node* tail;
	int length;
};

int main()
{
	NodeList list;
	int l, index;

	cout << "数组长度：";
	cin >> l;
	srand((unsigned)time(NULL));
	for (int i = 0; i < l; ++i) {
		if (i < (l / 2))
			list.pushnode(rand() % 101);
		else
			list.pushnode(0);
	}
	list.display();

	cout << "插入位置：";
	cin >> index;
	list.insertnode(index, 0);
	list.display();

	cout << "删除位置：";
	cin >> index;
	list.deletenode(index);
	list.display();

	cout << "转置数组：\n";
	list.transposelist();
	list.display();

	return 0;
}