#!/usr/bin/env bash

#
# Copyright (C) 2015-2016 Intel Corporation
# Copyright (C) 2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

set -x 
[ $# -eq 4 ] || {
    echo "SYNTAX: $0 <kernel_image_with_path> <tmp directory> <rootfs directory> <image_prefix>"
    exit 1
}

TARGET_IMG_DIR="`dirname $4`"

BZIMAGE="$1"
WORKDIR="$2"
KERNEL_SIZE="9437184"
ROOTFS_GUID="6FAEF15A-C0F4-4AD2-8619-77649F22DB8D"
UIMAGE_NAME="appcpuImage"
UIMAGE_IMAGE="${WORKDIR}/${UIMAGE_NAME}"
FINAL_UIMAGE_IMAGE="$4-${UIMAGE_NAME}"
ROOTFS_IMAGE_NAME="appcpuRootfs.img"
FINAL_ROOTFS_IMAGE="$4-${ROOTFS_IMAGE_NAME}"
UGW_ROOTFS="rootfs.img"
UGW_KERNEL="uImage"
UGW_FULLIMAGE="fullimage.img"
TARGETFS_NAME="$3"
TARGETFS="${WORKDIR}/${TARGETFS_NAME}"
EXTRA_BOOT_LINE_PARAMETERS="do_overlay vmalloc=382M memmap=4M\$0x00C00000"
UIMAGE_VERSION="2"
FLASH_BLOCK_SIZE="64k"

## ATOM images
ROOTFS_IMAGE="${WORKDIR}/${ROOTFS_IMAGE_NAME}"
KERNEL_IMAGE="$4-appcpuKernelfs.img"
FINAL_UGW_ROOTFS_IMAGE="${TARGET_IMG_DIR}/atom_${UGW_ROOTFS}"
FINAL_UGW_KERNEL_IMAGE="${TARGET_IMG_DIR}/atom_${UGW_KERNEL}"
FINAL_UGW_FULL_IMAGE="${TARGET_IMG_DIR}/atom_${UGW_FULLIMAGE}"

## ARM images
ARM_ROOTFS_IMAGE="${TARGET_IMG_DIR}/arm_images/rootfs.squashfs"
ARM_KERNEL_IMAGE="${TARGET_IMG_DIR}/arm_images/zImage"
FINAL_ARM_ROOTFS_IMAGE="${TARGET_IMG_DIR}/arm_${UGW_ROOTFS}"
FINAL_ARM_KERNEL_IMAGE="${TARGET_IMG_DIR}/arm_${UGW_KERNEL}"
FINAL_ARM_FULL_IMAGE="${TARGET_IMG_DIR}/arm_${UGW_FULLIMAGE}"

## BIOS image
BIOS_IMAGE="${TARGET_IMG_DIR}/bios_images/BIOS_Update.bin"
FINAL_BIOS_IMAGE="${TARGET_IMG_DIR}/bios.img"

## Combile Image
FINAL_CONBINE_IMAGE="${TARGET_IMG_DIR}/${UGW_FULLIMAGE}"

## Total Image
FINAL_TOTAL_IMAGE="${TARGET_IMG_DIR}/totalimage.img"

## GWFS image
GWFS_IMAGE="${WORKDIR}/GWFS.bin"
FINAL_GWFS_IMAGE="${TARGET_IMG_DIR}/GWFS.uimg"

