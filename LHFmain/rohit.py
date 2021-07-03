import csv
#%matplotlib inline
import matplotlib.pyplot as plt
import numpy as np
x1 = []
x2 = []
x3 = []

y1 = []
y2 = []
y3 = []

counter1 = []
counter2 = []
counter3 = []
inputfile = "output.csv"
y=0
blarge = 0
dlarge = 0
lines_count = 0
colors = ["Blue","Red","Green","Black"]
#with open('output.csv', mode='rt') as f, open('outputsorted.csv', 'w', newline='') as final:
#    writer = csv.writer(final, delimiter=',')
#    reader = csv.reader(f, delimiter=',')
#    sorted2 = sorted(reader, key=lambda row: (int(row[1]), float(row[3])))       
#    for row in sorted2:
#        writer.writerow(row)

with open(inputfile, mode ='r')as file:
    # reading the CSV file
    csvFileb = csv.reader(file)
    # displaying the contents of the CSV file
    for lines in csvFileb:
        lines_count = lines_count + 1
        if(int(lines[0]) == 0 and float(lines[2])!=.08):
            x1.append(float(lines[1]))
            y1.append(float(lines[2]))
            counter1.append(y)
        if(int(lines[0]) == 1):
            x2.append(float(lines[1]))
            y2.append(float(lines[2]))
            counter2.append(y)
        if(int(lines[0]) == 2):
            x3.append(float(lines[1]))
            y3.append(float(lines[2]))
            counter3.append(y)
        if(float(lines[2])>dlarge):
            dlarge = float(lines[2])
        if(float(lines[1])>blarge):
            blarge = float(lines[1])
        y=y+1

X_dim = []
X_dim.append(x1)
X_dim.append(x2)
X_dim.append(x3)

Y_dim = []
Y_dim.append(y1)
Y_dim.append(y2)
Y_dim.append(y3)

counter = []
counter.append(counter1)
counter.append(counter2)
counter.append(counter3)

for dim in [0,1,2]:
     plt.scatter(X_dim[dim], Y_dim[dim],color=colors[dim],s=6)
plt.axline([0, 0], [.12, .12],linewidth=1,color="black")

plt.savefig("persistence.png")
for dim in [0,1,2]:
    plt.plot([X_dim[dim], Y_dim[dim]], [counter[dim], counter[dim]],color=colors[dim],linestyle='solid',linewidth=1)

plt.savefig("barcodes.png")
	
