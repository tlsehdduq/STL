//-----------------------------------------------------------------------------
//2022.4.13  �� 34                    ��23��34                          (6�� 2��)
//
//  �ڿ��� �����ϴ� Ŭ���� - STRING - �����̳� , �ݺ���, �˰���
// 
//	�����̳� - �ٸ� ��ü�� �����ϴ� ��ü
// Sequence Container	- ������ ������ ���� �������� 
//				- array		�����ϰ� ũ�Ⱑ ������ Ÿ�ӿ� �����Ǿ��
//				- vector	dynamic array (���� �ð��� ũ�Ⱑ �ٲ�� �迭)
//				- deque	double ended queue ���Ϳ� ����Ʈ�� �߰��ܰ�  contiguous�� �ƴϴ�. 
//								���ͺ��� �� ���� ���Ҹ� ������ �� �ִ�. 
// 
// 
//	Associative Container
// Unordered Associative Container
//				-  �߰���� ���� ���� 4/20(��) (7�� 2��)
// 
//  list �˾ƿ���, å�� ���� Ǯ���,
// sequence container���� ������� , 
// �׸����� ��Ȯ�ϰ� ���ذ� �Ǿߵǰ�
// ���蹮���� deque<Dog>.. Ŭ������ �������� �����̳ʿ� �������� ��ü�� ����ִ�  �����غ��� 
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

//[����] "�ҽ�.cpp" ������ �ܾ deque<string>�� �����϶�.
// ���̿����������� �����϶�
// ���ĵ� ����� ����϶�.

int main()
{
	ifstream in{ "�ҽ�.cpp" };
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

	save("�ҽ�.cpp");
}