/*****************************************************************************\
 * TP CPE, 3ETI, TP synthese d'images
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

#include "mat4.hpp"
#include "vec3.hpp"
#include "vec2.hpp"
#include "triangle_index.hpp"


/*****************************************************************************\
 * Variables globales
 *
 *
\*****************************************************************************/


//identifiant du shader
GLuint shader_program_id;

//l'identifiant de l'objet 3D
GLuint vbo=0;
GLuint vboi=0;

//les parametres de translations
float translation_x=0.0f;
float translation_y=0.0f;
float translation_z=-3.0f;

float angle_x=0.0f;
float angle_y=0.0f;

//Matrice de rotation
mat4 rotation;

//Matrice de projection
mat4 projection;


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

    //coordonnees geometriques des sommets
    vec3 p0=vec3(0.0f,0.0f,0.0f);
    vec3 p1=vec3(1.0f,0.0f,0.0f);
    vec3 p2=vec3(0.0f,1.0f,0.0f);

    //normales pour chaque sommet
    vec3 n0=vec3(0.0f,0.0f,1.0f);
    vec3 n1=vec3(0.0f,0.0f,1.0f);
    vec3 n2=vec3(0.0f,0.0f,1.0f);

    //tableau entrelacant coordonnees-normales
    vec3 geometrie[]={p0,n0 , p1,n1 , p2,n2};

    //indice des triangles
    triangle_index tri0=triangle_index(0,1,2);
    triangle_index index[]={tri0};

    //attribution d'un buffer de donnees (1 indique la création d'un buffer)
    glGenBuffers(1,&vbo); PRINT_OPENGL_ERROR();
    //affectation du buffer courant
    glBindBuffer(GL_ARRAY_BUFFER,vbo); PRINT_OPENGL_ERROR();
    //copie des donnees des sommets sur la carte graphique
    glBufferData(GL_ARRAY_BUFFER,sizeof(geometrie),geometrie,GL_STATIC_DRAW); PRINT_OPENGL_ERROR();

    // Active l'utilisation des données de positions
    glEnableClientState(GL_VERTEX_ARRAY); PRINT_OPENGL_ERROR();
    // Indique que le buffer courant (désigné par la variable vbo) est utilisé pour les positions de sommets
    glVertexPointer(3, GL_FLOAT, 2*sizeof(vec3), 0); PRINT_OPENGL_ERROR();

    // Active l'utilisation des données de normales
    glEnableClientState(GL_NORMAL_ARRAY); PRINT_OPENGL_ERROR();
    // Indique que le buffer courant (désigné par la variable vbo) est utilisé pour les normales
    glNormalPointer(GL_FLOAT, 2*sizeof(vec3), buffer_offset(sizeof(vec3))); PRINT_OPENGL_ERROR();


    //attribution d'un autre buffer de donnees
    glGenBuffers(1,&vboi); PRINT_OPENGL_ERROR();
    //affectation du buffer courant (buffer d'indice)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboi); PRINT_OPENGL_ERROR();
    //copie des indices sur la carte graphique
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(index),index,GL_STATIC_DRAW); PRINT_OPENGL_ERROR();



    // Chargement du shader
    shader_program_id = read_shader("shader.vert", "shader.frag");

    //matrice de projection
    projection=matrice_projection(50.0f*M_PI/180.0f,1.0f,0.5f,10.0f);
    glUniformMatrix4fv(get_uni_loc(shader_program_id,"projection"),1,false,pointeur(projection)); PRINT_OPENGL_ERROR();


    //activation de la gestion de la profondeur
    glEnable(GL_DEPTH_TEST); PRINT_OPENGL_ERROR();

}


//Fonction d'affichage
static void display_callback()
{
    //effacement des couleurs du fond d'ecran
    glClearColor(0.5f, 0.6f, 0.9f, 1.0f); PRINT_OPENGL_ERROR();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); PRINT_OPENGL_ERROR();


    //envoie des parametres sur la carte graphique
    glUniformMatrix4fv(get_uni_loc(shader_program_id,"rotation"),1,false,pointeur(rotation)); PRINT_OPENGL_ERROR();
    glUniform4f(get_uni_loc(shader_program_id,"translation"),translation_x,translation_y,translation_z,0.0f);PRINT_OPENGL_ERROR();

    //affichage
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0); PRINT_OPENGL_ERROR();

    //Changement de buffer d'affichage pour eviter un effet de scintillement
    glutSwapBuffers();
}

/*****************************************************************************\
 * keyboard_callback                                                         *
\*****************************************************************************/
static void keyboard_callback(unsigned char key, int, int)
{
    float d_angle=0.1f;
    float dz=0.5f;

    //quitte le programme si on appuie sur les touches 'q', 'Q', ou 'echap'
    switch (key)
    {
    case 'q':
    case 'Q':
    case 27:
        exit(0);
        break;

    case 'i':
        angle_x+=d_angle;
        break;
    case 'k':
        angle_x-=d_angle;
        break;
    case 'j':
        angle_y+=d_angle;
        break;
    case 'l':
        angle_y-=d_angle;
        break;

    case 'p':
        translation_z+=dz;
        break;
    case 'm':
        translation_z-=dz;
        break;
    }

    mat4 rotation_x=matrice_rotation(angle_x,1.0f,0.0f,0.0f);
    mat4 rotation_y=matrice_rotation(angle_y,0.0f,1.0f,0.0f);
    rotation=rotation_x*rotation_y;
}

/*****************************************************************************\
 * special_callback                                                          *
\*****************************************************************************/
static void special_callback(int key, int,int)
{
    float dL=0.03f;
    switch (key)
    {
    case GLUT_KEY_UP:
        translation_y+=dL; //rotation avec la touche du haut
        break;
    case GLUT_KEY_DOWN:
        translation_y-=dL; //rotation avec la touche du bas
        break;
    case GLUT_KEY_LEFT:
        translation_x-=dL; //rotation avec la touche de gauche
        break;
    case GLUT_KEY_RIGHT:
        translation_x+=dL; //rotation avec la touche de droite
        break;
    }

    //reactualisation de l'affichage
    glutPostRedisplay();
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

    //Fonction des touches speciales du clavier (fleches directionnelles)
    glutSpecialFunc(special_callback);

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

