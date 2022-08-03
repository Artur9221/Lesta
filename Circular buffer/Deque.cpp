#include <iostream>
#include "MyQueue_1.h"
#include "MyQueue_2.h"
#include <string>

int main()
{
	MyQueue_1<std::string> Queue_1{ std::string("World"),std::string("of"),std::string("Tank") };
	Queue_1.push("2");
	//Распечаетаем Queue_1
	for (const auto& el : Queue_1)
	{
		static int i = 0;
		std::cout << "Element " << i++ <<": " << el << std::endl;
	}
	//---------var_2---------------------------------------------
	
	MyQueue_2<int> Queue_3;
	int x;
	Queue_3.enQueue(1);
	Queue_3.enQueue(2);
	Queue_3.enQueue(3);
	Queue_3.enQueue(4);
	Queue_3.enQueue(5);
	Queue_3.enQueue(6);
	x=Queue_3.deQueue();
	x = Queue_3.deQueue();
	x = Queue_3.deQueue();
	x = Queue_3.deQueue();
	Queue_3.enQueue(6);
	x = Queue_3.deQueue();
	x = Queue_3.deQueue();
	x = Queue_3.deQueue();
}