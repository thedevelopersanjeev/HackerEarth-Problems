class Solution:
	def power(self, A) :
		x = int(A)
		    if (x is 1) :
			    return 0
			           if (x & (x - 1)) :
				           return 0
				                  return 1