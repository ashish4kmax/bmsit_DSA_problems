#include <stdio.h>
#include <stdlib.h>
int a[20][20], reach[20], n;

void dfs(int v) {
	int i;
	reach[v]=1;
	for(i=1;i<=n;i++) {
		if(a[v][i] && !reach[i]) {
			printf("\n %d->%d",v,i);
			dfs(i);
		}
	}
}

void main() {
	int i, j, count=0;
	printf("\nEnter no. of vertices : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		reach[i]=0;
	}
	
	printf("\nEnter the adjacency matrix : \n");
	for(i=1;i<=n;i++) 
		for(j=1;j<=n;j++) 
			scanf("%d",&a[i][j]);
	dfs(1);
	printf("\n");
	for(i=1;i<=n;i++) {
		if(reach[i]) 
			count++;
	}
	if(count==n) {
		printf("\nGraph is connected!!");
	}
	else {
		printf("\nGraph is not connected!!");
	}	
}
