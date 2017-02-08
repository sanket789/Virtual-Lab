#include <iostream>
#include <fstream>
#include <math.h>
#include "face4.h"

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
			float tempamb;
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
			float absorbed;    //both these values need to be initialized to zero
			bool i;
		};
		
		struct fluxc
		{ 
			int fluxdirn;
			float fluxvalue;
			bool i;
		};
		
		struct fluxv
		{
			int fluxdirnv;
			float *time;
			float *flux;
			bool  i;
			int   h;
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
			float lth;
			float bth;
			float eflux;
			float *temp;
			float area;
			float thickness;
			float density;
			float spheat;
			float area1;
			float *temp1;
	 
		};
		  struct viewfactor
		  {
			   float x,y,z;
			   int sid;
	 };
	 struct vfactor
	 {
		int sid1,sid2,value ;
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
						float face_id_float = eidentity1.faceid;
						float decpart = face_id_float/100;
						
						if(f[faceid1].normal.x == 1 || f[faceid1].normal.x == -1)
						{
							if(centre1.z == centre.z && centre1.y == centre.y )
								retval = 100*eidentity1.i + eidentity1.j +decpart;
				   		};
					   
						if(f[faceid1].normal.y == 1 || f[faceid1].normal.y == -1)
						{
							if(centre1.z == centre.z && centre1.x == centre.x )
								retval = 100*eidentity1.i + eidentity1.j +decpart;
						};
					    
						if(f[faceid1].normal.z == 1 || f[faceid1].normal.z == -1)
						{
							if(centre1.x == centre.x && centre1.y == centre.y )
								retval = 100*eidentity1.i + eidentity1.j +decpart;	
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
	                 

		identity *selectface(face *f,identity *selectedelementidentity, int &totalelements)
		{
			ifstream in("elementidentity.txt",ios::in);
			int noof_faces;
			int selectedfaceid[10];
			int type;
			totalelements=0;			
			cout<<"Face/Element selection"<<endl;
			cout<<"Type 1 to select faces"<<endl;
			cout<<"Type 2 to select elements"<<endl;
			cout<<"Type 3 to select both faces and elements"<<endl;
			cin>>type;
			if(type==1)
			{			
				cout<<"Enter number of faces you want to select (should be less than 10)"<<endl;
				cin>>noof_faces;
				int k=0,m,n;
				for(int z=1;z<=noof_faces;z++)
				{
					cout<<"Enter the face ids"<<endl;
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
				cout<<"The number of selected elements are "<<k<<endl;
				totalelements=k;
			};
			
			if(type==2)   
			{
				int noof_elements,z;
				cout<<"Enter the number of elements you want to select"<<endl;
				cin>>noof_elements;
				cout<<"enter element's i j n faceid"<<endl;
			
				for (z=0;z<noof_elements;z++)
				{
			   		cin>>selectedelementidentity[z].i;
			   		cin>>selectedelementidentity[z].j;
			  	 	cin>>selectedelementidentity[z].faceid;
			        };
				cout<<"Total nummber of selected elements = "<<noof_elements<<endl;
				totalelements=noof_elements;
			};
			
			if(type==3)
			{	
				cout<<"Enter number of faces you want to select (should be less than 10)"<<endl;
				cin>>noof_faces;
				int k=0,m,n;
				for(int z=1;z<=noof_faces;z++)
				{
					cout<<"Enter the face ids"<<endl;
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
				cout<<"Enter the number of elements you want to select"<<endl;
				cin>>noof_elements;
				cout<<"enter element's i j n faceid"<<endl;
			
				for (z=k;z<noof_elements+k;z++)
				{
			   		cin>>selectedelementidentity[z].i;
			   		cin>>selectedelementidentity[z].j;
			  	 	cin>>selectedelementidentity[z].faceid;
			        };
				cout<<"Total nummber of selected elements = "<<k<<endl;
				totalelements=k;
				return selectedelementidentity;
			};
		};

		void readloadf(int fa,face *f,elementprop *elementproperties,int noof_elements)
		{               
			identity *selectedelement1;
			identity *selectedelement2;
			identity *selectedelement3;
			selectedelement1 = new identity[100];
			int totalselectedelements = 0;			
			identity *selectedelementidentity;
			selectedelementidentity = new identity[100];
			load readload;	int r1,r2,r3,r4,r5,r6,r7;	  				  
			cout<<"Load application:"<<endl;
			cout<<"Radiation (1=yes, 0=no) "<<endl;
			cin>>r1;
			cout<<"Internal Radiation (1=yes, 0=no) "<<endl;
			cin>>r2;
			cout<<"Constant Flux (W/m^2) (1=yes, 0=no) "<<endl;
			cin>>r3;
			cout<<"Time dependent Flux (W/m^2) (1=yes, 0=no) "<<endl;
			cin>>r4;
			cout<<"Initial temperature (K) (1=yes, 0=no)"<<endl; 
			cin>>r5;
			cout<<"Fixed Boundary Temperature (K) (1=yes, 0=no)"<<endl;
			cin>>r6;
			cout<<"Neighbours perpendicular to the face (1=yes, 0=no)"<<endl;
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
				cout<<"Enter Absorptivity, Emissivity, Ambient Temperature & Viewfactor in the mentioned order"<<endl;
				cin>>readload.radiation.alpha;
				cin>>readload.radiation.epsilon;
				cin>>readload.radiation.tempamb;
				cin>>readload.radiation.vfactor;	       
				selectedelement1 = selectface(f,selectedelementidentity,totalselectedelements);
				count=0;
				w=totalselectedelements;
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
				//NO NEED TO INPUT VIEW FACTOR HERE. WE WILL BE DOING IT INDIVIDUALLY. YOU CAN REMOVE IT FROM STRUCT AS WELL				
				cout<<"Enter Absorptivity & Emissivity epsilon:"<<endl;
				cin>>readload.internalradiation.alpha;
				cin>>readload.internalradiation.epsilon;
				selectedelement1 = selectface(f,selectedelementidentity,totalselectedelements);
				count=0;
				w=totalselectedelements;
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
				cout<<"Enter flux value"<<endl;
				cin>>readload.fluxconstant.fluxvalue;
				cout<<"enter 1 if fluxdirection's parallel to thickness else if parallel to breadth enter 2 else enter 3 if parallel to length of face"<<endl;
				cin>>readload.fluxconstant.fluxdirn;
				selectedelement1 = selectface(f,selectedelementidentity,totalselectedelements);
				count=0;
				w=totalselectedelements;
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
				cout<<"enter no.of timesteps for the array"<<endl;
				cin>>readload.fluxvariable.h;
				cout<<"enter 1 if fluxdirection's parallel to thickness else if parallel to breadth enter 2 else enter 3 if parallel to length of face"<<endl;
				cin>>readload.fluxvariable.fluxdirnv;
				for(int d = 0;d<readload.fluxvariable.h;d++)
				{
					//PUT IN OPTION TO INPUT FROM FILE AS WELL					
					cout <<"fill "<< d <<" time and flux array"<<endl;
					cin>>readload.fluxvariable.time[d];
					cin>>readload.fluxvariable.flux[d];
				};
		
				selectedelement1 = selectface(f,selectedelementidentity,totalselectedelements);
				count=0;
				w=totalselectedelements;
				k=-1;
		   		while(count<w)
				{
					k++;
					for( q=0;q<w;q++)
					{
						if(elementproperties[k].eidentity.i == selectedelement1[q].i && elementproperties[k].eidentity.j == selectedelement1[q].j && elementproperties[k].eidentity.faceid == selectedelement1[q].faceid)
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
				cout<<"Enter fixed boundary temperature"<<endl;
				cin>>readload.boundarytemperature.boundarytemp;
				selectedelement1 = selectface(f,selectedelementidentity,totalselectedelements);
				count=0;
				w=totalselectedelements;
				k=-1;
		   
				while(count<w)
				{
					k++;
					for( q=0;q<w;q++)
					{
						cout<<"hi"<<endl;
						if(elementproperties[k].eidentity.i == selectedelement1[q].i && elementproperties[k].eidentity.j == selectedelement1[q].j && elementproperties[k].eidentity.faceid == selectedelement1[q].faceid)
						{
							elementproperties[k].eload.boundarytemperature = readload.boundarytemperature;
							elementproperties[k].eload.boundarytemperature.i=true;			  
							count++;
						
						};
					};
				};
			};

			if(readload.initialtemperature.i==true)
			{
				cout<<"Enter initial temperature"<<endl;
				cin>>readload.initialtemperature.initialtemp;
				selectedelement1 = selectface(f,selectedelementidentity, totalselectedelements);
				count=0;
				w=totalselectedelements;
				k=-1;
				while(count<w)
				{
					k++;
					for(q=0;q<w;q++)
					{
						if(elementproperties[k].eidentity.i == selectedelement1[q].i && elementproperties[k].eidentity.j == selectedelement1[q].j && elementproperties[k].eidentity.faceid == selectedelement1[q].faceid)
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
				//TAKE A LOOK INTO THIS PART VERY CAREFULLY
				cout<<"While entering the faces and elements selected put in the element/face on top first " << endl;				
				selectedelement1 = selectface(f,selectedelementidentity,totalselectedelements);
				count=0;
				int faceid1,faceid2,m1,n1,m2,n2;
				w=totalselectedelements;
				float nodeid_of_currentelement;
				int nodeid_in_int;
				identity eidentity2;
				k=-1;
				int faceid3 = 0;
				while(count<w)
				{
					k++;
					for(q=0;q<w;q++)
					{
						if(elementproperties[k].eidentity.i == selectedelement1[q].i && elementproperties[k].eidentity.j == selectedelement1[q].j && elementproperties[k].eidentity.faceid == selectedelement1[q].faceid)
						{
							elementproperties[k].eload.thicknessnbour.i=true;
							count++;
							
				/*			if(selectedelement3[q].faceid!=faceid3)
							{ // faceid used so dat the cout may appear only once for all elements in a face
							*/			cout<<"enter faceid of face below n above face of element with i = "<<selectedelement3[q].i<<"and j = "<<selectedelement3[q].j<<" n faceid = "<<selectedelement3[q].faceid<<endl;
								cin>>faceid1;
								cin>>faceid2;
								m1 = f[faceid1].m;n1 = f[faceid1].n; m2 = f[faceid2].m; n2 = f[faceid2].n;
					/*			faceid3 = selectedelement3[q].faceid;
								cout<<"testing"<<endl;
							};
*/
                            nodeid_of_currentelement = 100*elementproperties[k].eidentity.i + elementproperties[k].eidentity.j +elementproperties[k].eidentity.faceid/100;
							if(elementproperties[k].enbour.thicknessnve == 0)
			{
							elementproperties[k].enbour.thicknessnve= thicknessnbourf(elementproperties[k].ecentre,faceid1,f,m1,n1);
							nodeid_in_int = elementproperties[k].enbour.thicknessnve;
							eidentity2.faceid = faceid1;eidentity2.j = nodeid_in_int % 100; eidentity2.i = nodeid_in_int/100;
							for(int h=0;h<noof_elements ;h++)
							{
								if(elementproperties[h].eidentity.faceid ==eidentity2.faceid && elementproperties[h].eidentity.i == eidentity2.i && elementproperties[h].eidentity.j == eidentity2.j)
									elementproperties[h].enbour.thicknesspve = nodeid_of_currentelement;
							};
			};     
                                if(elementproperties[k].enbour.thicknesspve == 0) 
								{
								elementproperties[k].enbour.thicknesspve= thicknessnbourf(elementproperties[k].ecentre,faceid2,f,m2,n2);
							    nodeid_in_int = elementproperties[k].enbour.thicknesspve;
						        eidentity2.faceid = faceid2;eidentity2.j = nodeid_in_int % 100; eidentity2.i = nodeid_in_int/100;
							    for(int h=0;h<noof_elements ;h++)
								{
								if(elementproperties[h].eidentity.faceid ==eidentity2.faceid && elementproperties[h].eidentity.i == eidentity2.i && elementproperties[h].eidentity.j == eidentity2.j)
								elementproperties[h].enbour.thicknessnve = nodeid_of_currentelement;
								};
								};
								cout<<"testing"<<endl;
						};
					};
				};
			};
	   
		};

		void viewstatus(identity identity1,elementprop *elementproperties,int fa,face *f)
		{
			int k=0;
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


		/* vfactor *viewfactorf(int noof_elements ,elementprop* eprop,int fa,face *f)
		{
		int k,i,j,l,p=0,q=0,u1=0,u2=0,u3=0;
		float y0,x0,z0;
		vfactor *vf2; // to return
		viewfactor *vf1;
		vf2 = new vfactor[100];
		vf1 = new viewfactor[100];
		for (k =0;k<noof_elements;k++)
		{
			if(eprop[k].eload.internalradiation.i)
			{
									vf1[p].x = eprop[k].ecentre.x;
									vf1[p].y = eprop[k].ecentre.y;
									vf1[p].z = eprop[k].ecentre.x;
									vf1[p].sid = eprop[k].eserialid;
									p++;
									};
							 };
		  for (k =1;k<=fa;k++)
		  {
				 for(i=0;i<p;i++)
				 {
								  for(j=0;j<p;j++)
								  {
												   if(j!=i)
												   {
	                                                        
				 if(f[k].normal.x == 1 || f[k].normal.x == -1)
				 {
								  if((f[k].startpt.x + f[k].thickness/2 - vf1[i].x)*(f[k].startpt.x + f[k].thickness/2 - vf1[j].x) <0)
								  {
										  y0 =  ((f[k].startpt.x + f[k].thickness/2 - vf1[i].x)*( vf1[i].y - vf1[j].y)/(vf1[i].x - vf1[j].x)) + vf1[i].y;
										  z0 =   ((f[k].startpt.x + f[k].thickness/2 - vf1[i].x)*( vf1[i].z - vf1[j].z)/(vf1[i].x - vf1[j].x)) + vf1[i].z; 
										  if(((y0-f[k].startpt.y)*(y0-(f[k].startpt.y+f[k].lth))<0)&& ((z0-f[k].startpt.z)*(z0-(f[k].startpt.z+f[k].bth))<0))
										  {
															   vf2[u1].value = 1;
																vf2[u1].sid1 = vf1[i].sid;
																 vf2[u1].sid2 = vf1[j].sid;
																 // vf1[i].repeat =1;
																	 u1++;      
																		};
																 };
														 };
	 if(f[k].normal.y == 1 || f[k].normal.y == -1)
	 {
								  if((f[k].startpt.y + f[k].thickness/2 - vf1[i].y)*(f[k].startpt.y + f[k].thickness/2 - vf1[j].y) <0)
								  {
										  x0 =  ((f[k].startpt.y + f[k].thickness/2 - vf1[i].y)*( vf1[i].x - vf1[j].x)/(vf1[i].y - vf1[j].y)) + vf1[i].x;
										  z0 =   ((f[k].startpt.y + f[k].thickness/2 - vf1[i].y)*( vf1[i].z - vf1[j].z)/(vf1[i].y - vf1[j].y)) + vf1[i].z; 
										  if(((x0-f[k].startpt.x)*(x0-(f[k].startpt.x+f[k].bth))<0)&& ((z0-f[k].startpt.z)*(z0-(f[k].startpt.z+f[k].lth))<0))
										  {
															   vf2[u2].value = 1;
																vf2[u2].sid1 = vf1[i].sid;
																 vf2[u2].sid2 = vf1[j].sid;
																 // vf1[i].repeat =1;
																	 u2++;      
														   };
												   };
										   };
	  if(f[k].normal.z == 1 || f[k].normal.z == -1)
	  {
								  if((f[k].startpt.z + f[k].thickness/2 - vf1[i].z)*(f[k].startpt.z + f[k].thickness/2 - vf1[j].z) <0)
								  {
										  y0 =  ((f[k].startpt.z + f[k].thickness/2 - vf1[i].z)*( vf1[i].y - vf1[j].y)/(vf1[i].z - vf1[j].z)) + vf1[i].y;
										  x0 =   ((f[k].startpt.z + f[k].thickness/2 - vf1[i].z)*( vf1[i].x - vf1[j].x)/(vf1[i].z - vf1[j].z)) + vf1[i].x; 
										  if(((y0-f[k].startpt.y)*(y0-(f[k].startpt.y+f[k].bth))<0)&& ((x0-f[k].startpt.x)*(x0-(f[k].startpt.x+f[k].lth))<0))
										  {
															   vf2[u3].value = 1;
																vf2[u3].sid1 = vf1[i].sid;
																 vf2[u3].sid2 = vf1[j].sid;
																 // vf1[i].repeat =1;
																	 u3++;      
																		};
																 };
														  };
												};
										 };
							 };
				 };
		  return vf2;
		};
	    
		double parallelfunction(double x,double y,double eta, double psi, double z)
{
	      double p=0;
	      double term1=(y-eta)*sqrt((x-psi)*(x-psi)+z*z)*atan((y-eta)/sqrt((x-psi)*(x-psi)+z*z));
	      double term2=(x-psi)*sqrt((y-eta)*(y-eta)+z*z)*atan((x-psi)/sqrt((y-eta)*(y-eta)+z*z));
	      double term3=0.5*z*z*log((x-psi)*(x-psi) + (y-eta)*(y-eta) + z*z);
	      p=(term1+term2-term3)/6.28;
	      return p;
};
		double perpendicularfunction(double x,double y,double eta, double psi)
{
	      double p=0;
	      double k,term1,term2;
	      if(y!=eta && (x*x+psi*psi)!=0)
	{
          k=(y-eta)/sqrt(x*x + psi*psi);
	      term1=(y-eta)*sqrt(x*x + psi*psi)*atan(k);
	      term2=0.25*((x*x + psi*psi)*log(1+k*k)-(y-eta)*(y-eta)*log(1+1/(k*k)));
	      p = (term1-term2)/6.28;
    };
          return p;
};
		
		float finding_viewfactor( int noof_elements ,elementprop* eprop,int fa,face *f,int sid1,int sid2)
		{
			int b;
				double x[2],y[2],eta[2],psi[2],sum , z;
	            int i,j,k,l;
                sum=0;
			    cout<<"press 1  if parallel fn is to be used"<<endl;
			    cin>>b;
				
						cout<<"Enter x values"<<endl;
	for(i=0; i<2; i++)
	{
		cin>>x[i];
	};
	cout<<"Enter y values"<<endl;
	for(i=0; i<2; i++)
	{
		cin>>y[i];
	};
	cout<<"Enter eta values"<<endl;
	for(i=0; i<2; i++)
	{
		cin>>eta[i];
	};
	cout<<"Enter psi values"<<endl;
	for(i=0; i<2; i++)
	{
		cin>>psi[i];
	};
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
					cout<<"hi"<<endl;
					if(b==1)
	      		   sum = sum + parallelfunction(x[i],y[j],eta[k],psi[l],z)*pow(-1,i+j+k+l);
					else
				   sum = sum + perpendicularfunction(x[i],y[j],eta[k],psi[l])*pow(-1,i+j+k+l);
				};
			};
		};
	};
	sum = abs (sum/((x[1]-x[0])*(y[1]-y[0])));
	cout<<" The view factor is"<<endl<<sum<<endl;
	
    return sum;
};*/

		
		//Numerical method
		void numerical(elementprop *eprop,face *f,int fa,int noof_elements)
		{
			ofstream out("tempfile.csv",ios::out);
			out<<"serialid "<<"i "<<"j "<<"time "<<"temp "<<"b "<<"conductionflux "<<"conductionfluxright "<<"conductionfluxbottom " << "conductionfluxtop "<<endl;
			float volume,area2,area3;
			float nlthnve=0,nlthpve=0,nbthnve=0,nbthpve=0,nthicknessnve=0,nthicknesspve=0;
			float  tclthnve,tclthpve,tcbthnve,tcbthpve,tcthicknessnve,tcthicknesspve,diff=1;
			int k,i,j,p,timestep,n,nfaceid1,nfaceid,klthnve,klthpve,kbthnve,kbthpve,kthicknessnve,transient=0,kthicknesspve,count1,diffcount=9;
			float sum1, sum2, radflux, radiationflux, conductionfluxleft, conductionfluxright, conductionfluxtop, conductionfluxbottom, vflux, constantflux, intradfluxfinal, area = 0;
			cout<<"For a transient solution press 1, for steady state 0"<<endl;
			cin>>transient;
			if (transient == 1)
			{
				cout<<"Enter the time step"<<endl;
				cin >> timestep;
				cout<<"Enter no of iterations"<<endl;
				cin>>n;
			}
			else
			{
				timestep = 1;
				n = 50000;
			}
			
			//Initialization of temperature
			for( k=0;k<noof_elements;k++)
			{
				if (transient==1)
					eprop[k].temp = new float[n];
				else
					eprop[k].temp = new float[50000];
					eprop[k].temp[0] = 301;
					eprop[k].eload.internalradiation.absorbed = 0;
			};
			
			int b;
			cout<<"Total no of elements : "<<noof_elements<<endl;
			cin >> b;			
			b=0;
			if(transient == 1)
			{
				for(i=1;i<=n;i++)
				{
					for( k=0;k<noof_elements;k++)
					{
        					
						//Boundary temperature						
						if(eprop[k].eload.boundarytemperature.i)
						{
							eprop[k].temp[0] = eprop[k].eload.boundarytemperature.boundarytemp;
							eprop[k].temp[i] = eprop[k].eload.boundarytemperature.boundarytemp;
							b++;
							cout<<"Loop number "<<b<<" Boundary Temperature"<<endl;
						};
			
						if(!eprop[k].eload.boundarytemperature.i)
						{
							sum1=0;
							radflux=0;
							eprop[k].eflux = 0;
							
							//Radiation
							if(eprop[k].eload.radiation.i==true)
							{   
								sum1 = eprop[k].eload.radiation.alpha * eprop[k].temp[i-1] * eprop[k].temp[i-1] * eprop[k].temp[i-1]*eprop[k].temp[i-1];
								sum2 = eprop[k].eload.radiation.alpha * eprop[k].eload.radiation.tempamb * eprop[k].eload.radiation.tempamb * eprop[k].eload.radiation.tempamb*eprop[k].eload.radiation.tempamb;
								radflux = sum2 - sum1 ;
								radiationflux = 0.0000000567*radflux * eprop[k].area;
								eprop[k].eflux = eprop[k].eflux + radiationflux; 
							};
	                    
						if(eprop[k].eload.internalradiation.i)
						{
							for(m=0;m<noof_elements;m++)
							{
								if(eprop[m].eload.internalradiation.i)
								{
									iradflux = (0.0000000567*eprop[m].eload.internalradiation.alpha*eprop[m].temp[i-1] * eprop[m].temp[i-1] * eprop[m].temp[i-1]*eprop[m].temp[i-1])+(1-eprop[m].eload.internalradiation.alpha)*eprop[m].eload.internalradiation.absorbed/eprop[m].eload.internalradiation.alpha;
									intradflux = iradflux * eprop[m].area;
									vf = finding_viewfactor(noof_elements,eprop,fa,f,eprop[m].eserialid,eprop[k].eserialid);
									sumvf = eprop[k].eload.internalradiation.alpha*vf*intradflux+sumvf;
								};
							};
							eprop[k].eload.internalradiation.absorbed = sumvf;
							intradfluxfinal = sumvf - 0.0000000567*eprop[k].eload.internalradiation.alpha*eprop[k].temp[i-1] * eprop[k].temp[i-1] * eprop[k].temp[i-1]*eprop[k].temp[i-1])+(1-eprop[k].eload.internalradiation.alpha)*eprop[k].eload.internalradiation.absorbed/eprop[k].eload.internalradiation.alpha;							
							eprop[k].eflux = eprop[k].eflux + intradfluxfinal;
						};
	                        			//Constant flux
							if(eprop[k].eload.fluxconstant.i == true)
							{
                                switch (eprop[k].eload.fluxconstant.fluxdirn)
							{
							case 1 : 
								area2 = eprop[k].lth * eprop[k].bth; 
							case 2 :
								area2 = eprop[k].lth * eprop[k].thickness;
							case 3 :
								area2 = eprop[k].bth * eprop[k].thickness;
							default :
								area2 = 1;
							};
								constantflux = eprop[k].eload.fluxconstant.fluxvalue* area2;
								eprop[k].eflux = eprop[k].eflux + constantflux;
							};
							
 							//Variable flux
							if(eprop[k].eload.fluxvariable.i == true)
							{
	                        switch (eprop[k].eload.fluxvariable.fluxdirnv)
							{
							case 1 : 
								area3 = eprop[k].lth * eprop[k].bth; 
							case 2 :
								area3 = eprop[k].lth * eprop[k].thickness;
							case 3 :
								area3 = eprop[k].bth * eprop[k].thickness;
							default :
								area3 = 1;
							};
								count1 = 0;vflux = 0;
								for( j=0;j<eprop[k].eload.fluxvariable.h;j++)
								{
									if( eprop[k].eload.fluxvariable.time[j] == i*timestep)
									{
										vflux= eprop[k].eload.fluxvariable.flux[j]*area3;
										count1 ++;
									};
				       				        if(i>eprop[k].eload.fluxvariable.time[j] && i<eprop[k].eload.fluxvariable.time[j+1])
								 	{
										vflux = ((eprop[k].eload.fluxvariable.flux[j+1] - eprop[k].eload.fluxvariable.flux[j])*(i*timestep - eprop[k].eload.fluxvariable.time[j])/(eprop[k].eload.fluxvariable.time[j+1] - eprop[k].eload.fluxvariable.time[j]) + eprop[k].eload.fluxvariable.flux[j])*area3;
										count1++;
									};
									if(count1>0)
					                			break;
								};
								eprop[k].eflux = eprop[k].eflux + vflux;
							};
	                                                                                                   
				      
				 			//Conduction flux left
							nlthnve = eprop[k].enbour.lthnve;
							klthnve = giveneidentityfindk(eprop,nlthnve,noof_elements);
						
							if(klthnve!=0)
							{
								nfaceid1 = nlthnve*100 ;
								nfaceid = nfaceid1 % 100;
								tclthnve = f[nfaceid].tconductivity;
								area = (f[nfaceid].thickness * f[nfaceid].bth/f[nfaceid].n)/(f[nfaceid].lth/f[nfaceid].m); 
								conductionfluxleft = tclthnve*area*(eprop[klthnve].temp[i-1] - eprop[k].temp[i-1]);
								eprop[k].eflux = eprop[k].eflux + conductionfluxleft;
							};
				        
							//Conduction flux right
							nlthpve = eprop[k].enbour.lthpve;
							klthpve = giveneidentityfindk(eprop,nlthpve,noof_elements);
							
							if(klthpve!=0)
							{
								nfaceid1 = nlthpve * 100;
								nfaceid = nfaceid1 % 100;
								tclthpve = f[nfaceid].tconductivity;
								area = (f[nfaceid].thickness * f[nfaceid].bth/f[nfaceid].n)/(f[nfaceid].lth/f[nfaceid].m); 
								conductionfluxright = tclthpve*area*(eprop[klthpve].temp[i-1] - eprop[k].temp[i-1]);
								eprop[k].eflux = eprop[k].eflux + conductionfluxright;
							};
				        
							//Conduction flux bottom							
							nbthnve = eprop[k].enbour.bthnve;
							kbthnve = giveneidentityfindk(eprop,nbthnve,noof_elements);
							if(kbthnve!=0)
							{
								nfaceid1 = nbthnve*100;
								nfaceid = nfaceid1%100;
								tcbthnve = f[nfaceid].tconductivity;
								area = (f[nfaceid].thickness * f[nfaceid].lth/f[nfaceid].m)/(f[nfaceid].bth/f[nfaceid].n);
								conductionfluxbottom = tcbthnve*area*(eprop[kbthnve].temp[i-1] - eprop[k].temp[i-1]);
								eprop[k].eflux = eprop[k].eflux + conductionfluxbottom;
							};
				        
							//Conduction flux top						
							nbthpve = eprop[k].enbour.bthpve;
							kbthpve = giveneidentityfindk(eprop,nbthpve,noof_elements);
							if(kbthpve!=0)
							{
								nfaceid1 = nbthpve*100;
								nfaceid = nfaceid1%100;
								tcbthpve = f[nfaceid].tconductivity;
								area = (f[nfaceid].thickness * f[nfaceid].lth/f[nfaceid].m)/(f[nfaceid].bth/f[nfaceid].n); 
								conductionfluxtop = tcbthpve*area*(eprop[kbthpve].temp[i-1] - eprop[k].temp[i-1]);
								eprop[k].eflux = eprop[k].eflux + conductionfluxtop;
							};
			
						/* 	nthicknessnve = eprop[k].enbour.thicknessnve;
							kthicknessnve = giveneidentityfindk(eprop,nthicknessnve,noof_elements);
							cout<<"serialid of back element is "<<kthicknessnve<<endl;
							
							if(kthicknessnve!=0)
							{
					 			nfaceid1 = nthicknessnve*100;
								nfaceid = nfaceid1%100;
				 				tcthicknessnve = f[nfaceid].tconductivity;
				 				area = (f[nfaceid].lth/f[nfaceid].m * f[nfaceid].bth/n)/f[nfaceid].thickness;
								conductionflux = tcthicknessnve*area*(eprop[kthicknessnve].temp[i-1] - eprop[k].temp[i-1]);
				 				eprop[k].eflux = eprop[k].eflux + conductionflux;
							};

							nthicknesspve = eprop[k].enbour.thicknesspve;
       						        kthicknesspve = giveneidentityfindk(eprop,nthicknesspve,noof_elements);
							
							if(kthicknesspve!=0)
							{
								nfaceid1 = nthicknesspve*100;
				 				nfaceid = nfaceid1%100;
				 				tcthicknesspve = f[nfaceid].tconductivity;
				 				area = (f[nfaceid].lth/f[nfaceid].m * f[nfaceid].bth/n)/f[nfaceid].thickness;
								conductionflux = tcthicknesspve*area*(eprop[kthicknesspve].temp[i-1] - eprop[k].temp[i-1]);
								eprop[k].eflux = eprop[k].eflux + conductionflux;
							};*/

							b++;
							volume = eprop[k].area * eprop[k].thickness;
							cout <<"eprop[k].eflux = "<<eprop[k].eflux<<"Loop number "<<b<<endl;
							eprop[k].temp[i] = (eprop[k].eflux * timestep)/(eprop[k].density * eprop[k].spheat * volume) + eprop[k].temp[i-1];
							out<<k<<" "<<eprop[k].eidentity.i<<" "<<eprop[k].eidentity.j<<" "<<i<<" "<<eprop[k].temp[i]<<" " << b <<" "<<conductionfluxleft<<" "<<conductionfluxright<<" "<<conductionfluxbottom<<" "<<conductionfluxtop<<endl;

							};
						};
					};
				};
				if(transient!=1)
				{	   
					i = 1;
					while(diffcount !=0)
					{
						diffcount = 0;
						for( k=0;k<noof_elements;k++)
					{
        					
						//Boundary temperature						
						if(eprop[k].eload.boundarytemperature.i)
						{
							eprop[k].temp[0] = eprop[k].eload.boundarytemperature.boundarytemp;
							eprop[k].temp[i] = eprop[k].eload.boundarytemperature.boundarytemp;
							b++;
							cout<<"Loop number "<<b<<" Boundary Temperature"<<endl;
						};
			
						if(!eprop[k].eload.boundarytemperature.i)
						{
							sum1=0;
							radflux=0;
							eprop[k].eflux = 0;
							
							//Radiation
							if(eprop[k].eload.radiation.i==true)
							{   
								sum1 = eprop[k].eload.radiation.alpha * eprop[k].temp[i-1] * eprop[k].temp[i-1] * eprop[k].temp[i-1]*eprop[k].temp[i-1];
								sum2 = eprop[k].eload.radiation.alpha * eprop[k].eload.radiation.tempamb * eprop[k].eload.radiation.tempamb * eprop[k].eload.radiation.tempamb*eprop[k].eload.radiation.tempamb;
								radflux = sum2 - sum1 ;
								radiationflux = 0.0000000567*radflux * eprop[k].area;
								eprop[k].eflux = eprop[k].eflux + radiationflux; 
							};
	                    
							if(eprop[k].eload.internalradiation.i)
						{
							iradflux = (eprop[k].eload.internalradiation.alpha*eprop[k].temp[i-1] * eprop[k].temp[i-1] * eprop[k].temp[i-1]*eprop[k].temp[i-1])+(1-eprop[k].eload.internalradiation.alpha)/eprop[k].eload.internalradiation.alpha*absorbed;
                            intradflux = iradflux * eprop[k].area;
	                        eprop[k].eflux = eprop[k].eflux + intradflux; 
							for(m=0;m<noof_elements;m++)
							{
								if(eprop[m].eload.internalradiation.i)
								{
									vf = finding_viewfactor(noof_elements,eprop,fa,f,eprop[m].eserialid,eprop[k].eserialid);
									sumvf = eprop[m].eload.internalradiation.alpha*vf*intradflux+sumvf;
								};
							};
							absorbed = sumvf;
						};
						
	                        			//Constant flux
							if(eprop[k].eload.fluxconstant.i == true)
							{
                             switch (eprop[k].eload.fluxconstant.fluxdirn)
							{
							case 1 : 
								area2 = eprop[k].lth * eprop[k].bth; 
							case 2 :
								area2 = eprop[k].lth * eprop[k].thickness;
							case 3 :
								area2 = eprop[k].bth * eprop[k].thickness;
							default :
								area2 = 1;
							};	
								constantflux = eprop[k].eload.fluxconstant.fluxvalue* area2;
								eprop[k].eflux = eprop[k].eflux + constantflux;
							};
							
 							//Variable flux
							if(eprop[k].eload.fluxvariable.i == true)
							{
							switch (eprop[k].eload.fluxvariable.fluxdirnv)
							{
							case 1 : 
								area3 = eprop[k].lth * eprop[k].bth; 
							case 2 :
								area3 = eprop[k].lth * eprop[k].thickness;
							case 3 :
								area3 = eprop[k].bth * eprop[k].thickness;
							default :
								area3 = 1;
							};
								count1 = 0;vflux = 0;
								for( j=0;j<eprop[k].eload.fluxvariable.h;j++)
								{
									if( eprop[k].eload.fluxvariable.time[j] == i*timestep)
									{
										vflux= eprop[k].eload.fluxvariable.flux[j]*area3;
										count1 ++;
									};
				       				        if(i>eprop[k].eload.fluxvariable.time[j] && i<eprop[k].eload.fluxvariable.time[j+1])
								 	{
										vflux = ((eprop[k].eload.fluxvariable.flux[j+1] - eprop[k].eload.fluxvariable.flux[j])*(i*timestep - eprop[k].eload.fluxvariable.time[j])/(eprop[k].eload.fluxvariable.time[j+1] - eprop[k].eload.fluxvariable.time[j]) + eprop[k].eload.fluxvariable.flux[j])*area3;
										count1++;
									};
									if(count1>0)
					                			break;
								};
								eprop[k].eflux = eprop[k].eflux + vflux;
							};
	                                                                                                   
				      
				 			//Conduction flux left
							nlthnve = eprop[k].enbour.lthnve;
							klthnve = giveneidentityfindk(eprop,nlthnve,noof_elements);
						
							if(klthnve!=0)
							{
								nfaceid1 = nlthnve*100 ;
								nfaceid = nfaceid1 % 100;
								tclthnve = f[nfaceid].tconductivity;
								area = (f[nfaceid].thickness * f[nfaceid].bth/f[nfaceid].n)/(f[nfaceid].lth/f[nfaceid].m); 
								conductionfluxleft = tclthnve*area*(eprop[klthnve].temp[i-1] - eprop[k].temp[i-1]);
								eprop[k].eflux = eprop[k].eflux + conductionfluxleft;
							};
				        
							//Conduction flux right
							nlthpve = eprop[k].enbour.lthpve;
							klthpve = giveneidentityfindk(eprop,nlthpve,noof_elements);
							
							if(klthpve!=0)
							{
								nfaceid1 = nlthpve * 100;
								nfaceid = nfaceid1 % 100;
								tclthpve = f[nfaceid].tconductivity;
								area = (f[nfaceid].thickness * f[nfaceid].bth/f[nfaceid].n)/(f[nfaceid].lth/f[nfaceid].m); 
								conductionfluxright = tclthpve*area*(eprop[klthpve].temp[i-1] - eprop[k].temp[i-1]);
								eprop[k].eflux = eprop[k].eflux + conductionfluxright;
							};
				        
							//Conduction flux bottom							
							nbthnve = eprop[k].enbour.bthnve;
							kbthnve = giveneidentityfindk(eprop,nbthnve,noof_elements);
							if(kbthnve!=0)
							{
								nfaceid1 = nbthnve*100;
								nfaceid = nfaceid1%100;
								tcbthnve = f[nfaceid].tconductivity;
								area = (f[nfaceid].thickness * f[nfaceid].lth/f[nfaceid].m)/(f[nfaceid].bth/f[nfaceid].n);
								conductionfluxbottom = tcbthnve*area*(eprop[kbthnve].temp[i-1] - eprop[k].temp[i-1]);
								eprop[k].eflux = eprop[k].eflux + conductionfluxbottom;
							};
				        
							//Conduction flux top						
							nbthpve = eprop[k].enbour.bthpve;
							kbthpve = giveneidentityfindk(eprop,nbthpve,noof_elements);
							if(kbthpve!=0)
							{
								nfaceid1 = nbthpve*100;
								nfaceid = nfaceid1%100;
								tcbthpve = f[nfaceid].tconductivity;
								area = (f[nfaceid].thickness * f[nfaceid].lth/f[nfaceid].m)/(f[nfaceid].bth/f[nfaceid].n); 
								conductionfluxtop = tcbthpve*area*(eprop[kbthpve].temp[i-1] - eprop[k].temp[i-1]);
								eprop[k].eflux = eprop[k].eflux + conductionfluxtop;
							};
			
						/* 	nthicknessnve = eprop[k].enbour.thicknessnve;
							kthicknessnve = giveneidentityfindk(eprop,nthicknessnve,noof_elements);
							cout<<"serialid of back element is "<<kthicknessnve<<endl;
							
							if(kthicknessnve!=0)
							{
					 			nfaceid1 = nthicknessnve*100;
								nfaceid = nfaceid1%100;
				 				tcthicknessnve = f[nfaceid].tconductivity;
				 				area = (f[nfaceid].lth/f[nfaceid].m * f[nfaceid].bth/n)/f[nfaceid].thickness;
								conductionflux = tcthicknessnve*area*(eprop[kthicknessnve].temp[i-1] - eprop[k].temp[i-1]);
				 				eprop[k].eflux = eprop[k].eflux + conductionflux;
							};

							nthicknesspve = eprop[k].enbour.thicknesspve;
       						        kthicknesspve = giveneidentityfindk(eprop,nthicknesspve,noof_elements);
							
							if(kthicknesspve!=0)
							{
								nfaceid1 = nthicknesspve*100;
				 				nfaceid = nfaceid1%100;
				 				tcthicknesspve = f[nfaceid].tconductivity;
				 				area = (f[nfaceid].lth/f[nfaceid].m * f[nfaceid].bth/n)/f[nfaceid].thickness;
								conductionflux = tcthicknesspve*area*(eprop[kthicknesspve].temp[i-1] - eprop[k].temp[i-1]);
								eprop[k].eflux = eprop[k].eflux + conductionflux;
							};*/

							b++;
							volume = eprop[k].area * eprop[k].thickness;
							cout <<"eprop[k].eflux = "<<eprop[k].eflux<<"Loop number "<<b<<endl;
							eprop[k].temp[i] = (eprop[k].eflux * timestep)/(eprop[k].density * eprop[k].spheat * volume) + eprop[k].temp[i-1];
							out<<k<<" "<<eprop[k].eidentity.i<<" "<<eprop[k].eidentity.j<<" "<<i<<" "<<eprop[k].temp[i]<<" " << b <<" "<<conductionfluxleft<<" "<<conductionfluxright<<" "<<conductionfluxbottom<<" "<<conductionfluxtop<<endl;

							};
						};

						for (k=0;k<noof_elements;k++)
						{
							diff = eprop[k].temp[i] - eprop[k].temp[i-1];
							if(diff >0.001)
							{
								diffcount=1; 
								break;
							};
						};
						cout<<"ith timecycle"<<i<<endl;
						i++;
							
					};
				};
				
				identity identity2;
				int temptime;
				int g = 1;
				
				//Temperature Probing				
				while(g==1)
				{
					cout<<"Time:"<<endl;
					cin>>temptime;
					cout<<"i, j, faceid:"<<endl;
					cin>>identity2.i;
					cin>>identity2.j;
					cin>>identity2.faceid;
					int u;
					for(u=0;u<noof_elements;u++)
					{
						if(eprop[u].eidentity.faceid == identity2.faceid && eprop[u].eidentity.i == identity2.i && eprop[u].eidentity.j == identity2.j)
						{ 
							cout<<"Temperature of the probed element at time "<<temptime<<" is "<<endl;
							cout<<eprop[u].temp[temptime]<<endl;
							break;
						};
					};
					cout<<"Type 1 to probe other temperatures"<<endl;
					cin>>g;
				};
			};         
	              
	                                                                                                                                 

	int main()
	{
		face *f;  
		int fa;
		cout<<"Enter number of faces"<<endl;
		cin>>fa;
		f = new face[5];
		int i,k=0,noof_elements=0,sum;
		load load1;
		load1.radiation.i = false;
		load1.internalradiation.i = false;
		load1.fluxconstant.i = false;
		load1.fluxvariable.i = false;
		load1.boundarytemperature.i = false;
		load1.initialtemperature.i = false;
		elementprop *elementproperties;
		identity identity1;int p,q;
		cout<<"testing"<<endl;
		int m,n;
		for(i=1;i<=fa;i++)
		{
			sum = f[i].read(i);
			noof_elements+=sum;
			m = f[i].m;
			n = f[i].n;
		};
		cout<<"noof_elements: "<<noof_elements<<endl;
		elementproperties = new elementprop[100];		
		cout<<"hi"<<endl;
		for(i=1;i<=fa;i++)
		{
			for(p=1;p<=m;p++)
			{
				for(q=1;q<=n;q++)
				{
					identity1.faceid = i;identity1.i = p; identity1.j = q;
					elementproperties[k].eidentity = identity1;
					elementproperties[k].ecentre = f[i].centref(identity1);
					elementproperties[k].eserialid = k;
                    elementproperties[k].lth = f[i].lth/m;
					elementproperties[k].bth = f[i].bth/n;
					elementproperties[k].eload = load1;
					elementproperties[k].area = (f[i].lth/m)*(f[i].bth/n);
					elementproperties[k].thickness = f[i].thickness;
					elementproperties[k].density = f[i].density;
					elementproperties[k].spheat = f[i].spheat;
					k++;
				};
			};
		};
		for(k=0;k<noof_elements;k++){
           elementproperties[k].enbour = neighbour(elementproperties[k].eidentity,fa,f);
		};
		int fg;		
		int esc=1;
		while(esc==1)
		{
			readloadf(fa,f,elementproperties,noof_elements);
			cout<<"To continue loading press 1"<<endl;
			cin>>esc;
		};

		numerical(elementproperties,f,fa,noof_elements);
		cin>>fg;	
		
	};
