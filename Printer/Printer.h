#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
#include "PrinterTask.h"
#include "PriorityQueue.h"

using namespace std;

//��� ��������� �������� ������� 
#include <chrono>
#include <ctime>
#pragma warning(disable : 4996)





class Printer
{   
	//����  ��������� ��� �� ������ ����������� ��������� ��� ������ ������� � �� �������� ������ (10)
	QueuePriority <PrinterTask,int> clients = QueuePriority <PrinterTask, int>(10);//������������ �������-������� ������� �� ������ (��������� ������ �� �����(Person) � ������ ��������������)
	QueuePriority <PrinterTask, int> history = QueuePriority <PrinterTask, int>(25);//-������� ������� �� ������� ������ (��������� ������ �� �����(Person) � ������ ��������������)


public:

	void addTask(PrinterTask p);////�������� ������ � ������� 
	void print();//�������� ����� ������������ �������
	void printHistory();//�������� ��� ������� 
	
};



void Printer::addTask(PrinterTask p)
{
	clients.Add(p, p.getPriority());//�� ��� ���� ������ ��������� �������, ���� ����� ���� ������� 
}

void Printer::print()
{
	PrinterTask mostWanted = clients.Extract();//  ����������� ���������� �� ������� ������������ ������
	
	cout << endl << "Printing text: " << mostWanted.getText();//��������� ������ ������� ����� ������

	//��� �������
	auto now = chrono::system_clock::now();
	time_t end_time = chrono::system_clock::to_time_t(now);
	mostWanted.setTime(ctime(&end_time));//�������������� ����� �������� ����� ������

	history.Add(mostWanted, 0);//��������� � ������� ������� ������������ ������ � ��������� 0,�� ���� �� ���������� ���, ���� ������� ���������� ��� ����������
}

void Printer::printHistory()
{
	cout << endl << "History of prints:" << endl;
	for (int i = 0; i < history.getQueueLength(); i++) {
		cout << history.getElements()[i].ToString();//�������� � ����� ������� ��������
	}
}

