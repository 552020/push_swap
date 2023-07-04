# Using arm64v8/ubuntu as base image
FROM arm64v8/ubuntu:latest

# Setting working directory in the container
WORKDIR /app

# Installing necessary tools for building your application and Valgrind for memory leak detection
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    make \
    valgrind 

# Copying your application and its dependencies into the Docker image
COPY . /app

# Building your application
RUN make re

# This will run when the container starts. Change this to whatever command you wish to run.
CMD cd ./tests && ./script500.sh
