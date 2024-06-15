#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int ny, nx;
    for(int i = 0;i<park.size();i++){
        for(int j = 0;j<park[i].length();j++){
            if(park[i][j] == 'S'){
                ny = i;
                nx = j;
                break;
            }
        }
    }
    for(int i = 0;i<routes.size();i++){
        char path = routes[i][0];
        int n = routes[i][2] - '0';
        
        int ty = ny, tx = nx;
        bool isClear = true;
        for(int j = 0;j<n;j++){
            if(path == 'N'){
                if(ny-n<0||park[ty-1][tx] == 'X'){
                    isClear = false;
                    break;
                }
                ty--;
            }
            else if(path == 'S'){
                if(ny+n>=park.size()||park[ty+1][tx] == 'X'){
                    isClear = false;
                    break;
                }
                ty++;
            }
            else if(path == 'W'){
                if(nx-n<0||park[ty][tx-1] == 'X'){
                    isClear = false;
                    break;
                }
                tx--;
            }
            else{
                if(nx+n>=park[0].length()||park[ty][tx+1] == 'X'){
                    isClear = false;
                    break;
                }
                tx++;
            }
        }
        if(isClear){
            nx = tx; 
            ny = ty;
        }
    }
    answer.push_back(ny);
    answer.push_back(nx);
    return answer;
}