// link = https://www.hackerrank.com/challenges/encryption/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=60-day-campaign&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string removeBlanks(string s){
    string str = "";
    for(int i=0; i<s.length(); i++){
        if(s[i] !=' ') str += s[i];
    }
    return str;
}

string encryption(string s) {
    s = removeBlanks(s);
    int n = s.length();
    int num_rw = floor(sqrt(n));
    int num_cl = ceil(sqrt(n));
    if((num_rw * num_cl) < n) num_rw++;
    string str = "";
    for(int j=0; j<num_cl; j++){
        for(int i=0; i<num_rw; i++){
            if(j + i*num_cl < n) str += s[j + i*num_cl];
        }
        str += ' ';
    }
    return str;
}

int main()
{
    string s;
    getline(cin, s);

    string result = encryption(s);

    cout << result << "\n";

    return 0;
}
