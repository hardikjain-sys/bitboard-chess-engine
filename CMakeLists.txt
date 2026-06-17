cmake_minimum_required(VERSION 3.10)

project(ChessEngine C)
add_executable(
    ChessEngine
    src/main.c
    src/board.c
    src/pawn.c
    src/knight.c
    src/king.c
    src/utils.c
    src/bitboard.c
    src/fen.c
    src/rook.c
    src/bishop.c
    src/queen.c
)
target_include_directories(
    ChessEngine PRIVATE include
)
