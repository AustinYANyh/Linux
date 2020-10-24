#define _CRT_SECURE_NO_WARNINGS

//学习字符串处理
#if 0 
#include <iostream>
#include <vector>
#include <cstring>
#include <boost/algorithm/string.hpp>

int main()
{
	std::cout << "Hello World!\n";
	std::string s = "Hello World!";
	//使用boost库,将字符串转为大写
	std::cout << boost::algorithm::to_upper_copy(s) << std::endl;

	//使用STL标准算法库,将字符串转为大写
	transform(s.begin(), s.end(), s.begin(), towupper);
	std::cout << s << std::endl;

	//删除出现的第一个"O"
	//std::cout << boost::algorithm::erase_first_copy(s, "O") << std::endl;

	//删除第二个出现的"O",索引是1
	//std::cout << boost::algorithm::erase_nth_copy(s, "O", 1) << std::endl;

	//删除所有的"O"
	//std::cout << boost::algorithm::erase_all_copy(s, "O") << std::endl;

	//auto r = boost::algorithm::find_first(s, "WO");
	//std::cout << r << std::endl;

	//将第一个出现的"O"替换成"o"
	//std::cout << boost::algorithm::replace_first_copy(s, "O", "o") << std::endl;

	//boost库将vector中的字符串拼接
	std::vector<std::string> v;
	v.push_back("He");
	v.push_back("LLO");
	std::cout << boost::algorithm::join(v, " ") << std::endl;

	//拼接char*
	char S[50] = "lubaobao";
	char aa[8] = " xihuan";
	char bb[10] = " fujunjun";
	//sprintf(S, "%s%s%s", S, aa, bb);
	//std::cout << S << std::endl;

	strcat(S, aa);
	strcat(S, bb);
	std::cout << S << std::endl;

	//string的拼接
	std::string aaa = "lubaobao";
	std::string bbb = " xihuan";
	std::string ccc = " fujunjun";
	aaa.append(bbb);
	aaa.append(ccc);
	std::cout << aaa << std::endl;

	//判断字符串中是否含有子串
	bool res = boost::algorithm::contains(s, "HE");
}
#endif

//学习文件系统
#if 0
#include <boost/filesystem.hpp>
#include <iostream>
#include <iomanip>

double TransToG(double kb)
{
	return kb / 1024 / 1024 / 1024;
}

