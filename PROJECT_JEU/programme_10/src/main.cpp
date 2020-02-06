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
#include <unistd.h>

#define GLEW_STATIC 1
#include <GL/glew.h>
#include <GL/glut.h> 

#include "glutils.hpp"

#include "mat4.hpp"  
#include "vec3.hpp"
#include "vec2.hpp"
#include "triangle_index.hpp"
#include "vertex_opengl.hpp"
#include "image.hpp"
#include "mesh.hpp"


/*****************************************************************************\
 * Variables globales
 *
 *
\*****************************************************************************/


//identifiant du shader
GLuint shader_program_id;

//identifiants pour object 1
GLuint vbo_object_1=0;
GLuint vboi_object_1=0;
GLuint texture_id_object_1=0;
int nbr_triangle_object_1;

//identifiants pour object 2
GLuint vbo_object_2=0;
GLuint vboi_object_2=0;
GLuint texture_id_object_2=0;
int nbr_triangle_object_2;

//identifiants pour object 3
GLuint vbo_object_3=0;
GLuint vboi_object_3=0;
GLuint texture_id_object_3=0;
int nbr_triangle_object_3;

//identifiants pour object 4
GLuint vbo_object_4=0;
GLuint vboi_object_4=0;
GLuint texture_id_object_4=0;
int nbr_triangle_object_4;

//identifiants pour Sffobject 5
GLuint vbo_object_5=0;
GLuint vboi_object_5=0;
GLuint texture_id_object_5=0;
int nbr_triangle_object_5;


//nombre de cible
int const nombre_cible(15);


GLuint vbo_object_tab[nombre_cible]={0};
GLuint vboi_object_tab[nombre_cible]={0};
GLuint texture_id_object_tab[nombre_cible]={0};
int nbr_triangle_object_tab[nombre_cible];



int nombre = 0;
//Matrice de transformation
struct transformation
{
    mat4 rotation;
    vec3 rotation_center;
    vec3 translation;

    transformation():rotation(),rotation_center(),translation(){}
};

//Transformation des modeles
transformation transformation_model_1;
transformation transformation_model_2;
transformation transformation_model_3;
transformation transformation_model_4;
transformation transformation_model_5;

transformation transformation_model_tab[nombre_cible];




//Transformation de la vue (camera)
transformation transformation_view;

//Matrice de projection
mat4 projection;

//angle de deplacement
float angle_x_model_1 = 0.0f;
float angle_y_model_1 = 0.0f;
float angle_x_model_3 = 0.0f;
float angle_y_model_3 = 0.0f;
float angle_x_model_4 = 0.0f;
float angle_y_model_4 = 0.0f;
float angle_x_model_5 = 0.0f;
float angle_y_model_5 = 0.0f;

float angle_x_model_tab[nombre_cible] = {0};
float angle_y_model_tab[nombre_cible] = {0};


float angle_view = 3.15f;




void load_texture(const char* filename,GLuint *texture_id);

void init_model_1();
void init_model_2();
void init_model_3();
void init_model_4();
void init_model_5();


//attention au nombre de cible...
void init_model_i(int);





void draw_model_1();
void draw_model_2();
void draw_model_3();
void draw_model_4();
void draw_model_5();



//attention au nombre de cible...
void draw_model_i(int);


static void init()
{


    // Chargement du shader
    shader_program_id = read_shader("shader.vert", "shader.frag");

    //matrice de projection
    projection = matrice_projection(60.0f*M_PI/180.0f,1.0f,0.01f,100.0f);
    glUniformMatrix4fv(get_uni_loc(shader_program_id,"projection"),1,false,pointeur(projection)); PRINT_OPENGL_ERROR();

    //centre de rotation de la 'camera' (les objets sont centres en z=-2)
    transformation_view.rotation_center = vec3(0.0f,0.0f,0.0f);

    //activation de la gestion de la profondeur
    glEnable(GL_DEPTH_TEST); PRINT_OPENGL_ERROR();

    // Charge modele 1 sur la carte graphique
    init_model_1();
    // Charge modele 2 sur la carte graphique
    init_model_2();
    // Charge modele 3 sur la carte graphique
    init_model_3();
	

	//moi


	
	// Charge modele 4 sur la carte graphique
    init_model_4();
	// Charge modele 5 sur la carte graphique
    init_model_5();




	// Charge modele 6 sur la carte graphique
	for (int k(0) ; k<(nombre_cible) ; k++)
	{
		init_model_i(k);
	}



	//variables
	(transformation_model_1.translation.z) = 2.08f;
	transformation_model_3.translation.z=transformation_model_1.translation.z;
	transformation_model_3.translation.x=transformation_model_1.translation.x;
	transformation_model_4.translation.z=transformation_model_1.translation.z;
	transformation_model_4.translation.x=transformation_model_1.translation.x;
	transformation_model_5.translation.z=transformation_model_1.translation.z;
	transformation_model_5.translation.x=transformation_model_1.translation.x;

	for (int j(0) ; j<(nombre_cible) ; j++)
	{
		transformation_model_tab[j].translation.z=transformation_model_1.translation.z+1+rand() %25;
		//printf("boute %f \n",transformation_model_tab[j].translation.z);
					transformation_model_tab[j].translation.x=transformation_model_1.translation.x-25+rand() %50;
		//printf("boute %f \n",transformation_model_tab[j].translation.x);
	}



	transformation_view.translation.z -= 0.5f;



	//envoie à opengl//initialisation variables
    transformation_model_1.rotation = matrice_rotation(angle_y_model_1 , 0.0f,1.0f,0.0f);
	transformation_model_3.rotation = matrice_rotation(angle_y_model_3 , 0.0f,1.0f,0.0f);
	transformation_model_4.rotation = matrice_rotation(angle_y_model_4 , 0.0f,1.0f,0.0f);
	transformation_model_5.rotation = matrice_rotation(angle_y_model_5 , 0.0f,1.0f,0.0f);
    transformation_view.rotation = matrice_rotation(angle_view , 0.0f,1.0f,0.0f);

	for (int j(0) ; j<(nombre_cible) ; j++)
	{	
		angle_y_model_tab[j]=angle_y_model_tab[j]+M_PI;
		transformation_model_tab[j].rotation = matrice_rotation(angle_y_model_tab[j] , 0.0f,1.0f,0.0f);
	}
}


