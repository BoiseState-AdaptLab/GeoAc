#!/bin/sh

#Set number of threads for the OMP run
export OMP_NUM_THREADS=28

#Large run ~58 minutes
#./GeoAcGlobal -prop WASP.met \
#lat_src=38.73 lon_src=43.45 z_src=0.0 \
#theta_min=0.0 theta_max=90 theta_step=0.1 \
#phi_min=0.0 phi_max=350.0 phi_step=1 \
#bounces=0 rng_max=5000

#Small run ~3 seconds
./GeoAcGlobal -prop WASP.met \
lat_src=38.73 lon_src=43.45 z_src=0.0 \
theta_min=0.0 theta_max=20 theta_step=1 \
phi_min=0.0 phi_max=350.0 phi_step=10 \
bounces=0 rng_max=2000

