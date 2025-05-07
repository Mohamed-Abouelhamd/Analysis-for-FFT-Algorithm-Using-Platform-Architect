file delete -force monitors.xml
source $::env(SNPS_VP_HOME)/pa/plugins/IMPO/simulation/sim_run/rs_help_procs.tcl
source /home/mmoussa/Projects/FFT/results/run/export/vpxsh_scenario_desc.tcl
if {[catch {source "/cad/adi/apps/synopsys/pa/2023.03-1/IP/SCML_TM_VPU_20/Internal/scripts/custom_monitors.tcl"} err]} {   puts "Error in sourcing startup script /cad/adi/apps/synopsys/pa/2023.03-1/IP/SCML_TM_VPU_20/Internal/scripts/custom_monitors.tcl: $err" }
#attaching monitors if analysis is enabled
proc ::sim::create_vpx_monitors {} {
      ::sim::create_vpx_monitor /home/mmoussa/Projects/FFT/results/run {{/HARDWARE#{{Deadline Analysis} {Deadline Analysis} true true {Aggregation interval}}} {/HARDWARE#{{FastTrack Errors} {FastTrack Errors} true {} {}}} {/HARDWARE#{{MCO Residency} {MCO Residency} true false {Aggregation interval}}} {/HARDWARE#{{MCO Resource} {MCO Resource} true false {Aggregation interval}}} {/HARDWARE#{{MCO Task} {MCO Task} true true {Aggregation interval}}}} "10000 ns" false false false 0  1 false true true true
      # monitor_creation_flag is used to communicate the completion status back to the auto_continue loop.
      variable ::impo_sim::monitor_creation_flag
      set ::impo_sim::monitor_creation_flag 2
}

::sim::create_vpx_monitors
