#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(char ch);
	bool find(char ch);
	bool del(char ch);

	friend std::ostream& operator<<(std::ostream& out, const LinkedList& list);

private:
	//fill in your code here
	struct Node
	{
		Node(char ch);
		Node(char ch, Node* tail);
		~Node();

		char GetCharacter();

		char  character;
		Node* next;
	};

	Node* First();

	Node* head;
	Node* tail;
};

#endif // _LINKED_LIST_
