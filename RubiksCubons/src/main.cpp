#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <cstdio>
#include <cstdlib>
#include <new>

using namespace std;
#include "Couleur.h"
#include "RubikCube.h"
#include "Point.h"


int Win_width = 800;
int Win_height = 800;
/*GESTION DE LA SOURIS*/
char ClicGauchePresse;//Gestion des clics de la souris
/*RUBIK CUBE*/
//rotation
int Mouse_x,Mouse_y;//NEW : Position actuelle de la souris
int Oldmouse_x,Oldmouse_y;//OLD: Gestion des clics de la souris
int Angle_x,Angle_y;//ACTION:Gestion de l'angle de vue (pour faire tourner l'objet)
//deplacement
GLfloat Mouse_plan_x, Mouse_plan_y;//NEW: Nouvelles coordonnées de la souris dans le plan
GLfloat Oldmouse_plan_x, Oldmouse_plan_y;//OLD: Anciennes coordonnées de la souris dans le plan
GLfloat Deplac_x, Deplac_y, Deplac_z;//ACTION:Position actuelle du centre de l'objet dans l'espace plan
/*CAMERA*/
GLfloat camera_posx = 1.0;
GLfloat camera_posy = 1.0;
GLfloat camera_posz = 4.0;
GLfloat camera_directionx = 0.0;
GLfloat camera_directiony = 0.0;
GLfloat camera_directionz = 0.0;
GLfloat camera_sensx = 0.0;
GLfloat camera_sensy = 1.0;
GLfloat camera_sensz = 0.0;


/*GESTION DES MENUS*/
int Dimension = 3;//taille du cube (3 par defaut)
char *ModeCube = "deplacement";//actions du clic gauches (0=mode ROTATION; 1=mode DEPLACEMENT)


/* Prototype des fonctions */
void affichage();
void clavier(unsigned char touche,int x,int y);
void reshape(int width,int height);
void mouse(int bouton,int etat,int x,int y);
void mousemotion(int x,int y);
//Creation de notre RubikCube 3x3 (par default)
RubikCube *rc = new RubikCube(Dimension);


/*GESTION DES MENUS*/
void selectDimension(int selection) {//selection de la taille du cube
  switch (selection) {
    case 11 :
    	Dimension = 3 ;
    	//rc->~RubikCube();
    	delete rc;
    	rc = new RubikCube(Dimension);
              break ;
    case 12 :
    	Dimension = 5 ;
    	//rc->~RubikCube();
    	delete rc;
		rc = new RubikCube(Dimension);
              break ;
  }
  glutPostRedisplay();
}

/*  selection pour l'objet */
void selectModeCube(int selection) {//selection du mode ROTATION/DEPLACEMENT
  switch (selection) {
    case 21  :
    	ModeCube = "rotation";
    	break;
    case 22  :
    	ModeCube = "deplacement";
    	break;
  }
  glutPostRedisplay();
}

void selectModeCamera(int selection){//selection de la vue de la CAMERA
	switch (selection) {
		case 31  ://centre
			camera_posx = 0.0;
			camera_posy = 0.0;
			camera_posz = 4.0;
			camera_directionx = 0.0;
			camera_directiony = 0.0;
			camera_directionz = 0.0;
			camera_sensx = 0.0;
			camera_sensy = 1.0;
			camera_sensz = 0.0;
			break;
		case 32  ://vue de l'espace haut gauche
			camera_posx = 0.0;
			camera_posy = 2.0;
			camera_posz = 2.0;
			camera_directionx = 0.0;
			camera_directiony = 0.0;
			camera_directionz = 0.0;
			camera_sensx = 0.0;
			camera_sensy = 1.0;
			camera_sensz = 0.0;
			break;

	}
	glutPostRedisplay();
}

void select(int selection) {
  switch (selection) {
    case 0  : exit(0); }
  glutPostRedisplay();
}
/*FIN DE GESTION DES MENUS*/


void affichage()
{
	/* effacement de l'image avec la couleur de fond */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();//Scene
		//glTranslatef(rc->getCentre()->getX(),rc->getCentre()->getY(),rc->getCentre()->getZ());
			glPushMatrix();//Observateur
				gluLookAt(	camera_directionx,camera_directiony,camera_directionz,//où je regarde
							camera_posx, camera_posy, camera_posz,//où je suis
							camera_sensx, camera_sensy, camera_sensz//sens de ma tete(x,y,z)
							);
				glPushMatrix();//RubikCube
					rc->Deplacement(Deplac_x, Deplac_y, Deplac_z);
					rc->Rotation('x', -Angle_y);
					rc->Rotation('y', -Angle_x);
					rc->afficher();//Affichage
				glPopMatrix();//RubikCube
				glMatrixMode(GL_MODELVIEW);
			glPopMatrix();//Observateur
		glPopMatrix();//Scene


	  /*
	  float camera[] = {0.0, 1.0, 1.0};
	  float target[] = {0.0, 0.0, 0.0};
	  float tete[] = {0.0, 1.0, 0.0};

	  gluLookAt(camera[0], camera[1], camera[2],
	                 target[0], target[1], target[2],
	                 tete[0], tete[1], tete[2]);
	   */


	  //récupère la valeur du centre de l'objet, pour pouvoir le déplacer dans l'espace plan
	  /*posx = rc->getCentre()->getX();
	  posy = rc->getCentre()->getY();
	  posz = rc->getCentre()->getZ();
*/
	  /* On echange les buffers */
	  glutSwapBuffers();
}

