all:udp-client udp-server
tcp-client:tcp-client.cpp
	e++ $^ -o $@
tcp-thread:tcp-thread.cpp
	g++ $^ -o $@ -lpthread
tcp-process:tcp-process.cpp
	g++ $^ -o $@
tcp-server:tcp-server.cpp
	g++ $^ -o $@
udp-client:udp-client.cpp
	g++ $^ -o $@
udp-server:udp-server.cpp
	g++ $^ -o $@
