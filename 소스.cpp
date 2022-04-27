//-----------------------------------------------------------------------------
//2022.4.27  �� 34                    ��23��34                          (8�� 2��)
//
//  �ڿ��� �����ϴ� Ŭ���� - STRING - �����̳� , �ݺ���, �˰���
// 
//	�����̳� - �ٸ� ��ü�� �����ϴ� ��ü	
// Sequence Container
//				�ݺ��� - Iteratiors are a generalization of pointers 
//							- that allow a C++ program to work with different data structures 
//							- in a uniform manner.
// �ݺ��ڶ� �����͸� �߻�ȭ �Ѱ� 
// �ڷᱸ���� �ϰ��� ������� �����ϱ� ���ؼ�.
// 
//	Associative Container
// Unordered Associative Container
// 
//  C++ 20 concept �� ���캸��./ (������ 3��) module, range, coroutine
// 
// ���� �ڵ��ؼ� �˾ƺ� ����
//  - �ݺ��� ���� ����
//  - STRING�� �ݺ��ڸ� �ڵ� - �ݺ��ڴ� �����̳ʰ� �����ϴ� Ŭ������ �Ǿ��
//  - sort(str.begin(), str.end()); STRING�� sort�� �ǰ� ����
//		
//-----------------------------------------------------------------------------

#include<iostream>
#include<algorithm>
#include<string>
#include<array>
#include"STRING.h"
#include "save.h"

using namespace std;

//���δٸ� �ڷ����� �����ϱ� ���ø�
template <class Iter>
void show(Iter)
{
	// [����] Iter�� catergory�� ����϶�.

	cout << typeid(Iter::iterator_category).name() << endl;

}

int main()
{
	STRING str{ "The quick brown fox jumps over the lazy dog" };
	// [����] str�� sort�� ������ �� �ְ� �Ѵ�.
	
	sort(str.begin(), str.end());
	

	save("�ҽ�.cpp");
}
