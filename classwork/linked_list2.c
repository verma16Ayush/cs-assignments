#include <stdio.h>
#include <math.h>


// note- always set the last node's next as null or you will get segmentation fault
// struct Node *head;
struct Node
{
    int data;
    struct Node *next;
};

void at_head(struct Node** head_ref, int data);    //insert a node at head
void at_tail(struct Node** head_ref, int data);    //insert a node at tail
void after_node(struct Node** node_ref, int data); //insert a noe after a given node
void print_ll(struct Node** head_ref);             //print the linked list
void del_head(struct Node** head_ref);             //delete list head
void del_tail(struct Node** head_ref);             //delete list tail 
void reverse_ll(struct Node** head_ref);           //reverse the linked list

void at_head(struct Node** head_ref, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)); // allocate memory for a node
    new_node->data = data;                                              // set the data for this node equal to new data
    new_node->next = *head_ref;                                         // point this node's 'next' to previous head
    *head_ref = new_node;                                               // seat the head as this new node
}

void at_tail(struct Node** head_ref, int data)
{
    struct Node *curr_node = *head_ref;                                 // make a node pointer and point it to head of list
    while (curr_node->next != NULL)
        curr_node = curr_node->next;                                    // traverse to the end of the list

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)); // create a new node
    new_node->data = data;                                              // set its data value equal to new value
    curr_node->next = new_node;                                         // point the curr_node(node at the end of our list) to newly created node(new_node)
    new_node->next = NULL;                                              // set new node's next as null
}

void after_node(struct Node** node_ref, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)); //create a new node
    new_node->next = (*node_ref)->next;                                 //point this node's next to next of the node after which we wanted to insert
    new_node->data = data;                                              //set data equal to new data
    (*node_ref)->next = new_node;                                       //point our original node's next to this newly created node
}

void print_ll(struct Node** head_ref)
{
    struct Node *curr_node = *head_ref;
    for(curr_node = *head_ref; curr_node != NULL; curr_node=curr_node->next)
    {
        printf("%d -> ", curr_node->data);
    }
    printf("\n");
}


void del_head(struct Node** head_ref)
{
    // free(*head_ref);
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void del_tail(struct Node** head_ref)
{
    struct Node* curr_node = *head_ref;
    while(curr_node->next != NULL)
    {
        if((curr_node->next)->next == NULL)
        {
            // curr_node->next = NULL;
            break;
        }
        curr_node = curr_node->next;
    }
    struct Node* temp = curr_node->next;
    curr_node->next = NULL;
    free(temp);
}

void reverse_ll(struct Node** head_ref)
{
    struct Node* curr_node = *head_ref;
    struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
    struct Node* next = (struct Node*)malloc(sizeof(struct Node));
    prev = NULL;
    next = NULL;
    while(curr_node != NULL)
    {
        next = curr_node ->next;
        curr_node->next = prev;
        prev = curr_node;
        curr_node = next;
    }
    *head_ref = prev;
}


int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 0;
    head->next = NULL;

    printf("\nenter 3 elements to be inserted at head, current head value is 0\n");
    for (int i = 0; i < 3; i++)
    {
        int data;
        scanf("%d", &data);
        at_head(&head, data);
    }
    printf("\nafter entering 3 elements at head, the list looks like\n");
    print_ll(&head);

    printf("\nenter 3 elements at the tail\n");
    for (int i = 0; i < 3; i++)
    {
        int data;
        scanf("%d", &data);
        at_tail(&head, data);
    }
    printf("\nafter entering 3 elements at tail, the list looks like\n");
    print_ll(&head);

    printf("\nenter one element to be inserted after 2nd node\n");
    int data;
    scanf("%d", &data);
    after_node(&(head->next), data);
    printf("\nafter entering 1 elements after 2nd node, the list looks like\n");
    print_ll(&head);

    printf("\ndeleting the head. list now looks like\n");
    del_head(&head);
    print_ll(&head);

    printf("\ndeleting the tail. list now looks like\n");
    del_tail(&head);
    print_ll(&head);

    printf("\nreversing\n");
    reverse_ll(&head);
    print_ll(&head);


    return 0;
}