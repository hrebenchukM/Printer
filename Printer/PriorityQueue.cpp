#include "PriorityQueue.h"



template<typename T, typename P>
QueuePriority<T, P>::QueuePriority(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new T[MaxQueueLength];
	Pri = new P[MaxQueueLength];
	// »значально очередь пуста
	QueueLength = 0;
}



template<typename T, typename P>
QueuePriority<T, P>::~QueuePriority()
{

	//удаление очереди
	delete[]Wait;
	delete[]Pri;
}


template<typename T, typename P>
void QueuePriority<T, P>::Clear()
{

	// Ёффективна€ "очистка" очереди 
	QueueLength = 0;
}


template<typename T, typename P>
void QueuePriority<T, P>::Show()
{
	cout << "\n-------------------------------------\n";
	//демонстраци€ очереди
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " - " << Pri[i] << "\n\n";
	}
	cout << "\n-------------------------------------\n";
}






template<typename T, typename P>
bool QueuePriority<T, P>::IsEmpty()
{
	// ѕуст?
	return QueueLength == 0;
}



template<typename T, typename P>
bool QueuePriority<T, P>::IsFull()
{
	// ѕолон?
	return QueueLength == MaxQueueLength;
}

template<typename T, typename P>
int QueuePriority<T, P>::GetCount()
{

	//  оличество присутствующих в очереди элементов
	return QueueLength;
}






template<typename T, typename P>
void QueuePriority<T, P>::Add(T& item, P& priority)
{
	// ≈сли в очереди есть свободное место, то увеличиваем количество
	// значений и вставл€ем новый элемент
	if (!IsFull()) {
		Wait[QueueLength] = item;
		Pri[QueueLength] = priority;
		QueueLength++;
	}
}

template<typename T, typename P>
T QueuePriority<T, P>::Extract()
{
	// ≈сли в очереди есть элементы, то возвращаем тот, 
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
		T temp2 = Pri[pos_max_pri];

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
