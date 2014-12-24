#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <cstdlib>

#include "Couleur.h"
#include "Cube.h"
#include "Point.h"



char presse;
int anglex,angley,x,y,xold,yold;

/* Prototype des fonctions */
void affichage();
void clavier(unsigned char touche,int x,int y);
void reshape(int x,int y);
void idle();
void mouse(int bouton,int etat,int x,int y);
void mousemotion(int x,int y);




void affichage()
{
  int i,j;
  /* effacement de l'image avec la couleur de fond */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  glRotatef(-angley,1.0,0.0,0.0);
  glRotatef(-anglex,0.0,1.0,0.0);
  /* Dessin du cube */

  //Creation des 6 différentes couleurs
  Couleur *rouge = new Couleur(1.0, 0.0, 0.0);
  Couleur *vert = new Couleur(0.0, 1.0, 0.0);
  Couleur *bleu = new Couleur(0.0, 0.0, 1.0);
  Couleur *jaune = new Couleur(1.0, 1.0, 0.0);
  Couleur *blanc = new Couleur(1.0, 1.0, 1.0);
  Couleur *orange = new Couleur(1.0, 0.7, 0.0);
  //Creation d'un cube
  Cube *c =  new Cube(
  		Point(-0.5, -0.5, 0.5),
  		Point(-0.5, 0.5, 0.5),
  		Point(0.5, 0.5, 0.5),
  		Point(0.5,-0.5, 0.5),
  		Point(-0.5,-0.5,-0.5),
  		Point(-0.5, 0.5,-0.5),
  		Point(0.5, 0.5,-0.5),
  		Point(0.5,-0.5,-0.5),
  		*rouge,
  		*vert,
  		*bleu,
  		*jaune,
  		*blanc,
  		*orange);

  c->afficher();
  /*for (i=0;i<6;i++)
    {
      glBegin(GL_POLYGON);
      for (j=0;j<4;j++)
	{
	  glColor3f(p[f[i][j]].r,p[f[i][j]].g,p[f[i][j]].b);
	  glVertex3f(p[f[i][j]].x,p[f[i][j]].y,p[f[i][j]].z);
	}
      glEnd();
    }*/
  glFlush();

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
  /* si on appuie sur le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    presse = 1; /* le booleen presse passe a 1 (vrai) */
    xold = x; /* on sauvegarde la position de la souris */
    yold=y;
  }
  /* si on relache le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    presse=0; /* le booleen presse passe a 0 (faux) */
}

void mousemotion(int x,int y)
  {
    if (presse) /* si le bouton gauche est presse */
    {
      /* on modifie les angles de rotation de l'objet
	 en fonction de la position actuelle de la souris et de la derniere
	 position sauvegardee */
      anglex=anglex+(x-xold);
      angley=angley+(y-yold);
      glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
    }

    xold=x; /* sauvegarde des valeurs courante de le position de la souris */
    yold=y;
  }
int main(int argc,char **argv)
{
  /* initialisation de glut et creation de la fenetre */
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(200,200);
  glutInitWindowSize(500,500);
  glutCreateWindow("RubiksCubons");

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
