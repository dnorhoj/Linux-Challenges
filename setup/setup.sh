#!/bin/bash

cd $(dirname "$0")

setup_levels() {
    LEVELS=$(find /home/pirat -maxdepth 1 -type d -name level_*)
    
    # Should run before the user gets access to the environment, but after the files are copied
    for i in $LEVELS
    do
        chmod 640 $i/flag
        chmod u+s $i/level_*
    done
}

populate_fs() {
    cp -r ./fs/* /
}

setup_levels
populate_fs
