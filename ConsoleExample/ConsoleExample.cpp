// ConsoleExample.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Это демо проект необходимый для визуальной демонстрации и тестирования библиотеки генератора 
//

#include <iostream>

#include "..\maze generator\Map.hpp"
#include "..\maze generator\MazeBuilder.hpp"



int main() {
	Map q(58, 235);//58,235 - fhd fullscrean
	MazeBuilder mb;
	mb.setMap(&q);
	mb.setStartPoint({35,35});
	mb.build();
	std::cout << q;
	return 0;
}