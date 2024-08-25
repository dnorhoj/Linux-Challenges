#!/bin/sh

if [ ! -t 1 ]; then
    echo "Not a TTY, exiting..."
    exit 1
fi

NAME=challenge-instance-$(xxd -l 8 -p /dev/urandom)

echo "Spawning challenge, please wait..."

docker run --rm --network=none --name $NAME --hostname challenge -e TERM=$TERM -u user -it linux-challenge /bin/bash
