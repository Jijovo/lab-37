//Ezzat Mohamadein | ComSc 210 | Lab 37
#include <iostream>
#include <fstream>
using namespace std;

//sum ascii function prototype
int sum_ascii(string s);

int main() {
    //read all strings in lab-37-data-3.txt and sum all their ascii value sums
    string s;
    int sum = 0;
    ifstream fin("lab-37-data-3.txt");
    while (getline(fin, s)) {
        sum += sum_ascii(s);
    }
    //close file    
    fin.close();
    //print sum
    cout << sum << endl;

    return 0;
}

//sum ascii function definition, recieves a string and returns the sum of that string' characters ascii values
int sum_ascii(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += (int) s[i];
    }
    return sum;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
