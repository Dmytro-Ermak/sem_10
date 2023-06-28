#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int count;
    char* string; 
    struct tree* parent;
    struct tree* left;
    struct tree* right;
} Tree;

Tree* add_str(Tree* tree_copy, char* string, int not_reverce);
void tree_output(Tree* tree);
Tree* fileread(FILE* file, Tree* tree, int not_reverce);