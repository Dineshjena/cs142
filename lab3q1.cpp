//Program implementing doubly link list
//including library
#include<iostream>
using namespace std;

class node
	{
	public:
	int x;
	char y;
	node *next,*prev;
	//constructor
	node()
		{
		next=NULL;
		prev=NULL;
		}
	};

class func
	{
	public:
	node *head,*tail;
	func()
		{
		head=NULL;
		tail=NULL;
		}
	};	

void insert(func &l)
	{
	if(l.head==NULL)
		{
		l.head=new node;
		l.tail=l.head;
		cout<<"Enter an integer - ";
		cin>>l.head->x;
		cout<<"Enter a character - ";
		cin>>l.head->y;
		}
	else
		{
		node *temp=l.tail;
		l.tail->next=new node;
		l.tail=l.tail->next;
		cout<<"Enter an integer - ";
		cin>>l.tail->x;
		cout<<"Enter a character - ";
		cin>>l.tail->y;
		}
	}
//declare an int function countItems
int countItems(func l)
	{
	//declare x pointer of class node titled current and initialise it with the value of the node pointer head 
	node *current=l.head;
	//declare an int type counter count and initialise it with the value of 0
	int count=0;
	//while current is not NULL, run x loop and in each iteration, increment count by 1 and assign the value of the address to the next node to the current node to current
	while(current!=l.tail->next)
		{
		count++;
		current=current->next;
		}
	//return the value of count
	return count;
	}
//declare a void function insertAt 
void insertAt(func &l,int pos)
	{
	node *current=l.head;
	int i=1;
	if(pos<=countItems(l))
		{
		while(i<pos-1)
			{
			current=current->next;
			i++;
			}
		node *temp=current;
		current=new node;
		cout<<"Enter an integer - ";
		cin>>current->x;
		cout<<"Enter a character - ";
		cin>>current->y;
		current->next=temp->next;
		temp->next=current;
		}
	else
	cout<<" Invalid input ";
	}
//declare a void function deleteAt 
void deleteAt(func &l,int pos)
	{
	node *current=l.head;
	int i=1;
	if(l.head==NULL)
		{
		cout<<"Underflow";
		}
	else if(pos<=countItems(l))
		{
		while(i<pos)
			{
			current=current->next;
			i++;
			}
		current=current->prev;
		}
	else
	cout<<"LOL - Invalid input ";
	}

void deletenodel(func &l)
	{
	if(l.head==NULL)
		{
		cout<<"Underflow";
		}
	else if(l.head!=NULL)
		{
		if(l.head->next==NULL)
			{
			delete l.head;
			l.head=NULL;
			l.tail=NULL;

			}
		else
			{	
			node *current=l.head;
			l.head=l.head->next;
			delete current;	
			}
		}
	}
//write a void function delet() 
void delet(func &l)
	{
	if(l.head==NULL)
		{
		cout<<"Underflow";
		}
	else if(l.head!=NULL)
		{
		node *current=l.head; 
		if(l.head->next==NULL)
			{
			delete l.head;
			l.head=NULL;
			l.tail=NULL;
			}
		else
			{	
			node *temp=l.tail;
			l.tail=l.tail->prev;
			l.tail->next=NULL;
			delete temp;
			}
		}
	}
//write a function display 	
void display(func l)	
{
	//
	node *current=l.head;
	int i=1;
	if(l.head==NULL)
	{
		cout<<"Underflow";
	}
	else
	{
		while(current!=l.tail->next)
		{
			cout<<"Node no. "<<i++<<endl;
			cout<<"Integer value - "<<current->x<<endl<<"Character value - "<<current->y<<endl;
			current=current->next;
		}
	}
}
void revdisplay(func l,node*p,int pos=1)
{
	if(l.head==NULL)
	cout<<"Underflow";
	else
	{
		int i=1;
		node *current=l.tail;
		do
		{
			cout<<"Node no. "<<i++<<endl;
			cout<<"Integer value - "<<current->x<<endl<<"Character value - "<<current->y<<endl;
			current=current->prev;
		}while(current!=l.head->prev);
	}		
}

int main()
{
	int ch;
	func l;
	int pos;
	do
	{
		cout<<"\n\tLinked List Gen "<<endl<<"1. Insert a node"<<endl<<"2. Delete the first node"<<endl<<"3. Delete the last node"<<endl<<"4. Display the stored values"<<endl<<"5. Insert Node at a particular position"<<endl<<"6. Delete Node from a particular position"<<endl<<"7. Count the number of nodes present"<<endl<<"0. Exit";
		cout<<endl<<"Make your choice - ";
		cin>>ch;
		switch(ch)
		{
			case 1:insert(l);
			       break;
			case 2:deletenodel(l);
			       break;
			case 3:delet(l);
			       break;
			case 4:display(l);
			       break;
			case 5:cout<<"Enter the position at which node is to be inserted - ";
			       cin>>pos;
			       insertAt(l,pos);
			       break;
			case 6:cout<<"Enter the position from which node is to be deleted - ";
			       cin>>pos;
			       deleteAt(l,pos);
			       break;
			case 7:cout<<"No. of nodes- "<<countItems(l);
			       break;
			case 8:if(ch==8)
			       {
			       		node *p=l.head;
			       		while(p->next!=NULL)
			       		{
			       			p=p->next;
			       		}
			       		revdisplay(l,p);
			       }
			       break;
			case 0:break;
			default:cout<<"invalid input";
				break;
		}
	}while(ch!=0);
	return 0;
}
			
