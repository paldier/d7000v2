#***************************************************************************
#***
#***    Copyright 2014  Hon Hai Precision Ind. Co. Ltd.
#***    All Rights Reserved.
#***    No portions of this material shall be reproduced in any form without the
#***    written permission of Hon Hai Precision Ind. Co. Ltd.
#***
#***    All information contained in this document is Hon Hai Precision Ind.  
#***    Co. Ltd. company private, proprietary, and trade secret property and 
#***    are protected by international intellectual property laws and treaties.
#***
#****************************************************************************
#*** xAgent cloud
#*** Modify Reason       Author      Date          Search Flag(Option)
#*** ----------------------------------------------------------------------------
#*** File Creation       Kathy Lai       03/12/2014
#*****************************************************************************


include ../config.mk
include ../config.in

#SUBDIRS := xagent_source
SUBDIRS := xagent_D7000v2

all:
	for i in ${SUBDIRS}; do \
		(cd $$i; make) || exit 1; \
	done
install:
	for i in ${SUBDIRS}; do \
		(cd $$i; make install) || exit 1; \
	done
	
clean:
	for i in ${SUBDIRS}; do \
		(cd $$i; make clean); \
	done

.PHONY: $(SUBDIRS)
