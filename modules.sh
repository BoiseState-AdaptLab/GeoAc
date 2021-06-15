#!/bin/sh
module list
echo "Removing all modules" 
module purge
echo "Loading modules for GeoAc"
module load slurm/19.05.8
module load gcc/7.2.0
module load openmpi4/gcc/4.0.1
module load hdf5/gcc/1.10.5
module load netcdf/gcc/openmpi/4.7.4
echo "Done!"
