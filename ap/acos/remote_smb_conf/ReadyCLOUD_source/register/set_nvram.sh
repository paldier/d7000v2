#-------------------------------------------------------------------------
#  Copyright 2014, Foxconn
#  Author: Kathy Lai
#-------------------------------------------------------------------------

#!/bin/sh
nvram set leafp2p_run=0
nvram set leafp2p_services=1
nvram set leafp2p_service_0=RouterRemote,0,1,1,0,1,6:135,6:136,6:137,6:138,6:139,6:445,6:548,17:135,17:136,17:137,17:138,17:139,17:445,17:548
nvram set leafp2p_debug=5
nvram set leafp2p_connection_method_type=2
nvram set leafp2p_peer_route_type=1

nvram save

#/tmp/mnt/usb0/part1/broken/leafp2p &
