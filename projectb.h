
#include "CSCIx229.h"
#include "projecth.h"


typedef struct {float x,y,z;} vtx;
#define n 500
vtx is[n];
double demove= 0;

int light=1;
int cross1 = 0;
int light1=1;
int one=1;
int distance=10;
int inc=10;
int smooth=1;
int local=0;
int emission=10;
int dooropen=0;
int flag=0;
int ambient = 0;
int diffuse=50;
int specular=0;
double Demonx=3;
double Demonz=7;

int shininess= 0;
int shiny=1;
int zh=90;
double flashx=0;
double flashy=0;
double flashz=0;
float ylight=0;
unsigned int texture[20];
unsigned int sky[2];
int ttype=0;
int tmode=0;
int color=0;
int th=0;
double th1=179.1;
int ph=0;
double bladeroll=0;
double ph1=0;
int box=1;
int p=2;
int mode=0;
double Ex = 0.0;   //  Eye
double Ey = 0.3;   //  Eye
double Ez = 9;   //  Eye
double viewheight =0.1;
double viewang =0.0;
double View = 0.0;
double w =0.02;
int fov=55;
double dim=6;
//double zh=0;
double move=0;

double movement=1;    
double asp=1;
const char* text[] = {"Cubes with Spheres","Spheres", "Town with rolling stones"};
// #define Cos(x) (cos((x)*3.14159265/180))
// #define Sin(x) (sin((x)*3.14159265/180))

#define LEN 8192
void idle();

static void Reverse(void* x,const int n1)
{
   char* ch = (char*)x;
   for (int k=0;k<n1/2;k++)
   {
      char tmp = ch[k];
      ch[k] = ch[n1-1-k];
      ch[n1-1-k] = tmp;
   }
}
void Print(const char* format , ...)
{
   char buf[LEN];
   char* ch=buf;
   va_list args;

   va_start(args, format);
   vsnprintf(buf, LEN, format, args);
   va_end(args);
   while(*ch)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *ch++);
}
void Project()
{
   glMatrixMode(GL_PROJECTION);

   glLoadIdentity();
   if(p==2){
      gluPerspective(fov,asp,dim/16,16*dim);
   }
   if(p==1)
      gluPerspective(fov,asp,dim/16,16*dim);

   else if (p==0)
      glOrtho(-asp*dim,+asp*dim,-dim, +dim, -dim,+dim);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
void ErrCheck(const char* where)
{
   int err = glGetError();
   if (err) fprintf(stderr,"ERROR: %s [%s]\n",gluErrorString(err),where);
}
void Fatal(const char* format , ...)
{
   va_list args;
   va_start(args,format);
   vfprintf(stderr,format,args);
   va_end(args);
   exit(1);
}

static void Vertex(double th, double ph)
{  
   double x = Sin(th)*Cos(ph);
         double y = Cos(th)*Cos(ph);
         double z =         Sin(ph);
   
   glNormal3d(x,y,z);
   glTexCoord2f(x,y);
   glVertex3d(x,y,z);

}


