// link = https://www.hackerrank.com/challenges/the-grid-search/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gridSearch' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY G
 *  2. STRING_ARRAY P
 */

// function to get the index of s2 in s1
int isSubstring(string s1, string s2){
    // using find method to check if s2 is
    // a substring of s1
    if (s1.find(s2) != string::npos)
        return s1.find(s2);
    return -1;
}

string gridSearch(vector<string> G, vector<string> P) {
    int pre_index = isSubstring(G[0], P[0]);
    int index = pre_index;

    for(int j=0; j<P.size(); j++){
        bool isStrInGrid = false;
        for(int i=0; i<=(G.size() - P.size() + j); i++){
            index = isSubstring(G[i], P[j]);
            cout<<"Grid str: "<<G[i]<<endl;
            cout<<"Pattern str: "<<P[j]<<endl;
            cout<<"index: "<<index<<endl;
            cout<<"******************"<<endl;
            if(index != -1 && index == pre_index){
                isStrInGrid = true;
            }
            pre_index = index;
        }
        if(isStrInGrid == false) return "NO";
    } 

    return "YES";
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int R = stoi(first_multiple_input[0]);

        int C = stoi(first_multiple_input[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string second_multiple_input_temp;
        getline(cin, second_multiple_input_temp);

        vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

        int r = stoi(second_multiple_input[0]);

        int c = stoi(second_multiple_input[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
