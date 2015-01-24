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
int RotationAngleOfTranche = 0; //l'angle de rotation d'une tranche
int Mouse_x,Mouse_y;//NEW : Position actuelle de la souris
int Oldmouse_x,Oldmouse_y;//OLD: Gestion des clics de la souris
int Angle_x,Angle_y;//ACTION:Gestion de l'angle de vue (pour faire tourner l'objet)
//deplacement
GLfloat Mouse_plan_x, Mouse_plan_y;//NEW: Nouvelles coordonnйes de la souris dans le plan
GLfloat Oldmouse_plan_x, Oldmouse_plan_y;//OLD: Anciennes coordonnйes de la souris dans le plan
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
	int index;
  switch (selection) {
    case 11 :
    	Dimension = 3;
    	 index = rc->getSelectedtexture();
    	//rc->~RubikCube();
    	delete rc;
    	rc = new RubikCube(Dimension);
    	rc->loadTexture(index);
              break ;
    case 12 :
    	Dimension = 5;
    	index = rc->getSelectedtexture();
    	//rc->~RubikCube();
    	delete rc;
		rc = new RubikCube(Dimension);
		rc->loadTexture(index);
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

	/*GLfloat no_mat[] = { 0.0F, 0.0F, 0.0F, 0.0F };
		GLfloat mat_ambient[] = { 0.7F, 0.7F, 0.7F, 1.0F };
		GLfloat mat_ambient_color[] = { 0.8F, 0.8F, 0.2F, 1.0F };
		GLfloat mat_diffuse[] = { 0.0F, 1.0F, 0.0F, 1.0F };
		GLfloat mat_specular[] = { 0.0F, 0.0F, 1.0F, 1.0F };
		GLfloat no_shininess[] = { 0.0F };
		GLfloat low_shininess[] = { 5.0F };
		GLfloat high_shininess[] = { 15.0F };
		GLfloat mat_emission[] = { 0.3F, 0.2F, 0.2F, 0.0F };
		GLfloat jaune[] = { 1.0F, 1.0F, 0.0F, 1.0F };

		GLfloat amb[]  ={0.2, 0.2, 0.2, 1.0};
		GLfloat diff[] = {0.8, 0.8, 0.8, 1.0};
		GLfloat qsd[] = {0.0, 0.0, 0.0, 1.0};

		GLfloat jaune2[] = { 1.0F, 1.0F, 0.0F, 0.1F };

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		    glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, jaune);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, jaune);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);


		glutSolidTeapot(0.5);
		*/



	glPushMatrix();//Scene
		//glTranslatef(rc->getCentre()->getX(),rc->getCentre()->getY(),rc->getCentre()->getZ());
			glPushMatrix();//Observateur
				gluLookAt(	camera_directionx,camera_directiony,camera_directionz,//oщ je regarde
							camera_posx, camera_posy, camera_posz,//oщ je suis
							camera_sensx, camera_sensy, camera_sensz//sens de ma tete(x,y,z)
							);
				glPushMatrix();//RubikCube


					rc->Deplacement(Deplac_x, Deplac_y, Deplac_z);

					rc->Rotation('x', -Angle_y);
					rc->Rotation('y', -Angle_x);
					 //glutSolidCube(1.2);
					// glutSolidSphere(0.8,20,20);
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


	  //rйcupиre la valeur du centre de l'objet, pour pouvoir le dйplacer dans l'espace plan
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

void reshape(int w,int l)
{
	glViewport(0, 0, w, l);
		/* On veut changer la matrice de projection */
		glMatrixMode(GL_PROJECTION);
		/* chargement de la matrice identité */
		glLoadIdentity();
		/* On modifie les valeurs de projection */
		if (w > l)
			glOrtho((float)-w / l, (float)w / l, -1.0, 1.0, -1.0, 1.0);
		else
			glOrtho(-1.0, 1.0, (float)-l / w, (float)l / w, -1.0, 1.0);
		/* On applique la modification de matrice */
		glMatrixMode(GL_MODELVIEW);
		/*On revient sur la matrice initiale */
		glLoadIdentity();
	//glViewport(0, 0, width, height);
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
			//calcul du dйplacement par rapport а l'ancienne position
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

void trancheRotation(int tranche){


	RotationAngleOfTranche = rc->getAngle(tranche);
	RotationAngleOfTranche++;

	if (RotationAngleOfTranche % 90 != 0 ||  RotationAngleOfTranche == 0) {

		rc->RotateTranche(RotationAngleOfTranche,tranche);
		glutTimerFunc(50, trancheRotation, tranche);
		glutPostRedisplay();

	} else {
		if (RotationAngleOfTranche == 360) {
			RotationAngleOfTranche = 0;
		}
		rc->RotateTranche(RotationAngleOfTranche, tranche);
		glutPostRedisplay();

	}
	printf("RotationAngleOfTranche: %d \n", RotationAngleOfTranche);

}
void anim1(int arg){
	int time = 80;
	rc->updateAnim(1);
	if (arg < 3000 / time)
		glutTimerFunc(time, anim1, ++arg);
	else
		rc->StopCustomAnimation();

	glutPostRedisplay();
}
void anim2(int arg) {
	int time = 30;
	rc->updateAnim(2);
	if (arg < 5000 / time)
		glutTimerFunc(time, anim2, ++arg);
	else
		rc->StopCustomAnimation();

	glutPostRedisplay();
}
void menuAnimation(int arg){

	switch (arg) {
		case 1:
			  glutTimerFunc(100,trancheRotation,0);
			break;
		case 2:
			 glutTimerFunc(100,trancheRotation,1);
			break;
		case 3:
			 glutTimerFunc(100,trancheRotation,2);
			break;
		case 4:
			rc->StartCustomtAnimation1();
			 glutTimerFunc(100,anim1,0);
		break;
		case 5:
			rc->StartCustomtAnimation2();
			glutTimerFunc(100,anim2,0);
			glutPostRedisplay();
		break;
	default:
			break;
	}

}
void selectTexture(int arg){
	switch (arg) {
	case 1://default
		rc->loadTexture(0); //0 - no textures
		glutPostRedisplay();
		break;
	case 2: //texture 1
		rc->loadTexture(1);
		glutPostRedisplay();
		break;
	case 3: //texture 2
		rc->loadTexture(2);
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
void menuLight(int arg){


	GLfloat white[] = { 1.0F, 1.0F, 1.0F, 1.0F };
	GLfloat blue[] = { 0.0F, 0.0F, 1.0F, 1.0F };
	GLfloat green[] = { 0.0F, 1.0F, 0.0F, 1.0F };

	GLfloat position_centre[] = { 0.0F, 0.0F, 1.0F, 0.0F };
	GLfloat position_left[] = { -1.0F, 0.0F, 0.0F, 0.0F };
	GLfloat position_right[] = { 0.7F, 0.0F, 0.0F, 1.0F };
	GLfloat position_centre_color[] = { 0.0F, 0.0F, 0.8F, 0.0F };


	switch (arg) {
	case 44:
		 glDisable(GL_LIGHTING);
		 glDisable(GL_LIGHT0);
		 glDisable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
		 glutPostRedisplay();
		break;
	case 11:

		//glLightfv(GL_LIGHT0, GL_AMBIENT, blanc);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
		glLightfv(GL_LIGHT0, GL_SPECULAR, white);
		glLightfv(GL_LIGHT0, GL_POSITION, position_centre);

		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glutPostRedisplay();
		break;
	case 10:
		glDisable(GL_LIGHT0);
		glutPostRedisplay();
		break;
	case 21:
		glLightfv(GL_LIGHT1, GL_AMBIENT, blue);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, blue);
		glLightfv(GL_LIGHT1, GL_SPECULAR, white);
		glLightfv(GL_LIGHT1, GL_POSITION, position_centre_color);

		glEnable(GL_LIGHT1);
		  glEnable(GL_LIGHTING);
		glutPostRedisplay();
		break;
	case 20:
		glDisable(GL_LIGHT1);
		glutPostRedisplay();
		break;
	case 31:
			glLightfv(GL_LIGHT2, GL_AMBIENT, green);
			glLightfv(GL_LIGHT2, GL_DIFFUSE, green);
			glLightfv(GL_LIGHT2, GL_SPECULAR, white);
			glLightfv(GL_LIGHT2, GL_POSITION, position_right);
			glEnable(GL_LIGHT2);
			  glEnable(GL_LIGHTING);
			glutPostRedisplay();
			break;
		case 30:
		glDisable(GL_LIGHT2);
		glutPostRedisplay();
			break;
	default:
			break;
	}

}
void menuMaterials(int arg){

	switch (arg) {
		case 1:
			rc->setShining(true);
			glutPostRedisplay();
			break;
		case 0:
			rc->setShining(false);
			glutPostRedisplay();
				break;
		default:
			break;
	}

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
  glDepthFunc(GL_LESS);

  /*creation du menu */

  //on commence par crйer les sous-menus
  int menuDimension = glutCreateMenu(selectDimension);
       glutAddMenuEntry("3x3",11);
       glutAddMenuEntry("5x5",12);

   int menuCube = glutCreateMenu(selectModeCube);
           glutAddMenuEntry("Rotation",21);
           glutAddMenuEntry("Deplacement",22);

   int menuCamera = glutCreateMenu(selectModeCamera);
			  glutAddMenuEntry("Centre sur la face active",31);
			  glutAddMenuEntry("Haut gauche",32);

	int menuRotate = glutCreateMenu(menuAnimation);
		glutAddMenuEntry("Tranche 1", 1);
		glutAddMenuEntry("Tranche 2", 2);
		glutAddMenuEntry("Tranche 3", 3);

	int Menuanimation = glutCreateMenu(menuAnimation);
		glutAddSubMenu("Rotate", menuRotate);
		glutAddMenuEntry("Custom 1", 4);
		glutAddMenuEntry("Custom 2", 5);

	int MenuTextures = glutCreateMenu(selectTexture);
		glutAddMenuEntry("Default", 1);
		glutAddMenuEntry("Texture 1", 2);
		glutAddMenuEntry("Texture 2", 3);

		///==================================================
	// Light
	int menuLight1 = glutCreateMenu(menuLight);
		glutAddMenuEntry("On", 11);
		glutAddMenuEntry("Off", 10);
	int menuLight2 = glutCreateMenu(menuLight);
		glutAddMenuEntry("On", 21);
		glutAddMenuEntry("Off", 20);
	int menuLight3 = glutCreateMenu(menuLight);
		glutAddMenuEntry("On", 31);
		glutAddMenuEntry("Off", 30);
	int MenuLight = glutCreateMenu(menuLight);
		glutAddMenuEntry("Disable lighting", 44);
		glutAddSubMenu("Light centre white", menuLight1);
		glutAddSubMenu("Light centre blue", menuLight2);
		glutAddSubMenu("Light right green", menuLight3);

	//=========================================
		int MenuMat= glutCreateMenu(menuMaterials);
		glutAddMenuEntry("Enable shininess", 1);
		glutAddMenuEntry("Disable shininess", 0);

 /* on crйe ensuite le menu superieur et on lie les sous-menus  */
   glutCreateMenu(select);
        glutAddSubMenu("Dimension",menuDimension);
        glutAddSubMenu("Cube",menuCube);
        glutAddSubMenu("Camera",menuCamera);
        glutAddSubMenu("Animation",Menuanimation);
        glutAddSubMenu("Textures", MenuTextures);
        glutAddSubMenu("Lights", MenuLight);
        glutAddSubMenu("Materials", MenuMat);
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