## removed files for the unified image
REMOVED_FILE_LIST="\
	boot \
	usr/grub \
	usr/lib/grub \
	usr/lib/xtables \
	usr/lib/X11 \
	usr/lib/vfs \
	usr/lib/tc \
	usr/lib/pdb \
	bin/qemu \
	bin/qemu-io \
	bin/qemu-nbd \
	bin/qemu-img \
	usr/bin/libvirt_samples \
	usr/bin/mtp-* \
	usr/bin/grub-* \
	usr/sbin/grub-* \
	usr/sbin/iDTSRmtSrv \
	usr/sbin/libvirtd \
	usr/sbin/ubiattach \
	usr/sbin/ubicrc32 \
	usr/sbin/ubidetach \
	usr/sbin/ubiformat \
	usr/sbin/ubimkvol \
	usr/sbin/ubinfo \
	usr/sbin/ubinize \
	usr/sbin/ubirename \
	usr/sbin/ubirmvol \
	usr/sbin/ubirsvol \
	usr/sbin/ubiupdatevol \
	usr/sbin/mkfs.ubifs \
	usr/lib/gconv \
	usr/bin/gdb \
	usr/bin/minicom \
	usr/bin/virsh \
	usr/bin/virt-pki-validate \
	usr/bin/virt-xml-validate \
	usr/bin/localedef \
	usr/bin/locale \
	sbin/ldconfig \
	sbin/sln \
	usr/dtsbin \
	bin/anim_app  \
	bin/audio_player  \
	bin/audio_setup_outputs  \
	bin/cl_app  \
	bin/dvr_app  \
	bin/gdl_samples  \
	bin/renderer_driven_clock_player  \
	bin/tsout_streamer  \
	bin/video_buffer  \
	lib/libgdl.so  \
	lib/libgdl.so.1  \
	lib/libgdl.so.1.0.0  \
	lib/libismd_audio.so  \
	lib/libismd_audio.so.0  \
	lib/libismd_audio.so.0.0.0  \
	lib/libismd_avcap_shim.so  \
	lib/libismd_avcap_shim.so.0  \
	lib/libismd_avcap_shim.so.0.0.0  \
	lib/libismd_bufmon.so  \
	lib/libismd_bufmon.so.0  \
	lib/libismd_bufmon.so.0.0.0  \
	lib/libismd_mux.so  \
	lib/libismd_mux.so.0  \
	lib/libismd_mux.so.0.0.0  \
	lib/libismd_remux.so  \
	lib/libismd_remux.so.0  \
	lib/libismd_remux.so.0.0.0  \
	lib/libismd_tsout.so  \
	lib/libismd_tsout.so.0  \
	lib/libismd_tsout.so.0.0.0  \
	lib/libismd_viddec.so  \
	lib/libismd_viddec.so.0  \
	lib/libismd_viddec.so.0.0.0  \
	lib/libismd_videnc.so  \
	lib/libismd_videnc.so.0  \
	lib/libismd_videnc.so.0.0.0  \
	lib/libismd_vidpproc.so  \
	lib/libismd_vidpproc.so.0  \
	lib/libismd_vidpproc.so.0.0.0  \
	lib/libismd_vidrend.so  \
	lib/libismd_vidrend.so.0  \
	lib/libismd_vidrend.so.0.0.0  \
	lib/libismd_vidsink_direct.so  \
	lib/libismd_vidsink_direct.so.1  \
	lib/libismd_vidsink_direct.so.1.0.0  \
	lib/libpipeline_library.so  \
	lib/libpipeline_library.so.0  \
	lib/libpipeline_library.so.0.0.0  \
	lib/libpsi_handler.so  \
	lib/libpsi_handler.so.0  \
	lib/libpsi_handler.so.0.0.0  \
	lib/libpsi_parser.so  \
	lib/libpsi_parser.so.0  \
	lib/libpsi_parser.so.0.0.0  \
	lib/modules/3.12.17/extra/ismdbufmon.ko  \
	lib/modules/ismdbufmon.ko \
	usr/bin/bison \
	usr/bin/flex \
	usr/bin/m4 \
	usr/sbin/dhcp6r \
	usr/sbin/dhcp6s \
	bin/compile_et \
	bin/mk_cmds \
	lib/libcom_err.so \
	lib/libcom_err.so.2 \
	lib/libcom_err.so.2.1 \
	lib/libe2p.so \
	lib/libe2p.so.2 \
	lib/libe2p.so.2.3 \
	lib/libext2fs.so \
	lib/libext2fs.so.2 \
	lib/libext2fs.so.2.4 \
	lib/libss.so \
	lib/libss.so.2 \
	lib/libss.so.2.0 \
	sbin/badblocks \
	sbin/debugfs \
	sbin/dumpe2fs \
	sbin/e2freefrag \
	sbin/e2image \
	sbin/e2label \
	sbin/e2undo \
	sbin/e4defrag \
	sbin/filefrag \
	sbin/logsave \
	sbin/mklost+found \
	sbin/resize2fs \
	sbin/vigr \
	sbin/vipw \
	usr/bin/chage \
	usr/bin/chattr \
	usr/bin/chfn \
	usr/bin/chsh \
	usr/bin/compile_et \
	usr/bin/expiry \
	usr/bin/faillog \
	usr/bin/lastlog \
	usr/bin/lsattr \
	usr/bin/mk_cmds \
	usr/bin/sg \
	usr/lib/charset/CP437.so \
	usr/lib/charset/CP850.so \
	usr/lib/e2initrd_helper \
	usr/sbin/chgpasswd \
	usr/sbin/chpasswd \
	usr/sbin/groupadd \
	usr/sbin/groupdel \
	usr/sbin/groupmems \
	usr/sbin/groupmod \
	usr/sbin/grpck \
	usr/sbin/grpconv \
	usr/sbin/grpunconv \
	usr/sbin/newusers \
	usr/sbin/pwck \
	usr/sbin/pwconv \
	usr/sbin/pwunconv \
	usr/sbin/useradd \
	usr/sbin/userdel \
	usr/sbin/usermod \
	bin/update-alternatives \
	usr/bin/update-alternatives \
	usr/lib/opkg \
	usr/lib/libxml2.so.2 \
	usr/lib/libxml2.so.2.9.1 \
"
## shared part of strip the rootfs
strip_rootfs_common(){
	touch ${TARGETFS}/etc/uimage
##	for i in ${REMOVED_FILE_LIST} ; do rm -rf ${TARGETFS}/$i ; done
	find ${TARGETFS} -name lib*.a | xargs rm -f
	find ${TARGETFS} -name lib*.la | xargs rm -f
	find ${TARGETFS}/bin -type f -exec chmod 755 {} \;
	find ${TARGETFS}/sbin -type f -exec chmod 755 {} \;
	find ${TARGETFS}/usr/bin -type f -exec chmod 755 {} \;
	find ${TARGETFS}/usr/sbin -type f -exec chmod 755 {} \;
	mkdir -p "${TARGETFS}/lib/modules/3.12.17/extra"
	find ${TARGETFS}/lib/modules/3.12.17/extra -iname "*ko" -exec strip --strip-debug {} \;

}

