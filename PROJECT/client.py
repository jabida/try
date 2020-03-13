import socket
import json
import pickle
try:
        s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        print("socket is created")
except Exception as e:
        print(e)

port_num=27290
try:
        s.connect(('127.0.1.1',port_num))
        print("successfully connected")
except Exception as e:
        print(e)

#s.send("I am connected")
#res=s.recv(100)
#print(res)
'''json_str=s.recv(1000)
json_str=json_str.decode()
print(type(json_str))
dict1=json.loads(json_str)
print(dict1)
s.close()'''
while True:
	c=s.recv(1000)
	pic=pickle.loads(c)
	print(pic)