//Fonction d'affichage
static void display_callback()
{
    //effacement des couleurs du fond d'ecran
    glClearColor(0.5f, 0.6f, 0.9f, 1.0f);                 PRINT_OPENGL_ERROR();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   PRINT_OPENGL_ERROR();

    // Affecte les parametres uniformes de la vue (identique pour tous les modeles de la scene)
    {
        //envoie de la rotation
        glUniformMatrix4fv(get_uni_loc(shader_program_id,"rotation_view"),1,false,pointeur(transformation_view.rotation)); PRINT_OPENGL_ERROR();

        //envoie du centre de rotation
        vec3 cv = transformation_view.rotation_center;
        glUniform4f(get_uni_loc(shader_program_id,"rotation_center_view") , cv.x,cv.y,cv.z , 0.0f); PRINT_OPENGL_ERROR();

        //envoie de la translation
        vec3 tv = transformation_view.translation;
        glUniform4f(get_uni_loc(shader_program_id,"translation_view") , tv.x,tv.y,tv.z , 0.0f); PRINT_OPENGL_ERROR();
    }


    // Affiche le modele numero 1 (dinosaure)
    draw_model_1();
    // Affiche le modele numero 2 (sol)
    draw_model_2();
    // Affiche le modele numero 3 (monstre)
    draw_model_3();
	// Affiche le modele numero 4 (dinosaure)
    draw_model_4();
	// Affiche le modele numero 5 (dinosaure)
    draw_model_5();

	// Affiche les modele cible (dinosaure)
	for (int k(0) ; k<(nombre_cible) ; k++)
	{
		draw_model_i(k);
	}



    //Changement de buffer d'affichage pour eviter un effet de scintillement
    glutSwapBuffers();
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



bool colision_1(){
	bool boole=false;
	float d;
	for (int n=0 ; n<(nombre_cible) ; n++)
	{		
		d=sqrt(pow(transformation_model_1.translation.x-transformation_model_tab[n].translation.x,2) +pow(transformation_model_1.translation.z-transformation_model_tab[n].translation.z,2)+pow(transformation_model_1.translation.y-transformation_model_tab[n].translation.y,2));
		if ((d<0.5))
			{
			transformation_model_tab[n].translation.y = transformation_model_tab[n].translation.y - 15;
			boole=true;
			break;}
	
	}
	return boole;
	}

bool colision_2(){
	bool boole=false;
	float d;
	for (int n=0 ; n<(nombre_cible) ; n++)
	{		
		d=sqrt(pow(transformation_model_4.translation.x-transformation_model_tab[n].translation.x,2) +pow(transformation_model_4.translation.z-transformation_model_tab[n].translation.z,2)+pow(transformation_model_4.translation.y-transformation_model_tab[n].translation.y,2));
		if ((d<0.5))
			{
			transformation_model_tab[n].translation.y = transformation_model_tab[n].translation.y - 15;
			boole=true;

			break;}
	
	}
	return boole;
	}


bool colision_3(){
	bool boole=false;
	float d;
	for (int n=0 ; n<(nombre_cible) ; n++)
	{		
		d=sqrt(pow(transformation_model_5.translation.x-transformation_model_tab[n].translation.x,2) +pow(transformation_model_5.translation.z-transformation_model_tab[n].translation.z,2)+pow(transformation_model_5.translation.y-transformation_model_tab[n].translation.y,2));

		if ((d<0.5))
			{
			transformation_model_tab[n].translation.y = transformation_model_tab[n].translation.y - 15;
			boole=true;
			break;}
	
	}
	return boole;
	}


void tire_balle_i(float theta_i)
{	
	float r_i = 0.0f;
	float dr = 0.5f;

	printf("%i ",nombre);
	
	if (nombre%3==0)
	{	
		nombre += 1;
		transformation_model_1.translation.y = 0.000000;
		while ((r_i<32) & !colision_1()) //ou colision
		{
		r_i += dr;
		transformation_model_1.translation.x = r_i*cos((57.9*theta_i-92.34)*3.141593/180);
		//printf("%f/n",transformation_model_1.translation.x);
		transformation_model_1.translation.z = 2.08f+r_i*sin((57.9*theta_i-92.34)*3.141593/180);
		display_callback();
		//printf("%f/n",transformation_model_1.translation.z);
		
		}
		transformation_model_1.translation.y = transformation_model_1.translation.y - 5;
		nombre += 1;
	}
	else {if (nombre%3==1)
	{		
		nombre += 1;
		transformation_model_4.translation.y = 0.000000;
		while ((r_i<32) & !colision_2()) //ou colision
		{
		r_i += dr;
		transformation_model_4.translation.x = r_i*cos((57.9*theta_i-92.34)*3.141593/180);
		//printf(ff"%f/n",transformation_model_1.translation.x);
		transformation_model_4.translation.z =2.08f+ r_i*sin((57.9*theta_i-92.34)*3.141593/180);
    		display_callback();
		//printf("%f/n",transformation_model_1.translation.z);
		
		}
		transformation_model_4.translation.y = transformation_model_4.translation.y - 5;
		
	}
	else {if (nombre%3==2)
	{	
		nombre += 1;
		transformation_model_5.translation.y = 0.000000;
		while ((r_i<32) & !colision_3()) //ou colision
		{
		r_i += dr;
		transformation_model_5.translation.x = r_i*cos((57.9*theta_i-92.34)*3.141593/180);
		//printf("%f/n",transformation_model_1.translation.x);
		transformation_model_5.translation.z =2.08f + r_i*sin((57.9*theta_i-92.34)*3.141593/180);
	   	display_callback();
		//printf("%f/n",transformation_model_1.translation.z);
		
		}
		transformation_model_5.translation.y = transformation_model_5.translation.y - 5;
		nombre += 1;
	}}}
	//else suppr
	
}



/*****************************************************************************\
 * keyboard_callback                                                         *
\*****************************************************************************/
static void keyboard_callback(unsigned char key, int, int)
{
    float d_angle=0.03f;
    float dz=0.5f;

	

    //quitte le programme si on appuie sur les touches 'q', 'Q', ou 'echap'
    switch (key)
    {
    case 'q':
    case 'Q':
    case 27:
        exit(0);
        break;

    case 'o':
        tire_balle_i(angle_view);
        break;
    case 'l':
        angle_x_model_3 -= d_angle;
        break;

    case 'k':
        angle_y_model_3 += d_angle;
        break;
    case 'm':
        angle_y_model_3 -= d_angle;
        break;

	//tourner vue et perso droite
    case 's':
	if (angle_view >= 1.7f){
        angle_view -= d_angle;
		angle_y_model_1 += d_angle;
		angle_y_model_3 += d_angle;
		angle_y_model_4 += d_angle;
		angle_y_model_5 += d_angle;
		for (int j(0) ; j<(nombre_cible) ; j++)
		{
			angle_y_model_tab[j] += d_angle;
		}
		
		}
        	break;

	//tourner vue et perso gauche
    case 'f':
	if (angle_view <= 4.6f){
        angle_view += d_angle;
		angle_y_model_1 -= d_angle;
		angle_y_model_3 -= d_angle;
		angle_y_model_4 -= d_angle;
		angle_y_model_5 -= d_angle;
		for (int j(0) ; j<(nombre_cible) ; j++)
		{
			angle_y_model_tab[j] -= d_angle;
		}
		}
        	break;


    case 'e':
        transformation_view.translation.z += dz;
        break;
    case 'd':
        transformation_view.translation.z -= dz;
        break;

    }

    	transformation_model_1.rotation = matrice_rotation(angle_y_model_1 , 0.0f,1.0f,0.0f);
	transformation_model_3.rotation = matrice_rotation(angle_y_model_3 , 0.0f,1.0f,0.0f);
	transformation_model_4.rotation = matrice_rotation(angle_y_model_4 , 0.0f,1.0f,0.0f);
	transformation_model_5.rotation = matrice_rotation(angle_y_model_5 , 0.0f,1.0f,0.0f);
	
	for (int j(0) ; j<(nombre_cible) ; j++)
	{
		transformation_model_tab[j].rotation = matrice_rotation(angle_y_model_tab[j] , 0.0f,1.0f,0.0f);
	}
	
    transformation_view.rotation = matrice_rotation(angle_view , 0.0f,1.0f,0.0f);
	
}

/*****************************************************************************\
 * special_callback                                                          *
\*****************************************************************************/
static void special_callback(int key, int,int)
{
    float dL=0.01f;

    switch (key)
    {

	//test deplacement perso
	/*
    case GLUT_KEY_UP:
        transformation_model_1.translation.z += dL; //rotation avec la touche du haut
		printf("%f",transformation_model_1.translation.z);
        break;
    case GLUT_KEY_DOWN:
        transformation_model_1.translation.z -= dL; //rotation avec la touche du bas
        printf("%f",transformation_model_1.translation.z);
        break;
	*/
    case GLUT_KEY_UP:
        transformation_model_3.translation.z += dL; //rotation avec la touche du haut
		printf("%f",transformation_model_1.translation.z);
        break;
    case GLUT_KEY_DOWN:
        transformation_model_3.translation.z -= dL; //rotation avec la touche du bas
        printf("%f",transformation_model_1.translation.z);
        break;
    case GLUT_KEY_LEFT:
        transformation_model_3.translation.x -= dL; //rotation avec la touche de gauche
        break;
    case GLUT_KEY_RIGHT:
        transformation_model_3.translation.x += dL; //rotation avec la touche de droite
        break;
    }


    //reactualisation de l'affichage
    glutPostRedisplay();
}






int main(int argc, char** argv)
{
    //**********************************************//
    //Lancement des fonctions principales de GLUT
    //**********************************************//
	//void static tire_balle_i(float);

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
    glutTimerFunc(5, timer_callback, 0);

    //Initialisation des fonctions OpenGL
    glewInit();

    //Notre fonction d'initialisation des donnees et chargement des shaders
    init();


    //Lancement de la boucle (infinie) d'affichage de la fenetre
    glutMainLoop();

    //Plus rien n'est execute apres cela

    return 0;
}


void draw_model_1()
{

    //envoie des parametres uniformes
    {
        glUniformMatrix4fv(get_uni_loc(shader_program_id,"rotation_model"),1,false,pointeur(transformation_model_1.rotation));    PRINT_OPENGL_ERROR();

        vec3 c = transformation_model_1.rotation_center;
        glUniform4f(get_uni_loc(shader_program_id,"rotation_center_model") , c.x,c.y,c.z , 0.0f);                                 PRINT_OPENGL_ERROR();

        vec3 t = transformation_model_1.translation;
        glUniform4f(get_uni_loc(shader_program_id,"translation_model") , t.x,t.y,t.z , 0.0f);                                     PRINT_OPENGL_ERROR();
    }

    //placement des VBO
    {
        //selection du VBO courant
        glBindBuffer(GL_ARRAY_BUFFER,vbo_object_1);                                                    PRINT_OPENGL_ERROR();

        // mise en place des differents pointeurs
        glEnableClientState(GL_VERTEX_ARRAY);                                                          PRINT_OPENGL_ERROR();
        glVertexPointer(3, GL_FLOAT, sizeof(vertex_opengl), 0);                                        PRINT_OPENGL_ERROR();

        glEnableClientState(GL_NORMAL_ARRAY); PRINT_OPENGL_ERROR();                                    PRINT_OPENGL_ERROR();
        glNormalPointer(GL_FLOAT, sizeof(vertex_opengl), buffer_offset(sizeof(vec3)));                 PRINT_OPENGL_ERROR();

        glEnableClientState(GL_COLOR_ARRAY); PRINT_OPENGL_ERROR();                                     PRINT_OPENGL_ERROR();
        glColorPointer(3,GL_FLOAT, sizeof(vertex_opengl), buffer_offset(2*sizeof(vec3)));              PRINT_OPENGL_ERROR();

        glEnableClientState(GL_TEXTURE_COORD_ARRAY); PRINT_OPENGL_ERROR();                             PRINT_OPENGL_ERROR();
        glTexCoordPointer(2,GL_FLOAT, sizeof(vertex_opengl), buffer_offset(3*sizeof(vec3)));           PRINT_OPENGL_ERROR();

    }

    //affichage
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboi_object_1);                           PRINT_OPENGL_ERROR();
        glBindTexture(GL_TEXTURE_2D, texture_id_object_1);                             PRINT_OPENGL_ERROR();
        glDrawElements(GL_TRIANGLES, 3*nbr_triangle_object_1, GL_UNSIGNED_INT, 0);     PRINT_OPENGL_ERROR();
    }

}

