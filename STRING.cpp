//-----------------------------------------------------------------------------
// STRING.CPP - STL 관찰하려고 만든 자원 관리 클래스
// 
// 2022. 3. 30									Programmed by Wulong
//-----------------------------------------------------------------------------

#include <iostream>
#include "STRING.h"

bool Check{ false };			// 관찰메시지를 보려면 -> true
int STRING::gid{};			// STRING static

STRING::STRING() : id{ ++gid }, num{}, p{}
{
	if (Check)
		print("디폴트");
}

STRING::STRING(const char* s) : id{ ++gid }, num{ strlen(s) }, p{ new char[strlen(s)] }
{
	memcpy(p, s, num);
	if (Check)
		print("생성자(*)");
}

STRING::~STRING()
{
	if (Check)
		print("소멸자");
	if (num)
		delete[] p;
}

STRING::STRING(const STRING& other)
	: id{ ++gid }, num{ other.num }, p{ new char[other.num] }
{
	memcpy(p, other.p, num);

	if (Check)
		print("복사생성자");
}

STRING& STRING::operator=(const STRING& other)
{
	if (this == &other)
		return *this;

	num = other.num;
	delete[] p;
	p = new char[num];
	memcpy(p, other.p, num);

	if (Check)
		print("복사할당");

	return *this;
}


	// 이동 생성자/ 이동할당연산자 2022. 04 . 11
STRING::STRING(STRING&& other)noexcept : id{ ++gid }
{
	num = other.num;
	p = other.p;
	
	other.num = 0;
	other.p = nullptr;

	if (Check)
		print(" 이동 생성 ");
}

STRING& STRING::operator=(STRING&& other)noexcept {
	
	if (this != &other) {
		if (num)
			delete[] p;

		num = other.num;
		p = other.p;

		other.num = 0;
		other.p = nullptr;
	}
	if (Check)
		print(" 이동 할당 ");

	return *this;

}

STRING STRING::operator+(const STRING& rhs) const
{
	STRING temp;
	temp.num = num + rhs.num;
	temp.p = new char[temp.num];
	memcpy(temp.p, p, num);
	memcpy(temp.p + num, rhs.p, rhs.num);

	return temp;
}

// 2022.04.04 추가
size_t STRING::getNum() const {

	return num;

}

void STRING::print(const char* s) const
{
	std::cout << s << " [" << id << "] 객체:" << this << " 자원 - ";

	if (num != 0) {
		std::cout << " 갯수:" << num << ", 주소:" << (void*)p << std::endl;
	}
	else
		std::cout << " 없음" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const STRING& s)
{
	for (int i{}; i < s.num; ++i)
		os << s.p[i];
	return os;
};
