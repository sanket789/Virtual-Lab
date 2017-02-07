#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;
	  
//begin face.h
struct dirn{
       float x;
       float y;
       float z;
       };
       struct side{
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
			  struct identity{
				  int i,j;
				  int faceid;
			  };
              
       
class face {
      
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
              int read(int faceid,float size,float tconductivity1,float spheat1,float density1);
              dirn centref(identity eidentity);
              float intersection(identity eidentity, int noof_faces,face *f,int i,int j);
           //   fourside edgef();
               };

//end face.h

//begin face.cpp

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

//Inputs from user and returns the total number of elements on the face	     
int face::read(int faceid,float size,float tconductivity1,float spheat1,float density1)
{
  /*  cout<<endl<<endl<<"New Face:"<<endl<<"Geometry:"<<endl;
	cout<<"Enter startpt x co-ordinate"<<endl;
	cin>>startpt.x;
	cout<<"Enter startpt y co-ordinate"<<endl;
	cin>>startpt.y;
	cout<<"Enter startpt z co-ordinate"<<endl;
	cin>>startpt.z;
	cout<<"Enter unit normal vector "<<endl;
	cin>>normal.x;
	cin>>normal.y;
	cin>>normal.z;
	
	cout<<"Enter the length of face "<<endl;
	cin>>lth;
	cout<<"Enter the breadth of face"<<endl;
	cin>>bth;
	cout<<"Enter thickness of face"<<endl;
	cin>>thickness;
	*/
	//Assignment of all the four vertices
	
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
          thickness = 0.003;
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
          thickness = 0.003;
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
          thickness = 0.003; 
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
          thickness = 0.003; 
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
          thickness = 0.003;
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
          thickness = 0.003;
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
	
/*	cout<<"Meshing:"<<endl;
	cout <<"Enter number of elements along length of the face"<<endl;
	cin>>m;
	cout <<"Enter number of elements along breadth of the face"<<endl;
	cin>>n;
*/
        m = size*100;
        n = size*100;
	int multiply = m*n;
	
	//Assignment of the four edges
	fourside1.stptlthline.vertex1=startpt;
	fourside1.stptlthline.vertex2=stptlth;
	fourside1.stptlthline.i=0;
	fourside1.stptlthline.j=2; //can be any random value except 0 or n-1
	
	fourside1.stptbthline.vertex1=startpt;
	fourside1.stptbthline.vertex2=stptbth;
	fourside1.stptbthline.j=0;
	fourside1.stptbthline.i=1;
	fourside1.endptlthline.vertex1=endpt;
	fourside1.endptlthline.vertex2=stptbth;
	fourside1.endptlthline.i=0;
	fourside1.endptlthline.j=n;
	
	fourside1.endptbthline.vertex1=endpt;
	fourside1.endptbthline.vertex2=stptlth; // watch its stptlt n not stptbth 
	fourside1.endptbthline.j=0;
	fourside1.endptbthline.i=m;
	
/*	cout<<"Material Properties:"<<endl;
	cout<<"Thermal conductivity: "<<endl;
	cin>>tconductivity;
	cout<<"Specific heat"<<endl;
	cin>>spheat;
	cout<<"Density:"<<endl;
	cin>>density; 
*/	
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
	int k; //counter   
	fourside mainedgeset; //stores the foursides of the face
	side edge; //Edge under consideration for intersection 
	float retval=0.0; //node id
	
	// my code won't work if there are 2 edges of 2 diff faces r connected to d same edge of given face
	
	side *edgeset;
	edgeset = new side[4];

	//finding out the side under consideration
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
//end face.cpp


	  
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
	float alpha;	
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

/*
float thicknessnbourf(dirn centre,int faceid1,face *f, int m1,int n1)
{
	int i,j;
	float retval = 0.0;
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
					  
				if(retval!=0.0)
					break;
			};
					
			if(retval!=0.0)  
				break;
		};
	};
	
	return retval;
};
*/	    

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
//  int type;
	totalelements=0;			
/*	cout<<"Face/Element selection"<<endl;
	cout<<"Type 1 to select faces"<<endl;
	cout<<"Type 2 to select elements"<<endl;
	cout<<"Type 3 to select both faces and elements"<<endl;
	cin>>type;
*/	if(type==1)
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
			
	if(type==4)
	{			
//		cout<<"Enter number of faces you want to select (should be less than 10)"<<endl;
//		cin>>noof_faces;
        noof_faces = 6;
		int k=0,m,n;
		for(int z=1;z<=noof_faces;z++)
		{
		//	cout<<"Enter the face ids"<<endl;
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
		cout<<"The number of selected elements are "<<k<<endl;
		totalelements=k;
	};

	if(type==5)
	{			
//		cout<<"Enter number of faces you want to select (should be less than 10)"<<endl;
//		cin>>noof_faces;
      int   z = fileno;
		int k=0,m,n;
//		for(int z=1;z<=noof_faces;z++)
//		{
	//		cout<<"Enter the face ids"<<endl;
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
//		
		cout<<"The number of selected elements are "<<k<<endl;
		totalelements=k;
	};
	if(type==6)
	{			
	//	cout<<"Enter number of faces you want to select (should be less than 10)"<<endl;
	//	cin>>noof_faces;
		int z = fileno;
		int k=0,m,n;
	//	for(int z=1;z<=noof_faces;z++)
	//	{
		//	cout<<"Enter the face id"<<endl;
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
	};
	
	return selectedelementidentity;
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
	cout<<endl<<"Load application:"<<endl;
/*	cout<<"Radiation (1=yes, 0=no) "<<endl;
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
*/
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
		cout<<"surface external properties :Enter Absorptivity, Emissivity, in the mentioned order"<<endl;
		cin>>readload.radiation.alpha;
		cin>>readload.radiation.epsilon;
		cout<<"Hi"<<endl;
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
		cout<<" surface internal properties :Enter Absorptivity & Emissivity epsilon"<<endl;
		cin>>readload.internalradiation.alpha;
		cin>>readload.internalradiation.epsilon;
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
	 
	if(readload.fluxconstant.i==true)        //pain hoga i.e if faces input are not in ascending order then wrong elements'l be assigned the fluxconstant value
	{
		k = -1;
		int i;
		for(i=1;i<7;i++)
		{
		cout<<"Enter flux value"<<endl;
		cin>>readload.fluxconstant.fluxvalue;
	//	cout<<"enter 1 if fluxdirection's parallel to thickness else if parallel to breadth enter 2 else enter 3 if parallel to length of face"<<endl;
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
		readload.fluxvariable.flux = new float[20000];
		readload.fluxvariable.time = new float[20000];
		cout<<"Enter absorptivity"<<endl;
		cin>>readload.fluxvariable.alpha;
		
		//cout<<"enter 1 if fluxdirection's perpendicular to thickness else if perpendicular to breadth enter 2 else enter 3 if perpendicular to length of face"<<endl;
		readload.fluxvariable.fluxdirnv = 1;
	//	cout<<"enter file number"<<endl;
	//	cin>>fileno;
	    
	for(fileno=1;fileno<=6;fileno++)
	{
                 
		if(fileno == 1)
		{
                        ofstream out("view1.csv",ios::out);
			ifstream in("1.csv",ios::in);
			cout<<"testing1"<<endl;
     			while(!in.eof())
           		{
				in>>readload.fluxvariable.time[d];
				in>>readload.fluxvariable.flux[d];
				d++;
                               
	                        out<<","<<readload.fluxvariable.time[d-1]<<","<<readload.fluxvariable.flux[d-1]<<endl;
                               
                               
			};
			cout<<"File 1 read"<<endl;		
		};
		
		if(fileno == 2)
		{
                        ofstream out("view2.csv",ios::out);
			cout<<"Started reading file 2"<<endl;			
			ifstream in("2.csv",ios::in);
            		while(!in.eof())
			//  for(int d = 0;d<readload.fluxvariable.h;d++)   // use end of file condn in while loop
			{
				in>>readload.fluxvariable.time[d];
				in>>readload.fluxvariable.flux[d];
				d++;
                                out<<","<<readload.fluxvariable.time[d-1]<<","<<readload.fluxvariable.flux[d-1]<<endl;
			};
			cout<<"File 2 read"<<endl;
	    	};

		if(fileno == 3)
		{
                        ofstream out("view3.csv",ios::out);
             		ifstream in("3.csv",ios::in);
			while(!in.eof())
         		{
				in>>readload.fluxvariable.time[d];
				in>>readload.fluxvariable.flux[d];
				d++;
                                out<<","<<readload.fluxvariable.time[d-1]<<","<<readload.fluxvariable.flux[d-1]<<endl;
			};
			cout<<"File 3 read"<<endl;
		};

		if(fileno == 4)
		{
         	   	ifstream in("4.csv",ios::in);
		   	while(!in.eof())
       			{
				in>>readload.fluxvariable.time[d];
				in>>readload.fluxvariable.flux[d];
				d++;
			};
			cout<<"File 4 read"<<endl;
		};

		if(fileno == 5)
		{
               	        ifstream in("5.csv",ios::in);
		   	while(!in.eof())
        		{
				in>>readload.fluxvariable.time[d];
				in>>readload.fluxvariable.flux[d];
				d++;

			};
                        
			cout<<"File 5 read"<<endl;
		};

					

	       if(fileno == 6)
  		{
          		ifstream in("6.csv",ios::in);
			while(!in.eof())
			{
				in>>readload.fluxvariable.time[d];
				in>>readload.fluxvariable.flux[d];
				d++;
			};
  			cout<<"File 6 read"<<endl;      
  		};
                
   //             readload.fluxvariable.h = d;
     //           d = 0;

		selectedelement1 = selectface(f,selectedelementidentity,totalselectedelements,5,fileno);
		cout<<"dsdaAaadsa"<<endl;
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
					cout<<count<<endl;
				};
			};
		};
        
		cout<<fileno<<endl;
               
	};
};
	if(readload.boundarytemperature.i==true)
	{
	//	cout<<"Enter fixed boundary temperature"<<endl;
		readload.boundarytemperature.boundarytemp = 273;
		selectedelement1 = selectface(f,selectedelementidentity,totalselectedelements,4,0);
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
					elementproperties[k].eload.boundarytemperature = readload.boundarytemperature;
					elementproperties[k].eload.boundarytemperature.i=true;			  
					count++;
				};
			};
		};
	};

	if(readload.initialtemperature.i==true)
	{
	//	cout<<"Enter initial temperature"<<endl;
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
					
/*if(elementproperties[k].enbour.thicknessnve == 0)
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
					};*/
					
				};
			};
		};
	};
};
/*
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
*/
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
			cout <<"count = "<<count<<endl;
			break;
		};
	};
		
	if(count == 0)
		return -1;
	
	else 
		return k;
};


