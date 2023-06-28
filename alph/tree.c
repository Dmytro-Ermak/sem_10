#include "tree.h"
#include "strings.h"

Tree* add_str(Tree* tree_copy, char* string, int not_reverce) {
    //printf("%s\n", string);
    if (tree_copy == NULL) {
        tree_copy = (Tree*) malloc(sizeof(Tree));
        tree_copy -> string = string;
        tree_copy -> count = 1;
        tree_copy -> parent = NULL;
        tree_copy -> left = NULL;
        tree_copy -> right = NULL;
        //putchar('\n');
        return tree_copy;
    }
    Tree* tree = tree_copy;
    while (1) {
        int i = alph_check(string, tree -> string, not_reverce);
        //printf("%s %s %i\n", string, tree -> string, i);
        if (i == 0) {
            tree -> count++;
            //putchar('\n');
            return tree_copy;
        }
        else if (i == -1) {
            if (tree -> left == NULL) {
                tree -> left = (Tree*) malloc(sizeof(Tree));
                tree -> left -> string = string;
                tree -> left -> count = 1;
                tree -> left -> parent = tree; 
                tree -> left -> left = NULL;
                tree -> left -> right = NULL;
                //putchar('\n');
                return tree_copy;
            }
            else {
                tree = tree -> left;
            }
        }
        else {
            if (tree -> right == NULL) {
                tree -> right = (Tree*) malloc(sizeof(Tree));
                tree -> right -> string = string;
                tree -> right -> count = 1;
                tree -> right -> parent = tree;
                tree -> right -> left = NULL;
                tree -> right -> right = NULL;
                //putchar('\n');
                return tree_copy;
            }
            else {
                tree = tree -> right;
            }
        }
    }
}

void tree_output(Tree* tree) {
    while (tree -> parent != NULL || tree -> left != NULL || tree -> right != NULL) {
        if (tree -> left == NULL) {
            if (tree -> right == NULL) {
                if (tree -> string != NULL) {
                    printf("%s %i\n", tree -> string, tree -> count);
                    free(tree -> string);
                    tree -> string = NULL;
                }
                tree = tree -> parent;
                free(tree -> left);
                tree -> left = NULL;
            }
            else {
                if (tree -> string != NULL) {
                    printf("%s %i\n", tree -> string, tree -> count);
                    free(tree -> string);
                    tree -> string = NULL;
                }
                tree = tree -> right;
                if (tree -> left == NULL) {
                    if (tree -> string != NULL) {
                        printf("%s %i\n", tree -> string, tree -> count);
                        free(tree -> string);
                        tree -> string = NULL;
                    }
                    if (tree -> right == NULL) {
                        tree = tree -> parent;
                        free(tree -> right);
                        tree -> right = NULL;
                    }
                }
            }
        }
        else {
            tree = tree -> left;
        }
    }
    if (tree -> string != NULL) {
        printf("%s %i\n", tree -> string, tree -> count);
        free(tree -> string);
        tree -> string = NULL;
    }
}

Tree* fileread(FILE* file, Tree* tree, int not_reverce) {
    char s;
    char* str = (char*) calloc(0, sizeof(char));
    int i = 0;
    while ((s = getc(file)) != EOF) {    
        if (s != '\n') {
            str = (char*) realloc(str, (i + 2) * sizeof(char));
            str[i++] = s;
            str[i] = '\0';
        }
        else {
            tree = add_str(tree, str, not_reverce);
            str = NULL;
            char* str = (char*) calloc(0, sizeof(char));
            i = 0;
        }
    }
    if (i) {
        tree = add_str(tree, str, not_reverce);
    }
    else {
        free(str);
    }
    return tree;
}
