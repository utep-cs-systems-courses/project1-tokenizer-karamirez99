#include "history.h"
#include <stdlib.h>
#include <stdio.h>

List* init_history()
{
  List *list = malloc(sizeof(List));
  return list;
}

void add_history(List *list, char *str)
{
  int id;
  Item *currItem;

  if(list->root == NULL){
    Item *newItem = malloc(sizeof(Item));
    newItem->id = 1;
    newItem->str = str;
    list->root = newItem;
    return;
  }

  id = 2;
  currItem = list->root;
  while(currItem->next != NULL){
    id += 1;
    currItem = currItem->next;
  }

  Item *newItem = malloc(sizeof(Item));
  newItem->id = id;
  newItem->str = str;

  currItem->next = newItem;
}

char* get_history(List *list, int id)
{
  Item *currItem;
  int currId;
  
  if(list->root == NULL)
    return NULL;

  
  currItem = list->root;
  for(currId = 1; currId < id && currItem->next != NULL; currId++){
    currItem = currItem->next;
  }
  
  return (currId == id) ? currItem->str : NULL;
}

void print_history(List *list)
{
  Item *currItem;
  
  if(list->root == NULL)
    return;

  currItem = list->root;
  while(currItem != NULL){
    printf("%d: %s\n", currItem->id, currItem->str);
    currItem = currItem->next;
  }
}

void free_history(List *list)
{
  Item *currItem, *nextItem;

  if(list->root == NULL)
    return;
  
  currItem = list->root;
  while(currItem != NULL){
    free(currItem->str);
    nextItem = currItem->next;
    free(currItem);
    currItem = nextItem;
  }
  
  free(list);
}