void shadowingf(int noof_elements ,elementprop* eprop,int fa,face *f,vfactor *vf2)
{
	int k,i,j,l,p=0,q=0,u1=0,u2=0,u3=0,count1 = 19;
	float y0,x0,z0;
	viewfactor *vf1;
	vf1 = new viewfactor[100];
	for (k =0;k<noof_elements;k++)
	{
		if(eprop[k].eload.internalradiation.i)
		{
			vf1[p].x = eprop[k].ecentre.x;
			vf1[p].y = eprop[k].ecentre.y;
			vf1[p].z = eprop[k].ecentre.z;
			vf1[p].sid = eprop[k].eserialid;
			vf1[p].faceid = eprop[k].eidentity.faceid;
			p++;
		};
	};
	
	for (k =1;k<=fa;k++)
	{
		for(i=0;i<p;i++)
		{
			for(j=0;j<p;j++)
			{
				count1 = 11;  // they 'l become 9 if execution's over
				if(vf1[i].faceid!=vf1[j].faceid)
				{
					if(f[k].normal.x == 1 || f[k].normal.x == -1)
					{
						if((f[k].startpt.x + f[k].thickness/2 - vf1[i].x)*(f[k].startpt.x + f[k].thickness/2 - vf1[j].x) <0)
						{
							y0 =  ((f[k].startpt.x + f[k].thickness/2 - vf1[i].x)*( vf1[i].y - vf1[j].y)/(vf1[i].x - vf1[j].x)) + vf1[i].y;
							z0 =   ((f[k].startpt.x + f[k].thickness/2 - vf1[i].x)*( vf1[i].z - vf1[j].z)/(vf1[i].x - vf1[j].x)) + vf1[i].z; 
							if(((y0-f[k].startpt.y)*(y0-(f[k].startpt.y+f[k].lth))<=0)&& ((z0-f[k].startpt.z)*(z0-(f[k].startpt.z+f[k].bth))<=0))
							{
								vf2[u1].value = 0;                          // shadowin occurs so o view factor
								vf2[u1].sid1 = vf1[i].sid;
								vf2[u1].sid2 = vf1[j].sid;
								u1++;   
								count1 = 9;
							};
							
							if(count1!=9)
							{
								vf2[u1].value = 1;                          // shadowin occurs so o view factor
								vf2[u1].sid1 = vf1[i].sid;
								vf2[u1].sid2 = vf1[j].sid;
								u1++; 
								count1 = 9;
							};
						}; 
						if(count1!=9)
						{
							vf2[u1].value = 1;                          // shadowin occurs so o view factor
							vf2[u1].sid1 = vf1[i].sid;
							vf2[u1].sid2 = vf1[j].sid;
							u1++; 
							count1 = 9;
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
								vf2[u1].value = 0;
								vf2[u1].sid1 = vf1[i].sid;
								vf2[u1].sid2 = vf1[j].sid;
								u1++;      
								count1 = 9;
							};
							if(count1!=9)
							{
								vf2[u1].value = 1;                          // shadowin occurs so o view factor
								vf2[u1].sid1 = vf1[i].sid;
								vf2[u1].sid2 = vf1[j].sid;
								u1++; 
								count1 = 9;
							};
						};
						if(count1!=9)
						{
							vf2[u1].value = 1;                          // shadowin occurs so o view factor
							vf2[u1].sid1 = vf1[i].sid;
							vf2[u1].sid2 = vf1[j].sid;
							u1++; 
							count1 = 9;
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
								vf2[u1].value = 0;
								vf2[u1].sid1 = vf1[i].sid;
								vf2[u1].sid2 = vf1[j].sid;
								u1++;      
								count1 = 9;
							};
							
							if(count1!=9)
							{
								vf2[u1].value = 1;                          // shadowin occurs so o view factor
								vf2[u1].sid1 = vf1[i].sid;
								vf2[u1].sid2 = vf1[j].sid;
								u1++; 
								count1 = 9;
							};
						};
						
						if(count1!=9)
						{
							vf2[u1].value = 1;                          // shadowin occurs so o view factor
							vf2[u1].sid1 = vf1[i].sid;
							vf2[u1].sid2 = vf1[j].sid;
							u1++; 
							count1 = 9;
						};
					};
				};

				if(count1!=9)
				{
					vf2[u1].value = 1;                          // shadowin occurs so o view factor
					vf2[u1].sid1 = vf1[i].sid;
					vf2[u1].sid2 = vf1[j].sid;
					u1++; 
					count1 = 9;
				};
			};
		};
	};
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

