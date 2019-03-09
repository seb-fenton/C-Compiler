2,10c2,13
<     if(a<b):
<         a=a-1
<         if(a>b):
<             b=b+3
<             if(a==b):
<                 return a*b
<         return b
<     return 13
<     
---
> 
> 	if(a<b):
> 		a=a-1
> 
> 		if():
> 			b=b+3
> 
> 			if(a==b):
> 				return a*b
> 		return b
> 	return 13
> 
12c15
<     return function(0,0)+function(1,2)+function(4,3)+function(6,7)
---
> 	return function(6.9498e-310,6.9498e-310)+function(1,2)+function(4,3)+function(6,7)
16,19c19,21
<     import sys
<     ret=main()
<     sys.exit(ret)
< 
---
> 	import sys
> 	ret=main()
> 	sys.exit(ret)
\ No newline at end of file
