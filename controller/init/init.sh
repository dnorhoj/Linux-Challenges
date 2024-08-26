#!/bin/sh

# This bash script runs with SUID (root).
# We have to be careful that all commands are explicitly stated via absolute paths to minimize risk of PATH injection or similar.

if [ ! -t 1 ]; then
    /bin/echo "Not a TTY, exiting..."
    exit 1
fi

NAME=challenge-instance-$(/usr/bin/xxd -l 8 -p /dev/urandom)

/bin/cat /etc/motd
/usr/bin/docker run --rm --network=none --name $NAME --hostname challenge -e TERM=$TERM -u 1000 -it $DOCKER_IMAGE_NAME /bin/bash
