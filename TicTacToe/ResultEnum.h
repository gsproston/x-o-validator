#pragma once

#include <string>

enum class Result
{
    xWon = 0,
    oWon,
    draw,
    incomplete,
    invalid
};

std::string ResultToString(const Result result);