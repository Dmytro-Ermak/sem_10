#include "tree.h"

int alph_check(char* first, char* second, int not_reverce) {
    while (*first == *second) {
        if (*first == '\0') { 
            return 0;
        }
		*first++;
		*second++;
    } 
    if (*first < *second) {
        return -1 * not_reverce;
    }
    return 1 * not_reverce;
}