#include <iostream>
#include <string>
#include <codecvt>
#include <locale>
using namespace std;

int main()
{
	string test1 = u8"aaa 이백원입니다"; // UTF-8 인코딩을 지원하지 않기 때문에 깨진 글자가 출력된다.
	cout << test1 << endl;

	string test2 = u8"aaa 이백원입니다";
	setlocale(LC_ALL, "en_US.UTF-8"); // 모든 로케일 범주를 en_US.UTF-8로 설정하게 된다
	cout << test2 << endl;

	const char16_t* test3 = u"aaa 이백원입니다";
	u16string utf16_str = test3;
	wstring_convert<codecvt_utf8_utf16<char16_t>, char16_t> convert;
	string utf8_str = convert.to_bytes(utf16_str);

	cout << utf8_str << endl;

	return 0;
}