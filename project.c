
#include "CSCIx229.h"
#include "projecth.h"
#include "projectb.h"

static void terrain(double x, double y, double z, double dx, double dy, double dz, double th){
   float white[] = {1,1,1,1};
   float Emission[]  = {0.0,0.0,0.01*emission,1.0};
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,Emission);
   glPushMatrix();
   glTranslated(x,y,z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);
   glEnable(GL_TEXTURE_2D);
   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
   glColor3f(1,1,1);
   glBindTexture(GL_TEXTURE_2D,texture[14]);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glColor3f(2,2,0.5);
   
   if(ttype) glBindTexture(GL_TEXTURE_2D,texture[1]);

   glBegin(GL_QUADS);
   
   glNormal3f( 0, 0, 1);
   
   glTexCoord2f(0.0f,0.0f);   glVertex3f(-1,-1, 1);
   glTexCoord2f(160.0f,0.0f);   glVertex3f(+1,-1, 1);
   glTexCoord2f(160.0f,160.0f);   glVertex3f(+1,+1, 1);
   glTexCoord2f(0.0f,160.0f);   glVertex3f(-1,+1, 1);
   

   if(color){
   glColor3f(0,0,0);
   }
   glNormal3f( 0,-one, 0);
      glTexCoord2f(0.0f,0.0f);  glVertex3f(-1,-1,-1);
   glTexCoord2f(160.0f,0.0f); glVertex3f(+1,-1,-1);
   glTexCoord2f(160.0f,160.0f);glVertex3f(+1,-1,+1);
   glTexCoord2f(0.0f,160.0f); glVertex3f(-1,-1,+1);
 
  
   
  
   glEnd();
   //glBegin(GL_TRIANGLE_FAN);
   //Vertex(30,90);
   //for(int th=15; th<=360;th+=15){
   //   Vertex(th,90-15);
   //}
   
   
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}
static void sphere(double x, double y, double z, double r, int texindx){
   glPushMatrix();
   
   glTranslated(x,y,z);
   glScaled(r,r,r);
   
   float yellow[]   = {1.0,1.0,0.0,1.0};
   float Emission[] = {0.0,0.0,0.01*emission,1.0};
   
   glColor3f(1,1,1);
   glMaterialf(GL_FRONT,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT,GL_SPECULAR,yellow);
   glMaterialfv(GL_FRONT,GL_EMISSION,Emission);
   
   // glEnable(GL_TEXTURE_2D);
   // glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
   // glColor3f(1,1,1);
    glEnable(GL_TEXTURE_2D);
   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,mode?GL_REPLACE:GL_MODULATE);
   glBindTexture(GL_TEXTURE_2D,texture[texindx]);
   for (int ph=-90;ph<90;ph+=inc)
   {
      
   
      glBegin(GL_QUAD_STRIP);
      for (int th=0;th<=360;th+=2*inc)
      {
         
         
         double x = Sin(th)*Cos(ph);
         double y = Cos(th)*Cos(ph);
         double z =         Sin(ph);
      
         glNormal3f(x,y,z);
         glTexCoord2f(x,y);
         glVertex3d(x,y,z);
         
         
         double x1 = Sin(th)*Cos(ph+inc);
         double y1 = Cos(th)*Cos(ph+inc);
         double z1 =         Sin(ph+inc);
   
         glNormal3f(x1,y1,z1);
         glTexCoord2f(x1,y1);
         glVertex3d(x1,y1,z1);
      }
      glEnd();
      
      
   }
   glDisable(GL_TEXTURE_2D);
   glPopMatrix();
      
   
   
   
}
static void skullwall1(double x, double y, double z, double dx, double dy, double dz, double th){
   
   float white[] = {1,1,1,1};
   float Emission[]  = {0.0,0.0,0.01*emission,1.0};
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,Emission);
   glPushMatrix();
   glTranslated(x,y,z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);
   glPolygonOffset(2,2);
   glEnable(GL_TEXTURE_2D);
   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
   glColor3f(0.5,0.5,0.5);
   glBindTexture(GL_TEXTURE_2D,texture[0]);
   
   if(ttype) glBindTexture(GL_TEXTURE_2D,texture[1]);

   glBegin(GL_QUADS);
   
   glNormal3f( 0, 0, 1);
   
   glTexCoord2f(0,0);   glVertex3f(-1,-1, 1);
   
   
   glTexCoord2f(1,0);   glVertex3f(+1,-1, 1);
   glTexCoord2f(1,1);   glVertex3f(+1,+1, 1);
   glTexCoord2f(0,1);   glVertex3f(-1,+1, 1);
   
   
   glNormal3f( 0, 0,-1);
   glTexCoord2f(0,0);   glVertex3f(+1,-1,-1);
   glTexCoord2f(1,0);   glVertex3f(-1,-1,-1);
   glTexCoord2f(1,1);   glVertex3f(-1,+1,-1);
   glTexCoord2f(0,1);   glVertex3f(+1,+1,-1);

   glEnd();

   glBindTexture(GL_TEXTURE_2D,texture[4]);
   glBegin(GL_QUADS);
   glNormal3f(+1, 0, 0);
   glTexCoord2f(0.0f,0.0f);   glVertex3f(+1,-1,+1);
   glTexCoord2f(1.0f,0.0f);   glVertex3f(+1,-1,-1);
   glTexCoord2f(1.0f,1.0f);   glVertex3f(+1,+1,-1);
   glTexCoord2f(0.0f,1.0f);   glVertex3f(+1,+1,+1);
   glEnd();

glBindTexture(GL_TEXTURE_2D,texture[0]);
   glBegin(GL_QUADS);
   
   //  Left
   
   glNormal3f(-1, 0, 0);
      glTexCoord2f(0,0);glVertex3f(-1,-1,-1);
   glTexCoord2f(1,0);glVertex3f(-1,-1,+1);
   glTexCoord2f(1,1);glVertex3f(-1,+1,+1);
   glTexCoord2f(0,1); glVertex3f(-1,+1,-1);
   
   
   
  
   //  Top
   
    glNormal3f( 0,+1, 0);
   glTexCoord2f(0,0);glVertex3f(-1,+1,+1);
   glTexCoord2f(1,0);glVertex3f(+1,+1,+1);
   glTexCoord2f(1,1);glVertex3f(+1,+1,-1);
   glTexCoord2f(0,1);glVertex3f(-1,+1,-1);
   
   
   
   
   //  Bottom
   
   glNormal3f( 0,-one, 0);
      glTexCoord2f(0,0);  glVertex3f(-1,-1,-1);
   glTexCoord2f(1,0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1,1);glVertex3f(+1,-1,+1);
   glTexCoord2f(0,1); glVertex3f(-1,-1,+1);
 
  
   
  
   glEnd();
   
   //glBegin(GL_TRIANGLE_FAN);
   //Vertex(30,90);
   //for(int th=15; th<=360;th+=15){
   //   Vertex(th,90-15);
   //}
   
   
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

static void sphere1(double x, double y, double z, double r){
      //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   glTranslated(x,y,z);
   glScaled(r,r,r);
   //  White ball with yellow specular
   float yellow[]   = {1.0,1.0,0.0,1.0};
   float Emission[] = {0.0,0.0,0.01*emission,1.0};
   glColor3f(1,1,1);
   glMaterialf(GL_FRONT,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT,GL_SPECULAR,yellow);
   glMaterialfv(GL_FRONT,GL_EMISSION,Emission);
   //  Bands of latitude
   for (int ph=-90;ph<90;ph+=inc)
   {
      glBegin(GL_QUAD_STRIP);
      for (int th=0;th<=360;th+=2*inc)
      {
         Vertex(th,ph);
         Vertex(th,ph+inc);
      }
      glEnd();
   }
   //  Undo transofrmations
   glPopMatrix();


}
static void spheredemon(double x, double y, double z, double r, double red, double green, double blue){
      //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   glTranslated(x,y,z);
   glScaled(r,r,r);
   //  White ball with yellow specular
   float yellow[]   = {1.0,1.0,0.0,1.0};
   float Emission[] = {0.0,0.0,0.01*emission,1.0};
   glColor3f(red,green,blue);
   glMaterialf(GL_FRONT,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT,GL_SPECULAR,yellow);
   glMaterialfv(GL_FRONT,GL_EMISSION,Emission);
   //  Bands of latitude
   for (int ph=-90;ph<90;ph+=inc)
   {
      glBegin(GL_QUAD_STRIP);
      for (int th=0;th<=360;th+=2*inc)
      {
         Vertex(th,ph);
         Vertex(th,ph+inc);
      }
      glEnd();
   }
   //  Undo transofrmations
   glPopMatrix();


}

