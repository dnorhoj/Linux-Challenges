#!/bin/bash
# Should run before the user gets access to the environment, but after the files are copied

cd $(dirname $(readlink -f "$0"))

setup_levels() {
    LEVELS=$(find /home/${LINUX_USERNAME} -maxdepth 1 -type d)

    for i in $LEVELS
    do
        if [ -d $i/fs ]; then
            cp -r $i/fs/* /
            rm -rf $i/fs
        fi

        find $i -type d -exec chmod 0755 {} +
        find $i -type f -not -executable -exec chmod 0644 {} +
        find $i -type f -name flag -exec chmod 0640 {} +
        find $i -type f -executable -exec chmod 4755 {} +
    done
}

setup_levels
