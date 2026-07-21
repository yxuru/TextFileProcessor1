#include "clean.h"


std::string_view trim(std::string_view str)
{
    const std::string_view whitespace = " \t\n\r\f\v";

    const auto start = str.find_first_not_of(whitespace);

    if (start == std::string_view::npos)
        return "";

    const auto end = str.find_last_not_of(whitespace);

    return str.substr(start, end - start + 1);
}