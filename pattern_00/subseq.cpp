#include <stdio.h>
#include <string.h>

int main()
{
  char *word = "inguanzo";
  char *words[] = {"inguanzo", "ini", "ingo", "guan"};
  int word_count = sizeof(words) / sizeof(words[0]);
  int i = 0, j=0, k=0, word_length = strlen(word), testlength = 0;

  printf("core word: %s\n", words[0]);
  while (word_count--)
  {
    printf("word: %s\n", words[word_count]);
    testlength = strlen(words[word_count]);
    j = 0;
    for(i = 0; i < word_length; i++)
    {
      if (words[word_count][j] == word[i])
      {
        j++;
        //printf("subsequence: [id : %d] %s %d :  %d\n", word_count, words[word_count], j, testlength);
        if (j == testlength)
        {
          printf("subsequence: %s\n", words[word_count]);
          k++;
          break;
        }
      }
    }
  }
  printf("total subsequences: %d\n", k);
  return 0;
}