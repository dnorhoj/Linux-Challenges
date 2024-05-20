FROM ubuntu:22.04 AS build

RUN apt update
RUN apt install -y build-essential

WORKDIR /app

COPY chal /app

RUN make

FROM ubuntu:22.04

# Install stuff
RUN apt update
RUN apt install -y \
    openssh-server \
    sudo \
    nano \
    vim \
    strace \
    man \
    man-db

RUN yes | unminimize

RUN useradd -m -s /bin/bash pirat
RUN echo 'pirat:codingpirates' | chpasswd
RUN echo 'root:secret1234' | chpasswd

# SSH
RUN mkdir /run/sshd
COPY ./config/sshd_config /etc/ssh/sshd_config

# motd
RUN rm -rf /etc/update-motd.d
RUN rm -rf /etc/legal
COPY ./config/motd /etc/motd

# Copy challenge
COPY --from=build /app/dist /home/pirat/

# Run setup.sh
COPY ./setup /tmp/
RUN /tmp/setup.sh
RUN rm -rf /tmp/setup.sh

CMD ["/usr/sbin/sshd", "-D"]