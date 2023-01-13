#include "BoardUtils.h"

#include <math.h>
#include <string>

void GetTokenCount(const Board& board, uint8_t& xnum, uint8_t& onum)
{
    // set the counts to 0
    xnum = 0;
    onum = 0;

    // check each space
    for (uint8_t i = 0; i < 3; ++i)
    {
        for (uint8_t j = 0; j < 3; ++j)
        {
            switch (board[i][j])
            {
            case 'x':
                ++xnum;
                break;
            case 'o':
                ++onum;
                break;
            default:
                break;
            }
        }
    }
}

bool IsBoardFull(const Board& board)
{
    // simply check for the presence of the '-' character
    for (uint8_t i = 0; i < 3; ++i)
    {
        for (uint8_t j = 0; j < 3; ++j)
        {
            if (board[i][j] == '-')
                return false;
        }
    }

    // if we reach here, there are no '-' characters
    // board must be full
    return true;
}

// sees if the passed token ('x' or 'o') has won
bool IsTokenWinner(const Board& board, const char token)
{
    // check vertical and horizontal winning patterns
    for (uint8_t i = 0; i < 3; ++i)
    {
        if (board[i][0] == token &&
            board[i][1] == token &&
            board[i][2] == token)
        {
            return true;
        }
        else if (board[0][i] == token &&
            board[1][i] == token &&
            board[2][i] == token)
        {
            return true;
        }
    }

    // check diagonal
    // the middle square must have the token
    if (board[1][1] == token)
    {
        if (board[0][0] == token &&
            board[2][2] == token)
        {
            return true;
        }
        else if (board[0][2] == token &&
            board[2][0] == token)
        {
            return true;
        }
    }

    // if we reach here, this token has not won
    return false;
}

// checks that all chars in the board are 'x', 'o', or '-'
// checks that the right number of moves have been played
bool Validate(const Board& board)
{
    const std::string VALID_CHARS = "xo-";
    for (uint8_t i = 0; i < 3; ++i)
    {
        for (uint8_t j = 0; j < 3; ++j)
        {
            if (VALID_CHARS.find(board[i][j]) == std::string::npos)
            {
                // character not valid
                return false;
            }
        }
    }
    
    // if we reach here, all characters are valid
    return true;
}

Result Examine(const Board& board)
{
    // check board only have valid characters
    if (!Validate(board))
        return Result::invalid;

    // get the number of 'x's and 'o's
    uint8_t xnum = 0;
    uint8_t onum = 0;
    GetTokenCount(board, xnum, onum);
    // number of 'x's and 'o's must be within 1 
    if (abs(xnum - onum) > 1)
        return Result::invalid;

    const bool xwon = IsTokenWinner(board, 'x');
    const bool owon = IsTokenWinner(board, 'o');
    if (xwon && owon)
    {
        // both X and O cannot win
        return Result::invalid;
    }
    else if (xwon)
    {
        // in this case, number of 'o' tokens must be <= 'x' tokens
        if (xnum < onum)
            return Result::invalid;
        else
            return Result::xWon;
    }
    else if (owon)
    {
        // in this case, number of 'x' tokens must be <= 'o' tokens
        if (onum < xnum)
            return Result::invalid;
        else
            return Result::oWon;
    }
    else if (IsBoardFull(board))
    {
        return Result::draw;
    }
    else
    {
        return Result::incomplete;
    }
}