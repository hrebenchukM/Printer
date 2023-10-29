#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
#pragma once
#include <iostream>

template<typename T, typename P>
class QueuePriority
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
    QueuePriority(int m);


    // Деструктор
    ~QueuePriority();

    // Очистка очереди
    void Clear();


    // Добавление элемента
    void Add(T& item, P& priority);

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
};

#include "PriorityQueue.h"




