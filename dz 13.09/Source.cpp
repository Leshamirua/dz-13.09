#include <iostream>
using namespace std;

class MyString {
private:
	char* str;
	char* strsearch;
	char* nwstr;
	int length;
	static int count;
public:
	MyString();
	MyString(const char* txt);
	~MyString();
	void Input();
	const void Print();
	MyString(const MyString& str);
	const bool MyStrStr(const char* str);
	const void  MyChr();
	const int MyStrLen();
	const void MyStrCat(MyString& obj);
	const void MyDelChr();
	const int MyStrCmp(MyString& b);
	static int GetCount()
	{
		cout << endl << "Obj in MyString:";
		return count;
	}
};
int MyString::count = 0;


const int MyString::MyStrLen()
{
	int length = strlen(str);
	cout << endl << "Characters in text: " << length;

	return 0;
}

const void MyString::MyStrCat(MyString& obj)
{

	MyString newStr;

	int length = strlen(str);
	int secondlength = strlen(obj.str);

	newStr.str = new char[length + secondlength + 1];

	int i = 0;

	for (; i < length; i++)
	{
		newStr.str[i] = str[i];
	}


	for (size_t j = 0; j < secondlength; j++, i++)
	{
		newStr.str[i] = obj.str[j];
	}

	cout << newStr.str[length + secondlength];



}

const void MyString::MyDelChr()
{
	char c;

	int length = strlen(str);
	cout << endl << "Input symbol for Del:";
	cin >> c;
	int Index = -1;

	for (int i = 0; i < length; ++i) {
		if (str[i] == c) {
			Index = i;
			break;
		}
	}

	if (Index == -1) {
		return;
	}

	MyString Temp;

	delete[] Temp.str;

	Temp.length = --length;
	Temp.str = new char[Temp.length];

	for (int i = 0; i < Index; ++i) {
		Temp.str[i] = str[i];
	}

	for (int i = Index; i < Temp.length; ++i) {
		Temp.str[i] = str[i + 1];
	}

	delete[] str;

	length = Temp.length;
	str = new char[length];

	strcpy_s(str, length, Temp.str);
}

const int MyString::MyStrCmp(MyString& b)
{
	if (this->length > b.length) {
		return 1;
	}
	else if (this->length < b.length) {
		return -1;
	}
	else {
		return 0;
	}


}

const void MyString::MyChr()
{
	cout << endl << "Input symbol for search:";
	char submol;
	cin >> submol;
	int count = 1;
	int coub = 1;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == submol) {

			cout << endl << "Symbol " << submol << " : " << count;
			coub = true;
			break;

		}
		else {
			count++;
			coub = false;
		}
	}
	if (coub == false) {
		cout << endl << "Symbol not found";

	}

}



MyString::MyString(const MyString& temp)
{
	str = new char[strlen(temp.str) + 1];
	strcpy_s(str, strlen(temp.str) + 1, temp.str);
	cout << endl << "Copyy";
}

const bool MyString::MyStrStr(const char* str)
{
	int Size = strlen(str);
	for (int i = 0; i < Size; ++i) {
		for (int j = i; j < strlen(str) + 1; ++j) {
			if (this->str[j] != str[j - i]) {
				continue;
			}

			else if (str[j] == '\0') {
				return true;
			}
		}
	}

	return false;



}



MyString::MyString()
{
	count++;
	str = nullptr;
	length = 0;
}

MyString::MyString(const char* txt)
{
	count++;
	str = new char[strlen(txt) + 1];
	strcpy_s(str, strlen(txt) + 1, txt);


}

MyString::~MyString()
{
	delete[]str;
	count--;
}

void MyString::Input()
{
	count++;
	char buff[80];
	cout << "Enter txt -  ";
	cin.getline(buff, 80);
	if (str != nullptr)
	{
		delete[]str;
	}
	str = new char[strlen(buff) + 1];
	strcpy_s(str, strlen(buff) + 1, buff);
	length = strlen(str);

}

const void MyString::Print()
{
	cout << endl << "txt - " << str;
}




int main() {



	MyString obj1;
	MyString obj5;
	MyString str("1234567890234567890123456789012345678901234567890123456789012345678902345678901234567890");

	obj1.Input();
	obj1.Print();
	MyString obj2(obj1);
	obj2.Print();
	obj1.MyChr();
	obj1.MyStrLen();
	obj1.Print();

	cout << MyString::GetCount();


}