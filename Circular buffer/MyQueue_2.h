#pragma once
#define SIZE 5 /* Size of Circular Queue */
template<typename T>
class MyQueue_2
{
	T items[SIZE];
	int front;
	int rear;
public:
	MyQueue_2()
	{
		front = -1;
		rear = -1;
	}

	bool isFull() const;	// проверка что не полон
	bool isEmpty() const;  // проверим что пуст
	void enQueue(const T& elem); // Добавляем элемент
	int deQueue(); // Удаление элемента
}; 

template<typename T>
inline bool MyQueue_2<T>::isFull() const
{
	if (front == 0 && rear == SIZE - 1)
	{
		std::cout << "Queue is full" << std::endl;
		return true;
	}
	else if (front == rear + 1)
	{
		return true;
	}
	return false;
}

template<typename T>
inline bool MyQueue_2<T>::isEmpty() const
{
	if (front == -1)
	{
		return true;
	}
	return false;
}

template<typename T>
inline void MyQueue_2<T>::enQueue(const T& elem)
{
	if (isFull()) 
		std::cout << "Fuul";
	else {
		
		if (front == -1)
			front = 0;
			rear = (rear + 1) % SIZE;
			items[rear] = elem;
	}
}

template<typename T>
inline int MyQueue_2<T>::deQueue()
{
	int elem;
	if (isEmpty()) //  если он пустой, то удалять ничего не надо 
	{
		std::cout << "Queue is empty" << std::endl;
		return (-1);
	}
	else {
		elem = items[front];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
			front = (front + 1) % SIZE;
				
	}
	return elem;
}
