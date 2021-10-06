//Programming Practice #1
//Coach Dasgupta (2014)
//Spy Hard with a Vengeance (2006 Maryland High-school Programming Contest)

//Our Solution:
//we solved it with an exhaustive breadth-first approach.
//Our solution exhausts down the search tree for solutions, and
//avoids cycles by stopping when a duplicate jug state was reached.
//we can also break out early at times when we have used more gallons then a possible solution already recorded.

//STD HEADERS
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <queue>

//CONSTANTS AND TYPEDEFS
using Gallon = unsigned int;              //we'll use unsigned ints to represent gallons of water
constexpr unsigned int NUMBER_OF_JUGS{3}; //this problem only involves 3 jugs, but we might want to one day extend it to more

//this structure holds all the user input for each scenario
struct Input_Data{
	std::vector<Gallon> jug_capacities;
	Gallon goal;
};

//this is structure represents a jug of water an its contents
struct Jug{

	//constructor
	Jug(unsigned int capacity_in, unsigned int amount_in=0)
	: capacity(capacity_in)
	, amount(amount_in)
	{}

	//comparison operators
	bool operator < (Jug const& lhs) const{
		return (capacity < lhs.capacity) && (amount < lhs.amount);
	}

	bool operator == (Jug const& lhs) const{
		return (capacity == lhs.capacity) && (amount == lhs.amount);
	}

	bool operator != (Jug const& lhs) const{
		return !((capacity == lhs.capacity) && (amount == lhs.amount));
	}

	friend std::ostream& operator<< (std::ostream& out, Jug const& jug) {
		out << "[" <<  jug.amount <<  "/" << jug.capacity <<  "]";
		return out;
	}

	//data members
	unsigned int capacity;
	unsigned int amount;
};

// stored inside of a process queue
struct Jug_Formation {

	Jug_Formation(std::vector<Jug> const& jug_formation_in = {},  Gallon const& gallons_used_so_far_in = 0)
	: jug_formation(jug_formation_in)
	, gallons_used_so_far(gallons_used_so_far_in)
	{}


	std::vector<Jug> jug_formation;
	Gallon gallons_used_so_far;

};

//keeps track of jug formations to see if a jug state has been revisited
//the best data structure would probably be a tree of some sort, but is not crucial to solving the problem
//in a quick amount of time
struct Jug_Formation_Tracker{

	bool Exists(std::vector<Jug> const& jug_formation){
		//bool found = std::binary_search(jug_formations.begin(),jug_formations.end(),jug_formation);
		//std::cout << "[" << found << "]";
		bool found = false;
		for (auto const& it: jug_formations){
			if (it == jug_formation){
				return true;
			}
		}

		return false;
	}

	void Add(std::vector<Jug> const& jug_formation){
		jug_formations.push_back(jug_formation);
		//std::sort(jug_formations.begin(), jug_formations.end());
	}


private:
	std::vector<std::vector<Jug>> jug_formations;
};

//FUNCTION DECELERATIONS
Input_Data Read_In_Input_Data(std::istream & in_stream=std::cin);
void Solve_Problem(Input_Data const& input_data);
void Take_All_Available_Next_Steps(std::queue<Jug_Formation> & process_queue, Jug_Formation_Tracker & jug_formations_seen, Gallon & solutions, Gallon const& goal);

void Add_All_Empty_Steps(std::queue<Jug_Formation> & process_queue, Jug_Formation const& current_move);
void Add_All_Fill_Steps (std::queue<Jug_Formation> & process_queue, Jug_Formation const& current_move);
void Add_All_Pour_Steps (std::queue<Jug_Formation> & process_queue, Jug_Formation const& current_move);

void Print_Lowest_Gallon_Solution(std::vector<Gallon> const& solutions);

//there are 3 main actions that can be performed on the set of jugs
//FILLING
std::vector<Jug> Get_Jugs_After_Fill_Of_Index(std::vector<Jug> jugs, size_t const& index);
void Fill_Jug_Index(std::vector<Jug> & jugs, size_t const& index);
	void Fill_Up_Jug(Jug & jug);
Gallon Get_Gallon_Amount_After_Fill(Jug const& jug);

//EMPTYING
std::vector<Jug> Get_Jugs_After_Empty_Of_Index(std::vector<Jug> jugs, size_t const& index);
void Empty_Jug_Index(std::vector<Jug> & jugs, size_t const& index);
	void Empty_Jug(Jug & jug);

