#include <cstdlib> //��� ������� ������
#include <iostream> //��� ������ � �����������
#include <fstream> //��� ������ � ��������� ��������

using namespace std;

void main()
{
	system("CLS"); //������� ������
	int y = 0; //Y ����� ���������� � ����
	int x = 0; //X ����� ��������� �� �����

	cout << "Y = "; cin >> y; //������ �����, ������� ����� ��������� � ����
	ofstream out("1.txt",ios::binary|ios::out); //��������� ���� � �������� ������ ��� ������
	out.write((char*)&y, sizeof y); //���������� � ���� ����� y
	out.close(); //��������� ����

	cout << "x = " << x << endl; //���������� X �� ��� ���������

	ifstream in("1.txt",ios::binary|ios::in); //��������� ���� � �������� ������ ������ ��� ������
	in.read((char*)&x, sizeof x); //������ ������ ���������� � ���������� � � X
	in.close(); //��������� ����

	cout << "x = " << x << endl; //���������� X ����� ���������
	system("PAUSE");
}