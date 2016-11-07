#include <stdio.h>
void merge_sort(int, int*);
void merge(int, int, const int*, const int*, int*);
int main(){
	int n, i;
	printf("배열 크기 입력 : ");
	scanf("%d",&n);
	int s[n];
	for(i=0;i<n;i++){
		printf("s[%d]의 값 입력 : ",i);
		scanf("%d",&s[i]);
	}
	merge_sort(n,s);
	printf("정렬 후\n");
	for(i=0;i<n;i++){
		printf("%d ",s[i]);
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
