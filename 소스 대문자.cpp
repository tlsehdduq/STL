//-----------------------------------------------------------------------------
//2022.3.23  월34                    월23수34                          (3주 2일)
//
//  오늘 - 호출 가능 타입(CALLABLE TYPE) - 정렬 (SORT)
//	자원을 관리하는 클래스 - STRING - 컨테이너, 반복자, 알고리즘
//-----------------------------------------------------------------------------

#INCLUDE<IOSTREAM>
#INCLUDE<FSTREAM>
#INCLUDE<ALGORITHM>
#INCLUDE "SAVE.H"

USING NAMESPACE STD;

//[문제] "소스.CPP"를 읽어
//			소문자를 대문자로 변경하여,
//			"소스 대문자.CPP"에 저장하라.
 
INT MAIN() {

	IFSTREAM IN{ "소스.CPP" };
	OFSTREAM OUT{ "소스 대문자.CPP" };
	
	TRANSFORM(ISTREAMBUF_ITERATOR<CHAR>{IN}, {}, OSTREAMBUF_ITERATOR<CHAR>{OUT}, [](CHAR C) {
		RETURN TOUPPER(C); 
		});

	SAVE("소스.CPP");
}

//내가 처리해야할 데이터 - CONTAINER  같은 타입의 데이터를 담도록, 