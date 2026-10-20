#include <iostream>
#include <vector>
#include <algorithm>
// Esteban Munoz Serrano - 8966406

using namespace std;
// Metodo sacado de el ejemplo dado por el profesor
bool comparador(int i,int j){
    bool ans = i < j;
    return ans;
}

void cases(int numCases) {
    vector<int> friend1, friend2, friend3, result1, result2, result3;
    int num1, n1, num2, n2, num3, n3;
    // Se llena friend1
    //cout << "friend1" << endl;
    cin >> n1;
    for (int i = 0; i < n1; ++i) {
        cin >> num1;
        friend1.push_back(num1);
    }

    //cout << "friend2" << endl;
    cin >> n2;
    for (int i = 0; i < n2; ++i) {
        cin >> num2;
        friend2.push_back(num2);
    }

    //cout << "friend3" << endl;
    cin >> n3;
    for (int i = 0; i < n3; ++i) {
        cin >> num3;
        friend3.push_back(num3);
    }


    for(int i: friend1){
        if (find(friend2.begin(), friend2.end(),i) == friend2.end() && find(friend3.begin(), friend3.end(),i) == friend3.end()){
            result1.push_back(i);
        }
    }

    for(int i: friend2){
        if (find(friend1.begin(), friend1.end(),i) == friend1.end() && find(friend3.begin(), friend3.end(),i) == friend3.end()){
            result2.push_back(i);
        }
    }

    for(int i: friend3){
        if (find(friend2.begin(), friend2.end(),i) == friend2.end() && find(friend1.begin(), friend1.end(),i) == friend1.end()){
            result3.push_back(i);
        }
    }
    int size;
    int index;
    if (result1.size() > result2.size() && result1.size() > result3.size()){
        index = 1;
    }else if(result2.size() > result1.size() && result2.size() > result3.size()){
        index = 2;
    }else{
        index = 3;
    }
    cout << "Case #" << numCases <<":";
    cout << endl;
    switch (index) {
        case 1:
            cout << index << " ";
            size = result1.size();
            cout << size << " ";
            sort(result1.begin(), result1.end(), comparador);
            for (vector<int>::iterator it = result1.begin(); it != result1.end();++it) {
                cout << *it << " ";
            }
            cout << endl;
        break;
        case 2:
            cout << index << " ";
            size = result2.size();
            cout << size << " ";
            sort(result2.begin(), result2.end(), comparador);
            for (vector<int>::iterator it = result2.begin(); it != result2.end();++it) {
                cout << *it << " ";
            }
            cout << endl;
        break;
        case 3:
            cout << index << " ";
            size = result3.size();
            cout << size << " ";
            sort(result3.begin(), result3.end(), comparador);
            for (vector<int>::iterator it = result3.begin(); it != result3.end();++it) {
                cout << *it << " ";
            }

            cout << endl;
        break;
    }
    cout << endl;
}



int main() {
    int numCases;
    //cout << "Escribe cuantos casos deseas realizar"<< endl;
    cin >> numCases;
    for (int i = 1; i <= numCases; ++i) {
        cases(i);
    }

    return 0;

}
