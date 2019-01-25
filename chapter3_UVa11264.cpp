#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        ll Array[N];
        for(int i=0;i<N;i++){ cin>>Array[i];}
        ll Biggest=Array[0];
        int coin=1;
        for(int i=1;i<N-1;i++){
            if (Biggest+Array[i]<Array[i+1]){
                Biggest+=Array[i];
                coin++;
            }
        }
        coin++;
        cout<<coin<<endl;
    }
    return 0;
}

/*
Input
First line of the input contains T the number of test cases. Each of the test cases starts with n
(1 ≤ n ≤ 1000), the number of different types of coin. Next line contains n integers C1, C2, . . . , Cn
the value of each coin type. C1 < C2 < C3 < . . . < Cn < 1000000000. C1 equals to 1.
Output
For each test case output one line denoting the maximum number of coins that Sultan can collect in a
single withdrawal. He can withdraw infinite amount of money from the Bank.
Sample Input
2
6
1 2 4 8 16 32
6
1 3 6 8 15 20
Sample Output
6
4
*/
