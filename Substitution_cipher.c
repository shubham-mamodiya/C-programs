/*
 * File: substitution_cipher.c
 * Author: Shubham Mamodiya
 * Description:
 *    This program an implementation of encryption algorithm to cypher Text with
 * a unique key.
 */
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_INVALID_INPUT 2

// headers
int char_hash(char ch);
void substitution_cipher(char *plain_text, char *key, int len_plain_text,
                         char *cipher_text);

int main(int argc, char *argv[]) {
  // checking
  // There should be only Executable and Key in the cli-arguments
  if (argc != 2) {
    printf("Usage: ./Executable Key.\n");
    return ERR_INVALID_INPUT;
  }

  char *key = argv[2];
  int key_len = strlen(key);

  // checking length
  if (key_len != 26) {
    printf("Key must contain 26 characters.\n");
    return ERR_INVALID_INPUT;
  }

  // checking does it only contains letters
  for (int idx = 0; idx < key_len; idx++) {
    char ch = key[idx];

    if (!isalpha(ch)) {
      printf("Key must contain only letters.\n");
      return ERR_INVALID_INPUT;
    }
  }
  // checking done

  char *plain_text = get_string("Plain Text: ");
  int len_plain_text = strlen(plain_text);
  char cipher_text[len_plain_text];

  substitution_cipher(plain_text, key, len_plain_text, cipher_text);
  printf("Cipher Text: %s", cipher_text);
  return EXIT_SUCCESS;
}

void substitution_cipher(char *plain_text, char *key, int len_plain_text,
                         char *cipher_text) {
  /*
   * cipher's the Plain Text with key and stores it in cipher_text pointer
   * location cipher_text buffer should be same or more in length of plain text
   * String plain text
   * char key[26]
   * int length of plain text
   * pointer cipher_text[length]
   */
  for (int idx = 0; idx < len_plain_text; idx++) {
    char ch = plain_text[idx];
    int ch_hash = char_hash(ch);

    if (ch_hash == 0) { // ch is not alphabetical
      cipher_text[idx] = plain_text[idx];
      continue;
    } else if (isupper(plain_text[idx])) {
      cipher_text[idx] = toupper(key[idx]);
    } else {
      cipher_text[idx] = key[idx];
    }
  }
  cipher_text[len_plain_text] = '\0';
}

int char_hash(char ch) {
  if (isupper(ch)) {
    return (-1 * ('A' - ch));
  } else if (islower(ch)) {
    return (-1 * ('a' - ch));
  }
  return 0;
}
