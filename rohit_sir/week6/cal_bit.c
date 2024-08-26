int addBit(int a, int b){
    int ans = 0, i = 0;
    int carry = 0;
    while(a | b | carry){
        int x = a & 1;
        int y = b & 1;

        int digit = x ^ y ^ carry;
        carry = (x & y) | (carry & (x ^ y));

        ans = ans | (digit << i);

        a = a >> 1; b = b >> 1;
        i++;
    }
}
int subBit(int a, int b){
    return a - b;
}
int mulBit(int a, int b){
    return a * b;
}
int divBit(int a, int b){
    return a / b;
}