/*
    Author: Jihyo Kim
    Date: 20190224

    COMP-2510 Procedural Programming Review Excercise for Midterm Preperation
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
    (1-a) a function that returns the index of the first occurrence of the 
    character c in the string s. If c is not found, the function returns -1
    (cast as size_t)
*/
size_t find_first(const char s[], int c) {
    size_t i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return i;
        }
    }
    return (size_t)-1;
}

/*
    (1-b) a function that replaces the first occurrence of the character oldc
    in the string s by the character newc.
*/
void replace_first(char s[], int oldc, int newc) {
    size_t i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == oldc) {
            s[i] = newc;
            return;
        }
    }
}

/*
    (1-c) a function that replaces the last occurrence of the character oldc 
    in the string s by the character newc.
*/
void replace_last(char s[], int oldc, int newc) {
    size_t i, last_index = -1;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == oldc) {
            last_index = i;
        }
    }
    if (last_index != (size_t)-1) {
        s[last_index] = newc;
    }
}

/*
    (1-d) a function that returns the nnumber of occurrence of the integer x 
    in the array of n integer.
*/
size_t count(const int a[], size_t n, int x) {
    size_t i, number_of_occurrence = 0;
    for (i = 0; i < n; i++) {
        if (a[i] == x) {
            number_of_occurrence++;
        }
    }
    return number_of_occurrence;
}

/* 
    (2-a) a function that returns the number of alphabets in the string s.
*/
size_t count_alpha(const char s[]) {
    size_t i, number_of_alphas = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            number_of_alphas++;
        }
    }
    return number_of_alphas;
}

/*
    (2-b) a function that returns 1 if the string s consists entirely of digits;
    otherwise, it returns 0.
*/
int all_digits(const char s[]) {
    size_t i;
    for (i = 0; s[i] != '\0'; i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}

/*
    (2-c) a function that copies the string src to dest with all uppercase characters
    changed to lowercase in the copy.
    Assume that dest is large enough to store the copy.
*/
void lowercase_copy(char dest[], const char src[]) {
    size_t i;
    for (i = 0; src[i] != '\0'; i++) {
        if (isalpha(src[i])) {
            dest[i] = tolower(src[i]);
        } else {
            dest[i] = src[i];
        }
    }
}


/*
    (2-d) a function that copies the string src to dest in reverse. ASsume that dest
    is large enough to store the copy.
    For example, after executing the following char s[10]; reverse_copy(s, "hello");
    s will contain the stirng "olleh".
*/

void reverse_copy(char dest[], const char src[]) {
    size_t i, len = strlen(src);
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[len - i];
    }
}

/*
    (2-e) a function that makes a copy of src with leading whitespaces removed and
    store the copy in dest. (A whitespace is any character that tests true by thr isspace
    function.) Assume that dest is large enough to store the copy.
*/
void ltrim_copy(char dest[], const char src[]) {
    size_t i, starting = 0;
    for (i = 0; src[i] == ' ' && src[i] != '\0'; i++) {
        starting = i;
    }
    starting++;
    for (i = 0; src[i + starting] != '\0'; i++) {
        dest[i] = src[i + starting];
    }
}

/*
    a function that tests wheter the string s is a valid BCIT student ID. For simplicity,
    a valid student ID is a string that starts with either an 'a'or 'A' & is then followed
    by exactly 8 digits. The function returns 1 if s is a valid student ID; otherwise,
    it returns 0.
*/
int is_valid_id(const char s[]) {
    size_t i;
    if (s[0] != 'a' || s[0] != 'A') {
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
    a function that tests whether the string s is valid. If it is valid, the function
    returns 1; otherwise, it returns 0.
    For this question, a string is valid if it has at least 2 characters and at most
    19 characters (not counting the null character). Furthermore, each character must be
    either an alphabet or a hyphen and the string cannot start or end with a hypen.
    For example, Homer and Homer-J are valid whereas, D'Arcy, B, and bart- are invalid.
*/
int is_valid(const char s[]) {
    size_t i;
    for (i = 0; s[i] != '\0'; i++) {
        if (!isalpha(s[i]) && s[i] == '-') {
            return 0;
        }
    }
    return i >= 2 && i <= 19 && s[0] != '-' && s[i-1] != '-';
}

/*
    Write a C program that counts the number of alphabets in a text file. The name of the
    text file is speficied on the command-line. The program should check that exactly
    1 file is specified.
*/
size_t count_number_of_alphas_in_text_file(char *file_name) {
    size_t number_of_alphas = 0;
    int c;
    FILE *fp = fopen(file_name, "r");
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            number_of_alphas++;
        }
    }
    fclose(fp);
    return number_of_alphas;
}

int main() {
    char word[50] = "       hello";
    char dest[125];
    ltrim_copy(dest, word);
    printf("%s\n", dest);
    return 0;
}