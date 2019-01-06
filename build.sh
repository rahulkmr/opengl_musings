#!/bin/sh

clang++ -std=c++11 -o $2 -I ./include  -lglfw -framework OpenGL src/glad.c src/utils.cpp $1