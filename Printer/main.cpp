#include <iostream>
#include <string.h>
#include <time.h>
#include "PriorityQueue.h"
#include "Printer.h"

using namespace std;



int main()
{
	srand(time(0));

	//создание очереди
	QueuePriority <int,int> QUP(25);

	//заполнение части элементов
	for (int i = 0; i < 5; i++) {

		// значения от 0 до 99 (включительно)
		// и приоритет от 0 до 11 (включительно)
		QUP.Add(rand() % 100, rand() % 12 + 1);
	}
	//показ очереди
	QUP.Show();

	//извлечение элемента
	QUP.Extract();

	//показ очереди
	QUP.Show();
}
