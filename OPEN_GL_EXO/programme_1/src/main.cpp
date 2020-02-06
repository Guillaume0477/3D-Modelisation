/*****************************************************************************\
 * TP CPE, 4ETI, TP synthese d'images
 * --------------
 *
 * Programme principal des appels OpenGL
\*****************************************************************************/



#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#define GLEW_STATIC 1
#include <GL/glew.h>
#include <GL/glut.h>

#include "glutils.hpp"


/*****************************************************************************\
 * Variables globales
 *
 *
\*****************************************************************************/

//identifiant du shader
GLuint shader_program_id;


/*****************************************************************************\
 * Fonctions GLUT
 *
 *
\*****************************************************************************/


/*****************************************************************************\
 * init                                                                      *
\*****************************************************************************/
static void init()
{

    // Chargement du shader
    shader_program_id = read_shader("shader.vert", "shader.frag");


    //activation de la gestion de la profondeur
    glEnable(GL_DEPTH_TEST); PRINT_OPENGL_ERROR();

}


//Fonction d'affichage
static void display_callback()
{

    //effacement des couleurs du fond d'ecran
    glClearColor(0.5f, 0.6f, 0.9f, 1.0f); PRINT_OPENGL_ERROR();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); PRINT_OPENGL_ERROR();



    //Changement de buffer d'affichage pour eviter un effet de scintillement
    glutSwapBuffers();
}

/*****************************************************************************\
 * keyboard_callback                                                         *
\*****************************************************************************/
static void keyboard_callback(unsigned char key, int, int)
{
    //quitte le programme si on appuis sur les touches 'q', 'Q', ou 'echap'
    switch (key)
    {
    case 'q':
    case 'Q':
    case 27:
        exit(0);
    }
}

/*****************************************************************************\
 * timer_callback                                                            *
\*****************************************************************************/
static void timer_callback(int)
{
    //demande de rappel de cette fonction dans 25ms
    glutTimerFunc(25, timer_callback, 0);

    //reactualisation de l'affichage
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    //**********************************************//
    //Lancement des fonctions principales de GLUT
    //**********************************************//

    //initialisation
    glutInit(&argc, argv);

    //Mode d'affichage (couleur, gestion de profondeur, ...)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    //Taille de la fenetre a l'ouverture
    glutInitWindowSize(600, 600);

    //Titre de la fenetre
    glutCreateWindow("OpenGL");

    //Fonction de la boucle d'affichage
    glutDisplayFunc(display_callback);

    //Fonction de gestion du clavier
    glutKeyboardFunc(keyboard_callback);

    //Fonction d'appel d'affichage en chaine
    glutTimerFunc(25, timer_callback, 0);

    //Initialisation des fonctions OpenGL
    glewInit();

    //Notre fonction d'initialisation des donnees et chargement des shaders
    init();


    //Lancement de la boucle (infinie) d'affichage de la fenetre
    glutMainLoop();

    //Plus rien n'est execute apres cela

    return 0;
}

