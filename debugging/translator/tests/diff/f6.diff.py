1d0
< 
3,6c2,5
<     x=0
<     x=5
<     x=x*x
<     return x
---
> 	x=0
> 	x=5
> 	x=x*x
> 	return x
10,13c9,11
<     import sys
<     ret=main()
<     sys.exit(ret)
< 
---
> 	import sys
> 	ret=main()
> 	sys.exit(ret)
\ No newline at end of file
