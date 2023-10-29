#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
#pragma once
#include <iostream>

template<typename T, typename P>
class QueuePriority//������������ �������
{
	// �������
	T* Wait;
	// ���������
	P* Pri;
	// ������������ ������ �������
	int MaxQueueLength;
	// ������� ������ �������
	int QueueLength;

public:
	// �����������
	QueuePriority() = default;
	QueuePriority(int m);
	QueuePriority(const QueuePriority&other);


	// ����������
	~QueuePriority();

	// ������� �������
	void Clear();


	// ���������� ��������
	void Add(T item, P priority);

	// ���������� ��������
	T Extract();

	// �������� ������������� ��������� � �������
	bool IsEmpty();

	// �������� �� ������������ �������
	bool IsFull();

	// ���������� ��������� � �������
	int GetCount();

	// ������������ �������
	void Show();




	int getQueueLength();
	T* getElements();//Wait


};




template<typename T, typename P>
inline QueuePriority<T, P>::QueuePriority(int m)
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
inline QueuePriority<T, P>::QueuePriority(const QueuePriority& other)
{
	MaxQueueLength = other.MaxQueueLength;
	QueueLength = other.QueueLength;

	Wait = new T[MaxQueueLength];
	for (int i = 0; i < QueueLength; i++)
	{
		Wait[i] = other.Wait[i];
	}


	Pri = new P[MaxQueueLength];
	for (int i = 0; i < QueueLength; i++)
	{
		Pri[i] = other.Pri[i];
	} 

}



template<typename T, typename P>
inline QueuePriority<T, P>::~QueuePriority()
{

	//�������� �������
	delete[]Wait;
	delete[]Pri;
}


template<typename T, typename P>
inline void QueuePriority<T, P>::Clear()
{

	// ����������� "�������" ������� 
	QueueLength = 0;
}


template<typename T, typename P>
inline void QueuePriority<T, P>::Show()
{
	cout << "\n-------------------------------------\n";
	//������������ �������
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " - " << Pri[i] << "\n\n";
	}
	cout << "\n-------------------------------------\n";
}

template<typename T, typename P>
inline int QueuePriority<T, P>::getQueueLength()
{
	return QueueLength;
}

template<typename T, typename P>
inline T* QueuePriority<T, P>::getElements()
{
	return Wait;
}





template<typename T, typename P>
inline bool QueuePriority<T, P>::IsEmpty()
{
	// ����?
	return QueueLength == 0;
}



template<typename T, typename P>
inline bool QueuePriority<T, P>::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}

template<typename T, typename P>
inline int QueuePriority<T, P>::GetCount()
{

	// ���������� �������������� � ������� ���������
	return QueueLength;
}






template<typename T, typename P>
inline void QueuePriority<T, P>::Add(T item, P priority)
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
inline T QueuePriority<T, P>::Extract()
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
		P temp2 = Pri[pos_max_pri];

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





