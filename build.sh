#!/bin/bash
# A script for compiling and preparing the GPIO class and read_button.cpp for use over a web server
echo "Compiling..."
g++ read_button.cpp GPIO.cpp -o read_button.cgi -pthread -lcgicc
config-pin p8.16 gpio_pu
echo "Done"
