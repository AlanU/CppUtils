#include <iostream>
#include <vector>
#include <regex>
#include <chrono>
#include <iomanip>


auto vectorToString = [](const std::vector<std::string> & vectorToPrint, const std::string separator="\n" )->std::string{
    std::string vectorString;
    for(const std::string & objectToPrint :vectorToPrint)
    {
        vectorString = vectorString + objectToPrint + separator;
    }
    vectorString.pop_back();
    return vectorString;};

std::vector<std::string> flex_split(const std::string & stringToSplit,const std::string &regexString)
{
    std::regex regexToSplitWith {regexString};
    //create a ForwardIterator of submatches for the regex regexToSplitWith


    std::sregex_token_iterator wordsIterator {stringToSplit.begin(),stringToSplit.end(),regexToSplitWith,-1};


    return {wordsIterator,std::sregex_token_iterator{}};
}

std::vector<std::string> fast_split(const std::string & stringToSplit,const char charToSplitOn=' ')
{
   std::vector<std::string> returnVect;
   std::string temp;
    for(const char & c :stringToSplit)
    {
        if(c != charToSplitOn)
        {
            temp = temp + c;
        }
        else
        {
            returnVect.push_back(std::move(temp));
            temp="";
        }

    }
    return returnVect;
}

int main(int argc, const char * argv[]) {

    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();

    std::vector<std::string> words = flex_split("The quick brown fox jumps over the lazy dog.",  "\\s+");
    //std::vector<std::string> words = fast_split("The quick brown fox jumps over the lazy dog.", ' ');

    std::clock_t c_end = std::clock();
    auto t_end = std::chrono::high_resolution_clock::now();

    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end-t_start).count()
              << " ms\n";

    std::cout<<vectorToString(words)<<std::endl;
    return 0;
}
