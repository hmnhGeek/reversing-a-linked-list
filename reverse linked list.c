#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next, *prev;
}list;

list *head = NULL;

/* To understand how insert() works, see linked_list repository in repositories. */

void insert(int item)
{
	if(head == NULL)
	{
		head = (list *)malloc(sizeof(list));
		head -> next = NULL;
		head -> data = item;
		head -> prev = NULL;
	}
	else
	{
		list *var = (list *)malloc(sizeof(list));
		var -> data = item;
		var -> next = head;
		head -> prev = var;
		var -> prev = NULL;
		head = var;
	}
}

void display()
{
	if(head == NULL)
	{
		printf("The list is empty.\n");
	}
	else
	{
		list *temp = head;
		while(temp != NULL)
		{
			printf("%d\n", temp -> data);
			temp = temp -> next;
		}
	}
}

void reverse()
{	/* First check if head is null and if it is then print that the list is empty. */
	if(head == NULL)
	{
		printf("The list is empty.\n");
	}
	else
	{	// Else initialise temp to traverse the list. //
		list *temp = head;
		list *prev;
		list *last;
		while(temp != NULL)
		{	/* to reverse the list, you need to exchange the previous and the next
				field of every node and at last make the last value of temp before it 
				becomes null to head. */
			prev = temp -> prev;
			temp -> prev = temp -> next;
			temp -> next = prev;
			last = temp;
			temp = temp -> prev;
		}
		head = last;
	}
}

void main()
{
	int ch = 1;
	while(ch == 1)
	{
		printf("1. insert\n");
		printf("2. reverse\n");
		printf("3. display\n");
		printf("4. exit\n");

		int choice;
		scanf("%d", &choice);

		if(choice == 1)
		{
			int item;
			printf("Item?? \n");
			scanf("%d", &item);
			insert(item);
		}

		else if(choice == 2)
		{
			reverse();
		}

		else if(choice == 3)
		{
			display();
		}
		else
		{
			ch = 0;
		}
	}
}