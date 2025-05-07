#ifndef HARDWARE_H
#define HARDWARE_H

#include "systemc.h"
#include "SystemC/include/scml_tm_fifo_chnl.h"
#include "SystemC/include/scml_tm_generic_task.h"
#include "SystemC/include/scml_tm_glbl_vpu.h"
#include "SystemC/include/scml_tm_memory_driver.h"
#include "SystemC/include/scml_tm_mmu.h"
#include "SystemC/include/scml_tm_stochastic_processing_model.h"
#include "SystemC/include/scml_tm_task_def_function.h"
#include "SystemC/include/vpu.h"
#include "common/scml_tm_stubs.h"
#include "common/scml_tm_task_graph.h"
#include "deque"
#include "tlm.h"
#include "cwr_sc_object_creator.h"
#include "cwr_sc_object_registry.h"

//-------------------------------

struct CwrModule_HARDWARE_HW_HW_CPU : public VPU
{
  sc_in<bool> m_PE_p_clk_pin;
  tlm::tlm_base_initiator_socket<64, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND> PE_p_insn;
  tlm::tlm_base_initiator_socket<64, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND> PE_p_data;
  sc_in<bool> m_DRVR_p_clk_pin;
  tlm::tlm_base_initiator_socket<64, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND> DRVR_p_socket;
  
  scml_tm_stochastic_processing_model<64> PE;
  scml_tm_memory_driver<64> DRVR;
  
  CwrModule_HARDWARE_HW_HW_CPU(sc_module_name _name) :
    VPU(_name),
    m_PE_p_clk_pin("PE_p_clk_pin"),
    PE_p_insn("PE_p_insn"),
    PE_p_data("PE_p_data"),
    m_DRVR_p_clk_pin("DRVR_p_clk_pin"),
    DRVR_p_socket("DRVR_p_socket"),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    PE("PE"),
    DRVR("DRVR")
  {
    PE.p_clk(m_PE_p_clk_pin);
    add_portname_attr(PE.p_clk, "p_clk");
    add_portname_attr(m_PE_p_clk_pin, "PE_p_clk");
    PE.p_insn(PE_p_insn);
    add_portname_attr(PE.p_insn, "p_insn");
    add_portname_attr(PE_p_insn, "PE_p_insn");
    PE.p_data(PE_p_data);
    add_portname_attr(PE.p_data, "p_data");
    add_portname_attr(PE_p_data, "PE_p_data");
    DRVR.p_clk(m_DRVR_p_clk_pin);
    add_portname_attr(DRVR.p_clk, "p_clk");
    add_portname_attr(m_DRVR_p_clk_pin, "DRVR_p_clk");
    DRVR.p_socket(DRVR_p_socket);
    add_portname_attr(DRVR.p_socket, "p_socket");
    add_portname_attr(DRVR_p_socket, "DRVR_p_socket");
  }

  CwrModule_HARDWARE_HW_HW_CPU* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

struct CwrModule_HARDWARE_HW_HW_Butterfly : public VPU
{
  sc_in<bool> m_PE_p_clk_pin;
  tlm::tlm_base_initiator_socket<64, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND> PE_p_insn;
  tlm::tlm_base_initiator_socket<64, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND> PE_p_data;
  sc_in<bool> m_DRVR_p_clk_pin;
  tlm::tlm_base_initiator_socket<64, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND> DRVR_p_socket;
  
  scml_tm_stochastic_processing_model<64> PE;
  scml_tm_memory_driver<64> DRVR;
  
  CwrModule_HARDWARE_HW_HW_Butterfly(sc_module_name _name) :
    VPU(_name),
    m_PE_p_clk_pin("PE_p_clk_pin"),
    PE_p_insn("PE_p_insn"),
    PE_p_data("PE_p_data"),
    m_DRVR_p_clk_pin("DRVR_p_clk_pin"),
    DRVR_p_socket("DRVR_p_socket"),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    PE("PE"),
    DRVR("DRVR")
  {
    PE.p_clk(m_PE_p_clk_pin);
    add_portname_attr(PE.p_clk, "p_clk");
    add_portname_attr(m_PE_p_clk_pin, "PE_p_clk");
    PE.p_insn(PE_p_insn);
    add_portname_attr(PE.p_insn, "p_insn");
    add_portname_attr(PE_p_insn, "PE_p_insn");
    PE.p_data(PE_p_data);
    add_portname_attr(PE.p_data, "p_data");
    add_portname_attr(PE_p_data, "PE_p_data");
    DRVR.p_clk(m_DRVR_p_clk_pin);
    add_portname_attr(DRVR.p_clk, "p_clk");
    add_portname_attr(m_DRVR_p_clk_pin, "DRVR_p_clk");
    DRVR.p_socket(DRVR_p_socket);
    add_portname_attr(DRVR.p_socket, "p_socket");
    add_portname_attr(DRVR_p_socket, "DRVR_p_socket");
  }

