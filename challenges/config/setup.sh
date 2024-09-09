#!/bin/bash
# Should run before the user gets access to the environment, but after the files are copied

cd $(dirname $(readlink -f "$0"))

setup_levels() {
    level_directories=$(find "/home/${LINUX_USERNAME}" -maxdepth 1 -type d)

    for level_dir in $level_directories
    do
        if [ -d "$level_dir"/fs ]
        then
            cp -r "$level_dir"/fs/* /
            rm -rf "$level_dir"/fs
        fi

        # Normalize permissions
        find "$level_dir" -type d -exec chmod 0755 {} +
        find "$level_dir" -type f -not -executable -exec chmod 0644 {} +

        # Make flag unreadable by user
        find "$level_dir" -type f -name flag -exec chmod 0640 {} +

        # Make executable files SUID
        find "$level_dir" -type f -executable -exec chmod 4755 {} +

        # Challenge specific options
        if [ -f "$level_dir"/config.json ]
        then
            # Run level setup commands
            jq -r ".commands[]?" "$level_dir"/config.json | while read command
            do
                (cd "$level_dir"; bash -c "$command")
            done
        fi
    done
}

setup_levels
