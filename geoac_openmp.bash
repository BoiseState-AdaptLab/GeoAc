#!/bin/bash

#SBATCH -J GeoAc_omp        # job name
#SBATCH -o log_slurm.o%j      # output and error file name (%j expands to jobID)
#SBATCH -n 28                 # total number of tasks/cores requested
#SBATCH -N 1 		              # number of nodes you want to run on	
#SBATCH -p adaptlab           # queue (partition) -- defq, eduq, gpuq, shortq
#SBATCH -t 24:00:00           # run time (hh:mm:ss) - 12.0 hours in this example.

# Mail alert at start, end and abortion of execution
#SBATCH --mail-type=FAIL,END

# Send mail to this address
#SBATCH --mail-user=ravishankar@u.boisestate.edu

# Generally needed modules:
module load slurm

# Execute the program
time sh run_example.sh

# Exit if mpirun errored:
status=$?
if [ $status -ne 0 ]; then
    exit $status
fi

