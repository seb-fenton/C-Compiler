4,6c4,5
<     global x
<     x=x+1
<     return x
---
> 	x=x+1
> 	return x
9,16d7
<     return f()+f()
< 
< # Boilerplate
< if __name__ == "__main__":
<     import sys
<     ret=main()
<     sys.exit(ret)
< 
