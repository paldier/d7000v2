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
 * Utility to strip the asp stuff <% ... %> from HTML files.
 * 
 * Created - Foxconn wklin 01/04/2007
 *
 */
#include <stdio.h>
#include <unistd.h>

extern char *optarg;

int main(int argc, char *argv[])
{
    int c, c1, c2;
    char *in_file = NULL, *out_file = NULL;
    FILE *in = NULL, *out = NULL;
    char buf[3];

    for (;;) {
        c = getopt(argc, argv, "i:o:");
        if (c == EOF) break;
        switch (c) {
            case 'i':
                in_file = optarg;
                break;
            case 'o':
                out_file = optarg;
                break;
            default:
                exit(1);
        }
    } /* end of for */

    if (!in_file || !out_file) {
        fprintf(stderr, "usage: aspstrip -i infile -o outfile\n");
        exit(1);
    }

    in = fopen(in_file, "r");
    if (!in) {
        fprintf(stderr, "Error opening %s.\n", in_file);
        return -1;
    }

    out = fopen(out_file, "w");
    if (!out) {
        fprintf(stderr, "Error opening %s.\n", out_file);
        fclose(in);
        return -1;
    }

    c1 = -1;
    while (EOF != (c2 = fgetc(in))) {
        if (c1=='<' && c2=='%') {
            c1 = -1;
            while (EOF != (c2 = fgetc(in))) {
                if (c1=='%' && c2=='>') {
                    c1 = -1;
                    break;
                } else {
                    c1 = c2;
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
    return 0;
}
