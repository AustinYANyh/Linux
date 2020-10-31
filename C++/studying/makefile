all:string_boost filesystem_boost asio_boost socket_boost sharedmemory_boost container_boost datastructure_boost serialize_boost
LIB=-I /home/luzihan/boost_1_74_0/include -L /home/luzihan/boost_1_74_0/lib 

string_boost:string_boost.cpp
	g++ -std=c++11 $^ -o $@
filesystem_boost:filesystem_boost.cpp
	g++ -std=c++11 $^ -o $@ $(LIB) -lboost_system -lboost_filesystem
asio_boost:asio_boost.cpp
	g++ -std=c++11 $^ -o $@ $(LIB) -lboost_system-mt -lboost_thread-mt -lpthread
socket_boost:socket_boost.cpp
	g++ -std=c++11 $^ -o $@ $(LIB) -lpthread
sharedmemory_boost:sharedmemory_boost.cpp
	g++ $^ -o $@ $(LIB)  -pthread -lrt
container_boost:container_boost.cpp
	g++ -std=c++11 $^ -o $@ $(LIB)
datastructure_boost:datastructure_boost.cpp
	g++ -std=c++11 $^ -o $@ $(LIB)
serialize_boost:serialize_boost.cpp
	g++ -std=c++11 $^ -o $@ $(LIB) -lboost_serialization
clean:
	rm string_boost filesystem_boost asio_boost socket_boost sharedmemory_boost container_boost datastructure_boost serialize_boost