//POURING
std::vector<Jug> Get_Jugs_After_Pour_Of_Indexes(std::vector<Jug> jugs, size_t const& pour_index, size_t const& fill_index);
void Pour_Jug_Index(std::vector<Jug> & jugs, size_t const& pour_index, size_t const& fill_index);
	void Pour_Jug(Jug & pour_jug, Jug & fill_jug);

//checking
bool Goal_Has_Been_Reached(std::vector<Jug> const& jugs, Gallon const& goal);

void Print_Results(Input_Data const& input_data, Gallon const& solution);

int main() {

	//read in the data for each problem set
	//and call Solve_Problem to print the solution
	Input_Data input_data = Read_In_Input_Data();
	while (std::cin) {
		Solve_Problem(input_data);
		input_data = Read_In_Input_Data();
	}

	return EXIT_SUCCESS;
}
Input_Data Read_In_Input_Data(std::istream & in_stream){

	Input_Data input_data;
	Gallon temp;
	for (unsigned int i=0; i < NUMBER_OF_JUGS; ++i){
		in_stream >> temp;
		input_data.jug_capacities.push_back(temp);
	}
	in_stream >> input_data.goal;
	return input_data;
}
void Solve_Problem(Input_Data const& input_data){

	//first we create the jugs;
	std::vector<Jug> jugs;
	for (auto const& it: input_data.jug_capacities){jugs.push_back(Jug(it));}

	//next we create a list to store only unique combinations of how these jugs have been filled.
	//This way, we can stop recursion if we reach a similar jug formation
	Jug_Formation_Tracker jug_formations_seen;

	//a queue to allow us a breadth-first approach to solving
	std::queue<Jug_Formation> process_queue;
	process_queue.push(Jug_Formation(jugs, 0));

	//solution (how many gallons it took to reach our goal)
	//there will be multiple solutions, but we'll only keep the cheapest one.
	//we'll assume the solution is infinity until we find a better solution or seek all the possibilities
	Gallon solution = std::numeric_limits<Gallon>::max();

	//brute force all of the different actions that can be performed on the set of jugs,
	//but avoid continuing from a jug formation that we have already seen.
	//after this function has finished, we will have a list of solutions.
	//the problem states to print the one involving the least amount of gallons.
	Take_All_Available_Next_Steps(process_queue, jug_formations_seen,solution,input_data.goal);

	//print results for particular input data set
	Print_Results(input_data, solution);

	return;
}
void Take_All_Available_Next_Steps(std::queue<Jug_Formation> & process_queue, Jug_Formation_Tracker & jug_formations_seen, Gallon & solution, Gallon const& goal){


	//Process the next element of the queue,  and add all the available next moves onto the end of the queue
	Jug_Formation current_move;
	while (!process_queue.empty()) {
		current_move = process_queue.front();
		process_queue.pop();

		//check the current pop state
		if (Goal_Has_Been_Reached(current_move.jug_formation,goal)){
			if (current_move.gallons_used_so_far < solution) {
				solution = current_move.gallons_used_so_far;
			}

		//add the other states
		}else if (!jug_formations_seen.Exists(current_move.jug_formation)){
			jug_formations_seen.Add(current_move.jug_formation);

			//if the gallon amount is already more than a possible solution, don't go any further down the tree
			if (current_move.gallons_used_so_far <= solution) {
				Add_All_Pour_Steps  (process_queue,current_move);
				Add_All_Fill_Steps  (process_queue,current_move);
				Add_All_Empty_Steps (process_queue,current_move);
			}
		}else{
		}
	}

	return;
}
void Add_All_Empty_Steps(std::queue<Jug_Formation> & process_queue, Jug_Formation const& current_move){

	process_queue.push(Jug_Formation(Get_Jugs_After_Empty_Of_Index(current_move.jug_formation,0), current_move.gallons_used_so_far));
	process_queue.push(Jug_Formation(Get_Jugs_After_Empty_Of_Index(current_move.jug_formation,1), current_move.gallons_used_so_far));
	process_queue.push(Jug_Formation(Get_Jugs_After_Empty_Of_Index(current_move.jug_formation,2), current_move.gallons_used_so_far));

	return;
}
void Add_All_Fill_Steps (std::queue<Jug_Formation> & process_queue, Jug_Formation const& current_move){

	process_queue.push(Jug_Formation(
		Get_Jugs_After_Fill_Of_Index(current_move.jug_formation,0),
		current_move.gallons_used_so_far+Get_Gallon_Amount_After_Fill(current_move.jug_formation[0])));

	process_queue.push(Jug_Formation(
		Get_Jugs_After_Fill_Of_Index(current_move.jug_formation,1),
		current_move.gallons_used_so_far+Get_Gallon_Amount_After_Fill(current_move.jug_formation[1])));

	process_queue.push(Jug_Formation(
		Get_Jugs_After_Fill_Of_Index(current_move.jug_formation,2),
		current_move.gallons_used_so_far+Get_Gallon_Amount_After_Fill(current_move.jug_formation[2])));

	return;
}
void Add_All_Pour_Steps (std::queue<Jug_Formation> & process_queue, Jug_Formation const& current_move){

	process_queue.push(Jug_Formation(Get_Jugs_After_Pour_Of_Indexes(current_move.jug_formation,0, 1), current_move.gallons_used_so_far));
	process_queue.push(Jug_Formation(Get_Jugs_After_Pour_Of_Indexes(current_move.jug_formation,0, 2), current_move.gallons_used_so_far));
	process_queue.push(Jug_Formation(Get_Jugs_After_Pour_Of_Indexes(current_move.jug_formation,1, 0), current_move.gallons_used_so_far));
	process_queue.push(Jug_Formation(Get_Jugs_After_Pour_Of_Indexes(current_move.jug_formation,1, 2), current_move.gallons_used_so_far));
	process_queue.push(Jug_Formation(Get_Jugs_After_Pour_Of_Indexes(current_move.jug_formation,2, 0), current_move.gallons_used_so_far));
	process_queue.push(Jug_Formation(Get_Jugs_After_Pour_Of_Indexes(current_move.jug_formation,2, 1), current_move.gallons_used_so_far));

	return;
}

