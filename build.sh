#!/bin/bash

PWD="`pwd`"

cd `dirname $0`/deps/wiringPi/wiringPi
make
cd "$pwd"

node-gyp rebuild