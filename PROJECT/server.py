# first of all import the socket library 
import random 
import csv
import socket ,time , threading ,pickle,json             
  
# next create a socket object 
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)          
print("Socket successfully created")
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) 
# reserve a port on your computer in our 
# case it is 12345 but it can be anything 
port = 27290               
  
# Next bind to the port 
# we have not typed any ip in the ip field 
# instead we have inputted an empty string 
# this makes the server listen to requests  
# coming from other computers on the network 
s.bind(('127.0.1.1', port))         
print("socket binded to %s" %(port) )
  
# put the socket into listening mode 
s.listen(5)      
print("socket is listening")

# Establish connection with client. 
c, addr = s.accept()    
print('Got connection from', addr )

def data():
	round_value=0
	d={'start':0xAA,'stop':0xBB,'packtype':0xA4,'macId':0xCC,'checksum':20,
	'temp': round(round_value+random.uniform(10,40),2),'hum': round(round_value+random.uniform(45,90),2)}
	
	with open('file1.csv', mode='a+') as file1:
		write = csv.writer(file1, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
		write.writerow([d['temp']])
		write.writerow([d['hum']])
	if c:
		c.send(pickle.dumps(d))
		#json_str=json.dumps(dict1,indent=4)
        	#print(json_str)
	        #connc.send(json_str.encode())'''
# a forever loop until we interrupt it or  
# an error occurs
 
while True :   
# send a thank you message to the client.  
	t=threading.Timer(5.0,data)
	#json_str=json.dumps(dict1,indent=4)
	#print(json_str)
	#connc.send(json_str.encode())
	#connc.close
	t.start()
	t.join()        
	
# Close the connection with the client 

c.close() 
s.close()
exit(0)
