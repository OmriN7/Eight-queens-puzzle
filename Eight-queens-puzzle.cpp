
//Function Commenting Format
/*/////////////////////////////////////////////////////////////////////
* Name:
*
* Inputs:
*       // Parameters //
*
*       // Variables //
*
*
* Outputs:
*       // Return Value //
*
* Description:
*
*/


///HEADER FILES
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdio.h> // scanf
#include <conio.h> // getch
#include <stdlib.h> // malloc, free
#include <chrono> // high_resolution_clock


///DEFINES
//////////////////////////////////////////////////////////////////////
using namespace std;

#define ROW 0 //x of the board
#define COLUMN 1 //y of the board

#define VERTICAL 0
#define DIAGONALTLBR 1
#define DIAGONALTRBL 2

//#define DEBUG 1



///MACROS
//////////////////////////////////////////////////////////////////////
#define TestVertical(y1, y2)  ((y1) == (y2) ? (true) : (false))
#define TestDiagonalLeft(x1, y1, x2, y2)  ((y1-x1) == (y2-x2) ? (true) : (false))
#define TestDiagonalRight(x1, y1, x2, y2)  ((y1+x1) == (y2+x2) ? (true) : (false))




///FUNCTION PROTOTYPES
///////////////////////////////////////////////////////////////////////
static bool RemoveQueen(int queensCoordinate[],  int* possibleColumn, int* possibleRow, int* queensPlacedDown);
static void PrintQueens(int queensCoordinate[], int boardSize, int queensPlacedDown);
static void PushSequence(int boardSize, int* possibleColumn, int* possibleRow);
static int EightQueensPuzzle(int boardSize);



///Function Notes
/*/////////////////////////////////////////////////////////////////////
* Name: int main()
*
* Inputs:
*       // Parameters //
*       N/A
*
*       // Variables //
*       int boardSize       The size of the board for the puzzle.
*
*
* Outputs:
*       // Return Value //
*       N/A
  *
*
* Description:
*       main function. Prompts the user for the board size, calls
*       EightQueensPuzzle function and shows the amount of permutations
*       that are possible with the given board size and then asks the user
*       to press any button to exit the program.
*
*/
int main()
{

    int boardSize = 8;
    /* WORK IN PROGRESS
        //Asks the user for a board size and saves that variable inside int boardSize.
        cout << "Please give me a size for the board: ";
        scanf("%d", &boardSize);
    */

    #ifdef DEBUG
        cout << "The program is running in debug mode.\n";
    #endif
	auto start_time = chrono::high_resolution_clock::now();


    //Calculates and shows the user the amount of permutations that are possible with the given board size.
    cout << "You can have " << EightQueensPuzzle(boardSize) << " possible permutations for a square board that's " << boardSize << " tiles large.\n\n";



	auto end_time = chrono::high_resolution_clock::now();
	cout << "It took the program " << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << " microseconds to run.\n\n";


    //Asks the user to press any key to exit the program.
    cout << "\nPress any key to exit.";
    _getch();

    //End of program.
    return 0;
}




///Function Notes
/*/////////////////////////////////////////////////////////////////////
* Name: bool RemoveQueen(int queensCoordinate[][2],  int* possibleColumn, int* possibleRow, int* queensPlacedDown)
*
* Inputs:
*       // Parameters //
*       int queensCoordinate[][2]       The list of all the queens.
*       int* possibleColumn             Pointer to possibleColumn in the original 'EightQueensPuzzle' function
*       int* possibleRow                Pointer to possibleRow in the original 'EightQueensPuzzle' function
*       int queensPlacedDown            The amount of queens that were placed down.
*
*       // Variables //
*       N/A
*
*
* Outputs:
*       // Return Value //
*       If the last piece of the puzzle has been removed and the program should end.
*
*
* Description:
*       Moves of the coordinates of the queen the program is about to remove to the
*       possibleColumn and possibleRow variables and then removes the queen from the array.
*/
static bool RemoveQueen(int queensCoordinate[],  int* possibleColumn, int* possibleRow, int* queensPlacedDown)
{

    (*possibleRow) = ((*queensPlacedDown)-1);

    (*possibleColumn) = queensCoordinate[((*queensPlacedDown)-1)];

    if((*possibleRow) == 0 && (*possibleColumn) == 7)
    {
        return true;
    }

    (*queensPlacedDown)--;

    return false;
}


