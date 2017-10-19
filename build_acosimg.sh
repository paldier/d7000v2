#!/bin/sh
#Shell script location
BASEDIR="$( cd "$( dirname "$0" )" && pwd )"
#echo "Shell script location: ${BASEDIR}"

FW_NAME="D7000v2"

TARGET=${BASEDIR}"/bin/lantiq/grx350_1600_opensrc_71_sample/"

###########################################
### Create .chk files for Web UI upgrade ##
echo ""
echo "###########################################"
echo "Create .chk files for Web UI upgrade "
echo "output chk image at" ${TARGET}${FW_NAME}"_`date +%m%d%H%M`.chk"
cp packet4 ${TARGET} && \
cp ${BASEDIR}/project/product/INTEL/compatible_"${FW_NAME}".txt ${TARGET} && \
cd ${TARGET} && touch rootfs && chmod 755 packet4 && \
./packet4 -k fullimage.img -f rootfs -b compatible_"${FW_NAME}".txt -i ${BASEDIR}/project/acos/include/ambitCfg.h -ok kernel_image -or rootfs_image -oall kernel_rootfs_image && \
rm rootfs packet4 compatible_"${FW_NAME}".txt && \
cp kernel_rootfs_image.chk "${FW_NAME}"_`date +%m%d%H%M`.chk
cd ${BASEDIR}
