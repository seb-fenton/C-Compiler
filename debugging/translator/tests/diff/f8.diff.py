4,6c4,6
<     global x
<     x=x+1
<     return x
---
> 	global x
> 	x=x+1
> 	return x
9,16c9
<     return f()+f()
< 
< # Boilerplate
< if __name__ == "__main__":
<     import sys
<     ret=main()
<     sys.exit(ret)
< 
---
> 	global x