static void sphere2(double x, double y, double z, double r1, double r2, double r3){
      //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   glTranslated(x,y,z);
   glScaled(r1,r2,r3);
   //  White ball with green specular
   float green[]   = {0.0,1.0,0.0,0.0};
   float Emission[] = {0.0,0.0,0.01*emission,1.0};
   glColor3f(0,1,0);
   glMaterialf(GL_FRONT,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT,GL_SPECULAR,green);
   glMaterialfv(GL_FRONT,GL_EMISSION,Emission);
   //  Bands of latitude
   for (int ph=-90;ph<90;ph+=inc)
   {
      glBegin(GL_QUAD_STRIP);
      for (int th=0;th<=360;th+=2*inc)
      {
         Vertex(th,ph);
         Vertex(th,ph+inc);
      }
      glEnd();
   }
   //  Undo transofrmations
   glPopMatrix();


}
static void skullwall(double x, double y, double z, double dx, double dy, double dz, double th){
   
   float white[] = {1,1,1,1};
   float Emission[]  = {0.0,0.0,0.01*emission,1.0};
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,Emission);
   glPushMatrix();
   glTranslated(x,y,z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);
   glPolygonOffset(2,2);
   glEnable(GL_TEXTURE_2D);
   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
   glColor3f(1,1,1);
   glBindTexture(GL_TEXTURE_2D,texture[0]);
   if(color){
   glColor3f(1,0,0);
   }
   if(ttype) glBindTexture(GL_TEXTURE_2D,texture[1]);

   glBegin(GL_QUADS);
   
   glNormal3f( 0, 0, 1);
   
   glTexCoord2f(0,0);   glVertex3f(-1,-1, 1);
   
   
   glTexCoord2f(1,0);   glVertex3f(+1,-1, 1);
   glTexCoord2f(1,1);   glVertex3f(+1,+1, 1);
   glTexCoord2f(0,1);   glVertex3f(-1,+1, 1);
   
   if(color){
   glColor3f(0,0,1);
   }
   glNormal3f( 0, 0,-1);
   glTexCoord2f(0,0);   glVertex3f(+1,-1,-1);
   glTexCoord2f(1,0);   glVertex3f(-1,-1,-1);
   glTexCoord2f(1,1);   glVertex3f(-1,+1,-1);
   glTexCoord2f(0,1);   glVertex3f(+1,+1,-1);




   if(color){
   glColor3f(1,1,0);
   }

   glEnd();

   glBindTexture(GL_TEXTURE_2D,texture[4]);
   glBegin(GL_QUADS);
   glNormal3f(+1, 0, 0);
   glTexCoord2f(0.0f,0.0f);   glVertex3f(+1,-1,+1);
   glTexCoord2f(2.0f,0.0f);   glVertex3f(+1,-1,-1);
   glTexCoord2f(2.0f,1.0f);   glVertex3f(+1,+1,-1);
   glTexCoord2f(0.0f,1.0f);   glVertex3f(+1,+1,+1);
   glEnd();


glBindTexture(GL_TEXTURE_2D,texture[0]);
   glBegin(GL_QUADS);
   
   //  Left
   if(color){
   glColor3f(0,1,0);
   }
   glNormal3f(-1, 0, 0);
      glTexCoord2f(0,0);glVertex3f(-1,-1,-1);
   glTexCoord2f(1,0);glVertex3f(-1,-1,+1);
   glTexCoord2f(1,1);glVertex3f(-1,+1,+1);
   glTexCoord2f(0,1); glVertex3f(-1,+1,-1);
   
   
   
  
   //  Top
   if(color){
   glColor3f(0,1,1);
   }
    glNormal3f( 0,+1, 0);
   glTexCoord2f(0,0);glVertex3f(-1,+1,+1);
   glTexCoord2f(1,0);glVertex3f(+1,+1,+1);
   glTexCoord2f(1,1);glVertex3f(+1,+1,-1);
   glTexCoord2f(0,1);glVertex3f(-1,+1,-1);
   
   
   
   
   //  Bottom
   if(color){
   glColor3f(1,0,1);
   }
   glNormal3f( 0,-one, 0);
      glTexCoord2f(0,0);  glVertex3f(-1,-1,-1);
   glTexCoord2f(1,0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1,1);glVertex3f(+1,-1,+1);
   glTexCoord2f(0,1); glVertex3f(-1,-1,+1);
 
  
   
  
   glEnd();
   //glBegin(GL_TRIANGLE_FAN);
   //Vertex(30,90);
   //for(int th=15; th<=360;th+=15){
   //   Vertex(th,90-15);
   //}
   
   
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

static void crossh(double x, double y, double z, double dx, double dy, double dz, double th, int texindx){
   
   float white[] = {1,1,1,1};
   float Emission[]  = {0.0,0.0,0.01*emission,1.0};
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,Emission);
   glPushMatrix();
   glTranslated(x,y,z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);
   glEnable(GL_TEXTURE_2D);
   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
   glColor3f(1,1,1);
   glBindTexture(GL_TEXTURE_2D,texture[texindx]);

   glBegin(GL_QUADS);
   
   glNormal3f( 0, 0, 1);
   
   glTexCoord2f(0,0);   glVertex3f(-1,-1, 1);
   
   
   glTexCoord2f(1,0);   glVertex3f(+1,-1, 1);
   glTexCoord2f(1,1);   glVertex3f(+1,+1, 1);
   glTexCoord2f(0,1);   glVertex3f(-1,+1, 1);
   

   glNormal3f( 0, 0,-1);
   glTexCoord2f(0,0);   glVertex3f(+1,-1,-1);
   glTexCoord2f(1,0);   glVertex3f(-1,-1,-1);
   glTexCoord2f(1,1);   glVertex3f(-1,+1,-1);
   glTexCoord2f(0,1);   glVertex3f(+1,+1,-1);

   glEnd();
   glBegin(GL_QUADS);
   glNormal3f(+1, 0, 0);
   glTexCoord2f(0,0);   glVertex3f(+1,-1,+1);
   glTexCoord2f(1,0);   glVertex3f(+1,-1,-1);
   glTexCoord2f(1,1);   glVertex3f(+1,+1,-1);
   glTexCoord2f(0,1);   glVertex3f(+1,+1,+1);
   glEnd();

glBindTexture(GL_TEXTURE_2D,texture[0]);
   glBegin(GL_QUADS);
   
   //  Left
   
   glNormal3f(-1, 0, 0);
      glTexCoord2f(0,0);glVertex3f(-1,-1,-1);
   glTexCoord2f(1,0);glVertex3f(-1,-1,+1);
   glTexCoord2f(1,1);glVertex3f(-1,+1,+1);
   glTexCoord2f(0,1); glVertex3f(-1,+1,-1);
   
   
   
  
   //  Top
   
    glNormal3f( 0,+1, 0);
   glTexCoord2f(0,0);glVertex3f(-1,+1,+1);
   glTexCoord2f(1,0);glVertex3f(+1,+1,+1);
   glTexCoord2f(1,1);glVertex3f(+1,+1,-1);
   glTexCoord2f(0,1);glVertex3f(-1,+1,-1);
   
   
   
   
   //  Bottom
   
   glNormal3f( 0,-one, 0);
      glTexCoord2f(0,0);  glVertex3f(-1,-1,-1);
   glTexCoord2f(1,0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1,1);glVertex3f(+1,-1,+1);
   glTexCoord2f(0,1); glVertex3f(-1,-1,+1);
 
  
   
  
   glEnd();
   //glBegin(GL_TRIANGLE_FAN);
   //Vertex(30,90);
   //for(int th=15; th<=360;th+=15){
   //   Vertex(th,90-15);
   //}
   
   
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

static void cross(double x, double y, double z, double dx, double dy, double dz, double th){
   
   float white[] = {1,1,1,1};
   float Emission[]  = {0.0,0.0,0.01*emission,1.0};
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,Emission);
   glPushMatrix();
   glTranslated(x,y,z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);
   glEnable(GL_TEXTURE_2D);
   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
   glColor3f(1,1,1);
   glBindTexture(GL_TEXTURE_2D,texture[0]);
   

   crossh(0,0.5,0,0.05,1,0.05,0,13); 
   crossh(0,0.9,0,0.05,0.08,00.5,90,13);
   //glBegin(GL_TRIANGLE_FAN);
   //Vertex(30,90);
   //for(int th=15; th<=360;th+=15){
   //   Vertex(th,90-15);
   //}
   
   
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}
static void wills(double x, double y, double z, double dx, double dy, double dz){
   glPushMatrix();
      glTranslated(x,y,z);
      glScaled(dx, dy, dz);
      float Ambient[]   = {0.03*ambient ,0.03*ambient ,0.03*ambient ,1.0};
      float Diffuse[]   = {0.03*diffuse ,0.03*diffuse ,0.03*diffuse ,1.0};
      float Specular[]  = {0.03*specular,0.03*specular,0.03*specular,1.0};
      //  Light position
      float Position[]  = {1,0.1,1,1.0};
      //  Draw light position as ball (still no lighting here)
      glColor3f(0,1,0);
      sphere2(Position[0],Position[1],Position[2],0.1,0.1,0.1);
      
      glEnable(GL_NORMALIZE);
      //  Enable lighting
      glEnable(GL_LIGHTING);
      //  Location of viewer for specular calculations
      glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,local);
      //  glColor sets ambient and diffuse color materials
      glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
      glEnable(GL_COLOR_MATERIAL);
      
      glEnable(GL_LIGHT2);
      //  Set ambient, diffuse, specular components and position of light 2
      glLightfv(GL_LIGHT2,GL_AMBIENT ,Ambient);
      glLightfv(GL_LIGHT2,GL_DIFFUSE ,Diffuse);
      glLightfv(GL_LIGHT2,GL_SPECULAR,Specular);
      glLightfv(GL_LIGHT2,GL_POSITION,Position);
      glPopMatrix();
}
static void cube(double x, double y, double z, double dx, double dy, double dz, double th){
   
   float white[] = {1,1,1,1};
   float Emission[]  = {0.0,0.0,0.01*emission,1.0};
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,Emission);
   glPushMatrix();
   glTranslated(x,y,z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);
   glEnable(GL_TEXTURE_2D);
   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
   glColor3f(1,1,1);
   glBindTexture(GL_TEXTURE_2D,texture[0]);
   if(color){
   glColor3f(1,0,0);
   }
   if(ttype) glBindTexture(GL_TEXTURE_2D,texture[1]);

   glBegin(GL_QUADS);
   
   glNormal3f( 0, 0, 1);
   
   glTexCoord2f(0,0);   glVertex3f(-1,-1, 1);
   
   
   glTexCoord2f(1,0);   glVertex3f(+1,-1, 1);
   glTexCoord2f(1,1);   glVertex3f(+1,+1, 1);
   glTexCoord2f(0,1);   glVertex3f(-1,+1, 1);
   
   if(color){
   glColor3f(0,0,1);
   }
   glNormal3f( 0, 0,-1);
   glTexCoord2f(0,0);   glVertex3f(+1,-1,-1);
   glTexCoord2f(1,0);   glVertex3f(-1,-1,-1);
   glTexCoord2f(1,1);   glVertex3f(-1,+1,-1);
   glTexCoord2f(0,1);   glVertex3f(+1,+1,-1);




   if(color){
   glColor3f(1,1,0);
   }

   glEnd();

   glBindTexture(GL_TEXTURE_2D,texture[4]);
   glBegin(GL_QUADS);
   glNormal3f(+1, 0, 0);
   glTexCoord2f(0,0);   glVertex3f(+1,-1,+1);
   glTexCoord2f(1,0);   glVertex3f(+1,-1,-1);
   glTexCoord2f(1,1);   glVertex3f(+1,+1,-1);
   glTexCoord2f(0,1);   glVertex3f(+1,+1,+1);
   glEnd();

