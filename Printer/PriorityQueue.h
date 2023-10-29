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
    QueuePriority(int m);


    // ����������
    ~QueuePriority();

    // ������� �������
    void Clear();


    // ���������� ��������
    void Add(T& item, P& priority);

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
};

#include "PriorityQueue.h"




