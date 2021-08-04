#include<iostream>
#include<math.h>
#define h 6.626*pow(10,-34)  //plank's constant
#define me 9.1*pow(10,-31) //mass of a electron
#define pi 3.14 //pi value
#define c 3*pow(10,8) //speed of light, maximum speed any entity in the universe can have , massive particles cannot reach speed of light
#define rad pow(10,-10) //size (radius) of a hydrogen atom
#define nuc pow(10,-15) //size(radius) of a hydrogen nucleus
using namespace std;
const char quantity[6][20]={"position","momentum","energy","time","angular-position","angular-momentum"};
class data 
{   protected:
    string name;
    int n;
    double dataval[100];  //position-momentum or energy-time or angular position-amgular momentum
    double pdf[100];
    public:
    void input_name()
    {
        cout<<"enter the name of the data values :"<<endl;
        cout<<"it can be :"<<endl;
        for(int i=0;i<6;i++)
        {
            cout<<quantity[i]<<endl;

        }
        cout<<"\n";
        cin>>name;
    }
    void input_n()
    {
        cout<<"enter the number of values recorded:"<<endl;
        cin>>n;
    }
    void input_data()
    {
        cout<<"enter the data:"<<endl;
        for(int i=0;i<n;i++)
        {
           cin>>dataval[i];

        }

    }
     void input_pdf()
    {
        cout<<"enter the probability distribution function :"<<endl;
        for(int i=0;i<n;i++)
        {
           cin>>pdf[i];

        }
        
    }
    void display_data()
    {
        cout<<"data of "<< name<<" :\n"<<endl;
           for(int i=0;i<n;i++)
        {
           cout<<dataval[i];
           cout<<"\n";

        }
        
    }
     void display_pdf()
    {
        cout<<"probability distribution of "<< name<<" :\n"<<endl;
           for(int i=0;i<n;i++)
        {
           cout<<pdf[i];
           cout<<"\n";

        }
    }
    string get_name()
    {
        return name;
    }

        
};
class mean : public data
{
  protected:
  double mean_val = 0;
  public:
  
  void meancal()
  {
      cout<<"mean value is calculated"<<endl;
      for(int i=0;i<n;i++)
      {
        mean_val = mean_val+dataval[i]*pdf[i];
        //cout<<mean_val;
      }
  }
  void display_mean()
  {
    cout<<"the mean of the "<< name <<":"<<endl;
    cout<<mean_val;
    cout<<"\n";
  }

  

};

class std_deviation:public mean
{
    protected:
    double std=0;
    //float meanv=0;
    public:
    void std_cal()
    {
      double exp2=0;
      //meanv=0;
      for(int i=0;i<n;i++)
      {
          exp2=exp2+pow(dataval[i],2)*(pdf[i]);
          //meanv=meanv+dataval[i]*pdf[i];
      }
      double variance = exp2-pow(mean_val,2);
      std = sqrt(variance);
       
        
    }
    double get_std()
    {
      double exp2=0;
      //meanv=0;
      for(int i=0;i<n;i++)
      {
          exp2=exp2+pow(dataval[i],2)*(pdf[i]);
          //meanv=meanv+dataval[i]*pdf[i];
      }
      double variance = exp2-pow(mean_val,2);
      std = sqrt(variance);
       
      return std;
    }
    
    void display_std()
    {
        cout<<"the standard deviation or uncertainity in "<< name <<":"<<endl;
        cout<<std;
        cout<<"\n";
    }




};
int main()
{  
   cout<<"\n\n\n";
   cout<<"\t\t-----[]------<>------[]------<>------//HEISENBERG UNCERTAINITY PRINCIPLE STATISTICS//-------~~-------||------~~-------||------"<<endl;
   cout<<"\n\n\n";
   cout<<"In quantum physics, if we are trying to measure a quantity more accurately then the corresponding quantity connected with commutation relation  becomes more uncertain.\nOr in other words we cannot measure two quantities simultaneously, uncertainities and errors develop when we try to do so.....\nThe product of uncertainities in two quantities is always greater than equal to planks constant 'h' over 4pi....\nthat is : q1*q2>=h/4*pi.....\n"<<endl;
   cout<<"In qunatum physics few quantities or observables doesn't commute like for example  position and momentum :xp-px!=0..\nThese quantities behave according to HEISENBERG UNCERTAINITY PRINCIPLE"<<endl;
   cout<<"\n\n";
   cout<<"commutator relations are:"<<endl;
   char commutators[3][40]= {"[position,momentum]","[energy,time]","[angular_position,angular_momentum]"};
   for(int l=0;l<3;l++)
   {
       cout<<commutators[l]<<endl;
   }
    
   cout<<"\n\n";
   std_deviation sd;
   sd.input_name();
   sd.input_n();
   sd.input_data();
   sd.input_pdf();
   cout<<"\n";
   sd.display_data();
   cout<<"\n";
   sd.display_pdf();
   cout<<"\n";
   sd.meancal();
   cout<<"\n";
   sd.display_mean();
   cout<<"\n";
   sd.std_cal();
   cout<<"\n";
   sd.display_std();
   cout<<"\n";
   string quant = sd.get_name();
   string quant2;
   string units;
   if(quant=="position")
   {quant2="momentum"; units = "kg m/s";}
   else if(quant=="momentum")
   {quant2="position"; units = "m";}
    else if(quant=="energy")
   {quant2="time"; units = "s";}
    else if(quant=="time")
   {quant2="energy"; units = "joules";}
    else if(quant=="angular-velocity")
   {quant2="angular-position"; units = "rad";}
    else if(quant=="angular-position")
   {quant2="angular-velocity"; units = "rad/sec";}
   cout<<"\n";
   cout<<"the uncertainity or standard deviation in "<<  quant2 <<" is :"<<endl;
   double dev=sd.get_std();
   
   double q;
   q = 1/(4*dev*pi)*h;
   cout<<q<<  units <<endl;
  
   if(quant=="position")
   {
       cout<<"uncertainity in velocity:"<<endl;
   double v=q/9.1*pow(10,31);

   cout<<v<<" m/s"<<endl;
   if(v>=c)
   {
     cout<<"\nspeed of light:"<<c<<endl;  
     cout<<"\nCONCUSION\n";  
     cout<<"According to heisenberg principle the uncertainity is veclocity is maximum and reached beyond or equal to speed of light ,well any massive particle cannot reach speed of light ,this verifies that we cannot measure a quantity with accuracy,if we try to do so other quantities behave in an imaginary way "<<endl;
   }
}

  


    return 0;
}