int main()
{
	boost::filesystem::path path1("C:\\Windows");
	//boost::filesystem::path* path1 = new boost::filesystem::path("C:\\");

	//判断path是不是目录
	std::cout << boost::filesystem::is_directory(path1) << std::endl;

	boost::filesystem::file_status filestatus = boost::filesystem::status(path1);
	std::cout << boost::filesystem::is_directory(filestatus) << std::endl;

	try
	{
		//获得文件的最后修改时间
		boost::filesystem::path path2("C:\\Users\\29572\\Desktop\\vsbg.jpg");
		std::time_t time = boost::filesystem::last_write_time(path2);
		std::cout << ctime(&time) << std::endl;

		//获取磁盘空间信息
		boost::filesystem::path path3("C:\\");
		boost::filesystem::space_info pathinfo = boost::filesystem::space(path3);

		//设置小数精度
		std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1);

		std::cout << TransToG(pathinfo.capacity) << std::endl;
		std::cout << TransToG(pathinfo.free) << std::endl;
		std::cout << TransToG(pathinfo.available) << std::endl;

		//获取程序当前目录
		std::cout << boost::filesystem::current_path() << std::endl;
	}
	catch (boost::filesystem::filesystem_error e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
#endif

//学习智能指针
#if 0
#include <iostream>
#include <windows.h>

using namespace std;

class Window_Handle
{
public:
	Window_Handle(HANDLE h) :_handle(h)
	{

	}

	~Window_Handle()
	{
		CloseHandle(_handle);
	}

	Window_Handle(const Window_Handle* data)
	{
		_handle = data->_handle;
	}

	//通过成员函数访问到private的成员变量
	HANDLE handle() const
	{
		return _handle;
	}
private:
	HANDLE _handle;
};

int main()
{
	//通过 OpenProcess() 打开的资源不需要显示的调用 CloseHandle() 来关闭。
	//当然，应用程序终止时资源也会随之关闭。 
	//然而，在更加复杂的应用程序里， windows_handle 类确保当一个资源不再使用时就能正确的关闭。 
	//某个资源一旦离开了它的作用域——上例中 h 的作用域在 main() 函数的末尾——它的析构函数会被自动的调用，
	//相应的资源也就释放掉了
	Window_Handle h(OpenProcess(PROCESS_SET_INFORMATION, false, GetCurrentProcessId()));
	//_handle不可访问,需要通过成员函数访问
	SetPriorityClass(h.handle(), HIGH_PRIORITY_CLASS);

	auto_ptr<string> p1(new string("lubaobao love fujunjun"));
	auto_ptr<string> p2;

	p2 = p1;
	//此时,p1的所有权已被剥夺,p1变为empty,访问p1会报错
	//p1->append(" heihei");

	unique_ptr<string> p3(new string("lubaobao"));
	unique_ptr<string> p4;
	//此时编译器会报错(尝试引用已删除的函数),因为p3、p4是单独占用模式
	//p3 = p4;	

	//但如果是临时右值,编译器允许
	p3 = unique_ptr<string>(new string("fujunjun"));

	string tmp = "luzihan is lubaobao";
	shared_ptr<string> p5(&tmp);
	shared_ptr<string> p6;
	p6 = p5;
	cout << p5.use_count() << endl;
	cout << p6.use_count() << endl;
	cout << p5.unique() << endl;

	shared_ptr<string> p7(new string("yanyunhao is funjunjun"));
	cout << p5.get() << endl;
	cout << p7.get() << endl;
	swap(p5, p7);
	cout << p5.get() << endl;
	cout << p7.get() << endl;


	cout << p5.use_count() << endl;
	cout << p6.use_count() << endl;

	p6 = p5;
	cout << p5.use_count() << endl;
	cout << p6.use_count() << endl;

	//在VS 2017以上版本,将引用计数置为0
	p5.reset();
	cout << p5.use_count() << endl;
	cout << p6.use_count() << endl;

	return 0;
}
#endif

//一个简单理解多态的Demo
#if 0
#include <iostream>

using namespace std;

class softbanker
{
public:
	softbanker()
	{

	};

	virtual	void DoSomething()
	{
		cout << "save money" << endl;
	}
};

class softbanker1 :public softbanker
{
public:
	virtual void DoSomething()
	{
		cout << "take money" << endl;
	}
};

class softbanker2 :public softbanker
{
public:
	virtual void DoSomething()
	{
		cout << "change money" << endl;
	}
};

int main()
{
	softbanker* sbanker = new softbanker();
	sbanker->DoSomething();

	sbanker = new softbanker1();
	sbanker->DoSomething();

	sbanker = new softbanker2();
	sbanker->DoSomething();

	delete sbanker;

	return 0;
}
#endif

//学习函数对象
#if 0 
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <boost/bind.hpp>

using namespace std;

void Print(int i)
{
	cout << i << endl;
}

//for_each中要求的函数仅能接受一个参数
void Add(int i, int j)
{
	cout << i + j << endl;
}

bool Compare(int i, int j)
{
	return i < j;
}

class add :public binary_function<int, int, void>
{
public:
	void operator()(int i, int j)const
	{
		cout << i + j << endl;
	}
};

int main()
{
	vector<int> v{ 1,2,3 };
	//for_each(v.begin(), v.end(), Print);

	//遍历打印v中的每个数+10
	for_each(v.begin(), v.end(), bind1st(add(), 10));

	//使用boost库中的bind方法
	//_1,_2,_3这些都是占位符,Add是二元函数,传入参数10 ,_1将v数组中的元素传入
	for_each(v.begin(), v.end(), boost::bind(Add, 10, _1));

	swap(v[0], v[1]);
	for_each(v.begin(), v.end(), Print);
	//Compare是一个二元函数,_1,_2一次传入v数组中两个数
	sort(v.begin(), v.end(), boost::bind(Compare, _1, _2));
	for_each(v.begin(), v.end(), Print);

	//不像for_each只能使用一元函数作为参数
	//sort中的比较方法可以是多元,上面的bind方法其实不需要
	sort(v.begin(), v.end(), Compare);

	//不需要改变Compare的定义,就可以改变是升序还是降序
	sort(v.begin(), v.end(), boost::bind(Compare, _2, _1));
	for_each(v.begin(), v.end(), Print);

	return 0;
}
#endif

//学习事件处理
#if 0
#include <boost/signals2.hpp>
#include <iostream>

//为了将信号槽函数的返回值写出至标准输出流
#include <boost/optional/optional_io.hpp>

using namespace std;

void Func()
{
	cout << "Hello World!" << endl;
}

void Func1()
{
	cout << "Func1 Called" << endl;
}

int Func2()
{
	return 2;
}

int Func3()
{
	return 3;
}

namespace my_max_element
{
	template<typename T>
	struct max_element
	{
		typedef T result_type;
		template<typename InputIterator>

		//max_element的返回值为_Fwdlt
#if 0
		T operator()(InputIterator first, InputIterator last)const
		{
			return *std::max_element(first, last);
		}
#endif
		T operator()(InputIterator first, InputIterator last)const
		{
			return T(first, last);
		}
	};
}

int main()
{
	boost::signals2::signal<void()> sig;
	//sig.connect(Func);
	//sig.connect(Func1);

	//重载方式指定执行顺序
	sig.connect(1, Func);
	sig.connect(0, Func1);
	sig();

	//释放与绑定信号的关联
	sig.disconnect(Func1);
	sig();

	//清除所有关联的信号
	sig.disconnect_all_slots();

	//函数被关联至信号执行后的返回值会被覆盖,只保留最后一个
	//注意signal<>函数的返回值类型
	boost::signals2::signal<int()> new_sig;
	new_sig.connect(Func3);
	new_sig.connect(Func2);
	cout << new_sig() << endl;

	//保留每个返回值,重载()操作符,返回最大的其中一个返回值
	//boost::signals2::signal<int(), my_max_element::max_element<int>> max_sig;
	boost::signals2::signal<int(), my_max_element::max_element<vector<int>>> max_sig;
	max_sig.connect(Func3);
	max_sig.connect(Func2);
	//cout << max_sig() << endl;
	vector<int> sig_return_value;
	sig_return_value = max_sig();

	for (auto e : sig_return_value)
		cout << e << endl;

	return 0;
}
#endif

//学习多线程
#if 0
#include <boost/thread.hpp>
#include <iostream>

void Wait(int seconds)
{
	//sleep函数区别于Sleep,位于this_thread命名空间
	//seconds函数用于获得一个精确的时间,位于boost库的DateTime
	boost::this_thread::sleep(boost::posix_time::seconds(seconds));
}

#if 0
boost::mutex mutex;

void Thread_thread()
{
	try
	{
		for (int i = 1; i <= 5; ++i)
		{
			Wait(1);
			//mutex.lock();

			//lock_guard类的构造函数中自动调用lock()
			//lock_guard类的析构函数中自动调用unlock()
			boost::lock_guard<boost::mutex> lock(mutex);

			std::cout << i << std::endl;
			//mutex.unlock();

			//lock_guard的生命周期为for循环进入到结束
		}
		std::cout << boost::this_thread::get_id() << std::endl;
	}
	//中断后会抛出一个thread_interrupted异常
	catch (boost::thread_interrupted&)
	{

	}
}
#endif

boost::timed_mutex mutex;

void Thread_thread()
{
	for (int i = 1; i <= 5; ++i)
	{
		Wait(1);
		boost::unique_lock<boost::timed_mutex> lock(mutex, boost::try_to_lock);
		if (!lock.owns_lock())
			lock.timed_lock(boost::get_system_time() + boost::posix_time::seconds(1));
		std::cout << boost::this_thread::get_id() << ": " << i << std::endl;
		boost::timed_mutex* m = lock.release();
		m->unlock();
	}
}

#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> random_numbers;
boost::shared_mutex shared_mutex;

#if 0
void Fill()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	for (int i = 0; i < 3; ++i)
	{
		//这里改变了random_numers的内容,需要独占资源,使用独占锁
		boost::unique_lock<boost::shared_mutex> lock(shared_mutex);
		random_numbers.push_back(std::rand());

		//独占锁需要显式调用unlock
		lock.unlock();

		//等待时间放在最后为了确保random_numbers里至少有一个数据
		Wait(1);
	}
}

