//-------------------------------------------------------------------------
// STRING.cpp - �ڿ��� �����ϴ� STL ������ Ŭ����
// 2022. 3. 30                          Programmed by Wulong
//-------------------------------------------------------------------------
#include <iostream>
#include "STRING.h"

bool ����{}; // �޽����� ������ true��

STRING::STRING() : num{}, p{}, id{ ++cid }
{
	if (����)
		print("����Ʈ");
}

STRING::STRING(const char* str) : num{ strlen(str) }, id{ ++cid }
{
	p = new char[num];
	memcpy(p, str, num);

	if (����)
		print("������(*)");
}

STRING::STRING(const STRING& other) : num{ other.num }, id{ ++cid } // ���� ������
{
	p = new char[num];
	memcpy(p, other.p, num);
	if (����) {
		print("���� ����");
	}
}

STRING::~STRING()
{
	if (����) {
		print("�Ҹ���");
	}
	if (num)
		delete[] p;
}

STRING& STRING::operator=(const STRING& other) // ���� ���� (�ӽ� ��ü�� �������� �ʴ´�.)
{
	if (this == &other) { // �ڱ� �ڽ��� �Ҵ� �ϴ°��� ����
		return *this;
	}

	if (num) // �̹� �ڿ��� �Ҵ��ϰ������� ����
		delete[] p;

	num = other.num;
	p = new char[num];
	memcpy(p, other.p, num);

	if (����)
		print("�����Ҵ�");

	return *this;
}

STRING::STRING(STRING&& other) noexcept : id{ ++cid } // 2022. 4. 7 �̵�������/�̵��Ҵ翬����
{
	num = other.num;
	p = other.p;

	other.num = 0;
	other.p = nullptr;

	if (����)
		print("�̵�����");
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

	if (����)
		print("�̵��Ҵ�");
	return *this;
}

STRING STRING::operator+(const STRING& rhs) const  // �ӽ� ��ü�� �����ϱ� ������ const
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
	std::cout << s << ", [" << id << "] ��ü : " << this;
	if (num) {
		std::cout << " �ڿ� �� : " << num << " �ּ� : " << (void*)p;
	}
	else
		std::cout << " �ڿ� ����";
	std::cout << std::endl;
}

int STRING::cid{}; //����ƽ���� �ʱ�ȭ

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