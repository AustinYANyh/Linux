#include "class-mod.h"
#include <iostream>

using namespace std;

#if 0
int main()
{
	Seqlist<int> d1;

	d1.PushBack(1);
	d1.PushBack(2);
	d1.PushBack(3);

	cout << d1.Capacity() << endl;
	cout << d1.Size() << endl;

	Seqlist<double>d2;

	d2.PushBack(1.0);
	d2.PushBack(2.0);
	d2.PushBack(3.0);

	cout << d2.Capacity() << endl;
	cout << d2.Size() << endl;

	d1.PrintSList();
	d2.PrintSList();

	cout << d1[1] << endl;

	system("pause");
	return 0;
}
#endif


template<typename T>

T Add(T left, T right)
{
	return left + right;
}

int main()
{
	cout << Add<int>(1, 2) << endl;
	cout << Add<double>(1.0, 2.0) << endl;

	system("pause");
	return 0;
}