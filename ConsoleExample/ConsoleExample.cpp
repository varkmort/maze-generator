// ConsoleExample.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Это демо проект необходимый для визуальной демонстрации и тестирования библиотеки генератора 
//

#include <iostream>

#include "..\maze generator\Map.hpp"
#include "..\maze generator\MazeBuilder.hpp"

void programm() {
	using namespace Mazes;
	Map q(58, 235);//58,235 - fhd fullscrean
	MazeBuilder mb;
	mb.makeFast();
	mb.build(q, { 5,5 });
	std::cout << q << "\n\n\n";
	//Map w(40, 235);
	//mb.makeSlow();
	//mb.build(w, {5, 5});
	//std::cout << w << "\n\n\n";
}

int main() {
	programm();
	return 0;
}