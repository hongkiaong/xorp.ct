// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2003 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

// $XORP: xorp/fea/xrl_target.hh,v 1.9 2003/05/19 06:50:29 pavlin Exp $

#ifndef __FEA_XRL_TARGET_HH__
#define __FEA_XRL_TARGET_HH__

#include "xrl/targets/fea_base.hh"

#include "fticonfig.hh"

#include "xrl_fti.hh"
#include "xrl_ifmanager.hh"
#include "xrl_ifupdate.hh"
#include "xrl_rawsock4.hh"

class XrlFeaTarget : public XrlFeaTargetBase {
public:
    XrlFeaTarget(EventLoop&			e,
		 XrlRouter&			rtr,
		 FtiConfig& 			ftic,
		 InterfaceManager& 		ifmgr,
		 XrlIfConfigUpdateReporter&	ifupd,
		 XrlRawSocket4Manager*		xrsm = 0);

    XrlCmdError common_0_1_get_target_name(
	// Output values,
	string&	name);

    XrlCmdError common_0_1_get_version(
	// Output values,
	string&	version);

    /**
     *  Get status from Xrl Target
     */
    XrlCmdError common_0_1_get_status(
	// Output values,
        uint32_t& status,
	string&	reason);

    //
    // FEA network interface management interface
    //

    XrlCmdError ifmgr_0_1_get_all_interface_names(
	// Output values,
	XrlAtomList&	ifnames);

    XrlCmdError ifmgr_0_1_get_configured_interface_names(
	// Output values,
	XrlAtomList&	ifnames);

    XrlCmdError ifmgr_0_1_get_all_vif_names(
	const string&		ifname,
	// Output values,
	XrlAtomList&		ifnames);

    XrlCmdError ifmgr_0_1_get_configured_vif_names(
	const string&	ifname,
	// Output values,
	XrlAtomList&		ifnames);

    XrlCmdError ifmgr_0_1_get_all_vif_flags(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	// Output values, 
	bool&	enabled, 
	bool&	broadcast, 
	bool&	loopback, 
	bool&	point_to_point, 
	bool&	multicast);

    XrlCmdError ifmgr_0_1_get_configured_vif_flags(
	// Input values, 
	const string&	ifname, 
	const string&	vif, 
	// Output values, 
	bool&	enabled, 
	bool&	broadcast, 
	bool&	loopback, 
	bool&	point_to_point, 
	bool&	multicast);

    XrlCmdError ifmgr_0_1_start_transaction(
	// Output values,
	uint32_t&	tid);

    XrlCmdError ifmgr_0_1_commit_transaction(
	// Input values,
	const uint32_t&	tid);

    XrlCmdError ifmgr_0_1_abort_transaction(
	// Input values,
	const uint32_t&	tid);

    XrlCmdError ifmgr_0_1_create_interface(
	// Input values,
	const uint32_t& tid,
	const string&	ifname);

    XrlCmdError ifmgr_0_1_delete_interface(
	// Input values,
	const uint32_t& tid,
	const string&	ifname);

    XrlCmdError ifmgr_0_1_set_interface_enabled(
	// Input values,
	const uint32_t& tid,
	const string&	ifname,
	const bool&	enabled);

    XrlCmdError ifmgr_0_1_get_all_interface_enabled(
	// Input values,
	const string&	ifname,
	// Outputput values,
	bool&		enabled);

    XrlCmdError ifmgr_0_1_get_configured_interface_enabled(
	// Input values,
	const string&	ifname,
	// Outputput values,
	bool&		enabled);

    XrlCmdError ifmgr_0_1_set_mac(
	// Input values,
	const uint32_t& tid,
	const string&	ifname,
	const Mac&	mac);

    XrlCmdError ifmgr_0_1_get_all_mac(
	// Input values,
	const string&	ifname,
	// Output values,
	Mac&	mac);

    XrlCmdError ifmgr_0_1_get_configured_mac(
	// Input values,
	const string&	ifname,
	// Output values,
	Mac&	mac);

    XrlCmdError ifmgr_0_1_set_mtu(
	// Input values,
	const uint32_t& tid,
	const string&	ifname,
	const uint32_t&	mtu);

    XrlCmdError ifmgr_0_1_get_all_mtu(
	// Input values,
	const string&	ifname,
	// Output values,
	uint32_t&	mtu);

    XrlCmdError ifmgr_0_1_get_configured_mtu(
	// Input values,
	const string&	ifname,
	// Output values,
	uint32_t&	mtu);

    XrlCmdError ifmgr_0_1_get_all_address_flags4(
	// Input values,
	const string& ifname,
	const string& vifname,
	const IPv4&   address,
	// Output values,
	bool& up,
	bool& broadcast,
	bool& loopback,
	bool& point_to_point,
	bool& multicast);

