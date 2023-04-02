
/* gisfil.c */
int    loadGIS(Mesh*);

/* input/output */
int    inmsh2(Mesh*mesh);
int    bbfile(Mesh*);
int    loadMesh(Mesh*);
int    loadSol(Mesh*mesh,char *filename,int numsol);
int    saveMesh(pScene ,Mesh*,char *,ubyte );

/* psfile.c */
void writeEPSheader(FILE *,char *,char ,int ,int ,float ,float);
void writeEPStrailer(FILE *);
void writeEPSRow(FILE *,char ,ubyte *,int ,ubyte );

