#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings.h"
#define LEN 256

typedef unsigned long long ull;

typedef struct town {
    char* name;
    ull population;
    struct town* next;
} Town;

int hash_str(char* str);
void add_town(Town*** db);
void remove_town(Town*** db);
void print_db(Town** db);