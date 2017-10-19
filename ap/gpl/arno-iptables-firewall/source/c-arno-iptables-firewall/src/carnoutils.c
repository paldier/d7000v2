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

#define _CARNOUTILS_C_

/*! \file carnoutils.c
    \brief Generalized utilities
*/

/**************************************************************************/
/*      INCLUDES:                                                         */
/**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define __USE_GNU
#include <string.h>
#undef __USE_GNU
#include <errno.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "carnoutils.h"

/**************************************************************************/
/*      EXTERNS Declaration:                                              */
/**************************************************************************/

/**************************************************************************/
/*      DEFINES:                                                          */
/**************************************************************************/

/**************************************************************************/
/*      LOCAL DECLARATIONS:                                               */
/**************************************************************************/

int DBG_sysoutDebug = 0;
int DBG_stringcatDebug = 0;
int DBG_getfield = 0;

/**************************************************************************/
/*      LOCAL VARIABLES:                                                  */
/**************************************************************************/

/**************************************************************************/
/*      INTERFACE FUNCTIONS Implementation:                               */
/**************************************************************************/

/**************************************************************************/
/*! \fn char *sysout(char *cmd, int *retval)
 **************************************************************************
 *  \brief Execute command in a shell
 *  \param[in] command
 *  \param[out] return value fropm the shell
 *  \return stdout of the shell, this is an allocated string, must be free()-ed
 **************************************************************************/
char* sysout(char *cmd, int *retval) 
{
    FILE *p;
    char *buff = NULL;
    int len = 50;
    int nchars = 0;
    int fret;
    int err;
    int ret;

    if (DBG_sysoutDebug) DBG("cmd - |%s|", cmd);

    p = popen(cmd, "r");
    while (!feof(p))
    {
        len *= 2;
        buff = realloc(buff, len);
        fret = fread(buff + nchars, 1, len - nchars - 1, p);
        err = errno;
        if (fret >= 0)
        {
            nchars += fret;
            buff[nchars] = '\0';
            if (DBG_sysoutDebug) DBG("buff - @%p - %d (of %d, %d on this fread) |%s|", buff, nchars, len, fret, buff);
        }
        else
        {
            if (!feof(p))
            {
                if (DBG_sysoutDebug) DBG("Got err %d - %s", err, strerror(err));
            }
        }
    }
    ret = WEXITSTATUS(pclose(p));

    if (DBG_sysoutDebug) DBG("Final buff - @%p - %d (of %d) |%s|, ret %d", buff, nchars, len, buff, ret);

    if (retval != NULL)
    {
        *retval = ret;
    }

    return buff;
}

/**************************************************************************/
/*! \fn char *tr(char *insrc, char *inorg, char *inrepl)
 **************************************************************************
 *  \brief Replace all appearances (in insrc) of chars in inorg by the matching char in inrepl
 *  \param[in] insrc - string to search in
 *  \param[in] inorg - what to search for
 *  \param[in] inrepl - write instead of org
 *  \return Translated string, this is an allocated string, must be free()-ed
 **************************************************************************/
char* tr(char *insrc, char *inorg, char *inrepl) 
{
    int org_len;
    int repl_len;
    char *src = NULL;
    char *org = NULL;
    char *repl = NULL;
    char *curr_char;
    char *org_p;
    char char_str[2] = {'\0', '\0'};

    if ((insrc == NULL) || (inorg == NULL) || (inrepl == NULL))
    {
        return NULL;
    }

    src = strdup(insrc);
    org = strdup(inorg);
    org_len = strlen(org);
    repl = strdup(inrepl);
    repl_len = strlen(repl);
    /* If org is longer than repl, expand the last char of repl till length match */
    for (; org_len > repl_len; repl_len++)
    {
        char_str[0] = repl[repl_len - 1];
        STRINGCAT(repl, char_str);
    }
    /* If org is shorter than repl, shorten repl to the length of org */
    if (org_len < repl_len)
    {
        repl[org_len - 1] = '\0';
    }
    /* Now org and repl are the same length */

    /* For each char in src, if it is in org, replace it with the match in repl */
    for (curr_char = src; *curr_char != '\0'; curr_char++)
    {
        /* Is the curr char in org? */
        if ((org_p = strchr(org, *curr_char)) != NULL)
        {
            /* Replace with the match in repl */
            *curr_char = repl[org_p - org];
        }
    }

    return src;
}

