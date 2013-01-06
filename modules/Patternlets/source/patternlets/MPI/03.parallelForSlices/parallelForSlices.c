/* parallelForSlices.c
 * ... illustrates the parallel for loop pattern in MPI 
 *	in which processes perform the loop's iterations in 'slices' 
 *	(simple, and useful when loop iterations do not access
 *	 memory/cache locations) ...
 * Joel Adams, Calvin College, at November 2009.
 */

#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
	const int ITERS = 16;
	int id = -1, numProcesses = -1, i = -1;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcesses);

	for (i = id; i < ITERS; i += numProcesses) {
		printf("Process %d is performing iteration %d\n",
			id, i);
	}

	MPI_Finalize();
	return 0;
}

