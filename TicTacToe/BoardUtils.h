#pragma once

#include <stdint.h>

#include "ResultEnum.h"

// Tic Tac Toe board is 3x3 grid of chars
// possible chars are the two tokens 'x' and 'o', and a character for a blank space '-'
typedef char Board[3][3];

Result Examine(const Board& board);