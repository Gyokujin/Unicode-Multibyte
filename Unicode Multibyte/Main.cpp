#include <iostream>
#include <string>
#include <codecvt>
#include <locale>
using namespace std;

int main()
{
	string test1 = u8"aaa �̹���Դϴ�"; // UTF-8 ���ڵ��� �������� �ʱ� ������ ���� ���ڰ� ��µȴ�.
	cout << test1 << endl;

	string test2 = u8"aaa �̹���Դϴ�";
	setlocale(LC_ALL, "en_US.UTF-8"); // ��� ������ ���ָ� en_US.UTF-8�� �����ϰ� �ȴ�
	cout << test2 << endl;

	const char16_t* test3 = u"aaa �̹���Դϴ�";
	u16string utf16_str = test3;
	wstring_convert<codecvt_utf8_utf16<char16_t>, char16_t> convert;
	string utf8_str = convert.to_bytes(utf16_str);

	cout << utf8_str << endl;

	return 0;
}