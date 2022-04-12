//-----------------------------------------------------------------------------
// STRING - STL 관찰하려고 만든 자원 관리 클래스
// 
// 2022. 3. 30									Programmed by Wulong
//-----------------------------------------------------------------------------
#pragma once

#include <iostream>

class STRING {
	char* p;							// 확보한 자원 주소
	size_t num;							// 관리하는 바이트 수
	int id;								// 생성 시 부여한 id
	static int gid;						// 클래스 스태틱 - id 관리

public:
	STRING();
	STRING(const char* s);

	~STRING();

	STRING(const STRING& other);
	STRING& operator=(const STRING& other);
	// 이동 생성자/ 이동할당연산자 2022. 04 . 11

	STRING(STRING&& other) noexcept; // noexecept
	STRING& operator=(STRING&& other) noexcept;
	STRING operator+(const STRING& rhs) const;

	// 2022.04.04 추가
	size_t getNum() const;

	void print(const char* s) const;

	friend std::ostream& operator<<(std::ostream&, const STRING&);
};
