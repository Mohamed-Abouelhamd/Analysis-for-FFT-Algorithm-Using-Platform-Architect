::namespace eval ::pct::build {
    proc add_vpsim_path { fromPath toPath } {
        while { [string first "\\" "$fromPath"] >= 0 } {
            set idx [string first "\\" "$fromPath"]
            set fromPath [string replace "$fromPath" $idx $idx "/" ]
        }
        if {[file isdirectory "$fromPath"]} {
            foreach childPath [glob -nocomplain -directory "$fromPath" "*"] {
                set newToPath "$toPath/[file tail $fromPath]"
                ::file mkdir "$newToPath"
                add_vpsim_path "$childPath" "$newToPath"
            }
        } else {
            if {![file isdirectory "$toPath"] && \
                [file dirname "$toPath"] != "."} then {
              ::file mkdir [file dirname "$toPath"]
            }
            ::file copy -force -- "$fromPath" "$toPath"
        }
    }
    proc add_vppack_path { fromPath toPath } {
        while { [string first "\\" "$fromPath"] >= 0 } {
            set idx [string first "\\" "$fromPath"]
            set fromPath [string replace "$fromPath" $idx $idx "/" ]
        }
        if {[file isdirectory "$fromPath"]} {
            foreach childPath [glob -nocomplain -directory "$fromPath" "*"] {
                add_vppack_path "$childPath" "$toPath/[file tail $fromPath]"
            }
        } else {
            ::scsh::vp::add_file_to_package "$fromPath" "$toPath"
        }
    }
  proc callback {args} {
    #START_OF_LOCAL_DYNAMIC_LIBRARY_SEARCH_PATHS
    #END_OF_LOCAL_DYNAMIC_LIBRARY_SEARCH_PATHS
    ::scsh::cwr_add_ip_load_library_dir {${SNPS_VP_HOME}/IP_common/common_debug/lib/linux.gcc-9.2-64}
    ::scsh::cwr_add_ip_load_library_dir {./simulation/FastBuild/common_debug}
    [namespace current]::add_vppack_path "[::subst -nobackslashes -nocommands {$::env(SNPS_VP_HOME)/IP_common/common_debug/lib/linux.gcc-9.2-64/libipdebug.so}]" "[::subst -nobackslashes -nocommands {simulation/FastBuild/common_debug}]"
    [namespace current]::add_vppack_path "[::subst -nobackslashes -nocommands {/cad/adi/apps/synopsys/pa/2023.03-1/IP/GenericIPlib/SystemC/lib/linux.gcc-9.2-64/libClockGenerator.so}]" "[::subst -nobackslashes -nocommands {simulation/FastBuild/GenericIPlib}]"
    [namespace current]::add_vppack_path "[::subst -nobackslashes -nocommands {/cad/adi/apps/synopsys/pa/2023.03-1/IP/GenericIPlib/SystemC/lib/linux.gcc-9.2-64/libMemory_generic.so}]" "[::subst -nobackslashes -nocommands {simulation/FastBuild/GenericIPlib}]"
    [namespace current]::add_vppack_path "[::subst -nobackslashes -nocommands {/cad/adi/apps/synopsys/pa/2023.03-1/IP/GenericIPlib/SystemC/lib/linux.gcc-9.2-64/libSig_drive.so}]" "[::subst -nobackslashes -nocommands {simulation/FastBuild/GenericIPlib}]"
    [namespace current]::add_vppack_path "[::subst -nobackslashes -nocommands {/cad/adi/apps/synopsys/pa/2023.03-1/IP/GenericIPlib/SystemC/lib/linux.gcc-9.2-64/librst.so}]" "[::subst -nobackslashes -nocommands {simulation/FastBuild/GenericIPlib}]"
    [namespace current]::add_vppack_path "[::subst -nobackslashes -nocommands {/cad/adi/apps/synopsys/pa/2023.03-1/SLS/linux/pc/TLM2_PL/SystemC/lib/linux.gcc-9.2-64/libtlm2_pl.so}]" "[::subst -nobackslashes -nocommands {simulation/FastBuild/TLM2_PL}]"
    [namespace current]::add_vppack_path "[::subst -nobackslashes -nocommands {/home/mmoussa/Projects/FFT/results/run/export/parameters/HARDWARE.unevald.parameters}]" "[::subst -nobackslashes -nocommands {simulation/parameters}]"
  }
  ::scsh::add_build_callback [::namespace current]::callback
}
