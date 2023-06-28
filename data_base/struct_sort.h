#pragma once
#include "struct_db.h"

typedef struct sorted_list
{
    Town* town;
    struct sorted_list* next;
} Sorted_list;