void draw_model_2()
{

    //envoie des parametres uniformes
    {
        glUniformMatrix4fv(get_uni_loc(shader_program_id,"rotation_model"),1,false,pointeur(transformation_model_2.rotation));    PRINT_OPENGL_ERROR();

        vec3 c = transformation_model_2.rotation_center;
        glUniform4f(get_uni_loc(shader_program_id,"rotation_center_model") , c.x,c.y,c.z , 0.0f);                                 PRINT_OPENGL_ERROR();

        vec3 t = transformation_model_2.translation;
        glUniform4f(get_uni_loc(shader_program_id,"translation_model") , t.x,t.y,t.z , 0.0f);                                     PRINT_OPENGL_ERROR();
    }

    //placement des VBO
    {
        //selection du VBO courant
        glBindBuffer(GL_ARRAY_BUFFER,vbo_object_2);                                                    PRINT_OPENGL_ERROR();

        // mise en place des differents pointeurs
        glEnableClientState(GL_VERTEX_ARRAY);                                                          PRINT_OPENGL_ERROR();
        glVertexPointer(3, GL_FLOAT, sizeof(vertex_opengl), 0);                                        PRINT_OPENGL_ERROR();

        glEnableClientState(GL_NORMAL_ARRAY); PRINT_OPENGL_ERROR();                                    PRINT_OPENGL_ERROR();
        glNormalPointer(GL_FLOAT, sizeof(vertex_opengl), buffer_offset(sizeof(vec3)));                 PRINT_OPENGL_ERROR();

        glEnableClientState(GL_COLOR_ARRAY); PRINT_OPENGL_ERROR();                                     PRINT_OPENGL_ERROR();
        glColorPointer(3,GL_FLOAT, sizeof(vertex_opengl), buffer_offset(2*sizeof(vec3)));              PRINT_OPENGL_ERROR();

        glEnableClientState(GL_TEXTURE_COORD_ARRAY); PRINT_OPENGL_ERROR();                             PRINT_OPENGL_ERROR();
        glTexCoordPointer(2,GL_FLOAT, sizeof(vertex_opengl), buffer_offset(3*sizeof(vec3)));           PRINT_OPENGL_ERROR();

    }

    //affichage
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboi_object_2);                           PRINT_OPENGL_ERROR();
        glBindTexture(GL_TEXTURE_2D, texture_id_object_2);                             PRINT_OPENGL_ERROR();
        glDrawElements(GL_TRIANGLES, 3*nbr_triangle_object_2, GL_UNSIGNED_INT, 0);     PRINT_OPENGL_ERROR();
    }
}