/**************************************************************************/
/*! \fn char *getfield(char *src, char *sep, int field_num)
 **************************************************************************
 *  \brief sep divides src into fields, return field number field_num (1st is 1)
 *  \param[in] src - string to search in
 *  \param[in] sep - field seperator
 *  \param[in] field_num - number of field to return (1st is 1)
 *  \return Requested field, this is an allocated string, must be free()-ed
 **************************************************************************/
char *getfield(char *insrc, char *sep, int field_num)
{
    int i;
    char *p;
    char *src = NULL;
    char *src_r = NULL;
    char *token = NULL;

    if (insrc == NULL)
    {
        return NULL;
    }

    if (strstr(insrc, sep) == NULL)
    {
        /* sep does not exist in src */
        return NULL;
    }
    src = strdup(insrc);

    /* Search for requested field */
    for (i = 1, token = strtok_r(src, sep, &src_r); (i < field_num) && (token != NULL); i++, token = strtok_r(NULL, sep, &src_r))
    {
        ;
    }

    if ((token != NULL) && (i == field_num))
    {
        /* Found token on requested field */
        p = strdup(token);
    }
    else
    {
        p = NULL;
    }
    FREE(src);

    if (DBG_getfield) DBG("src \"%s\", sep \"%s\", field %d, ret \"%s\"", insrc, sep, field_num, p);

    return p;
}

#if 1
/**************************************************************************/
/*! \fn char *stringcat_null(char *s1, char *s2, ...)
 **************************************************************************
 *  \brief Cat all strings
 *  \param[in] s1
 *  \param[in] s2
 *  \param[in] Optional additional strings, last must be NULL
 *  \return Catenated string, this is an allocated string, must be free()-ed
 **************************************************************************/
char* stringcat_null(char *s1, char *s2, ...) 
{
    va_list va;
    char *s = NULL;
    int len;
    char *nextarg;
    char *result = NULL;

    if (DBG_stringcatDebug) DBG("s1 - |%s|, s2 - |%s|", s1, s2);

    if (s1 != NULL)
    {
        result = strdup(s1);
    }

    va_start(va, s2);
    for (nextarg = s2; nextarg != NULL; nextarg = va_arg(va, char *))
    {
        len = (result == NULL ? 0 : strlen(result)) + strlen(nextarg) + 1;

        s = realloc(result, len);
        if (result == NULL)
        {
            // 1st, ensure we are null terminated 
            s[0] = '\0';
        }
        result = s;
        strcat(result, nextarg);

        if (DBG_stringcatDebug) DBG("len %d, result - |%s|", len, result);
    }
    va_end(va);

    if (DBG_stringcatDebug) DBG("len %d, result - |%s|", len, result);

    return result;
}
#else
char *stringcat(char *s1, char *s2)
{
    char *s;
    int len;

    len = ((s1 != NULL) ? strlen(s1) : 0) + ((s2 != NULL) ? strlen(s2) : 0) + 1;
    if (len == 0)
    {
        return NULL;
    }
    s = malloc(len);
    if (s1 != NULL)
    {

        strcpy(s, s1);
        if (s2 != NULL)
        {

            strcat(s, s2);
        }
    }
    else
    {
        /* s2 != NULL since len != 0 && s1 == NULL */

        strcpy(s, s2);
    }


    return s;
}
#endif

/**************************************************************************/
/*! \fn char *stringcatn(char *s1, char *s2, int s2_len)
 **************************************************************************
 *  \brief Cat strings with len limit
 *  \param[in] s1
 *  \param[in] s2
 *  \param[in] s2_len
 *  \return Catenated string, this is an allocated string, must be free()-ed
 **************************************************************************/
