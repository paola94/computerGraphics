///////////////////////////////////////////////////////////////////
//  A basic skeleton for 2D like game developpers.
//
//  model data
///////////////////////////////////////////////////////////////////

#include <windows.h>		// Header File For Windows
#include <stdio.h>			// Header File For Standard Input/Output
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library

#include "Model.h"
#include "SOIL.h"

// All Setup For OpenGL Goes Here
bool MyModel::InitGL(void)
{
	if (!this->LoadGLTextures())				// Jump To Texture Loading Routine
  {	return false; }							// If Texture Didn't Load Return FALSE


	glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping ( NEW )
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
  this->BuildFont();

  // eye    (0,0,0)
  // center (0,0,-1)
  // up     (0,1,0)
  gluLookAt(0.0,0.0,0.0, 0.0,0.0,-1.0, 0.0,1.0,0.0);

  return true;										// Initialization Went OK
}


void MyModel::ReSizeGLScene(int width, int height)
{
	if (height==0) height=1;					// Prevent A Divide By Zero By
	if (width==0) width=1;					// Prevent A Divide By Zero By

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// orthographic projection
  // background in [-1, 1] on both x and y
  // fill th background according to the window aspect ratio
  // void WINAPI glOrtho( GLdouble left,   GLdouble right,
  //                      GLdouble bottom, GLdouble top,
  //                      GLdouble zNear,  GLdouble zFar );
  if( width >= height ) {
    this->plx = 1.0;
    //this->ply = (double) height /(double) width;
	this->ply = 1.0;
  } else {
    //this->plx = (double) width /(double) height;
	  this->plx= 1.0;
    this->ply = 1.0;
  }
  glOrtho(-this->plx, this->plx, -this->ply, this->ply, 1, 5.1);
  
  //  saving the window width and height in pixels
  this->Wheight = height;
  this->Wwidth = width;

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}