void draw_model_3()
{

    //envoie des parametres uniformes
    {
        glUniformMatrix4fv(get_uni_loc(shader_program_id,"rotation_model"),1,false,pointeur(transformation_model_3.rotation));    PRINT_OPENGL_ERROR();

        vec3 c = transformation_model_3.rotation_center;
        glUniform4f(get_uni_loc(shader_program_id,"rotation_center_model") , c.x,c.y,c.z , 0.0f);                                 PRINT_OPENGL_ERROR();

        vec3 t = transformation_model_3.translation;
        glUniform4f(get_uni_loc(shader_program_id,"translation_model") , t.x,t.y,t.z , 0.0f);                                     PRINT_OPENGL_ERROR();
    }

    //placement des VBO
    {
        //selection du VBO courant
        glBindBuffer(GL_ARRAY_BUFFER,vbo_object_3);                                                    PRINT_OPENGL_ERROR();

        // mise en place des differents pointeurs
        glEnableClientState(GL_VERTEX_ARRAY);                                                          PRINT_OPENGL_ERROR();
        glVertexPointer(3, GL_FLOAT, sizeof(vertex_opengl), 0);                                        PRINT_OPENGL_ERROR();

        glEnableClientState(GL_NORMAL_ARRAY); PRINT_OPENGL_ERROR();                                    PRINT_OPENGL_ERROR();
        glNormalPointer(GL_FLOAT, sizeof(vertex_opengl), buffer_offset(sizeof(vec3)));                 PRINT_OPENGL_ERROR();

        glEnableClientState(GL_COLOR_ARRAY); PRINT_OPENGL_ERROR();                                     PRINT_OPENGL_ERROR();
        glColorPointer(3,GL_FLOAT, sizeof(vertex_opengl), buffer_offset(2*sizeof(vec3)));              PRINT_OPENGL_ERROR();

        glEnableClientState(GL_TEXTURE_COORD_ARRAY); PRINT_OPENGL_ERROR();                             PRINT_OPENGL_ERROR();
        glTexCoordPointer(2,GL_FLOAT, sizeof(vertex_opengl), buffer_offset(3*sizeof(vec3)));           PRINT_OPENGL_ERROR();

    }

    //affichage
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboi_object_3);                           PRINT_OPENGL_ERROR();
        glBindTexture(GL_TEXTURE_2D, texture_id_object_3);                             PRINT_OPENGL_ERROR();
        glDrawElements(GL_TRIANGLES, 3*nbr_triangle_object_3, GL_UNSIGNED_INT, 0);     PRINT_OPENGL_ERROR();
    }

}


