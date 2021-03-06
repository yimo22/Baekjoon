/*
    joon - #1013
	contact
	Coded by yimo22  
*/
#include <iostream>
#include <string>
using namespace std;
bool IsMatched(string s)
{
    if (s.back() != '1')
        return false;
    while (!s.empty())
    {
        if (s.front() == '0')
        {                    // 0으로 시작하는 경우
            if (s[1] == '1') // 01을 포함하는 경우
                s = s.substr(2);
            else // 00을 포함하는 경우
                return false;
        }
        else
        { // 1로 시작하는 경우
            if (s.compare(0, 3, "100") == 0)
            {
                int i = 0;
                // 0+
                for (i = 3; i < s.length(); i++)
                {
                    if (s[i] != '0')
                        break;
                }
                // 1+
                for(;i<s.length();i++){
                    if(s[i] !='1'){
                        // ex) 1001001 
                        if(s[i-2] != '1')
                            break;
                        else if(s[i+1] != '1'){ // ex) 10011001
                            i--;
                        }
                        break;
                    }
                }
                s = s.substr(i);
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    // Pattern match (100+1+ | 01)+
    int N=0;
    cin >> N;
    string s[N];
    for(int i=0;i<N;i++){
        cin >> s[i];
    }
    for(int i=0;i<N;i++){
    if (IsMatched(s[i]))
        cout << "YES\n";
    else
        cout << "NO\n";
    }
    return 0;
}