build_efi_partition_image() {
	echo "Building EFI partition image"

	echo Temporary process -- package EFI partition image instead of just
	echo the kernel image

	dd if=/dev/zero of="${KERNEL_IMAGE}" bs=${KERNEL_SIZE} count=1
	mkfs.vfat "${KERNEL_IMAGE}"

	echo Create directory structure
	mmd -i "${KERNEL_IMAGE}" "EFI"
	mmd -i "${KERNEL_IMAGE}" "EFI/BOOT"

	echo Add kernel image
	mcopy -i "${KERNEL_IMAGE}" "${BZIMAGE}" "::EFI/BOOT/bzImage.efi"

	echo Add startup script
	ARM_BOOT='mm 0x400d0003 3'
	ATOM_BOOT='fs%kernel_aid%:\EFI\BOOT\\bzImage console=ttyS0,115200n8 loglevel=8 root=%rootfs% rootwait'
	ATOM_BOOT="${ATOM_BOOT} ${EXTRA_BOOT_LINE_PARAMETERS}"

	EFI_SCRIPT_FILE=`mktemp`

	echo 'npcpu start'                            >> "${EFI_SCRIPT_FILE}"
	echo 'if not %lasterror% == 0 then'           >> "${EFI_SCRIPT_FILE}"
	echo "${ARM_BOOT}"                            >> "${EFI_SCRIPT_FILE}"
	echo 'endif'                                  >> "${EFI_SCRIPT_FILE}"
	echo 'bootkernel -c %kernel_cmd_line% '  "${EXTRA_BOOT_LINE_PARAMETERS}" >> "${EFI_SCRIPT_FILE}"
	echo 'if not %lasterror% == 0 then'           >> "${EFI_SCRIPT_FILE}"
	# Add Atom boot command
	echo "${ATOM_BOOT}"                           >> "${EFI_SCRIPT_FILE}"
	echo 'endif'                                  >> "${EFI_SCRIPT_FILE}"

	# Add startup.nsh to the EFI partition image
	mcopy -i "${KERNEL_IMAGE}" "${EFI_SCRIPT_FILE}" "::EFI/BOOT/startup.nsh"
}

## strip the rootfs
strip_rootfs(){
	# Fix etc files.
	install -d  ${TARGETFS}/nvram/etc
	strip_rootfs_etc passwd
	strip_rootfs_etc group
	strip_rootfs_etc fstab
	strip_rootfs_etc shadow

	strip_rootfs_common
}

