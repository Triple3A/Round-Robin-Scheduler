#ifndef thread_h
#define thread_h

#include "computer.h"

class Core;
class Process;

class Thread {
public: 
	Thread(Process* _process, int _num_time_slice);
	int get_num_time_slices();
	void set_Core(Core* _core);
	void set_Process(Process* _process);
	int get_reg_num();
	void show_process_and_thread();
	void show_process_and_thread_and_timeslice();
	void decrease_time();
private:
	int reg_number;
	int num_time_slice;
	Core* core;
	Process* process;
};


#endif