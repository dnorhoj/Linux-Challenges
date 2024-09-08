
FROM ubuntu:22.04

RUN apt update
RUN apt install -y \
    nano \
    strace \
    ltrace \
    less \
    man \
    man-db

RUN yes | unminimize

RUN useradd -M -s /bin/bash -p '$y$j9T$bXq36aKFGB8EJvkk1GmCL1$LmEsevrFVUMUIHGhynuMaTWgOKa2ovnPyaiEeADv0J0' chal1
RUN useradd -M -s /bin/bash -p '$y$j9T$mTsHlTikWwxyBY12HfSMn0$81CGC86RrYQllGGbK6zddqRsVhlAlNyyzztrneHeDJ9' chal2
RUN useradd -M -s /bin/bash -p '$y$j9T$M8upLYq0pXEMzpOTWaiyo1$oEWngXnZglgL2DGHgo7G0x.Ck0VdbUpHdrVo02DRIQ.' chal3
RUN useradd -M -s /bin/bash -p '$y$j9T$A6noIv3/571aykTu4.jLj0$Od8HZ57ZuEBkgH4In4SDk7MeD5RT5hGygVvQUIGxQl3' chal4
RUN useradd -M -s /bin/bash -p '$y$j9T$b4T7Ow9zjQZ9RkzwCbWpe.$WxFYU5rQQrKcIrTAgtogxC.oiYf62acxbPw3GGGYHJ2' chal5
RUN useradd -M -s /bin/bash -p '$y$j9T$RO1dG0ZC7xBDUUgZYZkJs0$Z1wgH/7zOxybyOFH1uC4WFtZq1FW7xzWqxXCOR3f.d6' chal6
RUN useradd -M -s /bin/bash -p '$y$j9T$K2MJFX8pqrODtjeUjdgcq/$FUJedhJ22FQnNLpgOTiBEYL398qBu8y/xcTR2cHR9mD' chal7
RUN useradd -M -s /bin/bash -p '$y$j9T$u3341WTCsOYVBLIcOQTqr1$Ox.B3aOoIrg16eirTlWayhtxWy55eQ/uhaLuWXP0930' chal8
RUN useradd -M -s /bin/bash -p '$y$j9T$bwMZRA11UQJ/zFH3tYXhb0$yPKZf56DmT6aePI8D6Ocp3qQmibw.n46szTZWFW2JSC' chal9
RUN useradd -M -s /bin/bash -p '$y$j9T$SoUVTkcPgbA.LNm6lLabQ1$5DwWeL1B13lXZReUCC2WgEVUB.dpxz8mKzLVfAHoNL0' chal10
RUN useradd -M -s /bin/bash -p '$y$j9T$hiF6dWZapsebvkPUGYu/k.$DesxjkCBaxUspdSLw6KxAKEkm4iOZ7Er8.sn1nZITv5' chal11

COPY chall.tar.gz /tmp
RUN tar -C / -xzf /tmp/chall.tar.gz
RUN rm /tmp/chall.tar.gz

USER chal1
WORKDIR /home/chal1
