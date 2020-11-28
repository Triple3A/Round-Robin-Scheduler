#include "process.h"

int Process::get_reg_num()
{
	return reg_number;
}

void Process::add_thread(Thread* thread)
{
	threads.push_back(thread);
}

int Process::get_num_of_threads()
{
	return threads.size();
}

void Process::set_Comp(Computer* _computer)
{
	computer = _computer;
}
