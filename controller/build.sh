#!/bin/bash

cd "$(dirname "$0")"

if [ ! -f ../.env ]; then
    echo "$0: .env file not found. Please read README.md"
    exit 1
fi

set -a
source ../.env
set +a

docker build . --no-cache \
    -t ${DOCKER_IMAGE_NAME}-controller \
    --build-arg LINUX_USERNAME=${LINUX_USERNAME} \
    --build-arg LINUX_PASSWORD=${LINUX_PASSWORD} \
    --build-arg DOCKER_IMAGE_NAME=${DOCKER_IMAGE_NAME}
