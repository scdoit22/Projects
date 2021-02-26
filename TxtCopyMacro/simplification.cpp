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
    void Input()
    {
        std::ifstream f;
        f.open("D:\\Programming\\DB\\XiBasicVoca.txt", std::ios::in);

        if (!f.is_open()) 
        {
            std::cout << "파일을 찾을 수 없습니다!" << std::endl;
        }
        std::string buf;
        int count = 0;
        std::smatch match;
        while (!f.eof()) 
        {
            std::getline(f, buf);
            if(std::regex_search(buf, match, wordRegex))
            {
                buf = match.str();
                buf.erase(0,3);
                output.push_back(buf);
                std::cout << buf << "\n";
            }
            else if(std::regex_search(buf, chapterRegex))
            {
                buf = buf[0];
                buf += std::to_string(count);
                output.push_back(buf);
                std::cout << buf << std::endl;;
                ++count;
            }
            
        }
        f.close();
    }   
    void Output()
    {
        std::ofstream f;
        f.open("D:\\Programming\\C++\\Projects\\TxtCopyMacro\\simple.txt");
        std::string tmp;
        for(int i = 0; i < output.size(); ++i)
        {
            tmp = output[i];
            if (i != output.size() - 1)
            {
                tmp += "\n";    //마지막 단어 빼고 엔터 넣어주기
            }
            f.write(tmp.c_str(), tmp.size());
        }
    }
};
int main(void)
{
    simplification si;
    si.Input();
    si.Output();
    return 0;
}