#!/bin/bash
#SBATCH -J my_job_name
#SBATCH -o %J.out
#SBATCH -e %J.err
#SBATCH -n 24
#SBATCH -p small
#SBATCH -t 5
#SBATCH --reservation=summer_school
aprun -n 24 /homeappl/home/training059/git/summerschool/unix/prog
