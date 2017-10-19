// ============================================================================
// file: project_two.c
// ============================================================================
// Programmers: Jose Ordaz (CWID:) & Faraj Haddad (CWID:)
// Date: 10/19/2017
// Class: CPSC-351 "Operating System Concepts"
// Time: T/TH 2:30 P.M.
// Instructor: Dr. McCarthy, W.
// Project: Sudoku Solution Validator
//
// Description: As stated in the 9th Edition Silbershatz text, Ch04, Pg 197,
// this program consists of designing a multithreaded application that
// determines whether a soduku solution is valid. The approch we took was to
// create three seperate threads to cover the nine Rows, Columns, and Grids.
//
// HOW to Compile: gcc -Wall -std=c99 project_two.c -pthread -o project_one.exe
// ============================================================================


 



// ===  =====================================================================
//
// 
// ===========================================================================================




// === main =================================================================================
// 
// ==========================================================================================
int	main(){

	void*   function_pointers[NUM_THREADS] = {CheckRows_runner,CheckColumns_runner,
						  CheckGrid_runner};
	pthread_t   t_ids[NUM_THREADS];
	// Launch Threads
	struct runner_struct arg[NUM_THREADS];

	for(int i = 0; i < NUM_THREADS; ++i){
		arg[i].case_sum = 0;
		pthread_attr_t attr;
		pthread_attr_init(&attr);   // get the default attributes
		pthread_create(&t_ids[i],&attr,function_pointers[i],&arg[i]); // create the thread

	}

	int sum = 0; // sum of all arg->case_sums

	// Wait untill each thread is done working
	for(int i = 0; i < NUM_THREADS; ++i){
		pthread_join(t_ids[i],NULL);    // wait for the thread to exit
		sum += arg[i].case_sum;
	}

	if( sum == 27){printf("The Sudoku Set is a valid set\n");}
	 else{ printf("The Sudoku Set is Not a valid set\n"); }

	return 0;


}// end of main