void draw_model_4()
{

    //envoie des parametres uniformes
    {
        glUniformMatrix4fv(get_uni_loc(shader_program_id,"rotation_model"),1,false,pointeur(transformation_model_4.rotation));    PRINT_OPENGL_ERROR();

        vec3 c = transformation_model_4.rotation_center;
        glUniform4f(get_uni_loc(shader_program_id,"rotation_center_model") , c.x,c.y,c.z , 0.0f);                                 PRINT_OPENGL_ERROR();

        vec3 t = transformation_model_4.translation;
        glUniform4f(get_uni_loc(shader_program_id,"translation_model") , t.x,t.y,t.z , 0.0f);                                     PRINT_OPENGL_ERROR();
    }

    //placement des VBO
    {
        //selection du VBO courant
        glBindBuffer(GL_ARRAY_BUFFER,vbo_object_4);                                                    PRINT_OPENGL_ERROR();

        // mise en place des differents pointeurs
        glEnableClientState(GL_VERTEX_ARRAY);                                                          PRINT_OPENGL_ERROR();
        glVertexPointer(3, GL_FLOAT, sizeof(vertex_opengl), 0);                                        PRINT_OPENGL_ERROR();

        glEnableClientState(GL_NORMAL_ARRAY); PRINT_OPENGL_ERROR();                                    PRINT_OPENGL_ERROR();
        glNormalPointer(GL_FLOAT, sizeof(vertex_opengl), buffer_offset(sizeof(vec3)));                 PRINT_OPENGL_ERROR();

        glEnableClientState(GL_COLOR_ARRAY); PRINT_OPENGL_ERROR();                                     PRINT_OPENGL_ERROR();
        glColorPointer(3,GL_FLOAT, sizeof(vertex_opengl), buffer_offset(2*sizeof(vec3)));              PRINT_OPENGL_ERROR();

        glEnableClientState(GL_TEXTURE_COORD_ARRAY); PRINT_OPENGL_ERROR();                             PRINT_OPENGL_ERROR();
        glTexCoordPointer(2,GL_FLOAT, sizeof(vertex_opengl), buffer_offset(3*sizeof(vec3)));           PRINT_OPENGL_ERROR();

    }

    //affichage
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboi_object_4);                           PRINT_OPENGL_ERROR();
        glBindTexture(GL_TEXTURE_2D, texture_id_object_4);                             PRINT_OPENGL_ERROR();
        glDrawElements(GL_TRIANGLES, 3*nbr_triangle_object_4, GL_UNSIGNED_INT, 0);     PRINT_OPENGL_ERROR();
    }

}

void draw_model_5()
{

    //envoie des parametres uniformes
    {
        glUniformMatrix4fv(get_uni_loc(shader_program_id,"rotation_model"),1,false,pointeur(transformation_model_5.rotation));    PRINT_OPENGL_ERROR();

        vec3 c = transformation_model_5.rotation_center;
        glUniform4f(get_uni_loc(shader_program_id,"rotation_center_model") , c.x,c.y,c.z , 0.0f);                                 PRINT_OPENGL_ERROR();

        vec3 t = transformation_model_5.translation;
        glUniform4f(get_uni_loc(shader_program_id,"translation_model") , t.x,t.y,t.z , 0.0f);                                     PRINT_OPENGL_ERROR();
    }

    //placement des VBO
    {
        //selection du VBO courant
        glBindBuffer(GL_ARRAY_BUFFER,vbo_object_5);                                                    PRINT_OPENGL_ERROR();

        // mise en place des differents pointeurs
        glEnableClientState(GL_VERTEX_ARRAY);                                                          PRINT_OPENGL_ERROR();
        glVertexPointer(3, GL_FLOAT, sizeof(vertex_opengl), 0);                                        PRINT_OPENGL_ERROR();

        glEnableClientState(GL_NORMAL_ARRAY); PRINT_OPENGL_ERROR();                                    PRINT_OPENGL_ERROR();
        glNormalPointer(GL_FLOAT, sizeof(vertex_opengl), buffer_offset(sizeof(vec3)));                 PRINT_OPENGL_ERROR();

        glEnableClientState(GL_COLOR_ARRAY); PRINT_OPENGL_ERROR();                                     PRINT_OPENGL_ERROR();
        glColorPointer(3,GL_FLOAT, sizeof(vertex_opengl), buffer_offset(2*sizeof(vec3)));              PRINT_OPENGL_ERROR();

        glEnableClientState(GL_TEXTURE_COORD_ARRAY); PRINT_OPENGL_ERROR();                             PRINT_OPENGL_ERROR();
        glTexCoordPointer(2,GL_FLOAT, sizeof(vertex_opengl), buffer_offset(3*sizeof(vec3)));           PRINT_OPENGL_ERROR();

    }

    //affichage
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboi_object_5);                           PRINT_OPENGL_ERROR();
        glBindTexture(GL_TEXTURE_2D, texture_id_object_5);                             PRINT_OPENGL_ERROR();
        glDrawElements(GL_TRIANGLES, 3*nbr_triangle_object_5, GL_UNSIGNED_INT, 0);     PRINT_OPENGL_ERROR();
    }

}


	//attention au nombre de cible...
