#include <fstream>
#include <string>
#include <iostream>
#include <regex>

class CopyMacro
{
    private:
    char chapter[1];
    std::regex chapterRegex; // 챕터 찾는 정규표현식
    std::ifstream f;
    char buf[100];

    public:
    CopyMacro()
    {
        std::cin >> chapter; //chpater = A(1)~S(19)
        chapterRegex = strcat(chapter, " [0-9]{2}");
        f.open("D:\\Programming\\DB\\XiBasicVoca.txt", std::ios::in);

    }
    void Find()
    {
        if (!f.is_open()) 
        {
            std::cout << "파일을 찾을 수 없습니다!" << std::endl;
        }

        while (f) 
        {
            f.getline(buf, 100);
            if(std::regex_match(buf, chapterRegex))
            {
                break;
            }
        }
        
    }
    void wordCollect()
    {
        chapter[0] += 1;
        chapterRegex = strcat(chapter," [0-9]{2}");
        while(f)
        {   
            f.getline(buf, 100);
             if(std::regex_match(buf, chapterRegex))
            {
                break;
            }
        }
        f.close();
    }
};
int main(void)
{

    CopyMacro cm;

    cm.Find();
    cm.wordCollect();
    return 0;
}