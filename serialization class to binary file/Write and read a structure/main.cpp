#include <iostream> //��� ������ � �����������
#include <fstream> //��� ������ � �������
#include <cstdlib> //��� ������� ������

using namespace std;

//���� ���������
struct MyStruct
{
	char *Name;
	int size;
};

void main()
{
	system("CLS"); //������� ������
	MyStruct X, Y; //������� ��� ������� ��������������� ����� ���������
				   //�������� ������ X ����� ����� ���������
	X.Name = "bear"; //
	X.size = 100; //

				  //��������� ���� ��� ������ � �������� ������
	ofstream out("2.txt",ios::binary|ios::out);
	out.write((char*)&X, sizeof X); //���������� ������ X � �������� ���� ����
	out.close(); //��������� �������� ����

				 //��������� ���� ������ ��� ������, ��������� � �������� ������
	fstream in("2.txt",ios::binary|ios::in);
	in.read((char*)&Y, sizeof Y); //��������� ���������� � ������ Y
	in.close(); //��������� �������� ����

				//���������� ������ Y �� ��� ��������� ������
	cout << Y.Name << "\n";
	cout << Y.size << "\n";

	cin.get();

}