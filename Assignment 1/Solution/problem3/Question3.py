import numpy as np
from numpy.linalg import inv 
import pylab as pl

T = int(raw_input(""))
v1 = np.zeros(shape=(T))
v2 = np.zeros(shape=(T))
for w in xrange(T):
	N = int(raw_input(""))
	mat = np.zeros(shape=(N, N))
	delta = np.zeros(shape=(N, N))
	mat1 = np.zeros(shape=(N, N))

	for i in xrange (N):
		s=raw_input("")
		s=s[:-1]
		mat[i]=s.split(' ');
	#print mat

	b=raw_input("")
	b=b[:-1]
	b=b.split(' ');


	for i in xrange (N):
		s=raw_input("")
		s=s[:-1]
		delta[i]=s.split(' ');

	for i in xrange (N):
		for j in xrange (N):
			mat1[i][j]=mat[i][j]+delta[i][j]
	#print mat1
	#print np.linalg.inv(mat)
	x1=np.linalg.solve(mat,b)
	x2=np.linalg.solve(mat1,b)


	v1[w]=np.linalg.cond(mat,1)
	v2[w]=np.linalg.norm(x2-x1,2)/np.linalg.norm(x1)

	print v1[w],
	print v2[w]
#pl.xlabel("Condition number")
#pl.ylabel("Change")
#pl.plot(v1,v2)
#pl.show()
