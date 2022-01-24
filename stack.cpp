#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *next;
};

class Stack{
	private:
		Node *tp;
	public:
		Node *create_node(int x);
		void pop();
		void push(int x);
		bool empty();
		int size();
		int top();
};

Node *Stack::create_node(int x){
	Node *p = new Node;
	if(p == NULL) return 0;
	p->data = x;
	p->next = NULL;
	return p;
}

bool Stack::empty(){
	if(tp == NULL) return true;
	return  false;
}

void Stack::push(int x){
	Node *p, *tmp;
	p = create_node(x);
	if(this->empty()){
		tp = p;
	}
	else{
		tmp = tp;
		tp = p;
		tp->next=tmp;	
	}
}

void Stack::pop(){
	if(this->empty() == false){
		tp = tp->next;
	}
}

int Stack::top(){
	return tp->data;
}

int Stack::size(){
	Node *tmp;
	tmp = tp;
	int cnt = 0;
	while(tmp!= NULL){
		cnt++;
		tmp = tmp->next;
	}
	return cnt;
}

int main(){
	Stack stk;
	stk.push(1);
	stk.push(2);
	while(!stk.empty()){
		cout << stk.top() << " ";
		stk.pop();
	}
	cout << stk.size();
	return 0;
}
