#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;
	  
struct dirn
      {
       float x;
       float y;
       float z;
       };
       struct side
	         {
              dirn vertex1;
              dirn vertex2;
              int i,j;
       
              };
              struct fourside
		            {
                     side stptlthline;
                     side stptbthline;
                     side endptlthline;
                     side endptbthline;
                     };       
			  struct identity
			  {
				  int i,j;
				  int faceid;
			  };
              
       
class face 
    {
      
      private :             
          
      public:
	         
              dirn arbit;
    		  dirn endpt;
			  dirn stptlth;
			  dirn stptbth;
			  fourside fourside1;
	          float thickness;
	          float lth;
              float bth;
              dirn startpt;	
			  dirn normal;    
	          float tconductivity;
			  float spheat;
			  float density;
	          int m,n;
              dirn arbitf();
              int read(int faceid,float size,float tconductivity1,float spheat1,float density1, float thickness1);
              dirn centref(identity eidentity);
              float intersection(identity eidentity, int noof_faces,face *f,int i,int j);
      };


	dirn face::arbitf()
{
	if(normal.x==1 || normal.x==-1)
	{
		arbit.x=thickness;
		arbit.y=lth;
		arbit.z=bth;
	};
	
	if(normal.y==1 || normal.y==-1)
	{ 
		arbit.y=thickness;
		arbit.z=lth;
		arbit.x=bth;
	};
	
	if(normal.z==1 || normal.z==-1)
	{  
	    arbit.z=thickness;
		arbit.x=lth;
		arbit.y=bth;
	};
	
	return arbit;
}

int face::read(int faceid,float size,float tconductivity1,float spheat1,float density1, float thickness1)
{
 
        if(faceid == 1)
        {
          startpt.x = 0;
          startpt.y = 0;
          startpt.z = 0;
          normal.x = 0;
          normal.y = 0;
          normal.z = 1;
          lth = size;
          bth = size;
          thickness = thickness1;
         };
          if(faceid == 2)
        {
          startpt.x = 0;
          startpt.y = 0;
          startpt.z = 0;
          normal.x = 0;
          normal.y = 1;
          normal.z = 0;
          lth = size;
          bth = size;
          thickness = thickness1;
         };
           if(faceid == 3)
        {
          startpt.x = 0;
          startpt.y = 0;
          startpt.z = 0;
          normal.x = 1;
          normal.y = 0;
          normal.z = 0;
          lth = size;
          bth = size;
          thickness = thickness1; 
        };
           if(faceid == 4)
        {
          startpt.x = 0;
          startpt.y = 0;
          startpt.z = size;
          normal.x = 0;
          normal.y = 0;
          normal.z = -1;
          lth = size;
          bth = size;
          thickness = thickness1; 
        };
           if(faceid == 5)
        {
          startpt.x = 0;
          startpt.y = size;
          startpt.z = 0;
          normal.x = 0;
          normal.y = -1;
          normal.z = 0;
          lth = size;
          bth = size;
          thickness = thickness1;
         };
           if(faceid == 6)
        {
          startpt.x = size;
          startpt.y = 0;
          startpt.z = 0;
          normal.x = -1;
          normal.y = 0;
          normal.z = 0;
          lth = size;
          bth = size;
          thickness = thickness1;
         };
        if(normal.x==1 || normal.x==-1)
	{
		stptlth.x=startpt.x;
		stptlth.y=startpt.y+lth;
		stptlth.z=startpt.z;
		stptbth.x=startpt.x;
		stptbth.y=startpt.y;
		stptbth.z=startpt.z+bth;
		endpt.x=startpt.x;
		endpt.y=startpt.y+lth;
		endpt.z=startpt.z+bth;
	};
	
	if(normal.y==1 || normal.y==-1)
	{
		stptlth.x=startpt.x;
		stptlth.y=startpt.y;
		stptlth.z=startpt.z+lth;
		stptbth.x=startpt.x+bth;
		stptbth.y=startpt.y;
		stptbth.z=startpt.z;
		endpt.x=startpt.x+bth;
		endpt.y=startpt.y;
		endpt.z=startpt.z+lth;
	};
	
	if(normal.z==1 || normal.z==-1)
	{
		stptlth.x=startpt.x+lth;
		stptlth.y=startpt.y;
		stptlth.z=startpt.z;
		stptbth.x=startpt.x;
		stptbth.y=startpt.y+bth;
		stptbth.z=startpt.z;
		endpt.x=startpt.x+lth;
		endpt.y=startpt.y+bth;
		endpt.z=startpt.z;
	};
	

        m = (size+0.0025)*20;
        n = (size+0.0025)*20;
	int multiply = m*n;
	
	fourside1.stptlthline.vertex1=startpt;
	fourside1.stptlthline.vertex2=stptlth;
	fourside1.stptlthline.i=0;
	fourside1.stptlthline.j=2; 
	
	fourside1.stptbthline.vertex1=startpt;
	fourside1.stptbthline.vertex2=stptbth;
	fourside1.stptbthline.j=0;
	fourside1.stptbthline.i=1;
	fourside1.endptlthline.vertex1=endpt;
	fourside1.endptlthline.vertex2=stptbth;
	fourside1.endptlthline.i=0;
	fourside1.endptlthline.j=n;
	
	fourside1.endptbthline.vertex1=endpt;
	fourside1.endptbthline.vertex2=stptlth; 
	fourside1.endptbthline.j=0;
	fourside1.endptbthline.i=m;
	
	
        tconductivity = tconductivity1;
        spheat = spheat1;
        density = density1;
	return multiply;
}
	     
