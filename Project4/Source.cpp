#include <iostream>
#include <set>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include<iostream>
#include<chrono>
#include<windows.h>
#include<array>
class Timer {
	using clock_t = std::chrono::steady_clock;
	using timepoint_t = clock_t::time_point;
private:
	timepoint_t begin;
public:
	Timer()
	{
		start();
	}
	~Timer() noexcept
	{
		stop();
	}
	void start() {
		begin = clock_t::now();
	}
	void stop() {
		auto end = clock_t::now();
		std::cout << std::chrono::duration_cast <std::chrono::milliseconds>
			(end - begin).count() << std::endl;
	}
};

void main() 
{
	Timer timer = Timer();
	std::set<int> mySet;
	for (int i = 0; i < 100000; i++) {
		mySet.insert(rand());
	}
	timer.stop();
	timer.start();
	std::vector<int> myVector;
	for (int i = 0; i < 100000; i++) {
	
		myVector.push_back(rand());
	}
	std::sort(myVector.begin(), myVector.end());
	timer.stop();
	timer.start();
	std::array<int, 100000> myArray;
	for (int i = 0; i < 100000; i++) {
		myArray[i] = rand();
	}
	std::sort(myArray.begin(), myArray.end());
	timer.stop();
	system("pause");
}