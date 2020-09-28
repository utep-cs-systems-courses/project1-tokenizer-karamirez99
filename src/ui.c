#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define LINELIMIT 100
#define TRUE 1

int evaluateInput(char *line);
void intro();
int isDigit(char c);
char* copyLine(char *line);
void printItemHelper(char *line, List *list);

int main()
{
  List* history = init_history();
  char **tokens, line[LINELIMIT];
  int num;

  intro();
  while(TRUE){
    printf(">Enter a line\n");
    fgets(line, LINELIMIT, stdin);
    num = evaluateInput(line);

    switch(num) {
      case -1:
	break;
      case 0:
        add_history(history, copyLine(line));
	break;
      case 1:
        print_history(history);
	break;
      case 2: {
	printItemHelper(line, history);
        break;
      }
      case 3:
	printf("Thanks for using this\n");
	free_history(history);
        return 0;
      default:
        break;
    }

    printf("\n");
  }
}

int evaluateInput(char *line)
{
  char* history = "!history";
  char* exit = "!exit";
  int i = 0, numDigits;

  if(line[0] == '\n')
    return -1;

  /*Checking if given text is keyword*/
  if(line[0] != '!')
    return 0;

  /*Checking for history keyword)*/
  while(line[i] == history[i] && history[i++] != '\0') {}
  if(history[i] == '\0' && line[i] == '\n')
    return 1;

  /*Checking for get history */
  if(isDigit(line[1]))
    return 2;

  /*Checking for exit keyword)*/
  i = 0;
  while(line[i] == exit[i] && exit[i++] != '\0'){}
  if(exit[i] == '\0' && line[i] == '\n')
    return 3;

  printf("\nUnrecognized Command\n");
  return -1;
}

int isDigit(char c)
{
  return ('0' <= c && c <= '9') ? 1 : 0;   
}

char *copyLine(char *line)
{
  int numChars = 0;
  
  while(line[numChars++] != '\n'){}

  numChars -= 1;
  return (numChars > 0) ? copy_str(line, numChars) : NULL;
}

void printItemHelper(char *line, List *history)
{
  int num = atoi(line+1);
  char **tokens, *item = get_history(history, num);

  if(item != NULL){
    printf("\n%d: %s\n", num, item);
    tokens = tokenize(item);
    print_tokens(tokens);
    free_tokens(tokens);
  } else {
    printf("\nUnavailable History\n");
  }
  
}

void intro()
{
  printf("Welcome to History thing or something\n");
  printf("To view all history, type !history\n");
  printf("To examine a specific history, type !value\n");
  printf("To exit, type !exit\n\n");
}
