#include <iostream>
using namespace std;

struct LinkedList
{
	struct Node
	{
		int value;
		Node* next;

		Node()
		{
			value = 0;
			next = nullptr;
		}
	};

	Node* head;
	LinkedList()
	{
		head = nullptr;
	}
	
	void push(int value)
	{
		Node* node = new Node;
		node->value = value;

		if (head == nullptr)
		{
			node->next = nullptr;
			head = node;
		}
		else
		{
			Node* curr = head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			curr->next = node;
			node->next = nullptr;
		}
	}

	Node* deleteValue(Node* head, int theValue)
	{
		Node* curr = head;
		Node* tmp = head;
	   
		while (curr != nullptr)
		{
			if (head->value == theValue)
			{
				head = head->next;
				curr = head;
				tmp = head;
			}

			else if (tmp->next->value == theValue)
			{
				tmp->next = curr->next;
				curr = tmp;
			}

			tmp = curr;
			curr = curr->next;
		}
		return head;
	}

//	Node* deleteValue(Node* head, int theValue)     this works better than mine 
//	{
//		Node* curr = head;
//		Node* tmp = head;
//	   
//		while (curr != nullptr)
//		{
//			if (head->value == theValue)
//			{
//				head = head->next;
//				curr = head;
//				tmp = head;
//			}
//
//			else if (tmp->next->value == theValue)
//			{
//				tmp->next = curr->next;
//				curr = tmp;
//			}
//
//			tmp = curr;
//			curr = curr->next;
//		}
//		return head;
//	}

	void print()
	{
		Node* curr = head;
		if (head == nullptr)
		{
			cout << "Empty list" << endl;
			return;
		}
		while (curr != nullptr)
		{
			cout << curr->value << endl;
			curr = curr->next;
		}
	}
};

int main()
{
	LinkedList list;
	list.push(1);
	list.push(2);
	list.push(3);
	list.push(4);
	list.print();
	list.deleteValue(list.head, 1);
	list.print();
	return 0;
}
