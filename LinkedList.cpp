#include "linkedlist.h"

//implementations for the member functions of LinkedList class
LinkedList::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
}

LinkedList::~LinkedList()
{

}

void LinkedList::add(char ch)
{
	if (this->First() == nullptr)
	{
		this->head = new Node(ch);
		this->tail = head;
	}

	else
	{
		Node* newNode = new Node(ch, this->tail);
		this->tail->next = newNode;
		this->tail = newNode;
		newNode->next = nullptr;
	}
}

bool  LinkedList::find(char ch)
{
	bool found = false;

	if (ch == head->GetCharacter())
	{
		found = true;
	}

	else if (head->next != nullptr)
	{
		Node* currentNode = this->head->next;
		while (currentNode != nullptr)
		{
			if (currentNode->GetCharacter() == ch)
			{
				found = true;
				break;
			}
			else
				currentNode = currentNode->next;
		}
	}

	return found;
}

bool LinkedList::del(char ch)
{
	bool deleted = false;
	Node* placeholder = this->head;
	Node* temp = head;

	if (this->head->GetCharacter() == ch)
	{
		this->head = head->next;
		delete placeholder;
		placeholder = nullptr;

		delete temp;
		temp = nullptr;
	}

	else
	{
		while (placeholder != nullptr)
		{
			if (placeholder->next != nullptr)
			{
				if (placeholder->next->GetCharacter() == ch)
				{
					temp = placeholder->next;
					placeholder->next = placeholder->next->next;

					delete temp;
					temp = nullptr;

					deleted = true;
				}

				else
				{
					temp = placeholder;
					placeholder = placeholder->next;
				}
			}

			//tail must be deleted
			else
			{
				if (placeholder->GetCharacter() == ch)
				{
					this->tail = temp;

					delete placeholder;
					placeholder = nullptr;

					temp->next = nullptr;

					deleted = true;
				}
			}
		}
	}

	return deleted;
}

std::ostream& operator<<(std::ostream& out, const LinkedList& list)
{
	LinkedList::Node* currentNode = new LinkedList::Node(list.head->GetCharacter());

	if (list.head != nullptr)
	{
		out << list.head->GetCharacter() << ", ";
		currentNode = list.head->next;
	}

	while (currentNode != nullptr)
	{
		out << currentNode->GetCharacter();
		if (currentNode->next != nullptr)
		{
			out << ", ";
			currentNode = currentNode->next;

		}
		else
			currentNode = nullptr;
	}

	delete currentNode;
	currentNode = nullptr;
	return out;
}

LinkedList::Node::Node(char ch)
{
	this->character = ch;
	this->next = nullptr;
}

LinkedList::Node::Node(char ch, Node* tail)
{
	this->character = ch;
	this->next = tail;
}

LinkedList::Node::~Node()
{

}

LinkedList::Node* LinkedList::First()
{
	return this->head;
}

char LinkedList::Node::GetCharacter()
{
	return this->character;
}
