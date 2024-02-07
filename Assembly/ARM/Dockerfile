FROM arm32v7/debian:buster-slim

RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    gdb \
    binutils-arm-linux-gnueabihf \
    qemu-user \
    gdb-multiarch \
    vim \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

CMD ["/bin/bash"]
