#include <stdio.h>
#include "utils.h"
#include "king.h"
#include "bitboard.h"
#include "board.h"



void kingMoves(U64 bitboard[12], int x)
{

    U64 king = 1ULL << x;

    U64 north = king << 8;
    U64 south = king >> 8;
    U64 east = (king & notHFile) << 1;
    U64 west = (king & notAFile) >> 1;;

    U64 northEast  = (king & notHFile) << 9;
    U64 northWest  = (king & notAFile) << 7;

    U64 southEast  = (king & notHFile) >> 7;
    U64 southWest  = (king & notAFile) >> 9;

    U64 attacks = north | south | east | west | northEast | northWest | southEast | southWest;
  
    printBoard(attacks);

    U64 same, diff, taken;

    if (isBit(bitboard[K], x))
    {
        same = bitboard[P] | bitboard[R] | bitboard[N] |
               bitboard[B] | bitboard[K] | bitboard[Q];

        diff = bitboard[p] | bitboard[r] | bitboard[n] |
               bitboard[b] | bitboard[k] | bitboard[q];
    }
    else if (isBit(bitboard[k], x)){
        diff = bitboard[P] | bitboard[R] | bitboard[N] |
               bitboard[B] | bitboard[K] | bitboard[Q];

        same = bitboard[p] | bitboard[r] | bitboard[n] |
               bitboard[b] | bitboard[k] | bitboard[q];
    }
    else{
        printf("illegal move\n");
        return;
    }

    attacks = attacks & ~same;

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

