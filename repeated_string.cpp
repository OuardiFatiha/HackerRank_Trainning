// link = https://www.hackerrank.com/challenges/repeated-string/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=60-day-campaign&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

// Function that return count of the given
// character in the string
int count(string s, char c)
{
    // Count variable
    int res = 0;
 
    for (int i=0;i<s.length();i++)
 
        // checking character in string
        if (s[i] == c)
            res++;
 
    return res;
}

long repeatedString(string s, long n) {
    long l = 0;
    int occ = count(s, 'a');
    if((n % s.size()) == 0){
        l = (n / (s.size())) * occ;
    }else{
        l = (long(n / (s.size())) * occ) +  count(s.substr(0, n % s.size()), 'a');
    }
    return l;
}

int main()
{
    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

    cout << result << "\n";

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
