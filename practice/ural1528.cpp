/*g(n) = n
 *f(n) = n!
 *a1*a2 % b = ((a1 %b) * a2)%b
 */
 
 #include<iostream>
 using namespace std;
 
 
 int main(){
 	while(true){
 		long long n,p;
 		cin >> n >> p;
 		if(n == 0 and p == 0) break;
 		long long f = 1;
 		for(long long i = 2; i <= n; ++ i){
 			
 			f = ((i)%p)* f%p; 
 		}
 		cout << f << endl;
 		
 	}
 	return 0;
 }