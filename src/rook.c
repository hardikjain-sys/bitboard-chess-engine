#include <stdio.h>
#include "utils.h"
#include "rook.h"
#include "bitboard.h"
#include "board.h"


void rookMoves(U64 bitboard[12], int x, int t)
{
    U64 rook = 1ULL << x;
    U64 canMove = 0ULL;

    U64 same, diff;

    if (isBit(bitboard[R], x))
    {
        same = bitboard[P] | bitboard[R] | bitboard[N] |
               bitboard[B] | bitboard[K] | bitboard[Q];

        diff = bitboard[p] | bitboard[r] | bitboard[n] |
               bitboard[b] | bitboard[k] | bitboard[q];
    }
    else if (isBit(bitboard[r], x))
    {
        same = bitboard[p] | bitboard[r] | bitboard[n] |
               bitboard[b] | bitboard[k] | bitboard[q];

        diff = bitboard[P] | bitboard[R] | bitboard[N] |
               bitboard[B] | bitboard[K] | bitboard[Q];
    }
    else if(t)
    {
        if(isBit(bitboard[Q], x))
        {
            same = bitboard[P] | bitboard[R] | bitboard[N] |
               bitboard[B] | bitboard[K] | bitboard[Q];

            diff = bitboard[p] | bitboard[r] | bitboard[n] |
               bitboard[b] | bitboard[k] | bitboard[q];
        }
        else if (isBit(bitboard[q], x))
        {
           same = bitboard[p] | bitboard[r] | bitboard[n] |
               bitboard[b] | bitboard[k] | bitboard[q];

        diff = bitboard[P] | bitboard[R] | bitboard[N] |
               bitboard[B] | bitboard[K] | bitboard[Q];
        }
        else
        {
            printf("illegal move"); return;
        }
        
    }
    else
    {
        printf("illegal move\n");
        return;
    }

    U64 occupied = same | diff;
    U64 c = rook;

    
    while (c >> 8)
    {
        c >>= 8;
        canMove |= c;

        if (c & occupied)
            break;
    }

    c = rook;
    while (c << 8)
    {
        c <<= 8;
        canMove |= c;

        if (c & occupied)
            break;
    }

    c = rook;
    while (c & notHFile)
    {
        c = (c & notHFile) << 1;
        canMove |= c;

        if (c & occupied)
            break;
    }
    c = rook;
    while (c & notAFile)
    {
        c = (c & notAFile) >> 1;
        canMove |= c;

        if (c & occupied)
            break;
    }

    canMove &= ~same;

    U64 kill = canMove & diff;
    U64 onlyMove = canMove & ~diff;

    printBoard(canMove);

    for (int sq = 0; sq < 64; sq++)
    {
        if (kill & (1ULL << sq))
        {
            printf("killed ");
            ps(sq);
        }

        if (onlyMove & (1ULL << sq))
        {
            printf("moved ");
            ps(sq);
        }
    }
}
