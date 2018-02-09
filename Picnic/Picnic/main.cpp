// 소풍 문제 - 서로 친구인 두 명씩 짝을 짓는 방법의 수를 계산하는 문제

#include <iostream>
#include <string>
#include <vector>

#define MAX_CASE 50

using namespace std;

int countPair(bool taken[10]) {

}

int main() {
	int total_case;
	bool areFriend[10][10];

	cin >> total_case;
	if (total_case > MAX_CASE) exit(-1);

	for (int i = 0; i < total_case; i++) {
		int st_num, pair_num;
		cin >> st_num >> pair_num;

		bool taken[10] = { false, };

		if (st_num > 10 || st_num < 2) exit(-1);
		if (pair_num < 0 || pair_num >(st_num*(st_num - 1) / 2)) exit(-1);

		for (int k = 0; k < pair_num; k++) {
			int student1, student2;
			cin >> student1 >> student2;
			
			if (student1 == student2 || student1 <0 || student2 <0 || student1 > st_num || student2 > st_num) exit(-1);

			areFriend[student1][student2] = true;
			areFriend[student2][student1] = true;
		}
	}


	return 0;
}