#include <bits/stdc++.h>
using namespace std;

int main(){
	 double arry[101][101]={0};
    int w, h;
     int maxx,x1,x2,x3,x4;

	cin>>w>>h;	
	cin>>maxx; 
	for(int i=0;i<maxx;i++){
		cin>>x1>>x2>>x3>>x4;
	
		if(x1==x3){
			if(x2>x4) arry[x1][x2]=-1;
			else arry[x3][x4]=-1;
		}
		else{
			if(x1>x3) arry[x1][x2]=-2;
			else arry[x3][x4]=-2;
		}
	}

	  for(int i=0;i<=w;i++){
		for(int j=0;j<=h;j++){
			if(i==0 && j==0) arry[i][j]=1;
			else{

				if(arry[i][j]==0){
					if(j!=0) arry[i][j]+=arry[i][j-1];
					if(i!=0) arry[i][j]+=arry[i-1][j];
				
				}
				else if(arry[i][j]==-1){

					if(i==0) arry[i][j]=0;
					else arry[i][j]=arry[i-1][j];
				}
				else if(arry[i][j]==-2){

					if(j==0) arry[i][j]=0;
					else arry[i][j]=arry[i][j-1];
				}
			}
		}
	}

	cout<<arry[w][h]<<endl;
}
