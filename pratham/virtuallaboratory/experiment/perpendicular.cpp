#include<iostream.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>

double parallelfunction(double ,double ,double , double );

int main()
{
	double x[2],y[2],eta[2],psi[2],sum;
	int i,j,k,l;
    sum = 0;
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
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			for(k=0; k<2; k++)
			{
				for(l=0; l<2; l++)
				{
					sum = sum + parallelfunction(x[i],y[j],eta[k],psi[l])*pow(-1,i+j+k+l);
				}
			}
		}
	}
	sum=abs(sum/((x[1]-x[0])*(y[1]-y[0])));
    cout<<sum<<endl;
    getch();
	return 0;
}		

double parallelfunction(double x,double y,double eta, double psi)
{
	double p=0;
	double k,term1,term2;
	if(y!=eta && (x*x+psi*psi)!=0)
	{
          k=(y-eta)/sqrt(x*x + psi*psi);
	      term1=(y-eta)*sqrt(x*x + psi*psi)*atan(k);
	      term2=0.25*((x*x + psi*psi)*log(1+k*k)-(y-eta)*(y-eta)*log(1+1/(k*k)));
	      p = (term1-term2)/6.28;
    }
    return p;
}
			
