int g(int x){
    return x + 10;
}

int f(int x){
    return g(x);
}

int main(){
    int i = 0;
    return f(20) + 8;
}
