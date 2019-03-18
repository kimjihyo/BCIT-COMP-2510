#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define IDSIZE 10
#define NAMESIZE 20
#define LINESIZE 100

typedef struct {
    char last[NAMESIZE];
    char first[NAMESIZE];
} name;

typedef struct {
    char id[IDSIZE];
    name name;
    int score;
} record;

void makelower(char s[]) {
    size_t i;
    for (i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            s[i] = tolower(s[i]);
        }
    }
}

int read_record (record *prec) {
    char buffer[LINESIZE];
    char first[LINESIZE];
    char last[LINESIZE];
    char id[LINESIZE];
    int score;

    if (!fgets(buffer, LINESIZE, stdin)) {
        clearerr(stdin);
        return 0;     
    }

    if (sscanf(buffer, "%s %s %s %d", first, last, id, &score) == 4) {
        makelower(first); makelower(last); makelower(id);
        if (id[0] != 'a' || strlen(first) >= NAMESIZE || strlen(last) >= NAMESIZE || strlen(id) >= IDSIZE) {
            return -1;
        }

        strcpy(prec->name.first, first);
        strcpy(prec->name.last, last);
        strcpy(prec->id, id);
        prec->score = score;

        return 1;
    } else {
        return -1;
    }
    return 0;
}


void print_record(const record *prec) {
    printf("%s: %s, %s : %d\n", prec->id, prec->name.last, prec->name.first, prec->score);
}


int main() {
    record my_record;
    printf("%d\n", read_record(&my_record));
    print_record(&my_record);
    return 0;
}