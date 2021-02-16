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

  int token;

  // TODO: receive from higher process and send to the lower process
  if (world_rank != world_size - 1) {
    // TODO: complete the receive command
    MPI_Recv(&token, 1, MPI_INT, world_rank + 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    // TODO: complete the print command

    printf("Process %d received token %d from process %d\n", world_rank, token,  world_rank + 1);
  } else {
    token = -1;
  }

  // TODO: complete the send command

  // TODO: complete the corner case
  if (world_rank = world_size - 1) {
    // TODO: complete the receive command
    MPI_Recv(&token, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
    // TODO: complete the print command
    printf("Process %d received token %d from process %d\n", world_rank, token,
           0);
  }
  MPI_Finalize();
}