void draw_model_i(int k)
{
	
    //envoie des parametres uniformes
    {
        glUniformMatrix4fv(get_uni_loc(shader_program_id,"rotation_model"),1,false,pointeur(transformation_model_tab[k].rotation));    PRINT_OPENGL_ERROR();

        vec3 c = transformation_model_1.rotation_center;
        glUniform4f(get_uni_loc(shader_program_id,"rotation_center_model") , c.x,c.y,c.z , 0.0f);                                 PRINT_OPENGL_ERROR();

        vec3 t = transformation_model_tab[k].translation;
        glUniform4f(get_uni_loc(shader_program_id,"translation_model") , t.x,t.y,t.z , 0.0f);                                     PRINT_OPENGL_ERROR();
    }

    //placement des VBO
    {
        //selection du VBO courant
        glBindBuffer(GL_ARRAY_BUFFER,vbo_object_tab[k]);                                                    PRINT_OPENGL_ERROR();

        // mise en place des differents pointeurs
        glEnableClientState(GL_VERTEX_ARRAY);                                                          PRINT_OPENGL_ERROR();
        glVertexPointer(3, GL_FLOAT, sizeof(vertex_opengl), 0);                                        PRINT_OPENGL_ERROR();

        glEnableClientState(GL_NORMAL_ARRAY); PRINT_OPENGL_ERROR();                                    PRINT_OPENGL_ERROR();
        glNormalPointer(GL_FLOAT, sizeof(vertex_opengl), buffer_offset(sizeof(vec3)));                 PRINT_OPENGL_ERROR();

        glEnableClientState(GL_COLOR_ARRAY); PRINT_OPENGL_ERROR();                                     PRINT_OPENGL_ERROR();
        glColorPointer(3,GL_FLOAT, sizeof(vertex_opengl), buffer_offset(2*sizeof(vec3)));              PRINT_OPENGL_ERROR();

        glEnableClientState(GL_TEXTURE_COORD_ARRAY); PRINT_OPENGL_ERROR();                             PRINT_OPENGL_ERROR();
        glTexCoordPointer(2,GL_FLOAT, sizeof(vertex_opengl), buffer_offset(3*sizeof(vec3)));           PRINT_OPENGL_ERROR();

    }

    //affichage
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboi_object_tab[k]);                           PRINT_OPENGL_ERROR();
        glBindTexture(GL_TEXTURE_2D, texture_id_object_tab[k]);                             PRINT_OPENGL_ERROR();
        glDrawElements(GL_TRIANGLES, 3*nbr_triangle_object_tab[k], GL_UNSIGNED_INT, 0);     PRINT_OPENGL_ERROR();
    }

}







void init_model_1()
{
    // Chargement d'un maillage a partir d'un fichier
    mesh m = load_obj_file("../data/stegosaurus.obj");

    // Affecte une transformation sur les sommets du maillage
    float s = 0.2f;
    mat4 transform = mat4(   s, 0.0f, 0.0f, 0.0f,
                          0.0f,    s, 0.0f,-0.9f,
                          0.0f, 0.0f,   s ,-2.0f,
                          0.0f, 0.0f, 0.0f, 1.0f);
    apply_deformation(&m,transform);

    // Centre la rotation du modele 1 autour de son centre de gravite approximatif
    transformation_model_1.rotation_center = vec3(0.0f,-0.5f,-2.08f);

    // Calcul automatique des normales du maillage
    update_normals(&m);
    // Les sommets sont affectes a une couleur blanche
    fill_color(&m,vec3(1.0f,1.0f,1.0f));

    //attribution d'un buffer de donnees (1 indique la création d'un buffer)
    glGenBuffers(1,&vbo_object_1); PRINT_OPENGL_ERROR();
    //affectation du buffer courant
    glBindBuffer(GL_ARRAY_BUFFER,vbo_object_1); PRINT_OPENGL_ERROR();
    //copie des donnees des sommets sur la carte graphique
    glBufferData(GL_ARRAY_BUFFER,m.vertex.size()*sizeof(vertex_opengl),&m.vertex[0],GL_STATIC_DRAW); PRINT_OPENGL_ERROR();


    //attribution d'un autre buffer de donnees
    glGenBuffers(1,&vboi_object_1); PRINT_OPENGL_ERROR();
    //affectation du buffer courant (buffer d'indice)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboi_object_1); PRINT_OPENGL_ERROR();
    //copie des indices sur la carte graphique
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,m.connectivity.size()*sizeof(triangle_index),&m.connectivity[0],GL_STATIC_DRAW); PRINT_OPENGL_ERROR();

    // Nombre de triangles de l'objet 1
    nbr_triangle_object_1 = m.connectivity.size();

    // Chargement de la texture
    load_texture("../data/stegosaurus.tga",&texture_id_object_1);


}

