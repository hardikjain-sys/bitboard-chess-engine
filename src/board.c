#include <stdio.h>
#include "board.h"
#include "utils.h"


void printBoard(U64 bitboard){

    for (int i = 0; i < 8; i++)
    {
    printf("\n");

        for (int j = 0; j < 8; j++)
        {
            int square = i*8+j;

            if (j == 0)
            {
                printf("  %d    ", 8 - i);
            }
            
            
            printf("%d ", isBit(bitboard,square) ? 1 : 0);
        }
        printf("\n");
    }

    printf("\n\n       a b c d e f g h \n\n\n");
    // printf("%llud\n\n", bitboard);
}

void printOccupied(U64 bitboard[12])
{
    U64 fullboard = 0ULL;
    for (int i = 0; i < 12; i++)
    {
        fullboard |= bitboard[i];
    }
    printBoard(fullboard);
}

void printFull(U64 bitboard[12])
{
    
    for (int i = 0; i < 8; i++)
    {
    printf("\n");

        for (int j = 0; j < 8; j++)
        {
            int square = i*8+j;

            if (j == 0)
            {
                printf("  %d    ", 8 - i);
            }
            

            // if(isBit(bitboard[P], square)){
            //     printf("P ");
            // }
            // else if(isBit(bitboard[R], square)){
            //     printf("R ");
            // }
            // else if(isBit(bitboard[N], square)){
            //     printf("N ");
            // }
            // else if(isBit(bitboard[B], square)){
            //     printf("B ");
            // }
            // else if(isBit(bitboard[K], square)){
            //     printf("K ");
            // }
            // else if(isBit(bitboard[Q], square)){
            //     printf("Q ");
            // }
            // else if(isBit(bitboard[p], square)){
            //     printf("p ");
            // }
            // else if(isBit(bitboard[r], square)){
            //     printf("r ");
            // }
            // else if(isBit(bitboard[n], square)){
            //     printf("n ");
            // }
            // else if(isBit(bitboard[b], square)){
            //     printf("b ");
            // }
            // else if(isBit(bitboard[k], square)){
            //     printf("k ");
            // }
            //  else if(isBit(bitboard[q], square)){
            //     printf("q ");
            // }
            //  else{
            //      printf(". ");
            //  }


            if(isBit(bitboard[K], square)){
    printf("♔ ");
}
else if(isBit(bitboard[Q], square)){
    printf("♕ ");
}
else if(isBit(bitboard[R], square)){
    printf("♖ ");
}
else if(isBit(bitboard[B], square)){
    printf("♗ ");
}
else if(isBit(bitboard[N], square)){
    printf("♘ ");
}
else if(isBit(bitboard[P], square)){
    printf("♙ ");
}
else if(isBit(bitboard[k], square)){
    printf("♚ ");
}
else if(isBit(bitboard[q], square)){
    printf("♛ ");
}
else if(isBit(bitboard[r], square)){
    printf("♜ ");
}
else if(isBit(bitboard[b], square)){
    printf("♝ ");
}
else if(isBit(bitboard[n], square)){
    printf("♞ ");
}
else if(isBit(bitboard[p], square)){
    printf("♟ ");
}
else{
    printf(". ");
}


























        }
        printf("\n");
    }

    printf("\n\n       a b c d e f g h \n\n\n");
    
    

}


void movePiece(U64 bitboard[12], int pFrom, int pTo){

    for (int i = 0; i < 12; i++)
    {
        if(isBit(bitboard[i], pFrom)){
            setPiece(bitboard[i],pTo);
            removePiece(bitboard[i],pFrom);
            printFull(bitboard);
            return;
        }
    }
}
