//Ezzat Mohamadein | ComSc 210 | Lab 37
#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

//sum ascii function prototype | switch to gen_hash_index()
list<char> gen_hash_index(string s);

int main() {
    //define map of hash indexes
    map<int, list<char>> hash_table;
    //read all strings in lab-37-data-3.txt and run them through gen_hash_index(), then push the lists into the map
    ifstream fin("lab-37-data-3.txt");
    string s;
    int i = 0;
    while (fin >> s) {
        hash_table[i] = gen_hash_index(s);
        i++;
        fin.ignore();
    }
    fin.close();

    //print first 100 values in the map
    for (int i = 0; i < 100; i++) {
        cout << i << ": ";
        for (auto it = hash_table[i].begin(); it != hash_table[i].end(); it++) {
            cout << *it;
        }
        cout << endl;
    }

    return 0;
}

//sum ascii function definition, recieves a string and returns the sum of that string' characters ascii values
//switch to gen_hash_index(), creats a hash index, a list of chars from the string
list<char> gen_hash_index(string s) {
    list<char> hash_index;
    for (int i = 0; i < s.length(); i++) {
        hash_index.push_back(s[i]);
    }
    return hash_index;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
