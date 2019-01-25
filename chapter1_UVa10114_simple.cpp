#include <bits/stdc++.h>
using namespace std;
/*
Input
Input consists of information for several loans. Each loan consists of one line containing the duration in
months of the loan, the down payment, the amount of the loan, and the number of depreciation records
that follow. All values are nonnegative, with loans being at most 100 months long and car values at most
$75,000. Since depreciation is not constant, the varying rates are specified in a series of depreciation
records. Each depreciation record consists of one line with a month number and depreciation percentage,
which is more than 0 and less than 1. These are in strictly increasing order by month, starting at
month 0. Month 0 is the depreciation that applies immediately after driving the car off the lot and
is always present in the data. All the other percentages are the amount of depreciation at the end of
the corresponding month. Not all months may be listed in the data. If a month is not listed, then the
previous depreciation percentage applies. The end of the input is signalled by a negative loan duration
- the other three values will be present but indeterminate.
For simplicity, we will assume a 0% interest loan, thus the car’s initial value will be the loan amount
plus the down payment. It is possible for a car’s value and amount owed to be positive numbers less
than $1.00. Do not round values to a whole number of cents ($7,347.635 should not be rounded to
$7,347.64).
Consider the first example below of borrowing $15,000 for 30 months. As the buyer drives off the
lot, he still owes $15,000, but the car has dropped in value by 10% to $13,950. After 4 months, the
buyer has made 4 payments, each of $500, and the car has further depreciated 3% in months 1 and 2
and 0.2% in months 3 and 4. At this time, the car is worth $13,073.10528 and the borrower only owes
$13,000.
Output
For each loan, the output is the number of complete months before the borrower owes less than the car
is worth. Note that English requires plurals (5 months) on all values other than one (1 month).
Sample Input
30 500.0 15000.0 3
0 .10
1 .03
3 .002
12 500.0 9999.99 2
0 .05
2 .1
60 2400.0 30000.0 3
0 .2
1 .05
12 .025
-99 0 17000 1
Sample Output
4 months
1 month
49 months
*/
int main(){
	int a,d;
	double b,c;
	while (cin>>a>>b>>c>>d, a >= 0){
		double loan,totalValue,monthlyPay;
		loan = c;
		totalValue = c + b;
		monthlyPay = c / a;
		int e,month = 0;
		bool flag = true;
		cin>>e;
		for (int i = 0; i < d; i++){
			double f;
			cin>>f;
			if (i != d-1) cin>>e;
			else e = a;
			for (; month < e && flag; month++){
				if (month != 0) loan -= monthlyPay;
				totalValue *= (1-f);
				if (totalValue > loan) {
					flag = false;
					break;
				}
			}
		}
		month == 1?cout<<"1 month"<<endl:cout<<month<<" months"<<endl;
	}
}

