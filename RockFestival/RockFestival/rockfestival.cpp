#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
	int test;
	cin >> test;
	if (test > 100)
		exit(1);

	while(test--){
		double total_day, team;
		double result = 1000;

		cin >> total_day >> team;
		if (total_day < 1 || total_day > 1000 || team > total_day || team < 1 || team > 1000)
			exit(1);
	
		int *day = new int[(int)total_day];
		for (int i = 0; i < total_day; i++) {
			cin >> day[i];
			if (day[i] > 100)
				exit(1);
		}

		for(int a = team; a <= total_day; a ++){
			for (int i = 0; i < total_day - a + 1; i++) {
				int total = 0;
				for (int k = i; k < a + i; k++) {
					total += day[k];
				}
				if (result > ((double)total / a))
					result = ((double)total / a);
			}
		}
		printf("%.11f\n", result);
	}
	return 0;
}