int Fib (int n){
int i1 = 1, i2 = 1, tmp;
	while(n-- > 2){
	tmp=i1+i2;
	i2=i1;
	i1=tmp;
	}
return i1;
}
