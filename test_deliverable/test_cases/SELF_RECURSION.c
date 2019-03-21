int SELF_RECURSION(int x){
    if (x < 0) return SELF_RECURSION(++x);
    else return x;
}