#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>

#include "commands.h"
#include "cwd.h"
#include "logging.h"
#include "mystring.h"

char *cwd = NULL;

extern int readyshareCloud_conn;    /* pling added 10/08/2012 */

int bftpd_cwd_chdir(char *dir)
{
	/* Foxconn added start pling 10/08/2012 */
	char root_dir[] = "/shares/%s";
	char convert_dir[1024];
	/* Foxconn added end pling 10/08/2012 */

    if (strncmp(dir,"/shares/shares",strlen("/shares/shares"))==0)
    {//jenny
        if (chdir(dir))
        {
            dir = dir+strlen("/shares");
        }
    }
	char *tmp = bftpd_cwd_mappath(dir);

	/* Foxconn added start pling 10/08/2012 */
	/* Handle ReadyShare Cloud connections specially */
	if (readyshareCloud_conn)
	{
		if (strncmp(tmp, "/shares", 7))
		{
			free(tmp);
			sprintf(convert_dir, root_dir, dir);
			tmp = bftpd_cwd_mappath(convert_dir);
		}
	}
	/* Foxconn added end pling 10/08/2012 */

	/* Foxconn added start pling 05/14/2009 */
	/* Sanity check, don't allow user to get outside of the /shares  */
	/* Foxconn modified start pling 09/17/2013 */
	/* IE will have problem when sees 'access denied', so allow chdir to '/' */
	if (strlen(tmp) == 0 /*|| strcmp(tmp, "/") == 0*/) {
	/* Foxconn modified end pling 09/17/2013 */
		free(tmp);
		errno = EACCES;
		return -1;
	}
	/* Foxconn added end pling 05/14/2009 */

	/* Foxconn added start pling 09/02/2012 */
	/* WNDR4500v2 IR45/46/47, don't allow user to access outside /shares */
	/* Foxconn modified start pling 09/17/2013 */
	/* IE will have problem when sees 'access denied', so allow chdir to '/' */
	if (strncmp(tmp, "/shares", 7) != 0 && strcmp(tmp, "/") != 0) {
		free(tmp);
		bftpd_log("Block cwd to '%s'\n", tmp);
		errno = ENOENT; //EACCES;
		return -1;
	}
	/* Foxconn modified end pling 09/17/2013 */
	/* Foxconn added end pling 09/02/2012 */

	if (chdir(tmp)) {
		free(tmp);
		return errno;
	}
	cwd = realloc(cwd, strlen(tmp) + 1);
	strcpy(cwd, tmp);
	new_umask();
	free(tmp);
	return 0;
}

char *bftpd_cwd_getcwd()
{
	return strdup(cwd);
}

void appendpath(char *result, char *tmp)
{
	if (!strcmp(tmp, "."))
		return;
	if (!strcmp(tmp, "..")) {
        if (strcmp(result, "/")) {
            if (result[strlen(result) - 1] == '/')
                result[strlen(result) - 1] = '\0';
            tmp = result;
            while (strchr(tmp, '/'))
                tmp = strchr(tmp, '/') + 1;
            *tmp = '\0';
            if ((result[strlen(result) - 1] == '/') && (strlen(result) > 1))
                result[strlen(result) - 1] = '\0';
        }
	} else {
		if (result[strlen(result) - 1] != '/')
			strcat(result, "/");
		strcat(result, tmp);
	}
}



char *bftpd_cwd_mappath(char *path)
{
	char *result = malloc(strlen(path) + strlen(cwd) + 16);
	char *path2;
	char *tmp;

        if (! result)
           return NULL;
        path2 = strdup(path);
        if (! path2)
        {
           free(result);
           return NULL;
        }

	if (path[0] == '/')
		strcpy(result, "/");
	else
		strcpy(result, cwd);

	while (strchr(path2, '/')) {
		tmp = strdup(path2);
		*strchr(tmp, '/') = '\0';
		cutto(path2, strlen(tmp) + 1);
		appendpath(result, tmp);
		free(tmp);
	}
	appendpath(result, path2);
	free(path2);
	return result;
}

void bftpd_cwd_init()
{
	cwd = malloc(256);
	getcwd(cwd, 255);
}

void bftpd_cwd_end()
{
	if (cwd) {
		free(cwd);
		cwd = NULL;
	}
}
