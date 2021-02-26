#include <iostream>
#include <regex>
#include <string>

int main(void)
{
    char chapter[1];
    std::string str = "A 01";    
    std::regex chapterRegex;
    std::cin >> chapter; //chpater = A(1)~S(19)
    chapterRegex = strcat(chapter," [0-9][0-9]");
    // chapterRegex = "A [0-9][0-9]";
    if(std::regex_match(str, chapterRegex))
    {
        std::cout << "True";
    }
    return 0;
}