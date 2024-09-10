FROM ubuntu:22.04 AS build

ARG LINUX_USERNAME
ARG LINUX_PASSWORD

RUN apt update
RUN apt install -y build-essential gettext-base

WORKDIR /app

COPY Makefile /app
COPY src /app/src

RUN make clean && LINUX_USERNAME=$LINUX_USERNAME make

FROM ubuntu:22.04

ARG LINUX_USERNAME
ARG LINUX_PASSWORD

# Install stuff
RUN apt update
RUN apt install -y \
    sudo \
    nano \
    vim \
    strace \
    man \
    man-db \
    jq \
    less \
    strace \
    ltrace

RUN yes | unminimize

RUN useradd -m -s /bin/bash $LINUX_USERNAME
RUN echo "${LINUX_USERNAME}:${LINUX_PASSWORD}" | chpasswd

WORKDIR /home/${LINUX_USERNAME}/

# Copy challenge
COPY --from=build /app/dist .

# Run setup.sh
COPY ./config/setup.sh /tmp/
RUN LINUX_USERNAME=$LINUX_USERNAME /tmp/setup.sh
RUN rm /tmp/setup.sh
