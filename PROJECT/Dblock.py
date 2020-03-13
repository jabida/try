import threading , socket ,pickle               
import random
import csv
from itertools import count
#import pandas as pd
#import matplotlib.pyplot as plt
#from matplotlib.animation import FuncAnimation

# next create a socket object 
s = socket.socket()          
print("Socket successfully created")

# reserve a port on your computer in our 
# case it is 12345 but it can be anything 
port = 9009                
  
# Next bind to the port 
# we have not typed any ip in the ip field 
# instead we have inputted an empty string 
# this makes the server listen to requests  
# coming from other computers on the network 
s.bind(('', port))         
print("socket binded to %s" %(port) )
  
# put the socket into listening mode 
s.listen(5)      
print("socket is listening")
  
# a forever loop until we interrupt it or  
# an error occurs
# Establish connection with client. 
c, addr = s.accept()      
print('Got connection from', addr)
counter1=0
flag=0
x_vals = []
y_vals = []
time=[]
index = count()

def animate(i):
	print(counter1)
	rcvdata=c.recv(1024)
	data=pickle.loads(rcvdata)
	print(data)
	with open('file1.csv', mode='w') as file1:
		write=csv.writer(file1,delimiter=',',quotechar='"',quoting=csv.QUOTE_MINIMAL)
		write.writerow(data)
'''	x_vals.append(next(index))
	y_vals.append(data['temp'])
	time.append(data['time'])
	if counter1 == 20:
		global x_vals
		x_vals =x_vals[-10:]
		global y_vals
		y_vals=y_vals[-10:]
		global time
		time=time[-10:]
		global counter1
		counter1=0
	plt.cla()
	plt.xticks(x_vals,time,rotation=45)
	plt.plot(x_vals, y_vals)
	global counter1
	counter1+=1


	
while True: 
    
   # send a thank you message to the client.  

	ani=FuncAnimation(plt.gcf(),animate,interval=5000)
	counter1+=1
	if flag ==0:
		#plt.tight_layout()
		plt.show()
		flag=1
 ''' 
   # Close the connection with the client 
c.close() 
