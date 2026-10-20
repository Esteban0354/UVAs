#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Friend{
private:
    string name;
    int moneySpent;
    int giftsGiven;
    //string friendsNames[giftsGiven];

public:
    Friend(string n, int ms, int gg) : name(n),moneySpent(ms),giftsGiven(gg){}

    string getName(){
        return name;
    }

    int getMoneySpent(){
        return moneySpent;
    }

    int getGiftsGiven(){
        return giftsGiven;
    }
};

void addFriends(int totalFriends){
    int numFriends,dinero,cantidadRegalo,perdida;
    string nombre, nombreAmigos;
    vector<string> amigosRegalos;
    vector<Friend> friends;

    cin >> nombre >> dinero >> numFriends;
    friends.push_back({nombre,dinero,numFriends});
    for (int i = 0; i < numFriends; ++i) {
        cin>>nombreAmigos;
        amigosRegalos.push_back(nombreAmigos);
    }

    if(dinero > 0 && numFriends >0 ){
        cantidadRegalo = dinero/numFriends;
    }else{
        cantidadRegalo = 0;
    }
    perdida = cantidadRegalo * numFriends;







}


int main() {
    int totalFriends;
    string nombreAmigos;
    vector<string> allFriends;
    while (cin >> totalFriends){
        for (int i = 0; i < totalFriends; ++i) {
            cin >> nombreAmigos;
            allFriends.push_back(nombreAmigos);
        }
        for (int i = 0; i < totalFriends; ++i) {
            cout << allFriends[i]<< " ";
        }
        cout << endl;
        for (int i = 0; i < totalFriends; ++i) {
            addFriends(totalFriends);
        }
    }

}