glBindTexture(GL_TEXTURE_2D,texture[0]);
   glBegin(GL_QUADS);
   
   //  Left
   if(color){
   glColor3f(0,1,0);
   }
   glNormal3f(-1, 0, 0);
      glTexCoord2f(0,0);glVertex3f(-1,-1,-1);
   glTexCoord2f(1,0);glVertex3f(-1,-1,+1);
   glTexCoord2f(1,1);glVertex3f(-1,+1,+1);
   glTexCoord2f(0,1); glVertex3f(-1,+1,-1);
   
   
   
  
   //  Top
   if(color){
   glColor3f(0,1,1);
   }
    glNormal3f( 0,+1, 0);
   glTexCoord2f(0,0);glVertex3f(-1,+1,+1);
   glTexCoord2f(1,0);glVertex3f(+1,+1,+1);
   glTexCoord2f(1,1);glVertex3f(+1,+1,-1);
   glTexCoord2f(0,1);glVertex3f(-1,+1,-1);
   
   
   
   
   //  Bottom
   if(color){
   glColor3f(1,0,1);
   }
   glNormal3f( 0,-one, 0);
      glTexCoord2f(0,0);  glVertex3f(-1,-1,-1);
   glTexCoord2f(1,0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1,1);glVertex3f(+1,-1,+1);
   glTexCoord2f(0,1); glVertex3f(-1,-1,+1);
 
  
   
  
   glEnd();
   //glBegin(GL_TRIANGLE_FAN);
   //Vertex(30,90);
   //for(int th=15; th<=360;th+=15){
   //   Vertex(th,90-15);
   //}
   
   
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

static void tombstone(double x, double y, double z, double dx, double dy, double dz, double th, int texindx){
   
   float white[] = {1,1,1,1};
   float Emission[]  = {0.0,0.0,0.01*emission,1.0};
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,Emission);
   glPushMatrix();
   glTranslated(x,y,z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);
   glEnable(GL_TEXTURE_2D);
   
   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
   glColor3f(1,1,1);
   
   glBindTexture(GL_TEXTURE_2D,texture[7]);
   if(color){
   glColor3f(1,0,0);
   }
   
    
            
   if(ttype) glBindTexture(GL_TEXTURE_2D,texture[1]);

   glBegin(GL_QUADS);
   
   glNormal3f( 0, 0, 1);
   
   
   glTexCoord2f(0,0);   glVertex3f(-1,-1, 1);
   
   
   glTexCoord2f(1,0);   glVertex3f(+1,-1, 1);
   glTexCoord2f(1,1);   glVertex3f(+1,+1, 1);
   glTexCoord2f(0,1);   glVertex3f(-1,+1, 1);
   
   
   




   if(color){
   glColor3f(1,1,0);
   }

   glEnd();

   glBindTexture(GL_TEXTURE_2D,texture[texindx]);
   glBegin(GL_QUADS);
   glNormal3f(+1, 0, 0);
   glNormal3f( 0, 0,-1);
   glTexCoord2f(0,0);   glVertex3f(+1,-1,-1);
   glTexCoord2f(1,0);   glVertex3f(-1,-1,-1);
   glTexCoord2f(1,1);   glVertex3f(-1,+1,-1);
   glTexCoord2f(0,1);   glVertex3f(+1,+1,-1);


   glTexCoord2f(0,0);   glVertex3f(+1,-1,+1);
   glTexCoord2f(1,0);   glVertex3f(+1,-1,-1);
   glTexCoord2f(1,1);   glVertex3f(+1,+1,-1);
   glTexCoord2f(0,1);   glVertex3f(+1,+1,+1);
   glEnd();

glBindTexture(GL_TEXTURE_2D,texture[texindx]);
   glBegin(GL_QUADS);
   
   //  Left
   if(color){
   glColor3f(0,1,0);
   }
   glNormal3f(-1, 0, 0);
      glTexCoord2f(0,0);glVertex3f(-1,-1,-1);
   glTexCoord2f(1,0);glVertex3f(-1,-1,+1);
   glTexCoord2f(1,1);glVertex3f(-1,+1,+1);
   glTexCoord2f(0,1); glVertex3f(-1,+1,-1);
   
   
   
  
   //  Top
   if(color){
   glColor3f(0,1,1);
   }
    glNormal3f( 0,+1, 0);
   glTexCoord2f(0,0);glVertex3f(-1,+1,+1);
   glTexCoord2f(1,0);glVertex3f(+1,+1,+1);
   glTexCoord2f(1,1);glVertex3f(+1,+1,-1);
   glTexCoord2f(0,1);glVertex3f(-1,+1,-1);
   
   
   
   
   //  Bottom
   if(color){
   glColor3f(1,0,1);
   }
   glNormal3f( 0,-one, 0);
      glTexCoord2f(0,0);  glVertex3f(-1,-1,-1);
   glTexCoord2f(1,0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1,1);glVertex3f(+1,-1,+1);
   glTexCoord2f(0,1); glVertex3f(-1,-1,+1);
 
  
   
   //sphere(x-0.1,y+1.5,z,0.25);
   
   glEnd();
   

   for(double i =-0.75; i<=0.75;i=i+0.25){
      if(i!=-0.75 && i!=0.75){
         sphere(i-0.1,y+1.125,0,0.30, 5);
      }
      sphere(i-0.1,y+1,0,0.30,5);
   }
   if(cross1==1){

               
            }
   //glBegin(GL_TRIANGLE_FAN);
   //Vertex(30,90);
   //for(int th=15; th<=360;th+=15){
   //   Vertex(th,90-15);
   //}
   
   
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}



//
//  Load texture from BMP file
//
unsigned int LoadTexBMP(const char* file)
{
   //  Open file
   FILE* f = fopen(file,"rb");
   if (!f) Fatal("Cannot open file %s\n",file);
   //  Check image magic
   unsigned short magic;
   if (fread(&magic,2,1,f)!=1) Fatal("Cannot read magic from %s\n",file);
   if (magic!=0x4D42 && magic!=0x424D) Fatal("Image magic not BMP in %s\n",file);
   //  Read header
   unsigned int dx,dy,off,k; // Image dimensions, offset and compression
   unsigned short nbp,bpp;   // Planes and bits per pixel
   if (fseek(f,8,SEEK_CUR) || fread(&off,4,1,f)!=1 ||
       fseek(f,4,SEEK_CUR) || fread(&dx,4,1,f)!=1 || fread(&dy,4,1,f)!=1 ||
       fread(&nbp,2,1,f)!=1 || fread(&bpp,2,1,f)!=1 || fread(&k,4,1,f)!=1)
     Fatal("Cannot read header from %s\n",file);
   //  Reverse bytes on big endian hardware (detected by backwards magic)
   if (magic==0x424D)
   {
      Reverse(&off,4);
      Reverse(&dx,4);
      Reverse(&dy,4);
      Reverse(&nbp,2);
      Reverse(&bpp,2);
      Reverse(&k,4);
   }
   //  Check image parameters
   unsigned int max;
   glGetIntegerv(GL_MAX_TEXTURE_SIZE,(int*)&max);
   if (dx<1 || dx>max) Fatal("%s image width %d out of range 1-%d\n",file,dx,max);
   if (dy<1 || dy>max) Fatal("%s image height %d out of range 1-%d\n",file,dy,max);
   if (nbp!=1)  Fatal("%s bit planes is not 1: %d\n",file,nbp);
   if (bpp!=24) Fatal("%s bits per pixel is not 24: %d\n",file,bpp);
   if (k!=0)    Fatal("%s compressed files not supported\n",file);
#ifndef GL_VERSION_2_0
   //  OpenGL 2.0 lifts the restriction that texture size must be a power of two
   for (k=1;k<dx;k*=2);
   if (k!=dx) Fatal("%s image width not a power of two: %d\n",file,dx);
   for (k=1;k<dy;k*=2);
   if (k!=dy) Fatal("%s image height not a power of two: %d\n",file,dy);
#endif

   //  Allocate image memory
   unsigned int size = 3*dx*dy;
   unsigned char* image = (unsigned char*) malloc(size);
   if (!image) Fatal("Cannot allocate %d bytes of memory for image %s\n",size,file);
   //  Seek to and read image
   if (fseek(f,off,SEEK_SET) || fread(image,size,1,f)!=1) Fatal("Error reading data from image %s\n",file);
   fclose(f);
   //  Reverse colors (BGR -> RGB)
   for (k=0;k<size;k+=3)
   {
      unsigned char temp = image[k];
      image[k]   = image[k+2];
      image[k+2] = temp;
   }

   //  Sanity check
   ErrCheck("LoadTexBMP");
   //  Generate 2D texture
   unsigned int texture;
   glGenTextures(1,&texture); 
   glBindTexture(GL_TEXTURE_2D,texture);
   //  Copy image
   glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,dx,dy,0,GL_RGB,GL_UNSIGNED_BYTE,image);
   if (glGetError()) Fatal("Error in glTexImage2D %s %dx%d\n",file,dx,dy);
   //  Scale linearly when image size doesn't match
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

   //  Free image memory
   free(image);
   //  Return texture name
   return texture;
}
//skybox?


