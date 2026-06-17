#include <stdio.h>
#include "utils.h"
#include "fen.h"
#include "bitboard.h"
#include "board.h"

void loadFen(U64 bitboard[12], char sFen[]){

    for(int i = 0; i < 12; i++)
    {
        bitboard[i] = 0ULL;
    }

    int x=0;
    for (int i = 0; sFen[i] != '\0'; i++)
    {
        if (sFen[i] == ' ')
        {
            break;
        }

        switch (sFen[i])
        {

        case 'r':
            setPiece(bitboard[R], x);
            x++;
            break;
        case 'n':
            setPiece(bitboard[N], x);
            x++;
            break;
        case 'b':
            setPiece(bitboard[B], x);
            x++;
            break;
        case 'q':
            setPiece(bitboard[Q], x);
            x++;
            break;
        case 'k':
            setPiece(bitboard[K], x);
            x++;
            break;
        case 'p':
            setPiece(bitboard[P], x);
            x++;
            break;
        case 'R':
            setPiece(bitboard[r], x);
            x++;
            break;
        case 'N':   
            setPiece(bitboard[n], x);
            x++;
            break;
        case 'B':
            setPiece(bitboard[b], x);
            x++;
            break;
        case 'Q':
            setPiece(bitboard[q], x);  
            x++;
            break;
        case 'K':
            setPiece(bitboard[k], x);
            x++;
            break;
        case 'P':
            setPiece(bitboard[p], x);
            x++;
            break;
        case '/':
            break;
        default:
            if (sFen[i] >= '1' && sFen[i] <= '8')
            {
                x += sFen[i] - '0';
            }
            break;
        }

    }
    if(x != 64)
    {
        printf("wrogn fen\n");
    }
    
    


}
