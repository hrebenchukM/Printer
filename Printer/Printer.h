#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
#include "PrinterTask.h"
#include "PriorityQueue.h"

using namespace std;

//ƒл€ получени€ текущего времени 
#include <chrono>
#include <ctime>
#pragma warning(disable : 4996)





class Printer
{   
	//„тоб  создалось ибо он вызвал конструктор дефолтный где пуста€ очередь и не позвол€л писать (10)
	QueuePriority <PrinterTask,int> clients = QueuePriority <PrinterTask, int>(10);//ќтправленные задани€-создали ќчередь на печать (принимает «адачу на принт(Person) и размер приоритетности)
	QueuePriority <PrinterTask, int> history = QueuePriority <PrinterTask, int>(25);//-создали ќчередь на историю печати (принимает «адачу на принт(Person) и размер приоритетности)


public:

	void addTask(PrinterTask p);////ƒобавили задачу в очередь 
	void print();//ѕечатает самое приоритетное задание
	void printHistory();//ѕечатает всю историю 
	
};



void Printer::addTask(PrinterTask p)
{
	clients.Add(p, p.getPriority());//“о дл€ чего делала шаблонную очередь, чтоб можно было хранить 
}

void Printer::print()
{
	PrinterTask mostWanted = clients.Extract();//  присваиваем вытащенную из очереди приоритетную задачу
	
	cout << endl << "Printing text: " << mostWanted.getText();//Ёмулируем печать добыва€ текст задачи

	//ƒл€ времени
	auto now = chrono::system_clock::now();
	time_t end_time = chrono::system_clock::to_time_t(now);
	mostWanted.setTime(ctime(&end_time));//»нициализируем нашим временем через сеттер

	history.Add(mostWanted, 0);//ƒобавл€ем в очередь истории приоритетную задачу с приоритет 0,то есть не используем его, чтоб очередь печаталась без приоритета
}

void Printer::printHistory()
{
	cout << endl << "History of prints:" << endl;
	for (int i = 0; i < history.getQueueLength(); i++) {
		cout << history.getElements()[i].ToString();//ѕечатаем в цикле историю строками
	}
}

