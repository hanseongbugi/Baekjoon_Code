using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    long long temp = price;
    answer = price; // 3
    for(int i = 1;i<count;i++){
        temp += price;
        answer += temp; // 6 9 12
    }
    answer -= money;
    if(answer <= 0)
        return 0;
    
    return answer;
}