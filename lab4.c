/*
    Author: Jihyo Kim
    Date: 20190224

    COMP-2510 Procedural Programming Lab04
*/

#include <stdio.h>
#include <ctype.h>

#define CHECK(PRED) printf("%s...%s\n", (PRED) ? "passed" : "failed", #PRED);

/*
    The squeeze function first converts each tab character in the input to a space character
    & then consequtive spaces are squeezed. For example, tow or more consecutive spaces
    are replaced by a single space in the output; all other characters (those that are 
    neither a tab nor a space)
*/
void squeeze_spaces() {
    int c, pc = ' ';
    while ((c = getchar()) != EOF) {
        c = c == '\t' ? ' ' : c;
        if (!(pc == ' ' && c == ' ')) {
            putchar(c);
        }
        pc = c;
    }
}
/*
    format_words echoes back what it reads but with the first character of each word
    printed in uppercase (if it is an alphabet) and the rest of the alphabets in the word
    printed in lowercase. For simplicity, except for the very first character in the input, 
    we regard a character as the first character of a wrod if it immediatrly follows a 
    whitespace or double quotes.
*/
void format_words() {
    int c, pc = ' ';
    while ((c = getchar()) != EOF) {
        if (isspace(pc) || c == '"') {
            c = toupper(c);
        } else {
            c = tolower(c);
        }
        putchar(c);
        pc = c;
    }
}

void squeeze_spaces_and_format_words() {
    int c, pc = ' ';
    while ((c = getchar()) != EOF) {
        c = c == '\t' ? ' ' : c;
        if (!(pc == ' ' && c == ' ')) {
            if (isspace(pc) || c == '"') {
                c = toupper(c);
            } else {
                c = tolower(c);
            }
            putchar(c);
        }
        pc = c;
    }
}

int main() {
    squeeze_spaces_and_format_words();
    return 0;
}