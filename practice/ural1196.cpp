#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
long n,m,t[15001],count=0;

bool find(long k,long l,long r){
 	long mid=(l+r)/2;
 	if(t[mid]==k) return true;
 	if(r<=l) return false;
 	else{
  		if(k<t[mid]) return find(k,l,mid-1);
  		else return find(k,mid+1,r);
 	}
}
int main(){
 	
 	scanf("%ld",&n);
 	for(long i=1;i<=n;i++) scanf("%ld",&t[i]);
 	
 	scanf("%ld",&m);
 	for(long i=1;i<=m;i++){
  		long tmp;
  		
  		scanf("%ld",&tmp);
  		if(find(tmp,1,n)) count++;
 	}
 	
 	printf("%ld\n",count);
 	return 0;
}