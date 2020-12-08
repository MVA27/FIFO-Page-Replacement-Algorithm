#include<stdio.h>

int numberOfFrames;
int numberOfPages;
int HIT = -1,FAULT = -1;
int numberOfHITs = 0,numberOfFAULTs = 0;

void main()
{
	int i,j;
	printf("\nENTER NUMBER OF FRAMES : ");
	scanf("%d",&numberOfFrames);
	int farmesBuffer[numberOfFrames];
	int index = 0;

	for(i=0;i<numberOfFrames;i++)
	{
		farmesBuffer[i] = -1;
	}

	printf("\nENTER NUMBER OF PAGES  : ");
	scanf("%d",&numberOfPages);
	int pageArray[numberOfPages];

	printf("\nENTER THE PAGES  : ");
	for(i=0;i<numberOfPages;i++)
	{
		scanf("%d",&pageArray[i]);
	}

	for(i=0;i<numberOfPages;i++)
	{
		for(j=0;j<numberOfFrames;j++)
		{
			if(pageArray[i] == farmesBuffer[j])
			{
				numberOfHITs++;
				HIT = 1;
				farmesBuffer[j] = pageArray[i];
				break;
			}
		}

		if(HIT != 1)
		{
			farmesBuffer[index] = pageArray[i];
			index = (index + 1) % numberOfFrames;
			numberOfFAULTs++;
		}
		HIT = 0;
	}

	printf("\nIN FIFO ALGORITHM : HITs = %d --- FAULTs = %d ",numberOfHITs,numberOfFAULTs);
}
