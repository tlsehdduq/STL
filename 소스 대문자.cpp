//-----------------------------------------------------------------------------
//2022.3.23  ��34                    ��23��34                          (3�� 2��)
//
//  ���� - ȣ�� ���� Ÿ��(CALLABLE TYPE) - ���� (SORT)
//	�ڿ��� �����ϴ� Ŭ���� - STRING - �����̳�, �ݺ���, �˰���
//-----------------------------------------------------------------------------

#INCLUDE<IOSTREAM>
#INCLUDE<FSTREAM>
#INCLUDE<ALGORITHM>
#INCLUDE "SAVE.H"

USING NAMESPACE STD;

//[����] "�ҽ�.CPP"�� �о�
//			�ҹ��ڸ� �빮�ڷ� �����Ͽ�,
//			"�ҽ� �빮��.CPP"�� �����϶�.
 
INT MAIN() {

	IFSTREAM IN{ "�ҽ�.CPP" };
	OFSTREAM OUT{ "�ҽ� �빮��.CPP" };
	
	TRANSFORM(ISTREAMBUF_ITERATOR<CHAR>{IN}, {}, OSTREAMBUF_ITERATOR<CHAR>{OUT}, [](CHAR C) {
		RETURN TOUPPER(C); 
		});

	SAVE("�ҽ�.CPP");
}

//���� ó���ؾ��� ������ - CONTAINER  ���� Ÿ���� �����͸� �㵵��, 