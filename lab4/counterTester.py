# Lab 4

from counterlib import *

# instantiate class to produce an object of the class
myCnt = counter(100)
print(myCnt.getState())

x = counter(1000)
print(x.getState())

y = counter(50)
print(y.getState())

myCnt.evolve(100)
print(myCnt.getState())

x.evolve(105)
print(x.getState())

y.evolve(110)
print(y.getState())