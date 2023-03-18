#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_MEMBERS 50

/*
 * Main function: prompts user to enter names of members,
 * puts the names into an array, chooses a random member from
 * the array, and prints their name as the leader of the discussion.
 *
 * Returns: 0 if the program runs successfully.
 */

int main(void) {
    // Declare variables
    int random_number;
    int number_of_members = 0;
    char *member[MAX_MEMBERS];
    char name[100];

    // Prompt user to enter names of members
    printf("Enter names of members (up to %d, enter 'done' when finished):\n", MAX_MEMBERS);
    do {
        printf("Member %d: ", number_of_members + 1);
        scanf("%s", name);
        if (strcmp(name, "done") != 0) {
            // Add name to array if it's not "done"
            member[number_of_members] = malloc(strlen(name) + 1);
            strcpy(member[number_of_members], name);
            number_of_members++;
        }
    } while (strcmp(name, "done") != 0 && number_of_members < MAX_MEMBERS);

    if (number_of_members == 0) {
        // If no members were entered, exit the program
        printf("No members entered, exiting program.\n");
        return 0;
    }

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Choose a random number between 0 and the number of members
    random_number = rand() % number_of_members;

    // Print the name of the chosen member as the leader of the discussion
    printf("%s will lead the discussion\n", member[random_number]);

    // Free memory allocated for member names
    for (int i = 0; i < number_of_members; i++) {
        free(member[i]);
    }

    // Return 0 to indicate successful program completion
    return 0;
}

