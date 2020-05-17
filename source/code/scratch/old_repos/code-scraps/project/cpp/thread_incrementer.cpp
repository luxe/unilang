#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

using std::thread;
using std::vector;
using std::cout;
using std::endl;
using std::mutex;

class Incrementer
{
private:
	int counter;
	mutex m;
	
public:
	Incrementer() : counter{0} { };
	
	void operator()()
	{
		for(int i = 0; i < 100000; i++)
		{
			this->m.lock();
			this->counter++;
			this->m.unlock();
		}
	}
	
	int getCounter() const
	{
		return this->counter;
	}   
};

int main()
{
	// Create the threads which will each do some counting
	vector<thread> threads;
	
	Incrementer counter;
	
	threads.push_back(thread(std::ref(counter)));
	threads.push_back(thread(std::ref(counter)));
	threads.push_back(thread(std::ref(counter)));
	
	for(auto &t : threads)
	{
		t.join();
	}
	
	cout << counter.getCounter() << endl;
	
	return 0;
}