#include <fstream>
#include <stdio.h>
#include <string>


int main()    {
    std::string text;
    std::ifstream file("./input.txt");
    std::string str = "";

    while (getline(file, text)) {
        str.append(text);
        str.append("\n");// replace lost eol
    }

    int iAns1 = 0;
    int iAns2 = 0;
    int i1, i2;
    char c = 0;
    bool on = true;
    const char* p = str.data();

    while( *p ) {
        if( sscanf( p, "mul(%d,%d%c", &i1, &i2, &c) == 3 && c == ')' ) {
            iAns1 += i1 * i2;
            if (on) iAns2 += i1 * i2;
        }
        if( sscanf( p, "do(%c", &c) == 1 && c == ')' ) on = true;
        if( sscanf( p, "don't(%c", &c) == 1 && c == ')' ) on = false;
        p++;
    }
    printf("Answer1 %d\n", iAns1);
    printf("Answer2 %d\n", iAns2);
}
