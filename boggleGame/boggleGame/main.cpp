// �˰��� ���� - ���۰��� 
// 5x5 ũ���� ���ĺ� ���ڸ� ������ �ϴ� ���� - �����¿� / �밢������ ������ ĭ���� ���ڵ��� �̾ �ܾ ã�Ƴ��� ����

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
	cout << "ã�� ���ڿ��� �Է��Ͻÿ� : ";
	cin >> word;
	cout << "x ��ǥ�� �Է��ϼ��� : ";
	cin >> x;
	cout << "y ��ǥ�� �Է��ϼ��� : ";
	cin >> y;

	if (boggle.hasWord(x, y, word)) {
		cout << word << "�� �����մϴ�." << endl;
	}
	else { cout << word << "�� �������� �ʽ��ϴ�." << endl; }

	return 0;
}

