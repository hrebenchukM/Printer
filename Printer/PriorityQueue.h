#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
#pragma once
#include <iostream>

template<typename T, typename P>
class QueuePriority//приоритетная очередь
{
	// Очередь
	T* Wait;
	// Приоритет
	P* Pri;
	// Максимальный размер очереди
	int MaxQueueLength;
	// Текущий размер очереди
	int QueueLength;

public:
	// Конструктор
	QueuePriority() = default;
	QueuePriority(int m);
	QueuePriority(const QueuePriority&other);


	// Деструктор
	~QueuePriority();

	// Очистка очереди
	void Clear();


	// Добавление элемента
	void Add(T item, P priority);

	// Извлечение элемента
	T Extract();

	// Проверка существования элементов в очереди
	bool IsEmpty();

	// Проверка на переполнение очереди
	bool IsFull();

	// Количество элементов в очереди
	int GetCount();

	// Демонстрация очереди
	void Show();




	int getQueueLength();
	T* getElements();//Wait


};




template<typename T, typename P>
inline QueuePriority<T, P>::QueuePriority(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new T[MaxQueueLength];
	Pri = new P[MaxQueueLength];
	// Изначально очередь пуста
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

	//удаление очереди
	delete[]Wait;
	delete[]Pri;
}


template<typename T, typename P>
inline void QueuePriority<T, P>::Clear()
{

	// Эффективная "очистка" очереди 
	QueueLength = 0;
}


template<typename T, typename P>
inline void QueuePriority<T, P>::Show()
{
	cout << "\n-------------------------------------\n";
	//демонстрация очереди
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
	// Пуст?
	return QueueLength == 0;
}



template<typename T, typename P>
inline bool QueuePriority<T, P>::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}

template<typename T, typename P>
inline int QueuePriority<T, P>::GetCount()
{

	// Количество присутствующих в очереди элементов
	return QueueLength;
}






template<typename T, typename P>
inline void QueuePriority<T, P>::Add(T item, P priority)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	if (!IsFull()) {
		Wait[QueueLength] = item;
		Pri[QueueLength] = priority;
		QueueLength++;
	}
}

template<typename T, typename P>
inline T QueuePriority<T, P>::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот, 
	// у которого наивысший приоритет и сдвигаем очередь	
	if (!IsEmpty()) {


		//пусть приоритетный элемент - нулевой
		int max_pri = Pri[0];
		//а приоритетный индекс = 0
		int pos_max_pri = 0;

		//ищем приоритет
		for (int i = 1; i < QueueLength; i++)
			//если встречен более приоритетный элемент
			if (max_pri < Pri[i]) {
				max_pri = Pri[i];
				pos_max_pri = i;
			}

		//вытаскиваем приоритетный элемент
		T temp1 = Wait[pos_max_pri];
		P temp2 = Pri[pos_max_pri];

		//сдвинуть все элементы
		for (int i = pos_max_pri; i < QueueLength - 1; i++) {
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		//уменьшаем количество
		QueueLength--;
		// возврат извлеченного элемента	
		return temp1;

	}
	else return T();
}





