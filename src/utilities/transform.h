
typedef struct transform {
  float    pos[3];                /* current mouse position */
  float    angle,axis[3];         /* rotation angle + axis  */
  float    panx,pany,opanx,opany; /* screen translation     */
  float    matrix[16],oldmat[16]; /* transformation matrix  */
  float    rot[16],tra[16];
  int      mstate,mbutton,manim;
} Transform;

typedef Transform * pTransform;

/* transform.c */
void   resetTransform(pTransform );
Transform *createTransform();
void   transformPoint(double u[4],float v[4],float m[16]);
void   transformPointd(double u[4],double v[4],double m[16]);
void   transformPoint2(double u[4],float v[4],float m[16]);
void   transformVector(float u[4],float v[4],float m[16]); 

