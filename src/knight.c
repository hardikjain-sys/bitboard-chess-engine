#include <stdio.h>
#include "utils.h"
#include "knight.h"
#include "bitboard.h"
#include "board.h"

void knightMoves(U64 bitboard[12], int x)
{
    U64 knight = 1ULL << x;

    U64 attacks = ((knight & notHFile)  << 17) | ((knight & notAFile)  << 15) | ((knight & notGHFile) << 10) | ((knight & notABFile) << 6 ) | ((knight & notHFile)  >> 15) | ((knight & notAFile)  >> 17) | ((knight & notGHFile) >> 6 ) | ((knight & notABFile) >> 10);

    printBoard(attacks);

    U64 same, diff;

    if (isBit(bitboard[N], x))
    {
        same = bitboard[P] | bitboard[R] | bitboard[N] |
               bitboard[B] | bitboard[K] | bitboard[Q];

        diff = bitboard[p] | bitboard[r] | bitboard[n] |
               bitboard[b] | bitboard[k] | bitboard[q];
    }
    else if (isBit(bitboard[n], x))
    {
        diff = bitboard[P] | bitboard[R] | bitboard[N] |
               bitboard[B] | bitboard[K] | bitboard[Q];

        same = bitboard[p] | bitboard[r] | bitboard[n] |
               bitboard[b] | bitboard[k] | bitboard[q];
    }
    else
    {
        printf("illegal move\n");
        return;
    }

    attacks &= ~same;

    U64 kill = attacks & diff;
    U64 onlyMove = attacks & ~diff;

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