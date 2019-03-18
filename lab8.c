#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IDSIZE 10
#define NAMESIZE 20
#define BLOCK 2

typedef struct
{
    char last[NAMESIZE];
    char first[NAMESIZE];
} name;

typedef struct
{
    char id[IDSIZE];
    name name;
    int score;
} record;

typedef struct
{
    record *data;
    size_t nalloc;
    size_t nused;
} record_list;

void print_data(const record *data)
{
    printf("%s, %s %s, %d\n", data->id, data->name.first, data->name.last, data->score);
}

void list_init(record_list *plist)
{
    plist->data = 0;
    plist->nalloc = 0;
    plist->nused = 0;
}

void list_clear(record_list *plist)
{
    free(plist->data);
    plist->data = 0;
    plist->nalloc = 0;
    plist->nused = 0;
}

int list_insert(record_list *plist, const record *prec)
{
    print_data(prec);
    if (plist->nalloc == plist->nused)
    {
        record *temp = realloc(plist->data, (plist->nalloc + BLOCK) * sizeof(record));
        if (temp == 0)
        {
            fprintf(stderr, "realloc failed");
            return 0;
        }

        plist->data = temp;
        plist->nalloc += BLOCK;
    }

    plist->data[plist->nused++] = *prec;
    return 1;
}

int main()
{
    size_t i;
    record r[] =
    {
        {"A01017545", {"Jihyo", "Kim"}, 100},
        {"A01019545", {"Wayne", "Chang"}, 80},
        {"A01019545", {"Wayne", "kk"}, 80}
    };

    record_list rlist;
    list_init(&rlist);

    for (i = 0; i < sizeof(r) / sizeof(r[0]); i++)
    {
        if (!list_insert(&rlist, &r[i]))
        {
            break;
        }
    }

    for (i = 0; i < sizeof(r) / sizeof(r[0]); i++)
    {
        print_data(&(rlist.data[i]));
    }

    return 0;
}