dirn face::centref(identity eidentity)
{
	dirn centre=normal;
	dirn arbit;
	int nl=eidentity.i;
	int nb=eidentity.j;
	arbit = arbitf();
	
	if(normal.x==1 || normal.x==-1)
	{
		float l=arbit.y/m;
		float w=arbit.z/n; 
		centre.x=startpt.x+arbit.x/2;
		centre.y=startpt.y+w*nb-w/2;
		centre.z=startpt.z+l*nl-l/2;
	};
	
	if(normal.y==1 || normal.y==-1)
	{
		float l=arbit.z/m;
		float w=arbit.x/n;
		centre.x=startpt.x+w*nb-w/2;
		centre.y=startpt.y+arbit.y/2;
		centre.z=startpt.z+l*nl-l/2;
	};
	
	if(normal.z==1 || normal.z==-1)
	{
		float l=arbit.x/m;
		float w=arbit.y/n;
		centre.x=startpt.x+l*nl-l/2;
		centre.y=startpt.y+w*nb-w/2;
		centre.z=startpt.z+arbit.z/2;
	};
 
	return centre;
}

		 
float face::intersection(identity eidentity, int noof_faces,face *f,int i,int j)
{
	int k;  
	fourside mainedgeset; 
	side edge;
	float retval=0.0; 
	
	
	
	side *edgeset;
	edgeset = new side[4];

	
	if(i==1)
	{
	    edge = fourside1.stptbthline;
    };
	
	if (i==m)
	{
	    edge = fourside1.endptbthline;
	};
	
	if (j==1)
	{
		edge = fourside1.stptlthline; 
	};
	
	if (j==n)
	{
		edge = fourside1.endptlthline;
	};
	
	int nl,nb,faceid;
    nl=eidentity.i; 
	nb=eidentity.j; 
	faceid=eidentity.faceid;
	
	int p;
	for (k=1;k<=noof_faces;k++)
	{
	    if(k!=faceid)
		{
			mainedgeset = f[k].fourside1;
		    edgeset[0]=mainedgeset.stptlthline;
			edgeset[1]=mainedgeset.stptbthline;
			edgeset[2]=mainedgeset.endptlthline;
			edgeset[3]=mainedgeset.endptbthline;
			for(p=0;p<4;p++)
			{
				float faceidinfloat = k;
				if(((edge.vertex1.x==edgeset[p].vertex1.x && edge.vertex1.y==edgeset[p].vertex1.y && edge.vertex1.z==edgeset[p].vertex1.z) || (edge.vertex1.x==edgeset[p].vertex2.x && edge.vertex1.y==edgeset[p].vertex2.y && edge.vertex1.z==edgeset[p].vertex2.z)) && ((edge.vertex2.x==edgeset[p].vertex1.x && edge.vertex2.y==edgeset[p].vertex1.y && edge.vertex2.z==edgeset[p].vertex1.z) || (edge.vertex2.x==edgeset[p].vertex2.x && edge.vertex2.y==edgeset[p].vertex2.y && edge.vertex2.z==edgeset[p].vertex2.z)))
				{
					if(edge.i==1)
					{
						retval = 100*nb+edgeset[p].j+ faceidinfloat/100;
					};
					
					if (edge.i==m)
					{
					    retval=100*nb+edgeset[p].j+faceidinfloat/100;//nbour.right
	                };
					
					if(edge.j==1)
					{
						retval=100*edgeset[p].i+nl+faceidinfloat/100;//nbour.top
					};
					
					if(edge.j==n)
					{
					    retval=100*edgeset[p].i+nl+faceidinfloat/100;//nbour.bottom                                                        
	                };
				};
				
				if(retval!=0)
				    break;
			};
		};
		if(retval!=0)
		    break;    
	};
	
	return retval; 
}



	  
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
	float absorbed;    
	float vfactor;
	bool i;
};
		
struct fluxc
{
	int fluxdirn;
	float fluxvalue;
	float alpha;	
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
	int faceid;
};

struct vfactor
{
	int sid1,sid2,value ;
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
	                 
identity *selectface(face *f,identity *selectedelementidentity, int &totalelements,int type,int fileno)
{
	ifstream in("elementidentity.txt",ios::in);
	int noof_faces;
	int selectedfaceid[10];
	totalelements=0;			
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
		totalelements=k;
	};
			