char *stringcatn(char *s1, char *s2, int s2_len)
{
    char *s;
    int s1_len;
    int s2strlen = 0;

    s1_len = (s1 != NULL) ? strlen(s1) : 0;
    if (s2 != NULL) 
    {
        s2strlen = strlen(s2);
    }
    if (s2_len > s2strlen)
    {
        s2_len = s2strlen;
    }
    if ((s1_len == 0) && (s2_len == 0))
    {
        return NULL;
    }
    s = malloc(s1_len + s2_len + 1);
    if (s1 != NULL)
    {
        strcpy(s, s1);
        if (s2 != NULL)
        {
            strncat(s, s2, s2_len);
        }
    }
    else
    {
        /* s2 != NULL since len != 0 && s1 == NULL */
        strncpy(s, s2, s2_len);
        s[s2_len] = '\0';
    }

    return s;
}

/**************************************************************************/
/*! \fn char *partial_ip4(char *ip4, int m1, int m2, int m3, int m4)
 **************************************************************************
 *  \brief Get masked IP
 *  \param[in] ip4 - ipv4 : a.b.c.d
 *  \param[in] m1, m2, m3, m4 : masks - 255 ==> mask out
 *  \return IP with masked parts as 255, this is an allocated string, must be free()-ed
 **************************************************************************/
char* partial_ip4(char *ip4, int m1, int m2, int m3, int m4) 
{
    char *useip = strdup(ip4);
    char *token1;
    char *token2;
    char *token3;
    char *token4;
    char newip4[16];

    token1 = strtok(useip, ".");
    token2 = strtok(NULL, ".");
    token3 = strtok(NULL, ".");
    token4 = strtok(NULL, ".");

    if (m1 != 255)
    {
        strcpy(newip4, token1);
    }
    else
    {
        strcpy(newip4, "255");
    }
    strcat(newip4, ".");
    if (m2 != 255)
    {
        strcat(newip4, token2);
    }
    else
    {
        strcat(newip4, "255");
    }
    strcat(newip4, ".");
    if (m3 != 255)
    {
        strcat(newip4, token3);
    }
    else
    {
        strcat(newip4, "255");
    }
    strcat(newip4, ".");
    if (m4 != 255)
    {
        strcat(newip4, token4);
    }
    else
    {
        strcat(newip4, "255");
    }
    
    FREE(useip);

    return strdup(newip4);
}

/**************************************************************************/
/*! \fn void source(char *filename)
 **************************************************************************
 *  \brief Execute file containg iptables commands
 *  \param[in] filename
 *  \return NA
 **************************************************************************/
void source(char *filename) 
{
    struct stat stat_buf;
    int len;
    char *file_buff;
    int fd;
    int l;
    char *line;
    char *line_r;
    char *cmd;
    char *cmd_r;
    char *iptcmd;


    if (stat(filename, &stat_buf) == 0)
    {
        len = stat_buf.st_size;
        file_buff = malloc(len + 11); /* to be on the safe side... */
        fd = open(filename, O_RDONLY);
        if (fd >= 0)
        {
            if ((l = read(fd, file_buff, len+5)) != len)
            {
                printf("File %s read %d, st_size %d\n", filename, l, len);
                close(fd);
                exit(2);
            }
            close(fd);
            /* Terminate */
            file_buff[l] = '\0';
            
            for (line = strtok_r(file_buff, "\n", &line_r); line != NULL; line = strtok_r(NULL, "\n", &line_r))
            {
                /* Skip leading blanks */
                line += strspn(line, " ");
                /* Comment? */
                if (line[0] == '#')
                {
                    continue;
                }
                /* Get cmd */
                cmd = strtok_r(line, " ", &cmd_r);
                if (cmd == NULL)
                {
                    continue;
                }
                /* Mark iptables cmd */
                iptcmd = line + strlen(cmd) + 1;
                /* Skip leading blanks */
                iptcmd += strspn(iptcmd, " ");
                if (strcmp(cmd, "iptables") == 0)
                {
                    iptables(iptcmd);
                }
                else if (strcmp(cmd, "ip4tables") == 0)
                {
                    ip4tables(iptcmd);
                }
                else if (strcmp(cmd, "ip6tables") == 0)
                {
                    ip6tables(iptcmd);
                }
                else
                {
                    printf("Unknown command |%s| in file %s\n", cmd, filename);
                }
            }
        }
    }
}



/**************************************************************************/
/*      LOCAL FUNCTIONS:                                                  */
/**************************************************************************/


