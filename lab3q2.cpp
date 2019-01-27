//Program to implement circular link list
//Including library

#include<iostream>

using namespace std;

class node{
	public:
	int data;
	
	node * next;
	
	
	//constructor 
	node(){
		next=NULL;
	}
};
class linkedlist{
	
	public:
	
	node* head;
	node* tail;
	//constructor
	linkedlist(){
		head=NULL;
		tail=NULL;
	}


	void insert(int value){
		node * temp=new node;
		temp->data=value;
		
		if (head==NULL){
			head=temp;
			temp->next=head;
		}
		
		else{
			tail->next=temp;
			temp->next=head;
		}
		tail = temp;
		
		
	}
	void insertAT(int pos,int value){
		
		node* current=head;
	if(pos!=1){
		int i=1;
		while(i<pos-1){
			i++;
			current=current->next;
		}
		//create a node
		node * temp= new node;
		temp->data=value;
		//moving ptrs
		temp->next=current->next;
		current->next=temp;
		
	}
	else{
		//create a node
		node * temp=new node;
		temp->data=value;
		
		temp->next=current;
		//make temp head;
		head=temp;	
	}
		
	}
	
	void delet(){
		
		node * temp = tail;
		
		node * current=head;
		while(current->next !=tail){
		current =current->next;		
		}
		current->next=head;
	
		tail=current;
		delete temp;
	}
	
	void deletAt(int pos){
			
			node *current=head;
				int i=1;
			while(i<pos-1){
				i++;
				current=current->next;
			}
			
			node * temp=current->next;
			
			current->next=temp->next;
			
			delete temp;
			
			
		
	}

	
	void display(){
		node * current=head;
		while(current !=tail){
			cout<< current ->data<<"->";	
			current =current->next;	
		}
		cout<<current->data<<endl;	
	}
	void countItems(){
		node * current=head;
		int i=1;
		while(current !=tail){	
			current =current->next;	
			i++;
		}
		
		cout<<"the number of elements in the linked list is-"<<i<<endl;
	}
};
int main(){
	linkedlist l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.display();
	l1.countItems();
	l1.insert(9);
	l1.insertAT(3,4);
	cout<<endl;
	l1.display();
	l1.delet();
	cout<<endl;
	l1.display();
	cout<<endl;
	l1.deletAt(2);
	l1.display();
	l1.display();
	return 0;
}
