/*Anjali Rengade BT19CSE095*/
/*Program to find Intersection of two linked lists*/
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* sortedIntersect(struct node* a,struct node* b)
{
	/* base case */
	if (a == NULL || b == NULL)
		return NULL;

	if (a->data < b->data)
		return sortedIntersect(a->next, b);

	if (a->data > b->data)
		return sortedIntersect(a, b->next);

	struct node* temp= (struct node*)malloc(sizeof(struct node));
	temp->data = a->data;
	temp->next = sortedIntersect(a->next, b->next);
	return temp;
}


void push(struct node** head_ref, int new_data)
{
	struct node* new_node= (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}


void printList(struct node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{

	struct node* a = NULL;
	struct node* b = NULL;
	struct node* intersect = NULL;

    int n1,i,n2,item1,item2;
    printf("Enter no of elements in 1st list=");
    scanf("%d",&n1);
    printf("Enter Elements in 1st list");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&item1);
        push(&a, item1);
    }
    printf("Enter no of elements in 2nd list=");
    scanf("%d",&n2);
    printf("Enter Elements in 2nd list");
    for(i=0;i<n2;i++)
    {
        scanf("%d",&item2);
        push(&b, item2);
    }

	intersect = sortedIntersect(a, b);

	printf("\n Linked list containing common items of a & b \n ");
	printList(intersect);

	return 0;
}
