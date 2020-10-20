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

//学习函数对象(未完)
#if 1 
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
