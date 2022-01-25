#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *next;
};

class Queue{
	private:
		Node *begin;
		Node *end;
	public:
		Node *create_node(int value);
		bool Empty();
		void Push(int value);
		int Top();
		void Pop();
};

Node *Queue::create_node(int value){
	Node *p = new Node;
	if(p == NULL) return 0;
	p->data = value;
	p->next = NULL;
	return p;
}

bool Queue::Empty(){
	if(begin == NULL) return true;
	return false;	
}

void Queue::Push(int value){
	Node *p = create_node(value);
	if(begin == NULL){
		begin = p;
		end = p;
	}
	else{
		Node *tmp = end;
		end = p;
		tmp->next = end;
	}
}


int Queue::Top(){
	if(begin != NULL){
		return begin->data;
	}	
}

void Queue::Pop(){
	if(begin != NULL){
		//Node *p = begin;
		begin = begin->next;
		//free(p);
	}
}


int main(){
	Queue Q;
	Q.Push(1);
	Q.Push(2);
	Q.Push(3);
	cout <<	Q.Top();
	Q.Pop();
	cout << "/n" << Q.Top();
	return 0;
}
