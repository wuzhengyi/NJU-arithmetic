int Algorithm_7_15(int A[n]){
	int a[n], pre[n];
	for(int i=1;i<=n;i++){
		a[i] = INF;
		pre[i] = -1;
	}
	a[1] = 0;
	for(int i=2;i<=n;i++){
		for(int j=i-1;A[i]-A[j]<=200;j--){
			if(a[j] + (200-A[i]+A[j])*(200-A[i]+A[j]) < a[i]){
				a[i] = a[j] + (200-A[i]+A[j])*(200-A[i]+A[j]);
				pre[i] = j;
			}
		}
	}
	return a[n];
}

bool Algorithm_7_1(int A[n], int S){
	bool temp[1……n][1……S];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=S;j++){
			if(i == 1){
				if(A[i] == j)
					temp[i][j] = true;
				else
					temp[i][j] = false;
			}
			else{
				if(A[i] > j)
					temp[i][j] = temp[i-1][j];
				else
					temp[i][j] = temp[i-1][j] | temp[i-1][j-A[i]];
			}
		}
	}
	return temp[n][S];
}

bool Algorithm_7_2(int A[n]){
	bool temp[1……n];
	temp[1] = 0;
	for(int i=2;i<=n;i++){
		if(i%3 == 0)
			temp[i] = temp[i/3] + 1;
		else if(i%2 == 0)
			temp[i] = temp[i/2] + 1;
		else
			temp[i] = temp[i-1] + 1;
	}
	return temp[n];
}

int LISS(int array[n]){  
    int i, j, k, max;  
    int liss[n];  
    int pre[n];  
  
    for(i = 0; i < n; ++i){  
        liss[i] = 1;  
        pre[i] = i;  
    }  
  
    for(i = 1, max = 1, k = 0; i < n; ++i){  
        for(j = 0; j < i; ++j){  
            if(array[j] <= array[i] && liss[j] + 1> liss[i]){  
                liss[i] = liss[j] + 1;  
                pre[i] = j;  
  
                if(max < liss[i]){  
                    max = liss[i];  
                    k = i;  
                }  
            }  
        }  
    }  
    return max;  
}  

int p(char a, char b){
	return (a == b)? 1 : 2;
}

int Algorithm_7_6(char A[m], char B[n]){
	int a[m+1][n+1];
	for(int i = 0; i <= m; i++)
		a[i][0] = i;
	for(int j = 0; j<= n; j++)
		a[0][j] = j;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j<= n; j++)
			a[i][j] = max{a[i-1][j] + 1, a[i-1][j-1] + p(A[i],B[j]), a[i][j] + 1};
	}
	return a[m][n];
}
int Algorithm_7_8(char T[n]){
	int a[n][n];
	for(int i = 1; i < n; i++){
		a[i][1] = (T[i]==T[1])?1 : 0;
		a[1][i] = (T[1]==T[i])?1 : 0;
	}
	for(int i = 2; i <= n; i++){
		for(int j = 2; j+i < n+1; j++)
			a[i][j] = (T[i]==T[j])? T[i-1][j-1] + 1 : 0;
	}
	return a[m][n];
}

int Algorithm_7_11(int i, int j){
	if(a[i][j] is calculated)
		return a[i][j];
	if(there is no m between i to j)
		a[i][j] = 0;
	else{
		int min = INF;
		for(all m form i to j){
			if(min > a[i][m] + a[m+1][j] + cost(i,j,m))
				min = a[i][m] + a[m+1][j] + cost(i,j,m);
		}
		a[i][j] = min;
	}
	return a[i][j];
}

int calculated_have_root(node u){
	if(u == NULL)
		return 0;
	if(a[u][1] is not calculated){
		int m1 = min(calculated_have_root(i.lchild),calculate_no_root(l.lchild));
		int m2 = min(calculated_have_root(i.rchild),calculate_no_root(l.rchild));
		a[u][1] = 1 + m1 + m2;
	}
	return a[u][1];
}
int calculate_no_root(node u){
	if(u == NULL)
		return 0;
	if(a[u][0] is not calculated)
		a[u][0] = calculated_have_root(u.lchild)+calculated_have_root(u.rchild);
	return a[u][0];	
}

int Algorithm_7_13(V, E, root){
	int a[n][2];
	calculate_no_root(root);
	calculated_have_root(root);
	return min(a[n][0],a[n][1]);
}

int Algorithm_7_15(int A[n]){
	int a[n], pre[n];
	for(int i=1;i<=n;i++){
		a[i] = INF;
		pre[i] = -1;
	}
	a[1] = 0;
	for(int i=2;i<=n;i++){
		for(int j=i-1;A[i]-A[j]<=200;j--){
			if(a[j] + (200-A[i]+A[j])*(200-A[i]+A[j]) < a[i]){
				a[i] = a[j] + (200-A[i]+A[j])*(200-A[i]+A[j]);
				pre[i] = j;
			}
		}
	}
	return a[n];
}

int Algorithm_7_17(){
	int a[n][n];
	for(int i=n;i>=1;i--)
		for(int j=n;j>=1;j--){
			a[i][j]=score[i][j];
			if(i == n && j == n)
				continue;
			else if(i == n && j != n)
				a[i][j] = max{a[i][j+1] + a[i][j], a[i][j]};
			else if(i != n && j == n)
				a[i][j] = max{a[i+1][j] + a[i][j], a[i][j]};
			else
				a[i][j] = max{a[i+1][j] + a[i][j], a[i][j+1] + a[i][j]};
		}
}
