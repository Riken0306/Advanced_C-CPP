#include <stdio.h>
#include <stdlib.h>

//Structure of a node
struct Node
{
    int data;
    struct Node* next;
};

int getLength(struct Node*);
void printList(struct Node*);
struct Node *insertAtBegining(struct Node*, int);
struct Node *insertAtEnd(struct Node*, int);  
struct Node *insertAtPosition(struct Node*, int, int);

//Function to get Length of LinkedList
int getLength(struct Node *head)
{
    int length = 0; // Initialize count
    struct Node *current = head; // Initialize current
    while (current->next != NULL) {
        length++;
        current = current->next;
    }
    return length+1;
}

//Function to print LinkedList
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

//Function to insert a node at the begin of the linked list.
struct Node *insertAtBegining(struct Node *head, int x) {

	//code here
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode->data = x;
	newNode->next = NULL;
	
	if(head == NULL)
	    return newNode;
	
	newNode->next = head;
	
	return newNode;
}


//Function to insert a node at the end of the linked list.
struct Node *insertAtEnd(struct Node *head, int x)  {

	//code here
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode->data = x;
	newNode->next = NULL;
	
	if(head == NULL){
	    return newNode;
	}
	
	else{
	    struct Node *last = head;
	   	while(last->next != NULL)
	        last = last->next; 
	    
	    last->next = newNode;
	}
	 return head;
}

//Function to insert a node at given index
struct Node *insertAtPosition(struct Node *head, int pos, int x){
    struct Node *current = head;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    int length = getLength(head);
    if (pos < 1 || pos > length+1) {
        printf("Invalid Index");
        return head;
    }
    else {
        while(pos--){
            if(pos==0){
                newNode->data = x;
	            newNode->next = current->next;
                current->next = newNode;
            }
            else
               current = current->next; 
        }
    }
    return head;
}

//Main Function 
//0 - InsertAtBeginning
//-1 - InsertAtEnd
//position - InsertAtPosition
int main(){
    
    int n;
    int data, index;
    scanf("%d", &n);
    struct Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &data);
        scanf("%d", &index);
        if (index == -1)
            head = insertAtEnd(head, data);
        else if(index == 0)
            head = insertAtBegining(head, data);
        else 
            head = insertAtPosition(head, index, data);
    }
    printList(head);
	return 0;
}