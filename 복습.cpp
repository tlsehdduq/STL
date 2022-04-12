#include<iostream>
#include<array>
#include<algorithm>
#include"STRING.h"

using namespace std;
extern bool Check;
int main()
{
	Check = true;
	array<STRING, 3> a{ "12345","333","12341523" };

	sort(a.begin(), a.end(), [](const STRING& a, const STRING& b) {
		return a.getNum() < b.getNum();
		});

	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << endl;


}