  CwrModule_HARDWARE_HW_HW_Butterfly* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

struct CwrModule_HARDWARE_HW_HW_DMA1 : public VPU
{
  sc_in<bool> m_PE_p_clk_pin;
  tlm::tlm_base_initiator_socket<64, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND> PE_p_insn;
  tlm::tlm_base_initiator_socket<64, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND> PE_p_data;
  sc_in<bool> m_DRVR_p_clk_pin;
  tlm::tlm_base_initiator_socket<64, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND> DRVR_p_socket;
  
  scml_tm_stochastic_processing_model<64> PE;
  scml_tm_memory_driver<64> DRVR;
  
  CwrModule_HARDWARE_HW_HW_DMA1(sc_module_name _name) :
    VPU(_name),
    m_PE_p_clk_pin("PE_p_clk_pin"),
    PE_p_insn("PE_p_insn"),
    PE_p_data("PE_p_data"),
    m_DRVR_p_clk_pin("DRVR_p_clk_pin"),
    DRVR_p_socket("DRVR_p_socket"),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    PE("PE"),
    DRVR("DRVR")
  {
    PE.p_clk(m_PE_p_clk_pin);
    add_portname_attr(PE.p_clk, "p_clk");
    add_portname_attr(m_PE_p_clk_pin, "PE_p_clk");
    PE.p_insn(PE_p_insn);
    add_portname_attr(PE.p_insn, "p_insn");
    add_portname_attr(PE_p_insn, "PE_p_insn");
    PE.p_data(PE_p_data);
    add_portname_attr(PE.p_data, "p_data");
    add_portname_attr(PE_p_data, "PE_p_data");
    DRVR.p_clk(m_DRVR_p_clk_pin);
    add_portname_attr(DRVR.p_clk, "p_clk");
    add_portname_attr(m_DRVR_p_clk_pin, "DRVR_p_clk");
    DRVR.p_socket(DRVR_p_socket);
    add_portname_attr(DRVR.p_socket, "p_socket");
    add_portname_attr(DRVR_p_socket, "DRVR_p_socket");
  }

  CwrModule_HARDWARE_HW_HW_DMA1* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

struct CwrModule_HARDWARE_HW_HW_DMA2 : public VPU
{
  sc_in<bool> m_PE_p_clk_pin;
  tlm::tlm_base_initiator_socket<64, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND> PE_p_insn;
  tlm::tlm_base_initiator_socket<64, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND> PE_p_data;
  sc_in<bool> m_DRVR_p_clk_pin;
  tlm::tlm_base_initiator_socket<64, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND> DRVR_p_socket;
  
  scml_tm_stochastic_processing_model<64> PE;
  scml_tm_memory_driver<64> DRVR;
  
  CwrModule_HARDWARE_HW_HW_DMA2(sc_module_name _name) :
    VPU(_name),
    m_PE_p_clk_pin("PE_p_clk_pin"),
    PE_p_insn("PE_p_insn"),
    PE_p_data("PE_p_data"),
    m_DRVR_p_clk_pin("DRVR_p_clk_pin"),
    DRVR_p_socket("DRVR_p_socket"),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    PE("PE"),
    DRVR("DRVR")
  {
    PE.p_clk(m_PE_p_clk_pin);
    add_portname_attr(PE.p_clk, "p_clk");
    add_portname_attr(m_PE_p_clk_pin, "PE_p_clk");
    PE.p_insn(PE_p_insn);
    add_portname_attr(PE.p_insn, "p_insn");
    add_portname_attr(PE_p_insn, "PE_p_insn");
    PE.p_data(PE_p_data);
    add_portname_attr(PE.p_data, "p_data");
    add_portname_attr(PE_p_data, "PE_p_data");
    DRVR.p_clk(m_DRVR_p_clk_pin);
    add_portname_attr(DRVR.p_clk, "p_clk");
    add_portname_attr(m_DRVR_p_clk_pin, "DRVR_p_clk");
    DRVR.p_socket(DRVR_p_socket);
    add_portname_attr(DRVR.p_socket, "p_socket");
    add_portname_attr(DRVR_p_socket, "DRVR_p_socket");
  }

