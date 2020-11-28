#include "computer.h"

using namespace std;

vector<int> get_input(string &input)
{
	cin >> input;
	vector<int> time_slices;
	if(input == ADD_PROCESS)
	{
		int num_threads, time_slice;
		cin >> num_threads;
		for(int i = 0; i < num_threads; i++)
		{
			cin >> time_slice;
			time_slices.push_back(time_slice);
		}
	}
	return time_slices;
}

void Add_core(Computer* comp)
{
		Core core(comp);
		comp->add_core(&core);	
}

void Add_process(Computer* comp,vector<int> time_slices)
{
		Process process(comp);
		int num_threads = time_slices.size();
		comp->add_process(&process, num_threads, time_slices);
		cout << endl;
		comp->distribute_threads(&process);
}

void Show_cores_stat(Computer* comp)
{
	comp->show_cores_stat();
}

void Run_cores(Computer* comp)
{
	comp->run_cores();
}

void Finish_tasks(Computer* comp)
{
	int time_slice = 1;
	while(comp->Thread_exist())
	{
		cout << Time_Slice << time_slice << endl;
		comp->run_cores();
		time_slice++;				
	}
}

void Core_output(Computer* comp)
{
	cout << COREPRINT1;
	cout << comp->get_num_of_cores();
	cout << COREPRINT2;
	cout << endl;
}
	
void Process_output(Computer* comp)
{
	cout << PROCESSPRINT1;
	cout << comp->get_num_of_processes();
	cout << PROCESSPRINT2;
	cout << endl;
}

vector<int> separator(string s)
{
	int num = stoi(s.substr(0, 1));
	vector<int> time_slices;
	for(int i = 0; i < num; i++)
	{
		int _time = stoi(s.substr(2 + i * 2, 1));
		time_slices.push_back(_time);
	}
	return time_slices;
}

void input_analysis(Computer* comp, string input)
{
	if(input == ADD_CORE)
	{
		Add_core(comp);
		Core_output(comp);
	}
	else if(input.substr(0, 11) == ADD_PROCESS)
	{
		vector<int> time_slices = separator(input.substr(12));
		Add_process(comp, time_slices);
		Process_output(comp);
	}
	else if(input == SHOW_CORES_STAT)
	{
		Show_cores_stat(comp);
	}
	else if(input == RUN_CORES)
	{
		Run_cores(comp);
	}
	else if(input == FINISH_TASKS)
	{
		Finish_tasks(comp);
	}
}	

vector<string> get_input()
{
	string input;
	vector<string> s;
	while(getline(cin, input))
	{
		s.push_back(input);
	}
	return s;
}
	
int main()
{
	Computer comp(0);
	vector<string> inputs = get_input();
	for(int i = 0; i < inputs.size(); i++)
	{
		input_analysis(&comp, inputs[i]);
	}
	return 0;
}






