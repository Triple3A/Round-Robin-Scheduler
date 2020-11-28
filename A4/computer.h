
#ifndef computer_h
#define computer_h

#include <iostream>
#include <vector>
#include "core.h"
#include "thread.h"
#include "process.h"

const string ADD_CORE = "add_core";
const string ADD_PROCESS = "add_process";
const string SHOW_CORES_STAT = "show_cores_stat";
const string RUN_CORES = "run_cores";
const string FINISH_TASKS = "finish_tasks";
const string COREPRINT1 = "Core with core ID = ";
const string COREPRINT2 = " successfully added!";
const string PROCESSPRINT1 = "Process with pid = ";
const string PROCESSPRINT2 = " added!";
const string Core_number = "Core number : "; 
const string Process_ID = "Process ID : ";
const string Thread_ID =  " - Thread ID : ";
const string Number_of_time_slots = "Number of time slots : "; 
const string Time_Slice = "Time Slice : ";

class Core;
class Process;
class Thread;

class Computer {
public:
	Computer(int _number_of_cores = 0) :number_of_cores(_number_of_cores) {};
	void add_core(Core *core);
	int get_num_of_cores();
	int get_num_of_processes();
	void add_process(Process* process, int num_threads, std::vector<int> time_slices);
	int find_core_min_threads();
	void distribute_threads(Process* process);
	void show_cores_stat();
	void run_cores();
	bool Thread_exist();
private:
	int number_of_cores;
	std::vector<Core* > cores;
	std::vector<vector<Thread* > > processes_threads;
};


#endif