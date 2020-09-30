// A complete working C++ program to demonstrate all insertion methods on Linked List 

#include <bits/stdc++.h> 
using namespace std; 

// A linked list node 
class Node 
{ 
	public: 
	int data; 
	Node *next; 
}; 

/* Given a reference (pointer to pointer) 
to the head of a list and an int, inserts 
a new node on the front of the list. */
void push(Node** head_ref, int new_data) 
{ 
	/* 1. allocate node */
	Node* new_node = new Node(); 

	/* 2. put in the data */
	new_node->data = new_data; 

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref); 

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node; 
} 


/* Given a node prev_node, insert a new node after the given 
prev_node */
void insertAfter(Node* prev_node, int new_data) 
{ 
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL) 
	{ 
		cout<<"the given previous node cannot be NULL"; 
		return; 
	} 

	/* 2. allocate new node */
	Node* new_node = new Node(); 

	/* 3. put in the data */
	new_node->data = new_data; 

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next; 

	/* 5. move the next of prev_node as new_node */
	prev_node->next = new_node; 
} 

/* Given a reference (pointer to pointer) to the head 
of a list and an int, appends a new node at the end */
void append(Node** head_ref, int new_data) 
{ 
	/* 1. allocate node */
	Node* new_node = new Node(); 

	Node *last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->data = new_data; 

	/* 3. This new node is going to be 
	the last node, so make next of 
	it as NULL*/
	new_node->next = NULL; 

	/* 4. If the Linked List is empty, 
	then make the new node as head */
	if (*head_ref == NULL) 
	{ 
		*head_ref = new_node; 
		return; 
	} 

	/* 5. Else traverse till the last node */
	while (last->next != NULL) 
		last = last->next; 

	/* 6. Change the next of last node */
	last->next = new_node; 
	return; 
} 

// This function prints contents of 
// linked list starting from head 
void printList(Node *node) 
{ 
	while (node != NULL) 
	{ 
		cout<<" "<<node->data; 
		node = node->next; 
	} 
} 

/* Driver code*/
int main() 
{ 
	/* Start with the empty list */
	Node* head = NULL; 
	
	// Insert 6. So linked list becomes 6->NULL 
	append(&head, 6); 
	
	// Insert 7 at the beginning. 
	// So linked list becomes 7->6->NULL 
	push(&head, 7); 
	
	// Insert 1 at the beginning. 
	// So linked list becomes 1->7->6->NULL 
	push(&head, 1); 
	
	// Insert 4 at the end. So 
	// linked list becomes 1->7->6->4->NULL 
	append(&head, 4); 
	
	// Insert 8, after 7. So linked 
	// list becomes 1->7->8->6->4->NULL 
	insertAfter(head->next, 8); 
	
	cout<<"Created Linked list is: "; 
	printList(head); 
	
	return 0; 
} 
Time Complexity:-
Time complexity to insert a node  at front:O(1)
Time Complexity to insert a new node after the given prev_node: O(1)
Time Complexity to insert a new node at the end : O(N)

/* Deleting node from the list*/
struct node *del(struct node *head,int data)
{
	struct node *temp,*p;
	if(head==NULL)
	{
		printf("List is empty\n");
		return head;
	}
	/*Deletion of first node*/
	if(head->info==data)
	{
		temp=head;
		head=head->link;  
		free(temp);
		return head;
	}
	/*Deletion in between or at the end*/
	p=head;
	while(p->link!=NULL)
	{
		if(p->link->info==data)   
		{
			temp=p->link;
			p->link=temp->link;
			free(temp);
			return head;
		}
		p=p->link;
	}
	printf("Element %d not found\n",data);
	return head;

Time Complexity for deleting at the front: O(1)
Time Complexity for deletion at the end: O(N)

/*Traverse the list or display every element in the list */
void display(struct node *head)
{
	struct node *p;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=head;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n\n");
}/*End of display() */

Time Complexity for traversal: O(N)