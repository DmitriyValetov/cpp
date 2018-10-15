#include <cstdlib> 
#include <iostream>
#include <fstream>



class MyClass
{
	private:
		int z; //Недоступен ничему кроме своего класса

	public:
		int x;
		int y;
		
		MyClass() { z = 100; }; //Инициализация z с помощью конструктора
		void showZ() { std::cout << z << std::endl; }; //Метод класса, отображает на экране значение z
};


int main()
{
	system("CLS");
	MyClass A, O; //Создаем два объекта

				  //Задаем параметры объекту A и записываем его в файл
	A.x = 50;
	A.y = 60;
	O.x = 0; //Инициализируем параметры объекта О в нули. Будем читать его из файла
	O.y = 0;

	std::ofstream out("dump.bin", std::ios::binary|std::ios::out); //Открыли для записи в бинарном режиме
	out.write((char*)&A, sizeof A); //Записали объект А в открытый файл
	out.close(); //Закрыли открытый файл

	std::ifstream in("dump.bin", std::ios::binary|std::ios::in); //Открыли для только для чтения в бинарном режиме
	in.read((char*)&O, sizeof O); //Считали информацию в объект О
	in.close(); //Закрыли открытый файл

	std::cout << O.x << "  " << O.y << "  " << std::endl; //Вывели два доступных поля объекта О на экран
	O.showZ(); //С помощью метода класса отобразили z из объекта О на экране

	system("PAUSE");
	return 0;
}