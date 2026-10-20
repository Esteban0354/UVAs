#include <iostream>
#include <vector>
using namespace std;
// Esteban Munoz Serrano - 8966406
int main() {
    int n,pos,length;
    string card,word;

    while(cin>>n, n>0){
        pos = -1;
        vector<string> circle(n," ");
        for (int i = 0; i < n; ++i) {
            cin >> card >> word;
            length = word.length();

            while (length){
                pos = (pos+1) % n;
                if (circle[pos] == " ") -- length;

            }
            circle[pos] = card;
        }
        for (int i = 0; i < n; ++i) {
            cout << circle[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
