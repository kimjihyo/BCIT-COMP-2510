/*
    Author: Jihyo Kim
    Date: 20190224

    COMP-2510 Procedural Programming Lab05
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LINESIZE 1024

/*
    returns 1 if a wrd of length less then n is successfully
    read (from user input) and stored in the array word; retuns 0 when the user
    presses the end-of-file key.
    PRECONDITION: n < LINESIZE (a macro with a value of 1024)
*/

int get_word(char prompt[], char word[], size_t n) {
    char buffer[LINESIZE];
    char tempWord[LINESIZE];
    printf("%s", prompt);
    while (fgets(buffer, LINESIZE, stdin)) {
        if (sscanf(buffer, "%s", tempWord) != 0) {
            if (strlen(tempWord) < n) {
                strcpy(word, tempWord);
                return 1;
            }
        }
    }
    return 0;
}

/*
    is_valid_id function is used test wheter a string is balid ID.
    returns 1 if s is a valid ID; otherwise returns 0.
*/
int is_valid_id(const char s[]) {
    size_t i;
    if (s[0] != 'a' && s[0] != 'A') {
        return 0;
    }
    for (i = 1; s[i] != '\0'; i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return i == 9;
}

/*
    Combined get_word and is_valid_id in one function.
*/
void get_word_and_is_valid_id() {
    char buffer[LINESIZE];
    char temp[LINESIZE];
    while (fgets(buffer, LINESIZE, stdin)) {
        if (sscanf(buffer, "%s", temp) != 0) {
            if (is_valid_id(temp)) {
                temp[0] = 'a';
                fprintf(stderr, "%s\n", temp);
            }
        }
    }
}

int main() {
    get_();
    return 0;
}