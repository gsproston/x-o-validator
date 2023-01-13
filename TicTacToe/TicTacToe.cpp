// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "BoardUtils.h"

void TestBoard(const Board& board, const Result expectedResult)
{
    const Result actualResult = Examine(board);
    if (actualResult == expectedResult)
    {
        std::cout << "PASS\n";
    }
    else
    {
        std::cout << "FAIL. Expected '" << ResultToString(expectedResult) 
            << "' got '" << ResultToString(actualResult) << "'\n";
    }
}

int main()
{
    // TEST CASES:
    // empty board
    // bad characters
    // token count difference
    // win with less tokens
    // both win
    // horizontal win
    // vertical win
    // diagonal win
    // win with full board
    // win with incomplete board
    // draw
    // incomplete game

    // empty board
    {
        const Board board =
        {
            { '-', '-', '-' },
            { '-', '-', '-' },
            { '-', '-', '-' }
        };
        TestBoard(board, Result::incomplete);
    }

    // bad characters
    {
        const Board board =
        {
            { 'o', 'x', '-' },
            { '-', 'f', '-' },
            { '-', '-', '-' }
        };
        TestBoard(board, Result::invalid);
    }

    // token count difference
    {
        const Board board =
        {
            { 'o', 'x', 'x' },
            { '-', '-', 'x' },
            { '-', '-', '-' }
        };
        TestBoard(board, Result::invalid);
    }

    // win with less tokens
    {
        const Board board =
        {
            { 'o', 'x', 'x' },
            { '-', 'o', 'x' },
            { '-', 'x', 'o' }
        };
        TestBoard(board, Result::invalid);
    }

    // both win
    {
        const Board board =
        {
            { 'o', 'o', 'o' },
            { '-', '-', '-' },
            { 'x', 'x', 'x' }
        };
        TestBoard(board, Result::invalid);
    }

    // horizontal win
    {
        const Board board =
        {
            { 'o', 'o', 'o' },
            { '-', '-', '-' },
            { 'x', 'x', '-' }
        };
        TestBoard(board, Result::oWon);
    }

    // vertical win
    {
        const Board board =
        {
            { 'x', 'o', 'o' },
            { 'x', '-', '-' },
            { 'x', '-', '-' }
        };
        TestBoard(board, Result::xWon);
    }

    // diagonal win
    {
        const Board board =
        {
            { 'x', 'o', 'o' },
            { '-', 'x', '-' },
            { '-', '-', 'x' }
        };
        TestBoard(board, Result::xWon);
    }

    // win with full board
    {
        const Board board =
        {
            { 'x', 'o', 'o' },
            { 'x', 'x', 'o' },
            { 'o', 'x', 'x' }
        };
        TestBoard(board, Result::xWon);
    }

    // win with incomplete board
    {
        const Board board =
        {
            { 'x', 'o', 'o' },
            { '-', 'x', '-' },
            { '-', '-', 'x' }
        };
        TestBoard(board, Result::xWon);
    }

    // draw
    {
        const Board board =
        {
            { 'x', 'o', 'o' },
            { 'o', 'x', 'x' },
            { 'x', 'o', 'o' }
        };
        TestBoard(board, Result::draw);
    }

    // incomplete game
    {
        const Board board =
        {
            { 'x', 'o', 'o' },
            { '-', 'x', '-' },
            { '-', '-', '-' }
        };
        TestBoard(board, Result::incomplete);
    }
}