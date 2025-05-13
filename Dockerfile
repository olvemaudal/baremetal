FROM ubuntu

RUN apt-get update && apt-get install -y \
    build-essential \
    gcc-arm-none-eabi \
    gdb-multiarch \
    && apt-get clean

RUN apt-get update && apt-get install -y \
    git \
    python3 \
    nano \
    vim \
    ed \
    && apt-get clean

WORKDIR /workspace

CMD ["/bin/bash"]