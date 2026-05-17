//Ezzat Mohamadein | ComSc 210 | Lab 38
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

    //add menu with following options: seach for a key, add a key, remove a key, modify a key, exit
    int c;
    while (c!=5) {
        cout << "[1] Search for a key" << endl << "[2] Add a key" << endl << "[3] Remove a key" << endl << "[4] Modify a key" << endl << "[5] Exit" << endl << "Choice: ";
        cin >> c;
        //search for key
        if (c == 1) {
            int k;
            cout << "Enter the key: ";
            cin >> k;
            if (k > hash_table.size() || k < 0) { //check if key is valid
                cout << "Invalid key!" << endl;
            }
            else { //print list of chars from that key
                list<char> l = hash_table[k];
                cout << "Key " << k << " contains: ";
                for (list<char>::iterator it = l.begin(); it != l.end(); it++) {
                    cout << *it << " ";
                }
                cout << endl;
            }
        }
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