// Load Bitmaps And Convert To Textures
bool MyModel::LoadGLTextures(void)
{
	/* load an image file directly as a new OpenGL texture */
	texture[0] = SOIL_load_OGL_texture
	("../Data/background.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[0] == 0) return false;

	texture[1] = SOIL_load_OGL_texture
	("../Data/tessera1.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[1] == 0) return false;

	texture[2] = SOIL_load_OGL_texture
	("../Data/tessera2.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[2] == 0) return false;

	texture[3] = SOIL_load_OGL_texture
	("../Data/tessera3.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[3] == 0) return false;

	texture[4] = SOIL_load_OGL_texture
	("../Data/tessera4.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[4] == 0) return false;

	texture[5] = SOIL_load_OGL_texture
	("../Data/tessera5.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[5] == 0) return false;

	texture[6] = SOIL_load_OGL_texture
	("../Data/tessera6.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[6] == 0) return false;

	texture[7] = SOIL_load_OGL_texture
	("../Data/tessera7.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[7] == 0) return false;

	texture[8] = SOIL_load_OGL_texture
	("../Data/tessera8.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[8] == 0) return false;

	texture[9] = SOIL_load_OGL_texture
	("../Data/tessera9.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[9] == 0) return false;

	texture[10] = SOIL_load_OGL_texture
	("../Data/tessera10.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[10] == 0) return false;

	texture[11] = SOIL_load_OGL_texture
	("../Data/tessera11.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[11] == 0) return false;

	texture[12] = SOIL_load_OGL_texture
	("../Data/tessera12.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[12] == 0) return false;

	texture[43] = SOIL_load_OGL_texture
	("../Data/bordoverde.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[43] == 0) return false;

	texture[44] = SOIL_load_OGL_texture
	("../Data/selezione.png",
		SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture[44] == 0) return false;



	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	return true;										// Return Success
}



bool MyModel::DrawGLScene(void)
{
  

  //  TIMING - start
  clock_t t = clock();
  // elapsed time in seconds from the last draw
  double elapsed = double (t - Tstamp) /  (double)CLOCKS_PER_SEC;
  // elapsed time in milliseconds from the last draw
  int ms_elapsed = (int) (t - Tstamp);
  if (ms_elapsed < 0.01) {
	  return true;
  }
  // elapsed time in seconds from the beginning of the program
  this->Full_elapsed = double (t - Tstart) /  (double) CLOCKS_PER_SEC;
  this->frameTime += double (t - Tstamp) /  (double) CLOCKS_PER_SEC;

  this->Tstamp = t;
  //  TIMING - end
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
  glMatrixMode(GL_MODELVIEW);				// Select The Modelview Matrix
  glLoadIdentity();									// Reset The View
  
  glBindTexture(GL_TEXTURE_2D, texture[0]);

  //  Background
  glBegin(GL_QUADS);
  for(int i = 0; i < 4; i++) {
		glTexCoord2f(Background[i].u, Background[i].v);
    glVertex3f(Background[i].x, Background[i].y,  Background[i].z);
  }
  glEnd();

  double px, py;
  for (int i = N_COLONNE - 1; i >= 0; i--) {
	  for (int j = N_RIGHE - 1; j >= 0; j--) {
		  if (system.getTesseraMatrice(i, j)->isEsisto()) {
			  glBindTexture(GL_TEXTURE_2D, texture[1 + system.getTesseraMatrice(i, j)->getImg()]);
			  glMatrixMode(GL_MODELVIEW);        // Select The Modelview Matrix
			  glLoadIdentity();                  // Reset The View

			  //glTranslatef(system.getTesseraMatrice(i, j)->getX(), system.getTesseraMatrice(i, j)->getY(), 0);
			  glTranslatef((float)i / 14 - ((0.28*(N_RIGHE - 1)) / 7), (float)j / 7.5 - ((0.5*(N_RIGHE - 1)) / 7), 0);
			  glScalef(0.05f, 0.095f, 1);    // 1- scale the fire
			  system.getTesseraMatrice(i, j)->setX(i / 14.0 - ((0.28*(N_RIGHE - 1)) / 7));
			  system.getTesseraMatrice(i, j)->setY((float)j / 7.5 - ((0.5*(N_RIGHE - 1)) / 7));
			  glEnable(GL_BLEND);
			  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			  glEnable(GL_ALPHA_TEST);
			  glAlphaFunc(GL_GREATER, 0);
			  glBegin(GL_QUADS);
			  for (int k = 0; k < 4; k++) {
				  glTexCoord2f(fire[k].u, fire[k].v);
				  glVertex3f(fire[k].x, fire[k].y, fire[k].z);
			  }
			  glEnd();
			  if (system.getTesseraMatrice(i, j)->isSelezionata()) {
				  glBindTexture(GL_TEXTURE_2D, texture[44]);
				  glMatrixMode(GL_MODELVIEW);        // Select The Modelview Matrix
				  glLoadIdentity();                  // Reset The View

				  //glTranslatef(system.getTesseraMatrice(i, j)->getX(), system.getTesseraMatrice(i, j)->getY(), 0);
				  glTranslatef(system.getTesseraMatrice(i, j)->getX(), system.getTesseraMatrice(i, j)->getY(), 0);
				  glScalef(0.05f, 0.095f, 1);    // 1- scale the fire
				  glEnable(GL_BLEND);
				  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				  glEnable(GL_ALPHA_TEST);
				  glAlphaFunc(GL_GREATER, 0);
				  glBegin(GL_QUADS);
				  for (int k = 0; k < 4; k++) {
					  glTexCoord2f(fire[k].u, fire[k].v);
					  glVertex3f(fire[k].x, fire[k].y, fire[k].z);
				  }
				  glEnd();
			  }
			  else {
				  glBindTexture(GL_TEXTURE_2D, texture[1 + system.getTesseraMatrice(i, j)->getImg()]);
				  glMatrixMode(GL_MODELVIEW);        // Select The Modelview Matrix
				  glLoadIdentity();                  // Reset The View

				  //glTranslatef(system.getTesseraMatrice(i, j)->getX(), system.getTesseraMatrice(i, j)->getY(), 0);
				  glTranslatef(system.getTesseraMatrice(i, j)->getX(), system.getTesseraMatrice(i, j)->getY(), 0);
				  glScalef(0.05f, 0.095f, 1);    // 1- scale the fire
				  glEnable(GL_BLEND);
				  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				  glEnable(GL_ALPHA_TEST);
				  glAlphaFunc(GL_GREATER, 0);
				  glBegin(GL_QUADS);
				  for (int k = 0; k < 4; k++) {
					  glTexCoord2f(fire[k].u, fire[k].v);
					  glVertex3f(fire[k].x, fire[k].y, fire[k].z);
				  }
				  glEnd();
			  }
		  }
	  }
  }
  for (int i = N_COLONNE -1; i >= 0; i--) {
	  for (int j = N_RIGHE -1; j >= 0; j--) {
		  if (system.getTesseraMatrice2(i, j)->isEsisto()) {
			  glBindTexture(GL_TEXTURE_2D, texture[1 + system.getTesseraMatrice2(i, j)->getImg()]);
			  glMatrixMode(GL_MODELVIEW);        // Select The Modelview Matrix
			  glLoadIdentity();                  // Reset The View

			  //glTranslatef(system.getTesseraMatrice(i, j)->getX(), system.getTesseraMatrice(i, j)->getY(), 0);
			  glTranslatef((float)i / 14 - ((0.273*(N_RIGHE - 1)) / 7), (float)j / 7.5 - ((0.485*(N_RIGHE - 1)) / 7), 0);
			  glScalef(0.05f, 0.095f, 1);    // 1- scale the fire
			  system.getTesseraMatrice2(i, j)->setX(i / 14.0 - ((0.273*(N_RIGHE - 1)) / 7));
			  system.getTesseraMatrice2(i, j)->setY((float)j / 7.5 - ((0.485*(N_RIGHE - 1)) / 7));
			  glEnable(GL_BLEND);
			  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			  glEnable(GL_ALPHA_TEST);
			  glAlphaFunc(GL_GREATER, 0);
			  glBegin(GL_QUADS);
			  for (int k = 0; k < 4; k++) {
				  glTexCoord2f(fire[k].u, fire[k].v);
				  glVertex3f(fire[k].x, fire[k].y, fire[k].z);
			  }
			  glEnd();
			  if (system.getTesseraMatrice2(i, j)->isSelezionata()) {
				  glBindTexture(GL_TEXTURE_2D, texture[44]);
				  glMatrixMode(GL_MODELVIEW);        // Select The Modelview Matrix
				  glLoadIdentity();                  // Reset The View

				  //glTranslatef(system.getTesseraMatrice(i, j)->getX(), system.getTesseraMatrice(i, j)->getY(), 0);
				  glTranslatef(system.getTesseraMatrice2(i, j)->getX(), system.getTesseraMatrice2(i, j)->getY(), 0);
				  glScalef(0.05f, 0.095f, 1);    // 1- scale the fire
				  glEnable(GL_BLEND);
				  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				  glEnable(GL_ALPHA_TEST);
				  glAlphaFunc(GL_GREATER, 0);
				  glBegin(GL_QUADS);
				  for (int k = 0; k < 4; k++) {
					  glTexCoord2f(fire[k].u, fire[k].v);
					  glVertex3f(fire[k].x, fire[k].y, fire[k].z);
				  }
				  glEnd();
			  }
			  else {
				  glBindTexture(GL_TEXTURE_2D, texture[1 + system.getTesseraMatrice2(i, j)->getImg()]);
				  glMatrixMode(GL_MODELVIEW);        // Select The Modelview Matrix
				  glLoadIdentity();                  // Reset The View

				  //glTranslatef(system.getTesseraMatrice(i, j)->getX(), system.getTesseraMatrice(i, j)->getY(), 0);
				  glTranslatef(system.getTesseraMatrice2(i, j)->getX(), system.getTesseraMatrice2(i, j)->getY(), 0);
				  glScalef(0.05f, 0.095f, 1);    // 1- scale the fire
				  glEnable(GL_BLEND);
				  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				  glEnable(GL_ALPHA_TEST);
				  glAlphaFunc(GL_GREATER, 0);
				  glBegin(GL_QUADS);
				  for (int k = 0; k < 4; k++) {
					  glTexCoord2f(fire[k].u, fire[k].v);
					  glVertex3f(fire[k].x, fire[k].y, fire[k].z);
				  }
				  glEnd();
			  }
		  }
	  }
  }
  

  //  Texture for the fire, change every 1/19 sec.
  //int texF = 1 + ((int( (Full_elapsed*19) )) %27 );
  //glBindTexture(GL_TEXTURE_2D,2);

  //  fire geometrical trasformations
  /*glMatrixMode(GL_MODELVIEW);				// Select The Modelview Matrix
	glLoadIdentity();									// Reset The View

	
  //  circular path from window center. Radious and angular velocity
  //  in radians as follows
  double radious = 0.5;
  double omega = PI / 27.0;  // PI/8 each second
  double px, py;
  /* px = radious * cos(omega * Full_elapsed);
  py = radious * sin(omega * Full_elapsed);
  */
  /*glTranslatef((float) px, (float) py, 0);
  glScalef(1,1,1);    // 1- scale the fire

  //  fire
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_GREATER, 0);
  
  glBegin(GL_QUADS);
  for(int i = 0; i < 4; i++) {
		glTexCoord2f(fire[i].u, fire[i].v);
    glVertex3f(fire[i].x, fire[i].y,  fire[i].z);
  }
  glEnd();
  */
  
  
  int colonna = system.getColonna(cx, this->Wwidth);
  int riga = system.getRiga(cy, this->Wheight);

  /*if (riga >= 0 && riga < N_RIGHE && colonna >= 0 && colonna < N_COLONNE) {
	  if (system.getTesseraMatrice(colonna, riga)->isEsisto()){
		  glBindTexture(GL_TEXTURE_2D, texture[43]);
		  glMatrixMode(GL_MODELVIEW);        // Select The Modelview Matrix
		  glLoadIdentity();                  // Reset The View

		  //glTranslatef(system.getTesseraMatrice(i, j)->getX(), system.getTesseraMatrice(i, j)->getY(), 0);
		  glTranslatef(system.getTesseraMatrice(colonna, riga)->getX(), system.getTesseraMatrice(colonna, riga)->getY(), 0);
		  glScalef(0.05f, 0.095f, 1);    // 1- scale the fire
		  glEnable(GL_BLEND);
		  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		  glEnable(GL_ALPHA_TEST);
		  glAlphaFunc(GL_GREATER, 0);
		  glBegin(GL_QUADS);
		  for (int k = 0; k < 4; k++) {
			  glTexCoord2f(fire[k].u, fire[k].v);
			  glVertex3f(fire[k].x, fire[k].y, fire[k].z);
		  }
		  glEnd();
	  }
  }
  */

  //bordo verde
  if (system.getHoverTessera() != NULL) {
	  if (system.getHoverTessera()->isEsisto()) {
		  glBindTexture(GL_TEXTURE_2D, texture[43]);
		  glMatrixMode(GL_MODELVIEW);        // Select The Modelview Matrix
		  glLoadIdentity();                  // Reset The View

		  //glTranslatef(system.getTesseraMatrice(i, j)->getX(), system.getTesseraMatrice(i, j)->getY(), 0);
		  glTranslatef(system.getHoverTessera()->getX(), system.getHoverTessera()->getY(), 0);
		  glScalef(0.05f, 0.095f, 1);    // 1- scale the fire
		  glEnable(GL_BLEND);
		  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		  glEnable(GL_ALPHA_TEST);
		  glAlphaFunc(GL_GREATER, 0);
		  glBegin(GL_QUADS);
		  for (int k = 0; k < 4; k++) {
			  glTexCoord2f(fire[k].u, fire[k].v);
			  glVertex3f(fire[k].x, fire[k].y, fire[k].z);
		  }
		  glEnd();
	  }
  }
 

  glDisable(GL_BLEND);
  glDisable(GL_ALPHA_TEST);
  
  //  Some text
  glMatrixMode(GL_MODELVIEW);				// Select The Modelview Matrix
 	glLoadIdentity();									// Reset The Current Modelview Matrix
	glDisable(GL_TEXTURE_2D);

 	// Color
	glColor3f(1.0f,1.0f,1.0f);

	// Position The Text On The Screen
  glRasterPos3f(- (float) plx + PixToCoord_X(10), (float) ply-PixToCoord_Y(21),
    -4);


  // compute fps and write text
  this->frames++;
  if( this->frames > 18 ) {
    this->fps = frames / frameTime;
    this->frames = 0; this->frameTime = 0;
  }
  this->glPrint("Tempo: %6.2f sec. %f ",
    Full_elapsed, fps);

  if(this->Full_elapsed < 10) {
    glRasterPos3f(- (float) plx + PixToCoord_X(10), (float) -ply+PixToCoord_Y(21),
    -4);
    this->glPrint("F2 per attivare o disattivare il suono");
  }

  {
	  glRasterPos3f(-(float)plx + PixToCoord_X(10), (float)-ply + PixToCoord_Y(61),
		  -4);
	  this->glPrint("%1d %1d  %s", cx, cy, captured ? "captured" : "Not captured");
  }
  {
	  glRasterPos3f(-(float)plx + PixToCoord_X(10), (float)-ply + PixToCoord_Y(91),
		  -4);
	  this->glPrint("%1d %1d", this->Wwidth, this->Wheight);
  }
  
  {
	  glRasterPos3f(-(float)plx + PixToCoord_X(10), (float)-ply + PixToCoord_Y(151),
		  -4);
	  this->glPrint("%d %d", riga, colonna);
  }

	glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping
  return true;
}


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//  bitmap fonts
void MyModel::BuildFont(void)								// Build Our Bitmap Font
{
	HFONT	font;										// Windows Font ID
	HFONT	oldfont;									// Used For Good House Keeping

	base = glGenLists(96);								// Storage For 96 Characters

	font = CreateFont(	-20,							// Height Of Font
						0,								// Width Of Font
						0,								// Angle Of Escapement
						0,								// Orientation Angle
						FW_BOLD,						// Font Weight
						FALSE,							// Italic
						FALSE,							// Underline
						FALSE,							// Strikeout
						ANSI_CHARSET,					// Character Set Identifier
						OUT_TT_PRECIS,					// Output Precision
						CLIP_DEFAULT_PRECIS,			// Clipping Precision
						ANTIALIASED_QUALITY,			// Output Quality
						FF_DONTCARE|DEFAULT_PITCH,		// Family And Pitch
						"Courier New");					// Font Name

	oldfont = (HFONT)SelectObject(hDC, font);           // Selects The Font We Want
	wglUseFontBitmaps(hDC, 32, 96, base);				// Builds 96 Characters Starting At Character 32
	SelectObject(hDC, oldfont);							// Selects The Font We Want
	DeleteObject(font);									// Delete The Font
}

void MyModel::KillFont(void)									// Delete The Font List
{
	glDeleteLists(base, 96);							// Delete All 96 Characters
}

void MyModel::glPrint(const char *fmt, ...)					// Custom GL "Print" Routine
{
	char		text[256];								// Holds Our String
	va_list		ap;										// Pointer To List Of Arguments

	if (fmt == NULL)									// If There's No Text
		return;											// Do Nothing

	va_start(ap, fmt);									// Parses The String For Variables
	    vsprintf(text, fmt, ap);						// And Converts Symbols To Actual Numbers
	va_end(ap);											// Results Are Stored In Text

	glPushAttrib(GL_LIST_BIT);							// Pushes The Display List Bits
	glListBase(base - 32);								// Sets The Base Character to 32
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);	// Draws The Display List Text
	glPopAttrib();										// Pops The Display List Bits
}