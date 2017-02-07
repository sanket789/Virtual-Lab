#include<iostream.h>
#include<math.h>
#include<stdio.h>
#include<iomanip.h>
#include<conio.h>
double parallelfunction(double ,double ,double , double , double);

int main()
{
	double x[2],y[2],eta[2],psi[2],sum , z;
	int i,j,k,l;
    sum=0;
	cout<<"Enter x values"<<endl;
	for(i=0; i<2; i++)
	{
		cin>>x[i];
	}
	cout<<"Enter y values"<<endl;
	for(i=0; i<2; i++)
	{
		cin>>y[i];
	}
	cout<<"Enter eta values"<<endl;
	for(i=0; i<2; i++)
	{
		cin>>eta[i];
	}
	cout<<"Enter psi values"<<endl;
	for(i=0; i<2; i++)
	{
		cin>>psi[i];
	}
	cout<<"Enter z"<<endl;
	cin>>z;
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			for(k=0; k<2; k++)
			{
				for(l=0; l<2; l++)
				{
					sum = sum + parallelfunction(x[i],y[j],eta[k],psi[l],z)*pow(-1,i+j+k+l);
				}
			}
		}
	}
	sum = abs (sum/((x[1]-x[0])*(y[1]-y[0])));
	cout<<" The view factor is"<<endl<<sum<<endl;
	getch();
    return 0;
}

double parallelfunction(double x,double y,double eta, double psi, double z)
{
	double p=0;
	double term1=(y-eta)*sqrt((x-psi)*(x-psi)+z*z)*atan((y-eta)/sqrt((x-psi)*(x-psi)+z*z));
	double term2=(x-psi)*sqrt((y-eta)*(y-eta)+z*z)*atan((x-psi)/sqrt((y-eta)*(y-eta)+z*z));
	double term3=0.5*z*z*log((x-psi)*(x-psi) + (y-eta)*(y-eta) + z*z);
	p=(term1+term2-term3)/6.28;
	return p;
}
			