/*
	ofstream out1("vfactorcheckfile.csv",ios::out);
	while (count!=1)
	{
		i++;
		out1<<"vfsid1 = "<<vf2[i].sid1<<"vfsid2 = "<<vf2[i].sid2<<"sid1 = "<<sid1<<"sid2 = "<<sid2<<endl;
		
		if((vf2[i].sid1 == sid1 && vf2[i].sid2 == sid2) || (vf2[i].sid1 == sid2 && vf2[i].sid2 == sid1))
		{
			count = 1;
            break;
		};
	};
*/


	//if(vf2[i].value == 0)
	//	return 0;

	//if(vf2[i].value == 1)
	//{
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
	
	if(vf2[i].value==0) // note i 's not an incrementvalue once it comes out of while loop its a constant
		return 0;
};

void numerical(elementprop *eprop,face *f,int fa,int noof_elements)
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
	cout<<"Is conduction transient ? type 1 if yes"<<endl;
	cin>>transient;
	if(transient==1)
	{
		cout<<"Enter maximum time step"<<endl;
		cin>>timestep;
		cout<<"Enter number of timesteps"<<endl;
		cin>>n;
	}
	vfactor *vf2;

	vf2 = new vfactor[1000];
   
	//shadowingf(noof_elements,eprop,fa,f,vf2);

	for(k=0;k<noof_elements;k++)
	{
 
		eprop[k].temp = new float[50000];
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
						eprop[k].eflux = eprop[k].eflux + radiationflux; // i doubt if array of eflux with time is needed
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
						for(j=0;j<100;j++)           //replace 100 by readload.fluxvariable.h
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
								vflux = ((eprop[k].eload.fluxvariable.flux[j+1] - eprop[k].eload.fluxvariable.flux[j])*(i*timestep - eprop[k].eload.fluxvariable.time[j])/(eprop[k].eload.fluxvariable.time[j+1] - eprop[k].eload.fluxvariable.time[j]) + eprop[k].eload.fluxvariable.flux[j])*area3;
                                                               
								count1++;
							};

					/*		cout<<"flux"<<eprop[k].eload.fluxvariable.flux[j+1]<<"@j flux"<<eprop[k].eload.fluxvariable.flux[j]<<"time"<<eprop[k].eload.fluxvariable.time[j+1]<<"@j time"<<eprop[k].eload.fluxvariable.time[j]<<endl;
                                          */             
							if(count1>0)
								break;
						};
                                                 eprop[k].eflux = eprop[k].eflux + vflux;
					};
	                                                                                                   
  
				 	nlthnve = eprop[k].enbour.lthnve;
					klthnve = giveneidentityfindk(eprop,nlthnve,noof_elements);
					
				//	cout<<eprop[klthnve].temp[i-1];
					if(klthnve!=-1)
					{                                                nfaceid1 = nlthnve*100;
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
						area = (f[nfaceid].thickness * f[nfaceid].bth/f[nfaceid].n)/(f[nfaceid].lth/f[nfaceid].m); // lth bth thickness to be rotated accordingly
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
						area = (f[nfaceid].thickness * f[nfaceid].lth/f[nfaceid].m)/(f[nfaceid].bth/f[nfaceid].n); // lth bth thickness to be rotated accordingly
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
													  };
													  // note a lot of things 've been changed to the non commented parts n needs to be done to this part too
	*/
					b++;
					volume = eprop[k].area * eprop[k].thickness;
					eprop[k].temp[i] = (eprop[k].eflux * timestep)/(eprop[k].density*eprop[k].spheat*volume) + eprop[k].temp[i-1];
					out<<k<<", "<<eprop[k].eidentity.i<<", "<<eprop[k].eidentity.j<<", "<<i*timestep<<", "<<eprop[k].temp[i]<<", "<<eprop[k].eflux<<", "<<radiationflux<<", "<<intradfluxfinal<<", "<<constantflux<<", "<<vflux<<endl;
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
						sum1 = eprop[k].eload.radiation.alpha * eprop[k].temp[i-1] * eprop[k].temp[i-1] * eprop[k].temp[i-1]*eprop[k].temp[i-1];
						sum2 = eprop[k].eload.radiation.alpha * eprop[k].eload.radiation.tempamb * eprop[k].eload.radiation.tempamb * eprop[k].eload.radiation.tempamb*eprop[k].eload.radiation.tempamb;
						radflux = sum2 - sum1 ;
						radiationflux = 0.0000000567*radflux * eprop[k].area;
						eprop[k].eflux = eprop[k].eflux + radiationflux; // i doubt if array of eflux with time is needed
					};
	                if(eprop[k].eload.internalradiation.i)
					{
						float intradfluxfinal;
						int m;							
						for(m=0;m<noof_elements;m++)
						{
							if(eprop[m].eload.internalradiation.i)
							{
								vf=0;
								iradflux = (0.0000000567*eprop[m].eload.internalradiation.alpha*eprop[m].temp[i-1] * eprop[m].temp[i-1] * eprop[m].temp[i-1]*eprop[m].temp[i-1])+(1-eprop[m].eload.internalradiation.alpha)*eprop[m].eload.internalradiation.absorbed/eprop[m].eload.internalradiation.alpha;
								intradflux = iradflux * eprop[m].area;
								if(eprop[m].eidentity.faceid!=eprop[k].eidentity.faceid)
									vf = finding_viewfactor(noof_elements,eprop,fa,f,eprop[m].eserialid,eprop[k].eserialid,vf2);
								sumvf = eprop[k].eload.internalradiation.alpha*vf*intradflux+sumvf;
							};
						};
							eprop[k].eload.internalradiation.absorbed = sumvf;
							intradfluxfinal = sumvf - 0.0000000567* eprop[k].area* eprop[k].eload.internalradiation.alpha * eprop[k].temp[i-1] * eprop[k].temp[i-1] * eprop[k].temp[i-1]*eprop[k].temp[i-1] + (1-eprop[k].eload.internalradiation.alpha) * eprop[k].eload.internalradiation.absorbed / eprop[k].eload.internalradiation.alpha;							
							eprop[k].eflux = eprop[k].eflux + intradfluxfinal;
					};

									
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
						constantflux = eprop[k].eload.fluxconstant.fluxvalue*area2;
						eprop[k].eflux = eprop[k].eflux + constantflux;
					};
							 
					if(eprop[k].eload.fluxvariable.i == true)
					{
						count1 = 0;vflux = 0;
						for( j=0;j<eprop[k].eload.fluxvariable.h;j++)
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
							
							if(eprop[k].eload.fluxvariable.time[j] == i)
							{
								vflux= eprop[k].eload.fluxvariable.flux[j] * area3;
								count1 ++;
							};
							if(i>eprop[k].eload.fluxvariable.time[j] && i<eprop[k].eload.fluxvariable.time[j+1])
							{
								vflux = ((eprop[k].eload.fluxvariable.flux[j+1] - eprop[k].eload.fluxvariable.flux[j])*(i - eprop[k].eload.fluxvariable.time[j])/(eprop[k].eload.fluxvariable.time[j+1] - eprop[k].eload.fluxvariable.time[j]) + eprop[k].eload.fluxvariable.flux[j])*area3;
								count1++;
							};
							
							if(count1>0)
								break;
						};
						eprop[k].eflux = eprop[k].eflux + vflux;
					};
	                                                                                                   
				      
				 	nlthnve = eprop[k].enbour.lthnve;
					klthnve = giveneidentityfindk(eprop,nlthnve,noof_elements);
					if(klthnve!=0)
					{
						nfaceid1 = nlthnve*100 ;
						nfaceid = nfaceid1 % 100;
						tclthnve = f[nfaceid].tconductivity;
						area = (f[nfaceid].thickness * f[nfaceid].bth/f[nfaceid].n)/(f[nfaceid].lth/f[nfaceid].m); // lth bth thickness to be rotated accordingly
						conductionfluxleft = tclthnve*area*(eprop[klthnve].temp[i-1] - eprop[k].temp[i-1]);
						eprop[k].eflux = eprop[k].eflux + conductionfluxleft;
					};
				        
					nlthpve = eprop[k].enbour.lthpve;
					klthpve = giveneidentityfindk(eprop,nlthpve,noof_elements);
					if(klthpve!=0)
					{
						nfaceid1 = nlthpve*100;
						nfaceid = nfaceid1 %100;
						tclthpve = f[nfaceid].tconductivity;
						area = (f[nfaceid].thickness * f[nfaceid].bth/f[nfaceid].n)/(f[nfaceid].lth/f[nfaceid].m); // lth bth thickness to be rotated accordingly
						conductionfluxright = tclthpve*area*(eprop[klthpve].temp[i-1] - eprop[k].temp[i-1]);
						eprop[k].eflux = eprop[k].eflux + conductionfluxright;
					};
				        
					nbthnve = eprop[k].enbour.bthnve;
					kbthnve = giveneidentityfindk(eprop,nbthnve,noof_elements);
					if(kbthnve!=0)
					{
						nfaceid1 = nbthnve*100;
						nfaceid = nfaceid1%100;
						tcbthnve = f[nfaceid].tconductivity;
						area = (f[nfaceid].thickness * f[nfaceid].lth/f[nfaceid].m)/(f[nfaceid].bth/f[nfaceid].n); // lth bth thickness to be rotated accordingly
						conductionfluxbottom = tcbthnve*area*(eprop[kbthnve].temp[i-1] - eprop[k].temp[i-1]);
						eprop[k].eflux = eprop[k].eflux + conductionfluxbottom;
					};
				        
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
													  };
													  // note a lot of things 've been changed to the non commented parts n needs to be done to this part too
	*/

					b++;
					volume = eprop[k].area * eprop[k].thickness;
					eprop[k].temp[i] = (eprop[k].eflux * timestep)/(eprop[k].density*eprop[k].spheat*volume) + eprop[k].temp[i-1];// if ist term in rhs is 10^-2 times smaller to 301 (2nd term) then rhs 'l be rounded of to 301 so tc
					out<<k<<", "<<eprop[k].eidentity.i<<", "<<eprop[k].eidentity.j<<", "<<i<<", "<<eprop[k].temp[i]<<", "<<eprop[k].eflux<<endl;
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
			i++;
		};
	};
	
	identity identity2;
	int temptime;
	int g = 0;
	while(g!=1)
	{
		cout<<"enter time wen u want to see the temp"<<endl;
		cin>>temptime;
		cout<<"enter i,j and faceid of the element whose temp is to be found"<<endl;
		cin>>identity2.i;
		cin>>identity2.j;
		cin>>identity2.faceid;
		int u;
		for( u=0;u<noof_elements;u++)
		{
			if(eprop[u].eidentity.faceid == identity2.faceid && eprop[u].eidentity.i == identity2.i && eprop[u].eidentity.j == identity2.j)
			{ 
				cout<<"temp of "<<u<<"th element at  "<<temptime<<" is "<<endl;
				cout<<eprop[u].temp[temptime]<<endl;
				break;
			};
		};
		cout<<"type 1 to leave the loop else any other no"<<endl;
		cin>>g;
	};
};         
	              
