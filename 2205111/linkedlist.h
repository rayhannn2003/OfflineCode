#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    // add *next and *prev here
    struct Node *next;
    struct Node *prev;
    
} Node;

typedef struct
{
    // add Node* head, tail, current_position and other necessary fields here
    Node *head;
    Node *tail;
    Node *current_position;
    int size;
} LinkedList;

void init_linkedlist(LinkedList *list)
{
    //printf("implement init_linkedlist\n");
    // initialize head, tail with null
    list->head = NULL;
    list->tail = NULL;
    list->current_position = NULL;
    list->size = 0;
}

void clear(LinkedList *list)
{
    printf("cleared list\n");
    // traverse the list and free each node
    // set head and tail to null
    Node *current_node = list->head;
    while (current_node != NULL)
    {
        Node *for_free = current_node;
        current_node = current_node->next;
        free(for_free);
    }
    list->head = NULL;
    list->tail = NULL;
    list->current_position = NULL;
    list->size = 0;
}

int get_size(LinkedList *list) 
{
    printf("size is %d\n",list->size);
   // return list->size;

    return list->size;
}

void append(LinkedList *list, int value)
{
   
    // create a new node and set its value
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = list->tail;

    // consider the case when the list is empty and when it isnt
    if (list->tail != NULL)
    {
        list->tail->next = new_node;
    }
    else
    {
        list->head = new_node;//when empty
    }

    list->tail = new_node;
    list->size++;
    //  list->current_position = new_node;
    if (list->current_position == NULL) // check
    {
        list->current_position = new_node;
    }
    // printf("appended %d\n",value);
}

void insert(LinkedList *list, int value)
{
    //printf("Implement insert\n");
    
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;

    if (list->current_position == NULL)
    { // If the list is empty
        new_node->next = NULL;
        new_node->prev = NULL;
        list->head = new_node;
        list->tail = new_node;
        list->current_position = new_node;
    }
    else
    {
        new_node->next = list->current_position;
        new_node->prev = list->current_position->prev;

        if (list->current_position->prev != NULL)
        {
            list->current_position->prev->next = new_node;
        }
        else
        {
            list->head = new_node; // as prepend
        }
        list->current_position->prev = new_node;
    }
     printf("inserted %d\n", value);
    list->current_position = new_node; // New node becomes the current position
    list->size++;
}

int remove_at_current(LinkedList *list)
{
    //printf("Implement remove_at_current\n");
    if (list->current_position == NULL)
    {
        return -1;
    }
     printf("removed %d\n", list->current_position->data);
    // consider the case when current code is at the begining or at the end
  //  Node *to_be_removed = (Node *)malloc(sizeof(Node));
   Node* to_be_removed = list->current_position;
    int value = to_be_removed->data;
    if (to_be_removed->prev == NULL)
    {
        list->head = to_be_removed->next;
        to_be_removed->next->prev = NULL;
      //  list->current_position = list->current_position->next;
    }
    else if (to_be_removed->next == NULL)
    {
        list->tail = list->current_position->prev;
        to_be_removed->prev->next = NULL;
       // list->current_position = list->current_position->prev;
    }
    else if (list->size==1)
    {
        /* code */
        
        list->head=NULL;
        list->tail=NULL;
        list->current_position=NULL;
    }
    else
    {
        list->current_position->prev->next = list->current_position->next;
        list->current_position->next->prev = list->current_position->prev;
          //list->current_position = list->current_position->next;
    }
        list->current_position = list->current_position->next;

    free(to_be_removed);
    list->size--;
    
    return value;
}

int find(LinkedList *list, int value)
{
   // printf("Implement find\n");
    // traverse the list and return the position of the value
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = list->head;
   // int index = 0;
    int position = 0;
    while (temp != NULL)
    {
        if (temp->data == value)
        {    printf("found %d at %d\n", value, position);
            return position;
        }
        temp = temp->next;
        position++;
    }  printf("did not find %d in the list\n", value);
    return -1;
}

void move_to_start(LinkedList *list)
{
   // printf("Implement move_to_start\n");
    list->current_position = list->head;
     printf("moved current position to 0\n");
}

