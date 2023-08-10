#include<iostream>
#include "calculatescore.h"

int main()
{
    float a, b, c, d, e, f;
    std::cout << "input 6 score" << std::endl;
    std::cin >> a >> b >> c >> d >> e >> f;
    float high = gethighestscore(a, b, c, d, e, f);
    float low = getlowestscore(a, b, c, d, e, f);
    float average = SCORE(a, b, c, d, e, f);
    std::cout << "highest:" << high << "\nlowest:" << low << "\naverage:" << average;
}