void Print()
{
	for (int i = 0; i < 3; ++i)
	{
		Wait(1);
		//虽然写到了标准输出,但是不操作random_numbers,所以可以共享互斥体
		boost::shared_lock<boost::shared_mutex> lock(shared_mutex);
		std::cout << random_numbers.back() << std::endl;
	}
}
#endif

boost::mutex r_mutex;
boost::condition_variable_any condition;

#if 0
void Fill()
{
	std::srand(static_cast<unsigned int> (std::time(0)));
	for (int i = 0; i < 3; ++i)
	{
		boost::unique_lock<boost::mutex> lock(r_mutex);
		random_numbers.push_back(std::rand());

		//数据放完后,size相等,跳出循环,唤醒wait线程
		condition.notify_all();

		//这边进入等待,直到print出数据,size增加,唤醒这边的wait
		condition.wait(r_mutex);
	}
}

void Print()
{
	std::size_t next_size = 1;
	for (int i = 0; i < 3; ++i)
	{
		boost::unique_lock<boost::mutex> lock(r_mutex);

		//数据没拿到一直wait
		while (random_numbers.size() != next_size)
			condition.wait(r_mutex);

		//size相等,被唤醒
		std::cout << random_numbers.back() << std::endl;
		++next_size;

		//唤醒插入数据的线程的wait
		condition.notify_all();
	}
}

