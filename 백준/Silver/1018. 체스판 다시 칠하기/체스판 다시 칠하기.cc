#include<iostream>

using namespace std;
char board[51][51];

char ans_white[8][8] = {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
       {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
       {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
       {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'}
};
char ans_black[8][8] = {
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
};

int check(int a, int b) { //check함수는 바꿔야하는 개수 반환
    int count1 = 0;
    int count2 = 0;
    
    
        for (int i = a; i < a + 8; i++) {
            for (int j = b; j < b + 8; j++) {
                if (board[i][j] != ans_white[i-a][j-b])
                    count1++;
            }
        }

   
  
        for (int i = a; i < a + 8; i++) {
            for (int j = b; j < b + 8; j++) {
                if (board[i][j] != ans_black[i-a][j-b])
                    count2++;
            }
        }
    
    if (count1 > count2)return count2;
    else return count1;
    

}
int main() {
    int N, M;
    int min = 987654321;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    //i, j는 시작 인덱스
    for (int i = 0; i < N - 7; i++) {
        for (int j = 0; j < M - 7; j++) {
            if (min > check(i, j)) {
                min = check(i, j);
            }
        }
    }
    cout << min << endl;
    return 0;
}