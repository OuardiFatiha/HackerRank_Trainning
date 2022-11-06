// link = https://www.hackerrank.com/challenges/queens-attack-2/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=60-day-campaign&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles){
    int i,j;
    int r = n - c_q;
    int l = c_q - 1;
    int u = n - r_q;
    int d = r_q - 1;
    int ru = min(n - c_q, n - r_q);
    int rd = min(n - c_q, r_q - 1);
    int lu = min(c_q - 1, n - r_q);
    int ld = min(c_q - 1, r_q - 1);
    if(k == 0) return r+l+u+d+ru+rd+lu+ld;
    for(vector<int> o : obstacles){
        i = o[0];
        j = o[1];
        //right
        if(i == r_q && j>c_q) r = min(r, j-c_q-1);
        //left
        if(i == r_q && j<c_q) l = min(l, c_q-j-1);
        //up
        if(i>r_q && j==c_q) u = min(u, i-r_q-1);
        //down
        if(i<r_q && j==c_q) d = min(d, r_q-i-1);
        //right up
        if(i>r_q && j>c_q && i-r_q==j-c_q) ru = min(ru, i-r_q-1);
        //right down
        if(i<r_q && j>c_q && r_q-i==j-c_q) rd = min(rd, r_q-i-1);
        //left up
        if(i>r_q && j<c_q && i-r_q==c_q-j) lu = min(lu, i-r_q-1);
        //left down
        if(i<r_q && j<c_q && r_q-i==c_q-j) ld = min(ld, r_q-i-1);
    }
    return r+l+u+d+ru+rd+lu+ld;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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


