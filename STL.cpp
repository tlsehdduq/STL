#include<iostream>
#include<fstream>
#include<string>
#include<format>
#include<vector>
#include<algorithm>

using namespace std;

class Player
{
	string name;
	int score;
	int id;
	size_t num;
	char* p;

public:
	void read(istream& in) {
		in.read((char*)this, sizeof(Player));
		p = new char[num];
		in.read((char*)p, num);
	}
	void write(ostream& os) {
		os.write((char*)this, sizeof(Player));
		os.write((char*)p, num);
	}



	int getScore() const { return score; }
	size_t getNum() const { return num; }

		friend ostream& operator<<(ostream& os, const Player& str);
		friend istream& operator>>(istream& is, Player& s);
};

ostream& operator<<(ostream& os, const Player& str) {
	os << "�̸� : " << str.name << " " << "���̵� : " << str.id << " " << " ���� : " << str.score << " " << " �ڿ� �� : " << str.num;
	return os;
}
istream& operator>>(istream& is, Player& s) {
	is >> s.name >> s.score >> s.num >> s.id >> s.p;
	return is;
}
int main()
{

	ifstream in{ "2022 STL ���� ����"s,ios::binary };

	if (!in)
		cout << "������ ���� ���Ͽ����ϴ�." << endl;

	Player p;
	vector<Player> v;
	v.reserve(2000000);

	for (int i = 0; i < 2'000'000; ++i) {
		p.read(in);
		v.push_back(p);
	}


	/*for (const Player& n : v) {
		cout << n << endl;
	}*/

	long long sum{};
	for (int i{}; i < v.size(); ++i) {
		sum += v[i].getScore();
	}
	cout << "��� �� : " << sum / v.size() << " �Դϴ�" << endl;

}