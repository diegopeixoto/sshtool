#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "database.h"
#include "actions.h"

void print_centered(const char *text) {
    int term_width = 80; // Assuming a default terminal width
    int text_width = strlen(text);
    int left_padding = (term_width - text_width) / 2;
    printf("%*s\n", left_padding + text_width, text);
}

int main() {
    char ascii_logo[] = "     _     _              _\n ___ ___| |__ | |_ ___   ___ | |\n/ __/ __| '_ \\| __/ _ \\ / _ \\| |\n\\__ \\__ \\ | | | || (_) | (_) | |\n|___/___/_| |_|\\__\\___/ \\___/|_|\n";
    char copyright_text[] = "(C) 2023 - 2024 Diego Peixoto - All rights reserved. github.com/diegopeixoto";

    print_centered(ascii_logo);
    print_centered(copyright_text);
    load_db();

    while (1) {
        printf("1. Connect to Host\n2. Create\n3. Advanced\n4. Exit\n");
        printf("Choose option [1]: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                connect_to_host();
                break;
            case 2:
                while (1) {
                    printf(">>> Create:\n");
                    printf("1. Add Host\n2. Add User\n3. Add Key\n4. Back to Main Menu\n");
                    printf("Choose option: ");
                    int sub_choice;
                    scanf("%d", &sub_choice);
                    if (sub_choice == 1) add_host();
                    else if (sub_choice == 2) add_user();
                    else if (sub_choice == 3) add_key();
                    else if (sub_choice == 4) break;
                    else printf("Invalid choice, please try again.\n");
                }
                break;
            case 3:
                advanced_submenu();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
