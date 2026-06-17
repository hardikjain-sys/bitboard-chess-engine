#include <stdio.h>
#include "utils.h"
#include "pawn.h"
#include "bitboard.h"
#include "board.h"

void pawnMoves(U64 bitboard[12], int x)
{
    U64 pawn = 1ULL << x;

    U64 same, diff;

    if (isBit(bitboard[P], x))
    {
        same = bitboard[P] | bitboard[R] | bitboard[N] |
               bitboard[B] | bitboard[K] | bitboard[Q];

        diff = bitboard[p] | bitboard[r] | bitboard[n] |
               bitboard[b] | bitboard[k] | bitboard[q];

        U64 taken = same | diff;

        U64 attacks = 0ULL;

        if ((pawn << 8) & ~taken)
            attacks |= (pawn << 8);

        if ((x / 8 == 1) &&
            ((pawn << 8) & ~taken) &&
            ((pawn << 16) & ~taken))
            attacks |= (pawn << 16);

        U64 kill = ((pawn & notHFile) << 9 & diff) | ((pawn & notAFile) << 7 & diff);

        printBoard(attacks | kill);

        for (int sq = 0; sq < 64; sq++)
        {
            if (kill & (1ULL << sq))
            {
                printf("killed ");
                ps(sq);
            }

            if (attacks & (1ULL << sq))
            {
                printf("moved ");
                ps(sq);
            }
        }
    }
    else if (isBit(bitboard[p], x))
    {
        same = bitboard[p] | bitboard[r] | bitboard[n] |
               bitboard[b] | bitboard[k] | bitboard[q];

        diff = bitboard[P] | bitboard[R] | bitboard[N] |
               bitboard[B] | bitboard[K] | bitboard[Q];

        U64 taken = same | diff;

        U64 attacks = 0ULL;

        if ((pawn >> 8) & ~taken)
            attacks |= (pawn >> 8);

        if ((x / 8 == 6) && ((pawn >> 8) & ~taken) && ((pawn >> 16) & ~taken))
            attacks |= (pawn >> 16);

        U64 kill = ((pawn & notAFile) >> 9 & diff) | ((pawn & notHFile) >> 7 & diff);

        printBoard(attacks | kill);

        for (int sq = 0; sq < 64; sq++)
        {
            if (kill & (1ULL << sq))
            {
                printf("killed ");
                ps(sq);
            }

            if (attacks & (1ULL << sq))
            {
                printf("moved ");
                ps(sq);
            }
        }
    }
    else
    {
        printf("illegal move\n");
    }
}