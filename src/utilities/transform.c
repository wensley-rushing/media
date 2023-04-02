#include "medit.h"
#include "extern.h"
#include "sproto.h"


void resetTransform(Transform *tr) {
  static float  itransf[16] = { 1., 0., 0., 0.,  0., 1., 0., 0.,
				0., 0., 1., 0.,  0., 0., 0., 1.};

  tr->pos[0] = tr->pos[1] = tr->pos[2] = 0.0f;
  tr->angle  = 0.0f;
  tr->panx   = tr->pany  = 0.0f;
  tr->opanx  = tr->opany = 0.0f;
  tr->mstate = 1;  
  tr->manim  = GL_FALSE;

  memcpy(tr->matrix, itransf,16*sizeof(float));
  memcpy(tr->rot, itransf,16*sizeof(float));
  memcpy(tr->tra, itransf,16*sizeof(float));
}

Transform *createTransform() {
  Transform   *tr;

  /* default */
  if ( ddebug) printf("create transformation\n");

  tr = (Transform*)M_calloc(1,sizeof(struct transform),"transform") ;
  assert(tr);

  /* set default values */
  resetTransform(tr);
  tr->mbutton = 0;

  return(tr);
}

/* transform: u = MxV */
void transformPoint(double u[4],float v[4],float m[16]) {
  u[0] = v[0] * m[0]  + v[1] * m[1]  + v[2] * m[2]  + v[3] * m[3];
  u[1] = v[0] * m[4]  + v[1] * m[5]  + v[2] * m[6]  + v[3] * m[7];
  u[2] = v[0] * m[8]  + v[1] * m[9]  + v[2] * m[10] + v[3] * m[11];
  u[3] = v[0] * m[12] + v[1] * m[13] + v[2] * m[14] + v[3] * m[15];
}

void transformPoint2(double u[4],float v[4],float m[16]) {
  u[0] = v[0] * m[0] + v[1] * m[4] + v[2] * m[8]  + v[3] * m[12];
  u[1] = v[0] * m[1] + v[1] * m[5] + v[2] * m[9]  + v[3] * m[13];
  u[2] = v[0] * m[2] + v[1] * m[6] + v[2] * m[10] + v[3] * m[14];
  u[3] = v[0] * m[3] + v[1] * m[7] + v[2] * m[11] + v[3] * m[15];
}

void transformPointd(double u[3],double v[3],double m[16]) {
  u[0] = v[0] * m[0]  + v[1] * m[1]  + v[2] * m[2];
  u[1] = v[0] * m[4]  + v[1] * m[5]  + v[2] * m[6];
  u[2] = v[0] * m[8]  + v[1] * m[9]  + v[2] * m[10];
}

void transformVector(float u[4],float v[4],float m[16]) {
  u[0] = v[0] * m[0] + v[1] * m[4] + v[2] * m[8];
  u[1] = v[0] * m[1] + v[1] * m[5] + v[2] * m[9];
  u[2] = v[0] * m[2] + v[1] * m[6] + v[2] * m[10];
  u[3] = v[0] * m[3] + v[1] * m[7] + v[2] * m[11];
}

