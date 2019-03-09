double atof(const char *str);

double test(){

    char str[11] = {'2', '.', '7', '1', '8', '2', '8', '1', '8', '2', '8'};
    return atof(str);
}