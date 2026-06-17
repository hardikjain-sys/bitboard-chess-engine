#include <stdio.h>
#include <math.h>

#include "bitboard.h"
#include "board.h"
#include "pawn.h"
#include "knight.h"
#include "king.h"
#include "utils.h"
#include "fen.h"
#include "pawn.h"
#include "knight.h"
#include "king.h"

int main()
{
    U64 bitboard[12];

    // {bitboard[0] = 65280ULL; bitboard[6] = 71776119061217280ULL; bitboard[1] = 129ULL; bitboard[7] = 9295429630892703744ULL; bitboard[2] = 66ULL; bitboard[8] = 4755801206503243776ULL; bitboard[3] = 36ULL; bitboard[9] = 2594073385365405696ULL; bitboard[4] = 8ULL; bitboard[5] = 16ULL; bitboard[10]=576460752303423488ULL; bitboard[11]=1152921504606846976ULL;}
    loadFen(bitboard,"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    printFull(bitboard);
}