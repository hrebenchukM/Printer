#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <time.h>
#include "PriorityQueue.h"
#include "Printer.h"

class PrinterTask {//Задача на принт
private:
    string name;
    int priority;
    string text;
    string time;

public:
    // Конструктор по умолчанию и с 3 параметрами
    PrinterTask() = default;
    PrinterTask(string n, int p, string t): name(n), priority(p), text(t){}

    // Геттеры
   string getName() const { return name; }
    int getPriority() const { return priority; }
    string getText() const { return text; }
   string getTime() const { return time; }

   //Сеттер
   void setTime(string tm) { time = tm; }

   // Метод ToString()
   string ToString()  {
       string result = "Name: " + name + ", Priority: " +to_string(priority) + ", Text: " + text + ", Time: " + time;
       return result;
   }
};




