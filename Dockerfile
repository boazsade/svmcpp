FROM ubuntu:20.04
MAINTAINER boaz_sade
# rppg for base image
LABEL version="1.0"
LABEL description="build docker with c++20 compiler"

WORKDIR /apps

ENV container docker

RUN apt-get update && apt-get install -y curl git wget \
    openssl libssl-dev apt-utils python3  \
    make build-essential vim dos2unix
RUN apt install -y  unzip python3 
#    libavcodec-dev libavformat-dev libswscale-dev  pkg-config autoconf automake libtool 
#RUN apt install -y   libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libopenexr-dev \
#    libgstreamer-plugins-base1.0-dev libgstreamer1.0-dev \
#    libdc1394-22-dev ffmpeg 
RUN apt install -y manpages-dev gcc-10 g++-10
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 100 --slave /usr/bin/g++ g++ /usr/bin/g++-10 --slave /usr/bin/gcov gcov /usr/bin/gcov-10
