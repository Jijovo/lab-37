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
        //check if choice is valid
        if (c < 1 || c > 5) {
            cout << "Invalid choice!" << endl;
        }
        //search for key
        if (c == 1) {
            string str;
            cout << "Enter the string: ";
            cin >> str;
            //find the string in the map, say not found otherwise
            bool found = false;
            int ks;
            for (auto it = hash_table.begin(); it != hash_table.end(); it++) {
                if (it->second == gen_hash_index(str)) {
                    found = true;
                    ks = it->first;
                    break;
                }
            }
            if (found) {
                cout << "String found at key: " << ks << endl;
            }
            else {
                cout << "String not found!" << endl;
            }
        }
        //add key
        else if (c == 2) {
            int ka;
            string s;
            cout << "Enter the string: ";
            cin >> s;
            //add to a new key by finding the highest key in the map and adding one to it
            for (auto it = hash_table.begin(); it != hash_table.end(); it++) {
                if (it->first > ka) {
                    ka = it->first;
                }
            }
            ka++;
            hash_table[ka] = gen_hash_index(s);
            cout << "String added at key: " << ka << endl;
        }
        //remove key
        else if (c == 3) {
            string strr;
            int kr;
            cout << "Enter the string: ";
            cin >> strr;
            //check if string exists
            bool found = false;
            for (auto it = hash_table.begin(); it != hash_table.end(); it++) {
                if (it->second == gen_hash_index(strr)) {
                    found = true;
                    kr = it->first;
                    break;
                }
            }
            if (found) {
                hash_table.erase(kr);
                cout << "String removed at key: " << kr << endl;
            }
            else {
                cout << "String not found!" << endl;
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
