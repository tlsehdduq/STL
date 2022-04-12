//-----------------------------------------------------------------------------
//SAVE.CPP
//
// 저장할 파일을 알려주면 한학기 강의를 저장할 파일에 덧붙인다.
//        "2022 1학기 STL 월23수34 강의저장.txt"
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
	//읽을 파일을 연다
	std::ifstream in{ fname.data() };

	//저장할 파일도 연다(덧붙이기 모드로 열어야 한다)
	std::ofstream out{ "2022 1학기 STL 월23수34 강의저장.txt",std::ios::app };

	// 저장할 파일의 이름과 크기를 기록한다(c++17)
	out << "파일 정보 : " << fname << ", 크기:" << std::filesystem::file_size(fname) << std::endl;//17

	//현재 시간을 화면에 출력한다.
	auto time = floor<std::chrono::seconds>(std::chrono::system_clock::now());
	out << std::chrono::zoned_time("Asia/Seoul", time) << std::endl;


	out << " 저장 시간 : " << std::chrono::zoned_time("Asia/Seoul", time) << std::endl;//20
	out << std::endl;

	// 벡터를 만들면서 in 파일의 내용을 다 읽어온다 (STL 컨테이너)
	std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };


	// v로 읽어 온 파일을 out에 출력한다.(STL 알고리즘)
	copy(v.begin(), v.end(), std::ostream_iterator<char>{out});
}