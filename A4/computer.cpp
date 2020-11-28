
#include "computer.h"

void Computer::show_cores_stat()
{
	for(int i = 0; i < int(cores.size()); i++)
	{
		std::cout << Core_number << i + 1 << endl;
		cores[i]->show_threads();
	}
}

void Computer::run_cores()
{
	for(int i = 0; i < cores.size(); i++)
	{
		if(cores[i]->get_num_of_threads() == 0)
			continue;
		std::cout << Core_number << i + 1 << endl;
		cores[i]->show_run_core();
		cores[i]->run_core();
	}
}

void Computer::add_core(Core* core)
{
	number_of_cores++;
	cores.push_back(core);
	core->set_Comp(this);
}

int Computer::get_num_of_cores()
{
	return number_of_cores;
}

int Computer::get_num_of_processes()
{
	return processes_threads.size();
}

void Computer::add_process(Process* process, int num_threads, vector<int> time_slices)
{
	std::vector<Thread* > threads;
	for(int i = 0; i < time_slices.size(); i++)
	{
		Thread thread(process, time_slices[i]);
		process->add_thread(&thread);
		threads.push_back(&thread);
	}
	processes_threads.push_back(threads);
}

int Computer::find_core_min_threads()
{
	int min = cores[0]->get_num_of_threads();
	int No = 0;
	for(int i = 1; i < int(cores.size()); i++)
	{
		if(cores[i]->get_num_of_threads() < min)
		{
			min = cores[i]->get_num_of_threads();
			No = i;
		}
	}
	return No;
}

void Computer::distribute_threads(Process* process)
{
	int num_process = processes_threads.size() - 1;
	for(int i = 0; i < process->get_num_of_threads(); i++)
	{
		int j = find_core_min_threads();
		processes_threads[num_process][i]->set_Core(cores[j]);
		cores[j]->add_thread(processes_threads[num_process][i]);
	}
}

bool Computer::Thread_exist()
{
	for(int i = 0; i < cores.size(); i++)
	{
		if(cores[i]->get_num_of_threads() != 0)
			return true;
	}
	return false;
}

