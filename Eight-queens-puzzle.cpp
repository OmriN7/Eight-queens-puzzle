#include "stdafx.h"
#include "stdio.h"
#include "string.h"

void Placer();
void Qualifier();

int Board[8][8];
int Row;
int Lane;
int qual;
int i;
int d;
int z;
int QueensNo;
int Queens[8][2];
int successfulVariations;
int p;


void setUp() //Resets the entire board so that all of the values on the board will be set to 0
{
for(Row=0;Row<8;Row++)
	{
 		for(Lane=0;Lane<8;Lane++)
		{
		Board[Row][Lane]=0;
		}
	}
Row=0;
z=0;
Lane=-1;
}

void Cleaner()
{
	for(;;Lane--)
	{
			if(Board[Row][Lane]==1)
			{
				z=Lane;
				z++;
				Board[Row][Lane]=0;
				QueensNo--;
				if(z==8)
				{
					Row--;
					for(;;Lane--)
					{
						if(Board[Row][Lane]==1)
						{
							z=Lane;
							z++;
							Board[Row][Lane]=0;
							QueensNo--;
							return;
						}
					}
				}
				return;
			}
	}
}

void Placer()
{
	if(z==8)
	{
		Row--;
		Cleaner();
	}
	if(Lane==7)
	{
		Row++;
		Lane=-1;
	}
	Lane++;
	Board[Row][Lane]=1;
	p++;
	return;
} 




void Qualifier()
{
for(qual=1;Lane+qual<8;qual++) //Checks Right >
	{
	i=Lane+qual;
	if (Board[Row][i]==1)
		{
		Board[Row][Lane]=0;
		z++;
		return;
		}
	}

for(qual=1;Lane-qual>-1;qual++) //Checks Left <
	{
	i=Lane-qual;
	if (Board[Row][i]==1)
		{
		Board[Row][Lane]=0;
		z++;
		return;
		}
	}

for(qual=1;Row+qual<8;qual++) //Checks Down v
	{
	i=Row+qual; 
	if (Board[i][Lane]==1)
		{
		Board[Row][Lane]=0;
		z++;
		return;
		}
	}

for(qual=1;Row-qual>-1;qual++) //Checks Up ^
	{
	i=Row-qual;
	if (Board[i][Lane]==1)
		{
		Board[Row][Lane]=0;
		z++;
		return;
		}
	}

for(qual=1;Row-qual>-1 && Lane+qual<8;qual++) //Checks Up Right Diagonal ^>
	{
	i=Lane+qual;
	d=Row-qual;
	if (Board[d][i]==1)
		{
		Board[Row][Lane]=0;
		z++;
		return;
		}
	}

for(qual=1;Row-qual>-1 && Lane-qual>-1;qual++) //Checks Up Left Diagonal ^<
	{
	i=Lane-qual;
	d=Row-qual;
	if (Board[d][i]==1)
		{
		Board[Row][Lane]=0;
		z++;
		return;
		}
	}

for(qual=1;Row+qual<8 && Lane+qual<8;qual++) //Checks Down Right Diagonal v>
	{
	i=Lane+qual;
	d=Row+qual;
	if (Board[d][i]==1)
		{
		Board[Row][Lane]=0;
		z++;
		return;
		}
	}

for(qual=1;Row+qual<8 && Lane-qual>-1;qual++) //Checks Down Left Diagonal v<
	{
	i=Lane-qual;
	d=Row+qual;
	if (Board[d][i]==1)
		{
		Board[Row][Lane]=0;
		z++;
		return;
		}
	}

Queens[Row][0]=Row;
Queens[Row][1]=Lane;
QueensNo++;
z=0;

//FOR DEBUGGING
if(QueensNo==8)
{
	successfulVariations++;
	Board[Row][Lane]=0;
	QueensNo--;
	z=Lane+1;
	printf("==== Combination Number %d ====\n",successfulVariations);
	 
	for(d=0;d<8;d++)
	{
		printf("\n");
		for(i=0;i<8;i++)
		{
			if(Queens[d][0]==d && Queens[d][1]==i)
			{
				printf("X ");
			}
			else
			{
				printf("O ");
			}
		}
	}

	printf("\n\n\n");
}
else
{
	Lane=7;
}
return;
}


void main ()
{
	setUp();
	for(;;)
	{
		Placer();
		Qualifier();
	}
}


