#include <bits/stdc++.h>
using namespace std;
#define S 100000

int R[S]={0};
int A[S] = {0};
int Indx[S]= {0};
int Pre[S]={0};

void Print(int i){
    if ( i == 0) return;
    else {
        Print(Pre[i]);
        printf("%d\n",A[i]);
    }
    return;
}

int BS(int v,int s,int e){
    int mid=0;
    while(s<=e){
         mid = s+((e-s)/2);
         if (v<=R[mid]){
              if(R[mid-1]<v) break;
              e = mid-1;
         }
         else if (v>R[mid]){
            if(R[mid+1]>=v){mid= mid+1;break;}
            s = mid+1;
         }
    }
    return mid;
}

int main(){
    int i,v=0;
    int rc;
    int s,e,mid;

    A[0]=R[0] = INT_MIN;
    Indx[0] = 0;
    i=1,rc=1;

    while(scanf("%d", &A[i]) == 1){
       v = A[i];
       if(v>R[rc-1]){
           R[rc] = v;
           Indx[rc] = i;
           Pre[i] = Indx[rc-1];
           rc++;
       }
       else if(v<R[rc-1]){
           mid = BS(v,1,rc-1);
           R[mid] = v;
           Indx[mid]= i;
           Pre[i] = Indx[mid-1];
        }
        i++;
    }

    printf("%d\n-\n",rc-1);
    i = Indx[rc-1];
    Print(i);
    return 0;
}
/*
Input
The input file will contain a sequence of integers (positive, negative, and/or zero). Each line of the
input file will contain one integer.
Output
The output for this program will be a line indicating the length of the longest subsequence, a newline,
a dash character (‘-’), a newline, and then the subsequence itself printed with one integer per line. If
the input contains more than one longest subsequence, the output file should print the one that occurs
last in the input file.
Hint: Notice that the second 8 was not included — the subsequence must be strictly increasing.
Sample Input
-7
10
9
2
3
8
8
6
Sample Output
4
-
-7
2
3
6
*/
