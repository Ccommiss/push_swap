FROM ubuntu:latest
RUN mkdir push_swap
ENV TZ=Europe/Minsk
RUN apt-get update -y
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get install -y build-essential valgrind clang
COPY srcs /push_swap/srcs
COPY includes /push_swap/includes
COPY main.c /push_swap/
COPY Makefile /push_swap/
