#include <stdio.h>
#include "utils.h"
#include "queen.h"
#include "bitboard.h"
#include "bishop.h"
#include "rook.h"
#include "board.h"


void queenMoves(U64 bitboard[12], int x)
{
    rookMoves(bitboard, x,1);
    bishopMoves(bitboard, x,1);

}