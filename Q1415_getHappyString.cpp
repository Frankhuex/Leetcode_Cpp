#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    string getHappyString(int n, int k) {
        string abc="abc";
        string result="";
        --k;
        // Create binary string (first bit is ternary)
        int* array=(int*)malloc(n*sizeof(int));
        for (int i=n-1;i>0;i--) {
            array[i]=k%2;
            k/=2;
        }
        if (k>2) {
            return "";
        }
        array[0]=k;

        // Generate abc string
        result.push_back(abc[array[0]]);
        for (int i=1;i<n;i++) {
            int j=array[i];
            switch(result[i-1]) {
                case 'a':
                    j+=1;
                    break;
                case 'b':
                    j*=2;
                    break;
                default:
                    break;
            }
            result.push_back(abc[j]);
        }
        return result;
    }
};
int main() {
    return 0;
}