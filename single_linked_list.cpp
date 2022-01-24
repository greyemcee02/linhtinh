#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *next;
};

class List{
	private:
		Node *begin, *last;
	public:
		Node *create_node(int x){
			Node *p = new Node;
			if(p == NULL) return 0;
			else{
				p->data=x;
				p->next = NULL;
				return p;
			}
		}
		void insert_begin(int value);
		void insert_last(int value);
		void insert_pos(int value, int pos);
		void delete_node(int pos);
		Node *search(int value);
		void in(){
			Node *p = begin;
			while(p != NULL){
				cout << p->data << " ";
				p = p->next;
			}
		}
};

void List:: insert_begin(int value){
	Node *tmp, *p;
	tmp = create_node(value);
	if(begin == NULL){
		begin = tmp;
		last = tmp;
	}
	else{
		p = begin;
		begin = tmp;
		begin->next = p;
	}
}

void List::insert_last(int value){
	Node *tmp, *p;
	tmp = create_node(value);
	if(last == NULL){
		begin = tmp;
		last = tmp;
	}
	else{
		p = last;
		last = tmp;
		p->next = last;
	}
}

void List::insert_pos(int value, int pos){
	Node *tmp = new Node;
	Node *p = create_node(value);
	tmp->next = begin;
	for(int i = 1; i < pos; i++){
		tmp = tmp->next;
	}
	Node *tmp1 = tmp->next;
	tmp->next = p;
	p->next = tmp1;
}

void List::delete_node(int pos){
	Node *tmp = new Node;
	tmp->next = begin;
	for(int i = 1; i < pos; i++){
		tmp = tmp->next;
	}
	Node *tmp1 = tmp->next;
	tmp1 = tmp1->next;
	tmp->next = tmp1;
}

Node *List::search(int value){
	Node *tmp = new Node;
	tmp = begin;
	while(tmp!= NULL){
		if(tmp->data == value) return tmp;
		tmp = tmp->next;
	}
	return tmp;
}

int main(){
	List ls;
	ls.insert_begin(1);
	ls.insert_begin(2);
	ls.insert_begin(1);
	ls.insert_begin(1);
	ls.insert_begin(4);
	ls.insert_begin(2);
	ls.insert_pos(3, 6);
	ls.insert_last(3);
	ls.delete_node(3);
	//ls.delete_node(4);
	ls.in();
	return 0;
}
