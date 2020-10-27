all:testboost testboost1 testboost2

LIB=-L /home/luzihan/boost_1_74_0/lib -lboost_system-mt -lboost_thread-mt

testboost:testboost.cpp
	g++ -std=c++11 testboost.cpp -o testboost -I /home/luzihan/boost_1_74_0/include/ 
testboost1:testboost1.cpp
	g++ -std=c++11 testboost1.cpp -o testboost1 -I /home/luzihan/boost_1_74_0/include/ -L /home/luzihan/boost_1_74_0/lib -lboost_system -lboost_filesystem
testboost2:testboost2.cpp
	g++ -std=c++11 testboost2.cpp -o testboost2 -I /home/luzihan/boost_1_74_0/include/ $(LIB) -lpthread
