// 알고리즘 문제 - 보글게임 
// 5x5 크기의 알파벳 격자를 가지고 하는 게임 - 상하좌우 / 대각선으로 인접한 칸들의 글자들을 이어서 단어를 찾아내는 게임

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class boggleGame {
public:
	vector<string>map;
	const int dx[8] = { -1,-1,0,1,1,1,0,-1 };
	const int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

	boggleGame() {
		map.push_back("URLPM");
		map.push_back("XPRET");
		map.push_back("GIAET");
		map.push_back("XTNZY");
		map.push_back("XOORS");
	};

	bool hasWord(int x, int y, const string& word) {
		if (x > 4 || y > 4 || x < 0 || y < 0) return false;

		if (map[x][y] != word[0]) return false;

		if (word.size() == 1) return true;

		for (int i = 0; i < 8; i++) {
			int nextX = x + dx[i], nextY = y + dy[i];

			if (hasWord(nextX, nextY, word.substr(1)))
				return true;
		}
	}
};

int main(void) {

	boggleGame boggle;
	int x, y;
	string word;
	cout << "찾을 문자열을 입력하시오 : ";
	cin >> word;
	cout << "x 좌표를 입력하세요 : ";
	cin >> x;
	cout << "y 좌표를 입력하세요 : ";
	cin >> y;

	if (boggle.hasWord(x, y, word)) {
		cout << word << "는 존재합니다." << endl;
	}
	else { cout << word << "는 존재하지 않습니다." << endl; }

	return 0;
}

