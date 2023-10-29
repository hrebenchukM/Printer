#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <time.h>
#include "PriorityQueue.h"
#include "Printer.h"

class PrinterTask {//������ �� �����
private:
    string name;
    int priority;
    string text;
    string time;

public:
    // ����������� �� ��������� � � 3 �����������
    PrinterTask() = default;
    PrinterTask(string n, int p, string t): name(n), priority(p), text(t){}

    // �������
   string getName() const { return name; }
    int getPriority() const { return priority; }
    string getText() const { return text; }
   string getTime() const { return time; }

   //������
   void setTime(string tm) { time = tm; }

   // ����� ToString()
   string ToString()  {
       string result = "Name: " + name + ", Priority: " +to_string(priority) + ", Text: " + text + ", Time: " + time;
       return result;
   }
};




