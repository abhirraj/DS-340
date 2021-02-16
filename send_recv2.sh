#!/bin/bash
#SBATCH -N 1
#SBATCH -p RM-shared
#SBATCH -t 5:00:00
#SBATCH --ntasks-per-node 2

mpiexec -np 10 --oversubscribe ./send_recv2 -o send_recv2_out.xt