int sum = 0;

void Sum()
{
	for (int i = 0; i < 3; ++i)
	{
		Wait(1);
		//只有读操作,
		boost::shared_lock<boost::shared_mutex> lock(shared_mutex);
		sum += random_numbers.back();
	}
}
#endif

#if 0
//静态变量done,srand执行了只一次,生成的随机数2/3是同一个
void InitNumber()
{
	//第二次进来done已经变成true了
	static bool done = false;
	if (!done)
	{
		done = true;
		std::srand(static_cast<unsigned int>(std::time(0)));
	}

}
#endif

//同一时间完成初始化的话,随机数还是有可能一样
void InitNumber()
{
	boost::thread_specific_ptr<bool> tls;
	if (!tls.get())
		//reset参数是指针,C++ 的new出来的是指针,C# 的new出来的是对象
		tls.reset(new bool(false));
	if (!*tls)
	{
		*tls = true;
		std::srand(static_cast<unsigned int>(std::time(0)));
	}
}

void GenerateNumber()
{
	InitNumber();
	int i = std::rand();
	boost::unique_lock<boost::mutex> lock(r_mutex);
	std::cout << i << std::endl;
}

int main()
{
#if 0
	boost::thread t(Thread_thread);
	Wait(3);

	//获得当前线程的线程ID
	std::cout << boost::this_thread::get_id() << std::endl;

	//3秒后t线程被终止,打印结果为1,2,3
	t.interrupt();

	//join的作用是阻塞调用,直到调用join的线程运行结束
	t.join();
#endif

#if 0
	//如果函数内不加mutex,可能输出如下:
	//11
	//2
	//2
	//...
	//如果函数内加mutex,输出如下:
	//1
	//1
	//2
	//2
	//...
	boost::thread t1(Thread_thread);
	boost::thread t2(Thread_thread);

	t1.join();
	t2.join();
#endif

#if 0
	boost::thread thread1(Fill);
	boost::thread thread2(Print);
	//boost::thread thread3(Sum);

	thread1.join();
	thread2.join();
	//thread3.join();
#endif

	boost::thread thread[3];
	for (int i = 0; i < 3; ++i)
		thread[i] = boost::thread(GenerateNumber);
	for (int i = 0; i < 3; ++i)
		thread[i].join();

	return 0;
}
#endif

//学习异步输入输出
#if 1
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <iostream>

using namespace std;

boost::asio::io_service service;

//参数好像必须要传一个boost库提供的错误码(引用类型)
void Async_Cout(const boost::system::error_code& ec)
{
	cout << "lubaobao shigezhu" << endl;
}

void Async_Cout1(const boost::system::error_code& ec)
{
	cout << "lubaobao nengchi nengshui" << endl;
}

void Myrun()
{
	service.run();
}


int main()
{
	boost::asio::deadline_timer timer(service, boost::posix_time::seconds(5));

#if 0
	timer.async_wait(Async_Cout);
	cout << "async is right" << endl;

	//这里调用的run是阻塞式的,如果不是阻塞的,main函数结束调用后程序退出会把异步的方法中断掉
	service.run();
#endif

	boost::asio::deadline_timer timer1(service, boost::posix_time::seconds(5));

	timer.async_wait(Async_Cout);
	timer1.async_wait(Async_Cout1);

	boost::thread thread1(Myrun);
	boost::thread thread2(Myrun);
	thread1.join();
	thread2.join();

	return 0;
}
#endif
