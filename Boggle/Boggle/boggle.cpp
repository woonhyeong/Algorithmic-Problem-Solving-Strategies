#include <string.h>
#include <stdio.h>
#include <cstdlib>
#define FOR(i,n) for(int i = 0; i<(n);++i)

const int dx[8] = { -1,0,1,-1,1,-1,0,1 };
const int dy[8] = { -1,-1,-1,0,0,1,1,1 };
char board[5][6];
char table[5][5][10];
char word[11];
int wordLength;
using namespace std;

bool inRange(int x, int y) {
	if (x < 0 || y < 0 || x>4 || y>4)
		return false;
	return true;
}

bool hasWord(int x, int y, int index) {
	if (!inRange(x, y))
		return false;
	if (index + 1 >= wordLength)
		return true;

	FOR(direction, 8) {
		int nextX = x + dx[direction], nextY = y + dy[direction];

		if (inRange(nextX, nextY) && (table[nextX][nextY][index + 1] == 1) && (board[nextX][nextY] == word[index + 1]) && hasWord(nextX, nextY, index + 1))
			return true;
	}

	table[x][y][index] = 0;

	return false;
}

int main(void) {
	int test = 0;

	scanf_s("%d", &test);
	if (test < 0 || test>50)
		exit(1);

	while (test--) {
		int wordNum = 0;

		FOR(i, 5) {
			scanf_s("%s", board[i], sizeof(board[i]));
		}

		scanf_s("%d", &wordNum);
		if (wordNum < 1 || wordNum >10)
			exit(1);

		while (wordNum--) {
			bool check = false;
			scanf_s("%s", word, sizeof(word));
			wordLength = strlen(word);
			memset(table, 1, sizeof(table));

			FOR(i, 5) {
				FOR(j, 5) {
					if ((board[i][j] == word[0]) && hasWord(i, j, 0)) {
						check = true;
						break;
					}
				}
				if (check)
					break;
			}
			printf("%s %s\n", word, check ? "YES" : "NO");
		}
	}
	return 0;
}