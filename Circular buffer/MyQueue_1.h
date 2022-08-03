#pragma once
#include <initializer_list>
#include <iterator>
#include <iostream>
template <typename T> class MyQueue_1
{
	T* m_p{};	//��������� �� ������ ������������� �������
	size_t m_n{}; //���������� ���������� ��������� � ������� 
	size_t m_cap{1}; //������� (������� �������� ������)
	size_t m_first{};// ������ ������� �������� � ������� (��� ��� �������, ������ ����� ��������� pop)
	size_t m_last{};//  ������ ������� ���������� �������� � ������� (push())
	const size_t delta{ 1 }; // �� ������� ����������� ������� ��� ����������������� ������
public:
	class iterator	{
	// ������ � ������, ����������� ���������������� ��������� ��� ��������� �������
		const MyQueue_1* m_pQ;// ����������� ������� 
		int m_i; // ������ �������� ��������
	public:
		iterator(const MyQueue_1* x, size_t ind = 0) : m_pQ(x), m_i(ind) {}
		// ��������� ������, ������� ����������� range-based for
		iterator & operator++ ()
		{
			this->m_i = ++m_i % m_pQ->m_cap;
			return *this;
		}
		bool operator!=(const iterator& other) const //// �������� ���������
		{
			return other.m_i != this->m_i;
		}
		T& operator* () { return m_pQ->m_p[m_i];}
	};
	// �������� �� ������ ������
	iterator begin() const {
		return MyQueue_1::iterator(this, m_first);
	}
	// �������� �� ����� �������
	iterator end() const {
		return MyQueue_1::iterator(this, m_last);
	}
	MyQueue_1()=default;
	~MyQueue_1() { delete[] m_p;}

	MyQueue_1(std::initializer_list<T> other);
	MyQueue_1(const MyQueue_1& other);// ����������� ����������� 
	MyQueue_1(const MyQueue_1&& other);// ����������� �����������
	// ������, ����������� ��������������� ������
	void push(const T& other);
	T pop();
};

template<typename T>
inline MyQueue_1<T>::MyQueue_1(std::initializer_list<T> other)
{
	m_cap = 1 + other.size();
	m_p = new T[m_cap];
	auto it = m_p;
	for (const auto& val : other)
	{
		*it = val;
		++it;
		m_n++; //���������� ���������� ��������� (�����������) 
		m_last++;
	}
}

template<typename T>
inline MyQueue_1<T>::MyQueue_1(const MyQueue_1& other) :m_n{ other.m_n }, m_cap{ other.m_cap + 1 }, m_first{ 0 }, m_last{other.m_n}
{
	this->m_p = new T[m_cap];
	for (const auto& el : other)
	{
		static int i = 0;
		m_p[i++] = el;
	}
}

template<typename T>
inline MyQueue_1<T>::MyQueue_1(const MyQueue_1&& other)
{
	m_n = other.m_n;
	m_cap = other.m_cap;
	m_first = other.m_first;
	m_last = other.m_last;
	m_p = other.m_p;
	other.m_n = 0;
	other.m_cap=1;
	other.m_first=0;
	other.m_last=0;
	other.m_p=nullptr;
}

template<typename T>
inline void MyQueue_1<T>::push(const T& other)
{
	if (m_n == m_cap - 1) // ����� �����
	{
		m_cap += 1;
		T* tmp = new T[m_cap];
		for (int i = 0; i < m_n; i++)
		{
			tmp[i] = this->m_p[(m_first + i) % m_cap];
		}
		delete[] m_p;
		m_p = tmp;
		m_first = 0;
		m_last = m_n;
	}
	m_p[m_last] = other;
	m_last = (m_last + 1) % m_cap;
	m_n++;

}

template<typename T>
inline T MyQueue_1<T>::pop()
{
	auto tmp = std::move(m_p[m_first]);
	m_first = (m_first + 1) % m_cap;
	m_n--;
	return  tmp;
}
