#include <iostream>
#include <string.h>
#include <time.h>
#include "PriorityQueue.h"
#include "Printer.h"

using namespace std;



int main()
{
	srand(time(0));

	//�������� �������
	QueuePriority <int,int> QUP(25);

	//���������� ����� ���������
	for (int i = 0; i < 5; i++) {

		// �������� �� 0 �� 99 (������������)
		// � ��������� �� 0 �� 11 (������������)
		QUP.Add(rand() % 100, rand() % 12 + 1);
	}
	//����� �������
	QUP.Show();

	//���������� ��������
	QUP.Extract();

	//����� �������
	QUP.Show();
}
