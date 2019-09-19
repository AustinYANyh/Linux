#include <iostream>
#include <string>

using namespace std;

#if 0
int main()
{
	cout << string("wo ai luzihan ~") << endl;

	cout << string(5, 'Q') << endl;

	string d1("QAQ");
	string d2(d1);

	cout << d2 << endl;

	//cin >> d2;

	getline(cin, d2);
	cout << d2 << endl;
	cout << d2.size() << endl;
	cout << d2.capacity() << endl;

	system("pause");
}
#endif

#if 0
int main()
{
	string s1("鹿宝宝");
	cout << s1.length() << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	string s2("lubaobao wo ai ni ya");
	cout << s2 << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	cout << s2.empty() << endl;

	//s2.clear();
	//cout << s2.empty() << endl;

	//s2.resize(5);
	//cout << s2 << endl;

	s2.resize(10, '6');
	cout << s2 << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	system("pause");
}
#endif

#if 0
int main()
{
	string s1("lubaobao");
	cout<<s1.size() << endl;
	cout << s1.capacity() << endl;

	//新空间的大小没有旧空间的大,直接忽略
	s1.reserve(10);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	//新空间的大小比旧空间大,扩容底层有自己的算法(不是你要20,就给20)
	s1.reserve(20);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	system("pause");
}
#endif

#if 0
int main()
{
	string s1("lubaobao");
	cout << s1[2] << endl;

	//cout << s1[10] << endl;

	cout << s1.at(2) << endl;
	//cout << s1.at(10) << endl;

	//[begin,end)
	reverse(s1.begin(),s1.end());

	//string::iterator it = s1.begin();
	auto it = s1.begin();

	while (it != s1.end())
	{
		cout << *it ;
		++it;
	}

	cout << endl;

	for (auto e : s1)
	{
		cout << e ;
	}

	cout << endl;

	//反向遍历string
	auto rit = s1.rbegin();

	while (rit != s1.rend())
	{
		cout << *rit ;
		++rit;
	}

	cout << endl;

	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i];
	}

	cout << endl;

	system("pause");
}
#endif

int main()
{
	string s;

	s += 'I';

	s += "love";

	s += "luzihan";

	cout << s << endl;

	string s1(" luzihan ye ai wo");

	s += s1;

	cout << s << endl;

	s.push_back('!');

	cout << s << endl;

	size_t pos = s.find('!');

	cout << s.size() << endl;
	cout << pos << endl;

	string s2("hello");
	cout << s2.size() << endl;

	if (pos != string::npos)
	{
		s.insert(pos, "^_^");
	}
	cout << s << endl;

	//s.erase(s.find('^'),3);
	s.erase(s.rfind('o' ) + 1, 3);

	s.replace(s.find("luzihan"), 7, "yanyunhao");

	cout << s << endl;

	string s3("iloveluzihan luzihan ye ai wo");

	swap(s, s3);

	cout << s << endl;

	string s4;
	s4=s.substr(s.rfind('i')+2);
	cout << s4 << endl;

	string s5("hello");
	cout<<s5.rfind('e')<<endl;

	system("pause");
}