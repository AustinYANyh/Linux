#include <string>
#include <iostream>
#include <mutex>

using namespace std;

mutex g_mutex;

class TeseInstance
{
public:
	static TeseInstance* GetInstance()
	{
		g_mutex.lock();
		static TeseInstance* _instance;
		if (_instance == nullptr)
			_instance = new TeseInstance();
		g_mutex.unlock();
		return _instance;

		
	}

	int Add(int a, int b)
	{
		return a + b;
	}
private:
	TeseInstance()
	{

	}
};

int main()
{
	cout << TeseInstance::GetInstance()->Add(1, 2) << endl;
	cout << "Hello World!\n";
}
