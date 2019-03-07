4,5c4,6
<     x=1
<     return x
---
> 	global x
> 	x=1
> 	return x
9,12c10,12
<     import sys
<     ret=main()
<     sys.exit(ret)
< 
---
> 	import sys
> 	ret=main()
> 	sys.exit(ret)
\ No newline at end of file
