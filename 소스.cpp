//-----------------------------------------------------------------------------
//2022.4.13  수 34                    월23수34                          (6주 2일)
//
//  자원을 관리하는 클래스 - STRING - 컨테이너 , 반복자, 알고리즘
// 
//	컨테이너 - 다른 객체를 저장하는 객체
// Sequence Container	- 원소의 순서를 임의 지정가능 
//				- array		유일하게 크기가 컴파일 타임에 결정되어야
//				- vector	dynamic array (실행 시간에 크기가 바뀌는 배열)
//				- deque	double ended queue 벡터와 리스트의 중간단계  contiguous가 아니다. 
//								벡터보다 더 많은 원소를 저장할 수 있다. 
// 
// 
//	Associative Container
// Unordered Associative Container
//				-  중간고사 시험 예정 4/20(수) (7주 2일)
// 
//  list 알아오기, 책의 예제 풀어보기,
// sequence container까지 시험범위 , 
// 그림공부 정확하게 이해가 되야되고
// 시험문제는 deque<Dog>.. 클래스를 만들어놓고 컨테이너에 내가만든 객체를 집어넣는  생각해보기 
//-----------------------------------------------------------------------------

#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<deque>
#include "save.h"
#include "STRING.h"

using namespace std;
extern bool Check;

//[문제] "소스.cpp" 파일의 단어를 deque<string>에 저장하라.
// 길이오름차순으로 정렬하라
// 정렬된 결과를 출력하라.

int main()
{
	ifstream in{ "소스.cpp" };
	string str;
	deque<string> dq;
	while (in >> str) {
		dq.push_front(str);
	}
	for (int i = 0; i < dq.size(); ++i) {
		cout << dq[i] << '\t';
	}
	sort(dq.begin(), dq.end(), [](const string& a, const string& b) {
		return a.size() < b.size(); });

	cout << endl;
	cout << endl;
	
	for (int i = 0; i < dq.size(); ++i) {
		cout << dq[i] << endl;
	}

	save("소스.cpp");
}