void move_to_end(LinkedList *list)
{
    // printf("Implement move_to_end\n");
    list->current_position = list->tail;
     printf("moved current position to end\n");
}

void prev(LinkedList *list)
{
    //printf("Implement prev\n");
     int pos = 0;
    Node *current_for_pos = list->head;
    while (current_for_pos != NULL)
    {
        if (current_for_pos == list->current_position)
        {
            //printf("current position is %d\n", pos);
             break;
        }
        current_for_pos = current_for_pos->next;
        pos++;
    }
    int position_now =pos;
    if (list->current_position->prev != NULL)
    {   printf("moved current position from %d to %d\n", position_now, position_now - 1);
        list->current_position = list->current_position->prev;
    }
}

void next(LinkedList *list)
{    int pos = 0;
    Node *current_for_pos = list->head;
    while (current_for_pos != NULL)
    {
        if (current_for_pos == list->current_position)
        {
            //printf("current position is %d\n", pos);
             break;
        }
        current_for_pos = current_for_pos->next;
        pos++;
    }
    int position_now =pos;
   // printf("Implement next\n");
    if (list->current_position->next != NULL)
    {   printf("moved current position from %d to %d\n",position_now , position_now - 1);
        list->current_position = list->current_position->next;
    }
}

void move_to_position(LinkedList *list, int position)
{
    // printf("Implement move_to_position\n");
    //  traverse the list and stop at the given position
    int temp = 0;
    
    //for getting position
      int pos = 0;
    Node *current_for_pos = list->head;
    while (current_for_pos != NULL)
    {
        if (current_for_pos == list->current_position)
        {
            //printf("current position is %d\n", pos);
             break;
        }
        current_for_pos = current_for_pos->next;
        pos++;
    }
    int old_position =pos;
    //end of finding position
  //  Node *currentNode = list->head;
    Node *current = list->head;
    if (position < 0 || position >= list->size)
        return;
    
    while (temp != position)
    {
        temp++;
        current = current->next;
    }
    list->current_position = current;
    printf("moved current position from %d to %d\n", old_position, position);
}

int get_current_position(LinkedList *list)
{
    // printf("Implement get_current_position\n");
    //  traverse the list and stop when you are at the current position
    //  return the position (integer)
    int pos = 0;
    Node *current = list->head;
    while (current != NULL)
    {
        if (current == list->current_position)
        {
            printf("current position is %d\n", pos);
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;
}

int get_current_element(LinkedList *list)
{
    // printf("Implement get_current_element\n");
    // return the value at the current position
    int pos = 0;
    Node *current = list->head;
    while (current != NULL)
    {
        if (current == list->current_position)
        {
            printf("current element is %d\n", current->data);
            return current->data;
        }
        current = current->next;
        pos++;
    }
    return -1;
}

void print_list(LinkedList *list)
{

    // while(list->head !=NULL)
    // {
    //     printf("< list elements here >");
    //     printf("%d ",list->head->data);
    //     list->head=list->head->next;

    // }
    if (list->size == 0)
    {
        printf("< ");
    }
    else
        printf("<");
    Node *temp = list->head;
    // for (;temp != list->tail;temp->next)
    while (temp != NULL)
    {
        if (list->current_position == temp)
        {
            printf(" |");
            printf("%d ", temp->data);
        }
        else
            printf(" %d ", temp->data);

        temp = temp->next;
    }
    if (list->size == 0)
    {
        printf(" >\n");
    }
    else
        printf(">\n");
    /*Node *current = list->head;
     printf("<");
     while (current != NULL)
     {
         printf("%d", current->data);
         if (current->next != NULL)
             printf(", ");
         current = current->next;
     }
     printf(">\n");*/
}

void free_list(LinkedList *list)
{
    printf("Implement free_list\n");
    // free each node in the list
    int pos = 0;
    Node *current = list->head;
    Node *temp;
    while (current != NULL)
    {
        temp = current;
        free(temp);
        current = current->next;
    }
    list->head = list->tail = list->current_position = NULL;
    list->size = 0;
}
