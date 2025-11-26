#define _POSIX_C_SOURCE                                                        \
  200809L // Posix macro tells compiler to use I want to use functions from
          // posix.1-2008 and later
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// headers
int count_scores(char *word);
int char_hash(char c);
char *get_string_unix(char *format);
bool is_uppercase(char x);
bool is_lowercase(char x);
int strlength(char *string);
char to_uppercase(char x);

int main(void) {
  // You have to free every string you get from get_string_unix function because
  // it uses malloc

  char *player1 = get_string_unix("\nPlayer 1: ");
  char *player2 = get_string_unix("\nPlayer 2: ");

  int score_of_player1 = count_scores(player1);
  int score_of_player2 = count_scores(player2);

  if (score_of_player1 > score_of_player2) {
    printf("\n\t Player 1 Wins with Scores: %d", score_of_player1);
    free(player1);
    free(player2);
    return 0;
  } else if (score_of_player2 > score_of_player1) {
    printf("\n\t Player 2 Wins with Scores: %d", score_of_player2);
    free(player1);
    free(player2);
    return 0;
  } else {
    printf("\n\t Tie with Scores: %d", score_of_player1);
    free(player1);
    free(player2);
    return 0;
  }

  free(player1);
  free(player2);
  return 1;
}

char *get_string_unix(char *format) {

  char *line =
      NULL;       // getstring() is going to point it somewhere itself in memory
  size_t len = 0; // getstring() is going to define size itself so 0 is okay
  ssize_t nread;  // getstring() will return size of typed string or -1 if error
                  // or EOF happened

  printf("\n%s", format);

  nread = getline(&line, &len, stdin);

  // if there was and error or EOF
  if (nread == -1) {
    if (feof(stdin)) {
      fprintf(stderr, "End of input (EOF).\n");
    } else {
      perror("getline");
    }
    free(line);
    exit(EXIT_FAILURE);
  }

  // Remove trailing getline
  if (nread > 0 && line[nread - 1] == '\n')
    line[nread - 1] = '\0';

  return line;
}

bool is_uppercase(char x) { return (x >= 'A' && x <= 'Z'); }

bool is_lowercase(char x) { return (x >= 'a' && x <= 'z'); }

char to_uppercase(char x) { return (x - 32); }

int count_scores(char *word) {
  const int SCORES[] = {1, 3, 3, 2,  1, 4, 2, 2, 1, 8, 5, 1, 3,
                        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
  int length = strlength(word);
  int score = 0;

  for (int idx = 0; idx < length; idx++) {
    char x = word[idx];
    int index_hash = char_hash(x);
    score += SCORES[index_hash];
  }
  return score;
}

int char_hash(char x) {
  if (is_uppercase(x)) {
    return (-1 * ('A' - x));
  } else if (is_lowercase(x)) {
    return (-1 * ('a' - x));
  } else {
    fprintf(stderr,
            "\nError: '%c' Word contains special or more then just alphabets "
            "characters.",
            x);
    exit(1);
  }
}

int strlength(char *string) {
  char *ptr = string;
  int length = 0;
  while (*ptr != '\0') {
    length++;
    ptr++;
  }
  return length;
}
