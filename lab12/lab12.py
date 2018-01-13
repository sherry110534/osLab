#-*-coding:utf8-*-
import random

freeFrameList=[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
#processA=[0,4,7,2]
#processB=[1,5,7,6]
pageA={}
pageB={}
rand=[]
logic={}
def step1():
	print "STEP1:Initialization"
#processA
	print "Process A:"
	print "*******Page Table*******"
	print "-----Page------Frame----"
	for i in range(0,3):
		print "-\t-1\t-1"
#processB
	print "Process B:"
        print "*******Page Table*******"
        print "-----Page------Frame----"
        for i in range(0,3):
                print "-\t-1\t-1"
#logical memory
	print "*******Logical Memory*******"
        print "-----Page/Entry--Data---"
	
	for j in range(0,12):
		print "-\t%d   %d\t  ?---"%(j/2,j)
#physical memory
	print "*******Physical Memory*******"
        print "-----Page/Entry--Data---"
        for j in range(0,32):
                print "-\t%d   %d\t  ?---"%(j/2,j)
	print "FreeFrameList[16]:"+ str(freeFrameList)

def step2():
	print "STEP2:Paging"
	rand=random.sample(range(0,16),6)
	
	for i in range(0,16):
		if(i in rand):
			freeFrameList.remove(i)
	for i in range(0,3):
		pageA[i]=rand[i]
		print "Process A page(%d)->frame(%d)" %(i,rand[i])
	for i in range(3,6):
		pageB[i]=rand[i]
		print "Process B page(%d)->frame(%d)" %(i,rand[i])

def step3():
	print "STEP3:Result"
#logical memory
	print "*******Logical Memory*******"
        print "-----Page/Entry--Data---"
	for i in range(0,6):
		print "-\t%d   %d\t  %c---"%(i/2,i,i+65)
		logic[i]=i+65
	
	for i in range(6,12):
		print "-\t%d   %d\t  %c---"%(i/2,i,i+91)
		logic[i]=i+91
#processA
	print "Process A:"
	print "*******Page Table*******"
	print "-----Page------Frame----"
	for i in range(0,3):
		print "-\t%d\t%d" %(i,pageA[i])
#processB
	print "Process B:"
        print "*******Page Table*******"
        print "-----Page------Frame----"
        for i in range(3,6):
                print "-\t%d\t%d" %(i,pageB[i])
#physical memory
	print "*******Physical Memory*******"
        print "-----Page/Entry--Data---"

	
        for j in range(0,32):
		if(j/2 in freeFrameList):
                	print "-\t%d   %d\t  ?---"%(j/2,j)
		else:
			index=0
			if(j/2 in pageA.values()):
				index=pageA.keys()[pageA.values().index(j/2)]
			elif(j/2 in pageB.values()):
				index=pageB.keys()[pageB.values().index(j/2)]
			if(j%2==0):
                		print "-\t%d   %d\t  %c---"%(j/2,j,logic[index*2])	
			else:
	                	print "-\t%d   %d\t  %c---"%(j/2,j+1,logic[index*2+1])
	print ("FreeFrameList[%d]:"+ str(freeFrameList)) %len(freeFrameList)
step1()
step2()
step3()
