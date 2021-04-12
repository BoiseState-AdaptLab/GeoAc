#!/bin/sh

echo "Loading netCDF modules for GeoAc"
module list
module purge
module load slurm/17.11.12
module load gcc/7.2.0
module load openmpi4/gcc/4.0.1
module load hdf5/gcc/1.10.5
module load netcdf/gcc/openmpi/4.7.4
