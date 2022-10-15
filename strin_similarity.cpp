#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'stringSimilarity' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int stringSimilarity(string a){
    //Solved using Z Algorithm : http://codeforces.com/blog/entry/3107
    int n = a.size();
    int z[n];
    for(int j=0; j<n; j++) z[j] = 0; 
    int l = 0;
    int r = 0;
    for(int i=1; i<n; i++){
        if (i<=r)
            z[i]=min (r - i + 1, z[i - l]);
        while(i + z[i] < n and a[z[i]] == a[i + z[i]]):
            z[i]+=1
        if (i + z[i] - 1 > r):
            l = i 
            r = i + z[i] - 1
    }        
    return sum(z)+n
}    

int main()
{

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        int result = stringSimilarity(s);

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