static void Sky(double D, double x, double y, double z)
{


   //  Textured white box dimension (-D,+D)
   glPushMatrix();
   glTranslated(x, y, z);
   glScaled(D,D,D);
   glEnable(GL_TEXTURE_2D);
   glColor3f(1,1,1);

   //  Sides
   glBindTexture(GL_TEXTURE_2D,sky[0]);
   glBegin(GL_QUADS);
   glTexCoord2f(0.00,0); glVertex3f(-1,-1,-1);
   glTexCoord2f(0.25,0); glVertex3f(+1,-1,-1);
   glTexCoord2f(0.25,1); glVertex3f(+1,+1,-1);
   glTexCoord2f(0.00,1); glVertex3f(-1,+1,-1);

   glTexCoord2f(0.25,0); glVertex3f(+1,-1,-1);
   glTexCoord2f(0.50,0); glVertex3f(+1,-1,+1);
   glTexCoord2f(0.50,1); glVertex3f(+1,+1,+1);
   glTexCoord2f(0.25,1); glVertex3f(+1,+1,-1);

   glTexCoord2f(0.50,0); glVertex3f(+1,-1,+1);
   glTexCoord2f(0.75,0); glVertex3f(-1,-1,+1);
   glTexCoord2f(0.75,1); glVertex3f(-1,+1,+1);
   glTexCoord2f(0.50,1); glVertex3f(+1,+1,+1);

   glTexCoord2f(0.75,0); glVertex3f(-1,-1,+1);
   glTexCoord2f(1.00,0); glVertex3f(-1,-1,-1);
   glTexCoord2f(1.00,1); glVertex3f(-1,+1,-1);
   glTexCoord2f(0.75,1); glVertex3f(-1,+1,+1);
   glEnd();

   //  Top and bottom
   glBindTexture(GL_TEXTURE_2D,sky[1]);
   glBegin(GL_QUADS);
   glTexCoord2f(0.0,0); glVertex3f(+1,+1,-1);
   glTexCoord2f(0.5,0); glVertex3f(+1,+1,+1);
   glTexCoord2f(0.5,1); glVertex3f(-1,+1,+1);
   glTexCoord2f(0.0,1); glVertex3f(-1,+1,-1);

   glTexCoord2f(1.0,1); glVertex3f(-1,-1,+1);
   glTexCoord2f(0.5,1); glVertex3f(+1,-1,+1);
   glTexCoord2f(0.5,0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1.0,0); glVertex3f(-1,-1,-1);
   glEnd();

   //  Undo
   glDisable(GL_TEXTURE_2D);
   glPopMatrix();
}

static void cone(double x, double y, double z){
   glPushMatrix();
   glTranslatef(x,y,z);
   
   glEnable(GL_TEXTURE_2D);
      glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
      glColor3f(1,1,1);
      glBindTexture(GL_TEXTURE_2D,texture[2]);
      glColor3f(1,0,0); 
   const vtx trian[]={
         {0.0f, 0.05f, 0.0f},{-0.05f, -0.05f, 0.05f},{0.05f, -0.05f, 0.05f},
         {0.0f, 0.05f, 0.0f},{0.05f, -0.05f, 0.05f},{0.05f, -0.05f, -0.05f},
         {0.0f, 0.05f, 0.0f},{0.05f, -0.05f, -0.05f},{-0.05f, -0.05f, -0.05f},
         { 0.0f, 0.05f, 0.0f},{-0.05f,-0.05f,-0.05f},{-0.05f,-0.05f, 0.05f}


   };
   
   glBegin(GL_TRIANGLES);       
      //planar vector 0    
      // Front
      
      //glNormal3f(,Ny,Nz);
      float dx0=0;
      float dy0=0;
      float dz0=0;
      float dx1=0;
      float dy1=0;
      float dz1=0;
      dx0= trian[0].x-trian[1].x;
      dy0= trian[0].y-trian[1].y;
      dz0= trian[0].z-trian[1].z;

      dx1= trian[2].x-trian[0].x;
      dy1= trian[2].x-trian[0].x;
      dz1= trian[2].x-trian[0].x;
      float Nx = dy0*dz1 - dy1*dz0;
      float Ny = dz0*dx1 - dz1*dx0;
      float Nz = dx0*dy1 - dx1*dy0;
      glNormal3f(Nx,Ny,Nz);

      glTexCoord2f(0,0);
      glVertex3f(trian[0].x ,trian[0].y ,trian[0].z);
      glTexCoord2f(1,0);
      glVertex3f(trian[1].x ,trian[1].y ,trian[1].z);
      glTexCoord2f(0,1);
      glVertex3f(trian[2].x ,trian[2].y ,trian[2].z);
        


      glColor3f(1,1,1);
      dx0= trian[3].x-trian[4].x;
      dy0= trian[3].y-trian[4].y;
      dz0= trian[3].z-trian[4].z;

      dx1= trian[5].x-trian[3].x;
      dy1= trian[5].x-trian[3].x;
      dz1= trian[5].x-trian[3].x;
      Nx = dy0*dz1 - dy1*dz0;
      Ny = dz0*dx1 - dz1*dx0;
      Nz = dx0*dy1 - dx1*dy0;
      glNormal3f(Nx,Ny,Nz);   
      glTexCoord2f(0,0);
      glVertex3f(trian[3].x ,trian[3].y ,trian[3].z);
      glTexCoord2f(1,0);
      glVertex3f(trian[4].x ,trian[4].y ,trian[4].z);
      glTexCoord2f(0,1);
      glVertex3f(trian[5].x ,trian[5].y ,trian[5].z);
      dx0= trian[6].x-trian[7].x;
      dy0= trian[6].y-trian[7].y;
      dz0= trian[6].z-trian[7].z;

      dx1= trian[8].x-trian[6].x;
      dy1= trian[8].x-trian[6].x;
      dz1= trian[8].x-trian[6].x;
      Nx = dy0*dz1 - dy1*dz0;
      Ny = dz0*dx1 - dz1*dx0;
      Nz = dx0*dy1 - dx1*dy0;
      glNormal3f(Nx,Ny,Nz);  
    glColor3f(0,0,1);   
      glTexCoord2f(0,0);
      glVertex3f(trian[6].x ,trian[6].y ,trian[6].z);
      glTexCoord2f(1,0);
      glVertex3f(trian[7].x ,trian[7].y ,trian[7].z);
      glTexCoord2f(0,1);
      glVertex3f(trian[8].x ,trian[8].y ,trian[8].z);
      glColor3f(1,1,0);
      dx0= trian[9].x-trian[10].x;
      dy0= trian[9].y-trian[10].y;
      dz0= trian[9].z-trian[10].z;

      dx1= trian[11].x-trian[9].x;
      dy1= trian[11].x-trian[9].x;
      dz1= trian[11].x-trian[9].x;
      Nx = dy0*dz1 - dy1*dz0;
      Ny = dz0*dx1 - dz1*dx0;
      Nz = dx0*dy1 - dx1*dy0;
      glNormal3f(Nx,Ny,Nz);   
      
      glTexCoord2f(0,0);
      glVertex3f(trian[9].x ,trian[9].y ,trian[9].z);
      glTexCoord2f(1,0);
      glVertex3f(trian[10].x ,trian[10].y ,trian[10].z);
      glTexCoord2f(0,1);
      glVertex3f(trian[11].x ,trian[11].y ,trian[11].z);
      
   glEnd();   
 
   glPopMatrix(); // Swap the front and back frame buffers (double buffering)
   glDisable(GL_TEXTURE_2D);
}
static void cones(double x, double y, double z,double sx, double sy, double sz, double th, int texindx){
   glPushMatrix();
   glTranslatef(x,y,z);
   glScaled(sx,sy,sz);
   glRotated(th,1,0,0);
   
   glEnable(GL_TEXTURE_2D);
      glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
      glColor3f(1,1,1);
      glBindTexture(GL_TEXTURE_2D,texture[texindx]);
      glColor3f(1,0,0); 
   const vtx trian[]={
         {0.0f, 0.05f, 0.0f},{-0.05f, -0.05f, 0.05f},{0.05f, -0.05f, 0.05f},
         {0.0f, 0.05f, 0.0f},{0.05f, -0.05f, 0.05f},{0.05f, -0.05f, -0.05f},
         {0.0f, 0.05f, 0.0f},{0.05f, -0.05f, -0.05f},{-0.05f, -0.05f, -0.05f},
         { 0.0f, 0.05f, 0.0f},{-0.05f,-0.05f,-0.05f},{-0.05f,-0.05f, 0.05f}


   };
   
   glBegin(GL_TRIANGLES);       
      //planar vector 0    
      // Front
      
      //glNormal3f(,Ny,Nz);
      float dx0=0;
      float dy0=0;
      float dz0=0;
      float dx1=0;
      float dy1=0;
      float dz1=0;
      dx0= trian[0].x-trian[1].x;
      dy0= trian[0].y-trian[1].y;
      dz0= trian[0].z-trian[1].z;

      dx1= trian[2].x-trian[0].x;
      dy1= trian[2].x-trian[0].x;
      dz1= trian[2].x-trian[0].x;
      float Nx = dy0*dz1 - dy1*dz0;
      float Ny = dz0*dx1 - dz1*dx0;
      float Nz = dx0*dy1 - dx1*dy0;
      glNormal3f(Nx,Ny,Nz);

      glTexCoord2f(0,0);
      glVertex3f(trian[0].x ,trian[0].y ,trian[0].z);
      glTexCoord2f(1,0);
      glVertex3f(trian[1].x ,trian[1].y ,trian[1].z);
      glTexCoord2f(0,1);
      glVertex3f(trian[2].x ,trian[2].y ,trian[2].z);
        


      glColor3f(1,1,1);
      dx0= trian[3].x-trian[4].x;
      dy0= trian[3].y-trian[4].y;
      dz0= trian[3].z-trian[4].z;

      dx1= trian[5].x-trian[3].x;
      dy1= trian[5].x-trian[3].x;
      dz1= trian[5].x-trian[3].x;
      Nx = dy0*dz1 - dy1*dz0;
      Ny = dz0*dx1 - dz1*dx0;
      Nz = dx0*dy1 - dx1*dy0;
      glNormal3f(Nx,Ny,Nz);   
      glTexCoord2f(0,0);
      glVertex3f(trian[3].x ,trian[3].y ,trian[3].z);
      glTexCoord2f(1,0);
      glVertex3f(trian[4].x ,trian[4].y ,trian[4].z);
      glTexCoord2f(0,1);
      glVertex3f(trian[5].x ,trian[5].y ,trian[5].z);
      dx0= trian[6].x-trian[7].x;
      dy0= trian[6].y-trian[7].y;
      dz0= trian[6].z-trian[7].z;

      dx1= trian[8].x-trian[6].x;
      dy1= trian[8].x-trian[6].x;
      dz1= trian[8].x-trian[6].x;
      Nx = dy0*dz1 - dy1*dz0;
      Ny = dz0*dx1 - dz1*dx0;
      Nz = dx0*dy1 - dx1*dy0;
      glNormal3f(Nx,Ny,Nz);  
    glColor3f(0,0,1);   
      glTexCoord2f(0,0);
      glVertex3f(trian[6].x ,trian[6].y ,trian[6].z);
      glTexCoord2f(1,0);
      glVertex3f(trian[7].x ,trian[7].y ,trian[7].z);
      glTexCoord2f(0,1);
      glVertex3f(trian[8].x ,trian[8].y ,trian[8].z);
      glColor3f(1,1,0);
      dx0= trian[9].x-trian[10].x;
      dy0= trian[9].y-trian[10].y;
      dz0= trian[9].z-trian[10].z;

      dx1= trian[11].x-trian[9].x;
      dy1= trian[11].x-trian[9].x;
      dz1= trian[11].x-trian[9].x;
      Nx = dy0*dz1 - dy1*dz0;
      Ny = dz0*dx1 - dz1*dx0;
      Nz = dx0*dy1 - dx1*dy0;
      glNormal3f(Nx,Ny,Nz);   
      
      glTexCoord2f(0,0);
      glVertex3f(trian[9].x ,trian[9].y ,trian[9].z);
      glTexCoord2f(1,0);
      glVertex3f(trian[10].x ,trian[10].y ,trian[10].z);
      glTexCoord2f(0,1);
      glVertex3f(trian[11].x ,trian[11].y ,trian[11].z);
      
   glEnd();   
 
   glPopMatrix(); // Swap the front and back frame buffers (double buffering)
   glDisable(GL_TEXTURE_2D);
}

