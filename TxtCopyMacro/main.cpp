#include <fstream>
#include <string>
#include <iostream>
#include <regex>



class chapterFind
{
    private:
    char chapter[1];
    std::regex chapterRegex; // 챕터 찾는 정규표현식
    
    public:
    chapterFind()
    {
        std::cin >> chapter; //chpater = A(1)~S(19)
        chapterRegex = strcat(chapter, " [0-9]{2}");
    }
    void Find()
    {
        std::ifstream f;
        f.open("D:\\Programming\\DB\\XiBasicVoca.txt", std::ios::in);

        char buf[100];

        if (!f.is_open()) {
            std::cout << "파일을 찾을 수 없습니다!" << std::endl;
        }

        while (f) {
            f.getline(buf, 100);
            if(std::regex_match(buf, chapterRegex))
            {
                break;
            }
        }
    }
};
int main(void)
{

    chapterFind find;

    find.Find();
    return 0;
}