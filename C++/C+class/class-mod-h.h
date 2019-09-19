#pragma once

class Complex
{
public:
	Complex(double real, double inmage) :_real(real), _inmage(inmage)
	{

	}

	Complex operator+(const Complex& c)const
	{
		Complex tmp(*this);
		tmp._real += c._real;
		tmp._inmage += c._inmage;

		return tmp;
	}
private:
	double _real;
	double _inmage;
};

template<typename T>

class Seqlist
{
public:
	Seqlist(size_t capacity = 3) :_array(new T[capacity]), _size(0), _capacity(capacity)
	{

	}

	~Seqlist()
	{
		if (_array)
		{
			delete[] _array;
			_size = 0;
			_capacity = 0;
		}
	}

	size_t Size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	void PushBack(const T& data)
	{
		_array[_size++] = data;
	}

	void PopBack()
	{
		if (_size == 0)
		{
			return;
		}
		_size--;
	}

	T& operator[](size_t index)
	{
		return _array[index];
	}

	bool Empty()const
	{
		if (_size == 0)
		{
			return true;
		}
		return false;
	}

	void PrintSList()
	{
		for (int i = 0; i < _size; ++i)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
	}

private:
	T* _array;
	size_t _size;
	size_t _capacity;
};