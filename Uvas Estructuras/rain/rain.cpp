//
// Created by Esteban on 11/15/2023.
//
#include <stack>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


int rain(string simbols){
    int unitsWater = 0;
    stack<int> mountain;
    for (int i = 0; i <simbols.length(); ++i) {
        if(simbols[i] =='\\'){
            mountain.push(i);
        }else if(simbols[i] == '/'){
            if(!mountain.empty()){
                unitsWater += i -mountain.top();
                mountain.pop();
            }

        }
    }
    return unitsWater;
}

int main(){
    int n;
    string simbols;
    int unitsWater = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> simbols;
        unitsWater = rain(simbols);
        cout << unitsWater << endl;
    }
}