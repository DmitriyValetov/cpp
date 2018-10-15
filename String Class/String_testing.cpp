#include "String.cpp"
#include <iostream>
using namespace std;
int main()
{
	S str1;
	S str2('a');
	S str3("abc");
	S str4(str3);

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;


	cout << str4+str2 << endl;
	str3 += str2;
	cout << str3 << endl;
	str3 = str4;
    cout << str3 << endl;
	cout << str3.length() << endl;
	cout << str3[1] << endl;
	cout << *(str3.str()) << endl;


	return 0;
}