//Queue implementation using linked list
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node {
	int data;
	struct node* link;
} *front = NULL, *rear = NULL;

void enqueue(int);
int dequeue();
int peek();
int isEmpty();
void print();

int main() 
{
	int choice;
	int data;
	while(1)
	{
		cout<<"\n1. Insert "<<"\n2. Delete "<<"\n3. First Element "
		<<"\n4. Display "<<"\n5. Exit"<<endl;
		cout<<"\n";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"Enter the element to be added in queue : "<<endl;
				cin>>data;
				enqueue(data);
				cout<<"Element added sucessfully "<<endl;
			break;
			case 2:
				data = dequeue();
				cout<<"\nDeleted element is : "<<data;
			break;
			case 3: 
			cout<<"\nThe first element of the queue is : "<<peek();
			break;
			case 4: 
			print();
			break;
			case 5:
				exit(1);
			
			default:
				cout<<"Wrong choice, Please try again : "<<endl;
				
		}
	}

}
int isEmpty()
{
	if (front == NULL)
	return 1;
	else
	return 0;
}
void enqueue(int n)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(temp == NULL)
	{
		cout<<"\nNo space ";
		exit(1);
	}
	temp->data = n;
	temp->link = NULL;
	
	if(rear == NULL)
	{
		front = rear = temp;
	}
	else
	{
		rear->link = temp;
		rear = temp;
	}
}

int dequeue()
{
	int data;
	struct node* temp;
	if(isEmpty())
	{
		cout<<"\nQueue Underflow "<<endl;
		exit(1);
	}
	temp = front;
	data = temp->data;
	front = temp->link;
	free(temp);
	temp = NULL;
	return data;
}
int peek()
{
	if(isEmpty())
	{
		cout<<"\nQueue underflow "<<endl;
		exit(1);
	}
	return front->data;
}

void print()
{
	struct node* temp;
	temp = front;
	
	if(isEmpty())
	{
		cout<<"\nQueue underflow "<<endl;
		exit(1);
	}
	cout<<"\nElements in Queue are : "<<endl;
	while(temp != NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->link;
	}
}