void init_model_2()
{
    //Creation manuelle du model 2

    //coordonnees geometriques des sommets
    vec3 p0=vec3(-25.0f,-0.9f, -2.0f);
    vec3 p1=vec3( 25.0f,-0.9f, -2.0f);
    vec3 p2=vec3( 25.0f,-0.9f, 25.0f);
    vec3 p3=vec3(-25.0f,-0.9f, 25.0f);

    //normales pour chaque sommet
    vec3 n0=vec3(0.0f,1.0f,0.0f);
    vec3 n1=n0;
    vec3 n2=n0;
    vec3 n3=n0;

    //couleur pour chaque sommet
    vec3 c0=vec3(1.0f,1.0f,1.0f);
    vec3 c1=c0;
    vec3 c2=c0;
    vec3 c3=c0;

    //texture du sommet
    vec2 t0=vec2(0.0f,0.0f);
    vec2 t1=vec2(1.0f,0.0f);
    vec2 t2=vec2(1.0f,1.0f);
    vec2 t3=vec2(0.0f,1.0f);

    vertex_opengl v0=vertex_opengl(p0,n0,c0,t0);
    vertex_opengl v1=vertex_opengl(p1,n1,c1,t1);
    vertex_opengl v2=vertex_opengl(p2,n2,c2,t2);
    vertex_opengl v3=vertex_opengl(p3,n3,c3,t3);


    //tableau entrelacant coordonnees-normales
    vertex_opengl geometrie[]={v0,v1,v2,v3};


    //indice des triangles
    triangle_index tri0=triangle_index(0,1,2);
    triangle_index tri1=triangle_index(0,2,3);
    triangle_index index[]={tri0,tri1};
    nbr_triangle_object_2 = 2;

    //attribution d'un buffer de donnees (1 indique la création d'un buffer)
    glGenBuffers(1,&vbo_object_2);                                             PRINT_OPENGL_ERROR();
    //affectation du buffer courant
    glBindBuffer(GL_ARRAY_BUFFER,vbo_object_2);                                PRINT_OPENGL_ERROR();
    //copie des donnees des sommets sur la carte graphique
    glBufferData(GL_ARRAY_BUFFER,sizeof(geometrie),geometrie,GL_STATIC_DRAW);  PRINT_OPENGL_ERROR();


    //attribution d'un autre buffer de donnees
    glGenBuffers(1,&vboi_object_2);                                            PRINT_OPENGL_ERROR();
    //affectation du buffer courant (buffer d'indice)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboi_object_2);                       PRINT_OPENGL_ERROR();
    //copie des indices sur la carte graphique
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(index),index,GL_STATIC_DRAW);  PRINT_OPENGL_ERROR();

    // Chargement de la texture
    load_texture("../data/grass.tga",&texture_id_object_2);

}


void init_model_3()
{
    // Chargement d'un maillage a partir d'un fichier
    mesh m = load_obj_file("../data/stegosaurus.obj");

    // Affecte une transformation sur les sommets du maillage
    float s = 0.2f;
    mat4 transform = mat4(   s, 0.0f, 0.0f, 0.0f,
                          0.0f,    s, 0.0f,-0.9f,
                          0.0f, 0.0f,   s ,-2.0f,
                          0.0f, 0.0f, 0.0f, 1.0f);
    apply_deformation(&m,transform);

    // Centre la rotation du modele 1 autour de son centre de gravite approximatif
    transformation_model_3.rotation_center = vec3(0.0f,-0.5f,-2.08f);

    // Calcul automatique des normales du maillage
    update_normals(&m);
    // Les sommets sont affectes a une couleur blanche
    fill_color(&m,vec3(1.0f,1.0f,1.0f));

    //attribution d'un buffer de donnees (1 indique la création d'un buffer)
    glGenBuffers(1,&vbo_object_3); PRINT_OPENGL_ERROR();
    //affectation du buffer courant
    glBindBuffer(GL_ARRAY_BUFFER,vbo_object_3); PRINT_OPENGL_ERROR();
    //copie des donnees des sommets sur la carte graphique
    glBufferData(GL_ARRAY_BUFFER,m.vertex.size()*sizeof(vertex_opengl),&m.vertex[0],GL_STATIC_DRAW); PRINT_OPENGL_ERROR();


    //attribution d'un autre buffer de donnees
    glGenBuffers(1,&vboi_object_3); PRINT_OPENGL_ERROR();
    //affectation du buffer courant (buffer d'indice)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboi_object_3); PRINT_OPENGL_ERROR();
    //copie des indices sur la carte graphique
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,m.connectivity.size()*sizeof(triangle_index),&m.connectivity[0],GL_STATIC_DRAW); PRINT_OPENGL_ERROR();

    // Nombre de triangles de l'objet 1
    nbr_triangle_object_3 = m.connectivity.size();

    // Chargement de la texture
    load_texture("../data/stegosaurus.tga",&texture_id_object_3);
}


void init_model_4()
{
    // Chargement d'un maillage a partir d'un fichier
    mesh m = load_obj_file("../data/stegosaurus.obj");

    // Affecte une transformation sur les sommets du maillage
    float s = 0.2f;
    mat4 transform = mat4(   s, 0.0f, 0.0f, 0.0f,
                          0.0f,    s, 0.0f,-0.9f,
                          0.0f, 0.0f,   s ,-2.0f,
                          0.0f, 0.0f, 0.0f, 1.0f);
    apply_deformation(&m,transform);

    // Centre la rotation du modele 1 autour de son centre de gravite approximatif
    transformation_model_4.rotation_center = vec3(0.0f,-0.5f,-2.08f);

    // Calcul automatique des normales du maillage
    update_normals(&m);
    // Les sommets sont affectes a une couleur blanche
    fill_color(&m,vec3(1.0f,1.0f,1.0f));

    //attribution d'un buffer de donnees (1 indique la création d'un buffer)
    glGenBuffers(1,&vbo_object_4); PRINT_OPENGL_ERROR();
    //affectation du buffer courant
    glBindBuffer(GL_ARRAY_BUFFER,vbo_object_4); PRINT_OPENGL_ERROR();
    //copie des donnees des sommets sur la carte graphique
    glBufferData(GL_ARRAY_BUFFER,m.vertex.size()*sizeof(vertex_opengl),&m.vertex[0],GL_STATIC_DRAW); PRINT_OPENGL_ERROR();


    //attribution d'un autre buffer de donnees
    glGenBuffers(1,&vboi_object_4); PRINT_OPENGL_ERROR();
    //affectation du buffer courant (buffer d'indice)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboi_object_4); PRINT_OPENGL_ERROR();
    //copie des indices sur la carte graphique
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,m.connectivity.size()*sizeof(triangle_index),&m.connectivity[0],GL_STATIC_DRAW); PRINT_OPENGL_ERROR();

    // Nombre de triangles de l'objet 1
    nbr_triangle_object_4 = m.connectivity.size();

    // Chargement de la texture
    load_texture("../data/stegosaurus.tga",&texture_id_object_4);


}