///Function Notes
/*/////////////////////////////////////////////////////////////////////
* Name: void PrintQueens(int queensCoordinate[][2], int boardSize)
*
* Inputs:
*       // Parameters //
*       int queensCoordinate[][2]       The list of all the queens.
*       int boardSize                   The amount of queens that were placed down.
*
*       // Variables //
*       N/A
*
*
* Outputs:
*       // Return Value //
*       If the last piece of the puzzle has been removed and the program should end.
*
*
* Description:
*       Moves of the coordinates of the queen the program is about to remove to the
*       possibleColumn and possibleRow variables and then removes the queen from the array.
*/
static void PrintQueens(int queensCoordinate[], int boardSize, int queensPlacedDown)
{
    for(int row = 0; row < boardSize; row++)
    {
        for(int column = 0; column < boardSize; column++)
        {
            if(row < queensPlacedDown)
            {
                if(queensCoordinate[row] == column)
                {
                    cout << "1 ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << '\n';
    }
    cout << '\n';
}


///Function Notes
/*/////////////////////////////////////////////////////////////////////
* Name: void PushSequence( int boardSize, int* possibleColumn, int* possibleRow)
*
* Inputs:
*       // Parameters //
*       int boardSize                   The size of the board in tiles.
*       int* possibleColumn             Pointer to possibleColumn in the original 'EightQueensPuzzle' function
*       int* possibleRow                Pointer to possibleRow in the original 'EightQueensPuzzle' function
*
*       // Variables //
*       N/A
*
*
* Outputs:
*       // Return Value //
*       N/A
*
*
* Description:
*       Pushes the the possibleColumn and possibleRow a single tile forward on the board,
*       ensuring the value doesn't equate to a position that's off of the board.
*/
static void PushSequence(int boardSize, int* possibleColumn, int* possibleRow)
{
    (*possibleColumn)++;
    if((*possibleColumn) == boardSize)
    {
        (*possibleColumn) = 0;
        (*possibleRow)++;

        //I originally thought RemoveQueen should be called here but the
        //programs works when I don't include so I must've overthought the
        //problem. I kept the code here for future reference in case I was
        //right.

        /*
        if((*possibleRow) == boardSize)
        {
            //If the possibleRow is falling off the board.
            //RemoveQueen();
        }
        */
    }
}



///Function Notes
/*/////////////////////////////////////////////////////////////////////
* Name: int EightQueensPuzzle(int boardSize)
*
* Inputs:
*       // Parameters //
*       int boardSize                   The size of the board in tiles.
*                                       *NOTE* The board is a square.
*       // Variables //
*       N/A
*
*
* Outputs:
*       // Return Value //
*       The number of permutations that are possible on the board with
*       with the given board size.
*
*
* Description:
*       Receives a board size and calculates all of the possible permutations of
*       the amount of queens that can be placed on a board of that given size.
*
*/
static int EightQueensPuzzle(int boardSize)
{

    ///Make some sort of checker that checks that boardSize is an integer.

    ///Initializing the variables needed for this function
        //Array stack that keeps track of the coordinates of the queens


        int queensCoordinate[8]; ///Note that the array for the queens is static but in the future look into changing this into malloc

        ///Code for later
        //int* queensCoordinate = (int*) malloc (sizeof(int)*2*boardSize);


        //Number of successful possibilities of the queens being placed on the board.
        //This variable is also the return value of this function (if successful).
        int successsfulPossibilities = 0;

        //Keeps track of the amount of queePrintQueensns that were placed down.
        int queensPlacedDown = 0;


        //Used for checking if specific tiles can be used for placing the next queen or not.
        int testType;
        int possibleRow = 0;
        int possibleColumn = 0;

        //This will be set to true whenever
        bool everythingScanned = false;

    //Runs every single possibility until everything possible permutation has been simulated.
    while(!everythingScanned)
    {
        //Keep checking the potential row and column and see if they work
        while(possibleRow <= queensPlacedDown)
        {

            for(int QueensIndexScanner = 0; QueensIndexScanner < queensPlacedDown; QueensIndexScanner++)
            {
                //Check the queen vertically, diagonally to the left and diagonally to the right
                if((TestVertical(queensCoordinate[QueensIndexScanner],possibleColumn)) || (TestDiagonalLeft(queensCoordinate[QueensIndexScanner],QueensIndexScanner,possibleColumn,possibleRow)) || (TestDiagonalRight(queensCoordinate[QueensIndexScanner],QueensIndexScanner,possibleColumn,possibleRow)))
                {
                    //Current location is invalid
                    PushSequence(boardSize, &possibleColumn, &possibleRow);
                    QueensIndexScanner = -1;
                    continue;
                }
            }
            break;
        }

        //If the row is equal to the number of queens placed. This is a rule that has to be true for a permutation to work.
        if(queensPlacedDown == possibleRow)
        {
            //Add queen
            queensCoordinate[queensPlacedDown] = possibleColumn;
            queensPlacedDown++;

            possibleColumn = 7;
            PushSequence(boardSize, &possibleColumn, &possibleRow);

            //Register Queen and the remove the latest queen placed down and keep on searching
            if(queensPlacedDown == boardSize)
            {
                //Success! :D
                successsfulPossibilities++;


#ifdef DEBUG
                    cout << "Success! A possibility was found:\n";
                    PrintQueens(queensCoordinate, boardSize, queensPlacedDown);
                    cout << "\n";
#endif

                //Remove Queen
                everythingScanned = RemoveQueen(queensCoordinate, &possibleColumn, &possibleRow, &queensPlacedDown);
                PushSequence(boardSize, &possibleColumn, &possibleRow);
            }
        }
        //If it isn't then scrap the latest queen that was inserted to the array.
        else
        {
            everythingScanned = RemoveQueen(queensCoordinate, &possibleColumn, &possibleRow, &queensPlacedDown);
            PushSequence(boardSize, &possibleColumn, &possibleRow);
        }
    }

    return successsfulPossibilities;
}


