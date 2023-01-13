#include "ResultEnum.h"

std::string ResultToString(const Result result)
{
    std::string resultStr;
    switch (result)
    {
    case Result::xWon:          resultStr = "X won"; break;
    case Result::oWon:          resultStr = "O won"; break;
    case Result::draw:          resultStr = "Draw"; break;
    case Result::incomplete:    resultStr = "Incomplete"; break;
    case Result::invalid:       resultStr = "Invalid"; break;
    default: break;
    }
    return resultStr;
}