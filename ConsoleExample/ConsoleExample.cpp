// ConsoleExample.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Это демо проект необходимый для визуальной демонстрации и тестирования библиотеки генератора 
//

#include <iostream>

#include "..\maze generator\Map.hpp"
#include "..\maze generator\MazeBuilder.hpp"



int main() {
	Map q(1000, 235);//58,235 - fhd fullscrean
	MazeBuilder mb;
	mb.makeFast();
	mb.build(q, {5,5});
	std::cout << q << "\n\n\n";
	Map w(1000, 235);
	mb.makeSlow();
	mb.build(w, {5, 5});
	std::cout << w << "\n\n\n";
	return 0;
}