void init_model_5()
{
	// Chargement d'un maillage a partir d'un fichier
    mesh m = load_obj_file("../data/stegosaurus.obj");

    // Affecte une transformation sur les sommets du maillage
    float s = 0.2f;
    mat4 transform = mat4(   s, 0.0f, 0.0f, 0.0f,
                          0.0f,    s, 0.0f,-0.9f,
                          0.0f, 0.0f,   s ,-2.0f,
                          0.0f, 0.0f, 0.0f, 1.0f);
    apply_deformation(&m,transform);

    // Centre la rotation du modele 1 autour de son centre de gravite approximatif
    transformation_model_5.rotation_center = vec3(0.0f,-0.5f,-2.08f);

    // Calcul automatique des normales du maillage
    update_normals(&m);
    // Les sommets sont affectes a une couleur blanche
    fill_color(&m,vec3(1.0f,1.0f,1.0f));

    //attribution d'un buffer de donnees (1 indique la création d'un buffer)
    glGenBuffers(1,&vbo_object_5); PRINT_OPENGL_ERROR();
    //affectation du buffer courant
    glBindBuffer(GL_ARRAY_BUFFER,vbo_object_5); PRINT_OPENGL_ERROR();
    //copie des donnees des sommets sur la carte graphique
    glBufferData(GL_ARRAY_BUFFER,m.vertex.size()*sizeof(vertex_opengl),&m.vertex[0],GL_STATIC_DRAW); PRINT_OPENGL_ERROR();


    //attribution d'un autre buffer de donnees
    glGenBuffers(1,&vboi_object_5); PRINT_OPENGL_ERROR();
    //affectation du buffer courant (buffer d'indice)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboi_object_5); PRINT_OPENGL_ERROR();
    //copie des indices sur la carte graphique
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,m.connectivity.size()*sizeof(triangle_index),&m.connectivity[0],GL_STATIC_DRAW); PRINT_OPENGL_ERROR();

    // Nombre de triangles de l'objet 1
    nbr_triangle_object_5 = m.connectivity.size();

    // Chargement de la texture
    load_texture("../data/stegosaurus.tga",&texture_id_object_5);


}



void init_model_i(int k)
{
    // Chargement d'un maillage a partir d'un fichier
    mesh m = load_obj_file("../data/Toy_Elephant.obj");

    // Affecte une transformation sur les sommets du maillage
    float s = 0.2f;
    mat4 transform = mat4(   s, 0.0f, 0.0f, 0.0f,
                          0.0f,    s, 0.0f,-0.9f,
                          0.0f, 0.0f,   s ,-2.0f,
                          0.0f, 0.0f, 0.0f, 1.0f);
    apply_deformation(&m,transform);

    // Centre la rotation du modele 1 autour de son centre de gravite approximatif
    transformation_model_tab[k].rotation_center = vec3(0.0f,-0.5f,-2.08f);

    // Calcul automatique des normales du maillage
    update_normals(&m);
    // Les sommets sont affectes a une couleur blanche
    fill_color(&m,vec3(1.0f,1.0f,1.0f));

    //attribution d'un buffer de donnees (1 indique la création d'un buffer)
    glGenBuffers(1,&vbo_object_tab[k]); PRINT_OPENGL_ERROR();
    //affectation du buffer courant
    glBindBuffer(GL_ARRAY_BUFFER,vbo_object_tab[k]); PRINT_OPENGL_ERROR();
    //copie des donnees des sommets sur la carte graphique
    glBufferData(GL_ARRAY_BUFFER,m.vertex.size()*sizeof(vertex_opengl),&m.vertex[0],GL_STATIC_DRAW); PRINT_OPENGL_ERROR();


    //attribution d'un autre buffer de donnees
    glGenBuffers(1,&vboi_object_tab[k]); PRINT_OPENGL_ERROR();
    //affectation du buffer courant (buffer d'indice)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboi_object_tab[k]); PRINT_OPENGL_ERROR();
    //copie des indices sur la carte graphique
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,m.connectivity.size()*sizeof(triangle_index),&m.connectivity[0],GL_STATIC_DRAW); PRINT_OPENGL_ERROR();

    // Nombre de triangles de l'objet 1
    nbr_triangle_object_tab[k] = m.connectivity.size();

    // Chargement de la texture
    load_texture("../data/26145179-gris-naturel-tissu-éponge-en-peluche-serviette-turc-de-plage-de-bain-tissu-texturé-arrière-plan-macro-modèle.tga",&texture_id_object_tab[k]);


}




void load_texture(const char* filename,GLuint *texture_id)
{
    // Chargement d'une texture (seul les textures tga sont supportes)
    Image  *image = image_load_tga(filename);
    if (image) //verification que l'image est bien chargee
    {

        //Creation d'un identifiant pour la texture
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1); PRINT_OPENGL_ERROR();
        glGenTextures(1, texture_id); PRINT_OPENGL_ERROR();

        //Selection de la texture courante a partir de son identifiant
        glBindTexture(GL_TEXTURE_2D, *texture_id); PRINT_OPENGL_ERROR();

        //Parametres de la texture
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); PRINT_OPENGL_ERROR();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); PRINT_OPENGL_ERROR();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); PRINT_OPENGL_ERROR();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); PRINT_OPENGL_ERROR();

        //Envoie de l'image en memoire video
        if(image->type==IMAGE_TYPE_RGB){ //image RGB
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data); PRINT_OPENGL_ERROR();}
        else if(image->type==IMAGE_TYPE_RGBA){ //image RGBA
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->width, image->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->data); PRINT_OPENGL_ERROR();}
        else{
            std::cout<<"Image type not handled"<<std::endl;}

        delete image;
    }
    else
    {
        std::cerr<<"Erreur chargement de l'image, etes-vous dans le bon repertoire?"<<std::endl;
        abort();
    }

    glUniform1i (get_uni_loc(shader_program_id, "texture"), 0); PRINT_OPENGL_ERROR();
}
