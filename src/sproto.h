/* animat.c */
int    loadNextMesh(Mesh*,int ,int ,int );
int    animat();
int    playAnim(pScene ,Mesh*,int ,int );
void   glutIdle(void);

/* camera.c */
double  Azimuth(Camera*);
double  Elevation(Camera*);
void    updateSun(Scene*, Camera*);
void    updateCamera(Scene* , Camera*, double, double);
Camera *initCamera(Scene* , int);

/* clip.c */
void   updateClip(pClip ,Mesh*);
void   clipVertices(Mesh*,pScene ,pClip );
void   invertClip(pScene sc,pClip );
void   drawClip(pScene ,pClip ,Mesh*,GLboolean );
void   copyClip(pClip );
int    pasteClip(pClip );
void   resetClip(pScene ,pClip ,Mesh*);
Clip  *createClip(pScene ,Mesh*);

/* clipvol.c */
GLuint capTetra(Mesh*);
GLuint capTetraMap(Mesh*);
GLuint capTetraIso(Mesh*);

/* critip.c */
GLuint listCritPoint(pScene ,Mesh*);


/* geometry.c */
GLuint geomList(pScene ,Mesh*);

/* dlists.c */
GLuint  listTria(pScene ,Mesh*);
GLuint  listQuad(pScene ,Mesh*);
GLuint  listTetra(pScene ,Mesh*,ubyte );
GLuint  listHexa(pScene ,Mesh*,ubyte );

/* ilists.c */
GLuint listTriaIso( Scene *, Mesh*);
GLuint listTriaIso2(Scene *, Mesh*);
GLuint listQuadIso( Scene *, Mesh*);
GLuint listTetraIso(Scene *, Mesh*);


/* ellipse.c */
void drawEllipse(pScene sc, Mesh*mesh,int typel,int k);
void drawEllipsoid(pScene sc, Mesh*mesh,int typel,int k);
GLuint drawAllEllipse(pScene sc, Mesh*mesh);


void   updateCube(pCube ,Mesh*);
Cube  *createCube(pScene ,Mesh*);



/* items.c */
void   drawAxis(pScene ,int );
void   drawBox(pScene ,Mesh*,int );
void   drawCube(pScene ,Mesh*);
void   drawGrid(pScene ,Mesh*);
void   rubberBand(pPersp );
void   drawBase(pScene ,Mesh*);
void   drawIso(pScene );

/* keyboard.c */
void   specCamera(pScene ,int );
void   special(int ,int ,int );
void   keyScene(unsigned char ,int ,int );

/* listnum.c */
void   updatePoints(pScene sc, Mesh*mesh,int refmat);
void   listNum(pScene sc, Mesh*mesh);

/* material.c */
void   matInit(pScene );
void   matSort(pScene );
int    matRef(pScene ,int );
void   matReshape(int ,int );
void   matsubReshape(int ,int );
void   matsubDisplay();
void   matDisplay();
void   matMouse(int ,int ,int ,int );
void   matKeyboard(unsigned char ,int ,int );
void   matEdit(pScene );

/* menus.c */
int    createMenus(pScene ,Mesh*);
void   doIsoLists(pScene ,Mesh*,int );
void   doLists(pScene ,Mesh*);
void   doMapLists(pScene ,Mesh*,int );
void   keyAnim(unsigned char ,int ,int );
void   keyClip(unsigned char ,int ,int );
void   keyColor(unsigned char ,int ,int );
void   keyFeature(unsigned char ,int ,int );
void   keyFile(unsigned char ,int ,int );
void   keyItem(unsigned char ,int ,int );
void   keyMetric(unsigned char key,int x,int y);
void   keyMode(unsigned char ,int ,int );
void   keyTrajet(unsigned char ,int ,int );
void   keyView(unsigned char ,int ,int );
void   menuAnim(int );
void   menuClip(int );
void   menuColor(int );
void   menuFeature(int );
void   menuFile(int );
void   menuImage(int );
void   menuItem(int );
void   menuMode(int );
void   menuScene(int ); 
void   menuTrajet(int );
void   menuView(int );
 
/* mlists.c */
GLuint  listTriaMap(pScene ,Mesh*);
GLuint  listQuadMap(pScene ,Mesh*);
GLuint  listTetraMap(pScene ,Mesh*,ubyte );
GLuint  listHexaMap(pScene ,Mesh*,ubyte );
void    cutTriangle(pScene ,triangle );
GLuint  alt2dList(pScene ,Mesh*,int ,float ,float );
void    setupPalette(pScene ,Mesh*);
GLuint  drawPalette(pScene );

/* morphing */
int    morphMesh(pScene sc, Mesh*mesh1);
int    modeMorphing();
 
/* mouse.c */
void   mouse(int button,int state,int x,int y);
void   motion(int x,int y);
void   redrawOverlay(int stretchX,int stretchY);
void   motionCamera(int x,int y);
void   mouseCamera(int button,int state,int x,int y);
void   animateCamera();

/* normal.c */
GLuint drawNormals(Mesh*mesh,pScene sc);


/* parsop.c */
int    saveMeditFile(char *,pScene ); 
void   iniopt(pScene ,Mesh*);
int    parsop(pScene ,Mesh*);

/* particle.c */
int    createParticle(pScene ,Mesh*);
int    advectParticle(pScene sc, Mesh*mesh);
int    animParticle(pScene sc, Mesh*mesh);
int    displayParticle(pScene sc, Mesh*mesh);

