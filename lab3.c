/*
    Author: Jihyo Kim
    Date: 20190224

    COMP-2510 Procedural Programming Lab03
*/

#include <stdio.h>
#include <ctype.h>

#define CHECK(PRED) printf("%s ... %s\n", (PRED) ? "passed" : "FAILED", #PRED)

/*
    replaces all occurrences of the character oldc in the string s by the character newc.
    returns the number of replacemenets.
*/
size_t str_replace_all(char s[], int oldc, int newc) {
    size_t i, number_of_replacements = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == oldc) {
            s[i] = newc;
            number_of_replacements++;
        }
    }
    return number_of_replacements;
}

/*
    replaces the last occurrence of the character oldc in the string s by the character
    newc 
    returns 1 if a replacement has been made; otherwise retruns 0;
*/
int str_replace_last(char s[], int oldc, int newc) {
    size_t i, index_of_last_occurrence = -1;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == oldc) {
            index_of_last_occurrence = i;
        }
    }
    if (index_of_last_occurrence != (size_t)-1) {
        s[index_of_last_occurrence] = newc;
        return 1;
    } else {
        return 0;
    }
}

/*
    returns 1 of the string s consists entirely of digits; otherwise, returns 0
*/
int str_all_digits(const char s[]) {
    size_t i;
    for (i = 0; s[i] != '\0'; i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}

/*
    retruns 1 if the 2 strins s and t consists of the same sequence of characters;
    otherwise, returns 0.
*/
int str_equal(const char s[], const char t[]) {
    size_t i = 0;
    while (s[i] != '\0' || t[i] != '\0') {
        if (s[i] != t[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    char mystr[] = "hello, world";
    char mystr2[] = "1234";
    char mystr3[] = "1234";
    char mystr4[] = "11hello1234";

    char mystr5[] = "hello, world yo";
    char mystr6[] = "hello, world yo";
    CHECK(str_replace_all(mystr, 'l', 'x') == 3);
    CHECK(str_replace_all(mystr2, '1', '5') == 1);
    CHECK(str_replace_all(mystr, 'o', 'q') == 2);


    CHECK(str_replace_last(mystr, 'w', 'q') == 1);
    CHECK(str_replace_last(mystr, 'z', 'q') == 0);
    CHECK(str_replace_last(mystr2, '9', '5') == 0);

    CHECK(str_all_digits(mystr) == 0);
    CHECK(str_all_digits(mystr2) == 1);
    CHECK(str_all_digits(mystr4) == 0);

    CHECK(str_equal(mystr, mystr) == 1);
    CHECK(str_equal(mystr5, mystr6) == 1);
    CHECK(str_equal(mystr, mystr5) == 0);
    return 0;
}