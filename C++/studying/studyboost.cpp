#define _CRT_SECURE_NO_WARNINGS

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
