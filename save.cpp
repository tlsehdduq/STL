//-----------------------------------------------------------------------------
//SAVE.CPP
//
// ������ ������ �˷��ָ� ���б� ���Ǹ� ������ ���Ͽ� �����δ�.
//        "2022 1�б� STL ��23��34 ��������.txt"
//	
// 2022. 3 . 7		

#include "save.h"
#include<fstream>
#include<filesystem>
#include<chrono>
#include<vector>
#include<algorithm>

void save(std::string_view fname)
{
	//���� ������ ����
	std::ifstream in{ fname.data() };

	//������ ���ϵ� ����(�����̱� ���� ����� �Ѵ�)
	std::ofstream out{ "2022 1�б� STL ��23��34 ��������.txt",std::ios::app };

	// ������ ������ �̸��� ũ�⸦ ����Ѵ�(c++17)
	out << "���� ���� : " << fname << ", ũ��:" << std::filesystem::file_size(fname) << std::endl;//17

	//���� �ð��� ȭ�鿡 ����Ѵ�.
	auto time = floor<std::chrono::seconds>(std::chrono::system_clock::now());
	out << std::chrono::zoned_time("Asia/Seoul", time) << std::endl;


	out << " ���� �ð� : " << std::chrono::zoned_time("Asia/Seoul", time) << std::endl;//20
	out << std::endl;

	// ���͸� ����鼭 in ������ ������ �� �о�´� (STL �����̳�)
	std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };


	// v�� �о� �� ������ out�� ����Ѵ�.(STL �˰���)
	copy(v.begin(), v.end(), std::ostream_iterator<char>{out});
}