  CwrModule_HARDWARE_HW_HW_DMA2* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

SC_MODULE(CwrModule_HARDWARE_HW_HW_i_Bus_BackBone)
{
  
  
  CwrModule_HARDWARE_HW_HW_i_Bus_BackBone(sc_module_name _name) :
    sc_module(_name),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true)
  {
  }

  CwrModule_HARDWARE_HW_HW_i_Bus_BackBone* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

SC_MODULE(CwrModule_HARDWARE_HW_HW_i_Bus)
{
  
  CwrModule_HARDWARE_HW_HW_i_Bus_BackBone BackBone;
  
  CwrModule_HARDWARE_HW_HW_i_Bus(sc_module_name _name) :
    sc_module(_name),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    BackBone("BackBone")
  {
  }

  CwrModule_HARDWARE_HW_HW_i_Bus* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

SC_MODULE(CwrModule_HARDWARE_HW_HW)
{
  sc_signal<sc_uint<32> > conn_i_Memory_Generic_p_PSELECT_pin;
  sc_signal<bool> conn_i_Memory_Generic_p_PowerDown_pin;
  sc_signal<bool> conn_i_Memory_Generic_p_Retention_pin;
  
  CwrModule_HARDWARE_HW_HW_CPU CPU;
  CwrModule_HARDWARE_HW_HW_Butterfly Butterfly;
  CwrModule_HARDWARE_HW_HW_DMA1 DMA1;
  CwrModule_HARDWARE_HW_HW_DMA2 DMA2;
  sc_core::sc_attribute<std::string> m_cwr_module_kind;
  CwrModule_HARDWARE_HW_HW_i_Bus i_Bus;
  std::unique_ptr<sc_core::sc_module> i_Memory_Generic;
  std::unique_ptr<sc_core::sc_module> i_ClockGenerator;
  std::unique_ptr<sc_core::sc_module> i_ResetGenerator;
  sc_signal<bool> stub_i_ResetGenerator_p_RST;
  std::unique_ptr<sc_core::sc_module> stub_i_Memory_Generic_p_PSELECT;
  std::unique_ptr<sc_core::sc_module> stub_i_Memory_Generic_p_PowerDown;
  std::unique_ptr<sc_core::sc_module> stub_i_Memory_Generic_p_Retention;
  std::unique_ptr<sc_core::sc_module> stub_Butterfly_DRVR_p_socket;
  std::unique_ptr<sc_core::sc_module> stub_Butterfly_PE_p_data;
  std::unique_ptr<sc_core::sc_module> stub_Butterfly_PE_p_insn;
  std::unique_ptr<sc_core::sc_module> stub_CPU_DRVR_p_socket;
  std::unique_ptr<sc_core::sc_module> stub_CPU_PE_p_data;
  std::unique_ptr<sc_core::sc_module> stub_CPU_PE_p_insn;
  std::unique_ptr<sc_core::sc_module> stub_DMA1_DRVR_p_socket;
  std::unique_ptr<sc_core::sc_module> stub_DMA1_PE_p_data;
  std::unique_ptr<sc_core::sc_module> stub_DMA1_PE_p_insn;
  std::unique_ptr<sc_core::sc_module> stub_DMA2_DRVR_p_socket;
  std::unique_ptr<sc_core::sc_module> stub_DMA2_PE_p_data;
  std::unique_ptr<sc_core::sc_module> stub_DMA2_PE_p_insn;
  std::unique_ptr<sc_core::sc_module> stub_i_Memory_Generic_MEM;
  
  CwrModule_HARDWARE_HW_HW(sc_module_name _name) :
    sc_module(_name),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    conn_i_Memory_Generic_p_PSELECT_pin("conn_i_Memory_Generic_p_PSELECT_pin"),
    conn_i_Memory_Generic_p_PowerDown_pin("conn_i_Memory_Generic_p_PowerDown_pin"),
    conn_i_Memory_Generic_p_Retention_pin("conn_i_Memory_Generic_p_Retention_pin"),
    CPU("CPU"),
    Butterfly("Butterfly"),
    DMA1("DMA1"),
    DMA2("DMA2"),
    m_cwr_module_kind("CWR_MODULE_KIND", "Bus Framework"),
    i_Bus("i_Bus"),
    i_Memory_Generic(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("GIPL_MEM0<32>","i_Memory_Generic")))),
    i_ClockGenerator(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("GIPL_CLK0","i_ClockGenerator")))),
    i_ResetGenerator(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("GIPL_RST0","i_ResetGenerator")))),
    stub_i_ResetGenerator_p_RST("stub_i_ResetGenerator_p_RST"),
    stub_i_Memory_Generic_p_PSELECT(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("SigDrive0<sc_uint<32> >","stub_i_Memory_Generic_p_PSELECT")))),
    stub_i_Memory_Generic_p_PowerDown(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("SigDrive0<bool>","stub_i_Memory_Generic_p_PowerDown")))),
    stub_i_Memory_Generic_p_Retention(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("SigDrive0<bool>","stub_i_Memory_Generic_p_Retention")))),
    stub_Butterfly_DRVR_p_socket(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("TLM2InitiatorSocketStub0<64, tlm::tlm_base_protocol_types>","stub_Butterfly_DRVR_p_socket")))),
    stub_Butterfly_PE_p_data(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("TLM2InitiatorSocketStub0<64, tlm::tlm_base_protocol_types>","stub_Butterfly_PE_p_data")))),
    stub_Butterfly_PE_p_insn(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("TLM2InitiatorSocketStub0<64, tlm::tlm_base_protocol_types>","stub_Butterfly_PE_p_insn")))),
    stub_CPU_DRVR_p_socket(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("TLM2InitiatorSocketStub0<64, tlm::tlm_base_protocol_types>","stub_CPU_DRVR_p_socket")))),
    stub_CPU_PE_p_data(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("TLM2InitiatorSocketStub0<64, tlm::tlm_base_protocol_types>","stub_CPU_PE_p_data")))),
    stub_CPU_PE_p_insn(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("TLM2InitiatorSocketStub0<64, tlm::tlm_base_protocol_types>","stub_CPU_PE_p_insn")))),
    stub_DMA1_DRVR_p_socket(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("TLM2InitiatorSocketStub0<64, tlm::tlm_base_protocol_types>","stub_DMA1_DRVR_p_socket")))),
    stub_DMA1_PE_p_data(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("TLM2InitiatorSocketStub0<64, tlm::tlm_base_protocol_types>","stub_DMA1_PE_p_data")))),
    stub_DMA1_PE_p_insn(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("TLM2InitiatorSocketStub0<64, tlm::tlm_base_protocol_types>","stub_DMA1_PE_p_insn")))),
    stub_DMA2_DRVR_p_socket(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("TLM2InitiatorSocketStub0<64, tlm::tlm_base_protocol_types>","stub_DMA2_DRVR_p_socket")))),
    stub_DMA2_PE_p_data(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("TLM2InitiatorSocketStub0<64, tlm::tlm_base_protocol_types>","stub_DMA2_PE_p_data")))),
    stub_DMA2_PE_p_insn(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("TLM2InitiatorSocketStub0<64, tlm::tlm_base_protocol_types>","stub_DMA2_PE_p_insn")))),
    stub_i_Memory_Generic_MEM(dynamic_cast<sc_module*>(conf::cwr_sc_object_registry::inst().addObject(conf::ScObjectFactory::inst().create("TLM2TargetSocketStub0<32, tlm::tlm_base_protocol_types>","stub_i_Memory_Generic_MEM"))))
  {
    (*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".i_Memory_Generic.p_CLK")))((*conf::cwr_sc_object_registry::inst().getExport(name() + std::string(".i_ClockGenerator.p_CLK"))));
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".i_Memory_Generic.p_CLK"))).get_object(), "CLK");
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getExport(name() + std::string(".i_ClockGenerator.p_CLK"))).get_object(), "CLK");
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createPortProxy(&CPU.m_DRVR_p_clk_pin)))((*conf::cwr_sc_object_registry::inst().getExport(name() + std::string(".i_ClockGenerator.p_CLK"))));
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createPortProxy(&CPU.m_PE_p_clk_pin)))((*conf::cwr_sc_object_registry::inst().getExport(name() + std::string(".i_ClockGenerator.p_CLK"))));
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createPortProxy(&Butterfly.m_DRVR_p_clk_pin)))((*conf::cwr_sc_object_registry::inst().getExport(name() + std::string(".i_ClockGenerator.p_CLK"))));
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createPortProxy(&Butterfly.m_PE_p_clk_pin)))((*conf::cwr_sc_object_registry::inst().getExport(name() + std::string(".i_ClockGenerator.p_CLK"))));
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createPortProxy(&DMA1.m_DRVR_p_clk_pin)))((*conf::cwr_sc_object_registry::inst().getExport(name() + std::string(".i_ClockGenerator.p_CLK"))));
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createPortProxy(&DMA1.m_PE_p_clk_pin)))((*conf::cwr_sc_object_registry::inst().getExport(name() + std::string(".i_ClockGenerator.p_CLK"))));
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createPortProxy(&DMA2.m_DRVR_p_clk_pin)))((*conf::cwr_sc_object_registry::inst().getExport(name() + std::string(".i_ClockGenerator.p_CLK"))));
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createPortProxy(&DMA2.m_PE_p_clk_pin)))((*conf::cwr_sc_object_registry::inst().getExport(name() + std::string(".i_ClockGenerator.p_CLK"))));
    (*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".i_Memory_Generic.p_PageSelect")))(conn_i_Memory_Generic_p_PSELECT_pin);
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".i_Memory_Generic.p_PageSelect"))).get_object(), "p_PSELECT");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".i_Memory_Generic.p_PageSelect"))).get_object());
    (*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".stub_i_Memory_Generic_p_PSELECT.STUB")))(conn_i_Memory_Generic_p_PSELECT_pin);
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".stub_i_Memory_Generic_p_PSELECT.STUB"))).get_object(), "STUB");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".stub_i_Memory_Generic_p_PSELECT.STUB"))).get_object());
    (*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".i_Memory_Generic.p_PowerDown")))(conn_i_Memory_Generic_p_PowerDown_pin);
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".i_Memory_Generic.p_PowerDown"))).get_object(), "p_PowerDown");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".i_Memory_Generic.p_PowerDown"))).get_object());
    (*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".stub_i_Memory_Generic_p_PowerDown.STUB")))(conn_i_Memory_Generic_p_PowerDown_pin);
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".stub_i_Memory_Generic_p_PowerDown.STUB"))).get_object(), "STUB");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".stub_i_Memory_Generic_p_PowerDown.STUB"))).get_object());
    (*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".i_Memory_Generic.p_Retention")))(conn_i_Memory_Generic_p_Retention_pin);
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".i_Memory_Generic.p_Retention"))).get_object(), "p_Retention");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".i_Memory_Generic.p_Retention"))).get_object());
    (*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".stub_i_Memory_Generic_p_Retention.STUB")))(conn_i_Memory_Generic_p_Retention_pin);
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".stub_i_Memory_Generic_p_Retention.STUB"))).get_object(), "STUB");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".stub_i_Memory_Generic_p_Retention.STUB"))).get_object());
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createInitiatorSocketProxy(&Butterfly.DRVR_p_socket)))((*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_Butterfly_DRVR_p_socket.stubSocket"))));
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_Butterfly_DRVR_p_socket.stubSocket"))).get_object(), "stubSocket");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_Butterfly_DRVR_p_socket.stubSocket"))).get_object());
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createInitiatorSocketProxy(&Butterfly.PE_p_data)))((*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_Butterfly_PE_p_data.stubSocket"))));
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_Butterfly_PE_p_data.stubSocket"))).get_object(), "stubSocket");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_Butterfly_PE_p_data.stubSocket"))).get_object());
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createInitiatorSocketProxy(&Butterfly.PE_p_insn)))((*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_Butterfly_PE_p_insn.stubSocket"))));
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_Butterfly_PE_p_insn.stubSocket"))).get_object(), "stubSocket");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_Butterfly_PE_p_insn.stubSocket"))).get_object());
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createInitiatorSocketProxy(&CPU.DRVR_p_socket)))((*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_CPU_DRVR_p_socket.stubSocket"))));
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_CPU_DRVR_p_socket.stubSocket"))).get_object(), "stubSocket");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_CPU_DRVR_p_socket.stubSocket"))).get_object());
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createInitiatorSocketProxy(&CPU.PE_p_data)))((*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_CPU_PE_p_data.stubSocket"))));
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_CPU_PE_p_data.stubSocket"))).get_object(), "stubSocket");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_CPU_PE_p_data.stubSocket"))).get_object());
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createInitiatorSocketProxy(&CPU.PE_p_insn)))((*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_CPU_PE_p_insn.stubSocket"))));
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_CPU_PE_p_insn.stubSocket"))).get_object(), "stubSocket");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_CPU_PE_p_insn.stubSocket"))).get_object());
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createInitiatorSocketProxy(&DMA1.DRVR_p_socket)))((*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA1_DRVR_p_socket.stubSocket"))));
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA1_DRVR_p_socket.stubSocket"))).get_object(), "stubSocket");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA1_DRVR_p_socket.stubSocket"))).get_object());
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createInitiatorSocketProxy(&DMA1.PE_p_data)))((*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA1_PE_p_data.stubSocket"))));
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA1_PE_p_data.stubSocket"))).get_object(), "stubSocket");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA1_PE_p_data.stubSocket"))).get_object());
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createInitiatorSocketProxy(&DMA1.PE_p_insn)))((*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA1_PE_p_insn.stubSocket"))));
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA1_PE_p_insn.stubSocket"))).get_object(), "stubSocket");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA1_PE_p_insn.stubSocket"))).get_object());
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createInitiatorSocketProxy(&DMA2.DRVR_p_socket)))((*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA2_DRVR_p_socket.stubSocket"))));
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA2_DRVR_p_socket.stubSocket"))).get_object(), "stubSocket");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA2_DRVR_p_socket.stubSocket"))).get_object());
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createInitiatorSocketProxy(&DMA2.PE_p_data)))((*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA2_PE_p_data.stubSocket"))));
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA2_PE_p_data.stubSocket"))).get_object(), "stubSocket");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA2_PE_p_data.stubSocket"))).get_object());
    (*cwr_sc_proxy_temp(conf::cwr_sc_object_registry::createInitiatorSocketProxy(&DMA2.PE_p_insn)))((*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA2_PE_p_insn.stubSocket"))));
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA2_PE_p_insn.stubSocket"))).get_object(), "stubSocket");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".stub_DMA2_PE_p_insn.stubSocket"))).get_object());
    (*conf::cwr_sc_object_registry::inst().getInitiatorSocket(name() + std::string(".stub_i_Memory_Generic_MEM.stubSocket")))((*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".i_Memory_Generic.p_MEM"))));
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getInitiatorSocket(name() + std::string(".stub_i_Memory_Generic_MEM.stubSocket"))).get_object(), "stubSocket");
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".i_Memory_Generic.p_MEM"))).get_object(), "MEM");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getInitiatorSocket(name() + std::string(".stub_i_Memory_Generic_MEM.stubSocket"))).get_object());
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getTargetSocket(name() + std::string(".i_Memory_Generic.p_MEM"))).get_object());
    i_Bus.add_attribute(m_cwr_module_kind);
    (*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".i_ResetGenerator.p_RST")))(stub_i_ResetGenerator_p_RST);
    add_portname_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".i_ResetGenerator.p_RST"))).get_object(), "RST");
    add_stub_attr(*(*conf::cwr_sc_object_registry::inst().getPort(name() + std::string(".i_ResetGenerator.p_RST"))).get_object());
  }

  CwrModule_HARDWARE_HW_HW* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