int main()
{
        float size;
        float tconductivity,spheat,density;
	face *f;  
	int fa;
	cout<<"enter no.of faces"<<endl;
	cin>>fa;
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
	elementproperties = new elementprop[10000];
	identity identity1;int p,q;
        cout<<"enter size of cube, thermal conductivity, specific heat, density "<<endl;
        cin>>size;
        cin>> tconductivity;
        cin>>spheat;
        cin>>density;
	for(i=1;i<=fa;i++)
	{
		cout<<"Hello"<<endl;		
		sum = f[i].read(i,size,tconductivity,spheat,density);
		cout<<"Hello2"<<endl;		
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
				//			   elementproperties[k].enbour = neighbour(identity1,fa,f);
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
		
	cout<<"noof_elements = "<<noof_elements<<endl;
	int fg;
	float nodeid,pq; 
	int nodeidinint; 
	
	
	int escape=0;
	while(escape!=1)
	{
		readloadf(fa,f,elementproperties,noof_elements);
		cout<<"press 1 to stop reading loads else press any other no"<<endl;// arre vo escape vaala chal nahi raha tha aur main jyaada time waste nahi karna chahta tha
		cin>>escape;
	};
	numerical(elementproperties,f,fa,noof_elements);
	identity identity2;
	cin>>fg;	
};
