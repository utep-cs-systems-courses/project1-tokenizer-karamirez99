#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define LINELIMIT 100
#define TRUE 1

int evaluateInput(char *line);
void intro();
int isDigit(char c);
int parseNumber(char *line);
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
  return 0;
}

int evaluateInput(char *line)
{
  char* history = "!history";
  char* exit = "!exit";
  int i = 0, numDigits;
  
  if(line[0] == '\n')
    return -1;

  if(line[0] != '!')
    return 0;

  while(line[i] == history[i] && history[i++] != '\0') {}
  if(history[i] == '\0' && line[i] == '\n')
    return 1;

  i = 1;
  numDigits = 0;
  while(isDigit(line[i++]) && numDigits++ < 2){}
  if(1 <= numDigits && numDigits <= 2)
    return 2;
  
  i = 0;
  while(line[i] == exit[i] && exit[i++] != '\0'){}
  if(exit[i] == '\0' && line[i] == '\n')
    return 3;

  return -1;
}

int isDigit(char c)
{
  return ('0' <= c && c <= '9') ? 1 : 0;   
}

int parseNumber(char *line)
{
  int num;

  if(line[2] == '\n')
    return line[1] - '0';
  else
    return 10 * (line[1] - '0') + (line[2] - '0');
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
  int num = parseNumber(line);
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
