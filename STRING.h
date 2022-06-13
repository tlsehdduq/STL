//-------------------------------------------------------------------------
// STRING.h - 자원을 관리하는 STL 관찰용 클래스
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

	// 5.2 sort에 필요한 연산들 정의
	difference_type operator-(const STRING_iterator& rhs) const { // ptrdiff_t 포인터 끼리 연산할때 쓰는 타입
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

//2022. 4. 27 STRING이 제공할 역방향 반복자
class STRING_reverse_iterator {
private:
	char* p;
public:
	STRING_reverse_iterator(char* p) : p{ p } {} // 인자값에 다른값 쓰기않기 ex) _p , this값 받지않기 ex) this->p = p.

	STRING_reverse_iterator& operator++() { // 자기자신을 바꾸니까 const ㄴㄴ
		--p;
		return *this;
	}

	char& operator*() const { // char&를 리턴했기 때문에 값을 읽어도 되고 써도된다.
		return *(p - 1);
	}

	// <, >, <=, >=, ==, != (관계 연산자 relational operator)
	// 관계 연산자는 우주선 연산자로 한번에 해결 - C++20
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
	size_t num{};                // 8 자원개수
	char* p;                     // 8 자원이 있는곳 
	int id;                      // 4  생성 시 부여             + 테딩?4바이트까지 해서 24바이트
	static int cid;              // 객체가 생성될때마다 1증가
public:

	STRING();
	STRING(const char* str);

	~STRING();

	STRING(const STRING& other);
	STRING& operator=(const STRING& other);

	// 2022. 4. 7 이동생성자/이동할당연산자
	STRING(STRING&& other) noexcept;
	STRING& operator=(STRING&& other) noexcept;

	STRING operator+(const STRING& rhs) const;

	// 2022. 5. 2 default < 연산자
	bool operator < (const STRING& rhs) const {
		return num < rhs.num;
	}
	// 2022. 5. 18 unorderd_set 이 요구하는 == 
	bool operator==(const STRING& rhs) const {
		return std::string(begin(), end()) == std::string(rhs.begin(), rhs.end());
	}


	// 2022. 4. 21 begin(), end() 제공
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




	size_t getNum() const; // 2022.3.30 추가

	void print(const char* s);

	friend std::ostream& operator<<(std::ostream&, const STRING&);

	// 5.2 입력반복자가 >> 로 읽을 수 있게
	friend std::istream& operator>>(std::istream&, STRING&);


};