static void conesro(double x, double y, double z,double sx, double sy, double sz, double th, double th2, double th3, int texindx){
   glPushMatrix();
   glTranslatef(x,y,z);
   glScaled(sx,sy,sz);
   glRotated(th,1,0,0);
   glRotated(th2,0,1,0);
   glRotated(th3,0,0,1);
   
   glEnable(GL_TEXTURE_2D);
      glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
      glColor3f(1,1,1);
      glBindTexture(GL_TEXTURE_2D,texture[texindx]);
      
   const vtx trian[]={
         {0.0f, 0.05f, 0.0f},{-0.05f, -0.05f, 0.05f},{0.05f, -0.05f, 0.05f},
         {0.0f, 0.05f, 0.0f},{0.05f, -0.05f, 0.05f},{0.05f, -0.05f, -0.05f},
         {0.0f, 0.05f, 0.0f},{0.05f, -0.05f, -0.05f},{-0.05f, -0.05f, -0.05f},
         { 0.0f, 0.05f, 0.0f},{-0.05f,-0.05f,-0.05f},{-0.05f,-0.05f, 0.05f}


   };
   
   glBegin(GL_TRIANGLES);       
      //planar vector 0    
      // Front
      
      //glNormal3f(,Ny,Nz);
      float dx0=0;
      float dy0=0;
      float dz0=0;
      float dx1=0;
      float dy1=0;
      float dz1=0;
      dx0= trian[0].x-trian[1].x;
      dy0= trian[0].y-trian[1].y;
      dz0= trian[0].z-trian[1].z;

      dx1= trian[2].x-trian[0].x;
      dy1= trian[2].x-trian[0].x;
      dz1= trian[2].x-trian[0].x;
      float Nx = dy0*dz1 - dy1*dz0;
      float Ny = dz0*dx1 - dz1*dx0;
      float Nz = dx0*dy1 - dx1*dy0;
      glNormal3f(Nx,Ny,Nz);

      glTexCoord2f(0,0);
      glVertex3f(trian[0].x ,trian[0].y ,trian[0].z);
      glTexCoord2f(1,0);
      glVertex3f(trian[1].x ,trian[1].y ,trian[1].z);
      glTexCoord2f(0,1);
      glVertex3f(trian[2].x ,trian[2].y ,trian[2].z);
        


      
      dx0= trian[3].x-trian[4].x;
      dy0= trian[3].y-trian[4].y;
      dz0= trian[3].z-trian[4].z;

      dx1= trian[5].x-trian[3].x;
      dy1= trian[5].x-trian[3].x;
      dz1= trian[5].x-trian[3].x;
      Nx = dy0*dz1 - dy1*dz0;
      Ny = dz0*dx1 - dz1*dx0;
      Nz = dx0*dy1 - dx1*dy0;
      glNormal3f(Nx,Ny,Nz);   
      glTexCoord2f(0,0);
      glVertex3f(trian[3].x ,trian[3].y ,trian[3].z);
      glTexCoord2f(1,0);
      glVertex3f(trian[4].x ,trian[4].y ,trian[4].z);
      glTexCoord2f(0,1);
      glVertex3f(trian[5].x ,trian[5].y ,trian[5].z);
      dx0= trian[6].x-trian[7].x;
      dy0= trian[6].y-trian[7].y;
      dz0= trian[6].z-trian[7].z;

      dx1= trian[8].x-trian[6].x;
      dy1= trian[8].x-trian[6].x;
      dz1= trian[8].x-trian[6].x;
      Nx = dy0*dz1 - dy1*dz0;
      Ny = dz0*dx1 - dz1*dx0;
      Nz = dx0*dy1 - dx1*dy0;
      glNormal3f(Nx,Ny,Nz);  
     
      glTexCoord2f(0,0);
      glVertex3f(trian[6].x ,trian[6].y ,trian[6].z);
      glTexCoord2f(1,0);
      glVertex3f(trian[7].x ,trian[7].y ,trian[7].z);
      glTexCoord2f(0,1);
      glVertex3f(trian[8].x ,trian[8].y ,trian[8].z);
      
      dx0= trian[9].x-trian[10].x;
      dy0= trian[9].y-trian[10].y;
      dz0= trian[9].z-trian[10].z;

      dx1= trian[11].x-trian[9].x;
      dy1= trian[11].x-trian[9].x;
      dz1= trian[11].x-trian[9].x;
      Nx = dy0*dz1 - dy1*dz0;
      Ny = dz0*dx1 - dz1*dx0;
      Nz = dx0*dy1 - dx1*dy0;
      glNormal3f(Nx,Ny,Nz);   
      
      glTexCoord2f(0,0);
      glVertex3f(trian[9].x ,trian[9].y ,trian[9].z);
      glTexCoord2f(1,0);
      glVertex3f(trian[10].x ,trian[10].y ,trian[10].z);
      glTexCoord2f(0,1);
      glVertex3f(trian[11].x ,trian[11].y ,trian[11].z);
      
   glEnd();   
 
   glPopMatrix(); // Swap the front and back frame buffers (double buffering)
   glDisable(GL_TEXTURE_2D);
}





