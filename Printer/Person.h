#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <time.h>
#include "PriorityQueue.h"
#include "Printer.h"

class Person {
private:
    string name;
    int priority;
    string text;
    string time;

public:
    // Конструктор
    Person(string& n, int p, const string& t, const string& tm)
        : name(n), priority(p), text(t), time(tm) {}

    // Методы получения значений
   string getName() const { return name; }
    int getPriority() const { return priority; }
    string getText() const { return text; }
   string getTime() const { return time; }

   string ToString()  {
       string result = "Name: " + name + ", Priority: " +to_string(priority) + ", Text: " + text + ", Time: " + time;
       return result;
   }
};

