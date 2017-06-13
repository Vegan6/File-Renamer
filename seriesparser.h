#ifndef SERIESPARSER_H
#define SERIESPARSER_H
#include <string>
#include <iostream>
#include <regex>


class seriesparser
{
public:
    seriesparser(std::string FileName);
    static inline void ReplaceInMem(std::string &str, const std::string& from, const std::string& to);

private:
    bool setEpisodeSeason (std::string &fileName);
    std::string NormalizeString(std::string FileName);
};

#endif // SERIESPARSER_H
