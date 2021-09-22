/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** NetX Component                                                        */
/**                                                                       */
/**   User Specific                                                       */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/


/**************************************************************************/
/*                                                                        */
/*  PORT SPECIFIC C INFORMATION                            RELEASE        */
/*                                                                        */
/*    nx_user.h                                           PORTABLE C      */
/*                                                           6.1.8        */
/*                                                                        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This file contains user defines for configuring NetX in specific    */
/*    ways. This file will have an effect only if the application and     */
/*    NetX library are built with NX_INCLUDE_USER_DEFINE_FILE defined.    */
/*    Note that all the defines in this file may also be made on the      */
/*    command line when building NetX library and application objects.    */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  05-19-2020     Yuxin Zhou               Initial Version 6.0           */
/*  09-30-2020     Yuxin Zhou               Modified comment(s),          */
/*                                            resulting in version 6.1    */
/*  08-02-2021     Yuxin Zhou               Modified comment(s), and      */
/*                                            supported TCP/IP offload,   */
/*                                            resulting in version 6.1.8  */
/*                                                                        */
/**************************************************************************/

#ifndef NX_USER_H
#define NX_USER_H

/* Define for the specific project. 
   All the defines for specific project should be added under this line. */

#define NX_ENABLE_TCPIP_OFFLOAD
#define NX_ENABLE_INTERFACE_CAPABILITY
#define SAMPLE_DHCP_DISABLE
#define SAMPLE_NETWORK_DRIVER nx_driver_esp_offload
#define SAMPLE_NETWORK_CONFIGURE sample_network_configure

/* NetX */
#define NX_DNS_CLIENT_USER_CREATE_PACKET_POOL
#define NX_DNS_CLIENT_CLEAR_QUEUE
#define NXD_MQTT_CLOUD_ENABLE
#define NX_ENABLE_EXTENDED_NOTIFY_SUPPORT

/* Secure */
#define NX_SECURE_ENABLE
#define NX_SECURE_TLS_DISABLE_TLS_1_1

/* MQTT */
#define NXD_MQTT_PING_TIMEOUT_DELAY 500
#define NXD_MQTT_SOCKET_TIMEOUT 0

/* SNTP */
#define NX_SNTP_CLIENT_MIN_SERVER_STRATUM 3
#define NX_SNTP_CLIENT_MESSAGE_CHECK_DISABLE
     
/* Azure IoT Security Module */
#define NX_ENABLE_IP_PACKET_FILTER

#define NX_DISABLE_IPV6

#define NX_PACKET_ALIGNMENT             32

#define NX_DISABLE_ICMPV4_RX_CHECKSUM
#define NX_DISABLE_ICMPV4_TX_CHECKSUM  
#define NX_DISABLE_IP_RX_CHECKSUM
#define NX_DISABLE_IP_TX_CHECKSUM
#define NX_DISABLE_TCP_RX_CHECKSUM
#define NX_DISABLE_TCP_TX_CHECKSUM
#define NX_DISABLE_UDP_RX_CHECKSUM
#define NX_DISABLE_UDP_TX_CHECKSUM

#endif
