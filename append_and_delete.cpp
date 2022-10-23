// link = https://www.hackerrank.com/challenges/append-and-delete/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=60-day-campaign&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'appendAndDelete' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 *  3. INTEGER k
 */

string appendAndDelete(string s, string t, int k) {
    int n = s.size();
    int m = t.size();
    int i;
    for(i=0; i<min(n,m); i++){
        if(s[i] != t[i]){
            if(k <= (n-i)){
                return "No";
            }else{
                if((k-n+i) < (m-i)) return "No";
                else return "Yes";
            }
        }
    }
    if(n == m){
        return "Yes";
    }else if (n < m){
        if(k < (m-i)) return "No";
        else{
            if(k == (m-i)) return "Yes";
            else{
                if((n+m-i) <= k) return "No";
                else return "Yes";
            }
        } 
    }else{
        if(k < (n-i)) return "No";
        else return "Yes";
    }
}

int main()
{
    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = appendAndDelete(s, t, k);

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


