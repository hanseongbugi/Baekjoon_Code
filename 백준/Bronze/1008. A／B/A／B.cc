#include<iostream>
using namespace std;
int main(){
    double a,b;
    std::cin>>a>>b;
    cout.precision(12);
    cout << fixed;
    std::cout<<a/b<<'\n';
}