
using namespace std;
#include <iostream>

class node {
public:
	int row;
	int column;
	int value;
	node* nextNode;

	node(int row, int column, int value) {
		this->row = row;
		this->column = column;
		this->value = value;
	}

	void setNext(node* nextNode) {
		this->nextNode = nextNode;

	}
};

int main()
{
	int array[4][5] = {
		{0,0,3,0,4},
		{0,0,5,7,0},
		{0,0,0,0,0},
		{0,2,6,0,0}

	};
	node* head = NULL;
	node* nextNode;
	node* lastNode = NULL;
	for (int i = 0; i < 4;i++) {
		for (int j = 0; j < 5; j++) {
			if (array[i][j] != 0) {
				nextNode = new node(i, j, array[i][j]);
				if (lastNode) {
					lastNode->nextNode = nextNode;
				}
				else {
					head = nextNode;
				}
				lastNode = nextNode;
			}
		}
	}
	node* currentNode = head;
	while (true) {
		cout << currentNode->value << ", ";
		if (currentNode->nextNode == NULL) break;
		currentNode = currentNode->nextNode;
	}
	return 0;
}


