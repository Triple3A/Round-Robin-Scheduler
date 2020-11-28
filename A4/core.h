
#ifndef core_h
#define core_h

#include "computer.h"

class Thread;
class Computer;

class Core {
public: 
	Core(Computer* _computer) {computer = _computer; reg_number = computer->get_num_of_cores() + 1;}
	int get_num_of_threads();
	void set_Comp(Computer* _computer);
	int get_reg_num();
	void add_thread(Thread* thread);
	void show_threads();
	void show_run_core();
	void run_core();
	void go_to_end_of_stack();
private:
	int reg_number;
	std::vector<Thread* > threads;
	Computer* computer;
};

#endif
