
int f(){
	int x[5];
	int *a = x + 2;
	x[2] = 3;
	return *a;
}
