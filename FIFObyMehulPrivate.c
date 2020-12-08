#include<stdio.h>

int numberOfFrames;							//number of frames
int numberOfPages;							//number of pages
int HIT = -1,FAULT = -1;     				// To check if Hit occure
int numberOfHITs = 0,numberOfFAULTs = 0;

void main()
{
	int i,j;
	printf("\nENTER NUMBER OF FRAMES : ");
	scanf("%d",&numberOfFrames);
	int farmesBuffer[numberOfFrames];		//Array of FRAMES
	int index = 0;							//Index for FRAMES Array

	for(i=0;i<numberOfFrames;i++)
	{
		farmesBuffer[i] = -1; 				//Set as -1 because there can exist a PAGE with Number 0. Aim is to assign default value as minimum as possible minimum
	}

	printf("\nENTER NUMBER OF PAGES  : ");
	scanf("%d",&numberOfPages);
	int pageArray[numberOfPages];			//Array of PAGES

	printf("\nENTER THE PAGES  : ");
	for(i=0;i<numberOfPages;i++)
	{
		scanf("%d",&pageArray[i]);
	}

	for(i=0;i<numberOfPages;i++)	//STEP 1 : Travers Through EVERY PAGE. For every page, check if its HIT or FAULT
	{
		for(j=0;j<numberOfFrames;j++)	//STEP 2 : For every page, Travers through every FRAME
		{
			if(pageArray[i] == farmesBuffer[j])	// STEP 3 : Check if any such PAGE already exixts
			{
				farmesBuffer[j] = pageArray[i];		// STEP 3.1 : if yes just input that page number
				HIT = 1;							// STEP 3.2 : set HIT = 1 to avoid FAULT code below
				numberOfHITs++;
				break;
			}
		}

		if(HIT != 1)			//STEP 4 : if HIT != 1, then its FAULT for sure.
		{
			farmesBuffer[index] = pageArray[i];		//STEP 4.1 : Input data at index
			index = (index + 1) % numberOfFrames;	//STEP 4.2 : Make sure index doesnt go out of bound
			numberOfFAULTs++;
		}
		HIT = 0;
	}

	printf("\nIN FIFO ALGORITHM : HITs = %d --- FAULTs = %d ",numberOfHITs,numberOfFAULTs);
}
