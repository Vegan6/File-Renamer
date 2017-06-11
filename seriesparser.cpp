#include "seriesparser.h"

std::string fileName;

seriesparser::seriesparser(std::string FileName)
{
    fileName = FileName;
}

//Normalize filename

std::str seriesparser::NormalizeString(std::string FileName)
{
    // Replace . _  with space
    Replace(&FileName, ".", " ");
    Replace(&FileName, "_", " ");

    // Remove some normal add ons

    return FileName;
}

//Parse out TV series name and year

//Parse out season, episode

// String Replace Char
static inline void Replace(std::string &str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}