# Replace the specified etc configuration file with a symbolic link to one
# in the nvram partition. This creates a file whose contents duplicate the
# original file as '/etc/${FILE}.orig' and creates a symbolic link from
# '/etc/${FILE}' to '/nvram/etc/${FILE}'. This is to make up for the fact
# that '/etc/' is read-only on our system.
strip_rootfs_etc() {
	local file=${1}
	touch ${TARGETFS}/etc/${file}
	install -c  ${TARGETFS}/etc/${file} ${TARGETFS}/etc/${file}.orig
	install -c  ${TARGETFS}/etc/${file} ${TARGETFS}/nvram/etc/${file}
	chmod 644 ${TARGETFS}/etc/${file}.orig
	rm -f ${TARGETFS}/etc/${file}
	ln -sf /nvram/etc/${file} ${TARGETFS}/etc/${file}
}

build_gwfs_partition_image()
{
	echo "Building GWFS partition image"

	rm -f ${GWFS_IMAGE}

	## Generate 1 MB image
	dd if=/dev/zero of="${GWFS_IMAGE}" bs=1024 count=1024
}

gen_uimage()
{
	local files="$1"
	local name="$2"
	local target="$3"

	mkimage_grx750 --version ${UIMAGE_VERSION} --file "${files}" --name "${name}" --image "${target}"
	echo mkimage_grx750 --version ${UIMAGE_VERSION} --file "${files}" --name "${name}" --image "${target}" >> /tmp/ng.log
	chmod 644 ${target}
}

do_compile(){
	build_efi_partition_image
	build_gwfs_partition_image
	strip_rootfs
	mksquashfs4 ${TARGETFS} ${ROOTFS_IMAGE} -b ${FLASH_BLOCK_SIZE} -comp xz -noappend -root-owned

	## ATOM Images
	gen_uimage "${KERNEL_IMAGE},appcpu_kernel" "ATOM_${UGW_KERNEL}" "${FINAL_UGW_KERNEL_IMAGE}"
	gen_uimage "${ROOTFS_IMAGE},appcpu_rootfs" "ATOM_${UGW_ROOTFS}" "${FINAL_UGW_ROOTFS_IMAGE}"
	gen_uimage "${KERNEL_IMAGE},appcpu_kernel:${ROOTFS_IMAGE},appcpu_rootfs" "ATOM_${UGW_FULLIMAGE}" "${FINAL_UGW_FULL_IMAGE}"

	## ARM Images
	gen_uimage "${ARM_KERNEL_IMAGE},npcpu_kernel" "ARM_${UGW_KERNEL}" "${FINAL_ARM_KERNEL_IMAGE}"
	gen_uimage "${ARM_ROOTFS_IMAGE},npcpu_rootfs" "ARM_${UGW_ROOTFS}" "${FINAL_ARM_ROOTFS_IMAGE}"
	gen_uimage "${ARM_KERNEL_IMAGE},npcpu_kernel:${ARM_ROOTFS_IMAGE},npcpu_rootfs" "ARM_${UGW_FULLIMAGE}" "${FINAL_ARM_FULL_IMAGE}"

	## BIOS Image
	gen_uimage "${BIOS_IMAGE},uefi_bundle" "BIOS_Update.bin" "${FINAL_BIOS_IMAGE}"

	## Combine Image (Fullimage)
	gen_uimage "${KERNEL_IMAGE},appcpu_kernel:${ROOTFS_IMAGE},appcpu_rootfs:${ARM_KERNEL_IMAGE},npcpu_kernel:${ARM_ROOTFS_IMAGE},npcpu_rootfs" "${UGW_FULLIMAGE}" "${FINAL_CONBINE_IMAGE}"

	## Total Image
	gen_uimage "${KERNEL_IMAGE},appcpu_kernel:${ROOTFS_IMAGE},appcpu_rootfs:${ARM_KERNEL_IMAGE},npcpu_kernel:${ARM_ROOTFS_IMAGE},npcpu_rootfs:${BIOS_IMAGE},uefi_bundle" "Puma7UGW_TotalImage" "${FINAL_TOTAL_IMAGE}"

	## GWFS Image
	gen_uimage "${GWFS_IMAGE},gwfs" "GWFSImage" "${FINAL_GWFS_IMAGE}"
}

do_clear(){
	rm -rf ${TARGETFS}
	rm -f ${UIMAGE_IMAGE} ${ROOTFS_IMAGE}
}

do_compile
do_clear
