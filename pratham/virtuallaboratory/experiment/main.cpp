#include <iostream>
#include "face.h"


using namespace std;
  
  
    struct nbour
	{
        float lthnve;
        float lthpve;
        float bthnve;
        float bthpve;
        float thicknessnve;
        float thicknesspve;
	};

	struct rad
	{
		float alpha;
		float epsilon;
		float *tempamb;
		float vfactor;
		bool i;
	};
	
	struct thicknessneighbour
	{
		bool i;
	};
	
	struct intrad
	{
		float alpha,epsilon;
		float vfactor;
		bool i;
	};
	
	struct fluxc
	{
		float fluxvalue;
		bool i;
	};
	
	struct fluxv
	{
		float *time;
		float *flux;
		bool  i;
	};
	
	struct boundtemp
	{
		float boundarytemp;
		bool i;
	};
	
	struct initemp
	{
		float initialtemp;
		bool i;
	};
	
   struct load
   {
		rad radiation;
		intrad internalradiation;
		fluxc fluxconstant;
		fluxv fluxvariable;
		initemp initialtemperature;
		boundtemp boundarytemperature;
		thicknessneighbour thicknessnbour;
	};

	struct elementprop
	{
		nbour enbour;
		identity eidentity;
		dirn ecentre;
		load eload;
		int eserialid;
		float eflux;
		float temp[1000];
		float area;
		float thickness;
		float density;
		float spheat;
	};

	
	float thicknessnbourf(dirn centre,int faceid1,face *f, int m1,int n1)
	{
		int i,j;
		float retval = 0;
		if(faceid1!=0)
		{		
			dirn centre1;
            identity eidentity1;
			for(i=1;i<=m1;i++)
			{
				for (j=1;j<=n1;j++)
				{		
					eidentity1.i=i;
					eidentity1.j=j;
					eidentity1.faceid=faceid1;
					centre1 = f[eidentity1.faceid].centref(eidentity1);
					
					if(f[faceid1].normal.x == 1 || f[faceid1].normal.x == -1)
					{
						if(centre1.z == centre.z && centre1.y == centre.y )
						    retval = 100*eidentity1.i + eidentity1.j +eidentity1.faceid/100;
				   	};
				   
					if(f[faceid1].normal.y == 1 || f[faceid1].normal.y == -1)
					{
						if(centre1.z == centre.z && centre1.x == centre.x )
							retval = 100*eidentity1.i + eidentity1.j +eidentity1.faceid/100;
					};
				    
					if(f[faceid1].normal.z == 1 || f[faceid1].normal.z == -1)
					{
						if(centre1.x == centre.x && centre1.y == centre.y )
							retval = 100*eidentity1.i + eidentity1.j +eidentity1.faceid/100;	
					};
				  
					if(retval!=0)
					  break;
				};
				
				if(retval!=0)  break;
			};
		};
		return retval;
	};
    

	nbour neighbour(identity eidentity,int noof_faces, face *f)
	{
        nbour node;
        int fa=noof_faces;
        int faceid=eidentity.faceid;
	    int m=f[faceid].m;
		int n=f[faceid].n;
        int nl=eidentity.i; 
		int nb=eidentity.j; 
		float faceidinfloat = faceid;
		float decpart= faceidinfloat/100;
	    
		if(nl==1)
            node.lthnve= f[faceid].intersection(eidentity,fa,f,1,0);
        else
            node.lthnve=100*(nl-1)+nb+decpart;
        
		if(nl==m)
            node.lthpve= f[faceid].intersection(eidentity,fa,f,m,0);
        else
            node.lthpve=100*(nl+1)+nb+decpart;
        
		if(nb==1)
            node.bthnve= f[faceid].intersection(eidentity,fa,f,0,1);
		else
            node.bthnve=100*nl+(nb-1)+decpart;
        
		if(nb==n)
              node.bthpve= f[faceid].intersection(eidentity,fa,f,0,n);
        else
            node.bthpve=100*nl+(nb+1)+decpart;
	
        node.thicknessnve= 0;
              node.thicknesspve =0;
		
		return node;      
	};
                 

	identity *selectface(face *f,identity *selectedelementidentity)
	{
        int noof_faces;
		int selectedfaceid[10];
		cout<<"input noof faces under consideration"<<endl;
        cin>>noof_faces;
		int k=0,m,n;
        for(int z=1;z<=noof_faces;z++)
		{
			cout<<"enter the faceids "<<endl;
			cin>>selectedfaceid[z];
			m = f[selectedfaceid[z]].m;
			n = f[selectedfaceid[z]].n;
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=n;j++)
				{
					selectedelementidentity[k].faceid=selectedfaceid[z];
					selectedelementidentity[k].i=i;
					selectedelementidentity[k].j=j;
					k++;
				};
			};
		};
			   
		int noof_elements,z;
		cout<<"enter noof individual elements"<<endl;
		cin>>noof_elements;
		cout<<"enter element's i j n faceid"<<endl;
		
		for ( z=k;z<noof_elements+k;z++)
		{
           cin>>selectedelementidentity[z].i;
		   cin>>selectedelementidentity[z].j;
		   cin>>selectedelementidentity[z].faceid;
		};
		
		cout<<"total noof selected elements tbu l8r = "<<z<<endl;
		return selectedelementidentity;
	};

	void readloadf(int fa,face *f,elementprop *elementproperties,int noof_elements)
	{               
		identity *selectedelement1;
		identity *selectedelement2;
		identity *selectedelement3;
		selectedelement1 = new identity[100];
		selectedelement2 = new identity[100];
		selectedelement3 = new identity[100];
		identity *selectedelementidentity;
		selectedelementidentity = new identity[100];
		load readload;	int r1,r2,r3,r4,r5,r6,r7;	  				  
		cout<<"enter 1 for loads to be applied "<<endl;
		cout<<"rad,intrad,fluxc,fluxv,initemp,boundtemp,thicknessnbour n rest 0 for selected elements"<<endl;
		cin>>r1;
		cin>>r2;
		cin>>r3;
		cin>>r4;
		cin>>r5;
		cin>>r6;
		cin>>r7;
		
		if(r1==1)
			readload.radiation.i = true;
		else
			readload.radiation.i = false;
 
		if(r2==1)
			readload.internalradiation.i = true;
		else
			readload.internalradiation.i = false;

		if(r3==1)	 
			readload.fluxconstant.i = true;
		else
			readload.fluxconstant.i = false;
		
		if(r4==1)
			readload.fluxvariable.i = true;
		else
			readload.fluxvariable.i = false;

		if(r5==1)
			readload.initialtemperature.i = true;
		else
			readload.initialtemperature.i = false;

		if(r6==1)
			readload.boundarytemperature.i = true;
		else
			readload.boundarytemperature.i = false;

		if(r7==1)
			readload.thicknessnbour.i = true;
		else
			readload.thicknessnbour.i = false;
 
		int k,q,z,count,w,h;
 
		for(k=0;k<noof_elements;k++)
		{
			elementproperties[k].eload.fluxvariable.flux = new float[50000];
			elementproperties[k].eload.fluxvariable.time = new float[50000];
		};
	 
		if(readload.radiation.i==true)
		{
			cout<<"enter alpha,epsilon values,tempamb n viewfactor values"<<endl;
			cin>>readload.radiation.alpha;
			cin>>readload.radiation.epsilon;
			cout<<"enter no.of tempamb terms"<<endl;
			cin>>h;
			readload.radiation.tempamb = new float[50000];
			
			for(k=0;k<h;k++)
			{
				cout<<"enter amb temp values"<<endl;
				cin>>readload.radiation.tempamb[h];
			};
			
			cin>>readload.radiation.vfactor;	       
			cout<<"enter elements experiencing the load"<<endl;
			selectedelement1 = selectface(f,selectedelementidentity);
			count=0;
			cout<<"enter noof elements selected as seen by prev o/p"<<endl;
			cin>>w;
			k=-1;
	   
			while(count<w)
			{
				k++;
				for( q=0;q<w;q++)
				{
					if(elementproperties[k].eidentity.i == selectedelement1[q].i && elementproperties[k].eidentity.j == selectedelement1[q].j && elementproperties[k].eidentity.faceid == selectedelement1[q].faceid)
					{
						elementproperties[k].eload.radiation.i=true;
						elementproperties[k].eload.radiation = readload.radiation;
						count++;
					};
				};
			};
		};
 
		if(readload.internalradiation.i==true)
		{
			cout<<"enter alpha,epsilon,viewfactor"<<endl;
			cin>>readload.internalradiation.alpha;
			cin>>readload.internalradiation.epsilon;
			cin>>readload.internalradiation.vfactor;
			cout<<"enter elements experiencing the load"<<endl;
			selectedelement1 = selectface(f,selectedelementidentity);
			count=0;
			cout<<"enter noof elements selected as seen by prev o/p"<<endl;
			cin>>w;
			k=-1;
			while(count<w)
			{
				k++;
				for(q=0;q<w;q++)
				{
					if(elementproperties[k].eidentity.i == selectedelement1[q].i && elementproperties[k].eidentity.j == selectedelement1[q].j && elementproperties[k].eidentity.faceid == selectedelement1[q].faceid)
					{
						elementproperties[k].eload.internalradiation.i=true;
						elementproperties[k].eload.internalradiation = readload.internalradiation;
						count++;
					};
				};
			};
		};
 
		if(readload.fluxconstant.i==true)
		{
			cout<<"enter fluxvalue"<<endl;
			cin>>readload.fluxconstant.fluxvalue;
			cout<<"enter elements experiencing the load"<<endl;
			selectedelement1 = selectface(f,selectedelementidentity);
			count=0;
			cout<<"enter noof elements selected as seen by prev o/p"<<endl;
			cin>>w;
			k=-1;
			while(count<w)
			{
				k++;
				for( q=0;q<w;q++)
				{
					if(elementproperties[k].eidentity.i == selectedelement1[q].i && elementproperties[k].eidentity.j == selectedelement1[q].j && elementproperties[k].eidentity.faceid == selectedelement1[q].faceid)
					{
						elementproperties[k].eload.fluxconstant.i=true;
						elementproperties[k].eload.fluxconstant = readload.fluxconstant;
						count++;
					};
				};
			};
		};

		if(readload.fluxvariable.i==true)
		{
			readload.fluxvariable.flux = new float[50000];
			readload.fluxvariable.time = new float[50000];
			int h;
			cout<<"enter no.of timesteps"<<endl;
			cin>>h;
			for(int d=0;d<h;d++)
			{
				cout <<"fill time n flux arrays"<<endl;
				cin>>readload.fluxvariable.time[d];
				cin>>readload.fluxvariable.flux[d];
			};
	
			cout<<"enter elements experiencing the load"<<endl;
			selectedelement2 = selectface(f,selectedelementidentity);
			count=0;
			cout<<"enter noof elements selected as seen by prev o/p"<<endl;
			cin>>w;
			k=-1;
	   
			while(count<w)
			{
				k++;
				for( q=0;q<w;q++)
				{
					if(elementproperties[k].eidentity.i == selectedelement2[q].i && elementproperties[k].eidentity.j == selectedelement2[q].j && elementproperties[k].eidentity.faceid == selectedelement2[q].faceid)
					{
						elementproperties[k].eload.fluxvariable.i=true;
						elementproperties[k].eload.fluxvariable = readload.fluxvariable;
						count++;
					};
				};
			};
		};

		if(readload.boundarytemperature.i==true)
		{
			cout<<"enter boundary temperature"<<endl;
			cin>>readload.boundarytemperature.boundarytemp;
			cout<<"enter elements experiencing the load"<<endl;
			selectedelement2 = selectface(f,selectedelementidentity);
			count=0;
			cout<<"enter noof elements selected as seen by prev o/p"<<endl;
			cin>>w;
			k=-1;
	   
			while(count<w)
			{
				k++;
				for( q=0;q<w;q++)
				{
					if(elementproperties[k].eidentity.i == selectedelement2[q].i && elementproperties[k].eidentity.j == selectedelement2[q].j && elementproperties[k].eidentity.faceid == selectedelement2[q].faceid)
					{
						elementproperties[k].eload.boundarytemperature = readload.boundarytemperature;
						elementproperties[k].eload.boundarytemperature.i=true;			  
						count++;
					
						if(elementproperties[k].eload.boundarytemperature.i)
							cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx boundarytemp[k] :"<<elementproperties[k].eload.boundarytemperature.boundarytemp<<endl;
					};
				};
			};
		};

		if(readload.initialtemperature.i==true)
		{
			cout<<"enter initial temperature"<<endl;
			cin>>readload.initialtemperature.initialtemp;
			cout<<"enter elements experiencing the load"<<endl;
			selectedelement3 = selectface(f,selectedelementidentity);
			count=0;
			cout<<"enter noof elements selected as seen by prev o/p"<<endl;
			cin>>w;
			k=-1;
			while(count<w)
			{
				k++;
				for(q=0;q<w;q++)
				{
					if(elementproperties[k].eidentity.i == selectedelement3[q].i && elementproperties[k].eidentity.j == selectedelement3[q].j && elementproperties[k].eidentity.faceid == selectedelement3[q].faceid)
					{
						elementproperties[k].eload.initialtemperature.i=true;
						elementproperties[k].eload.initialtemperature = readload.initialtemperature;
						count++;
					};
				};
			};
		};

		if(readload.thicknessnbour.i==true)
		{
			cout<<"testing"<<endl;
			selectedelement3 = selectface(f,selectedelementidentity);
			count=0;
			int faceid1,faceid2,m1,n1,m2,n2;
			cout<<"enter noof elements selected as seen by prev o/p"<<endl;
			cin>>w;
			k=-1;
			int faceid3 = 0;
			while(count<w)
			{
				k++;
				for(q=0;q<w;q++)
				{
					if(elementproperties[k].eidentity.i == selectedelement3[q].i && elementproperties[k].eidentity.j == selectedelement3[q].j && elementproperties[k].eidentity.faceid == selectedelement3[q].faceid)
					{
						elementproperties[k].eload.thicknessnbour.i=true;
						count++;
						
						if(selectedelement3[q].faceid!=faceid3)
						{ // faceid used so dat the cout may appear only once for all elements in a face
							cout<<"enter faceid of face below n above face of faceid "<<selectedelement3[q].faceid<<endl;
							cin>>faceid1;
							cin>>faceid2;
							m1 = f[faceid1].m;n1 = f[faceid1].n; m2 = f[faceid2].m; n2 = f[faceid2].n;
							faceid3 = selectedelement3[q].faceid;
							cout<<"testing"<<endl;
						};
					
						elementproperties[k].enbour.thicknessnve= thicknessnbourf(elementproperties[k].ecentre,faceid1,f,m1,n1);
						elementproperties[k].enbour.thicknesspve= thicknessnbourf(elementproperties[k].ecentre,faceid2,f,m2,n2);
						cout<<"testing"<<endl;
					};
				};
			};
		};
   
	};

	void viewstatus(identity identity1,elementprop *elementproperties,int fa,face *f)
	{
		int k=0;
		cout<<"testing"<<endl;
		while(k>-1)
		{	
			k++;
			if(elementproperties[k].eidentity.faceid == identity1.faceid && elementproperties[k].eidentity.i == identity1.i && elementproperties[k].eidentity.j == identity1.j )
				break;
		};
	
		nbour node = neighbour(identity1,fa,f);
		cout<<"centre of chosen element is "<<elementproperties[k].ecentre.x<<" "<<elementproperties[k].ecentre.y<<" "<<elementproperties[k].ecentre.z<<" "<<endl;  
		cout<<"load applied on chosen element are ";
		
		if(elementproperties[k].eload.radiation.i == true)
			cout<<" radiation ";

		if(elementproperties[k].eload.internalradiation.i == true)
			cout<<" internalradiation ";

		if(elementproperties[k].eload.fluxconstant.i == true)
			cout<<" fluxconstant ";

		if(elementproperties[k].eload.fluxvariable.i == true)
			cout<<" fluxvariable ";

		if(elementproperties[k].eload.initialtemperature.i == true)
			cout<<" initialtemperature ";

		if(elementproperties[k].eload.boundarytemperature.i == true)
			cout<<" boundarytemperature ";

		if(elementproperties[k].eload.thicknessnbour.i == true)
		{
			node.thicknessnve = elementproperties[k].enbour.thicknessnve;
			node.thicknesspve = elementproperties[k].enbour.thicknesspve;
		};
		
		cout<<" "<<endl;
		cout<<"chosen element's serialid is "<<elementproperties[k].eserialid<<endl;
		cout<<"chosen element's neighbours are "<<node.lthnve<<""<<node.lthpve<<""<<node.bthnve<<""<<node.bthpve<<""<<node.thicknessnve<<""<<node.thicknesspve<<""<<endl;
		cout <<"temperature conductivity :  "<<f[identity1.faceid].tconductivity<<endl;
		cout<<"specific heat :  "<<f[identity1.faceid].spheat<<endl;
	};

	int giveneidentityfindk(elementprop *eprop1,float nodeid,int noof_elements)
	{
		int k=-1,nmultiply,count=0;
		int nodeidinint = nodeid;
		identity identity1;
		nmultiply = nodeid*100;
		identity1.faceid = nmultiply%100;
		identity1.j = nodeidinint % 100;
		identity1.i = nodeidinint/100;
		
		while(k<noof_elements)
		{
			k++;
			if(eprop1[k].eidentity.faceid == identity1.faceid && eprop1[k].eidentity.i == identity1.i && eprop1[k].eidentity.j == identity1.j)
			{
				count = 9;
				cout <<"count = "<<count<<endl;
				break;
			};
		};
	
		if(count == 0)
			return 0;
		else 
			return k;
	};


	void numerical(elementprop *eprop,face *f,int fa,int noof_elements)
	{
		float volume;
		float nlthnve=0,nlthpve=0,nbthnve=0,nbthpve=0,nthicknessnve=0,nthicknesspve=0;
		float  tclthnve,tclthpve,tcbthnve,tcbthpve,tcthicknessnve,tcthicknesspve;
		int k,i,p,timestep=1,n,nfaceid1,nfaceid,klthnve,klthpve,kbthnve,kbthpve,kthicknessnve,kthicknesspve;
		cout<<"enter noof timesteps"<<endl;
		cin>>n;
		float sum1,sum2,radflux,radiationflux,conductionflux,vflux,constantflux,area = 0;
		cout<<"testing5"<<endl;
		for(k=0; k<noof_elements; k++)
		{
			//   eprop[k].temp = new float[50000];
			eprop[k].temp[0] = 301;   
			cout<<"lamborghini"<<endl;
			eprop[k].enbour = neighbour(eprop[k].eidentity ,fa,f);
			if(eprop[k].eload.boundarytemperature.i)
			{
			   cout<<"asdfghjklqwertyuiop    "<<k<<endl;
			};
		};
	
		int b;
		cout<<"total noof elements : "<<noof_elements<<endl;
		cout<<"eprop[4].temp[0] = :"<<eprop[4].temp[0]<<endl;
		cout<<"right of 1 1 1 is "<<eprop[1].enbour.lthpve<<endl;
		cout<<"eprop[k].eload.boundarytemperature.boundarytemp = "<<eprop[0].eload.boundarytemperature.boundarytemp<<" type a no"<<endl;
		cin>>b;
		b=0;
		for(i=1;i<=n;i++)
		{
			for( k=0;k<noof_elements;k++)
			{
        		if(eprop[k].eload.boundarytemperature.i)
				{
					cout<<"hi"<<endl;
			     	eprop[k].temp[0] = eprop[k].eload.boundarytemperature.boundarytemp;
					eprop[k].temp[i] = eprop[k].eload.boundarytemperature.boundarytemp;
				};
		
				if(!eprop[k].eload.boundarytemperature.i)
				{
					sum1=0;
					radflux=0;
					eprop[k].eflux = 0;
					if(eprop[k].eload.radiation.i==true)
					{   
						sum1 = eprop[k].eload.radiation.alpha * eprop[k].temp[i-1] * eprop[k].temp[i-1] * eprop[k].temp[i-1]*eprop[k].temp[i-1];
                        sum2 = eprop[k].eload.radiation.alpha * eprop[k].eload.radiation.tempamb[i] * eprop[k].eload.radiation.tempamb[i] * eprop[k].eload.radiation.tempamb[i]*eprop[k].eload.radiation.tempamb[i];
                        radflux = sum2 - sum1 ;
                        radiationflux = 0.0000000567*radflux * eprop[k].area;
                        eprop[k].eflux = eprop[k].eflux + radiationflux; // i doubt if array of eflux with time is needed
					};
                    
					if(eprop[k].eload.fluxconstant.i == true)
					{
						constantflux = eprop[k].eload.fluxconstant.fluxvalue* eprop[k].area;
                        eprop[k].eflux = eprop[k].eflux + constantflux;
                    };
						 
                    if(eprop[k].eload.fluxvariable.i == true)
					{
                        if(i%timestep == 0)
							vflux= eprop[k].eload.fluxvariable.flux[i];
                        else
                        {
							p = i/timestep;
                            //assuming timestep's 10 in the initial array
							vflux = (eprop[k].eload.fluxvariable.flux[p+1] - eprop[k].eload.fluxvariable.flux[p])*((p+1)*timestep - i);
						};        
						
						eprop[k].eflux = eprop[k].eflux + vflux;
					};
                                                                                                   
                                                  
                    nlthnve = eprop[k].enbour.lthnve;
					cout<<"nlthnve = "<<nlthnve<<endl;
                    klthnve = giveneidentityfindk(eprop,nlthnve, noof_elements);
					cout<<"serialid of left element is "<<klthnve<<endl;     
					
					if(klthnve!=0)
					{
						nfaceid1 = nlthnve*100 ;
						nfaceid = nfaceid1 % 100;
						tclthnve = f[nfaceid].tconductivity;
						area = (f[nfaceid].thickness * f[nfaceid].bth/f[nfaceid].n)/(f[nfaceid].lth/f[nfaceid].m); // lth bth thickness to be rotated accordingly
						cout<<"eprop[klthnve].temp[i-1] = "<<eprop[klthnve].temp[i-1]<<endl;
						cout<<"eprop[k].temp[i-1] = "<<eprop[k].temp[i-1]<<endl;
						conductionflux = tclthnve*area*(eprop[klthnve].temp[i-1] - eprop[k].temp[i-1]);
						cout<<"conductionfluxleft ="<<conductionflux<<endl;
						eprop[k].eflux = eprop[k].eflux + conductionflux;
					};
			        
					nlthpve = eprop[k].enbour.lthpve;
					cout<<"nlthpve = "<<nlthpve<<endl;
                    klthpve = giveneidentityfindk(eprop,nlthpve,noof_elements);
					cout<<"serialid of right element is "<<klthpve<<endl;
					if(klthpve!=0)
					{
						nfaceid1 = nlthpve*100;
						nfaceid = nfaceid1 %100;
						tclthpve = f[nfaceid].tconductivity;
						area = (f[nfaceid].thickness * f[nfaceid].bth/f[nfaceid].n)/(f[nfaceid].lth/f[nfaceid].m); // lth bth thickness to be rotated accordingly
						cout<<"eprop[klthpve].temp[i-1] = "<<eprop[klthpve].temp[i-1]<<endl;
						cout<<"eprop[k].temp[i-1] = "<<eprop[k].temp[i-1]<<endl;            
						conductionflux = tclthpve*area*(eprop[klthpve].temp[i-1] - eprop[k].temp[i-1]);
						cout<<"conductionfluxright ="<<conductionflux<<endl;
						eprop[k].eflux = eprop[k].eflux + conductionflux;
					};
			        
					nbthnve = eprop[k].enbour.bthnve;
                    kbthnve = giveneidentityfindk(eprop,nbthnve,noof_elements);
					cout<<"serialid of bottom element is "<<kbthnve<<endl;
					if(kbthnve!=0)
					{
						nfaceid1 = nbthnve*100;
						nfaceid = nfaceid1%100;
						tcbthnve = f[nfaceid].tconductivity;
						area = (f[nfaceid].thickness * f[nfaceid].lth/f[nfaceid].m)/(f[nfaceid].bth/f[nfaceid].n); // lth bth thickness to be rotated accordingly
						cout<<"eprop[kbthnve].temp[i-1] = "<<eprop[kbthnve].temp[i-1]<<endl;
						cout<<"eprop[k].temp[i-1] = "<<eprop[k].temp[i-1]<<endl;
						conductionflux = tcbthnve*area*(eprop[kbthnve].temp[i-1] - eprop[k].temp[i-1]);
						cout<<"conductionfluxbottom ="<<conductionflux<<endl;
						eprop[k].eflux = eprop[k].eflux + conductionflux;
					};
			        
					nbthpve = eprop[k].enbour.bthpve;
                    kbthpve = giveneidentityfindk(eprop,nbthpve,noof_elements);
					cout<<"serialid of top element is "<<kbthpve<<endl;
					if(kbthpve!=0)
					{
						nfaceid1 = nbthpve*100;
						nfaceid = nfaceid1%100;
						tcbthpve = f[nfaceid].tconductivity;
						area = (f[nfaceid].thickness * f[nfaceid].lth/f[nfaceid].m)/(f[nfaceid].bth/f[nfaceid].n); 
						cout<<"area : "<<area<<endl;// lth bth thickness to be rotated accordingly
						cout<<"eprop[kbthpve].temp[i-1] = "<<eprop[kbthpve].temp[i-1]<<endl;
						cout<<"eprop[k].temp[i-1] = "<<eprop[k].temp[i-1]<<endl;
						conductionflux = tcbthpve*area*(eprop[kbthpve].temp[i-1] - eprop[k].temp[i-1]);
						cout<<"conductionfluxtop ="<<conductionflux<<endl;
						eprop[k].eflux = eprop[k].eflux + conductionflux;
					};
		
					/* nthicknessnve = eprop[k].enbour.thicknessnve;
					     kthicknessnve = giveneidentityfindk(eprop,nthicknessnve,noof_elements);
				               cout<<"serialid of back element is "<<kthicknessnve<<endl;
												  if(kthicknessnve!=0){
             nfaceid1 = nthicknessnve*100;
			 nfaceid = nfaceid1%100;
             tcthicknessnve = f[nfaceid].tconductivity;
             area = (f[nfaceid].lth/f[nfaceid].m * f[nfaceid].bth/n)/f[nfaceid].thickness; // lth bth thickness to be rotated accordingly
             conductionflux = tcthicknessnve*area*(eprop[kthicknessnve].temp[i-1] - eprop[k].temp[i-1]);
             eprop[k].eflux = eprop[k].eflux + conductionflux;
												  };
			                                            nthicknesspve = eprop[k].enbour.thicknesspve;
                                                  kthicknesspve = giveneidentityfindk(eprop,nthicknesspve,noof_elements);
												  cout<<"serialid of front element is "<<kthicknesspve<<endl;
												  if(kthicknesspve!=0){
             nfaceid1 = nthicknesspve*100;
			 nfaceid = nfaceid1%100;
             tcthicknesspve = f[nfaceid].tconductivity;
			 area = (f[nfaceid].lth/f[nfaceid].m * f[nfaceid].bth/n)/f[nfaceid].thickness; // lth bth thickness to be rotated accordingly
             conductionflux = tcthicknesspve*area*(eprop[kthicknesspve].temp[i-1] - eprop[k].temp[i-1]);
             eprop[k].eflux = eprop[k].eflux + conductionflux;
												  };
*/
					b++;
					volume = eprop[k].area * eprop[k].thickness;
					cout <<"eprop[k].eflux = "<<eprop[k].eflux<<"n nth repeat "<<b<<endl;
					eprop[k].temp[i] = (eprop[k].eflux * timestep)/(eprop[k].density*eprop[k].spheat*volume) + eprop[k].temp[i-1];// if ist term in rhs is 10^-2 times smaller to 301 (2nd term) then rhs 'l be rounded of to 301 so tc
					cout<<"eprop[k].temp[i] :"<<eprop[k].temp[i]<<endl;

				};
            };
        };
		//	 cout<<"temp of 1 1 1 at 50th iteration is "<<eprop[1].temp[50]<<endl;
	};         
              
                                                                                                                                 

