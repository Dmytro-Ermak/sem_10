#include "tree.h"
#include "strings.h"


int main(int args, char* argv[]) {
    char* filename;
    int not_reverce;
    if (args == 2)
    {
        filename = argv[1];
        not_reverce = 1;
    }
    else if (args == 4)
    {
       if (!alph_check("-o", argv[1], 1))
       {
            if (!alph_check("asc", argv[2], 1))
            {
                not_reverce = 1;   
            }
            else if (!alph_check("desc", argv[2], 1))
            {
                not_reverce = -1;  
            }
            else
            {
                puts("Error args");
                return 1;
            }
            filename = argv[3];
       }
       else if (!alph_check("-o", argv[2], 1))
       {
            if (!alph_check("asc", argv[3], 1))
            {
                not_reverce = 1;
            }
            else if (!alph_check("desc", argv[3], 1))
            {
                not_reverce = -1;  
            }
            else
            {
                puts("Error args");
                return 1;
            }
            filename = argv[1];
       } 
       else
       {
        puts("Error args");
        return 1;
       }
    }
    else 
    {
        puts("Error args");
        return 1;
    }  
    Tree* tree = NULL;
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        puts("ERROR: file not read");
        return 1;
    }
    tree = fileread(file, tree, not_reverce);
    fclose(file);
    tree_output(tree);
    return 0;
}