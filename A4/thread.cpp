#include "thread.h"

void Thread::decrease_time()
{
	num_time_slice--;
}

Thread::Thread(Process* _process, int _num_time_slice) 
{
	process = _process; 
	reg_number = process->get_num_of_threads() + 1; 
	num_time_slice = _num_time_slice;
}

int Thread::get_reg_num()
{
	return reg_number;
}

void Thread::set_Core(Core* _core)
{
	core = _core;
}
void Thread::set_Process(Process* _process)
{
	process = _process;
}

int Thread::get_num_time_slices()
{
	return num_time_slice;
}

void Thread::show_process_and_thread_and_timeslice()
{
	std::cout << Process_ID << process->get_reg_num();
	std::cout << Thread_ID << reg_number << endl;
	std::cout << Number_of_time_slots << num_time_slice << endl;
}

void Thread::show_process_and_thread()
{
	std::cout << Process_ID << process->get_reg_num();
	std::cout << Thread_ID << reg_number << endl;
}
