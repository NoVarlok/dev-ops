FROM gcc:latest as build

MAINTAINER User "https://github.com/HSE-NN-SE/devops-18pi-NoVarlok"

# RUN locale-gen en_US.UTF-8
# RUN update-locale LANG=en_US.UTF-8 LC_MESSAGES=POSIX

WORKDIR /build

# download packages
RUN apt-get update && \
    apt-get install -y \
      cmake

# copy directory /src into container
ADD ./src /app/src
ADD ./include /app/src
ADD ./cmake /app/src

# build directory set up
WORKDIR /app/build

# project build
RUN cmake ../src && \
    cmake --build .

# run ---------------------------------------

# use ubuntu:latest
FROM ubuntu:latest

# add user
RUN groupadd -r sample && useradd -r -g sample sample
USER sample

# set up workdir
WORKDIR /app

# copy app into workdir
COPY --from=build /app/build/project_app .
# COPY ./src/student_input.txt /app/build/student_input.txt
# COPY ./src/group_input.txt /app/build/student_input.txt

# set up entry point
ENTRYPOINT ["./project_app"]