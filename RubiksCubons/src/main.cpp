#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <cstdio>
#include <cstdlib>
#include <new>

using namespace std;
#include "Couleur.h"
#include "RubikCube.h"
#include "Point.h"

char ClicGauchePresse, ClicDroitPresse;//Gestion des clics de la souris
int anglex,angley;//Gestion de l'angle de vue (pour faire tourner l'objet)
int posx, posy, posz;//Position actuelle du centre de l'objet dans l'espace plan
int x,y;//Position actuelle de la souris
int xoldGAUCHE,yoldGAUCHE, xoldDROIT, yoldDROIT;//Gestion des clics de la souris

/* Prototype des fonctions */
void affichage();
void clavier(unsigned char touche,int x,int y);
void reshape(int x,int y);
void mouse(int bouton,int etat,int x,int y);
void mousemotion(int x,int y);
//Creation de notre RubikCube 3x3 (par default)
RubikCube *rc = new RubikCube(3);



void affichage()
{
	  /* effacement de l'image avec la couleur de fond */
	  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	  glLoadIdentity();

	  glRotatef(-angley,1.0,0.0,0.0);
	  glRotatef(-anglex,0.0,1.0,0.0);
	  /*
	  float camera[] = {0.0, 1.0, 1.0};
	  float target[] = {0.0, 0.0, 0.0};
	  float tete[] = {0.0, 1.0, 0.0};

	  gluLookAt(camera[0], camera[1], camera[2],
	                 target[0], target[1], target[2],
	                 tete[0], tete[1], tete[2]);
	   */

	  //Active l'antialiasing pour les lignes
	  glEnable(GL_LINE_SMOOTH);

	  //Affichage
	  rc->afficher();
	  //récupère la valeur du centre de l'objet, pour pouvoir le déplacer dans l'espace plan
	  posx = rc->getCentre()->getX();
	  posy = rc->getCentre()->getY();
	  posz = rc->getCentre()->getZ();

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

void reshape(int x,int y)
{
  if (x<y)
    glViewport(0,(y-x)/2,x,x);
  else
    glViewport((x-y)/2,0,y,y);
}

void mouse(int button, int state,int x,int y)
{
  //appui clic gauche
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    ClicGauchePresse = 1; /* le booleen presse passe a 1 (vrai) */
    xoldGAUCHE = x; /* on sauvegarde la position de la souris */
    yoldGAUCHE=y;
  }
  //relache le clic gauche
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    ClicGauchePresse=0; /* le booleen passe a 0 (faux) */


  //appui clic droit
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
      ClicDroitPresse = 1; /* le booleen presse passe a 1 (vrai) */
      xoldDROIT = x; /* on sauvegarde la position de la souris */
      yoldDROIT=y;
    }
    //relache le clic gauche
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
      ClicDroitPresse=0; /* le booleen passe a 0 (faux) */
}

void mousemotion(int x,int y)
  {
    if (ClicGauchePresse)
    {
      /* on modifie les angles de rotation de l'objet
	 en fonction de la position actuelle de la souris et de la derniere
	 position sauvegardee */
      anglex=anglex+(x-xoldGAUCHE);
      angley=angley+(y-yoldGAUCHE);
      glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
    }

    if (ClicDroitPresse)
	{
	  /* on modifie le centre de l'objet et on le déplace
	 en fonction de la position actuelle de la souris et de la derniere
	 position sauvegardee */
	  anglex=anglex+(x-xoldGAUCHE);
	  angley=angley+(y-yoldGAUCHE);
	  glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
	}

    xoldGAUCHE=xoldDROIT=x; /* sauvegarde des valeurs courante de le position de la souris */
    yoldGAUCHE=yoldDROIT=y;
  }
int main(int argc,char **argv)
{
  /* initialisation de glut et creation de la fenetre */
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);//Active le double buffering
  glutInitWindowPosition(200,200);	//Poisitionne la fenetre
  glutInitWindowSize(800,800);	//Taille de la fenetre
  glutCreateWindow("RubiksCubons");	//Nomme la fenetre

  /* Initialisation d'OpenGL */
  glClearColor(0.0,0.0,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glPointSize(2.0);
  glEnable(GL_DEPTH_TEST);

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
