/* 
  GPL LICENSE SUMMARY

  Copyright(c) 2013-2013 Intel Corporation.

  This program is free software; you can redistribute it and/or modify 
  it under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but 
  WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
  General Public License for more details.

  You should have received a copy of the GNU General Public License 
  along with this program; if not, write to the Free Software 
  Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
  The full GNU General Public License is included in this distribution 
  in the file called LICENSE.GPL.

  Contact Information:
    Intel Corporation
    2200 Mission College Blvd.
    Santa Clara, CA  97052
*/

#define _CARNOMAIN_C_

/*! \file carnomain.c
    \brief Glue the arno script to the C translation
*/

/**************************************************************************/
/*      INCLUDES:                                                         */
/**************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "carnoutils.h"

/**************************************************************************/
/*      EXTERNS Declaration:                                              */
/**************************************************************************/

/**************************************************************************/
/*      DEFINES:                                                          */
/**************************************************************************/

#define AIF_FUNCS \
    AIF_FUNC(config_check) \
    AIF_FUNC(init_firewall_chains) \
    AIF_FUNC(main_start_c) \
    AIF_FUNC(main_restart_c) \
    AIF_FUNC(reinit_firewall_chains) \
    AIF_FUNC(setup_default_policies) \
    AIF_FUNC(setup_firewall_rules) \
    AIF_FUNC(setup_hostblock_chain) \
    AIF_FUNC(setup_kernel_settings) \
    AIF_FUNC(setup_misc) \
    AIF_FUNC(show_applied) \
    AIF_FUNC(show_disabled) \
    AIF_FUNC(show_restart) \
    AIF_FUNC(show_start) \
    AIF_FUNC(show_stop) \
    AIF_FUNC(show_stop_blocked) \
    AIF_FUNC(stop_block_firewall) \
    AIF_FUNC(stop_firewall) \

#if 1 // Mos 2014/08/15, refresh iptable per different service
extern void main_run_custom_services(void);
#endif

/**************************************************************************/
/*      LOCAL DECLARATIONS:                                               */
/**************************************************************************/

/**************************************************************************/
/*      LOCAL VARIABLES:                                                  */
/**************************************************************************/

#define AIF_FUNC(__f) extern void __f(void);
AIF_FUNCS
#undef AIF_FUNC

#define AIF_FUNC(__f) { #__f, __f },
typedef struct
{
    char *name;
    void (*func)(void);
} AIF_funcs_t;
AIF_funcs_t AIF_funcs[] =
{
    AIF_FUNCS
#if 1 // Mos 2014/08/15, refresh iptable per different service
   {"main_run_custom_services", main_run_custom_services},
#endif
    {NULL, NULL}
};
#undef AIF_FUNC

/**************************************************************************/
/*      INTERFACE FUNCTIONS Implementation:                               */
/**************************************************************************/

/**************************************************************************/
/*! \fn int main(int argc, char *argv[])
 **************************************************************************
 *  \brief Executed the requested function
 *  \param[in] argv[0] is the name of the function requested
 *  \return 0
 **************************************************************************/
int main(int argc, char *argv[])
{
    AIF_funcs_t *p;

    env_init();

    if ((ARNO_IPTABLESBATCH_VERBOSE = getenv("ARNO_IPTABLESBATCH_VERBOSE")) == NULL)
    {
        ARNO_IPTABLESBATCH_VERBOSE = "";
    }

    for (p = AIF_funcs; p->name != NULL; p++)
    {
        if (strstr(argv[0], p->name) != NULL)
        {
            //{char str[22]; struct timeval tv; struct tm *tmp; gettimeofday(&tv, NULL); tmp = localtime(&tv.tv_sec); strftime(str, sizeof(str), "%H:%M:%S", tmp); printf(">>>>>>> %s - %s.%03ld\n", p->name, str, tv.tv_usec / 1000);}
            p->func();
            //{char str[22]; struct timeval tv; struct tm *tmp; gettimeofday(&tv, NULL); tmp = localtime(&tv.tv_sec); strftime(str, sizeof(str), "%H:%M:%S", tmp); printf("<<<<<<< %s - %s.%03ld\n", p->name, str, tv.tv_usec / 1000);}
            break;
        }
    }

    if (p == NULL)
    {
        /* Not found */
        printf("--->>> CARNO did not find %s\n", argv[0]);
    }

    return 0;
}
