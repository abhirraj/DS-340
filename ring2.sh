#!/bin/bash
#SBATCH -N 1
#SBATCH -p RM-shared
#SBATCH -t 5:00:00
#SBATCH --ntasks-per-node 2

mpiexec -np 10 --oversubscribe ./ring2 -o ring2_out.txt
