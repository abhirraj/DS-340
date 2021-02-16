#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  // Find out rank, size
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // We are assuming at least 2 processes for this task
  if (world_size < 2 || world_size % 2 != 0) {
    fprintf(stderr, "World size must be an even number greater than 1 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  // TODO: complete the send & receive commands
  int number;
  if (world_rank % 2 == 0) { // TODO: send at even process
    number = -1;
    MPI_Send(
      /* data         = */ &number, 
      /* count        = */ 1, 
      /* datatype     = */ MPI_INT, 
      /* destination  = */ world_rank + 1, 
      /* tag          = */ 0, 
      /* communicator = */ MPI_COMM_WORLD);
  } else { // TODO: receive at odd process
    MPI_Recv(
      /* data         = */ &number, 
      /* count        = */ 1, 
      /* datatype     = */ MPI_INT, 
      /* source       = */ world_rank - 1, 
      /* tag          = */ 0, 
      /* communicator = */ MPI_COMM_WORLD, 
      /* status       = */ MPI_STATUS_IGNORE);
    printf("Process %d received number %d from process %d\n",world_rank,number,world_rank - 1 );
  }

  MPI_Finalize();
}
