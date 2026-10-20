#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;
/*
void stones(string input) {
    queue<int> piedras;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] =='l') {
            piedras.push(i +1);
        } else {
            cout << i + 1 <<endl;
        }
    }
    while (!piedras.empty()) {
        cout << piedras.front() <<endl;
        piedras.pop();
    }
}
*/

void stones(string input) {
    stack<int> piedras;
    for (int i = 0; i < input.length();++i){
        if (input[i] =='l'){
            piedras.push(i + 1);
        }else {
            cout << i+1 <<endl;
        }
    }
    while (!piedras.empty()) {
        cout << piedras.top()<<endl;
        piedras.pop();
    }
}
int main() {
    string input;
    while (cin >> input) {
        stones(input);
        cout << endl;
    }
    return 0;
}
