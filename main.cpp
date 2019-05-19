#include <iostream>
#include <string>
#include <zmq.hpp>

#include <thread>
#include <chrono>
#include <cstdlib>


#include <vector>
#include <cstdarg>
#include <cstring>
 
const std::string format(const std::string& format, ...)
{
    va_list args;
    va_start (args, format);
    size_t len = std::vsnprintf(NULL, 0, format.c_str(), args);
    va_end (args);
    std::vector<char> vec(len + 1);
    va_start (args, format);
    std::vsnprintf(&vec[0], len + 1, format.c_str(), args);
    va_end (args);
    return &vec[0];
}

int main()
{
   zmq::context_t context(1);
   zmq::socket_t sock(context, ZMQ_PUB);
   sock.bind("tcp://*:9090");
   
   while (1) {
	   char dataStr[] = "%d %d";
	   char outStr[] = "%s = %d, %s = %d";
	   
	   int topic = std::rand() % 500;
	   int message = std::rand() % 100;
	   const std::string data = format(dataStr, topic, message);
	   const std::string out = format(outStr, "topic", topic, "message", message);
	   
	   sock.send(zmq::buffer(data), zmq::send_flags::dontwait);

	   std::this_thread::sleep_for(std::chrono::milliseconds(2));
	   
	   if (topic == 450)
		   std::cout << out << std::endl;
   }
   
   
   return 0;
}