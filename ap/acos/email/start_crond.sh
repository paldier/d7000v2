#echo $PATH
#!/bin/bash
#PATH=/bin:/sbin:/usr/bin:/usr/sbin:~/bin
#export PATH

CRON_PATH="/var/cron/crontabs"
PASSWD_PATH="/tmp/samba/private"
#echo "start crond.sh"
#echo "argc: $#"
#echo "argv 1: $1"
#echo "argv 2: $2"
#echo "argv 3: $3"
#echo "argv 4: $4"
#echo "argv @: $@"

if [ ! -e $CRON_PATH/root ]; then
    echo "create path /var/cron/crontabs"
    mkdir -p $CRON_PATH
fi

ps cax | grep crond
if [ $? -eq 0 ]; then
    killall crond
fi

if [ $2 == "0" ] && [ ! -f $PASSWD_PATH/passwd ]; then
    echo "rewrite passwd file for crond"
    mkdir -p $PASSWD_PATH
    echo "root:x:0:0:root:/:/bin/bash" > $PASSWD_PATH/passwd
elif [ $2 == "2" ]; then     #hour schedule
    echo "0 * * * * kill -SIGUSR2 $1" > $CRON_PATH/root
    /usr/sbin/crond -c /var/cron/crontabs 
elif [ $2 == "3" ]; then # Daily schedule
    echo "0 $3 * * * kill -SIGUSR2 $1" > $CRON_PATH/root
    /usr/sbin/crond -c /var/cron/crontabs 
elif [ $2 == "4" ]; then # Weekly schedule
    echo "0 $3 * * $4 kill -SIGUSR2 $1"> $CRON_PATH/root
    /usr/sbin/crond -c /var/cron/crontabs 
elif [ $2 == "5" ]; then # kill crond
    echo "only do kill crond"
else
    echo "error schedule in start_crond.sh"
fi

#echo "end crond.sh"