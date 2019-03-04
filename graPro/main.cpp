#include "GLUT/glut.h"
#include "OpenGL/OpenGL.h"
//#include "TextureBuilder.h"

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//#include "Model_3DS.h"

#define DEG2RAD(a) (a * 0.0174532925)
bool Lost=false;
bool Won=false;
bool Move = true;
bool s=true;
float CounterSofa=0.0;
float angle = 0.0;
float t= 1;
float bezierX=0 ;
float bezierY=0;
float bezierZ=0;
float bezierBool =0;
float HealthPoints=3;


bool Powerup = true;

float rotationWindMill = 0;


float patrickAngle =0 ;
float patrickAngleUp =0;
float patrickHand = 0;
float patrickMovement =0;


float jellyMovement=0;
float jellyX=0;
float jellyY=0;
float jellyT=1;


float SheldonAngle = 0;
float SheldonAngleUp=0;
float SheldonMovement=0;

float sheldonRight = 0;

float sheldonUp = 0;
float tSheldon=1;


float garyShell=1;
float scaleGary= 1;
float garyDeform = 0;


bool sideBool = true;


bool GaryMotion = true;
bool SpongeBobMotion = true;
bool PatrickMotion = true;
bool JellyFishMotion = true;
bool SheldonMotion = true;
bool KrabsMotion = true;
bool SceneMotion = true;


bool rotate = true;


float leftLeg = 0;
float leftThigh = 0;

float rightLeg = 0;
float rightThigh = 0;

float leftHand = 0;
float rightHand = 0;

float PepsiManRun= 0;
bool PepsiManJump = false;
float JumpCount = 0;
float zPepsiMan=0;
float xPepsiMan =0 ;
bool Sofa=true;

float bicycleZ = 400 ;
float bicycleRotate = -90 ;
bool bicycleMotion = false;

bool busBool = true ;
float busX= 0;
float busZ= 60;
float busMotion = 0 ;

float RedCarZ=90;

float sphereX = -6 ;
float rotateSphere = 0  ;
bool sphereMotion = false;

float krabsY = 0 ;
float krabsZ = 400;
bool krabs= false;
float xSofa=0;


GLuint texID;


// XZ position of the camera
float x = 0.0f, z = 6.0f;

void bezier(float t, int* p0,int* p1,int* p2,int* p3)
{
    //int res[2];
    bezierX=pow((1-t),3)*p0[0]+3*t*pow((1-t),2)*p1[0]+3*pow(t,2)*(1-t)*p2[0]+pow(t,3)*p3[0];
    bezierY=pow((1-t),3)*p0[1]+3*t*pow((1-t),2)*p1[1]+3*pow(t,2)*(1-t)*p2[1]+pow(t,3)*p3[1];
    // return res;
}


void bezierJelly(float t, int* p0,int* p1,int* p2,int* p3)
{
    //int res[2];
    jellyX=pow((1-t),3)*p0[0]+3*t*pow((1-t),2)*p1[0]+3*pow(t,2)*(1-t)*p2[0]+pow(t,3)*p3[0];
    jellyY=pow((1-t),3)*p0[1]+3*t*pow((1-t),2)*p1[1]+3*pow(t,2)*(1-t)*p2[1]+pow(t,3)*p3[1];
    // return res;
}

void bezierSheldon(float t, int* p0,int* p1,int* p2,int* p3)
{
    //int res[2];
    sheldonRight=pow((1-t),3)*p0[0]+3*t*pow((1-t),2)*p1[0]+3*pow(t,2)*(1-t)*p2[0]+pow(t,3)*p3[0];
    sheldonUp=pow((1-t),3)*p0[1]+3*t*pow((1-t),2)*p1[1]+3*pow(t,2)*(1-t)*p2[1]+pow(t,3)*p3[1];
    // return res;
}



void bezier2(float t, int* p0,int* p1,int* p2,int* p3)
{
    //int res[2];
    bezierZ=pow((1-t),3)*p0[0]+3*t*pow((1-t),2)*p1[0]+3*pow(t,2)*(1-t)*p2[0]+pow(t,3)*p3[0];
    bezierY=pow((1-t),3)*p0[1]+3*t*pow((1-t),2)*p1[1]+3*pow(t,2)*(1-t)*p2[1]+pow(t,3)*p3[1];
    // return res;
}

void bezier3(float t, int* p0,int* p1,int* p2,int* p3)
{
    //int res[2];
    bezierX=pow((1-t),3)*p0[0]+3*t*pow((1-t),2)*p1[0]+3*pow(t,2)*(1-t)*p2[0]+pow(t,3)*p3[0];
    bezierZ=(pow((1-t),3)*p0[0]+3*t*pow((1-t),2)*p1[0]+3*pow(t,2)*(1-t)*p2[0]+pow(t,3)*p3[0]);
    bezierY=pow((1-t),3)*p0[1]+3*t*pow((1-t),2)*p1[1]+3*pow(t,2)*(1-t)*p2[1]+pow(t,3)*p3[1];
    // return res;
}



class Vector3f {
public:
    float x, y, z;
    
    Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) {
        x = _x;
        y = _y;
        z = _z;
    }
    
    Vector3f operator+(Vector3f v) {
        return Vector3f(x + v.x, y + v.y, z + v.z);
    }
    
    Vector3f operator-(Vector3f v) {
        return Vector3f(x - v.x, y - v.y, z - v.z);
    }
    
    Vector3f operator*(float n) {
        return Vector3f(x * n, y * n, z * n);
    }
    
    Vector3f operator/(float n) {
        return Vector3f(x / n, y / n, z / n);
    }
    
    Vector3f unit() {
        return *this / sqrt(x * x + y * y + z * z);
    }
    
    Vector3f cross(Vector3f v) {
        return Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }
};
void SetupLights() {
    // Define Light source 0 ambient light
    GLfloat ambient[] = { 0.1f, 0.1f, 0.1, 1.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    
    // Define Light source 0 diffuse light
    GLfloat diffuse[] = {0.8, 0.8, 0.8, 1};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    
    GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    // Define Light source 0 Specular light
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    
    // Finally, define light source 0 position in World Space
    GLfloat light_position[] = { 40, 1000, 0, 1 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}
void SetupCamera() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 640 / 480, 0.001, 100);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if(sideBool){
        //        Side.look();
        gluLookAt(x-0.3
                  ,6.0f, z+zPepsiMan-4,
                  
                  0.0f, 1.0f, zPepsiMan-2,
                  0.0, 1.0f, zPepsiMan-2);
    }else{
        
        gluLookAt(x-0.3
                  ,4.0f+sheldonUp, z+zPepsiMan+14,
                  
                  0.0f, 1.0f, zPepsiMan+14,
                  0.0, 1.0f, zPepsiMan+14);
        
    }
    //    camera.look();
}

void Reshape(int w, int h)
{
    
    // Prevent a divide by zero, when window is too short
    if (h == 0)
        h = 1;
    float ratio = 1.0 * w / h;
    
    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);
    
    // Reset Matrix
    glLoadIdentity();
    
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    
    // Set the correct perspective.
    gluPerspective(45, ratio, 1, 1000);
    
    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}
