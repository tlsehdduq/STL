//-----------------------------------------------------------------------------
//2022.6.8  ��34                    ��23��34                          (14�� 2��)
//
//	anagram ã��
//  
//   
// 6/15(�� 15�� 2�� ) - �⸻���� 
// 6/20(�� 15�� 2��) - ��
//-----------------------------------------------------------------------------

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<ranges>
#include<list>
#include<set>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool ����;

struct WP : pair<string,string>{ //word pair
	WP(string s) : pair<string, string>{ s,s } {
		sort(first.begin(), first.end());
	}
};

int main()
{

	save("�ҽ�.cpp");

	ifstream in{ "�ܾ��.txt",ios::binary };			
	vector<WP> v{ istream_iterator<string>{in},{} };
	cout << "���� �ܾ� �� - " << v.size() << endl;

	ranges::sort(v, {}, &WP::first);

	// [����] �Է��� �ܾ ������ �ִٸ� 
	// anagram ���迡 �ִ� �ܾ ��� ����϶�.

	//for (WP words : v | views::drop(15'0000)
	//	| views::take(100))
	//	cout << words.first << " --- " << words.second << endl;
	// 
	// �ܾ� ���� 

	//while (true) {
	//	string word;
	//	cout << " ã�� �ܾ�� ? ";
	//	cin >> word;
	//	// �Է��� �ܾ ������ �ֳ�?
	//	// ������ �ִ� �ܾ���
	//	//	�ܾ �����Ѵ�.
	//	//	������ �ܾ�� WP�� first�� ��ġ�ϴ� �ܾ� ���� ��� ã�´�.
	//	//  WP�� second�� ����Ѵ�. 
	//	WP wp(word);
	//	auto [����, ����] = equal_range(v.begin(), v.end(), wp, [](const WP& a, const WP& b) {return a.first < b.first; });
	//	
	//	if (���� == ����)
	//		cout << word << " �� ������ ���� �ܾ� �Դϴ�. " << endl;
	//	else if (���� - ���� == 1)
	//		cout << word << " �ֳʱ׷��� ���� �ܾ� �Դϴ�. " << endl;
	//	else {
	//		cout << word << " -- ";
	//		for (auto i = ����; i < ����; ++i)
	//			cout << i->second << " ";
	//		cout << endl;
	//	}
	//}	
	for (WP words : v | views::drop(150000)
		| views::take(200))
		cout << words.first << " --- " << words.second << endl;
	 
	// [����] ��ü anagram ���� ����϶�.
	// ���� WP�� ���� WP���� first �� ����? - adjacent_find 
	// ���� ��ġ�� �߰��ߴٸ� 
	// ���� �޶����� ���� ���?
	auto b = v.cbegin();
	int cnt{};
	
	vector<list<string>> vls;



	while (true) {
		auto i = adjacent_find(b, v.cend(), [](const WP& a, const WP& b) {return a.first == b.first; });
		if (i == v.cend())
			break;
		auto j = find_if_not(i + 1, v.cend(), [i](const WP& a) {return a.first == i->first; });
		// {i , j ) ������ anagram �����̴�. 
		list<string>ls;

		for (auto p = i; p < j; ++p)
			ls.push_back(p->second);
		
		vls.push_back(ls);

		b = j;
	}	
	
	//vector<list<string>> ����
	// ������ 
	//sort(vls.begin(), vls.end(), [](const list<string>& a, const list<string>& b) {
	//	return a.size() > b.size();
	//	});
	//cout << "���� ������ ���� �� - " << vls[0].size() << endl;
	////�տ��� ���� 10�� ���

	//for (const list<string>& ls : vls | views::take(10)) {
	//	for (const string& s : ls )
	//		cout << s << " ";
	//	cout << endl;
	//}
	//���� �ܾ���̰� ��� �켱 
	sort(vls.begin(), vls.end(), [](const list<string>& a, const list<string>& b) {
		return a.begin()->size() > b.begin()->size();
		});
	cout << "���� �� �ܾ��  - " << vls[0].begin()->size() << endl;
	//�տ��� ���� 10�� ���

	for (const list<string>& ls : vls | views::take(200)) {
		for (const string& s : ls)
			cout << s << " ";
		cout << endl;
	}

}