#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
}

void randData(double *dPtr,int N , int M){
	for(double i = 0;i<49 ; i++){
			*dPtr = rand()%100;
			*dPtr/=100;

			dPtr+=1;
	}
}
void showData(double *data , int N , int M){
	for(int i = 0 ; i<N ; i++){
		for(int j = 0 ; j<M;j++){
			cout<< *data <<" ";
			if(*data == 0.9 || *data == 0.8 || *data == 0.7 || *data == 0.6 || *data == 0.5 || *data == 0.4 || *data == 0.3 || *data == 0.2 || *data == 0.1 )cout<<" ";
			else if(*data == 0)cout<< "   ";

			data+=1;
		}
		cout<<"\n";
	}
}

void findColSum(const double *dPtr,double *result,int N,int M){
	double sum = 0;
	int count = 0;
	for(double i = 0;i<49 ; i++){
		sum+= *dPtr;
		dPtr+=7;
		count++;
		if(count > 6){
			*result = sum;
			sum = 0;
			result+=1;
			dPtr-=7*count;
			count = 0;
			dPtr+=1;
		}
	}
}
