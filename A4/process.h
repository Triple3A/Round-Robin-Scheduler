#ifndef process_h
#define process_h

#include "computer.h"

class Thread;
class Computer;

class Process {
public: 
	Process(Computer* _computer) {computer = _computer; reg_number = computer->get_num_of_processes() + 1;}
	int get_num_of_threads();
	void add_thread(Thread* thread);
	void set_Comp(Computer* _computer);
	int get_reg_num();
private:
	int reg_number;
	std::vector<Thread* > threads;
	Computer* computer;
};
#endif