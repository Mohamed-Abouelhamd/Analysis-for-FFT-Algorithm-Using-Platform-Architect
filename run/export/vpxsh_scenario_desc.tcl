#############################################################################
# Copyright 1996-2023 Synopsys, Inc.                                        #
#                                                                           #
# This Synopsys software and all associated documentation are proprietary   #
# to Synopsys, Inc. and may only be used pursuant to the terms and          #
# conditions of a written license agreement with Synopsys, Inc.             #
# All other use, reproduction, modification, or distribution of the         #
# Synopsys software or the associated documentation is strictly prohibited. #
#############################################################################

#############################################################################
# The script below is used in the flow of vpx_startup_script to get scenario
# name and scenario properties
#############################################################################

namespace eval ::simulation {

variable script_dir [file dirname [file normalize [info script]]]

#############################################################################
# Proc: get_scenario_name
# Description: Get scenario name in VPX
#############################################################################
proc get_scenario_name {} {
    variable script_dir

    return [::sim::get_scenario_name_in_vpx $script_dir]
}

#############################################################################
# Proc: get_scenario_property
# Description: Get scenario properties in VPX
#############################################################################
proc get_scenario_property {args} {

    return [::sim::get_scenario_property_in_vpx $args]

}

}
variable ::sim::flows_info
 array set ::sim::flows_info {Workload {{Enable true} {Mapping Mapping:Map} {Name Workload}}}
 variable ::sim::params_info
 array set ::sim::params_info {}
 variable ::sim::settings_info
 set ::sim::settings_info {{run_manager LocalHost} {num_parallel_runs 1} {results_dir results} {vpx_startup_script {}} {power_analysis_script {}} {post_processing_cbk {}} {use_vpconfig_for_sim_run true} {include_connected_buses true} {remove_export_dir_after_sim_run false} {disable_results_extraction true} {license_polling_interval_s 60} {vpxsh_arguments {}} {scenario_polling_interval_ms 500} {scen_run_setting {Run default}} {reuse_build false} {reuse_build_export_dir {}} {run_for_duration -1} {start_timeout_s 1000} {run_wall_clk_timeout_s -1} {simulation_arguments {}} {enable_global_bus_analysis false} {analysis_interval 10000ns} {fasttrack_log_level 0} {record_analysis_start_time 0} {record_end_to_end_propagation_delay true} {target_perspective false} {thread_specific_analysis false} {trans_attr_specific_analysis false} {tlm_port_trace_max_data 1} {tlm_port_trace_record_byte_enable false} {{Deadline Analysis Stats} true} {{Deadline Analysis Trace} true} {{MCO Channel Analysis Stats} false} {{MCO Channel Analysis Trace} false} {{MCO Task Stats} true} {{MCO Task Trace} true} {{Activity Stats} false} {{Activity Trace} false} {{FastTrack Errors} true} {{FastTrack Info} false} {{FastTrack Model Internal} false} {{FastTrack Warnings} false} {{MCO Residency Stats} true} {{MCO Residency Trace} false} {{MCO Resource Stats} true} {{MCO Resource Trace} false} {{TLM Port Trace} false}}