void Animate(){
    if(SceneMotion){
        if(JellyFishMotion){
            if(jellyMovement==0){
                int s3[]={0,10};
                int s1[]={-5,5};
                int s2[]={5,5};
                int s0[]={0,0};
                //  std::cout<<randomBezier ;
                bezierJelly(jellyT, s3, s2, s1, s0);
                
                
                jellyT-=0.003;
                if(jellyT<=0){
                    jellyMovement=1;
                    jellyT=1;
                }
                
            }else {
                
                int s0[]={0,10};
                int s2[]={-5,5};
                int s1[]={5,5};
                int s3[]={0,0};
                
                bezierJelly(jellyT, s3, s2, s1, s0);
                
                jellyT-=0.003;
                if(jellyT<=0){
                    jellyT=1;
                    jellyMovement= 0;
                }
                
            }
        }
        
        
        
        if(PepsiManJump){
            
            if(JumpCount<40){
                sheldonUp+=0.05;
                
            }else{
                sheldonUp-=0.05;
            }
            JumpCount++;
            if(JumpCount>=80){
                JumpCount=0;
                PepsiManJump=false;
                
            }
            
            
            
            
            
        }
        
    }
    
    
    ///MotorCycle Collision
    if(xPepsiMan < jellyY+4 && xPepsiMan > jellyY-4){
        
        
        
        //        std::cout<<zPepsiMan;
        //        std::cout<<"\n";
        if (zPepsiMan >= 38.5 && zPepsiMan<=41.5) {
            std::cout<<"In";
            
            bicycleZ = 400 ;
            bicycleRotate = -90 ;
            busZ= 60;
            sphereX = -6 ;
            krabsZ = 770;
            zPepsiMan = 0;
            RedCarZ=90;
            HealthPoints--;
            
        }
        
    }
    
    
    //Red Car Collision
    if(zPepsiMan >= RedCarZ-7.8 && zPepsiMan <= RedCarZ+1.6){
        // std::cout<<"Ay haga";
        //         std::cout<<"\n";
        // std::cout<<xPepsiMan ;
        //         std::cout<<"\n";
        if(xPepsiMan<0 && xPepsiMan>-5){
            
            
            
            bicycleZ = 400 ;
            bicycleRotate = -90 ;
            busZ= 60;
            sphereX = -6 ;
            krabsZ = 770;
            RedCarZ = 90;
            zPepsiMan=0;
            HealthPoints--;
        }
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    //blocks collisions
    if((xPepsiMan>=-5 && xPepsiMan<=-1)&&(zPepsiMan>=104 && zPepsiMan<=106)){
        zPepsiMan=0;
        bicycleZ = 400 ;
        bicycleRotate = -90 ;
        busZ= 60;
        sphereX = -6 ;
        krabsZ = 770;
        
        RedCarZ=90;
        HealthPoints--;
    }
    if((xPepsiMan>=1 && xPepsiMan<=5)&&(zPepsiMan>=104 && zPepsiMan<=106)){
        bicycleZ = 400 ;
        bicycleRotate = -90 ;
        busZ= 60;
        sphereX = -6 ;
        krabsZ = 770;
        zPepsiMan = 0;
        RedCarZ=90;
        HealthPoints--;
    }
    if((xPepsiMan>=3 && xPepsiMan<=5)&&(zPepsiMan>=114 && zPepsiMan<=116)){
        bicycleZ = 400 ;
        bicycleRotate = -90 ;
        busZ= 60;
        sphereX = -6 ;
        krabsZ = 770;
        zPepsiMan = 0;
        RedCarZ=90;
        HealthPoints--;
    }
    if((xPepsiMan>=-5.5 && xPepsiMan<=0.5)&&(zPepsiMan>=114 && zPepsiMan<=116)){
        bicycleZ = 400 ;
        bicycleRotate = -90 ;
        busZ= 60;
        sphereX = -6 ;
        krabsZ = 770;
        zPepsiMan = 0;
        RedCarZ=90;
        HealthPoints--;
    }
    
    // power up collisions
    if((xPepsiMan >= 3.75 && xPepsiMan <=4.25) && (zPepsiMan>=49.5 && zPepsiMan<=50.5)){
        //        zPepsiMan =0;
        Powerup=false;
        if(HealthPoints<3)
            HealthPoints++;
        
    }
    if((xPepsiMan >= -3.25 && xPepsiMan <=-2.75) && (zPepsiMan>=149.5 && zPepsiMan<=150.5)){
        //        zPepsiMan =0;
        Powerup=false;
        if(HealthPoints<3)
            HealthPoints++;
    }
    if((xPepsiMan >= -0.25 && xPepsiMan <=0.25) && (zPepsiMan>=199.5 && zPepsiMan<=200.5)){
        //      zPepsiMan =0;
        Powerup=false;
        if(HealthPoints<3)
            HealthPoints++;
        
    }
    
    
    ///Pepsi Man motion
    if(rotate){
        float radius=8.0f;
        angle = 3.1;
        
        // std::cout<<zPepsiMan;
        std::cout<<"\n";
        x = radius * sin(angle);
        z = radius * cos(angle);
        if(Move){
            zPepsiMan+=0.2;
        }
        if(PepsiManRun < 20){
            rightLeg = 45;
            rightThigh=-45;
            leftHand=-40;
            
            leftLeg = 0;
            leftThigh=0;
            rightHand=0;
            
            PepsiManRun++;
        }else{
            rightLeg = 0;
            rightThigh=0;
            leftHand=0;
            leftLeg = 45;
            leftThigh=-45;
            rightHand=-40;
            
            PepsiManRun++;
            if(PepsiManRun>40){
                PepsiManRun=0;
            }
        }
    }
    
    
    ///Bicycle Collision Stage 3
    
    if(zPepsiMan <=221 && zPepsiMan>=219){
        // std::cout<<"Xpepsi Man";
        // std::cout<<xPepsiMan;
        // std::cout<<"Xpepsi Man";
        if(xPepsiMan<=7 && xPepsiMan >= 2){
            bicycleZ = 400 ;
            bicycleRotate = -90 ;
            busZ= 60;
            sphereX = -6 ;
            krabsZ = 770;
            zPepsiMan = 0;
            RedCarZ=90;
            HealthPoints--;
        }
    }
    
    
    ///Bus Collision
    if(zPepsiMan>=busZ-2.5 && zPepsiMan <= busZ+2.5){
        if (xPepsiMan>=busX-2 && xPepsiMan<= busX+2) {
            bicycleZ = 400 ;
            bicycleRotate = -90 ;
            busZ= 60;
            sphereX = -6 ;
            krabsZ = 770;
            zPepsiMan = 0;
            RedCarZ=90;
            HealthPoints--;
        }
    }
    
    if(!bicycleMotion){
        bicycleZ-=0.4;
        if(bicycleZ<=30)
            bicycleMotion=true;
    }else{
        bicycleRotate++;
        if (bicycleRotate>=0) {
            bicycleRotate=0;
        }
    }
    
    if(busBool){
        if(busMotion < 20){
            busZ-=0.2;
            busX-=0.1;
            busMotion++;
        }else{
            busZ+=0.2;
            busX-=0.1;
            busMotion++;
            if(busMotion>=40){
                busMotion = 0;
            }
        }
        if(busX <=-3){
            busBool = false;
            busMotion = 0;
        }
    }else{
        if(busMotion < 20){
            busZ+=0.2;
            busX+=0.1;
            busMotion++;
        }else{
            busZ-=0.2;
            busX+=0.1;
            busMotion++;
            if(busMotion>=40){
                busMotion = 0;
            }
        }
        if(busX >=2){
            busBool = true;
        }
        
    }
    
    //SpheresMotion
    if(sphereMotion){
        sphereX+=0.2;
        if(sphereX>=6){
            sphereMotion=false;
        }
    }else{
        sphereX-=0.2;
        if(sphereX<=-6){
            sphereMotion=true;
        }
    }
    
    //Krabs Y
    if(krabs){
        krabsY+=0.2;
        if(krabsY>=5){
            krabs = false;
        }
        
    }else{
        krabsY-=0.2;
        if(krabsY<=1){
            krabs= true;
        }
    }
    
    
    //collision spheres
    if((xPepsiMan >= sphereX-1 && xPepsiMan <=sphereX+1) && (zPepsiMan>=239 && zPepsiMan<=241)){
        bicycleZ = 400 ;
        bicycleRotate = -90 ;
        busZ= 60;
        sphereX = -6 ;
        krabsZ = 770;
        zPepsiMan = 0;
        RedCarZ=90;
        HealthPoints--;
    }
    
    RedCarZ-=0.4;
    krabsZ-= 0.3 ;
    rotationWindMill+=5;
    if(CounterSofa==100){
        Sofa=false;
    }
    if(CounterSofa==0){
        Sofa = true;
    }
    
    
    if(Sofa){
        
        xSofa+=0.1;
        CounterSofa++;
    }
    if(!Sofa){
        
        xSofa-=0.1;
        CounterSofa--;
    }
    if((xPepsiMan<-10.5+xSofa&&xPepsiMan>-16.5+xSofa)&&(zPepsiMan>152.5&&zPepsiMan<165.5)){
        zPepsiMan=0.0;
        HealthPoints--;
    }
    
    if((xPepsiMan>11.5-xSofa&&xPepsiMan<18-xSofa)&&(zPepsiMan>123.5&&zPepsiMan<132.5)){
        zPepsiMan=0.0;
        HealthPoints--;
    }
    if(HealthPoints==0){
        Move=false;
        Lost=true;
    }
    
    if(zPepsiMan>280){
        Move=false;
        Won=true;
    }
    std::cout<<zPepsiMan;
    glutPostRedisplay();
}


void drawTable(){
    //main matrix
    glPushMatrix();
    //round top
    glPushMatrix();
    glTranslated(0,2,0);
    glScaled(4,0.5,1.5);
    glRotated(90,1,0,0);
    glColor3d(124/255.0, 64/255.0, 24/255.0);
    glutSolidCube(1);
    glPopMatrix();
    
    
    
    //bottom cube
    glPushMatrix();
    glTranslated(-1.5, 0, 0.25);
    glScaled(0.3,4,0.5);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(-1.5, 0, -0.25);
    glScaled(0.3,4,0.5);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(1.5, 0, -0.25);
    glScaled(0.3,4,0.5);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(1.5, 0, 0.25);
    glScaled(0.3,4,0.5);
    glutSolidCube(1);
    glPopMatrix();
    
    glPopMatrix();
}

void drawBlock(){
    //main matrix
    glPushMatrix();
    //block
    glPushMatrix();
    glTranslated(0,1,0);
    glScaled(1,0.5,1);
    glRotated(90,1,0,0);
    glColor3d(0,0,1);
    glutSolidCube(2);
    glPopMatrix();
    glPopMatrix();
    
}
//draw powerups

void drawPowerUp(){
    glPushMatrix();
    glColor3d(0,0,1);
    glScaled(0.5,1,1);
    glPushMatrix();
    glutSolidCube(0.5);
    // glutSolidCube(1);// scaled into 0.5,1
    glPopMatrix();
    glPopMatrix();
}


//draw tables
void couch(){
    
    
    
    glPushMatrix();
    glTranslated(0.3, 1, 0);
    glScaled(0.16, 0.4, 0.16);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0.14, 1, 0);
    glScaled(0.16, 0.16, 0.16);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0.14, 1, 0);
    glScaled(0.16, 0.16, 0.16);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0.14, 1, 0);
    glScaled(0.16, 0.16, 0.16);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);
    glutSolidCube(1);
    
    glPopMatrix();
    glPopMatrix();
}

