# Use a Fedora base image
FROM fedora:latest

# Install Verilog development dependencies
RUN dnf install -y iverilog yosys inotify-tools just

# Install netlistsvg globally using npm
RUN dnf install -y nodejs
RUN npm install -g netlistsvg

# Set the working directory inside the container
WORKDIR /app

# Copy the Justfile and all *.v files inside the container
COPY Justfile /app/
COPY *.v /app/

# Set the entry point to an interactive shell
CMD ["/bin/bash"]
