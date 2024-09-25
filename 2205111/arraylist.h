#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    // Add more fields here
    int size;
    int capacity;
    int position;

} ArrayList;

void init_arraylist(ArrayList *list, int capacity)
{
    
    // dynamically allocate space for the array
    list->array = (int *)malloc(sizeof(int) * capacity);

    // initialize the size, capacity, and current position
    list->capacity = capacity;
    list->position = 0;
    list->size = 0;
  // printf("current position is %d\n", list->position);
}

void clear(ArrayList *list)
{
   // printf("Implement clear\n");
    // clear the list but do not free the array
    // modify the size, capacity, and current position

    list->size = 0;
    list->capacity = 0;
    list->position = 0;
    printf("cleared list\n");
}

int get_size(ArrayList *list)
{
    // printf("Implement get_size\n");
    // int i =0;
    // int size =0;
    // if(list->array[i] == NULL) return -1;
    // while(list->array[list->position] != '\0')
    // { size ++;
    // i++;

    // }
    printf("size is %d\n",list->size);
    return list->size;
    //
}

void resize(ArrayList *list, int new_capacity)
{
  //  printf("Implement resize\n");
    // allocate space for new array with new_capacity
      // Allocate new memory with the new capacity
    int *new_data = (int *)malloc(new_capacity * sizeof(int));
    int old_capacity=list->capacity;
    // If allocation fails
    if (new_data == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);  // Exit the program if allocation fails
    }
    
    // Copy existing elements to the new array
    for (int i = 0; i < list->size; i++) {
        new_data[i] = list->array[i];
    }
    
    // Free the old array memory
    free(list->array);
    
    // Point to the new array
    list->array = new_data;
    
    // Update the capacity to the new size
    list->capacity = new_capacity;
    printf("Resized array from %d to %d\n",old_capacity, new_capacity);
    //printf("Resized array: New capacity = %d\n", new_capacity);
    // print log message
    // int *new_array = (int *)realloc(list->array, new_capacity * sizeof(int));
    // if (new_array == NULL)
    // {
    //     printf("Failed to resize the array\n");
    //     return;
    // }
    // list->array = new_array;
    
    // list->capacity = new_capacity;
    // printf("Resized from %d to %d\n",old_capacity, new_capacity);
}

void append(ArrayList *list, int value)
{
    //printf("Implement append\n");
    //call resize if necessary
     if (list->size == list->capacity) {
        // Double the capacity when the array is full
        resize(list, list->capacity * 2);
    }
    
    // } // add value to the end of the list
    list->array[list->size] = value;
    //printf("appended %d\n",value);
    list->size++;
}

void insert(ArrayList *list, int value)
{
    //printf("Implement insert\n");
     printf("inserted %d\n", value);
    // call resize if necessary
    
    if (list->size >= list->capacity)
    {
        resize(list, list->capacity * 2);
    }
    list->size++;//increment size for inserted data

    // shift the elements to the right to make space
    for (int i = list->position+1; i < list->size; i++)
    {
        list->array[i] = list->array[i-1];
    }

    // add value at the current position
    list->array[list->position] = value;
}

int remove_at_current(ArrayList *list)
{
   // printf("Implement remove_at_current\n");
    printf("removed %d\n", list->array[list->position]);
    if (list->size == 0)
    {
        return -1;
    }
    // save the value of the current element in a variable
    int remove_value = list->array[list->position];
    // shift the elements to the left to fill the gap
    for (int i = list->position; i < (list->size) - 1; i++)
    {
        list->array[i] = list->array[i + 1];
    }

    // change the size, and current position as necessary
    list->size--;
    // call resize if necessary
    // return the saved value
    return remove_value;
}

int find(ArrayList *list, int value)
{
    //printf("Implement find\n");

    // traverse the list and return the position of the value
    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == value)
        {   printf("found %d at %d\n", value, i);
            return i;
        }
    }
    // return -1 if the value is not found
     printf("did not find %d in the list\n", value);
    return -1;
}

void move_to_start(ArrayList *list)
{
    //printf("Implement move_to_start\n");
     printf("moved current position to 0\n");
    // consider the cases when the list is empty
    if (list->size != 0)
    {
        list->position = 0;
    }
}

void move_to_end(ArrayList *list)
{
   // printf("Implement move_to_end\n");
   printf("moved current position to end\n");
    // consider the cases when the list is empty
    if (list->size != 0)
    {
        list->position = list->size - 1;
    }
}

void prev(ArrayList *list)
{
    //printf("Implement prev\n");
    // no change if the current position is at the start
    if (list->position == 0)
    {
        list->position = 0;
    }
    else
    {   printf("moved current position from %d to %d\n", list->position, list->position - 1);
        list->position--;
    }
}

void next(ArrayList *list)
{
   // printf("Implement next\n");
    // no change if the current position is at the end
    if (list->position < list->size - 1)
    {  printf("moved current position from %d to %d\n", list->position, list->position + 1);
        list->position++;
    }
}

void move_to_position(ArrayList *list, int position)
{
   //printf("Implement move_to_position\n");
    printf("moved current position from %d to %d\n", list->position, position);
    list->position = position;
}

int get_current_position(ArrayList *list)
{
    //printf("Implement get_current_position\n");
    
    if(list->array != NULL)
    { printf("current position is %d\n", list->position);
        return list->position;
    }
    else 
    return -1;
}

int get_current_element(ArrayList *list)
{
   // printf("Implement get_current_element\n");
    //printf("current element is %d\n", list->array[list->position]);
     if(list->array != NULL)
    {  printf("current element is %d\n", list->array[list->position]);
        return list->array[list->position];
    }
    else 
    return -1;
}

void print_list(ArrayList *list)
{
   // printf("< list elements here >");
   
   
    if(list->size == 0) 
    {printf("< ");}
    else printf("<");
    for (int i = 0; i < list->size; i++)
    {
        if (list->position == i)
        {
            printf(" |");
            printf("%d ", list->array[i]);
        }
        else
            printf(" %d ", list->array[i]);
    }
    if(list->size == 0) 
    {printf(" >\n");}
    else printf(">\n");
   // printf("current position is %d\n", list->position);
}

void free_list(ArrayList *list)
{
  //  printf("Implement free_list\n");
    // free the array before terminating the program
    free(list->array);
}
