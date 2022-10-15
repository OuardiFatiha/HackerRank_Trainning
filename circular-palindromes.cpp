// link = https://www.hackerrank.com/challenges/circular-palindromes/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'circularPalindromes' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING s as parameter.
 */

bool isPalindrome(string s){
    bool palindrome = true;
    int n = s.size() / 2;
    for(int i =0; i<n; n++){
        if(n % 2 == 0){
            if(s[n+i] != s[n-i-1]){
                palindrome = false;
                return palindrome;
            } 
        } else {
            if(s[n+i+1] != s[n-i-1]){
                palindrome = false;
                return palindrome;
            } 
        }
    }
    return palindrome;
}

vector<int> circularPalindromes(string s) {

}

int main()
{

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    vector<int> result = circularPalindromes(s);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