static void demonoutline(double x, double y, double z, double dx, double dy, double dz, double th, int texindx){
   float color[] = {1,1,1,1};
   float Emission[]  = {0.0,0.0,0.01*emission,1.0};
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,color);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,Emission);
   glPushMatrix();
   glTranslated(x,y,z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);
   glEnable(GL_TEXTURE_2D);
   
   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
   
   
   glBindTexture(GL_TEXTURE_2D,texture[7]);
   
   glColor3f(1,0,0);
   
   
    
   if(ttype) glBindTexture(GL_TEXTURE_2D,texture[1]);

   //feet

   //heel
   sphere(0,0,0,0.4,0);
   sphere(0,0,2,0.4,0);
   //toes
   double size =0.3;
   for(double i=-1;i<=0;i=i+0.1){
      if(i<=-0.8){
         sphere(i,0,i,size,0);
      

      sphere(i,0,0,size,0);
      sphere(-i,0,-i*0.5,size,0);
      }
      else{
      sphere(i,cos(i*2)-0.8,i,size+0.02*i,0);
      

      sphere(i,cos(i*2)-0.8,0,size+0.02*i,0);
      sphere(-i,cos(i*2)-0.8,-i*0.5,size+0.02*i,0);
      }

   }
   
   for(double i=3;i>=2;i=i-0.1){
      if(i>=2.5){
         sphere(0,0,i,size,0);
      

         sphere(i-3.5,0,i*0.5,size,0);
      sphere(0,0,i*0.5,size,0);
      }
 

   }

   //legs
   for(double i=0;i<=2;i=i+ 0.1){
      
      sphere(0,i,0,size,0);
      sphere(0,i,2, size,0);
   }
   //knee
   
   sphere(0,2,0,size*2,0);
   sphere(0,2,2,size*2,0);


   //thigh

   for(double i=2;i<=4;i=i+ 0.1){
      
      sphere(0,i,0,size,0);
      sphere(0,i,2, size,0);
   }

   //hip

   for(double i=2.5;i>=-0.5; i=i-0.05 ){
      sphere(0,4,i,size,10);
      sphere(0,4,i,size,10);
      //sphere(i,4,2, size,0);
   }

   //spine

   for(double i=4; i<=8; i=i+0.05){
      sphere(1.2,i,0.80,size,0);
      if(i==4.5 ||i==5 || i==5.5){
         cone(1.25,i,1.9);
      }
   }

   //ribs
   double rib;
   for(double i=5.0;i<8.0; i++ ){
      //left
      rib=2;
      for(double j =0.3;j<=1.9;j=j+0.05){
         sphere(j,i,cos(rib),size*(j/2),0);
         rib=rib+0.1;

      }
      rib=2;
      
     


      //right
      for(double j =-0.01;j<=1.9;j=j+0.05){
         sphere(j,i,2-cos(rib),size*(j/2),0);
         rib=rib+0.1;

      }
      
      
      //sphere(i,4,2, size,0);
   }


   

   
   //chest
   
   for(double i=5; i<=7; i++){
      if(i>=6){
      sphere(0.0,i,1.2,size*1.5,9);
      }
      else{
         sphere(-0.2,i,1.2,size*1.5,9);
      }
      
      //sphere(i,4,2, size,0);
   }

   //neck
   double neck=1;
   for(double i=8; i<=9.5; i=i+0.05){
      if(i<=8.75){
      sphere(1.5-cos(neck),i,1.2,size*0.5,11);
      neck=neck+0.05;
      }
      else{
         sphere(1.5-cos(neck),i,1.2,size*0.5,11);
         neck=neck-0.05;
      }
      
      
      //sphere(i,4,2, size,0);
   }

   //head 
   for(double i=9; i<10; i=i+0.25){
      

      
         for(double j=-0.1;j<=1.5;j=j+0.1){
            if(j<0){
            spheredemon(j,i,1.0,-size*(j/1.5),0.5,0.5,0);

            spheredemon(j,i,1.4,-size*(j/1.5),0.5,0.5,0);
            }
            else{
            spheredemon(j,i,1.0,size*(j/1.5),1,1,1);

            spheredemon(j,i,1.4,size*(j/1.5),1,1,1);
            }
         }
         
      
}
      //eyes
      double i = 10.0;
      double ji =3;
      for(double j=1.0; j<=1.4;j=j+0.08){
            if(j==1){
               spheredemon(j-0.5,i,1.0,size*(1.4/(j+ji))*0.8,0.1,0.1,0.1);
            spheredemon(j-0.5,i,1.4,size*(1.4/(j+ji))*0.8,0.1,0.1,0.1);
            i=i+0.1;
            ji+=1;
            }
            else{
               
               spheredemon(j-0.5,i,1.0,size*(1.4/(j+ji))*0.8,1,0,0);
            spheredemon(j-0.5,i,1.4,size*(1.4/(j+ji))*0.8,1,0,0);
            i=i+0.1;
            ji+=1;
            }
            

      }

      //horns
      double i1 = 10.0;
      double ji1 =3;
      for(double j=1.0; j<=1.4;j=j+0.08){
            if(j==1){
               
               spheredemon(j+0.75,i1,1.0,size*(1.4/(j+ji1))*0.8,0,0,0);
            spheredemon(j+0.75,i1,1.4,size*(1.4/(j+ji1))*0.8,0,0,0);
            i=i+0.1;
            ji+=1;
            }
            else{
              
               spheredemon(j+0.75,i1,1.0,size*(1.4/(j+ji1))*0.8,0,0,0);
            spheredemon(j+0.75,i1,1.4,size*(1.4/(j+ji1))*0.8,0,0,0);
            i=i+0.1;
            ji+=1;
            }
            

      }


      //sphere(i,4,2, size,0);
   

   
   
   glPopMatrix();
   glDisable(GL_TEXTURE_2D); 

}

static void signs(double x, double y, double z, double dx, double dy, double dz, double th, int texindx){
   
   float white[] = {1,1,1,1};
   float Emission[]  = {0.0,0.0,0.01*emission,1.0};
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,Emission);
   glPushMatrix();
   glTranslated(x,y,z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);
   glPolygonOffset(1,1);
   glEnable(GL_TEXTURE_2D);
   
   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
   glColor3f(1,1,1);
   
   glBindTexture(GL_TEXTURE_2D,texture[7]);
   if(color){
   glColor3f(1,0,0);
   }
   
    
   if(ttype) glBindTexture(GL_TEXTURE_2D,texture[1]);

   glBegin(GL_QUADS);
   
   glNormal3f( 0, 0, 1);
   
   glTexCoord2f(0,0);   glVertex3f(-1,-1, 1);
   
   
   glTexCoord2f(1,0);   glVertex3f(+1,-1, 1);
   glTexCoord2f(1,1);   glVertex3f(+1,+1, 1);
   glTexCoord2f(0,1);   glVertex3f(-1,+1, 1);
   
   
   




   if(color){
   glColor3f(1,1,0);
   }

   glEnd();

   glBindTexture(GL_TEXTURE_2D,texture[texindx]);
   glBegin(GL_QUADS);
   glNormal3f(+1, 0, 0);
   glNormal3f( 0, 0,-1);
   glTexCoord2f(0,0);   glVertex3f(+1,-1,-1);
   glTexCoord2f(1,0);   glVertex3f(-1,-1,-1);
   glTexCoord2f(1,1);   glVertex3f(-1,+1,-1);
   glTexCoord2f(0,1);   glVertex3f(+1,+1,-1);


   glTexCoord2f(0,0);   glVertex3f(+1,-1,+1);
   glTexCoord2f(1,0);   glVertex3f(+1,-1,-1);
   glTexCoord2f(1,1);   glVertex3f(+1,+1,-1);
   glTexCoord2f(0,1);   glVertex3f(+1,+1,+1);
   glEnd();

glBindTexture(GL_TEXTURE_2D,texture[texindx]);
   glBegin(GL_QUADS);
   
   //  Left
   if(color){
   glColor3f(0,1,0);
   }
   glNormal3f(-1, 0, 0);
      glTexCoord2f(0,0);glVertex3f(-1,-1,-1);
   glTexCoord2f(1,0);glVertex3f(-1,-1,+1);
   glTexCoord2f(1,1);glVertex3f(-1,+1,+1);
   glTexCoord2f(0,1); glVertex3f(-1,+1,-1);
   
   
   
  
   //  Top
   if(color){
   glColor3f(0,1,1);
   }
    glNormal3f( 0,+1, 0);
   glTexCoord2f(0,0);glVertex3f(-1,+1,+1);
   glTexCoord2f(1,0);glVertex3f(+1,+1,+1);
   glTexCoord2f(1,1);glVertex3f(+1,+1,-1);
   glTexCoord2f(0,1);glVertex3f(-1,+1,-1);
   
   
   
   
   //  Bottom
   if(color){
   glColor3f(1,0,1);
   }
   glNormal3f( 0,-one, 0);
      glTexCoord2f(0,0);  glVertex3f(-1,-1,-1);
   glTexCoord2f(1,0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1,1);glVertex3f(+1,-1,+1);
   glTexCoord2f(0,1); glVertex3f(-1,-1,+1);
 
  
   
   //sphere(x-0.1,y+1.5,z,0.25);
  
   glEnd();
   //glBegin(GL_TRIANGLE_FAN);
   //Vertex(30,90);
   //for(int th=15; th<=360;th+=15){
   //   Vertex(th,90-15);
   //}
   
   
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}



//mill update movement
static void mill(double x, double y, double z, double dx, double dy, double dz, double th, int texindx){
   
   float white[] = {1,1,1,1};
   float Emission[]  = {0.0,0.0,0.01*emission,1.0};
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,Emission);
   glPushMatrix();
   glTranslated(x,y,z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);
   glPolygonOffset(1,1);
   glEnable(GL_TEXTURE_2D);
   
   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
   glColor3f(1,1,1);
   
   glBindTexture(GL_TEXTURE_2D,texture[7]);
   if(color){
   glColor3f(1,0,0);
   }
   
   for(double angela = 0.0; angela<=90; angela+=1){
      cones(0,0.8,0,1.2,25,1.2,angela,1);
   }
   //for(double x1=)
   double decrease=1.0;

      for(double y1= 0.5; y1<=2.0;y1+=0.5){
         for(double z1= -0.5; z1<=0.5;z1+=0.5){
            for(double x1= -0.5; x1<=-0.5;x1+=0.5)
         conesro(x1+cos(bladeroll),y1,sin(z1+bladeroll),1.5*(decrease),1.5*(decrease),1.5*(decrease),-bladeroll*10000,-bladeroll*10000,-0,1);
         conesro(-cos(bladeroll),-y1,sin(z1-bladeroll),1.5*(decrease),1.5*(decrease),1.5*(decrease),0,bladeroll*10000,bladeroll*10000,1);
         
         decrease-=0.025;
         }
      }
   //for()
 
 
  
   
   //sphere(x-0.1,y+1.5,z,0.25);
  
   
   //glBegin(GL_TRIANGLE_FAN);
   //Vertex(30,90);
   //for(int th=15; th<=360;th+=15){
   //   Vertex(th,90-15);
   //}
   
   
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}



