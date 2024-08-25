#!/bin/bash

cd "$(dirname "$0")"

if [ ! -f ../.env ]; then
    echo "$0: .env file not found. Please read README.md"
    exit 1
fi

set -a
source ../.env
set +a

docker build . \
    -t ${DOCKER_IMAGE_NAME} \
    --build-arg LINUX_USERNAME=${LINUX_USERNAME} \
    --build-arg LINUX_PASSWORD=${LINUX_PASSWORD}
