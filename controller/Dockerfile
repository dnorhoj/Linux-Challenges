FROM alpine

ARG LINUX_USERNAME
ARG LINUX_PASSWORD
ARG DOCKER_IMAGE_NAME

RUN apk add --no-cache openssh docker-cli libc-dev gcc moreutils gettext-envsubst

# Setup user
RUN adduser -h /home/${LINUX_USERNAME} -s /bin/sh -D ${LINUX_USERNAME}
RUN echo "${LINUX_USERNAME}:${LINUX_PASSWORD}" | chpasswd

# Build init wrapper
COPY init/init_wrap.c /tmp/
RUN gcc /tmp/init_wrap.c -o /usr/bin/init
RUN rm /tmp/init_wrap.c

# Set SUID for init wrapper.
RUN chown root:root /usr/bin/init
RUN chmod u+s /usr/bin/init

# Copy init script
COPY init/init.sh /usr/bin/init.sh
RUN DOCKER_IMAGE_NAME=$DOCKER_IMAGE_NAME envsubst '$DOCKER_IMAGE_NAME' < /usr/bin/init.sh | sponge /usr/bin/init.sh

# SSH
COPY config/sshd_config /etc/ssh/sshd_config

# MOTD
COPY config/motd /etc/motd

# Entrypoint
COPY entrypoint.sh /
CMD [ "/entrypoint.sh" ]