static void tree(double x, double y, double z, double dx, double dy, double dz, double th, int texindx){
   
   float white[] = {1,1,1,1};
   float Emission[]  = {0.0,0.0,0.01*emission,1.0};
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,Emission);
   glPushMatrix();
   glTranslated(x,y,z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);
   glPolygonOffset(1,1);
   glEnable(GL_TEXTURE_2D);
   
   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
   glColor3f(1,1,1);
   
   glBindTexture(GL_TEXTURE_2D,texture[7]);
   
   
   for(int angela = 0; angela<=360; angela+=8){
      conesro(0,1.2,0,1,25,1,angela,0,0, 13);
   }
   //for(double x1=)
   double distance = 0;
   double decrease=2.0;
      for(double y1= 1; y1<=3;y1+=0.1){
         conesro(0,y1,-0.25+distance,0.5,0.2,2.5*(decrease),-90,0,0, 13);
         conesro(0,y1,0.25-distance,0.5,0.2,2.5*(decrease),90,0,0, 13);
         conesro(-0.25+distance,y1,0,2.5*(decrease),0.2,0.5,0,0,90, 13);
         conesro(0.25-distance,y1,0,2.5*(decrease),0.2,0.5,0,0,-90, 13);
         distance+=0.0007;
         decrease-=(0.030/2);
      }
   //for()
 
 
  
   
   //sphere(x-0.1,y+1.5,z,0.25);
  
   
   //glBegin(GL_TRIANGLE_FAN);
   //Vertex(30,90);
   //for(int th=15; th<=360;th+=15){
   //   Vertex(th,90-15);
   //}
   
   
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}
static void path(double x, double y, double z, double dx, double dy, double dz, double th, int texindx){
   
   float white[] = {1,1,1,1};
   float Emission[]  = {0.0,0.0,0.01*emission,1.0};
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,Emission);
   glPushMatrix();
   glTranslated(x,y,z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);
   glEnable(GL_TEXTURE_2D);
   
   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,tmode?GL_REPLACE:GL_MODULATE);
   
   
   glBindTexture(GL_TEXTURE_2D,texture[texindx]);
   
   glColor3d(1,1,1);
    
   if(ttype) glBindTexture(GL_TEXTURE_2D,texture[1]);

   glBegin(GL_QUADS);
   
   glNormal3f( 0, 0, 1);
   
   glTexCoord2f(0,0);   glVertex3f(-1,-1, 1);
   
   
   glTexCoord2f(1,0);   glVertex3f(+1,-1, 1);
   glTexCoord2f(1,1);   glVertex3f(+1,+1, 1);
   glTexCoord2f(0,1);   glVertex3f(-1,+1, 1);
   
   
   




   

   glEnd();

   
   glBegin(GL_QUADS);
   glNormal3f(+1, 0, 0);
   glNormal3f( 0, 0,-1);
   glTexCoord2f(0,0);   glVertex3f(+1,-1,-1);
   glTexCoord2f(1,0);   glVertex3f(-1,-1,-1);
   glTexCoord2f(1,1);   glVertex3f(-1,+1,-1);
   glTexCoord2f(0,1);   glVertex3f(+1,+1,-1);


   glTexCoord2f(0,0);   glVertex3f(+1,-1,+1);
   glTexCoord2f(1,0);   glVertex3f(+1,-1,-1);
   glTexCoord2f(1,1);   glVertex3f(+1,+1,-1);
   glTexCoord2f(0,1);   glVertex3f(+1,+1,+1);
   glEnd();


   glBegin(GL_QUADS);
   
   //  Left
   
   glNormal3f(-1, 0, 0);
      glTexCoord2f(0,0);glVertex3f(-1,-1,-1);
   glTexCoord2f(1,0);glVertex3f(-1,-1,+1);
   glTexCoord2f(1,1);glVertex3f(-1,+1,+1);
   glTexCoord2f(0,1); glVertex3f(-1,+1,-1);
   
   
   
  
   //  Top
   
    glNormal3f( 0,+1, 0);
   glTexCoord2f(0,0);glVertex3f(-1,+1,+1);
   glTexCoord2f(1,0);glVertex3f(+1,+1,+1);
   glTexCoord2f(1,1);glVertex3f(+1,+1,-1);
   glTexCoord2f(0,1);glVertex3f(-1,+1,-1);
   
   
   
   
   //  Bottom
   
   
   
   glNormal3f( 0,-one, 0);
      glTexCoord2f(0,0);  glVertex3f(-1,-1,-1);
   glTexCoord2f(1,0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1,1);glVertex3f(+1,-1,+1);
   glTexCoord2f(0,1); glVertex3f(-1,-1,+1);
 
  
   
   //sphere(x-0.1,y+1.5,z,0.25);
  
   glEnd();
   //glBegin(GL_TRIANGLE_FAN);
   //Vertex(30,90);
   //for(int th=15; th<=360;th+=15){
   //   Vertex(th,90-15);
   //}
   
   
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}



void display(){
   ErrCheck("display");
   

   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   
   glEnable(GL_DEPTH_TEST);

   //glEnable(GL_CULL_FACE);
   glLoadIdentity();


   if(Ez==Demonz){
      mode++;
   }


   if(p==1){
      
      double Ex = -2*dim*Sin(th)*Cos(ph);
      double Ey = +2*dim        *Sin(ph);
      double Ez = +2*dim*Cos(th)*Cos(ph);
      gluLookAt(Ex,Ey+0.2,Ez , 0,0,0 , 0,Cos(ph),0);

   }
   else if(p==2){
      
      gluLookAt(Ex,Ey,Ez ,Ex+sin(th1),Ey+sin(ph1),Ez+cos(th1), 0,cos(ph1),0);
      flashx=Ex;
   
      flashz=Ez;
     // if(Ez==1)
   }
   else if(p==0){
      glRotated(ph,1,0,0);
      glRotated(th,0,1,0);
   }
   glShadeModel(smooth ? GL_SMOOTH : GL_FLAT);
   if (box) Sky(6*dim,0,35,0);
   
   if(light){
      float Ambient[]   = {0.01*ambient ,0.01*ambient ,0.01*ambient ,1.0};
      float Diffuse[]   = {0.01*diffuse ,0.01*diffuse ,0.01*diffuse ,1.0};
      float Specular[]  = {0.01*specular,0.01*specular,0.01*specular,1.0};
      //  Light position
      float Position[]  = {distance*Cos(zh),distance*Sin(zh),4,1.0};
      //  Draw light position as ball (still no lighting here)
      glColor3f(1,1,1);
      sphere1(Position[0],Position[1]+0.5,Position[2]-0.3 , 0.5);
      
      glEnable(GL_NORMALIZE);
      //  Enable lighting
      glEnable(GL_LIGHTING);
      //  Location of viewer for specular calculations
      glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,local);
      //  glColor sets ambient and diffuse color materials
      glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
      glEnable(GL_COLOR_MATERIAL);
      //  Enable light 0
      glEnable(GL_LIGHT0);
      //  Set ambient, diffuse, specular components and position of light 0
      glLightfv(GL_LIGHT0,GL_AMBIENT ,Ambient);
      glLightfv(GL_LIGHT0,GL_DIFFUSE ,Diffuse);
      glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
      glLightfv(GL_LIGHT0,GL_POSITION,Position);



   }
   if(light1){
      float Ambient[]   = {0.01*ambient ,0.01*ambient ,0.01*ambient ,1.0};
      float Diffuse[]   = {0.01*diffuse ,0.01*diffuse ,0.01*diffuse ,1.0};
      float Specular[]  = {0.01*specular,0.01*specular,0.01*specular,1.0};
      //  Light position
      float Position1[]  = {flashx, flashy,flashz,1.0};
      //  Draw light position as ball (still no lighting here)
      glColor3f(1,0,0);
      sphere1(flashx, flashy,flashz,0.01);
      
      glEnable(GL_NORMALIZE);
      //  Enable lighting
      glEnable(GL_LIGHTING);
      //  Location of viewer for specular calculations
      glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,1);
      //  glColor sets ambient and diffuse color materials
      glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
      glEnable(GL_COLOR_MATERIAL);
      //  Enable light 1
      glEnable(GL_LIGHT1);
      //  Set ambient, diffuse, specular components and position of light 1
      glLightfv(GL_LIGHT1,GL_AMBIENT ,Ambient);
      glLightfv(GL_LIGHT1,GL_DIFFUSE ,Diffuse);
      glLightfv(GL_LIGHT1,GL_SPECULAR,Specular);
      glLightfv(GL_LIGHT1,GL_POSITION,Position1);
   }
      else{
         glDisable(GL_LIGHTING);
      }
   switch (mode)
   {
      case 0: //The cemetery
         

         

         cross1 =0;
         //the obelisk :O
         //wglSwapIntervalEXT(1);
         //glXSwapIntervalEXT(1);
         
         mill(15,5,-15,2,2,2,1,1);
         
         cube(-0.2,0.45,0.1 , 0.05,0.5,0.05 , 0);
         cone(-0.2,1,0.1);
         glEnable(GL_POLYGON_OFFSET_FILL);
         cones(4,1.60,4, 500, 1.8, 1.5,0,1);

         skullwall(4,0.75,4 , 0.05,0.8,3 , -90);
         skullwall(-4,0.75,4 , 0.05,0.8,3 , -90);
         for(double i =4.5; i>1;i--){
            
               wills(4,0.0,i , 1,1,1);

               wills(-4,0.0,i , 1,1,1);
            
         }
         for(int i = 17;i<75;i+=20){
            
            skullwall(i,0.75,4 , 0.05,0.8,10 , -90);

         }

         for(int i = -17;i>-75;i-=20){
            skullwall(i,0.75,4 , 0.05,0.8,10 , -90);

         }

         if(Ez>7.5 || Ez<1.5){
            
               skullwall1(0,0.75,4 , 0.05,0.8,1 , -90);
            
         }

         signs(1.5,0.7,3.94 , 0.2,0.8,0.005 , 0,8);
         signs(-1.5,0.7,3.94 , 0.2,0.8,0.005 , 0,8);
         signs(2.5,0.7,3.94 , 0.2,0.8,0.005 , 0,8);
         signs(-2.5,0.7,3.94 , 0.2,0.8,0.005 , 0,8);
         glDisable(GL_POLYGON_OFFSET_FILL);
         //skullwall();

         tombstone(0.2,0,1.1 ,0.01,0.04,0.025 , 1,6);
         for(double loc= 20; loc>-20; loc-=1){
            for(double locx= -24; locx<24; locx+=6)
            if(locx!=0){
            tree(locx,0.5,loc,2,2,2,0,1);
            }
            
         }
         
         cross1 = 1-cross1;
         //sphere(0.2,0.05,1.1 ,0.025);
         
         for(double i = -20; i<=20;i=i+8){
            
            if(i!=0){
         
            tombstone(1.2,0,i+1 ,0.03,0.04,0.015 , 1,6);
            
            cross1 = 1-cross1;
            tombstone(2,0,i+1 ,0.15,0.2,0.075 , 0,6);
            cross1 = 1-cross1;
            tombstone(-1.4,0,i+1 ,0.15,0.2,0.075 , 0,6);
            cross1 = 1-cross1;
            tombstone(-2.5,0,i+1 ,0.15,0.2,0.075 , 0,6);
            cross1 = 1-cross1;

            }

         }
         
         //cross yard
         for(double i = -25;i<=25;i+=4){
            cross(i,0.03,0,0.1,0.1,0.1,0);
            
            
            cross(i,0.0,i,0.1,0.1,0.1,15);
          
            
            cross(0,0.0,i,0.1,0.1,0.1,60);
         }


         for(double i = -10.0;i>=-20;i-=0.5){
            for(double z = -10.0;z>=-20;z-=0.5){  
            cross(i,0.03,z,0.1,0.1,0.1,0);
            }
         
         }


         
         for(int i=30;i>=-7;i--){
            path(0,-0.1,i,0.7,0.001,1,90,12);
            path(i,-0.1,-10,0.7,0.001,1,0,12);
            path(i,-0.1,-4,0.7,0.001,1,0,12);
            path(i,-0.1,15,0.7,0.001,1,0,12);
            path(i,-0.1,7,0.7,0.001,1,0,12);
            path(i,-0.1,10,0.7,0.001,1,0,12);
         }

         cube(0.5,0,0.1 , 0.5,0.05,0.05 ,90);


         //dome
         sphere(-4,0.1,0.3,0.25, 1);
         cube(-4.0,0,0.3 ,0.25,0.1,0.25 , 90);


         
         
         
      
            demonoutline(Demonx,-0.1,Demonz,0.1,0.1,0.1,-90,0);
            //demonoutline(-Demonx,-0.1,Demonz,0.1,0.1,0.1,-90,0);
            demonoutline(sin(Demonx)+5,-0.1,cos(Demonz)+5,0.1,0.1,0.1,-90,0);
         
      
         cube(-0.6,0,0.1 , 0.05,0.05,0.05 , 0);
         cone(-0.6,0.1,0.1);
         cube(-0.9,0,0.1 , 0.05,0.05,0.05 , 0);
         cone(-0.9,0.1,0.1);
         
       
         
         terrain(0.1,-0.01,0.001, 150,0.2,150,0);
         //wglSwapIntervalEXT(0);
         //glxSwapIntervalEXT(0);

         break;
      case 1:
         sphere(0,0,0 , 0.4,1);
         //cone(0,0,0);
         sphere(0,1,0 , 0.2,1);
         break;
      
      case 2:

         //the obelisk :O
         cube(-0.2,0.45,0.1 , 0.05,0.5,0.05 , 0);
         cone(-0.2,1,0.1);




         cube(0.5,0,0.1 , 0.5,0.05,0.05 ,0);
         
         
         


         break;

   }
   //glDrawArrays(GL_TRIANGLES,0,500);
   //  Draw axes in white
   const double len=2.0;
   glColor3f(1,1,1);
   glBegin(GL_LINES);
   glVertex3d(0.0,0.0,0.0);
   glVertex3d(len,0.0,0.0);
   glVertex3d(0.0,0.0,0.0);
   glVertex3d(0.0,len,0.0);
   glVertex3d(0.0,0.0,0.0);
   glVertex3d(0.0,0.0,len);
   glEnd();



   //labels
   glRasterPos3d(len,0.0,0.0);
   Print("X");
   glRasterPos3d(0.0,len,0.0);
   Print("Y");
   glRasterPos3d(0.0,0.0,len);
   Print("Z");

   glWindowPos2i(5,5);
   

         if(p==0){
         Print("Angle=%d,%d FOV=%d  Mode=%d    Projection=   Orthogonal",th,ph,fov,mode);
      }
      else if(p==1){
         Print("Angle=%d,%d FOV=%d  Mode=%d    Projection=  Perspective",th,ph,fov,mode);
      }
      else if(p==2){
         Print("Ansgle=%f,%f FOV=%f  Mode=%d  Ex=%f  Ez=%f    Projection=  FirstPerson",th1,ph1,fov,mode, Ex, Ez);
      }
   
   
   
  
   glFlush();
   glutSwapBuffers();
   

}


