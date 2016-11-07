#include <stdio.h>
#include <time.h>
void merge_sort(int, int*);
void merge(int, int, const int*, const int*, int*);
int main(){
	int a[3001],n[24];
	int i,j,k;
	long b;
	const long r[24] = {300000,300000,200000,200000,100000,100000,100000,80000,80000,50000,50000,25000,15000,15000,10000,7500,7000,6000,5000,5000,3000,2000,2000,1000};
	for(i=1;i<=3000;i++)
		a[i] = 3001-i;
	for(j=0;j<10;j++){
		n[j] = 10*j;
		n[j+10] = 100*(j+1);
	}
	n[20] = 1500;
	n[21] = 2000;
	n[22] = 2500;
	n[23] = 3000;

	printf("    n   totalTime     runTime\n");
	for(int k=0;k<24;k++){
		clock_t start, stop;
		start = clock();
		for(b = 1;b<=r[k];b++)
			merge_sort(n[k],a+1);
		stop = clock();
		clock_t totalTime = stop-start;
		double runTime = (double)totalTime/(double)(r[k]);
		printf(" %4d %11d %11lf\n",n[k],totalTime,runTime);
	}
	return 0;
}
void merge_sort(int n, int s[]){
	int i,j = 0;
	if(n>1){
		const int h = n/2, m = n-h;
		int u[h],v[m];
		for(i=0;i<h;i++){
			u[i] = s[j];
			j++;
		}
		for(i=0;i<m;i++){
			v[i] = s[j];
			j++;
		}
		merge_sort(h,u);
		merge_sort(m,v);
		merge(h,m,u,v,s);
	}
}
void merge(int h, int m, const int u[], const int v[], int s[]){
	int i = 0, j = 0, k = 0, l = 0;
	while(i < h && j < m){
		if(u[i] < v[j]){
			s[k] = u[i];
			i++;
		}
		else{
			s[k] = v[j];
			j++;
		}
		k++;
	}
	if(i>=h){
		for(l = j;l<m;l++){
			s[k] = v[l];
			k++;
		}
	}
	else{
		for(l=i;l<h;l++){
			s[k] = u[i];
			k++;
		}
	}
	return;
}