void tv(){
    glPushMatrix();
    glColor3d(0, 0, 0);
    glScaled(1, 2, 3);
    glutSolidCube(1);
    glPopMatrix();
}

void drawAladdin(){
    
    //----------left leg-----------
    //----------left leg-----------
    //----------left leg-----------
    glPushMatrix();
    glTranslated(0, 1.4, 0);
    glRotated(leftThigh, 1, 0, 0);
    glTranslated(0, -1.4, 0);
    
    glPushMatrix();
    glTranslated(0.14, 1, 0);
    glScaled(0.16, 1, 0.16);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);
    //glutSolidCube(1);
    glutSolidSphere(0.55, 20, 10);
    glPopMatrix();
    glPopMatrix();
    
    
    ///////////Left Leg Rotation
    glPushMatrix();
    glTranslated(0, 0.5, 0);
    glRotated(leftLeg, 1, 0, 0);
    glTranslated(0, -0.5, 0);
    ///////////////////////
    
    glPushMatrix();
    glTranslated(0.14, 0.3, 0);
    glScaled(0.1, 0.5, 0.1);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);    //glutSolidCube(1);
    glutSolidSphere(0.55, 20, 10);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0.14, 0, 0.07);
    glScaled(0.1, 0.08, 0.2);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);
    //glutSolidCube(1);
    glutSolidSphere(0.55, 20, 10);
    glPopMatrix();
    glPopMatrix();
    
    
    
    glPopMatrix();
    
    
    glPopMatrix();
    
    
    
    
    
    //---------right leg---------
    //---------right leg---------
    //---------right leg---------
    glPushMatrix();
    glTranslated(0, 1.4, 0);
    glRotated(rightThigh, 1, 0, 0);
    glTranslated(0, -1.4, 0);
    
    
    glPushMatrix();
    
    glTranslated(-0.14, 1, 0);
    glScaled(0.16, 1, 0.16);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);    //glutSolidCube(1);
    glutSolidSphere(0.55, 20, 10);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix(); /////////////////
    glTranslated(0, 0.5, 0);
    glRotated(rightLeg, 1, 0, 0);
    glTranslated(0, -0.5, 0);
    
    
    glPushMatrix();
    glTranslated(-0.14, 0.3, 0);
    glScaled(0.1, 0.5, 0.1);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);    //glutSolidCube(1);
    glutSolidSphere(0.55, 20, 10);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(-0.14, 0, 0.07);
    glScaled(0.1, 0.08, 0.2);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);
    //glutSolidCube(1);
    glutSolidSphere(0.55, 20, 10);
    glPopMatrix();
    glPopMatrix();
    
    
    glPopMatrix();
    
    
    glPopMatrix();
    
    
    
    //////
    ///////
    ////////
    
    
    
    glPushMatrix();
    //    glRotatef(AladdinWA, 1, 0, 0);
    //    glTranslated(0, 0, AladdinWZ);
    //glTranslated(0, -0.1, 0.5);
    
    glPushMatrix();
    
    glPushMatrix();
    glTranslated(0, 1.76, 0);
    glScaled(0.18, 0.42, 0.12);
    //glRotated(180, 0, 1, 0);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);    //    glutSolidCube(2);
    glutSolidSphere(1.3, 20, 10);
    glPopMatrix();
    glPopMatrix();
    
    //---------here---------
    
    
    glPushMatrix();
    glTranslated(0, 1.5, 0);
    glScaled(0.21, 0.3, 0.16);
    //glRotated(180, 0, 1, 0);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);
    glutSolidSphere(1, 30, 20);
    //  glutSolidCube(2);
    glPopMatrix();
    glPopMatrix();
    
    
    
    //------------CHEST--------------
    //------------CHEST--------------
    //------------CHEST--------------
    
    glPushMatrix();
    glTranslated(0.08, 2.05, 0.02);
    glScaled(0.16, 0.21, 0.13);
    glRotated(100, 0, 0, 1);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);
    glutSolidSphere(1, 30, 20);
    glPopMatrix();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslated(-0.08, 2.05, 0.02);
    glScaled(0.16, 0.21, 0.13);
    //glRotated(180, 0, 1, 0);
    glPushMatrix();
    glColor3f(1, 1, 1);
    glutSolidSphere(1, 30, 20);
    glPopMatrix();
    glPopMatrix();
    
    
    //----------------LEFT ARM------------------
    //----------------LEFT ARM------------------
    //----------------LEFT ARM------------------
    
    glPushMatrix();
    //    glRotated(AladdinLAAA, 0, 1, 0);
    //    glRotated(AladdinLAA, 0, 1, 0);
    //    glTranslated(AladdinLX, AladdinLY, AladdinLZ);
    glTranslated(0.23,2.08,0);
    glRotated(-70, 0, 0, 1);
    glRotated(leftHand, 0, 1, 0);
    glTranslated(-0.23,-2.08,0);
    
    
    
    
    
    glPushMatrix();
    glPushMatrix();
    glTranslated(0.42, 2.08, 0);
    glScaled(1, 0.25, 0.2611);
    //glRotated(180, 0, 1, 0);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);
    //glutSolidIcosahedron();
    //glutSolidCube(0.7);
    glutSolidSphere(0.33, 20, 10);
    glPopMatrix();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslated(0.73, 2.08, 0);
    glScaled(1, 0.25, 0.2611);
    //glRotated(180, 0, 1, 0);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);
    //glutSolidIcosahedron();
    //glutSolidCube(0.7);
    glutSolidSphere(0.27, 20, 10);
    glPopMatrix();
    glPopMatrix();
    
    
    
    glPushMatrix();
    glTranslated(1, 2.08, 0);
    glScaled(0.2, 0.15, 0.2611);
    //glRotated(180, 0, 1, 0);
    glPushMatrix();
    glColor3d(10/255.0, 89/255.0, 244/255.0);
    //glutSolidIcosahedron();
    //glutSolidCube(0.7);
    glutSolidSphere(0.27, 20, 10);
    glPopMatrix();
    glPopMatrix();
    
    glPopMatrix();
    glPopMatrix();
    
    
    
    
    
    //----------------RIGHT ARM------------------
    //----------------RIGHT ARM------------------
    //----------------RIGHT ARM------------------
    
    
    
    
    glPushMatrix();
    //////////right Hand Rotation ////
    glTranslated(-0.23,2.08,0);
    glRotated(70, 0, 0, 1);
    glRotated(-rightHand, 0, 1, 0);
    glTranslated(0.23,-2.08,0);
    ////////////////
    
    glPushMatrix();
    glPushMatrix();
    glTranslated(-0.42, 2.08, 0);
    glScaled(1, 0.25, 0.2611);
    //glRotated(180, 0, 1, 0);
    glPushMatrix();
    glColor3f(1, 1, 1);
    
    //glutSolidIcosahedron();
    //glutSolidCube(0.7);
    glutSolidSphere(0.33, 20, 10);
    glPopMatrix();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslated(-0.73, 2.08, 0);
    glScaled(1, 0.25, 0.2611);
    //glRotated(180, 0, 1, 0);
    glPushMatrix();
    glColor3f(1, 1, 1);
    
    //glutSolidIcosahedron();
    //glutSolidCube(0.7);
    glutSolidSphere(0.27, 20, 10);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(-1, 2.08, 0);
    glScaled(0.2, 0.15, 0.2611);
    //glRotated(180, 0, 1, 0);
    glPushMatrix();
    glColor3f(1, 1, 1);
    
    //glutSolidIcosahedron();
    //glutSolidCube(0.7);
    glutSolidSphere(0.27, 20, 10);
    glPopMatrix();
    glPopMatrix();
    
    glPopMatrix();
    glPopMatrix();
    
    glPopMatrix();
    
    //-------------------HEAD-----------------------
    //-------------------HEAD-----------------------
    //-------------------HEAD-----------------------
    
    glPushMatrix();
    glTranslated(0, 2.55, 0);
    glScaled(0.15, 0.5, 0.15);
    //glRotated(180, 0, 1, 0);
    glPushMatrix();
    glColor3f(1, 1, 1);
    //glutSolidIcosahedron();
    //glutSolidCube(0.7);
    glutSolidSphere(0.75, 20, 10);
    glPopMatrix();
    glPopMatrix();
    
    
    
}



