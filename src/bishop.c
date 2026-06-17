#include <stdio.h>
#include "utils.h"
#include "bishop.h"
#include "bitboard.h"
#include "board.h"


void bishopMoves(U64 bitboard[12], int x, int t)
{
    U64 bishop = 1ULL << x;
    U64 attacks = 0ULL;

    U64 same, diff;

    if (isBit(bitboard[B], x))
    {
        same = bitboard[P] | bitboard[R] | bitboard[N] |
               bitboard[B] | bitboard[K] | bitboard[Q];

        diff = bitboard[p] | bitboard[r] | bitboard[n] |
               bitboard[b] | bitboard[k] | bitboard[q];
    }
    else if (isBit(bitboard[b], x))
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
    U64 c;

    c = bishop;
    while (c & notHFile)
    {
        c = c >> 7;
        attacks |= c;

        if (c & occupied)
            break;
    }

    c = bishop;
    while (c & notAFile)
    {
        c = c >> 9;
        attacks |= c;

        if (c & occupied)
            break;
    }

    c = bishop;
    while (c & notHFile)
    {
        c = c << 9;
        attacks |= c;

        if (c & occupied)
            break;
    }

    c = bishop;
    while (c & notAFile)
    {
        c = c << 7;
        attacks |= c;

        if (c & occupied)
            break;
    }

    attacks &= ~same;

    U64 kill = attacks & diff;
    U64 onlyMove = attacks & ~diff;

    printBoard(attacks);

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