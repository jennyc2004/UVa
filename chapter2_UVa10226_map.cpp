#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	map<string, int> logbook;
	char name[35];
	scanf("%d\n\n", &n);
	while (n--) {
		int total = 0;
		while (gets(name)) {
			if (strlen(name) == 0)
				break;
			if (logbook.count(string(name)) == 0) {
				logbook[string(name)] = 1;
			} else
				logbook[string(name)] = logbook[string(name)] + 1;
			total++;
		}
		map<string, int>::iterator it;
		for (it = logbook.begin(); it != logbook.end(); it++) {
			printf("%s %.4lf\n", (*it).first.data(),
					(double) (*it).second / (double) total * 100.0);
		}
		if (n > 0){
            cout<<endl;
			logbook.clear();
		}
	}

	return 0;
}
/*
Input
The first line is the number of test cases, followed by a blank line.
Each test case of your program consists of a list of the species of every tree observed by the satellite;
one tree per line. No species name exceeds 30 characters. There are no more than 10,000 species and
no more than 1,000,000 trees.
There is a blank line between each consecutive test cases.
Output
For each test case print the name of each species represented in the population, in alphabetical order,
followed by the percentage of the population it represents, to 4 decimal places.
Print a blank line between 2 consecutive test cases.
Sample Input
1
Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow
Sample Output
Ash 13.7931
Aspen 3.4483
Basswood 3.4483
Beech 3.4483
Black Walnut 3.4483
Cherry 3.4483
Cottonwood 3.4483
Cypress 3.4483
Gum 3.4483
Hackberry 3.4483
Hard Maple 3.4483
Hickory 3.4483
Pecan 3.4483
Poplan 3.4483
Red Alder 3.4483
Red Elm 3.4483
Red Oak 6.8966
Sassafras 3.4483
Soft Maple 3.4483
Sycamore 3.4483
White Oak 10.3448
Willow 3.4483
Yellow Birch 3.448
*/
