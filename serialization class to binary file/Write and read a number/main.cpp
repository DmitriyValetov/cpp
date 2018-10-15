#include <cstdlib> //Для очистки экрана
#include <iostream> //Для работы с клавиатурой
#include <fstream> //Для работы с файловыми потоками

using namespace std;

void main()
{
	system("CLS"); //Очистка экрана
	int y = 0; //Y будем записывать в файл
	int x = 0; //X будем считывать из файла

	cout << "Y = "; cin >> y; //Вводим число, которое нужно сохранить в файл
	ofstream out("1.txt",ios::binary|ios::out); //Открываем файл в двоичном режиме для записи
	out.write((char*)&y, sizeof y); //Записываем в файл число y
	out.close(); //Закрываем файл

	cout << "x = " << x << endl; //Показываем X до его изменений

	ifstream in("1.txt",ios::binary|ios::in); //Открываем файл в двоичном режиме только для чтения
	in.read((char*)&x, sizeof x); //Читаем оттуда информацию и запоминаем её в X
	in.close(); //Закрываем файл

	cout << "x = " << x << endl; //Показываем X после изменения
	system("PAUSE");
}