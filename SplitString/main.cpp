#include <iostream>
#include <vector>
#include <regex>

auto vectorToString = [](const std::vector<std::string> & vectorToPrint, const std::string separator="\n" )->std::string{
    std::string vectorString;
    for(const std::string & objectToPrint :vectorToPrint)
    {
        vectorString = vectorString + objectToPrint + separator;
    }
    vectorString.pop_back();
    return vectorString;};

std::vector<std::string> split(const std::string & stringToSplit,const std::string &regexString)
{
    std::regex regexToSplitWith {regexString};
    //create a ForwardIterator of submatches for the regex regexToSplitWith
    std::sregex_token_iterator wordsIterator {stringToSplit.begin(),stringToSplit.end(),regexToSplitWith,-1};
    return {wordsIterator,std::sregex_token_iterator{}};
}

int main(int argc, const char * argv[]) {


    std::vector<std::string> words = split("The quick brown fox jumps over the lazy dog.",  "\\s+");
    std::cout<<vectorToString(words)<<std::endl;
    return 0;
}
