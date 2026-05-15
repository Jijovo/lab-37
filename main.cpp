//Ezzat Mohamadein | ComSc 210 | Lab 37
#include <iostream>
using namespace std;

//sum ascii function prototype
int sum_ascii(string s);

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;

    //testing sum ascii function
    cout << sum_ascii("abcdef") << endl;
    

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