/* path.c */
int    pathAdd(Scene*,int, int);
GLuint pathList(Scene*);
int    pathLoad(char *data, Scene*);
int    pathSave(char *file, Scene*);
void   pathFollow(Scene *);

/* persp.c */
void   setPersp(pScene ,pPersp ,int );
pPersp initPersp(pPersp ,float );

/* picking.c */
GLuint pickingList(pScene ,int ,int );
GLuint pickingPoint(pScene sc,int x,int y);
GLuint pickItem(Mesh*,pScene ,int );
GLuint pickingScene(pScene sc,int x,int y,int ident);
 
/* prierr.c */
void   prierr(int typerr,int indice);

/* scene.c */
int    currentScene();
void   checkErrors(void);
void   oglerr(GLenum error);
void   farclip(GLboolean );
void   reshapeScene(int width, int height);
void   setupView(Scene *sc);
void   drawBackTex(Scene *sc);
void   drawModel(Scene *sc);  
void   drawScene(Scene *);
void   redrawScene();
void   deleteScene(Scene *sc);
void   initGrafix(Scene *sc, Mesh*);
int    createScene(Scene *sc,int idmesh);
void   streamIdle();

/* scissor.c */
void   scissorScene();

/* status.c */
void reshapeStatusBar(pScene sc,int width,int height);
void redrawStatusBar(pScene sc);
void mouseStatus(int button,int state,int x,int y);

/* stream.c */
int     nxtPoint3D(Mesh*mesh,int nsdep,double *p,double step,double *v);
int     locateTria(Mesh*mesh,int nsdep,double *p,double *cb);
int     locateTetra(Mesh*mesh,int nsdep,double *p,double *cb);
int     inTria(Mesh*,int ,double *,double *);
int     inTetra(Mesh*mesh,int nsdep,double *p,double *cb);
int     listTetraStream(pScene ,Mesh*,float *,int ,double *,char );
int     listHexaStream(pScene ,Mesh*,float *,int );
int     listTriaStream(pScene ,Mesh*,float *,int );
pStream createStream(pScene ,Mesh*);
int     streamRefTria(pScene sc, Mesh*mesh);
int     streamRefQuad(pScene sc, Mesh*mesh);
int     streamRefPoint(pScene sc, Mesh*mesh);
int     streamIsoPoint(pScene sc, Mesh*mesh);
int     listSaddleStream(pScene sc, Mesh*mesh,int depart,float *pp,float *vv,double lambda);
double  field2DInterp(Mesh*, int iel, double *cb, double *v);
double  field3DInterp(Mesh*, int iel, double *cb, double *v);
double  vector3DInterp(Mesh*mesh,pPoint pt[4],double *cb,double *v);

/* tensor.c */
GLuint listPointVector(Mesh*,ubyte );

/* texture.c */
// pPPMimage texDistortion(pPPMimage );

/* tiles.c */
int   imgTiling(pScene sc,char *data,char key);


/* util.c */
void   setFont(char* name, int size);
void   drwstr(GLuint x,GLuint y,char* format, ...);
void   output2(GLfloat x,GLfloat y,char *format,...); 
void   output3(GLfloat x,GLfloat y,GLfloat z,char *format,...);
void   hsvrgb(double *hsv,double *rgb);
int    filnum(char *data,int numdep,char *ext);
void   multMatrix(GLfloat *p,GLfloat *a,GLfloat *b);
void   rotateMatrix(GLfloat angle,GLfloat x,GLfloat y,GLfloat z,GLfloat rm[16]);
int    invertMatrix(float src[16],float inverse[16]);

/* vector.c */
void   drawVector2D(float p[2],double u[2],double scal);
void   drawVector3D(float p[3],double u[3],double scal);
GLuint listTria2dVector(Mesh*mesh);
GLuint listTria3dVector(Mesh*mesh);
GLuint listClipTetraVector(Mesh *mesh);
GLuint listClipHexaVector(Mesh *mesh);

/* view.c */
void   copyView(pTransform view, pCamera cam, pPersp persp);
int    pasteView(pTransform view, pCamera cam, pPersp persp);
int    linkView(pScene sc1);
void   unlinkView(pScene sc1);

//
double  sizeTetra(Mesh*,int );
double  sizeHexa(Mesh*,int );
double  sizeTria(Mesh*,int );
// double  sizeTria(Mesh*mesh,int k);
double  sizeQuad(Mesh*mesh,int k);
double  sizeTetra(Mesh*mesh,int k);
//
void   keyCube(unsigned char key,int x,int y);
void   dumpCube(pScene sc, Mesh*mesh,pCube cube);
void   resetCube(pScene sc,pCube cube,Mesh*mesh);
void   tiltClip(pScene sc,pClip clip);
void   parEdit(pScene sc);
int    tetraIsoPOVray(pScene sc, Mesh*mesh);
GLuint listQuad2dVector(Mesh*mesh);
int    sftcpy(pScene sc, Mesh*mesh);
void   circumSphere(pScene sc, Mesh*mesh,int typel,int k);
GLuint drawAllEllipse(pScene sc, Mesh*mesh);
void   drawEllipsoid(pScene sc, Mesh*mesh,int typel,int k);

/* utilities */
int    cenrad(Mesh*mesh,int iel,double *c,double *rad);
