#include <bits/stdc++.h>
using namespace std;
/*
Input
The first line of the input file contains the number of test cases your program has to process. Each test
case is a forest description consisting of two parts:
1. A list of edges of the tree, (one per line, given as an unordered pair of capital letters delimited
by a row of asterisks).
2. A list of points in the tree, (these will be given on one line with a maximum on 26 corresponding
to the capital letters, A..Z).
Output
For each test case your program should print the number of trees and the number of acorns, in a
sentence, for example:
There are x tree(s) and y acorn(s).
where x and y are the numbers of trees and acorns, respectively.
Notes: A forest may have no trees and all acorns, all trees and no acorns, or anything in between, so
keep your eyes open and don’t miss the forest for the trees!
Example 2: Let G be a graph whose edges and points are given by the first test case in the sample
input. A depiction of this graph is given in figure following.
Sample Input
2
(A,B)
(B,C)
(B,D)
(D,E)
(E,F)
(B,G)
(G,H)
(G,I)
(J,K)
(K,L)
(K,M)
****
A,B,C,D,E,F,G,H,I,J,K,L,M,N
(A,B)
(A,C)
(C,F)
**
A,B,C,D,F
Sample Output
There are 2 tree(s) and 1 acorn(s).
There are 1 tree(s) and 1 acorn(s).
*/

vector<bool> visited;
vector<int>	neighbor[26];

void dfs( int index, int &counter ){
	int	i = 0;
	if(visited[index] == false){
        visited[index] = true;
		counter++;
		for( i = 0; i < neighbor[index].size(); i++ ) dfs(neighbor[index][i], counter);
	}
}
int main(){
	string buffer;
	int	numTree = 0;
	int	numAcorn = 0;
	int	counter = 0;
	int	t = 0;
	int	i = 0;
	cin >> t;
	while(t > 0){
		t--;
		visited.clear();
		visited.assign(26, false);
		for(i = 0; i < 26; i++) neighbor[i].clear() ;
		while( cin >> buffer, buffer[0] != '*' ){
			neighbor[buffer[1] - 'A'].push_back(buffer[3] - 'A') ;
			neighbor[buffer[3] - 'A'].push_back(buffer[1] - 'A') ;
		}
		cin >> buffer;
		numAcorn = 0;
		numTree = 0;
		for(i = 0; i < buffer.size(); i += 2){
			if(visited[buffer[i] - 'A'] == false){
				counter = 0;
				dfs(buffer[i] - 'A', counter);
				if(counter == 1)
					numAcorn++;
				else
					numTree++;
			}
		}
		cout << "There are " << numTree << " tree(s) and " << numAcorn << " acorn(s)." << endl ;
	}
	return 0 ;
}
