#include "PriorityQueue.h"



template<typename T, typename P>
QueuePriority<T, P>::QueuePriority(int m)
{
	//�������� ������
	MaxQueueLength = m;
	//������� �������
	Wait = new T[MaxQueueLength];
	Pri = new P[MaxQueueLength];
	// ���������� ������� �����
	QueueLength = 0;
}



template<typename T, typename P>
QueuePriority<T, P>::~QueuePriority()
{

	//�������� �������
	delete[]Wait;
	delete[]Pri;
}


template<typename T, typename P>
void QueuePriority<T, P>::Clear()
{

	// ����������� "�������" ������� 
	QueueLength = 0;
}


template<typename T, typename P>
void QueuePriority<T, P>::Show()
{
	cout << "\n-------------------------------------\n";
	//������������ �������
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " - " << Pri[i] << "\n\n";
	}
	cout << "\n-------------------------------------\n";
}






template<typename T, typename P>
bool QueuePriority<T, P>::IsEmpty()
{
	// ����?
	return QueueLength == 0;
}



template<typename T, typename P>
bool QueuePriority<T, P>::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}

template<typename T, typename P>
int QueuePriority<T, P>::GetCount()
{

	// ���������� �������������� � ������� ���������
	return QueueLength;
}






template<typename T, typename P>
void QueuePriority<T, P>::Add(T& item, P& priority)
{
	// ���� � ������� ���� ��������� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
	if (!IsFull()) {
		Wait[QueueLength] = item;
		Pri[QueueLength] = priority;
		QueueLength++;
	}
}

template<typename T, typename P>
T QueuePriority<T, P>::Extract()
{
	// ���� � ������� ���� ��������, �� ���������� ���, 
	// � �������� ��������� ��������� � �������� �������	
	if (!IsEmpty()) {


		//����� ������������ ������� - �������
		int max_pri = Pri[0];
		//� ������������ ������ = 0
		int pos_max_pri = 0;

		//���� ���������
		for (int i = 1; i < QueueLength; i++)
			//���� �������� ����� ������������ �������
			if (max_pri < Pri[i]) {
				max_pri = Pri[i];
				pos_max_pri = i;
			}

		//����������� ������������ �������
		T temp1 = Wait[pos_max_pri];
		T temp2 = Pri[pos_max_pri];

		//�������� ��� ��������
		for (int i = pos_max_pri; i < QueueLength - 1; i++) {
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		//��������� ����������
		QueueLength--;
		// ������� ������������ ��������	
		return temp1;

	}
	else return T();
}