    XrlCmdError ifmgr_0_1_get_all_address_flags6(
	// Input values,
	const string& ifname,
	const string& vifname,
	const IPv6&   address,
	// Output values,
	bool& up,
	bool& loopback,
	bool& point_to_point,
	bool& multicast);

    XrlCmdError ifmgr_0_1_get_configured_address_flags4(
	// Input values,
	const string& ifname,
	const string& vifname,
	const IPv4&   address,
	// Output values,
	bool& up,
	bool& broadcast,
	bool& loopback,
	bool& point_to_point,
	bool& multicast);

    XrlCmdError ifmgr_0_1_get_configured_address_flags6(
	// Input values,
	const string& ifname,
	const string& vifname,
	const IPv6&   address,
	// Output values,
	bool& up,
	bool& loopback,
	bool& point_to_point,
	bool& multicast);

    XrlCmdError ifmgr_0_1_create_vif(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif);

    XrlCmdError ifmgr_0_1_delete_vif(
	// Input values,
	const uint32_t& tid,
	const string& 	ifname,
	const string&	vif);

    XrlCmdError ifmgr_0_1_set_vif_enabled(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const bool&	enabled);

    XrlCmdError ifmgr_0_1_get_all_vif_enabled(
	// Input values,
	const string&	ifname,
	const string&	vif,
	// Output values,
	bool&		enabled);

    XrlCmdError ifmgr_0_1_get_configured_vif_enabled(
	// Input values,
	const string&	ifname,
	const string&	vif,
	// Output values,
	bool&		enabled);

    XrlCmdError ifmgr_0_1_get_all_vif_addresses4(
	// Input values,
	const string&	ifname,
	const string&	vif,
	// Output values,
	XrlAtomList&	addresses);

    XrlCmdError ifmgr_0_1_get_configured_vif_addresses4(
	// Input values,
	const string&	ifname,
	const string&	vif,
	// Output values,
	XrlAtomList&	addresses);

    XrlCmdError ifmgr_0_1_create_address4(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address);

    XrlCmdError ifmgr_0_1_delete_address4(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address);

    XrlCmdError ifmgr_0_1_set_address4(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address);

    XrlCmdError ifmgr_0_1_set_address_enabled4(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const bool&	en);

