#include "seriesparser.h"

std::string fileName;
std::string seriesName;
std::string episode;
std::string season;
std::string year;

seriesparser::seriesparser(std::string FileName)
{
    fileName = FileName;
}

// String Replace
static inline void ReplaceInMem(std::string &text, const std::string& from, const std::string& to)
{
    std::size_t
            start_pos = 0;

    while((start_pos = text.find(from, start_pos)) != std::string::npos)
    {
        text.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

//Normalize filename
std::string NormalizeString(std::string FileName)
{
    // Replace . _  with space
    ReplaceInMem(FileName, ".", " ");
    ReplaceInMem(FileName, "_", " ");

    // Remove some normal add ons
    //xvid 1080 720 eztv ettv

    return FileName;
}

//Parse out TV series name and year
std::string GetSeriesNameInMem (std::string &fileName)
{
    return fileName;
}

//Parse out season, episode
/*Look for:
 * Pattern1 S###E###, S##E##, S#E#
 * Pattern2 ##x##
 * Pattern3 101 (season 1 episode 1)
 *
 * Todo:
 * ep##
 * e01-03
 * e01+02
 * episode ##
 * season ##
 * 1.01 (Season 1 Episode 1)
 * season 00
 *
*/
bool setEpisodeSeason (std::string &fileName)
{
    std::regex
            pattern1("S([0-9]{0,2}[1-9])E([0-9]{0,2}[1-9])", std::regex_constants::icase),
            pattern2("([0-9]{0,2}[1-9])x([0-9]{0,2}[1-9])", std::regex_constants::icase);
    std::smatch
            match;
    std::string
            seasonEpisode;

    // Check Pattern 1 S01E06
    if (std::regex_search(fileName, match, pattern1))
    {
        seasonEpisode = std::string(match[0]);
        std::smatch sMatch;
        if (std::regex_search(seasonEpisode, sMatch, std::regex("[0-9]{0,2}[1-9]")))
        {
            season = sMatch[0];
            episode = sMatch[1];
            return true;
        }
        else
        {
            return false;
        }
    }
    // Check Pattern 1 01x06
    else if (std::regex_search(fileName, match, pattern2))
    {
        seasonEpisode = std::string(match[0]);
        std::smatch sMatch;
        if (std::regex_search(seasonEpisode, sMatch, std::regex("[0-9]{0,2}[1-9]")))
        {
            season = sMatch[0];
            episode = sMatch[1];
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;

}


