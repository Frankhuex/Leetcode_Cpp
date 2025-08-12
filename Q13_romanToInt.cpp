#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
//罗马数
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> hash={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int last=hash[s[s.size()-1]];
        int cur;
        int sum=last;
        for (int i=s.size()-2;i>=0;--i) {
            cur=hash[s[i]];
            if (cur<last) sum-=cur;
            else sum+=cur;
            last=cur;
        }
        return sum;
    }
    
    int romanToInt2(string s) {
        unordered_map<char,char> one2five={{'I','V'},{'X','L'},{'C','D'}};
        unordered_map<char,char> one2ten={{'I','X'},{'X','C'},{'C','M'}};
        unordered_map<char,int> value={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int i=0,sum=0,size=s.size();
        char c;
        while (1) {
            if (i==size) break;
            c=s[i];
            if (c=='I' || c=='X' || c=='C') {
                if (s[i+1]==c) {
                    if (s[i+2]==c) {
                        sum+=3*value[c];
                        i+=3;
                    }
                    else {
                        sum+=2*value[c];
                        i+=2;
                    }
                }
                else if (s[i+1]==one2five[c]) {
                    sum+=4*value[c];
                    i+=2;
                }
                else if (s[i+1]==one2ten[c]) {
                    sum+=9*value[c];
                    i+=2;
                }
                else {
                    sum+=value[c];
                    ++i;
                }
            }
            else {
                sum+=value[c];
                ++i;
            }
        }
        return sum;
    }
};
int main() {
    return 0;
}