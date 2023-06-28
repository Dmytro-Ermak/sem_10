#include "struct_db.h"
#include "struct_sort.h"


int hash_str(char* str) {
    int hash = 0;
    while (*str) {
        hash += *str++;
        hash = (hash * 3) % LEN;
    }
    return hash;
}

void add_town(Town*** db)
{
    puts("Add town name and population");
    char* name = get_town();
    ull pop = get_num();
    int hash = hash_str(name);
    //printf("%d\n", hash);
    if ((*db)[hash] == NULL)
    {
        (*db)[hash] = (Town*) malloc(sizeof(Town));
        (*db)[hash] -> name = name;
        (*db)[hash] -> population = pop;
        (*db)[hash] -> next = NULL;
        puts("Town added");
    }
    else
    {
        Town* db_copy  = (*db)[hash];
        while (db_copy -> next != NULL)
        {
            if (!strcmp(db_copy -> name, name))
            {
                puts("This town in data base");
                return;
            }
            else
            {
                db_copy = db_copy -> next;
            }
        }
        if (!strcmp(db_copy -> name, name))
        {
            puts("This town in data base");
            return;
        }
        else
        {
            puts("Town added");
            db_copy -> next = (Town*)malloc(sizeof(Town));
            db_copy = db_copy -> next;
            db_copy -> name = name;
            db_copy -> population = pop;
            db_copy -> next = NULL;
        }
    }
    return;
}

void remove_town(Town*** db)
{
    puts("Add town name");
    char* name = get_town();
    int hash = hash_str(name);
    Town* copy = (*db)[hash];
    if (copy == NULL)
    {
        puts("This town not in base");
        return;
    }
    if (!strcmp(name, copy -> name))
    {
        (*db)[hash] = copy -> next;
        free (copy -> name);
        free(copy);
        puts("town removed");
        return;
    }
    Town* copy_prev = copy;
    copy = copy -> next;
    while(copy != NULL)
    {
        if (strcmp(name, copy -> name))
        {   
            copy_prev = copy;
            copy = copy -> next;
        }
        else
        {
            copy_prev -> next = copy -> next;
            free (copy->name);
            free(copy);
            puts("town removed");
            return;
        }
    }
    puts("element not in db");
    return;
}

void print_db(Town** db)
{
    int void_check = 1;
    Town* copy_db;
    Sorted_list* list = NULL;
    for(int i = 0; i < 256; i++)
    {
        if (db[i] != NULL)
        {
            void_check = 0;
            copy_db = db[i];
            while (copy_db != NULL)
            {
                Sorted_list* elem = (Sorted_list*) malloc(sizeof(Sorted_list));
                elem -> town = copy_db;
                elem -> next = NULL;
                if(list == NULL)
                {
                    list = elem;
                }
                else if (strcmp(elem -> town -> name, list -> town -> name) < 0)
                {
                    elem -> next = list;
                    list = elem;
                }
                else
                {
                    Sorted_list* copy_list = list;
                    while (copy_list -> next != NULL)
                    {
                        if (strcmp(elem -> town -> name, copy_list -> next -> town -> name) < 0)
                        {
                            elem -> next = copy_list -> next;
                            copy_list -> next = elem;
                            break;
                        }
                        copy_list = copy_list -> next;
                    }
                    if (copy_list -> next == NULL)
                    {
                        copy_list -> next = elem;
                    }
                }
                copy_db = copy_db->next;
            }
        }
    }
    if (void_check)
    {
        puts("db is void");
    }
    else
    {
        Sorted_list* copy;
        while (list != NULL)
        {
            printf("Town: %s, population: %llu\n", list -> town -> name,  list -> town -> population);
            copy = list;
            list = list -> next;
            free(copy);
        }
    }
}