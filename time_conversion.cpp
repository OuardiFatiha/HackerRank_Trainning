// link = https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
       string sys = s.substr(8, 2);
       string hour = s.substr(0, 2);
       int h = stoi(hour);
       if(sys == "PM"){
          if(h == 12) return "12" + s.substr(2, 6);
          h = (h+12);
          hour = to_string(h);
          return hour + s.substr(2, 6);
       }
       else if(h == 12){
            return "00" + s.substr(2, 6);
       } 
       else return s.substr(0, 8);
}

int main()
{

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    cout << result << "\n";

    return 0;
}
