#include "tokenizer.h"
//#include <stdlib.h>
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
  
  while ((c = s[i++]) != '\0' && space_char(c)) {
  }
  i -= 1;
  
  return (s[i] != '\0') ? (s + i) : NULL;
}

char *word_terminator(char *s)
{
  char c;
  int i = 0;

  while ((c = s[i++]) != '\0' && non_space_char(c)) {
  }
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
