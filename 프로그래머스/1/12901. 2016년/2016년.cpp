#include <string>
#include <vector>
#include <iostream>
using namespace std;

int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string week[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

string solution(int a, int b) {
    string answer = "";    
    // 5월 24일 = 화요일
    // 5월 = 31 + 29 + 31 + 30 = 121
    // 121 + 24 = 145 / 7 = 20...5
    
    // 62 + 61 + 60 + 31 = 123 + 91 = 245 / 7 = 35...0
    
    // 월에 따른 날짜 계산 
    int day = 0;
    for(int i = 0;i<a - 1;i++)
        day += days[i];
    day += b; 
    cout<<day<<'\n';
    
    // 목표 월과 일을 더한 값에 7을 나눠 금요일에서 얼마나 지나간지
    day %= 7;
    if(day - 1 < 0){
        day = 7 + day;
    }
    answer = week[day-1];
    
    return answer;
}