//-------------------------------------------------------------------------
// STRING.cpp - 자원을 관리하는 STL 관찰용 클래스
// 2022. 3. 30                          Programmed by Wulong
//-------------------------------------------------------------------------
#include <iostream>
#include "STRING.h"

bool 관찰{}; // 메시지를 보려면 true로

STRING::STRING() : num{}, p{}, id{ ++cid }
{
	if (관찰)
		print("디폴트");
}

STRING::STRING(const char* str) : num{ strlen(str) }, id{ ++cid }
{
	p = new char[num];
	memcpy(p, str, num);

	if (관찰)
		print("생성자(*)");
}

STRING::STRING(const STRING& other) : num{ other.num }, id{ ++cid } // 복사 생성자
{
	p = new char[num];
	memcpy(p, other.p, num);
	if (관찰) {
		print("복사 생성");
	}
}

STRING::~STRING()
{
	if (관찰) {
		print("소멸자");
	}
	if (num)
		delete[] p;
}

STRING& STRING::operator=(const STRING& other) // 깊은 복사 (임시 객체를 리턴하지 않는다.)
{
	if (this == &other) { // 자기 자신을 할당 하는것을 방지
		return *this;
	}

	if (num) // 이미 자원을 할당하고있으면 해제
		delete[] p;

	num = other.num;
	p = new char[num];
	memcpy(p, other.p, num);

	if (관찰)
		print("복사할당");

	return *this;
}

STRING::STRING(STRING&& other) noexcept : id{ ++cid } // 2022. 4. 7 이동생성자/이동할당연산자
{
	num = other.num;
	p = other.p;

	other.num = 0;
	other.p = nullptr;

	if (관찰)
		print("이동생성");
}

STRING& STRING::operator=(STRING&& other) noexcept
{
	if (this != &other) {
		if (num)
			delete[] p;

		num = other.num;
		p = other.p;

		other.num = 0;
		other.p = nullptr;
	}

	if (관찰)
		print("이동할당");
	return *this;
}

STRING STRING::operator+(const STRING& rhs) const  // 임시 객체를 리턴하기 때문에 const
{
	STRING temp;

	temp.num = num + rhs.num;
	temp.p = new char[temp.num];
	memcpy(temp.p, p, num);
	memcpy(temp.p + num, rhs.p, rhs.num);

	return temp;
}

size_t STRING::getNum() const
{
	return num;
}

void STRING::print(const char* s)
{
	std::cout << s << ", [" << id << "] 객체 : " << this;
	if (num) {
		std::cout << " 자원 수 : " << num << " 주소 : " << (void*)p;
	}
	else
		std::cout << " 자원 없음";
	std::cout << std::endl;
}

int STRING::cid{}; //스태틱변수 초기화

std::ostream& operator<<(std::ostream& os, const STRING& s)
{
	for (int i = 0; i < s.num; ++i)
		os << s.p[i];
	return os;
}

std::istream& operator>>(std::istream& is, STRING& s) {
	std::string str;

	is >> str;

	s = STRING(str.c_str());

	return is;
}