void mrKrabs(){
    
    
    glPushMatrix();
    glRotated(90, 0, 0, 1);
    //Shirt
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, 1.18, 0);
    glScaled(0.62, 0.2, 0.62);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, 1.08, 0);
    glScaled(0.64, 0.2, 0.64);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, 0.98, 0);
    glScaled(0.64, 0.2, 0.64);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, 0.88, 0);
    glScaled(0.64, 0.2, 0.64);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, 0.78, 0);
    glScaled(0.64, 0.2, 0.64);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, 0.68, 0);
    glScaled(0.64, 0.2, 0.64);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    
    //Pants
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, 0.58, 0);
    glScaled(0.62, 0.2, 0.62);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, 0.48, 0);
    glScaled(0.64, 0.2, 0.64);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, 0.38, 0);
    glScaled(0.64, 0.2, 0.64);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, 0.28, 0);
    glScaled(0.64, 0.2, 0.64);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, 0.18, 0);
    glScaled(0.64, 0.2, 0.64);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, 0.08, 0);
    glScaled(0.64, 0.2, 0.64);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, -0.02, 0);
    glScaled(0.64, 0.2, 0.64);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, -0.12, 0);
    glScaled(0.64, 0.2, 0.64);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, -0.22, 0);
    glScaled(0.64, 0.2, 0.64);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3d(93/255.0,67/255.0,59/255.0);
    glTranslated(-0, -0.32, 0);
    glScaled(0.64, 0.2, 0.64);
    glutSolidSphere(2.0,15,15);
    glPopMatrix();
    
    
    glPopMatrix();
    //legs
    
    
    
}
void bus(){
    glPushMatrix();
    
    glPushMatrix();
    glColor3f(0,0,0.7);
    glTranslatef(-3,2,-2.5);
    glScalef(5,2,2.5);
    glutSolidCube(2);
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-6.8,0,0);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0.8,0,0);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0.8,0,0);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0.8,0,-4.8);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0.8,0,0);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-6.8,0,-4.8);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    glPushMatrix();
    
    glTranslatef(-7.7f, 1.0f, -1.0f);
    glScalef(0.3,1,1);
    glutSolidSphere(0.4f,20,20);
    glPopMatrix();
    glPushMatrix();
    
    glTranslatef(-7.7f, 1.0f, -4.0f);
    glScalef(0.3,1,1);
    glutSolidSphere(0.4f,20,20);
    glPopMatrix();
    glPopMatrix();
    
    
}

void car(){
    glPushMatrix();
    glTranslatef(-5, 0, RedCarZ);
    glRotated(-90, 0, 1, 0);
    
    
    /////Right Side
    glPushMatrix();
    glColor3f(0.8,0,0);
    glTranslatef(-3,1.5,0);
    glScalef(3,1.3,0.1);
    glutSolidCube(2);
    glPopMatrix();
    
    
    
    glPushMatrix();
    glColor3f(0.8,0,0);
    glTranslatef(-3,2.75,-2.4);
    glRotatef(90,1.0,0.0,0.0);
    glScalef(3,2.4,0.1);
    
    glutSolidCube(2);
    glPopMatrix();
    
    
    
    ///Left Side
    glPushMatrix();
    glColor3f(0.8,0,0);
    glTranslatef(-3,1.5,-4.8);
    glScalef(3,1.3,0.1);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.8,0,0);
    glTranslatef(-6.8,2.25,-2.4);
    glRotatef(90,1.0,0.0,0.0);
    glRotatef(30,0.0,1.0,0.0);
    glScalef(1,2.4,0.1);
    
    glutSolidCube(2);
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3f(0.8,0,0);
    glTranslatef(0.8,2.25,-2.4);
    glRotatef(90,1.0,0.0,0.0);
    glRotatef(-30,0.0,1.0,0.0);
    glScalef(1,2.4,0.1);
    
    glutSolidCube(2);
    glPopMatrix();
    
    
    
    ///FRONTT
    glPushMatrix();
    glColor3f(0.8,0,0);
    glTranslatef(-7.6,1.0,-2.4);
    glRotatef(90,1.0,0.0,0.0);
    glRotatef(90,0.0,1.0,0.0);
    glScalef(0.8,2.4,0.1);
    
    glutSolidCube(2);
    glPopMatrix();
    
    
    
    
    ///Back
    glPushMatrix();
    glColor3f(0.8,0,0);
    glTranslatef(1.65,1,-2.4);
    glRotatef(90,1.0,0.0,0.0);
    glRotatef(90,0.0,1.0,0.0);
    glScalef(0.8,2.4,0.1);
    
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-6.8,0,0);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0.8,0,0);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0.8,0,0);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0.8,0,-4.8);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0.8,0,0);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-6.8,0,-4.8);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    glPushMatrix();
    
    glTranslatef(-7.7f, 1.0f, -1.0f);
    glScalef(0.3,1,1);
    glutSolidSphere(0.4f,20,20);
    glPopMatrix();
    glPushMatrix();
    
    glTranslatef(-7.7f, 1.0f, -4.0f);
    glScalef(0.3,1,1);
    glutSolidSphere(0.4f,20,20);
    glPopMatrix();
    glPopMatrix();
}
void sabar(){
    glPushMatrix();
    glColor3d(65/255.0, 132/255.0, 44/255.0);
    glTranslated(12, 4, 40);
    glScaled(0.5,2.5,0.5);
    glutSolidSphere(10.0, 100, 100);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(65/255.0, 132/255.0, 44/255.0);
    glRotated(30.0, 0, 0, 1);
    glTranslated(12, 4, 40);
    glScaled(0.25,1.25,0.25);
    glutSolidSphere(10.0, 100, 100);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(65/255.0, 132/255.0, 44/255.0);
    glRotated(-30.0, 0, 0, 1);
    glTranslated(13, 6, 40);
    glScaled(0.25,1.25,0.25);
    glutSolidSphere(10.0, 100, 100);
    glPopMatrix();
    
}
void motorCycle(){
    glPushMatrix();
    //    glRotated(-90, 0, 1, 0);
    glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(0,2.4,0);
    glScalef(4,2,1.5);
    glutSolidCube(2);
    glPopMatrix();
    
    
    
    
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(1.5,0,1.5);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    glPushMatrix();
    
    
    
    glColor3f(0,0,0);
    glTranslatef(1.5,0,-1.5);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    
    
    
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-4,0,0);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    
    glPopMatrix();
}
void drawStrokeText(char*string,int x,int y,int z)
{
    char *c;
    glPushMatrix();
    //	  glRotatef(90,0,0,0);
    glTranslatef(x, y+8,z);
    glScalef(0.009f,-0.008f,z);
    
    for (c=string; *c != ' '; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
    }
    glPopMatrix();
}


