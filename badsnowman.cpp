#include "badsnowman.h"
#include "gameobject.h"
#include "cmesh.h"




#include <iostream>
badSnowman::badSnowman()
{
 m_name = "smok";
}


void badSnowman::init()
{
     m_mesh = CMesh::m_meshes["badSnowman"];
}

void badSnowman::render(GLWidget* glwidget)
{
    m_mesh->render(glwidget);
}

void badSnowman::update()
{
    // wykorzystanie energii.
    position = position + energy;
    int flagr=0;
    int flagrr=0;
    unsigned int r;
    unsigned int rr;
    if (flagr==0){
          r = rand() % 2;
    }
    if (flagrr==0){
           rr = rand() % 2;
    }

    if (r==1){
         int x = rand() % 9122412232;
         if(x==30){
              flagr++;
         }

        if(flagr>1000000000){
            flagr=0;
        }
         energy.setX(energy.x() + 0.01);
         energy.setY(energy.y() + 0.0001);
    }else{
        int x = rand() % 122412232;
        if(x==30){
             flagr++;
        }
        if(flagr>1000000000){
            flagr=0;
        }
        energy.setX(energy.x() - 0.01);
        energy.setY(energy.y() - 0.0001);
    }
   if (rr==1){
       int x = rand() % 522412232;
       if(x==30){
             flagrr++;
       }
       if(flagrr>1000){
           flagrr=0;
       }
         energy.setY(energy.y() + 0.0001);
       energy.setZ(energy.z() + 0.01);}
   else{
       int x = rand() % 822412232;
       if(x==30){
             flagrr++;
       }
       if(flagrr>1000){
           flagrr=0;
       }
       energy.setZ(energy.z() - 0.01);
         energy.setY(energy.y() - 0.0001);
   }

   // position =position + 1.2f;
    // wytracanie energii.
     energy = energy / 1.2f;
      // energy = energy / 1.1f;



}

void badSnowman::shadow(GLWidget* glwidget)
{

}





