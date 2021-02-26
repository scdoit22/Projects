#include <fstream>
#include <string>
#include <iostream>
#include <regex>
#include <vector>

class simplification
{
    private:
    char chapter[1];
    std::regex chapterRegex; // 챕터 찾는 정규표현식
    std::regex wordRegex;
    std::vector<std::string> output;
    const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    public:
    simplification()
    {
        chapterRegex = "[A-Z] [가-힣]+( [가-힣]*)*";
        wordRegex = "•[a-z ]*";
    }
    void input()
    {
        std::ifstream f;
        f.open("D:\\Programming\\DB\\XiBasicVoca.txt", std::ios::in);

        if (!f.is_open()) 
        {
            std::cout << "파일을 찾을 수 없습니다!" << std::endl;
        }

        char buf[100];
        int count = 0;
        std::string str;
        std::smatch match;
        while (true) 
        {
            if(f.eof()) break;
            f.getline(buf, 100);
            str = buf;
            if(std::regex_search(str, match, wordRegex))
            {
                str = buf;
                output.push_back(match.str());
                std::cout << match.str() << "\n";
            }
            else if(std::regex_search(str, chapterRegex))
            {
                str = str[0];
                str += std::to_string(count);
                output.push_back(str);
                std::cout << str << std::endl;;
                ++count;
            }
            
        }
        f.close();
    }
    // void wordCollect()
    // {
    //     chapter[0] += 1;
    //     chapterRegex = strcat(chapter," [0-9]{2}");
    //     while(f)
    //     {   
    //         f.getline(buf, 100);
    //          if(std::regex_match(buf, chapterRegex))
    //         {
    //             break;
    //         }
    //     }
    //     f.close();
    // }
};
int main(void)
{
    simplification si;
    si.input();
    return 0;
}