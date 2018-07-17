#include <string>
#include <stdio.h>

#define FOR(i,n) for(int i = 0; i<(n);++i)
const int dx[8] = { -1,0,1,-1,1,-1,0,1 };
const int dy[8] = { -1,-1,-1,0,0,1,1,1 };
char board[5][6];
using namespace std;

bool inRange(int x, int y) {
	if (x < 0 || y < 0 || x>4 || y>4)
		return false;

	return true;
}

bool hasWord(int x, int y, const string& word) {
	if (!inRange(x, y))
		return false;
	if (board[x][y] != word[0])
		return false;
	if (word.size() == 1)
		return true;

	for (int direction = 0; direction < 8; ++direction) {
		int nextX = x + dx[direction], nextY = y + dy[direction];
		if (hasWord(nextX, nextY, word.substr(1)))
			return true;
	}

	return false;
}

int main(void) {
	int test = 0;

	scanf_s("%d", &test);
	if (test < 0 || test>50)
		exit(1);

	while(test--) {
		int wordNum = 0;
		char word[11];

		FOR(i, 5) {
			scanf_s("%s",board[i],sizeof(board[i]));
		}

		scanf_s("%d", &wordNum);
		if (wordNum < 1 || wordNum >10)
			exit(1);

		while(wordNum--) {
			bool check = false;
			scanf_s("%s", word,sizeof(word));
			FOR(i, 5) {
				FOR(j, 5) {
					if (check = hasWord(i, j, word))
						break;
				}
				if (check)
					break;
			}
			printf("%s %s\n", word, check ? "YES" : "NO");
		}
	}
	return 0;
}