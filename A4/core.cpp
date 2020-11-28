#include "core.h"

int Core::get_reg_num()
{
	return reg_number;
}

void Core::show_threads()
{
	std::cout << get_num_of_threads() << endl;
	for(int i = 0; i < int(get_num_of_threads()); i++)
	{
		if(threads[i]->get_num_time_slices() == 0)
			continue;
		threads[i]->show_process_and_thread_and_timeslice();
	}
}

void Core::go_to_end_of_stack()
{
	for(int i = 0; i < threads.size() - 1; i++)
	{
		std::swap(threads[i], threads[i + 1]);
	}
}

void Core::show_run_core()
{
	threads[0]->show_process_and_thread();
}

void Core::run_core()
{
	threads[0]->decrease_time();
	go_to_end_of_stack();
	if(threads[int(threads.size()) - 1]->get_num_time_slices() == 0)
		threads.pop_back();
}

void Core::set_Comp(Computer* _computer)
{
	computer = _computer;
}

void Core::add_thread(Thread* thread)
{
	threads.push_back(thread);
}

int Core::get_num_of_threads()
{
	int num = 0;
	for(int i = 0; i < threads.size(); i++)
	{
		if(threads[i]->get_num_time_slices() != 0)
			num++;
	}
	return num;
}