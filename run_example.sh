#!/bin/sh


# GeoAc2D [option] profile.met [parameters]
export OMP_NUM_THREADS=1

./GeoAcGlobal -prop WASP.met \
lat_src=38.73 lon_src=43.45 z_src=0.0 \
theta_min=56.0 theta_max=90.0 theta_step=1.0 \
phi_min=0.0 phi_max=20.0 phi_step=10 \
bounces=0 rng_max=2000


# theta_min=0.0 theta_max=34.0 theta_step=1.0 \
# phi_min=0.0 phi_max=350.0 phi_step=10 \
