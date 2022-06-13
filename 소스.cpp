//-----------------------------------------------------------------------------
//2022.6.8  수34                    월23수34                          (14주 2일)
//
//	anagram 찾기
//  
//   
// 6/15(수 15주 2일 ) - 기말시험 
// 6/20(월 15주 2일) - 끝
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

extern bool 관찰;

struct WP : pair<string,string>{ //word pair
	WP(string s) : pair<string, string>{ s,s } {
		sort(first.begin(), first.end());
	}
};

int main()
{

	save("소스.cpp");

	ifstream in{ "단어들.txt",ios::binary };			
	vector<WP> v{ istream_iterator<string>{in},{} };
	cout << "읽은 단어 수 - " << v.size() << endl;

	ranges::sort(v, {}, &WP::first);

	// [문제] 입력한 단어가 사전에 있다면 
	// anagram 관계에 있는 단어를 모두 출력하라.

	//for (WP words : v | views::drop(15'0000)
	//	| views::take(100))
	//	cout << words.first << " --- " << words.second << endl;
	// 
	// 단어 정렬 

	//while (true) {
	//	string word;
	//	cout << " 찾을 단어는 ? ";
	//	cin >> word;
	//	// 입력한 단어가 사전에 있나?
	//	// 사전에 있는 단어라면
	//	//	단어를 정렬한다.
	//	//	정렬한 단어와 WP의 first와 일치하는 단어 쌍을 모두 찾는다.
	//	//  WP의 second를 출력한다. 
	//	WP wp(word);
	//	auto [상한, 하한] = equal_range(v.begin(), v.end(), wp, [](const WP& a, const WP& b) {return a.first < b.first; });
	//	
	//	if (하한 == 상한)
	//		cout << word << " 는 사전에 없는 단어 입니다. " << endl;
	//	else if (상한 - 하한 == 1)
	//		cout << word << " 애너그램이 없는 단어 입니다. " << endl;
	//	else {
	//		cout << word << " -- ";
	//		for (auto i = 하한; i < 상한; ++i)
	//			cout << i->second << " ";
	//		cout << endl;
	//	}
	//}	
	for (WP words : v | views::drop(150000)
		| views::take(200))
		cout << words.first << " --- " << words.second << endl;
	 
	// [문제] 전체 anagram 쌍을 출력하라.
	// 현재 WP와 다음 WP에서 first 가 같니? - adjacent_find 
	// 같은 위치를 발견했다면 
	// 다음 달라지는 곳은 어디?
	auto b = v.cbegin();
	int cnt{};
	
	vector<list<string>> vls;



	while (true) {
		auto i = adjacent_find(b, v.cend(), [](const WP& a, const WP& b) {return a.first == b.first; });
		if (i == v.cend())
			break;
		auto j = find_if_not(i + 1, v.cend(), [i](const WP& a) {return a.first == i->first; });
		// {i , j ) 구간은 anagram 관계이다. 
		list<string>ls;

		for (auto p = i; p < j; ++p)
			ls.push_back(p->second);
		
		vls.push_back(ls);

		b = j;
	}	
	
	//vector<list<string>> 정렬
	// 개수순 
	//sort(vls.begin(), vls.end(), [](const list<string>& a, const list<string>& b) {
	//	return a.size() > b.size();
	//	});
	//cout << "가장 개수가 많은 쌍 - " << vls[0].size() << endl;
	////앞에서 부터 10개 출력

	//for (const list<string>& ls : vls | views::take(10)) {
	//	for (const string& s : ls )
	//		cout << s << " ";
	//	cout << endl;
	//}
	//정렬 단어길이가 긴것 우선 
	sort(vls.begin(), vls.end(), [](const list<string>& a, const list<string>& b) {
		return a.begin()->size() > b.begin()->size();
		});
	cout << "가장 긴 단어는  - " << vls[0].begin()->size() << endl;
	//앞에서 부터 10개 출력

	for (const list<string>& ls : vls | views::take(200)) {
		for (const string& s : ls)
			cout << s << " ";
		cout << endl;
	}

}