void clavier(unsigned char touche,int x,int y)
{
  switch (touche)
    {
    case 'p': /* affichage du carre plein */
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glutPostRedisplay();
      break;
    case 'f': /* affichage en mode fil de fer */
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      glutPostRedisplay();
      break;
    case 's' : /* Affichage en mode sommets seuls */
      glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
      glutPostRedisplay();
      break;
    case 'd':
      glEnable(GL_DEPTH_TEST);
      glutPostRedisplay();
      break;
    case 'D':
      glDisable(GL_DEPTH_TEST);
      glutPostRedisplay();
      break;
    case 'q' : /*la touche 'q' permet de quitter le programme */
      exit(0);
    }
}

void reshape(int width,int height)
{
	glViewport(0, 0, width, height);
	//changement de viewport
//	if (x<y)			//x, 		y			width	height
		//glViewport(		0,			(y-x)/2,	x,		x);
	//else
		//glViewport(		(x-y)/2,	0,			y,		y);
}

void mouse(int button, int state,int x,int y)
{
  //appui clic gauche
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    ClicGauchePresse = 1; /* le booleen presse passe a 1 (vrai) */
    //rotation
    Oldmouse_x = x; /* on sauvegarde la position de la souris */
    Oldmouse_y = y;
    //deplacement
    Oldmouse_plan_x = (2.0 * x) / Win_width - 1.0;
	Oldmouse_plan_y = (2.0 * y) / Win_height - 1.0;
  }
  //relache le clic gauche
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    ClicGauchePresse=0; //le booleen passe a 0 (faux)
}

void mousemotion(int x,int y)
  {
    if (ClicGauchePresse)
    {
    	if(ModeCube == "rotation"){
			/* on modifie les angles de rotation de l'objet
			en fonction de la position actuelle de la souris et de la derniere
			position sauvegardee */
			Angle_x += x-Oldmouse_x;
			Angle_y += y-Oldmouse_y;
			glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
    	}

    	if(ModeCube == "deplacement"){
			/* on modifie les point du centre de l'objet
			en fonction de la position actuelle de la souris et de la derniere
			position sauvegardee */
    		//position actuelle de la souris dans le plan[-1;1]
    		Mouse_plan_x = (2.0 * x) / Win_width - 1.0;//(theGlutMouseXCoordinate / theGlutWindowWidth) - 1.0
			Mouse_plan_y = (2.0 * y) / Win_height - 1.0;
			//calcul du déplacement par rapport à l'ancienne position
			Deplac_x += Mouse_plan_x - Oldmouse_plan_x;
			Deplac_y += Mouse_plan_y - Oldmouse_plan_y;
			Deplac_z = 0;
			glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
		}


    }

    Oldmouse_x=x; /* sauvegarde des valeurs courante de le position de la souris */
    Oldmouse_y=y;
    Oldmouse_plan_x = Mouse_plan_x;
    Oldmouse_plan_y = Mouse_plan_y;
  }
int main(int argc,char **argv)
{
  /* initialisation de glut et creation de la fenetre */
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);//Active le double buffering
  glutInitWindowPosition(200,200);	//Poisitionne la fenetre
  glutInitWindowSize(Win_width,Win_height);	//Taille de la fenetre
  glutCreateWindow("RubiksCubons");	//Nomme la fenetre

  /* Initialisation d'OpenGL */
  glClearColor(0.0,0.0,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glPointSize(2.0);
  glEnable(GL_DEPTH_TEST);


  /*creation du menu */

  //on commence par créer les sous-menus
  int menuDimension = glutCreateMenu(selectDimension);
       glutAddMenuEntry("3x3",11);
       glutAddMenuEntry("5x5",12);

   int menuCube = glutCreateMenu(selectModeCube);
           glutAddMenuEntry("Rotation",21);
           glutAddMenuEntry("Déplacement",22);

   int menuCamera = glutCreateMenu(selectModeCamera);
			  glutAddMenuEntry("Centrée sur la face active",31);
			  glutAddMenuEntry("Haut gauche",32);
 /* on crée ensuite le menu superieur et on lie les sous-menus  */
   glutCreateMenu(select);
        glutAddSubMenu("Dimension",menuDimension);
        glutAddSubMenu("Cube",menuCube);
        glutAddSubMenu("Camera",menuCamera);
        glutAddMenuEntry("Quitter",0);

   /* On associe le choix du bouton gauche de la souris */

   glutAttachMenu(GLUT_RIGHT_BUTTON);

  /* enregistrement des fonctions de rappel */
  glutDisplayFunc(affichage);
  glutKeyboardFunc(clavier);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutMotionFunc(mousemotion);

  /* Entree dans la boucle principale glut */
  glutMainLoop();
  return 0;
}
