//-----------------------------------------------------------------------------
// STRING - STL �����Ϸ��� ���� �ڿ� ���� Ŭ����
// 
// 2022. 3. 30									Programmed by Wulong
//-----------------------------------------------------------------------------
#pragma once

#include <iostream>
#include <compare>				//C++20 shapceship operator( three-way comparator )

// 2022 - 04 - 27 STRING�� �����ϴ� �ݺ���
class STRING_iterator {
	char* p;

public:
	STRING_iterator(char* p) : p{p}{}

	operator-(const STRING_iterator& rhs) const {
		return p - rhs.p;
	}
};


// 2022 - 04 - 27 STRING�� �����ϴ� ������ �ݺ���.
class STRING_reverse_iterator {
	char* p;

public:
	STRING_reverse_iterator(char* p) : p{ p } {}

	STRING_reverse_iterator& operator++() {
		--p;
		return *this;
	}

	char& operator*() const {
		return *(p-1);
	}

	// < , >, == , !=, <=, >=
	auto operator<=>(const STRING_reverse_iterator& rhs) const = default;

	/*bool operator!=(const STRING_reverse_iterator& rhs) const {
		std::cout << "�ڵ����ٴ� ����� �켱" << std::endl;
		return p != rhs.p;
	}*/
};

class STRING {

public:
	// 2022 - 04 - 27
	using iterator = STRING_iterator;
	using reverse_iterator = STRING_reverse_iterator;

private:
	char* p;							// Ȯ���� �ڿ� �ּ�
	size_t num;							// �����ϴ� ����Ʈ ��
	int id;								// ���� �� �ο��� id
	static int gid;						// Ŭ���� ����ƽ - id ����

public:
	STRING();
	STRING(const char* s);

	~STRING();

	STRING(const STRING& other);
	STRING& operator=(const STRING& other);
	// �̵� ������/ �̵��Ҵ翬���� 2022. 04 . 11

	STRING(STRING&& other) noexcept; // noexecept
	STRING& operator=(STRING&& other) noexcept;
	STRING operator+(const STRING& rhs) const;

	// 2022 - 04 - 27 begin()/end() ����
	iterator begin() const {
		return iterator{ p };
	}
	iterator end() const {
		return iterator{ p + num };
	}

	reverse_iterator rbegin() const {
		return reverse_iterator{ p + num };
	}

	reverse_iterator rend() const {
		return reverse_iterator{ p };
	}

	// 2022.04.04 �߰�
	size_t getNum() const;

	void print(const char* s) const;

	friend std::ostream& operator<<(std::ostream&, const STRING&);
};

