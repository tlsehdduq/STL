//-------------------------------------------------------------------------
// STRING.h - �ڿ��� �����ϴ� STL ������ Ŭ����
// 2022. 3. 30                          Programmed by Wulong
//-------------------------------------------------------------------------
#pragma once
#include <iostream>

class STRING_iterator {
public:
	using iterator_category = std::random_access_iterator_tag;
	using value_type = char;
	using difference_type = ptrdiff_t;
	using pointer = const char*;
	using reference = const char&;

private:
	char* p;
public:
	STRING_iterator(char* p) : p{ p } {}

	// 5.2 sort�� �ʿ��� ����� ����
	difference_type operator-(const STRING_iterator& rhs) const { // ptrdiff_t ������ ���� �����Ҷ� ���� Ÿ��
		return p - rhs.p;
	}

	auto operator<=>(const STRING_iterator&) const = default;

	STRING_iterator& operator++() {
		++p;
		return *this;
	}

	char& operator*() const {
		return *p;
	}

	STRING_iterator& operator--() {
		--p;
		return *this;
	}

	STRING_iterator operator+ (difference_type d) const {
		return STRING_iterator{ p + d };
	}

	STRING_iterator operator- (difference_type d) const {
		return STRING_iterator{ p - d };
	}
};

//2022. 4. 27 STRING�� ������ ������ �ݺ���
class STRING_reverse_iterator {
private:
	char* p;
public:
	STRING_reverse_iterator(char* p) : p{ p } {} // ���ڰ��� �ٸ��� ����ʱ� ex) _p , this�� �����ʱ� ex) this->p = p.

	STRING_reverse_iterator& operator++() { // �ڱ��ڽ��� �ٲٴϱ� const ����
		--p;
		return *this;
	}

	char& operator*() const { // char&�� �����߱� ������ ���� �о �ǰ� �ᵵ�ȴ�.
		return *(p - 1);
	}

	// <, >, <=, >=, ==, != (���� ������ relational operator)
	// ���� �����ڴ� ���ּ� �����ڷ� �ѹ��� �ذ� - C++20
	// spaceship operator ( three-way comparison operator)

	auto operator<=>(const STRING_reverse_iterator& rhs) const = default;

	/*bool operator!=(const STRING_reverse_iterator& rhs) const {
		return p != rhs.p;
	}*/
};


class STRING {
public:
	//2022.04.27
	using iterator = STRING_iterator;
	using reverse_iterator = STRING_reverse_iterator;
private:
	size_t num{};                // 8 �ڿ�����
	char* p;                     // 8 �ڿ��� �ִ°� 
	int id;                      // 4  ���� �� �ο�             + �׵�?4����Ʈ���� �ؼ� 24����Ʈ
	static int cid;              // ��ü�� �����ɶ����� 1����
public:

	STRING();
	STRING(const char* str);

	~STRING();

	STRING(const STRING& other);
	STRING& operator=(const STRING& other);

	// 2022. 4. 7 �̵�������/�̵��Ҵ翬����
	STRING(STRING&& other) noexcept;
	STRING& operator=(STRING&& other) noexcept;

	STRING operator+(const STRING& rhs) const;

	// 2022. 5. 2 default < ������
	bool operator < (const STRING& rhs) const {
		return num < rhs.num;
	}
	// 2022. 5. 18 unorderd_set �� �䱸�ϴ� == 
	bool operator==(const STRING& rhs) const {
		return std::string(begin(), end()) == std::string(rhs.begin(), rhs.end());
	}


	// 2022. 4. 21 begin(), end() ����
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




	size_t getNum() const; // 2022.3.30 �߰�

	void print(const char* s);

	friend std::ostream& operator<<(std::ostream&, const STRING&);

	// 5.2 �Է¹ݺ��ڰ� >> �� ���� �� �ְ�
	friend std::istream& operator>>(std::istream&, STRING&);


};
