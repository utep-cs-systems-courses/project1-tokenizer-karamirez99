#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

int space_char(char c)
{
  return (c == ' ' || c == '\t') ? 1 : 0;
}

int non_space_char(char c)
{
  return (c != ' ' && c != '\t' && c != '\0') ? 1 : 0;
}

char *word_start(char *s)
{
  char c;
  int i = 0;
  
  while ((c = s[i++]) != '\0' && space_char(c)) {}
  
  i -= 1;
  return (s[i] != '\0') ? (s + i) : NULL;
}

char *word_terminator(char *s)
{
  char c;
  int i = 0;

  while ((c = s[i++]) && non_space_char(c)) {}

  i -= 1;
  return s + i;
}

int count_words(char *s)
{
  int wordCount = 0;
  char *word = s;

  while((word = word_start(word)) != NULL){
    word = word_terminator(word);
    wordCount += 1;
  }

  return wordCount;
}

char *copy_str(char *inStr, short len)
{
  char *newStr;
  int i = 0;

  newStr =  malloc(sizeof(char) * len+1);

  while((i < len) && (newStr[i++] = inStr[i]) != '\0'){}

  newStr[i] = '\0';
     
  return newStr;
}

char **tokenize(char* str)
{
  char **tokens;
  char *word = str, *wordEnd;
  int i = 0, cCount;
  
  tokens = malloc(sizeof(char*) * count_words(str) + 1);
  
  while((word = word_start(word)) != NULL){
    cCount = 0;
    wordEnd = word_terminator(word);

    while((word + cCount++) != wordEnd){}
    
    tokens[i++] = copy_str(word, cCount - 1);
    word = wordEnd;
  }

  tokens[i] = NULL;
  return tokens;
}

void print_tokens(char **tokens)
{
  int i = 0;
  
  while(tokens[i] != NULL){
    printf("%s\n", tokens[i++]);
  }
}

void free_tokens(char **tokens)
{
  char *currWord;
  int i = 0;

  while(tokens[i] != NULL){
    free(tokens[i++]);
  }

  free(tokens);
}
