// link = https://www.hackerrank.com/challenges/super-functional-strings/problem?isFullScreen=true&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'superFunctionalStrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

// unique characters in a string
int cntDistinct(string str)
{
    // Set to store unique characters
    // in the given string
    unordered_set<char> s;
 
    // Loop to traverse the string
    for (int i = 0; i < str.size(); i++) {
 
        // Insert current character
        // into the set
        s.insert(str[i]);
    }
 
    // Return Answer
    return s.size();
}

int superFunctionalStrings(string s) {
    int n = s.size();
    int res = 0;
    // Pick starting point
    for (int len = 1; len <= n; len++)
    {   
        // Pick ending point
        for (int i = 0; i <= n - len; i++)
        {
            //  Print characters from current
            // starting point to current ending
            // point. 
            int j = i + len - 1; 
            string sub = s.substr(i, len);          
            res += (int)pow(sub.size(), cntDistinct(sub)) % 1000000007;
             
            cout << endl;
        }
    }
    return res% 1000000007;
}

int main()
{

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        int result = superFunctionalStrings(s);

        cout << result << "\n";
    }


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