void key(unsigned char ch, int x, int y)
{

   if(ch == 27)
      exit(0);


   //movement
   
   else if(ch=='a'){
      Ex-=0.05*cos(th1+90);
      Ez+=0.05*sin(th1+179);
      //zloc += 0.25*sin(View);

   }

 else if(ch=='s'){
      Ez-=0.05*sin(th1+90);
      Ex+=0.05*cos(th1+177.5);
      //zloc += 0.25*sin(View);
      
   }

   else if(ch=='w'){
      Ez+=0.05*sin(th1+90);
      Ex-=0.05*cos(th1+177.5);
      //zloc -= 0.25*sin(View);
   }

   else if(ch=='d'){
      Ex+=0.05*cos(th1+90);
      Ez-=0.05*sin(th1+179);
      //zloc += 0.25*sin(View);

   }
   






   else if(ch=='0')
      th1=ph1=th=ph=View=0;

   else if(ch=='c'||ch=='C'){
      color=1-color;

   }
   else if (ch == 'm')
      mode = (mode+1)%4;
   else if (ch == 'M')
      mode = (mode+3)%4;

   else if(ch=='Q'||ch=='q'){
      tmode=1-tmode;

   }
   else if(ch=='t'||ch=='T'){
      ttype=1-ttype;
   }

   else if (ch=='P' || ch=='p')
      p=(p+1)%3;
   else if(ch== '-' &&ch>1){
      fov--;

   }
   else if(ch== '+' &&ch<179){
      fov++;

   }
   else if(ch=='?'){
      box = 1-box;
   }
   else if(ch=='L'){
      light=1-light;
   }
   else if(ch=='l'){
      
      light1=1-light1;

   }
   else if(ch==32){
      Ey+=0.1;
   }
   else if(ch=='o'||ch=='O'){
      movement=1-movement;
   }
   else if (ch=='v'){
      distance = (distance+1)%10;
   }

   else if (ch=='[')
      ylight -= 0.1;
   else if (ch==']')
      ylight += 0.1;
   //  Ambient level
   else if (ch=='@' && ambient>0)
      ambient -= 5;
   else if (ch=='A' && ambient<100)
      ambient += 5;
   //  Diffuse level
   else if (ch=='#' && diffuse>0)
      diffuse -= 5;
   else if (ch=='D' && diffuse<100)
      diffuse += 5;
   //  Specular level
   else if (ch=='!' && specular>0)
      specular -= 5;
   else if (ch=='S' && specular<100)
      specular += 5;
   //  Emission level
   else if (ch=='e' && emission>0)
      emission -= 5;
   else if (ch=='E' && emission<100)
      emission += 5;
   //  Shininess level
   else if (ch=='n' && shininess>-1)
      shininess -= 1;
   else if (ch=='N' && shininess<7)
      shininess += 1;
   else if(ch=='V'){
      distance = (distance+9)%10;
   }

   Project();
   glutIdleFunc(movement?idle:NULL);
   glutPostRedisplay();

}





void reshape(int width, int height)
{

   asp = (height>0) ? (double)width/height : 1;

   glViewport(0,0,RES*width,RES*height);


   Project();
   

}

void special(int key, int x,int y)
{
   if(key==GLUT_KEY_RIGHT)
   {
      th-=1;
      th1-=0.1;

   }
   else if(key==GLUT_KEY_LEFT)

   {
      th+=1;
      th1+=0.1;

   }
   else if(key==GLUT_KEY_UP)
   
   {
      ph+=1;
      ph1+=0.1;

   }
   else if(key==GLUT_KEY_DOWN)
   
   {
      ph-=1;
      ph1-=0.1;

   }
    else if (key == GLUT_KEY_PAGE_DOWN)
      dim += 0.1;

   //  PageDown key - decrease dim
   else if (key == GLUT_KEY_PAGE_UP && dim>1)
      dim -= 0.1;


   th %= 360;
   ph %= 360;
   Project();
   glutPostRedisplay();
   
}


void idle()
{
   double t = glutGet(GLUT_ELAPSED_TIME)/5000.0;
   
   zh = fmod(90*t,360);
   move = fmod(90*t,360)*0.01;
   
   bladeroll = fmod(90*t,360)*5;
if(flag==0 && Demonz>3.5){
   
      Demonz=Demonz-0.05;
   
}
else{
   if(flag==0){
      Demonz=-7;
      flag=1;
   }
   if(Demonx>=0){
   Demonx=Demonx-0.1;
   }
   else{
      if(Demonz>=8){
      Demonz=Demonz+0.5;
      }
      else{
         if(flag==1){
            flag+=1;
         }
         if(Demonz>-15 && Demonx >-15){
         Demonz-=0.1;
         Demonx-=0.1;
         }
         else{
            Demonx=fmod(90*t,360)*0.01;
            Demonz=fmod(90*t,360)*0.01;
         }

      }
   }

}


   
   glutPostRedisplay();
}

int main(int argc, char *argv[])
{
   
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGBA |GLUT_DEPTH| GLUT_DOUBLE);
   //GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
   //glfwSwapInterval(1);
   glutCreateWindow("B_Fortunato_Final_Project");

   #ifdef USEGLEW

   if (glewInit()!=GLEW_OK) Fatal("Error initializing GLEW\n");

   #endif
   
   
   glutDisplayFunc(display);

   glutReshapeFunc(reshape);


   glutSpecialFunc(special);

   glutKeyboardFunc(key);

   glutIdleFunc(idle);
   texture[0] = LoadTexBMP("WhiteWall.bmp");
   texture[1] = LoadTexBMP("ROCK.bmp");
   texture[2] = LoadTexBMP("red-roof.bmp");
   texture[3] = LoadTexBMP("grass.bmp");
   texture[4] = LoadTexBMP("door.bmp");
   texture[5] = LoadTexBMP("moss.bmp");
   texture[6] = LoadTexBMP("tombstone1.bmp");
   texture[7] = LoadTexBMP("skull.bmp");
   texture[8] = LoadTexBMP("pentagram.bmp");
   texture[9] = LoadTexBMP("chesthead.bmp");
   texture[10] = LoadTexBMP("hip.bmp");
   texture[11] = LoadTexBMP("headskull.bmp");
   texture[12] = LoadTexBMP("path.bmp");
   texture[13] = LoadTexBMP("bark.bmp");
   texture[14] = LoadTexBMP("leaves.bmp");


   sky[0]=LoadTexBMP("sky.bmp");
   sky[1]=LoadTexBMP("stars.bmp");
   
   glutMainLoop();

   return 0;
}