int main()
{
    face *f;
/*			 float a,b,c,d;cout<<"a : "<<endl; cin>>a; cout<<"a is "<<a<<endl;
			 b = a; c = b* 50; d = b+30; cout<<" d :"<<d<<"also b c"<<b<<c<<endl;   
*/   
	float a = 0.1;
	float	 b = .0000000567 * a;
	cout<<"  a: "<<a<<"b :"<<b<<endl;
    int fa;
    cout<<"enter no.of faces"<<endl;
    cin>>fa;
	f = new face[6];
    int i,k=0,noof_elements=0,sum;
	load load1;
	load1.radiation.i = false;
	load1.internalradiation.i = false;
	load1.fluxconstant.i = false;
	load1.fluxvariable.i = false;
	load1.boundarytemperature.i = false;
	load1.initialtemperature.i = false;
	elementprop *elementproperties;
	elementproperties = new elementprop[1000];
	identity identity1;int p,q;
	cout<<"testing"<<endl;
	for(i=1;i<=fa;i++)
	{
		sum = f[i].read(i);
		noof_elements+=sum;
		cout<<"testing"<<endl;
        int m = f[i].m;
		int n = f[i].n;
		for(p=1;p<=m;p++)
		{
			for(q=1;q<=n;q++)
			{
			    identity1.faceid = i;identity1.i = p; identity1.j = q;
				elementproperties[k].eidentity = identity1;
				elementproperties[k].ecentre = f[i].centref(identity1);
                //			   elementproperties[k].enbour = neighbour(identity1,fa,f);
				elementproperties[k].eserialid = k;
				elementproperties[k].eload = load1;
				elementproperties[k].area = (f[i].lth/m)*(f[i].bth/n);
				elementproperties[k].thickness = f[i].thickness;
				elementproperties[k].density = f[i].density;
				elementproperties[k].spheat = f[i].spheat;
				k++;
            };
		};
	};
	
	cout<<"testing1"<<endl;
	int fg;
	float nodeid; 
	int nodeidinint; 
	identity eidentity1,eidentity2;
	cout<<"enter i,j and faceid of the elements whose centre is to be found(faceid in 2 decimal)"<<endl;
	cin>>eidentity1.i;
	cin>>eidentity1.j;
	cin>>eidentity1.faceid;

	cout<<"faceid1 = "<<eidentity1.faceid<<endl;

	dirn center;
	center = f[eidentity1.faceid].centref(eidentity1);
	cout<<"co-ordinates of centre are"<<endl;
	cout<<center.x <<endl;
	cout<<center.y <<endl;
	cout<<center.z <<endl;
	int z;

	nbour nbour1;
	cout<<"enter i,j and faceid of node whose neighbours are to be found(faceid in 2 decimal)"<<endl; // dont use nodeid for elementid as its already used for findin centre
	cin>>eidentity2.i;
	cin>>eidentity2.j;
	cin>>eidentity2.faceid;
	nbour1 = neighbour(eidentity2,fa,f);
	cout<<nbour1.lthnve<<"  and  "<<nbour1.lthpve<<" and "<<nbour1.bthnve<<" and "<<nbour1.bthpve<<" and "<<nbour1.thicknessnve<<" and "<<nbour1.thicknesspve<<endl;
	cout<<"testing findk fn"<<endl;
	int y=8;
	y = giveneidentityfindk(elementproperties,101.01,noof_elements);
	cout<<"is y != 0 den fn works "<<y <<endl;
	int esc=0;
	while(esc!=1)
	{
		readloadf(fa,f,elementproperties,noof_elements);
		cout<<"press 1 to stop reading loads else press any other no"<<endl;// arre vo escape vaala chal nahi raha tha aur main jyaada time waste nahi karna chahta tha
		cin>>esc;
	};

	numerical(elementproperties,f,fa,noof_elements);
	identity identity2;
	int temptime;
	cout<<"enter time wen u want to see the temp"<<endl;
	cin>>temptime;
	cout<<"enter i,j and faceid of the element whose temp is to be found"<<endl;
	cin>>identity2.i;
	cin>>identity2.j;
	cin>>identity2.faceid;
	int u;
	cout<<"testing4"<<endl;
	for(u=0;u<noof_elements;u++)
	{
		if(elementproperties[u].eidentity.faceid == identity2.faceid && elementproperties[u].eidentity.i == identity2.i && elementproperties[u].eidentity.j == identity2.j)
		{ 
			cout<<"temp of "<<u<<"th element at  "<<temptime<<" is "<<endl;
			cout<<elementproperties[u].temp[temptime]<<endl;
			break;
		};
	};
// viewstatus(identity3,elementproperties,fa,f);
	cin>>fg;	
};
