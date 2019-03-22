int break_continue_func(){
    int x = 0;
    int y = 0;
    while(1){
        break;
    }
    while(y < 1){
        if(x == 0){ 
            continue;
            y++;
        }
        x = 1;
    }
    return x;
}