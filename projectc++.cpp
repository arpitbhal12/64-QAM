#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <fstream>
#include"stdlib.h"
#include <stdio.h>
using namespace std;

//#define endl "\n"
#define pi 3.1415926535
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
//#define mod 1000000007
#define inf 1000000000000000001;
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb pop_backn;i++
#define pb push_back
#define F first
#define S second

int main()
{
	FILE *fp,*f;
	
	// reading the image file
	fp = fopen("Cameraman.bmp","rb");
	
	vector<char> image;	
   	do 
    {
      image.push_back((char)fgetc(fp));
    } while(!feof(fp));
    
    // conversion to binary
    vector<ll> ascii;
    for(ll i=0;i<image.size();i++){
    	ascii.push_back((ll)image[i]+128);
	}
    	
    vector<ll> binary;
    
	for(ll i=0;i<ascii.size();i++)	
	{
		ll a=ascii[i];
		ll len=binary.size();
		ll t=0;
		while(a||t<8)
		{
			binary.push_back(a%2);
			a=a/2;
			t++;	
		}
		reverse(binary.begin()+len,binary.end());			
	}
	
	// 64 QAM modulation.
	vector<ll> modu;
	for(ll i=0;i<binary.size()/6;i=i+1)
	{	
		
		if(binary[i*6]==0 && binary[(i*6)+1]==0 && binary[(i*6)+2]==0)	modu.push_back(1);
			
		
		else if(binary[i*6]==0 && binary[(i*6)+1]==0 && binary[(i*6)+2]==1)	modu.push_back(3);
		
		else if(binary[i*6]==0 && binary[(i*6)+1]==1 && binary[(i*6)+2]==0)	modu.push_back(5);
		
		else if(binary[i*6]==0 && binary[(i*6)+1]==1 && binary[(i*6)+2]==1)	modu.push_back(7);
		else if(binary[i*6]==1 && binary[(i*6)+1]==0 && binary[(i*6)+2]==0)	modu.push_back(-1);
		
		else if(binary[i*6]==1 && binary[(i*6)+1]==0 && binary[(i*6)+2]==1) modu.push_back(-3);
		
		else if(binary[i*6]==1 && binary[(i*6)+1]==1 && binary[(i*6)+2]==0) modu.push_back(-5);

		else if(binary[i*6]==1 && binary[(i*6)+1]==1 && binary[(i*6)+2]==1) modu.push_back(-7);
	
		
		if(binary[(i*6)+3]==0 && binary[(i*6)+4]==0 && binary[(i*6)+5]==0) modu.push_back(1);
			
		
		else if(binary[(i*6)+3]==0 && binary[(i*6)+4]==0 && binary[(i*6)+5]==1) modu.push_back(3);
		
		else if(binary[(i*6)+3]==0 && binary[(i*6)+4]==1 && binary[(i*6)+5]==0) modu.push_back(5);
		
		else if(binary[(i*6)+3]==0 && binary[(i*6)+4]==1 && binary[(i*6)+5]==1) modu.push_back(7);
		
		else if(binary[(i*6)+3]==1 && binary[(i*6)+4]==0 && binary[(i*6)+5]==0) modu.push_back(-1);
		
		else if(binary[(i*6)+3]==1 && binary[(i*6)+4]==0 && binary[(i*6)+5]==1) modu.push_back(-3);
		
		else if(binary[(i*6)+3]==1 && binary[(i*6)+4]==1 && binary[(i*6)+5]==0) modu.push_back(-5);
		
		else if(binary[(i*6)+3]==1 && binary[(i*6)+4]==1 && binary[(i*6)+5]==1) modu.push_back(-7);
			
	}
	
	ll temp=modu.size()%6;
	ll left=6-temp;
	
	for(ll i=0;i<left;i++)	modu.push_back(1);
	
	ofstream qamdata;
	qamdata.open("QAMDATA.txt");
	qamdata<< "TEXT" <<endl;
	
	
	for(ll i=0;i<modu.size();i+=6) qamdata<<modu[i]<<", "<<modu[i+1]<<", "<<modu[i+2]<<", "<<modu[i+3]<<", "<<modu[i+4]<<", "<<modu[i+5]<<endl;
	
	qamdata.close();
	
	
	// demodulation of received signal 
	vector<ll> recon;
	for(ll i=0;i<modu.size()/2;i=i+1){	

		if(modu[i*2]==1){
			recon.push_back(0);
			recon.push_back(0);
			recon.push_back(0); 
		}
		
		
		else if(modu[i*2]==3){
			recon.push_back(0);
			recon.push_back(0);
			recon.push_back(1); 
		}
		
		
		
		else if(modu[i*2]==5){
			recon.push_back(0);
			recon.push_back(1);
			recon.push_back(0); 
		}
		
		
		
		else if(modu[i*2]==7){
			recon.push_back(0);
			recon.push_back(1);
			recon.push_back(1); 
		}
		
		
		
		else if(modu[i*2]==-1){
			recon.push_back(1);
			recon.push_back(0);
			recon.push_back(0); 
		}
		
		
		
		else if(modu[i*2]==-3){
			recon.push_back(1);
			recon.push_back(0);
			recon.push_back(1); 
		}
		
		
		
		else if(modu[i*2]==-5){
			recon.push_back(1);
			recon.push_back(1);
			recon.push_back(0); 
		}
		
		
		
		else if(modu[i*2]==-7){
			recon.push_back(1);
			recon.push_back(1);
			recon.push_back(1); 
		}
		
		
		if(modu[(i*2)+1]==1){
			recon.push_back(0);
			recon.push_back(0);
			recon.push_back(0); 
		}
		
		
		
		else if(modu[(i*2)+1]==3){
			recon.push_back(0);
			recon.push_back(0);
			recon.push_back(1); 
		}
		
		
		
		else if(modu[(i*2)+1]==5){
			recon.push_back(0);
			recon.push_back(1);
			recon.push_back(0); 
		}
		
		
		
		else if(modu[(i*2)+1]==7){
			recon.push_back(0);
			recon.push_back(1);
			recon.push_back(1); 
		}
		
		
		
		else if(modu[(i*2)+1]==-1){
			recon.push_back(1);
			recon.push_back(0);
			recon.push_back(0); 
		}
		
		
		
		else if(modu[(i*2)+1]==-3)
		{
			recon.push_back(1);
			recon.push_back(0);
			recon.push_back(1); 
		}
		
		
		
		else if(modu[(i*2)+1]==-5){
			recon.push_back(1);
			recon.push_back(1);
			recon.push_back(0); 
		}
		
		
		
		else if(modu[(i*2)+1]==-7){
			recon.push_back(1);
			recon.push_back(1);
			recon.push_back(1); 
		}
		
		
		
    }
	
    
	// rewriting the reconeived signal in a .bmp file
	vector<ll>deci;
	for(ll i=0;i<image.size()*8;i+=8)
	{	
		ll ye=0;
		ye+=recon[i]*pow(2,7);
		
		ye+=recon[i+1]*pow(2,6);
		
		ye+=recon[i+2]*pow(2,5);
		
		ye+=recon[i+3]*pow(2,4);
		
		ye+=recon[i+4]*pow(2,3);
		
		ye+=recon[i+5]*pow(2,2);
		
		ye+=recon[i+6]*pow(2,1);
		
		ye+=recon[i+7]*pow(2,0);
		deci.push_back(ye);	
		//cout<<t<<" "<<endl;
	}

	ll n = image.size();
	
	vector<char> finim;
	
	for(ll i=0;i<n;i++) finim.push_back((deci[i]-128));
			
	
	FILE *f2;
	f2=fopen("camer.bmp","wb");
	for(ll i=0;i<finim.size();i++) fputc(finim[i],f2);
	fclose(f2);


	
}