    XrlCmdError ifmgr_0_1_get_all_address_enabled4(
	// Input values,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	bool&		enabled);

    XrlCmdError ifmgr_0_1_get_configured_address_enabled4(
	// Input values,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	bool&		enabled);
    
    XrlCmdError ifmgr_0_1_set_prefix4(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const uint32_t&	prefix);

    XrlCmdError ifmgr_0_1_get_all_prefix4(
	// Input values,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	// Output values,
	uint32_t&	prefix);

    XrlCmdError ifmgr_0_1_get_configured_prefix4(
	// Input values,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	// Output values,
	uint32_t&	prefix);

    XrlCmdError ifmgr_0_1_set_broadcast4(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const IPv4&	broadcast);

    XrlCmdError ifmgr_0_1_get_all_broadcast4(
	// Input values,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	// Output values,
	IPv4&		broadcast);

    XrlCmdError ifmgr_0_1_get_configured_broadcast4(
	// Input values,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	// Output values,
	IPv4&		broadcast);

    XrlCmdError ifmgr_0_1_set_endpoint4(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const IPv4&	endpoint);

    XrlCmdError ifmgr_0_1_get_all_endpoint4(
	// Input values,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	// Output values,
	IPv4&	endpoint);

    XrlCmdError ifmgr_0_1_get_configured_endpoint4(
	// Input values,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	// Output values,
	IPv4&	endpoint);

    XrlCmdError ifmgr_0_1_get_all_vif_addresses6(
	// Input values,
	const string&	ifname,
	const string&	vif,
	// Output values,
	XrlAtomList&	addresses);

    XrlCmdError ifmgr_0_1_get_configured_vif_addresses6(
	// Input values,
	const string&	ifname,
	const string&	vif,
	// Output values,
	XrlAtomList&	addresses);

    XrlCmdError ifmgr_0_1_create_address6(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address);

    XrlCmdError ifmgr_0_1_delete_address6(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address);

    XrlCmdError ifmgr_0_1_set_address_enabled6(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const bool&	enabled);

    XrlCmdError ifmgr_0_1_get_all_address_enabled6(
	// Input values,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	bool&		enabled);

    XrlCmdError ifmgr_0_1_get_configured_address_enabled6(
	// Input values,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	bool&		enabled);
    
    XrlCmdError ifmgr_0_1_set_prefix6(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const uint32_t&	prefix);

    XrlCmdError ifmgr_0_1_get_all_prefix6(
	// Input values,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	// Output values,
	uint32_t&	prefix);

    XrlCmdError ifmgr_0_1_get_configured_prefix6(
	// Input values,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	// Output values,
	uint32_t&	prefix);

    XrlCmdError ifmgr_0_1_set_endpoint6(
	// Input values,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const IPv6&	endpoint);

    XrlCmdError ifmgr_0_1_get_all_endpoint6(
	// Input values,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	// Output values,
	IPv6&		endpoint);

    XrlCmdError ifmgr_0_1_get_configured_endpoint6(
	// Input values,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	// Output values,
	IPv6&		endpoint);

    XrlCmdError ifmgr_0_1_register_client(
	// Input values,
	const string&	spyname);

    XrlCmdError ifmgr_0_1_unregister_client(
	// Input values,
	const string&	spyname);

    //
    // Forwarding Table Interface
    //

    XrlCmdError fti_0_2_start_transaction(
	// Output values,
	uint32_t&	tid);

    XrlCmdError fti_0_2_commit_transaction(
	// Input values,
	const uint32_t&	tid);

    XrlCmdError fti_0_2_abort_transaction(
	// Input values,
	const uint32_t&	tid);

    XrlCmdError fti_0_2_add_entry4(
	// Input values,
	const uint32_t&	tid,
	const IPv4Net&	dst,
	const IPv4&	gateway,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const uint32_t& admin_distance,
	const string&	protocol_origin);

    XrlCmdError fti_0_2_add_entry6(
	// Input values,
	const uint32_t&	tid,
	const IPv6Net&	dst,
	const IPv6&	gateway,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const uint32_t& admin_distance,
	const string&	protocol_origin);

    XrlCmdError fti_0_2_delete_entry4(
	// Input values,
	const uint32_t&	tid,
	const IPv4Net&	dst);

    XrlCmdError fti_0_2_delete_entry6(
	// Input values,
	const uint32_t&	tid,
	const IPv6Net&	dst);

    XrlCmdError fti_0_2_delete_all_entries(
	// Input values,
	const uint32_t&	tid);

    XrlCmdError fti_0_2_delete_all_entries4(
	// Input values,
	const uint32_t&	tid);

    XrlCmdError fti_0_2_delete_all_entries6(
	// Input values,
	const uint32_t&	tid);

    XrlCmdError fti_0_2_lookup_route4(
	// Input values,
	const IPv4&	host,
	// Output values,
	IPv4Net&	netmask,
	IPv4&		gateway,
	string&		ifname,
	string&		vifname,
	uint32_t&	metric,
	uint32_t&	admin_distance,
	string&		protocol_origin);

    XrlCmdError fti_0_2_lookup_route6(
	// Input values,
	const IPv6&	host,
	// Output values,
	IPv6Net&	netmask,
	IPv6&		gateway,
	string&		ifname,
	string&		vifname,
	uint32_t&	metric,
	uint32_t&	admin_distance,
	string&		protocol_origin);

    XrlCmdError fti_0_2_lookup_entry4(
	// Input values,
	const IPv4Net&	dst,
	// Output values,
	IPv4&		gateway,
	string&		ifname,
	string&		vifname,
	uint32_t&	metric,
	uint32_t&	admin_distance,
	string&		protocol_origin);

    XrlCmdError fti_0_2_lookup_entry6(
	// Input values,
	const IPv6Net&	dst,
	// Output values,
	IPv6&		gateway,
	string&		ifname,
	string&		vifname,
	uint32_t&	metric,
	uint32_t&	admin_distance,
	string&		protocol_origin);

    //
    // Raw Socket Server Interface
    //

    XrlCmdError raw_packet_0_1_send4(
	// Input values,
	const IPv4&		src_address,
	const IPv4&		dst_address,
	const string&		vifname,
	const uint32_t&		proto,
	const uint32_t&		ttl,
	const uint32_t&		tos,
	const vector<uint8_t>&	options,
	const vector<uint8_t>&	payload);

    XrlCmdError raw_packet_0_1_send_raw4(
	// Input values,
	const string&		vifname,
	const vector<uint8_t>&	packet);

    XrlCmdError raw_packet_0_1_register_vif_receiver(
	// Input values,
	const string&	router_name,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	proto);

    XrlCmdError raw_packet_0_1_unregister_vif_receiver(
	// Input values,
	const string&	router_name,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	proto);

private:
    XrlFtiTransactionManager	_xftm;
    XrlInterfaceManager 	_xifmgr;
    XrlIfConfigUpdateReporter&	_xifcur;
    XrlRawSocket4Manager*	_xrsm;
};

#endif //  __FEA_XRL_TARGET_HH__
