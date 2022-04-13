#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linkedList{
	int data;
	struct linkedList *nextnode;
}node;

void push(node*,int);
void print_list(node*);

int main(){
	node* head=(node*)malloc(sizeof(node));
	node* current=(node*)malloc(sizeof(node));
	
	head->data=0;
	head->nextnode=current;
	
	current->data=1;
	current->nextnode=NULL;
	
	push(head,12);
	push(head,5);
	remove_last(head);
	print_list(head);
	
}

void print_list(node* head){
    node* current = head;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->nextnode;
    }
}

void push(node* head, int data) {
    node* current = head;
    while (current->nextnode != NULL) {
        current = current->nextnode;
    }

    current->nextnode = (node*)malloc(sizeof(node));
    current->nextnode->data = data;
    current->nextnode->nextnode = NULL;
}

int remove_last(node* head) {
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->nextnode == NULL) {
        retval = head->data;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */
    node* current = head;
    while (current->nextnode->nextnode != NULL) {
        current = current->nextnode;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->nextnode->data;
    free(current->nextnode);
    current->nextnode = NULL;
    return retval;

}


