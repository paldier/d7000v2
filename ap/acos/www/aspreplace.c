/***************************************************************************
***
***    Copyright 2005  Hon Hai Precision Ind. Co. Ltd.
***    All Rights Reserved.
***    No portions of this material shall be reproduced in any form without the
***    written permission of Hon Hai Precision Ind. Co. Ltd.
***
***    All information contained in this document is Hon Hai Precision Ind.  
***    Co. Ltd. company private, proprietary, and trade secret property and 
***    are protected by international intellectual property laws and treaties.
***
****************************************************************************/
/*
 * Utility to collect asp stuff <% ... %> from HTML files.
 * 
 * Created - Foxconn wklin 01/31/2007
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern char *optarg;

static void trim(char *cmd)
{
    char *p = cmd;
    char buf[1024] = "";
    int i;

    if (!p)
        return;

    /* trim off leading space */
    while (*p == ' ')
        p++;
    strcpy(buf, p);
    
    /* trim off trailing space */
    for (i=strlen(buf)-1; i>=0; i--) {
        if (buf[i] == ' ')
            buf[i] = '\0';
        else
            break;
    }
    strcpy(cmd, buf);
    return;
}

int main(int argc, char *argv[])
{
    int c, c1, c2;
    char *out_file = NULL, *asp_file = NULL;
    char in_file[512]="";
    FILE *in = NULL, *out = NULL, *asp = NULL;
    char buf[1024];
    int id = 0;
    char to_be_written[1024];
    int len;
    int i, matched;

    for (;;) {
        c = getopt(argc, argv, "i:o:k:");
        if (c == EOF) break;
        switch (c) {
            case 'i':
                out_file = optarg;
                break;
            case 'k':
                asp_file = optarg;
                break;
            default:
                exit(1);
        }
    } /* end of for */

    if (!out_file || !asp_file) {
        fprintf(stderr, "usage: aspreplace -i infile -k outfile\n");
        exit(1);
    }

    
    if (!strstr(out_file, ".htm") && !strstr(out_file, ".html") && !strstr(out_file, ".js")) {
        fprintf(stderr, "skip %s\n", out_file);
        exit(1);
    }

    sprintf(buf, "cp %s %s.bak", out_file, out_file);
    system(buf);

    out = fopen(out_file, "w+");
    if (!out) {
        fprintf(stderr, "Error opening %s.\n", in_file);
        return -1;
    }

    sprintf(in_file, "%s.bak", out_file);
    in = fopen(in_file, "r");
    if (!in) {
        fprintf(stderr, "Error opening %s.\n", in_file);
        fclose(out);
        return -1;
    }

    asp = fopen(asp_file, "r+");
    if (!asp) {
        fprintf(stderr, "Error opening %s.\n", asp_file);
        fclose(in);
        fclose(out);
        return -1;
    } else {
        for(id=0; fgets(buf, sizeof(buf), asp); id++);
    }

    c1 = -1;
    while (EOF != (c2 = fgetc(in))) {
        if (c1=='<' && c2=='%') {
            char command[1024] = "";
            char *cp = &command[0];
            c1 = -1;
            while (EOF != (c2 = fgetc(in))) {
                if (c1=='%' && c2=='>') {
                    cp--;
                    *cp = '\0';
                    trim(command);
                    /* check if the asp is alredy in the file */
                    rewind(asp);
                    matched = 0;
                    sprintf(to_be_written, "{\"%s\", NULL},\n", command);
                    for(id=0;fgets(buf, sizeof(buf), asp);id++) {
                        /* printf("compared %s <> %s\n", buf, to_be_written); */
                        if(strcmp(buf, to_be_written)==0) {
                            /* printf("matched %s <> %s\n", buf,
                             * to_be_written);*/
                            matched = 1;
                            break;
                        }
                    }
                    if (!matched)
                        fprintf(asp, "%s", to_be_written);
                    /*printf("id = %d\n", id); */
                    fprintf(out, "<%%%d%>", id);
                    c1 = -1;
                    break;
                } else {
                    c1 = c2;
                    if (c1 == '\"')
                        *cp++ = '\\';
                    *cp++ = c1;
                }
            }
        } else {
            if (c1 != -1)
                fputc(c1, out);
            c1 = c2;
        }
    }
    fputc(c1, out);

    fclose(in);
    fclose(out);
    fclose(asp);
    remove(in_file);
    return 0;
}