void biCycle(){
    glPushMatrix();
    glTranslated(3, 0, 0);
    glRotated(bicycleRotate, 0, 1, 0);
    glTranslated(-3, 0, 0);
    glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(0,3,0);
    glScalef(3,2,1);
    glutSolidCube(2);
    glPopMatrix();
    
    
    
    
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(3,0,0);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    
    
    
    
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-3,0,0);
    glScalef(0.35,0.35,0.35);
    
    glutSolidTorus(1,2,50,50);
    glPopMatrix();
    
    glPopMatrix();
}

void sphere(){
    glPushMatrix();
    glPushMatrix();
    glutSolidSphere(2,1000,100);
    glPopMatrix();
    glPopMatrix();
}



void finale(){
    glPushMatrix();
    glColor3d(0.5, 0.5, 0.5);
    glTranslated(24,1,300);
    glScaled(1, 14, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(0.5, 0.5, 0.5);
    glTranslated(18,1,300);
    glScaled(1, 14, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(0.5, 0.5, 0.5);
    glTranslated(12,1,300);
    glScaled(1, 14, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(0.5, 0.5, 0.5);
    glTranslated(6,1,300);
    glScaled(1, 14, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    
    //
    glPushMatrix();
    glColor3d(0.5, 0.5, 0.5);
    glTranslated(-24,1,300);
    glScaled(1, 14, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(0.5, 0.5, 0.5);
    glTranslated(-18,1,300);
    glScaled(1, 14, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(0.5, 0.5, 0.5);
    glTranslated(-12,1,300);
    glScaled(1, 14, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(0.5, 0.5, 0.5);
    glTranslated(-6,1,300);
    glScaled(1, 14, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    //ceiling
    glPushMatrix();
    glColor3d(0.5, 0.5, 0.5);
    glTranslated(0,16,300);
    glScaled(26, 1, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(0.5, 0.5, 0.5);
    glTranslated(12.5,18.5,300);
    glRotated(-10, 0, 0, 1);
    glScaled(13, 1, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(0.5, 0.5, 0.5);
    glTranslated(-12.5,18.5,300);
    glRotated(10, 0, 0, 1);
    glScaled(13, 1, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(0, 0, 0);
    glTranslated(-12.5,18.5,310);
    glScaled(160, 60, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    
}



void stage3(){
    glPushMatrix();
    glPushMatrix();
    glColor3d(236/255.0,199/255.0,88/255.0);
    
    
    glTranslated(0,-1.5,50);
    glScaled(100.0,0.1,100.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(255/255.0,124/255.0,77/255.0);
    
    
    glTranslated(-10,-1.1,40);
    glScaled(8,0.1,70);
    glutSolidCube(1);
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3d(255/255.0,124/255.0,77/255.0);
    
    
    glTranslated(10,-1.1,40);
    glScaled(8,0.1,70);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(236/255.0,199/255.0,88/255.0);
    
    
    
    glTranslated(8,-1,40);
    glScaled(4,0.13,70);
    glutSolidCube(1);
    glPopMatrix();
    
    //Tree
    glPushMatrix();
    glColor3d(65/255.0, 132/255.0, 44/255.0);
    glTranslated(10, 4, 40);
    glScaled(3, 3, 3);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(105/255.0, 65/255.0, 3/255.0);
    glTranslated(10, 0, 40);
    glScaled(0.5, 10, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    
    //Sabar
    glPushMatrix();
    glTranslated(6, -0.2, 5);
    glScaled(0.05, 0.05, 0.05);
    sabar();
    glPopMatrix();
    
    //Sabar
    glPushMatrix();
    glTranslated(6, -0.2, 20);
    glScaled(0.05, 0.05, 0.05);
    sabar();
    glPopMatrix();
    
    //Sabar
    glPushMatrix();
    glTranslated(6, -0.2, 35);
    glScaled(0.05, 0.05, 0.05);
    sabar();
    glPopMatrix();
    
    //Sabar
    glPushMatrix();
    glTranslated(6, -0.2, 50);
    glScaled(0.05, 0.05, 0.05);
    sabar();
    glPopMatrix();
    
    //Sabar
    glPushMatrix();
    glTranslated(6, -0.2, 65);
    glScaled(0.05, 0.05, 0.05);
    sabar();
    glPopMatrix();
    
    //Sabar
    glPushMatrix();
    glTranslated(-7, -0.2, 5);
    glScaled(0.05, 0.05, 0.05);
    sabar();
    glPopMatrix();
    
    //Sabar
    glPushMatrix();
    glTranslated(-7, -0.2, 20);
    glScaled(0.05, 0.05, 0.05);
    sabar();
    glPopMatrix();
    
    //Sabar
    glPushMatrix();
    glTranslated(-7, -0.2, 35);
    glScaled(0.05, 0.05, 0.05);
    sabar();
    glPopMatrix();
    
    //Sabar
    glPushMatrix();
    glTranslated(-7, -0.2, 50);
    glScaled(0.05, 0.05, 0.05);
    sabar();
    glPopMatrix();
    
    //Sabar
    glPushMatrix();
    glTranslated(-7, -0.2, 65);
    glScaled(0.05, 0.05, 0.05);
    sabar();
    glPopMatrix();
    
    
    //Tree
    glPushMatrix();
    glTranslated(0, 0, -15);
    glPushMatrix();
    glColor3d(65/255.0, 132/255.0, 44/255.0);
    glTranslated(10, 4, 40);
    glScaled(3, 3, 3);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(105/255.0, 65/255.0, 3/255.0);
    glTranslated(10, 0, 40);
    glScaled(0.5, 10, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    //Tree
    glPushMatrix();
    glTranslated(-20, 0, -15);
    glPushMatrix();
    glColor3d(65/255.0, 132/255.0, 44/255.0);
    glTranslated(10, 4, 40);
    glScaled(3, 3, 3);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(105/255.0, 65/255.0, 3/255.0);
    glTranslated(10, 0, 40);
    glScaled(0.5, 10, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    
    //Tree
    glPushMatrix();
    glTranslated(-20, 0, 0);
    glPushMatrix();
    glColor3d(65/255.0, 132/255.0, 44/255.0);
    glTranslated(10, 4, 40);
    glScaled(3, 3, 3);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(105/255.0, 65/255.0, 3/255.0);
    glTranslated(10, 0, 40);
    glScaled(0.5, 10, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3d(236/255.0,199/255.0,88/255.0);
    
    glTranslated(-8,-1,40);
    glScaled(4,0.13,70);
    glutSolidCube(1);
    glPopMatrix();
    
    
    //windmill
    glPushMatrix();
    glTranslated(20, 1, 40);
    glColor3d(1, 1, 1);
    //base
    glPushMatrix();
    glScaled(0.5, 10, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    //fins
    glPushMatrix();
    glTranslated(0, 5, -0.5);
    glRotated(rotationWindMill, 0, 0, 1);
    glRotated(45, 0, 0, 1);
    glScaled(4, 0.5, 0.5);
    glutSolidSphere(1, 100, 100);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0, 5, -0.5);
    glRotated(rotationWindMill, 0, 0, 1);
    glRotated(-45, 0, 0, 1);
    glScaled(4, 0.5, 0.5);
    glutSolidSphere(1, 100, 100);
    glPopMatrix();
    
    glPopMatrix();
    
    //windmill
    glPushMatrix();
    glTranslated(20, 1, 20);
    glColor3d(1, 1, 1);
    //base
    glPushMatrix();
    glScaled(0.5, 10, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    //fins
    glPushMatrix();
    glTranslated(0, 5, -0.5);
    glRotated(rotationWindMill, 0, 0, 1);
    glRotated(45, 0, 0, 1);
    glScaled(4, 0.5, 0.5);
    glutSolidSphere(1, 100, 100);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0, 5, -0.5);
    glRotated(rotationWindMill, 0, 0, 1);
    glRotated(-45, 0, 0, 1);
    glScaled(4, 0.5, 0.5);
    glutSolidSphere(1, 100, 100);
    glPopMatrix();
    
    glPopMatrix();
    
    //windmill
    glPushMatrix();
    glTranslated(20, 1, 60);
    glColor3d(1, 1, 1);
    //base
    glPushMatrix();
    glScaled(0.5, 10, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    //fins
    glPushMatrix();
    glTranslated(0, 5, -0.5);
    glRotated(rotationWindMill, 0, 0, 1);
    glRotated(45, 0, 0, 1);
    glScaled(4, 0.5, 0.5);
    glutSolidSphere(1, 100, 100);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0, 5, -0.5);
    glRotated(rotationWindMill, 0, 0, 1);
    glRotated(-45, 0, 0, 1);
    glScaled(4, 0.5, 0.5);
    glutSolidSphere(1, 100, 100);
    glPopMatrix();
    
    glPopMatrix();
    
    //windmill
    glPushMatrix();
    glTranslated(-20, 1, 40);
    glColor3d(1, 1, 1);
    //base
    glPushMatrix();
    glScaled(0.5, 10, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    //fins
    glPushMatrix();
    glTranslated(0, 5, -0.5);
    glRotated(rotationWindMill, 0, 0, 1);
    glRotated(45, 0, 0, 1);
    glScaled(4, 0.5, 0.5);
    glutSolidSphere(1, 100, 100);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0, 5, -0.5);
    glRotated(rotationWindMill, 0, 0, 1);
    glRotated(-45, 0, 0, 1);
    glScaled(4, 0.5, 0.5);
    glutSolidSphere(1, 100, 100);
    glPopMatrix();
    
    glPopMatrix();
    
    //windmill
    glPushMatrix();
    glTranslated(-20, 1, 20);
    glColor3d(1, 1, 1);
    //base
    glPushMatrix();
    glScaled(0.5, 10, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    //fins
    glPushMatrix();
    glTranslated(0, 5, -0.5);
    glRotated(rotationWindMill, 0, 0, 1);
    glRotated(45, 0, 0, 1);
    glScaled(4, 0.5, 0.5);
    glutSolidSphere(1, 100, 100);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0, 5, -0.5);
    glRotated(rotationWindMill, 0, 0, 1);
    glRotated(-45, 0, 0, 1);
    glScaled(4, 0.5, 0.5);
    glutSolidSphere(1, 100, 100);
    glPopMatrix();
    
    glPopMatrix();
    
    //windmill
    glPushMatrix();
    glTranslated(-20, 1, 60);
    glColor3d(1, 1, 1);
    //base
    glPushMatrix();
    glScaled(0.5, 10, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    //fins
    glPushMatrix();
    glTranslated(0, 5, -0.5);
    glRotated(rotationWindMill, 0, 0, 1);
    glRotated(45, 0, 0, 1);
    glScaled(4, 0.5, 0.5);
    glutSolidSphere(1, 100, 100);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0, 5, -0.5);
    glRotated(rotationWindMill, 0, 0, 1);
    glRotated(-45, 0, 0, 1);
    glScaled(4, 0.5, 0.5);
    glutSolidSphere(1, 100, 100);
    glPopMatrix();
    
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3f(74/255.0,44/255.0,68/255.0);
    glTranslated(sphereX,1,50);//radius 4
    glScaled(1,1,1);
    glRotatef(rotateSphere,0,0,1);
    sphere();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(74/255.0,44/255.0,68/255.0);
    glTranslated(-sphereX,1,50);
    glScaled(1,1,1);
    glRotatef(rotateSphere,0,0,1);
    sphere();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslated(0, krabsY, krabsZ);
    mrKrabs();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslated(4, 0, bicycleZ);
    biCycle();
    glPopMatrix();
    
}
void stage2(){
    
    glPushMatrix();
    glColor3d(65/255.0, 132/255.0, 44/255.0);
    
    glTranslated(0.5,-1.2,140);
    //        glRotated(90, 1, 0, 0);
    glScaled(40.0,0.1,100.0);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(255/255.0, 255/255.0, 255/255.0);
    glTranslated(0.5,15,140);
    //        glRotated(90, 1, 0, 0);
    glScaled(40.0,0.1,100.0);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    
    glTranslated(20,-2.5,140);
    glRotated(90, 0, 0, 1);
    glScaled(35.0,0.1,100.0);
    glutSolidCube(1);
    glPopMatrix();
    
    
    glPushMatrix();
    
    glTranslated(-20,-2.5,140);
    glRotated(90, 0, 0, 1);
    glScaled(35.0,0.1,100.0);
    glutSolidCube(1);
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslated(0, -1, 165);
    glRotated(180, 0, 1, 0);
    glPushMatrix();
    drawTable();
    glPopMatrix();
    glPopMatrix();
    
    
    //draw blocks
    glPushMatrix();
    glTranslated(3,-1.4,105);
    glScaled(2,2,1);
    drawBlock();
    glPopMatrix();
    //
    glPushMatrix();
    glTranslated(-3,-1.4,105);
    glScaled(2,2,1);
    drawBlock();
    glPopMatrix();
    //
    glPushMatrix();
    glTranslated(4,-1.4,115);
    glScaled(1,2,1);
    drawBlock();
    glPopMatrix();
    //
    glPushMatrix();
    glTranslated(-3,-1.4,115);
    glScaled(2.5,2,1);
    drawBlock();
    glPopMatrix();
    
    //draw power ups
    // power up stage1
    if(Powerup){
        glPushMatrix();
        glTranslated(4,1,50);
        drawPowerUp();
        glPopMatrix();
    }
    // power up stage2
    if(Powerup){
        glPushMatrix();
        glTranslated(-3,1,150);
        drawPowerUp();
        glPopMatrix();
    }
    // power up stage3
    if(Powerup){
        glPushMatrix();
        glTranslated(0,1,200);
        drawPowerUp();
        glPopMatrix();
    }
    
    
    //draw tv
    glPushMatrix();
    glTranslated(-18, 1, 160);
    tv();
    glPopMatrix();
    glPushMatrix();
    glColor3d(40/255.0, 40/255.0, 40/255.0);
    glTranslated(-17.7, 1, 160);
    glScaled(1, 2, 2);
    glutSolidSphere(0.5, 100, 100);
    glPopMatrix();
    
    //draw tv
    glPushMatrix();
    glColor3d(0/255.0, 0/255.0, 0/255.0);
    glTranslated(18, 1, 160);
    tv();
    glPopMatrix();
    glPushMatrix();
    glTranslated(17.7, 1, 160);
    glColor3d(100/255.0, 100/255.0, 100/255.0);
    glScaled(1, 2, 2);
    glutSolidSphere(0.5, 100, 100);
    glPopMatrix();
    
    
    
    glPushMatrix();
    glColor3d(210/255.0, 151/255.0, 73/255.0);
    glTranslated(-18, -2, 160);
    glScaled(1, 4, 3);
    glutSolidCube(1);
    glPopMatrix();
    
    
    
    
    glPushMatrix();
    glColor3d(210/255.0, 151/255.0, 73/255.0);
    glTranslated(18, -2, 160);
    glScaled(1, 4, 3);
    glutSolidCube(1);
    glPopMatrix();
    
    
    //draw sofa
    glPushMatrix();
    glTranslated(xSofa,0,0);
    glPushMatrix();
    
    glPushMatrix();
    glColor3d(210/255.0, 77/255.0, 60/255.0);
    glTranslated(-12, -2, 160);
    glScaled(1.5, 2, 6);
    glutSolidCube(2);
    glPopMatrix();
    
    
    glPushMatrix();
    
    glPushMatrix();
    glColor3d(210/255.0, 77/255.0, 60/255.0);
    glTranslated(-14, -2, 160);
    glScaled(1, 4, 6);
    glutSolidCube(2);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    
    glPushMatrix();
    glColor3d(210/255.0, 77/255.0, 60/255.0);
    glTranslated(-14, -2, 167);
    glScaled(3, 4, 1);
    glutSolidCube(2);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glColor3d(210/255.0, 77/255.0, 60/255.0);
    glTranslated(-14, -2, 154);
    glScaled(3, 4, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    glPopMatrix();
    glPopMatrix();
    
    //draw sofa
    glPushMatrix();
    glTranslatef(-5,0,0);
    glPushMatrix();
    glTranslatef(-xSofa,0,0);
    glPushMatrix();
    glColor3d(210/255.0, 77/255.0, 60/255.0);
    glTranslated(18, -2, 130);
    glScaled(1.5, 2, 6);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(210/255.0, 77/255.0, 60/255.0);
    glTranslated(20, -2, 130);
    glScaled(1, 4, 6);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(210/255.0, 77/255.0, 60/255.0);
    glTranslated(20, -2, 137);
    glScaled(3, 4, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(210/255.0, 77/255.0, 60/255.0);
    glTranslated(20, -2, 124);
    glScaled(3, 4, 1);
    glutSolidCube(2);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    //draw sofa
    glPushMatrix();
    glTranslatef(-xSofa,0,0);
    glPushMatrix();
    glTranslated(0, 0, 20);
    glPushMatrix();
    glColor3d(210/255.0, 77/255.0, 60/255.0);
    glTranslated(18, -2, 130);
    glScaled(1.5, 2, 6);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(210/255.0, 77/255.0, 60/255.0);
    glTranslated(20, -2, 130);
    glScaled(1, 4, 6);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(210/255.0, 77/255.0, 60/255.0);
    glTranslated(20, -2, 137);
    glScaled(3, 4, 1);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(210/255.0, 77/255.0, 60/255.0);
    glTranslated(20, -2, 124);
    glScaled(3, 4, 1);
    glutSolidCube(2);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();}

void stage1(){
    glPushMatrix();
    car();
    
    glPushMatrix();
    glColor3d(126/255.0,145/255.0,130/255.0);
    
    
    glTranslated(0,-1.5,50);
    glScaled(100.0,0.1,100.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    
    
    
    glPushMatrix();
    glColor3d(255/255.0,255/255.0,255/255.0);
    
    
    glTranslated(-2,-1.48,2);
    glScaled(0.5,0.1,3.0);
    glutSolidCube(1);
    glPopMatrix();
    
    
    glPushMatrix();
    glPushMatrix();
    glColor3d(255/255.0,255/255.0,255/255.0);
    
    
    glTranslated(2,-1.48,2);
    glScaled(0.5,0.1,3.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glPushMatrix();
    glColor3d(255/255.0,255/255.0,255/255.0);
    
    
    glTranslated(2,-1.48,10);
    glScaled(0.5,0.1,3.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    
    glPushMatrix();
    glPushMatrix();
    glColor3d(255/255.0,255/255.0,255/255.0);
    
    
    glTranslated(2,-1.48,18);
    glScaled(0.5,0.1,3.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    
    
    glPushMatrix();
    glPushMatrix();
    glColor3d(255/255.0,255/255.0,255/255.0);
    
    
    glTranslated(2,-1.48,25);
    glScaled(0.5,0.1,3.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    
    glPushMatrix();
    glPushMatrix();
    glColor3d(255/255.0,255/255.0,255/255.0);
    
    
    glTranslated(2,-1.48,33);
    glScaled(0.5,0.1,3.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    
    
    
    glPushMatrix();
    glPushMatrix();
    glColor3d(255/255.0,255/255.0,255/255.0);
    
    
    glTranslated(2,-1.48,40);
    glScaled(0.5,0.1,3.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    
    glPushMatrix();
    glPushMatrix();
    glColor3d(255/255.0,255/255.0,255/255.0);
    
    
    glTranslated(-2,-1.48,10);
    glScaled(0.5,0.1,3.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    
    glPushMatrix();
    glPushMatrix();
    glColor3d(255/255.0,255/255.0,255/255.0);
    
    
    glTranslated(-2,-1.48,18);
    glScaled(0.5,0.1,3.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    
    glPushMatrix();
    glPushMatrix();
    glColor3d(255/255.0,255/255.0,255/255.0);
    
    
    glTranslated(-2,-1.48,25);
    glScaled(0.5,0.1,3.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    
    
    glPushMatrix();
    glPushMatrix();
    glColor3d(255/255.0,255/255.0,255/255.0);
    
    
    glTranslated(-2,-1.48,33);
    glScaled(0.5,0.1,3.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    
    glPushMatrix();
    glPushMatrix();
    glColor3d(255/255.0,255/255.0,255/255.0);
    
    
    glTranslated(-2,-1.48,40);
    glScaled(0.5,0.1,3.0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    
    
    
    glPushMatrix();
    glColor3d(224/255.0,236/255.0,230/255.0);
    
    
    glTranslated(-10,-1.1,25);
    glScaled(8,0.1,50);
    glutSolidCube(1);
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3d(224/255.0,236/255.0,230/255.0);
    
    
    glTranslated(10,-1.1,25);
    glScaled(8,0.1,50);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(62/255.0,187/255.0,39/255.0);
    
    
    
    
    glTranslated(8,-1,25);
    glScaled(4,0.13,40);
    glutSolidCube(1);
    glPopMatrix();
    
    //Motorcycle
    glPushMatrix();
    glTranslated(jellyY,jellyX,40);
    motorCycle();
    glPopMatrix();
    
    //Bus
    glPushMatrix();
    glTranslated(busX, 0, busZ);
    bus();
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(62/255.0,187/255.0,39/255.0);
    
    
    glTranslated(-8,-1,25);
    glScaled(4,0.13,40);
    glutSolidCube(1);
    glPopMatrix();
    
    //Building
    glPushMatrix();
    glColor3d(140/255.0, 108/255.0, 66/255.0);
    glTranslated(20, 1, 40);
    glScaled(2, 12, 2);
    glutSolidCube(2);
    glPopMatrix();
    
    //Building
    glPushMatrix();
    glColor3d(140/255.0, 108/255.0, 66/255.0);
    glTranslated(20, 1, 50);
    glScaled(2, 14, 2);
    glutSolidCube(2);
    glPopMatrix();
    
    //Building
    glPushMatrix();
    glColor3d(140/255.0, 108/255.0, 66/255.0);
    glTranslated(20, 1, 30);
    glScaled(2, 16, 2);
    glutSolidCube(2);
    glPopMatrix();
    
    //Building
    glPushMatrix();
    glColor3d(140/255.0, 108/255.0, 66/255.0);
    glTranslated(20, 1, 20);
    glScaled(2, 10, 2);
    glutSolidCube(2);
    glPopMatrix();
    
    //Building
    glPushMatrix();
    glColor3d(140/255.0, 108/255.0, 66/255.0);
    glTranslated(-20, 1, 40);
    glScaled(2, 12, 2);
    glutSolidCube(2);
    glPopMatrix();
    
    //Building
    glPushMatrix();
    glColor3d(140/255.0, 108/255.0, 66/255.0);
    glTranslated(-20, 1, 50);
    glScaled(2, 14, 2);
    glutSolidCube(2);
    glPopMatrix();
    
    //Building
    glPushMatrix();
    glColor3d(140/255.0, 108/255.0, 66/255.0);
    glTranslated(-20, 1, 30);
    glScaled(2, 16, 2);
    glutSolidCube(2);
    glPopMatrix();
    
    //Building
    glPushMatrix();
    glColor3d(140/255.0, 108/255.0, 66/255.0);
    glTranslated(-20, 1, 20);
    glScaled(2, 10, 2);
    glutSolidCube(2);
    glPopMatrix();
    
    //Building
    glPushMatrix();
    glColor3d(140/255.0, 108/255.0, 66/255.0);
    glTranslated(20, 1, 70);
    glScaled(2, 16, 2);
    glutSolidCube(2);
    glPopMatrix();
    
    //Building
    glPushMatrix();
    glColor3d(140/255.0, 108/255.0, 66/255.0);
    glTranslated(20, 1, 60);
    glScaled(2, 10, 2);
    glutSolidCube(2);
    glPopMatrix();
    
    //Building
    glPushMatrix();
    glColor3d(140/255.0, 108/255.0, 66/255.0);
    glTranslated(-20, 1, 60);
    glScaled(2, 12, 2);
    glutSolidCube(2);
    glPopMatrix();
    
    //Building
    glPushMatrix();
    glColor3d(140/255.0, 108/255.0, 66/255.0);
    glTranslated(-20, 1, 70);
    glScaled(2, 14, 2);
    glutSolidCube(2);
    glPopMatrix();
    
    //Building
    glPushMatrix();
    glColor3d(140/255.0, 108/255.0, 66/255.0);
    glTranslated(20, 1, 80);
    glScaled(2, 10, 2);
    glutSolidCube(2);
    glPopMatrix();
    
    //Building
    glPushMatrix();
    glColor3d(140/255.0, 108/255.0, 66/255.0);
    glTranslated(-20, 1, 80);
    glScaled(2, 12, 2);
    glutSolidCube(2);
    glPopMatrix();
    
}


// void SetupLights()
// {
//     GLfloat mat_ambient[] = {0.7f, 0.7f, 0.7, 1.0f};
//     GLfloat mat_diffuse[] = {0.6f, 0.6f, 0.6, 1.0f};
//     GLfloat mat_specular[] = {1.0f, 1.0f, 1.0, 1.0f};
//     GLfloat mat_shininess[] = {50};
//     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
//     glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
//     glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//     glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//     //set the light source properties
//     GLfloat lightIntensity[] = {0.7f, 0.7f, 1, 1.0f};
//     GLfloat light_position[] = {-7.0f, 6.0f, 3.0f, 0.0f};
//     glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
//     glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
// }




void Display(void)
{
    
    //start drawing
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Setup light
    SetupLights();
    //set the camera
    SetupCamera();
    
    
    
    
    glPushMatrix();
    
    glTranslated(xPepsiMan, 0, zPepsiMan);
    glPushMatrix();
    drawAladdin();
    glPopMatrix();
    glPopMatrix();
    
    
    
    //      loadBMP(&texID, "/textures/metal.bmp", 500, 600, true);
    //    glPushMatrix();
    //    glBindTexture(GL_TEXTURE_2D, texID);
    ////    glRotatef(-90, 1, 0, 0);
    //    GLUquadricObj* sphere = gluNewQuadric();
    //    gluQuadricTexture(sphere, true);
    //    gluQuadricNormals(sphere, GLU_SMOOTH);
    //    gluSphere(sphere, 3, 3, 3);
    //    gluDeleteQuadric(sphere);
    //    glPopMatrix();
    
    glPushMatrix();
    stage1();
    glPopMatrix();
    
    glPushMatrix();
    stage2();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0, 0, 190);
    stage3();
    glPopMatrix();
    
    glPushMatrix();
    finale();
    glPopMatrix();
    
    if(Won){
        glPushMatrix();
        
        glColor3f(1,0.3,0.0);
        glRotatef(180,0,0,1);
        glLineWidth(5);
        drawStrokeText("YOU" "WON! ",0,-10,285);
        glPopMatrix();
    }
    if(Lost){
        glPushMatrix();
        
        glColor3f(1,0.3,0.0);
        glRotatef(180,0,0,1);
        glLineWidth(5);
        drawStrokeText("YOU" "LOST! ",-1,-10,10);
        glPopMatrix();
    }
    glutSwapBuffers();
}


void Keyboard(unsigned char key, int x, int y) {
    
    float d = 0.1;
    
    switch (key) {
        case 'p':
            
            sideBool=false;
            break;
        case 'y':
            sideBool =true;
            break;
        case 'n':{
            if(SceneMotion){
                SceneMotion=false;
            }else{
                SceneMotion =true;
            }
        }
        case 'w':{
            if (GaryMotion) {
                
                
                GaryMotion=false;
            }else{
                GaryMotion=true;
            }
            break;
        }
        case 's':{
            if (JellyFishMotion) {
                
                
                JellyFishMotion=false;
            }else{
                JellyFishMotion=true;
            }
            break;
        }
        case 'a':{
            
            rotate = !rotate;
            
            break;
        }
        case 'd':{
            if (SheldonMotion) {
                
                
                SheldonMotion=false;
            }else{
                SheldonMotion=true;
            }
            break;
        }
        case 'q':{
            if (KrabsMotion) {
                
                
                KrabsMotion=false;
            }else{
                KrabsMotion=true;
            }
            break;
        }
        case 'e':{
            if (PatrickMotion) {
                
                
                PatrickMotion=false;
            }else{
                PatrickMotion=true;
            }
            break;
        }        case 27:
            exit(EXIT_SUCCESS);
    }
    
    glutPostRedisplay();
}

void SpecialKeys(int key, int xx, int yy)
{
    
    float radius = 6.0f;
    
    switch (key)
    {
        case GLUT_KEY_LEFT:
        {
            
            xPepsiMan++;
            break;
        }
            
        case GLUT_KEY_RIGHT:{
            xPepsiMan--;
            
            break;
        }
            
    }
    
    // ask OpenGL to recall the display function to reflect the changes on the window
    glutPostRedisplay();
}



int main(int argc, char **argv)
{
    // Initialization
    glutInit(&argc, argv);
    
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(2000, 1000);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("PepsiMan");
    
    // glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearColor(97/255.0, 145/255.0, 222.0/255.0, 0.0f);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    
    
    // Calbacks
    glutDisplayFunc(Display);
    glutIdleFunc(Animate);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(SpecialKeys);
    glutReshapeFunc(Reshape);
    
    // loadBMP(&texID, "textures/metal.bmp", true);
    //    glutSpecialFunc(SpecialKeys);
    
    glutMainLoop();
    
    return 0;
}