//there are 3 main actions that can be performed on the set of jugs
std::vector<Jug> Get_Jugs_After_Fill_Of_Index(std::vector<Jug> jugs, size_t const& index){
	Fill_Jug_Index(jugs,index);
	return jugs;
}
void Fill_Jug_Index(std::vector<Jug> & jugs, size_t const& index){
	Fill_Up_Jug(jugs[index]);
	return;
}
	void Fill_Up_Jug(Jug & jug){
	jug.amount = jug.capacity;
	return;
}
Gallon Get_Gallon_Amount_After_Fill(Jug const& jug) {
	return jug.capacity - jug.amount;
}

std::vector<Jug> Get_Jugs_After_Empty_Of_Index(std::vector<Jug> jugs, size_t const& index){
	Empty_Jug_Index(jugs,index);
	return jugs;
}
void Empty_Jug_Index(std::vector<Jug> & jugs, size_t const& index){
	Empty_Jug(jugs[index]);
	return;
}
	void Empty_Jug(Jug & jug){
	jug.amount = 0;
	return;
}

std::vector<Jug> Get_Jugs_After_Pour_Of_Indexes(std::vector<Jug> jugs, size_t const& pour_index, size_t const& fill_index){
	Pour_Jug_Index(jugs,pour_index,fill_index);
	return jugs;
}
void Pour_Jug_Index(std::vector<Jug> & jugs, size_t const& pour_index, size_t const& fill_index){
	Pour_Jug(jugs[pour_index],jugs[fill_index]);
	return;
}
	void Pour_Jug(Jug & pour_jug, Jug & fill_jug){
	while (pour_jug.amount > 0 && fill_jug.amount < fill_jug.capacity){
		fill_jug.amount += 1;
		--pour_jug.amount;
	}
	return;
}

//checking
bool Goal_Has_Been_Reached(std::vector<Jug> const& jugs, Gallon const& goal){

	for (auto const& jug: jugs){
		if (jug.amount == goal){
			return true;
		}
	}

	return false;
}


void Print_Results(Input_Data const& input_data, Gallon const& solution) {

	std::cout << "Given jugs with capacities " <<
	input_data.jug_capacities[0] << ", " << input_data.jug_capacities[1] << " and " << input_data.jug_capacities[2] <<
	", target " << input_data.goal <<  " is ";
	if (solution ==  std::numeric_limits<Gallon>::max()) {
		std::cout <<  "not achievable";
	}else{
		std::cout <<  "achievable using " << solution <<  " gallons of water";
	}
	std::cout << ".\n";

	return;
}




