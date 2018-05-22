// from:
// http://codepad.org/FnxiQefu
// https://www.reddit.com/r/programming/comments/24meqs/peg_solitaire_solver_in_just_50_lines/ch8xu9s/
// https://blackflux.wordpress.com/2014/04/30/peg-solitaire-brute-force/

// g++ -Ofast -flto -s -std=c++11 peg_solitaire.cpp -o peg_solitaire

#include <stdint.h>
#include <stdio.h>
#include <unordered_set>
#include <vector>
#include <array>
#include <random>
#include <algorithm>

#define DO_SHUFFLE true

const uint64_t validBoardCells = 124141734710812ULL;
const uint64_t initialBoard    = 124141717933596ULL;
const uint64_t goalBoard       = 16777216ULL;
// C++14:
// const uint64_t validBoardCells = 0b'0011100'0011100'1111111'1111111'1111111'0011100'0011100'ULL;
// const uint64_t initialBoard    = 0b'0011100'0011100'1111111'1110111'1111111'0011100'0011100'ULL;
// const uint64_t goalBoard       = 0b'0000000'0000000'0000000'0001000'0000000'0000000'0000000'ULL;
static_assert((validBoardCells & ~goalBoard) == initialBoard, "Wrong constants.");

typedef std::array<std::array<uint64_t, 3>, 76> Moves;
typedef std::unordered_set<uint64_t> SeenBoards;

static void createMoves(const uint32_t bit1,
                        const uint32_t bit2,
                        const uint32_t bit3,
                        Moves &moves,
                        uint32_t &pos) noexcept {
    moves[pos++] = {(1ULL << bit1),
                    (1ULL << bit2) | (1ULL << bit3),
                    (1ULL << bit1) | (1ULL << bit2) | (1ULL << bit3)};
    moves[pos++] = {(1ULL << bit3),
                    (1ULL << bit2) | (1ULL << bit1),
                    (1ULL << bit1) | (1ULL << bit2) | (1ULL << bit3)};
}

static void initMoves(Moves &moves) {
    uint32_t pos = 0;

    const std::array<uint32_t, 19> starts = {2, 9, 14, 15, 16, 17, 18, 21, 22,
                                             23, 24, 25, 28, 29, 30, 31, 32, 37, 44};
    for (const auto& start: starts) {
        createMoves(start, start + 1, start + 2, moves, pos);
        createMoves((start % 7) * 7 + start / 7,
                    (start % 7 + 1) * 7 + start / 7,
                    (start % 7 + 2) * 7 + start / 7,
                    moves, pos);
    }

#if DO_SHUFFLE
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(moves.begin(), moves.end(), rng);
#endif
}

static bool search(const uint64_t board,
                   const Moves &moves,
                   SeenBoards &seenBoards,
                   std::vector<uint64_t> &solution) { // noexcept
    for (const auto& move: moves) {
        if (!(move[1] & board) && (move[0] & board)) {
            const auto newBoard = board ^ move[2];
            if (seenBoards.find(newBoard) == seenBoards.end()) {
                seenBoards.emplace(newBoard);
                if (newBoard == initialBoard
                    || search(newBoard, moves, seenBoards, solution)) {
                    solution.emplace_back(board);
                    return true;
                }
            }
        }
    }

    return false;
}

static void printBoard(const uint64_t board) {
    for (uint32_t i = 0; i < 49; i++) {
        const auto validCell = (1ULL << i) & validBoardCells;
        printf(validCell ? (((1ULL << i) & board) ? "X " : "O ") : "  ");
        if (i % 7 == 6)
            putchar('\n');
    }
    puts("-------------");
}

int main() {
    Moves moves = {0};
    initMoves(moves);

    SeenBoards seenBoards;
    std::vector<uint64_t> solution = {initialBoard};
    search(goalBoard, moves, seenBoards, solution);

    for (const auto& step: solution)
        printBoard(step);

    return 0;
}
