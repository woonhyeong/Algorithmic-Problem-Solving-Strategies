//문제 - 게임판 덮기

#include <vector>
#include <iostream>
#include <string>
#include <string.h>

#define MAX_CASE 30

using namespace std;

vector<vector<int>> table;

int cover(vector<vector<int>> table, int h, int w) {

	return 0;
}

int main() {

	int c;

	cin >> c;
	if (c > MAX_CASE || c < 0) exit(-1);

	for (int i = 0; i < c; i++) {
		int h, w;
		cin >> h >> w;
		if (h < 1 || w>20 || w < 1) exit(-1);

		for (int k = 0; k < h; k++) {
			string temp;
			vector<int> line;
			cin >> temp;

			for (int j = 0; j < w; j++) {
				if (temp[j] == '#')
					line.push_back(1);
				else line.push_back(0);
			}
			table.push_back(line);
		}

		int result = cover(table, h, w);
		cout << result << endl;
	}

	return 0;
};