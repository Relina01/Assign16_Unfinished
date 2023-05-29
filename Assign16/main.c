#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[100];
} element;

typedef struct ListNode
{
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

ListNode* findNode(ListNode* head, int index)
{
	ListNode* pre = head;
	for (int i = 0; i < index - 1; i++) {
		pre = pre->link;
	}
	return pre;
}

ListNode* search_list(ListNode* head, char* value)
{
	ListNode* p = head;

	while (p != NULL)
	{
		if (p->data.name == value) return p;
		p = p->link;
	}
	return NULL;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL\n");
}

int main()
{
	ListNode* head = NULL, * pre = NULL, * deleted = NULL;
	element data;
	int choice;
	int count = 0;
	char name[100];

	strcpy(data.name, "Peach");
	head = insert_first(head, data);
	strcpy(data.name, "Banana");
	head = insert_first(head, data);
	strcpy(data.name, "Raspberry");
	head = insert_first(head, data);
	strcpy(data.name, "Guava");
	head = insert_first(head, data);
	strcpy(data.name, "Plum");
	head = insert_first(head, data);
	strcpy(data.name, "Cherry");
	head = insert_first(head, data);
	strcpy(data.name, "Grape");
	head = insert_first(head, data);
	strcpy(data.name, "Apple");
	head = insert_first(head, data);
	strcpy(data.name, "Orange");
	head = insert_first(head, data);
	strcpy(data.name, "Mango");
	head = insert_first(head, data);
	pre = head;

	while (1)
	{
		printf("<1> Insert new fruit\n");
		printf("<2> Delete the fruit\n");
		printf("<3> Print deleted list\n");
		printf("<4> Exit\n");
		printf("Choose menu : ");
		scanf_s("%d", &choice);

		if (choice == 1)
		{
			printf("Fruit name to insert : ");
			scanf_s("%s", &name);
			strcpy(data.name, name);
			if (name == search_list(head, data.name))
			{
				printf("This fruit is already in\n");
			}
			else
			{
				head = insert_first(head, data);
				printf("Insert %s in list\n", name);
			}
		}

		else if (choice == 2)
		{
			printf("Fruit name to delete : ");
			scanf_s("%s", &name);
			strcpy(data.name, name);
			if (search_list(head, data.name) == NULL)
			{
				printf("There's not fruit name %s in list", data.name);
			}
			else
			{
				head = insert_first(deleted, data);
				delete(head, data.name);
				printf("Delete %s", name);
			}
		}

		else if (choice == 3)
		{
			print_list(deleted);
		}

		else if (choice == 4)
		{
			printf("Exit\n");
			break;
		}

		else
		{
			printf("EXIT");
			break;
		}
		printf("\n");
		printf("Fruit list : \n");
		print_list(head);
		printf("\n");
	}
}