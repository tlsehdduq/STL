//-----------------------------------------------------------------------------
//2022.4.27  수 34                    월23수34                          (8주 2일)
//
//  자원을 관리하는 클래스 - STRING - 컨테이너 , 반복자, 알고리즘
// 
//	컨테이너 - 다른 객체를 저장하는 객체	
// Sequence Container
//				반복자 - Iteratiors are a generalization of pointers 
//							- that allow a C++ program to work with different data structures 
//							- in a uniform manner.
// 반복자란 포인터를 추상화 한것 
// 자료구조를 일관된 방식으로 접근하기 위해서.
// 
//	Associative Container
// Unordered Associative Container
// 
//  C++ 20 concept 을 살펴보자./ (나머지 3개) module, range, coroutine
// 
// 오늘 코딩해서 알아볼 내용
//  - 반복자 종류 판정
//  - STRING의 반복자를 코딩 - 반복자는 컨테이너가 제공하는 클래스가 되어야
//  - sort(str.begin(), str.end()); STRING이 sort가 되게 하자
//		
//-----------------------------------------------------------------------------

#include<iostream>
#include<algorithm>
#include<string>
#include<array>
#include"STRING.h"
#include "save.h"

using namespace std;

//서로다른 자료형이 들어오니까 템플릿
template <class Iter>
void show(Iter)
{
	// [문제] Iter의 catergory로 출력하라.

	cout << typeid(Iter::iterator_category).name() << endl;

}

int main()
{
	STRING str{ "The quick brown fox jumps over the lazy dog" };
	// [도전] str을 sort로 정렬할 수 있게 한다.
	
	sort(str.begin(), str.end());
	

	save("소스.cpp");
}
