#include "struct_db.h"

int main() {
    Town** db;
    db = (Town**) malloc(sizeof(Town*) * LEN);
    for (int i = 0; i < LEN; i++)
    {
        db[i] = NULL;
    }
    while (1)
    {
        puts("Input symbol-command: 1: add town, 2: remove town, 3: print db, 4: exit");
        char command = get_command();
        switch (command)
        {
            case '1':
                add_town(&db);
                break;
            case '2':
                remove_town(&db);
                break;
            case '3':
                print_db(db);
                break;
            case '4':
                return 0;
            default:
                puts("Wrong command");
        }
    }
}