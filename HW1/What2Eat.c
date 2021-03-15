#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{

	// FIRST ROUND

	int numberOfPeople;
	int meal[5];				// THIS CHANGES THE SIZE OF MENU
	int threshold = 5;			// THRESHOLD
	
	// Initializing the menu for first round
	char firstRound[5][14];
	strcpy(firstRound[0], "Kebab");
	strcpy(firstRound[1], "Burger");
	strcpy(firstRound[2], "Pasta");
	strcpy(firstRound[3], "Lahmacun");
	strcpy(firstRound[4], "Salad");

	// Initialize the array of meal
	for(int i = 0; i < 5; i++)
		meal[i] = 0;

	printf("FIRST ROUND\n");
	printf("Enter number of people\n");
	scanf("%d", &numberOfPeople);


	for(int i = 0; i < numberOfPeople; i++)
	{
		printf("For User %d\n", (i + 1));
		// Getting preferences
		for(int k = 0; k < sizeof(meal) / sizeof(meal[0]); k++)
		{
			// Prints the menu
			for(int i = 0; i < sizeof(meal) / sizeof(meal[0]); i++)
			{
				printf("%d - %s\n", (i + 1), firstRound[i]);
			}
			
		
			int preference;
			printf("Enter you preference %d : \n", (k + 1));
			scanf("%d", &preference);

			// Calculating preferences
			meal[preference - 1] += (5 - k);
		}
		printf("\n\n\n");
	}

	printf("First round Results : \n");
	bool passThreshold = false;	
	
	// Printing preferences -> results
	for(int i = 0; i < sizeof(meal) / sizeof(meal[0]); i++)
	{
		if(meal[i] > threshold)
			passThreshold = true;
		printf("%s - %d\n", firstRound[i], meal[i]);
	}
	
	printf("\n");
	
	if(!passThreshold) 
	{
	 	printf("You are eating at home/dorm today\n");
	 	exit(0);
	}
	
	// SECOND ROUND
	
	int tempIndex = 0;
	int aboveThreshold = 0;
	
	
	// Calculating meals above threshold
	for(int i = 0; i < sizeof(meal) / sizeof(meal[0]); i++)
		if(meal[i] > threshold)
			aboveThreshold++;
	
	printf("Above threshold %d\n\n", aboveThreshold);
	

			
	int food[aboveThreshold];
	
	// Initialize the array of food
	for(int i = 0; i < aboveThreshold; i++)
		food[i] = 0;
	
	// Initializing the menu for second round
	char secondRound[aboveThreshold][14];
	
	for(int i = 0; i < sizeof(meal) / sizeof(meal[0]); i++)
		if(meal[i] > threshold)
			strcpy(secondRound[tempIndex++], firstRound[i]);
	
	
	if(aboveThreshold == 1) {
		printf("You are eating %s\n", secondRound[0]);
		exit(0);
	}
	printf("SECOND ROUND\n");
	
	
	for(int i = 0; i < numberOfPeople; i++)
	{
		printf("For User %d\n", (i + 1));
		// Getting preferences
		for(int k = 0; k < aboveThreshold; k++)
		{
		
			// Just prints the menu
			for(int i = 0; i < sizeof(food) / sizeof(food[0]); i++)
			{
				printf("%d - %s\n", (i + 1), firstRound[i]);
			}
			
			
			int preference;
			printf("Enter you preference %d : \n", (k + 1));
			scanf("%d", &preference);

			// Calculating preferences
			food[preference - 1] += (5 - k);
		}
		printf("\n\n\n");
	}

	printf("Second round Results : \n");
	
	int winner = 0;
	int winnerIndex = 0;

	// Printing preferences
	for(int i = 0; i < aboveThreshold; i++)
	{
		if(food[i] > winner) {
			winner = food[i];
			winnerIndex = i;
		}
		printf("%s - %d\n", secondRound[i],  food[i]);
	}
	printf("\n");
	
	printf("Winner points is %d\n", winner);
	printf("You are eating %s\n", secondRound[winnerIndex]);

	return 0;
}
