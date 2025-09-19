#include <cs50.h> // I did make my own string input function( which returns pointer to memory location) but intended to use CS50
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// This program computes reading level of some given Text.

// data structure
typedef struct Document {
  float average_letters;
  float average_sentences;
  int length;
  int total_words;
  int total_letters;
  int total_sentence;

} Document;

// headers
char *add_whitspace_front(char *str);
Document find_values(char *document);
char *trim_whitespaces(char *str);

int main(void) {
  // Get the string
  // calculate Grade level
  // print Results

  char *str = trim_whitespaces(get_string("\nText: "));
  int document_len = strlen(str);
  Document document = find_values(str);

  // Coleman-Liau-index
  float letter_scaler = 0.0588;
  float sentence_scaler = 0.296;
  float balancer = 15.8;
  float l = document.average_letters;
  float s = document.average_sentences;

  // here the formula is find the average number of letters in a word
  // and multiply it with 100 to get average for 100 words
  // index=0.0588×L−0.296×S−15.8

  float coleman_liau_index =
      (letter_scaler * l) - (sentence_scaler * s) - balancer;
  int rounded_coleman_liau_index = round(coleman_liau_index);

  printf("\nIndex: %f\nGrade: %d\nTotal Letters: %d\nTotal Words: %d\nTotal "
         "Sentence: %d\nAverage Letters: %f\nAverage_sentences: %f",
         coleman_liau_index, rounded_coleman_liau_index, document.total_letters,
         document.total_words, document.total_sentence, l, s);
}

char *trim_whitespaces(char *str) {
  int str_len = strlen(str);
  char white_space = ' ';

  // trim Back of string
  for (int idx = 0; idx < str_len; idx++) {
    char ch = str[idx];
    if (ch != white_space) {

      str = &str[idx];
      break;
    }
  }

  // trim Front of string
  int end_char_idx = str_len - 1;
  for (int idx = end_char_idx; idx >= 0; idx--) {
    char ch = str[idx];
    if (ch != white_space) {
      str[idx + 1] = '\0'; // "home  \0" to "home\0"
      break;
    }
  }

  return str;
}

char *add_whitspace_front(char *str) {
  int str_len = strlen(str);
  char sentence[(str_len + 1)];
  char white_space = ' ';
  sentence[0] = white_space;
  for (int i = 0; i <= str_len; i++) {
    sentence[(i + 1)] = str[i];
  }
  str = sentence;
  return str;
}

Document find_values(char *str) {
  Document values = {0, 0, 0, 0, 0, 0};
  values.length = strlen(str);
  char white_space = ' ';

  for (int i = 0; i < values.length; i++) {
    char ch = str[i];
    bool ch_alpha = isalpha(ch);

    if (ch_alpha) {
      values.total_letters++;
    }

    if ((i == 0 && ch_alpha) || (ch_alpha && str[i - 1] == white_space)) {
      values.total_words++;
    }

    if (ch == '.' || ch == '?' || ch == '!') {
      values.total_sentence++;
    }
  }

  values.average_letters =
      ((float)values.total_letters / values.total_words) *
      100.0f; // In C int/int is int so we need to cast it to float first even
              // if you store it in float variable
  values.average_sentences =
      ((float)values.total_sentence / values.total_words) * 100.0f;

  return values;
}
