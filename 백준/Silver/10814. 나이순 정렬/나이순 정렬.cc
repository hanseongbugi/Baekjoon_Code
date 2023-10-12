#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Person{
public:
    int age;
    string name;
    int rule;
    Person(int age, string name, int rule):age(age),name(name),rule(rule){}
};

bool bigger(Person a, Person b){
    if(a.age == b.age) return a.rule < b.rule;
    else return a.age < b.age;
}

int main(){
    int N;
    cin>>N;
    vector<Person> arr;
    for(int i = 0;i<N;i++){
        int age;
        string name;
        cin>>age>>name;
        arr.emplace_back(age,name,i);
    }
    sort(arr.begin(),arr.end(),bigger);
    
    for(int i = 0;i<arr.size(); i++)
        cout<<arr[i].age<<' '<<arr[i].name<<'\n';
}