SC_MODULE(CwrModule_HARDWARE_HW)
{
  
  CwrModule_HARDWARE_HW_HW HW;
  
  CwrModule_HARDWARE_HW(sc_module_name _name) :
    sc_module(_name),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    HW("HW")
  {
  }

  CwrModule_HARDWARE_HW* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

SC_MODULE(CwrModule_HARDWARE_Workload_Workload_tgg_cfg)
{
  
  
  CwrModule_HARDWARE_Workload_Workload_tgg_cfg(sc_module_name _name) :
    sc_module(_name),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true)
  {
  }

  CwrModule_HARDWARE_Workload_Workload_tgg_cfg* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

struct CwrModule_HARDWARE_Workload_Workload_Initialize : public scml_tm_generic_task
{
  
  scml_tm_task_def_function Default;
  
  CwrModule_HARDWARE_Workload_Workload_Initialize(sc_module_name _name) :
    scml_tm_generic_task(_name),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    Default("Default")
  {
  }

  CwrModule_HARDWARE_Workload_Workload_Initialize* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

struct CwrModule_HARDWARE_Workload_Workload_Cal_Str : public scml_tm_generic_task
{
  
  scml_tm_task_def_function Default;
  
  CwrModule_HARDWARE_Workload_Workload_Cal_Str(sc_module_name _name) :
    scml_tm_generic_task(_name),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    Default("Default")
  {
  }

  CwrModule_HARDWARE_Workload_Workload_Cal_Str* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

struct CwrModule_HARDWARE_Workload_Workload_Trigger : public scml_tm_generic_task
{
  
  scml_tm_task_def_function Default;
  
  CwrModule_HARDWARE_Workload_Workload_Trigger(sc_module_name _name) :
    scml_tm_generic_task(_name),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    Default("Default")
  {
  }

  CwrModule_HARDWARE_Workload_Workload_Trigger* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

struct CwrModule_HARDWARE_Workload_Workload_DMA1_Rd : public scml_tm_generic_task
{
  
  scml_tm_task_def_function Default;
  
  CwrModule_HARDWARE_Workload_Workload_DMA1_Rd(sc_module_name _name) :
    scml_tm_generic_task(_name),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    Default("Default")
  {
  }

  CwrModule_HARDWARE_Workload_Workload_DMA1_Rd* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

struct CwrModule_HARDWARE_Workload_Workload_DMA2_Wr : public scml_tm_generic_task
{
  
  scml_tm_task_def_function Default;
  
  CwrModule_HARDWARE_Workload_Workload_DMA2_Wr(sc_module_name _name) :
    scml_tm_generic_task(_name),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    Default("Default")
  {
  }

  CwrModule_HARDWARE_Workload_Workload_DMA2_Wr* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

struct CwrModule_HARDWARE_Workload_Workload_FFT_VLD : public scml_tm_generic_task
{
  
  scml_tm_task_def_function Default;
  
  CwrModule_HARDWARE_Workload_Workload_FFT_VLD(sc_module_name _name) :
    scml_tm_generic_task(_name),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    Default("Default")
  {
  }

  CwrModule_HARDWARE_Workload_Workload_FFT_VLD* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

struct CwrModule_HARDWARE_Workload_Workload : public scml_tm_task_graph
{
  scml_tm_fifo_chnl<int> C;
  scml_tm_fifo_chnl<int> C_1;
  scml_tm_fifo_chnl<int> C_2;
  scml_tm_fifo_chnl<int> C_3;
  scml_tm_fifo_chnl<int> C_4;
  scml_tm_fifo_chnl<int> C_5;
  scml_tm_fifo_chnl<int> C_6;
  scml_tm_fifo_chnl<int> C_8;
  scml_tm_fifo_chnl<int> C_7;
  scml_tm_fifo_chnl<int> C_9;
  
  CwrModule_HARDWARE_Workload_Workload_tgg_cfg tgg_cfg;
  CwrModule_HARDWARE_Workload_Workload_Initialize Initialize;
  CwrModule_HARDWARE_Workload_Workload_Cal_Str Cal_Str;
  CwrModule_HARDWARE_Workload_Workload_Trigger Trigger;
  CwrModule_HARDWARE_Workload_Workload_DMA1_Rd DMA1_Rd;
  CwrModule_HARDWARE_Workload_Workload_DMA1_Rd DMA1_Wr;
  CwrModule_HARDWARE_Workload_Workload_DMA1_Rd ADD_MUL;
  CwrModule_HARDWARE_Workload_Workload_DMA1_Rd DMA2_Rd;
  CwrModule_HARDWARE_Workload_Workload_DMA2_Wr DMA2_Wr;
  CwrModule_HARDWARE_Workload_Workload_FFT_VLD FFT_VLD;
  
  CwrModule_HARDWARE_Workload_Workload(sc_module_name _name) :
    scml_tm_task_graph(_name),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    C("C"),
    C_1("C_1"),
    C_2("C_2"),
    C_3("C_3"),
    C_4("C_4"),
    C_5("C_5"),
    C_6("C_6"),
    C_8("C_8"),
    C_7("C_7"),
    C_9("C_9"),
    tgg_cfg("tgg_cfg"),
    Initialize("Initialize"),
    Cal_Str("Cal_Str"),
    Trigger("Trigger"),
    DMA1_Rd("DMA1_Rd"),
    DMA1_Wr("DMA1_Wr"),
    ADD_MUL("ADD_MUL"),
    DMA2_Rd("DMA2_Rd"),
    DMA2_Wr("DMA2_Wr"),
    FFT_VLD("FFT_VLD")
  {
    Initialize.p_put[0](C);
    add_portname_attr(Initialize.p_put[0], "p_put[0]");
    Cal_Str.p_get[0](C);
    add_portname_attr(Cal_Str.p_get[0], "p_get[0]");
    Cal_Str.p_put[0](C_1);
    add_portname_attr(Cal_Str.p_put[0], "p_put[0]");
    Trigger.p_get[0](C_1);
    add_portname_attr(Trigger.p_get[0], "p_get[0]");
    DMA1_Rd.p_put[0](C_2);
    add_portname_attr(DMA1_Rd.p_put[0], "p_put[0]");
    DMA1_Wr.p_get[0](C_2);
    add_portname_attr(DMA1_Wr.p_get[0], "p_get[0]");
    Trigger.p_put[0](C_3);
    add_portname_attr(Trigger.p_put[0], "p_put[0]");
    DMA1_Rd.p_get[0](C_3);
    add_portname_attr(DMA1_Rd.p_get[0], "p_get[0]");
    DMA1_Wr.p_put[0](C_4);
    add_portname_attr(DMA1_Wr.p_put[0], "p_put[0]");
    ADD_MUL.p_get[0](C_4);
    add_portname_attr(ADD_MUL.p_get[0], "p_get[0]");
    ADD_MUL.p_put[0](C_5);
    add_portname_attr(ADD_MUL.p_put[0], "p_put[0]");
    DMA2_Rd.p_get[0](C_5);
    add_portname_attr(DMA2_Rd.p_get[0], "p_get[0]");
    DMA2_Rd.p_put[0](C_6);
    add_portname_attr(DMA2_Rd.p_put[0], "p_put[0]");
    DMA2_Wr.p_get[0](C_6);
    add_portname_attr(DMA2_Wr.p_get[0], "p_get[0]");
    Trigger.p_put[1](C_8);
    add_portname_attr(Trigger.p_put[1], "p_put[1]");
    Cal_Str.p_get[1](C_8);
    add_portname_attr(Cal_Str.p_get[1], "p_get[1]");
    DMA2_Wr.p_put[0](C_7);
    add_portname_attr(DMA2_Wr.p_put[0], "p_put[0]");
    FFT_VLD.p_get[0](C_7);
    add_portname_attr(FFT_VLD.p_get[0], "p_get[0]");
    DMA2_Wr.p_put[1](C_9);
    add_portname_attr(DMA2_Wr.p_put[1], "p_put[1]");
    Trigger.p_get[1](C_9);
    add_portname_attr(Trigger.p_get[1], "p_get[1]");
  }

  CwrModule_HARDWARE_Workload_Workload* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

SC_MODULE(CwrModule_HARDWARE_Workload)
{
  
  CwrModule_HARDWARE_Workload_Workload Workload;
  
  CwrModule_HARDWARE_Workload(sc_module_name _name) :
    sc_module(_name),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    Workload("Workload")
  {
  }

  CwrModule_HARDWARE_Workload* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

SC_MODULE(CwrModule_HARDWARE)
{
  
  CwrModule_HARDWARE_HW HW;
  CwrModule_HARDWARE_Workload Workload;
  
  CwrModule_HARDWARE(sc_module_name _name) :
    sc_module(_name),
    pct_stub_attribute("pct-stub", true),
    snps_tool_generated_attribute("snps_tool_generated", true),
    HW("HW"),
    Workload("Workload")
  {
  }

  CwrModule_HARDWARE* operator->() { return this; }

  virtual void add_portname_attr(sc_object& obj, const std::string& value) {
    static std::string PCT_PORT_NAME("pct-port-name");
    pct_port_name_attributes.emplace_back(PCT_PORT_NAME, value);
    obj.add_attribute(pct_port_name_attributes.back());
  }
  virtual void add_stub_attr(sc_object& obj) {
    obj.add_attribute(pct_stub_attribute);
  }
  std::deque< sc_core::sc_attribute<std::string> > pct_port_name_attributes;
  sc_core::sc_attribute<bool> pct_stub_attribute;
  sc_core::sc_attribute<bool> snps_tool_generated_attribute;
};

//-------------------------------

#endif // HARDWARE_H
