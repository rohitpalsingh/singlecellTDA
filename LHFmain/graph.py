import csv
import matplotlib.pyplot as plt
import numpy as np
import random

numpoints = 200


outfile = "S.csv"

inputPointsX = []
inputPointsY = []

#inputPointsXnormal = []
#inputPointsYnormal = []
#check=0
#minimX = 9999999999999
#maximX = 0
#minimY = 9999999999999
#maximY = 0
#with open("S2.csv", mode ='r')as file:
#    # reading the CSV file
#    csvFileb = csv.reader(file)
#    # displaying the contents of the CSV file
#    for lines in csvFileb:
#        lines = lines[0].split()
#        inputPointsX.append(float(lines[0]))
#        if(minimX > float(lines[0])):
#            minimX = float(lines[0])
#        if(maximX < float(lines[0])):
#            maximX = float(lines[0]) 
#        inputPointsY.append(float(lines[1]))
#        if(minimY > float(lines[1])):
#            minimY = float(lines[1])
#        if(maximY < float(lines[1])):
#            maximY = float(lines[1])

#print(minimX,minimY,maximX,maximY)
#for x in inputPointsX:
#    inputPointsXnormal.append((x-minimX)/(maximX-minimX))
#   
#for y in inputPointsY:
#    inputPointsYnormal.append((y-minimY)/(maximY-minimY))
#numpoints = 1000
#inputPointsX = inputPointsXnormal
#inputPointsY = inputPointsYnormal
#
#rows  = zip(inputPointsX,inputPointsY)
#with open("S.csv","w") as f:
#	writer = csv.writer(f)
#	for row in rows:
#		writer.writerow(row)
#
fig, axs = plt.subplots(1,1)
fig.suptitle('Dimension wise Plots')
for xy in range(0,1):
	inputfileMatrix = "incedenceMatrix"+str(xy)+".csv"
	incedenceMatrix = []

	#generate random number between 0 and 1

	#for x in range(0,numpoints):
	#    inputPointsX.append(random.uniform(0, 1))
	#    inputPointsY.append(random.uniform(0, 1))

	#with open(outfile, 'w', encoding='UTF8') as f:
	#    writer = csv.writer(f)
	#    for x in range(0,len(inputPointsX)):
	#        data = []
	#        data.append(inputPointsX[x])
	#        data.append(inputPointsY[x])
	#        writer.writerow(data)
	check = 0
	with open(outfile, mode ='r', encoding='utf-8-sig')as file:
	    # reading the CSV file
	    csvFileb = csv.reader(file)
	    # displaying the contents of the CSV file
	    for lines in csvFileb:
	        if(check%2 ==0):
	            inputPointsX.append(lines[0])
	            inputPointsY.append(lines[1])
	        check = check+1
	

	#with open('output.csv', mode='rt') as f, open('outputsorted.csv', 'w', newline='') as final:
	#    writer = csv.writer(final, delimiter=',')
	#    reader = csv.reader(f, delimiter=',')
	#    sorted2 = sorted(reader, key=lambda row: (int(row[1]), float(row[3])))       
	#    for row in sorted2:
	#        writer.writerow(row)
	count = 0
	with open(inputfileMatrix, mode ='r', encoding='utf-8-sig')as file:
	    # reading the CSV file
	    csvFileb = csv.reader(file)
	    # displaying the contents of the CSV file
	    for lines in csvFileb:
	        lines = lines[0].split()
	        count = len(lines)
	        incedenceLine = []
	        for x in range(0,count):
	            incedenceLine.append(lines[x])
	        incedenceMatrix.append(incedenceLine)
	x1 = []
	x2 = []
	y1 = []
	y2 = []
	for x in range(0,count):
	    for y in range(0,count):
	        if(float(incedenceMatrix[x][y])==1):
	            x1.append(float(inputPointsX[x]))
	            y1.append(float(inputPointsY[x]))
	            x2.append(float(inputPointsX[y]))
	            y2.append(float(inputPointsY[y]))
	t,p = divmod(xy,4)
	axs[t,p].plot([x1, x2], [y1, y2],color='blue',linestyle='solid',linewidth=1)
	
fig.savefig("ConnectivityGraph.png")
	
