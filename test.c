int f2(int *a){
    a = a + 2;
    return *a;
}

int f(){
    int x[5];
    x[0] = 3;
    x[1] = 5;
    x[2] = 7;
    x[3] = 8;
    x[4] = 9;
    int *p = x;
    return f2(p);
}

