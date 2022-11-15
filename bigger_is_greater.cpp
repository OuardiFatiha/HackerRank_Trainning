// link = https://www.hackerrank.com/challenges/bigger-is-greater/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=60-day-campaign&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

int getIndex(vector<char> v, char K)
{
    auto it = find(v.begin(), v.end(), K);
  
    // If element was found
    if (it != v.end()) 
    {
      
        // calculating the index
        // of K
        int index = it - v.begin();
        return index;
    }
    else {
        // If the element is not
        // present in the vector
        return -1;
    }
}

int findRepeatFirstN2(string s)
{
    // this is O(N^2) method
    int p = -1, i, j;
    for (i = 0; i < s.length(); i++)
    {
        for (j = i + 1; j < s.length(); j++)
        {
            if (s[i] == s[j])
            {
                p = i;
                break;
            }
        }
        if (p != -1)
            break;
    }
 
    return p;
}

string biggerIsGreaterAux(string w){
    vector<char> orgChars(w.begin(), w.end());
    vector<char> chars = orgChars;
    sort(chars.begin(), chars.end());
    string w_plus = w;
    int i = w.length() - 2;
    char c;
    while(i>=0){
        c = w[i];
        // check if there are characters greater than c in chars
        int index = getIndex(chars, c); 
        if(index < chars.size()-1){
            // check if those charcters does not exist before c in w
            for(int j=index+1; j<chars.size(); j++){
                int index2 = getIndex(orgChars, chars[j]);
                if(index2 > index){
                    swap(w_plus[i], w_plus[index2]);
                    sort(w_plus.begin()+i+1, w_plus.end());
                    return w_plus;
                }else if(index2 == index){
                    return "no answer";
                }

            }
        }else{
            i--;
        }
    }
    return "no answer";
}

string biggerIsGreater(string w){
    int pos = findRepeatFirstN2(w);
    if(pos == -1){
        return biggerIsGreaterAux(w);
    }else{
        char delimiter = w[pos];
        string token = w.substr(0, w.find(delimiter)) + delimiter;
        string res = biggerIsGreaterAux(token);
        // if(res == "no answer" && res!=""){
        //     token = w.substr(0, w.find(delimiter)) + delimiter;
        // res = biggerIsGreaterAux(token);
        // }
        return res;
    }
}

int main()
{
    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

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
