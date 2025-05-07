#!/bin/bash
echo "
RUNNING SCENARIO run ON HOST `hostname`" >> "/home/mmoussa/Projects/FFT/results/run/run_scenario_op.log"
echo "
SETTING LICENSE VARIABLES" >> "/home/mmoussa/Projects/FFT/results/run/run_scenario_op.log"
export LM_LICENSE_FILE="27000@limklicsrv2.adbvdesign:6464@ashsvcrh7licsrv6.engsvc:7906@adbllicsrv.adbldesign:27000@adlklicsrv2-dr.adsdesign:7906@adbllicsrv-dr.adbvdesign:6464@adslicsrv2-dr.adbvdesign:27000@svlmmglob.maxim-ic.com:5454@ashsvcrh7licsrv7.engsvc" >> "/home/mmoussa/Projects/FFT/results/run/run_scenario_op.log"
echo "
Setting SNPS_VP_COMPILER to gcc-9.2
 " >> "/home/mmoussa/Projects/FFT/results/run/run_scenario_op.log"
export SNPS_VP_COMPILER=gcc-9.2 >> "/home/mmoussa/Projects/FFT/results/run/run_scenario_op.log"
echo "
SOURCING PCT /cad/adi/apps/synopsys/pa/2023.03-1/SLS/linux/setup.sh " >> "/home/mmoussa/Projects/FFT/results/run/run_scenario_op.log"
. /cad/adi/apps/synopsys/pa/2023.03-1/SLS/linux/setup.sh PA-Base >> "/home/mmoussa/Projects/FFT/results/run/run_scenario_op.log" 2>&1
export SNPS_QUEUE=1 >> "/home/mmoussa/Projects/FFT/results/run/run_scenario_op.log"
export SNPS_QUEUE_SLEEPTIME=60 >> "/home/mmoussa/Projects/FFT/results/run/run_scenario_op.log"
export SNPS_VPX_USER_HOME=/home/mmoussa/Projects/FFT/results/run >> "/home/mmoussa/Projects/FFT/results/run/run_scenario_op.log"
export COWARE_SIMTOKEN_DIR=/home/mmoussa/Projects/FFT/results/run >> "/home/mmoussa/Projects/FFT/results/run/run_scenario_op.log"
export SNPS_VPX_LENIENT_CALLBACKS=1 >> "/home/mmoussa/Projects/FFT/results/run/run_scenario_op.log"
export RUN_SCENARIO_TCL=/home/mmoussa/Projects/FFT/results/run/run_scenario.tcl >> "/home/mmoussa/Projects/FFT/results/run/run_scenario_op.log" 2>&1
pcsh "$RUN_SCENARIO_TCL" --suppress-startup-warn >> "/home/mmoussa/Projects/FFT/results/run/run_scenario_op.log" 2>&1
echo "
"