	if(type==4)
	{			

        noof_faces = 6;
		int k=0,m,n;
		for(int z=1;z<=noof_faces;z++)
		{
			selectedfaceid[z] = z;
			m = f[selectedfaceid[z]].m;
			n = f[selectedfaceid[z]].n;
			cout<<m<<endl;
			cout<<n<<endl;			
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
		totalelements=k;
	};

	if(type==5)
	{			
      int   z = fileno;
		int k=0,m,n;

			selectedfaceid[z] = z;
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
		
		totalelements=k;
	};
	if(type==6)
	{			
	
		int z = fileno;
		int k=0,m,n;
	
			selectedfaceid[z]=z;
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
		
		totalelements=k;
	};
	
	return selectedelementidentity;
};

void readloadf(int fa,face *f,elementprop *elementproperties,int noof_elements, float alpha_ext, float alpha_int, float em_ext, float em_int, float cflux[])
{               
	identity *selectedelement1;
	identity *selectedelement2;
	identity *selectedelement3;
	selectedelement1 = new identity[100];
	int totalselectedelements = 0;			
	identity *selectedelementidentity;
	selectedelementidentity = new identity[100];
	load readload;	int r1,r2,r3,r4,r5,r6,r7;	  				  

	r1 = 1; r2=1; r3=1; r4=1; r5=1; r6=0; r7=0;
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
		readload.radiation.alpha = alpha_ext;
		readload.radiation.epsilon = em_ext;
		readload.radiation.tempamb = 0;
		readload.radiation.vfactor = 1;	       
		selectedelement1 = selectface(f,selectedelementidentity,totalselectedelements,4,0);
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
					elementproperties[k].eload.radiation.i=true;
					elementproperties[k].eload.radiation = readload.radiation;
					count++;
				};
			};
		};
	};
	 
	if(readload.internalradiation.i==true)
	{
		readload.internalradiation.alpha=alpha_int;
		readload.internalradiation.epsilon = em_int;
		selectedelement1 = selectface(f,selectedelementidentity,totalselectedelements,4,0);
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
		k = -1;
		int i;
		for(i=1;i<7;i++)
		{
			readload.fluxconstant.fluxvalue = cflux[i-1];
			readload.fluxconstant.fluxdirn = 1;
			selectedelement1 = selectface(f,selectedelementidentity,totalselectedelements,6,i);
			count=0;
			w=totalselectedelements;
		
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
	};
if(readload.fluxvariable.i==true)
{
	int readfile,fileno = 1,d=0;
	bool t;
	    k = -1;
		readload.fluxvariable.flux = new float[200000];
		readload.fluxvariable.time = new float[200000];
		
		readload.fluxvariable.fluxdirnv = 1;

	for(fileno=1;fileno<=6;fileno++)
	{
                 
		if(fileno == 1)
		{
			ifstream in("xf0.txt",ios::in);
     			while(!in.eof())
           		{
				in>>readload.fluxvariable.time[d];
				in>>readload.fluxvariable.flux[d];
				d++;
              
			};
		};
		
		if(fileno == 2)
		{
			ifstream in("xf1.txt",ios::in);
            		while(!in.eof())
			{
				in>>readload.fluxvariable.time[d];
				in>>readload.fluxvariable.flux[d];
				d++;
			};
    	};

		if(fileno == 3)
		{
       		ifstream in("xf2.txt",ios::in);
			while(!in.eof())
         		{
				in>>readload.fluxvariable.time[d];
				in>>readload.fluxvariable.flux[d];
				d++;
			    };
		};

		if(fileno == 4)
		{
         	ifstream in("xf3.txt",ios::in);
		   	while(!in.eof())
       			{
				in>>readload.fluxvariable.time[d];
				in>>readload.fluxvariable.flux[d];
				d++;
			    };
		};

		if(fileno == 5)
		{
			ifstream in("xf4.txt",ios::in);
		   	while(!in.eof())
        		{
				in>>readload.fluxvariable.time[d];
				in>>readload.fluxvariable.flux[d];
				d++;

			    };
		};

					

	       if(fileno == 6)
  		{
          	ifstream in("xf5.txt",ios::in);
			while(!in.eof())
			{
				in>>readload.fluxvariable.time[d];
				in>>readload.fluxvariable.flux[d];
				d++;
			};
  		};
                
		selectedelement1 = selectface(f,selectedelementidentity,totalselectedelements,5,fileno);
		count=0;
		w=totalselectedelements;
		cout<<w<<endl;
		while(count<w)
		{
			k++;
			for(q=0;q<w;q++)
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
};
	if(readload.boundarytemperature.i==true)
	{
		readload.boundarytemperature.boundarytemp = 273;
		selectedelement1 = selectface(f,selectedelementidentity,totalselectedelements,4,0);
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
					elementproperties[k].eload.boundarytemperature = readload.boundarytemperature;
					elementproperties[k].eload.boundarytemperature.i=true;			  
					count++;
				};
			};
		};
	};

	if(readload.initialtemperature.i==true)
	{
		readload.initialtemperature.initialtemp = 300;
		selectedelement1 = selectface(f,selectedelementidentity, totalselectedelements,4,0);
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
		cout<<"While entering the faces and elements selected put in the element/face on top first " << endl;				
		selectedelement1 = selectface(f,selectedelementidentity,totalselectedelements,3,0);
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
					cout<<"enter faceid of face below n above face of element with i = "<<selectedelement3[q].i<<"and j = "<<selectedelement3[q].j<<" n faceid = "<<selectedelement3[q].faceid<<endl;
					cin>>faceid1;
					cin>>faceid2;
					m1 = f[faceid1].m;n1 = f[faceid1].n; m2 = f[faceid2].m; n2 = f[faceid2].n;
					nodeid_of_currentelement = 100*elementproperties[k].eidentity.i + elementproperties[k].eidentity.j +elementproperties[k].eidentity.faceid/100;
					
					};
				};
			};
		};
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
			
	while(k<(noof_elements-1))
	{
		k++;
		if(eprop1[k].eidentity.faceid == identity1.faceid && eprop1[k].eidentity.i == identity1.i && eprop1[k].eidentity.j == identity1.j)
		{
			count = 9;
			break;
		};
	};
		
	if(count == 0)
		return -1;
	
	else 
		return k;
};	    
float parallelfunction(float x,float y,float eta, float psi, float z)
{
    float p=0;
    float term1=(y-eta)*sqrt((x-psi)*(x-psi)+z*z)*atan((y-eta)/sqrt((x-psi)*(x-psi)+z*z));
    float term2=(x-psi)*sqrt((y-eta)*(y-eta)+z*z)*atan((x-psi)/sqrt((y-eta)*(y-eta)+z*z));
    float term3=0.5*z*z*log((x-psi)*(x-psi) + (y-eta)*(y-eta) + z*z);
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

float power_f(int x,int y)
{
	int i;
	float multiply = 1;
	for(i=0;i<y;i++)
		multiply = multiply*x;
	return multiply;
};
		
float finding_viewfactor( int noof_elements ,elementprop* eprop,int fa,face *f,int sid1,int sid2,vfactor *vf2)
{
    int b;
	float eta[3],psi[3],x[3],y[3],sum=0 ,x1=0,y1=0,z1=0;
    int i = -1,tw,j,nt,k,l,count = 0;
    sum=0;


		int faceid1 = eprop[sid1].eidentity.faceid ;
		int faceid2 = eprop[sid2].eidentity.faceid ;

		if(f[faceid1].normal.z == 1 ||f[faceid1].normal.z == -1)
		{
			if(f[faceid2].normal.z ==1 || f[faceid2].normal.z == -1)
				b = 1;
			else
				b = 0;
			if( b==1)
			{
				x[1] = eprop[sid1].ecentre.x-eprop[sid1].lth/2;
				x[2] = eprop[sid1].ecentre.x+eprop[sid1].lth/2;
				y[1] = eprop[sid1].ecentre.y-eprop[sid1].bth/2;
				y[2] = eprop[sid1].ecentre.y+eprop[sid1].bth/2;
	                  eta[1]=eprop[sid2].ecentre.x-eprop[sid2].lth/2;
					  eta[2]=eprop[sid2].ecentre.x+eprop[sid2].lth/2;
					  psi[1]=eprop[sid2].ecentre.y-eprop[sid2].bth/2;
					  psi[2]=eprop[sid2].ecentre.y+eprop[sid2].bth/2;
					  z1 = f[faceid1].startpt.z - f[faceid2].startpt.z;
				
					};
					if(b==0)
					{
						if(f[faceid2].normal.x == 1 || f[faceid2].normal.x == -1)
						{
							eta[1] = eprop[sid2].ecentre.z - eprop[sid2].bth/2 - (eprop[sid1].ecentre.z - eprop[sid1].thickness/2);
							eta[2] = eprop[sid2].ecentre.z +  eprop[sid2].bth/2 - (eprop[sid1].ecentre.z - eprop[sid1].thickness/2);
							psi[1] = eprop[sid2].ecentre.y-eprop[sid2].lth/2;
							psi[2] = eprop[sid2].ecentre.y + eprop[sid2].lth/2;
							x[1]=eprop[sid1].ecentre.x - eprop[sid1].lth/2 - (eprop[sid2].ecentre.x - eprop[sid2].thickness/2);
							x[2]=eprop[sid1].ecentre.x + eprop[sid1].lth/2 - (eprop[sid2].ecentre.x - eprop[sid2].thickness/2);
							y[1]=eprop[sid1].ecentre.y - eprop[sid1].bth/2;
					        y[2]=eprop[sid1].ecentre.y + eprop[sid1].bth/2;
						}
						else
						{
                            x[1] = eprop[sid1].ecentre.x - eprop[sid1].lth/2;
							x[2] = eprop[sid1].ecentre.x + eprop[sid1].lth/2;
							y[1] = eprop[sid1].ecentre.y - eprop[sid1].bth/2 - (eprop[sid2].ecentre.y - eprop[sid2].thickness/2);
							y[2] = eprop[sid1].ecentre.y + eprop[sid1].bth/2 - (eprop[sid2].ecentre.y - eprop[sid2].thickness/2);
							eta[1]=eprop[sid2].ecentre.z - eprop[sid2].lth/2 - (eprop[sid1].ecentre.z - eprop[sid1].thickness/2);
							eta[2]=eprop[sid2].ecentre.z + eprop[sid2].lth/2 - (eprop[sid1].ecentre.z - eprop[sid1].thickness/2);
							psi[1]=eprop[sid2].ecentre.x - eprop[sid2].bth/2;
					        psi[2]=eprop[sid2].ecentre.x + eprop[sid2].bth/2;
						};   
					};
				};
				if(f[faceid1].normal.x == 1 ||f[faceid1].normal.x == -1)
				{
					if(f[faceid2].normal.x ==1 || f[faceid2].normal.x == -1)
						b = 1;
					else
						b = 0;
				if(b==1)
				{
                      x[1] = eprop[sid1].ecentre.y-eprop[sid1].lth/2;
					  x[2] = eprop[sid1].ecentre.y+eprop[sid1].lth/2;
					  y[1] = eprop[sid1].ecentre.z-eprop[sid1].bth/2;
					  y[2] = eprop[sid1].ecentre.z+eprop[sid1].bth/2;
	                  eta[1]=eprop[sid2].ecentre.y-eprop[sid2].lth/2;
					  eta[2]=eprop[sid2].ecentre.y+eprop[sid2].lth/2;
					  psi[1]=eprop[sid2].ecentre.z-eprop[sid2].bth/2;
					  psi[2]=eprop[sid2].ecentre.z+eprop[sid2].bth/2;
					  z1 = f[faceid1].startpt.x - f[faceid2].startpt.x;
					};
					if(b==0)
					{
                      if(f[faceid2].normal.y == 1 || f[faceid2].normal.y == -1)
						{
							y[1] =	eprop[sid1].ecentre.z - eprop[sid1].bth/2;  
					        y[2] = eprop[sid1].ecentre.z + eprop[sid1].bth/2;
							x[1] = eprop[sid1].ecentre.y-eprop[sid1].lth/2 - (eprop[sid2].ecentre.y-eprop[sid2].thickness/2);
							x[2] = eprop[sid1].ecentre.y+eprop[sid1].lth/2 - (eprop[sid2].ecentre.y-eprop[sid2].thickness/2);
							psi[1]=eprop[sid2].ecentre.z-eprop[sid2].lth/2;
					        psi[2]=eprop[sid2].ecentre.z+eprop[sid2].lth/2;
							eta[1]=eprop[sid2].ecentre.x-eprop[sid2].bth/2 - (eprop[sid1].ecentre.x-eprop[sid1].thickness/2);
							eta[2]=eprop[sid2].ecentre.x+eprop[sid2].bth/2 - (eprop[sid1].ecentre.x-eprop[sid1].thickness/2);
						}
						else
						{ 
							x[1] = eprop[sid1].ecentre.z - eprop[sid1].bth/2 - (eprop[sid2].ecentre.z - eprop[sid2].thickness/2);
							x[2] = eprop[sid1].ecentre.z +  eprop[sid1].bth/2 - (eprop[sid2].ecentre.z - eprop[sid2].thickness/2);
							y[1] = eprop[sid1].ecentre.y-eprop[sid1].lth/2;
							y[2] = eprop[sid1].ecentre.y + eprop[sid1].lth/2;
							eta[1]=eprop[sid2].ecentre.x - eprop[sid2].lth/2 - (eprop[sid1].ecentre.x - eprop[sid1].thickness/2);
							eta[2]=eprop[sid2].ecentre.x + eprop[sid2].lth/2 - (eprop[sid1].ecentre.x - eprop[sid1].thickness/2);
							psi[1]=eprop[sid2].ecentre.y - eprop[sid2].bth/2;
					        psi[2]=eprop[sid2].ecentre.y + eprop[sid2].bth/2;
						};   
					};
				};
                if(f[faceid1].normal.y == 1 ||f[faceid1].normal.y == -1)
				{
					if(f[faceid2].normal.y ==1 || f[faceid2].normal.y == -1)
						b = 1;
					else
						b = 0;
				if(b==1)
				{
                      x[1] =eprop[sid1].ecentre.z-eprop[sid1].lth/2;
					  x[2] = eprop[sid1].ecentre.z+eprop[sid1].lth/2;
					  y[1] = eprop[sid1].ecentre.x-eprop[sid1].bth/2;
					  y[2] = eprop[sid1].ecentre.x+eprop[sid1].bth/2;
	                  eta[1]=eprop[sid2].ecentre.z-eprop[sid2].lth/2;
					  eta[2]=eprop[sid2].ecentre.z+eprop[sid2].lth/2;
					  psi[1]=eprop[sid2].ecentre.x-eprop[sid2].bth/2;
					  psi[2]=eprop[sid2].ecentre.x+eprop[sid2].bth/2;
					  z1 = f[faceid1].startpt.y - f[faceid2].startpt.y;
					};
					if(b==0)
					{
                      if(f[faceid2].normal.x == 1 || f[faceid2].normal.x == -1)
						{                                                                                 //I THINK I MIGHT NEED TO INTERCHANGE X[] N Y[] @ FEW LHS VALUES
							psi[1] =	eprop[sid2].ecentre.z - eprop[sid2].bth/2;  
					        psi[2] = eprop[sid2].ecentre.z + eprop[sid2].bth/2;
							eta[1] = eprop[sid2].ecentre.y-eprop[sid2].lth/2 - (eprop[sid1].ecentre.y-eprop[sid1].thickness/2);
							eta[2] = eprop[sid2].ecentre.y+eprop[sid2].lth/2 - (eprop[sid1].ecentre.y-eprop[sid1].thickness/2);
							y[1]=eprop[sid1].ecentre.z-eprop[sid1].lth/2;
					        y[2]=eprop[sid1].ecentre.z+eprop[sid1].lth/2;
							x[1]=eprop[sid1].ecentre.x-eprop[sid1].bth/2 - (eprop[sid2].ecentre.x-eprop[sid2].thickness/2);
							x[2]=eprop[sid1].ecentre.x+eprop[sid1].bth/2 - (eprop[sid2].ecentre.x-eprop[sid2].thickness/2);
						}
						else
						{
							eta[1] = eprop[sid2].ecentre.x - eprop[sid2].lth/2;
							eta[2] = eprop[sid2].ecentre.x + eprop[sid2].lth/2;
							psi[1] = eprop[sid2].ecentre.y - eprop[sid2].bth/2 - (eprop[sid1].ecentre.y - eprop[sid1].thickness/2);
							psi[2] = eprop[sid2].ecentre.y + eprop[sid2].bth/2 - (eprop[sid1].ecentre.y - eprop[sid1].thickness/2);
							x[1]=eprop[sid1].ecentre.z - eprop[sid1].lth/2 - (eprop[sid2].ecentre.z - eprop[sid2].thickness/2);
							x[2]=eprop[sid1].ecentre.z + eprop[sid1].lth/2 - (eprop[sid2].ecentre.z - eprop[sid2].thickness/2);
							y[1]=eprop[sid1].ecentre.x - eprop[sid1].bth/2;
					        y[2]=eprop[sid1].ecentre.x + eprop[sid1].bth/2;
						};   
					};
				};


		sum = 0;
		for(i=1; i<=2; i++)
		{
			for(j=1; j<=2; j++)
			{
				for(k=1; k<=2; k++)
				{
					for(l=1; l<=2; l++)
					{
						if(b==1)
						{
							sum = sum + parallelfunction(x[i],y[j],eta[k],psi[l],z1)*power_f(-1,i+j+k+l);
						}
						else
							sum = sum + perpendicularfunction(x[i],y[j],eta[k],psi[l])*power_f(-1,i+j+k+l);
					};
				};
			};
		};

		sum = sum/((x[2]-x[1])*(y[2]-y[1]));

		return sum;
	
	if(vf2[i].value==0) 
		return 0;
};

int numerical(elementprop *eprop,face *f,int fa,int noof_elements, float timesteps)
{
	int b=0,tq;
	ofstream out("tempfile.csv",ios::out);
	out<<"Serialid, "<<"i, "<<"j, "<<"Time, "<<"Temp, "<<"Flux, "<<endl;
	float volume,area2,area3;
	float nlthnve=0,nlthpve=0,nbthnve=0,nbthpve=0,nthicknessnve=0,nthicknesspve=0;
	float timestep=0;
	float  tclthnve,tclthpve,tcbthnve,tcbthpve,tcthicknessnve,tcthicknesspve,diff=1;
	float intradfluxfinal;
	int k,i,j,m,p,n,nfaceid1,nfaceid,klthnve,klthpve,kbthnve,kbthpve,kthicknessnve,transient=0,kthicknesspve,count1,diffcount=9;
	float sum1,sum2,radflux,iradflux,vf,sumvf,absorbed,intradflux,radiationflux,conductionfluxleft,conductionfluxright,conductionfluxtop,conductionfluxbottom,vflux,constantflux,area = 0;
	transient = 1;
	if(transient==1)
	{
		timestep = 10;
		n = timesteps;
	}
	vfactor *vf2;

	vf2 = new vfactor[100000];
   


	for(k=0;k<noof_elements;k++)
	{
 
		eprop[k].temp = new float[500000];
		eprop[k].temp[0] = 301;   
		eprop[k].eload.internalradiation.absorbed = 0;
	};
 
	
	if(transient == 1)
	{
		for(i=1;i<=n;i++)
		{
			for(k=0;k<noof_elements;k++)
			{
				conductionfluxleft = 0;conductionfluxright = 0; conductionfluxtop = 0; conductionfluxbottom = 0;
        			if(eprop[k].eload.boundarytemperature.i)
				{
		     			eprop[k].temp[0] = eprop[k].eload.boundarytemperature.boundarytemp;
					eprop[k].temp[i] = eprop[k].eload.boundarytemperature.boundarytemp;
				};
			
				if(!eprop[k].eload.boundarytemperature.i)
				{
					sum1=0;
					sumvf = 0;
					radflux=0;
					eprop[k].eflux = 0;
					iradflux = 0;
					absorbed = 0;
					if(eprop[k].eload.radiation.i==true)
					{   
						sum1 = eprop[k].eload.radiation.epsilon * eprop[k].temp[i-1] * eprop[k].temp[i-1] * eprop[k].temp[i-1]*eprop[k].temp[i-1];
						sum2 = eprop[k].eload.radiation.alpha * eprop[k].eload.radiation.tempamb * eprop[k].eload.radiation.tempamb * eprop[k].eload.radiation.tempamb*eprop[k].eload.radiation.tempamb;
						radflux = sum2 - sum1 ;
                        radiationflux = 0.0000000567*radflux * eprop[k].area;
						eprop[k].eflux = eprop[k].eflux + radiationflux; 
					};
	                		
					if(eprop[k].eload.internalradiation.i)
					{
						int m;							
						for(m=0;m<noof_elements;m++)
						{
							if(eprop[m].eload.internalradiation.i)
							{
								vf=0;
								iradflux = (0.0000000567*eprop[m].eload.internalradiation.epsilon*eprop[m].temp[i-1] * eprop[m].temp[i-1] * eprop[m].temp[i-1]*eprop[m].temp[i-1])+(1-eprop[m].eload.internalradiation.alpha)*eprop[m].eload.internalradiation.absorbed/eprop[m].eload.internalradiation.alpha;
								intradflux = iradflux * eprop[m].area;
								if(eprop[m].eidentity.faceid!=eprop[k].eidentity.faceid)
								vf = finding_viewfactor(noof_elements,eprop,fa,f,eprop[m].eserialid,eprop[k].eserialid,vf2);
								sumvf = eprop[k].eload.internalradiation.alpha*vf*intradflux+sumvf;
                                                                                                                               
							};
						};
							eprop[k].eload.internalradiation.absorbed = sumvf;
							intradfluxfinal = sumvf - 0.0000000567* eprop[k].area* eprop[k].eload.internalradiation.epsilon * eprop[k].temp[i-1] * eprop[k].temp[i-1] * eprop[k].temp[i-1]*eprop[k].temp[i-1] + (1-eprop[k].eload.internalradiation.alpha) * eprop[k].eload.internalradiation.absorbed / eprop[k].eload.internalradiation.alpha;
							eprop[k].eflux = eprop[k].eflux + intradfluxfinal;
					};

									
					if(eprop[k].eload.fluxconstant.i == true)
					{
						switch (eprop[k].eload.fluxconstant.fluxdirn)
						{
							case 1 : 
								area2 = eprop[k].lth * eprop[k].bth; 
                                break;
							case 2 :
								area2 = eprop[k].lth * eprop[k].thickness;
                                break;
							case 3 :
								area2 = eprop[k].bth * eprop[k].thickness;
                                break;
							default :
								area2 = 1;
						};
						constantflux = eprop[k].eload.fluxconstant.fluxvalue*area2;
						eprop[k].eflux = eprop[k].eflux + constantflux;
					};
							 
					if(eprop[k].eload.fluxvariable.i == true)
					{
						count1 = 0;vflux = 0;
						for(j=0;j<10000;j++)        
						{
							switch (eprop[k].eload.fluxvariable.fluxdirnv)
							{
								case 1 : 
									area3 = eprop[k].lth * eprop[k].bth; 
                                    break;
								case 2 :
									area3 = eprop[k].lth * eprop[k].thickness;
                                    break;
								case 3 :
									area3 = eprop[k].bth * eprop[k].thickness;
                                    break;
								default :
									area3 = 1;
							};
						
                                                       
							if(eprop[k].eload.fluxvariable.time[j] == i*timestep)
							{
								vflux= eprop[k].eload.fluxvariable.flux[j] * area3;                                                    
								count1 ++;
							};
							if(i*timestep>eprop[k].eload.fluxvariable.time[j] && i*timestep<eprop[k].eload.fluxvariable.time[j+1])
							{
								vflux = eprop[k].eload.radiation.alpha*((eprop[k].eload.fluxvariable.flux[j+1] - eprop[k].eload.fluxvariable.flux[j])*(i*timestep - eprop[k].eload.fluxvariable.time[j])/(eprop[k].eload.fluxvariable.time[j+1] - eprop[k].eload.fluxvariable.time[j]) + eprop[k].eload.fluxvariable.flux[j])*area3;
                                                               
								count1++;
							};

            
							if(count1>0)
								break;
						};
                            eprop[k].eflux = eprop[k].eflux + vflux;
					};
	                                                                                                   
  
				 	nlthnve = eprop[k].enbour.lthnve;
					klthnve = giveneidentityfindk(eprop,nlthnve,noof_elements);
					
					if(klthnve!=-1)
					{
                        nfaceid1 = nlthnve*100;
						nfaceid = nfaceid1 % 100;
						tclthnve = f[nfaceid].tconductivity;
						area = (f[nfaceid].thickness * f[nfaceid].bth/f[nfaceid].n)/(f[nfaceid].lth/f[nfaceid].m); // lth bth thickness to be rotated accordingly
						conductionfluxleft = tclthnve*area*(eprop[klthnve].temp[i-1] - eprop[k].temp[i-1]);
   						eprop[k].eflux = eprop[k].eflux + conductionfluxleft;
					};
				        
					nlthpve = eprop[k].enbour.lthpve;
					klthpve = giveneidentityfindk(eprop,nlthpve,noof_elements);
					if(klthpve!=-1)
					{
						nfaceid1 = nlthpve*100;
						nfaceid = nfaceid1 %100;
						tclthpve = f[nfaceid].tconductivity;
						area = (f[nfaceid].thickness * f[nfaceid].bth/f[nfaceid].n)/(f[nfaceid].lth/f[nfaceid].m); 
						conductionfluxright = tclthpve*area*(eprop[klthpve].temp[i-1] - eprop[k].temp[i-1]);
                        eprop[k].eflux = eprop[k].eflux + conductionfluxright;
					};

					nbthnve = eprop[k].enbour.bthnve;
					kbthnve = giveneidentityfindk(eprop,nbthnve,noof_elements);
					if(kbthnve!=-1)
					{
						nfaceid1 = nbthnve*100;
						nfaceid = nfaceid1%100;
						tcbthnve = f[nfaceid].tconductivity;
						area = (f[nfaceid].thickness * f[nfaceid].lth/f[nfaceid].m)/(f[nfaceid].bth/f[nfaceid].n); 
						conductionfluxbottom = tcbthnve*area*(eprop[kbthnve].temp[i-1] - eprop[k].temp[i-1]);
                        eprop[k].eflux = eprop[k].eflux + conductionfluxbottom;
					};
				        
					nbthpve = eprop[k].enbour.bthpve;
					kbthpve = giveneidentityfindk(eprop,nbthpve,noof_elements);
                    	if(kbthpve!=-1)
					{
						nfaceid1 = nbthpve*100;
						nfaceid = nfaceid1%100;
						tcbthpve = f[nfaceid].tconductivity;
						area = (f[nfaceid].thickness * f[nfaceid].lth/f[nfaceid].m)/(f[nfaceid].bth/f[nfaceid].n); 
						conductionfluxtop = tcbthpve*area*(eprop[kbthpve].temp[i-1] - eprop[k].temp[i-1]);
                        eprop[k].eflux = eprop[k].eflux + conductionfluxtop;
					};
			
		
					b++;
					volume = eprop[k].area * eprop[k].thickness;
					eprop[k].temp[i] = (eprop[k].eflux * timestep)/(eprop[k].density*eprop[k].spheat*volume) + eprop[k].temp[i-1];
					out<<k<<", "<<eprop[k].eidentity.i<<", "<<eprop[k].eidentity.j<<", "<<i*timestep<<", "<<eprop[k].temp[i]<<", "<<eprop[k].eflux<<", "<<radiationflux<<", "<<intradfluxfinal<<", "<<constantflux<<", "<<vflux<<endl;
				};
			};
		};
	};
	return n;
};         
	              
int main()
{
        float size;
        float tconductivity,spheat,density, thickness, alpha_ext, em_ext, alpha_int, em_int, cflux[6], timesteps;
	face *f;  
	int fa;
	fa = 6;
	f = new face[8];
	int i,k=0,noof_elements=0,sum;
	int z=0;
	load load1;
	load1.radiation.i = false;
	load1.internalradiation.i = false;
	load1.fluxconstant.i = false;
	load1.fluxvariable.i = false;
	load1.boundarytemperature.i = false;
	load1.initialtemperature.i = false;
	elementprop *elementproperties;
	elementproperties = new elementprop[100000];
	identity identity1;int p,q;
	ifstream in1("input.txt",ios::in);        
	ifstream in2("input1.txt",ios::in);        
	cout<<"enter size of cube, thermal conductivity, specific heat, density, thickness "<<endl;
        in1>>size;
        in1>> tconductivity;
        in1>>spheat;
        in1>>density;
	in1>>thickness;
	in1>>alpha_ext;
	in1>>em_ext;
	in1>>alpha_int;
	in1>>em_int;
	for(i=0; i < 6; i++)
		in1>>cflux[i];
	
	in2>>timesteps;
	for(i=1;i<=fa;i++)
	{
		sum = f[i].read(i,size,tconductivity,spheat,density, thickness);
		noof_elements+=sum;
		int m = f[i].m;
		int n = f[i].n;
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
		
	int fg;
	float nodeid; 
	int nodeidinint; 
	
	
	int nsteps,faceid3;
	float average[10],sumtemp=0,elements_in_a_face;
	average[0] = 0;
	elements_in_a_face = size*size*20*20;
	readloadf(fa,f,elementproperties,noof_elements, alpha_ext, alpha_int, em_ext, em_int, cflux);

	nsteps = numerical(elementproperties,f,fa,noof_elements, timesteps);
    	ofstream out("faceavg.csv",ios::out);
	out<<"time, "<<"face1, "<<"face2, "<<"face3, "<<"face4, "<<"face5, "<<"face6, "<<endl;
	for(i=0;i<nsteps;i++)
	{
	    for(faceid3=1;faceid3<7;faceid3++)
	        {
		       sumtemp = 0;
			for(k=0;k<noof_elements;k++)
			     {
				     if(elementproperties[k].eidentity.faceid == faceid3)
				     {
					  sumtemp = sumtemp+elementproperties[k].temp[i];
					 };
			     };
			   average[faceid3] = sumtemp/elements_in_a_face;
		    };
			out<<i*10<<", "<<average[1]<<", "<<average[2]<<", "<<average[3]<<", "<<average[4]<<", "<<average[5]<<", "<<average[6]<<endl;   
	};
	return 1;
};
