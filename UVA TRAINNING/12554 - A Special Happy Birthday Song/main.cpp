// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> song {
        "Happy",
        "birthday",
        "to",
        "you",
        "Happy",
        "birthday",
        "to",
        "you",
        "Happy",
        "birthday",
        "to",
        "Rujia",
        "Happy",
        "birthday",
        "to",
        "you"
    };

    int people;
    cin>>people;
    vector<string> peoples;
    for (int i=0; i<people; i++) {
        string person;
        cin>>person;
        peoples.push_back(person);
    }
    int repeatSong = true;
    int everybodySang = false;
    int peopleIndex = 0;
    while(!everybodySang) {
        for (int i=0; i<song.size(); i++) {
            string sing = peoples[peopleIndex];
            cout<<sing<<": "<<song[i]<<endl;
            peopleIndex++;
            if (peopleIndex >= peoples.size()) {
                peopleIndex = 0;
                everybodySang = true;
            }
        }
    }

    return (0);
}
