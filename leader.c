#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * main: generates randon number from 0 to number of members
 *       then the member is chosen from the array
 *       if number chosen == \0 then a number number is chosen.
 *
 *return: 0
 */

int main (void){
	
	int random_number;
	int number_of_members;
	
	
	/*
	 *replace member _1 ... with the names of your members
	 */
	
	char *member[] = {"member_1", "member_2", "member_3", "member_4", "member_5", "member_6", "member_7", "\0"};

	srand(time(NULL));

	number_of_members = sizeof(*member)/sizeof(*member[0]);
	random_number = rand() % number_of_members;

	while (random_number == number_of_members - 1)
		random_number = rand() % number_of_members;	

	printf("%s will lead the discussion \n", member[random_number]);
	return 0;
}
