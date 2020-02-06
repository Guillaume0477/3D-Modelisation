

#include <GL/glew.h>

#include "scene.hpp"

#include "../../lib/opengl/glutils.hpp"
#include "../../lib/perlin/perlin.hpp"
#include "../../lib/interface/camera_matrices.hpp"
#include "../interface/myWidgetGL.hpp"
#include "../../lib/mesh/mesh_io.hpp"

#include <cmath>
#include <string>
#include <sstream>

using namespace cpe;

//*****************************************//
// Parameters                              //
//*****************************************//


/*Paramètres du sol*/
/*const float x_min1=-0.75f;
const float x_max1=1.0f;
const float y_min1=-2.0f;
const float y_max1=2.25f;
const float x_1=0.0f;
const float y_1=0.0f;
//meme nombre nombre pour pas int
const int Nu_1=7;
const int Nv_1=17;

/*Paramètres de la piste d'atterissage*/// AVEC grANDEUR CENTRÉ AUTOUR DE X_1 ET Y_1
/*const float x_max_land=0.25f;
const float y_min_land=-1.5f;
const float y_max_land=1.5f;
const int Nu_land=2;
const int Nv_land=2;
*/


/*Paramètres du sol*/
const float x_min1=-3.0f;
const float x_max1=3.0f;
const float y_min1=-3.0;
const float y_max1=2.0f;

//meme nombre nombre pour pas int
const int Nu_1=150;
const int Nv_1=150;

/*Paramètres de la piste d'atterissage*/// AVEC grANDEUR CENTRÉ AUTOUR DE X_1 ET Y_1
const float x_min_land=-0.25f;
const float x_max_land=0.25f;
const float y_min_land=-1.5f;
const float y_max_land=1.5f;
const int Nu_land=2;
const int Nv_land=2;

/*Paramètres de la tour de controle*/
const int N_tour=10;
const float x0_tour=x_max_land;
const float y0_tour=y_max_land;
const float h_tour=0.8f;
const float r_tour=0.1f;

/*Paramètres du dino mutant*/
const float x_dino=x_max_land-0.2f;
const float y_dino=y_max_land-0.2f;
int gonflement_dino=1;
int compteur_dino=0;

void scene::load_scene()
{

    //*****************************************//
    // Preload default structure               //
    //*****************************************//
    texture_default = load_texture_file("data/white.jpg"); PRINT_OPENGL_ERROR();
    shader_program_id = read_shader("shaders/shader_mesh.vert",
                                    "shaders/shader_mesh.frag"); PRINT_OPENGL_ERROR();


    //*****************************************//;
    // OBJ Mesh                                //
    //*****************************************//#ifndef MESH_HPP
#define MESH_HPP
    texture_dinosaur=load_texture_file("data/stegosaurus.jpg");PRINT_OPENGL_ERROR();
    mesh_dinosaur=load_mesh_file("data/stegosaurus.obj");
    mesh_dinosaur.transform_apply_auto_scale_and_center();
    mesh_dinosaur_opengl.fill_vbo(mesh_dinosaur);

    //*****************************************//
    // OFF Mesh                                //
    //*****************************************#ifndef MESH_HPP
#define MESH_HPP//
    mesh_camel=load_mesh_file("data/camel.off");
    mesh_camel.transform_apply_auto_scale_and_center();
    mesh_camel.transform_apply_scale(0.5f);
    mesh_camel.transform_apply_rotation({1.0f,0.0f,0.0f},-M_PI/2.0f);
    mesh_camel.transform_apply_rotation({0.0f,1.0f,0.0f}, 5*M_PI/6.0f);
    mesh_camel.transform_apply_translation({-0.55f,-0.0f,0.1f});
    mesh_camel.fill_color_xyz();
    mesh_camel_opengl.fill_vbo(mesh_camel);


#define MESH_HPP//
    mesh_dino=load_mesh_file("data/dino_0.off");
    mesh_dino.transform_apply_auto_scale_and_center();
    mesh_dino.transform_apply_scale(0.5f);
    mesh_dino.transform_apply_rotation({1.0f,0.0f,0.0f},-M_PI/2.0f);
    mesh_dino.transform_apply_rotation({0.0f,1.0f,0.0f}, 8*M_PI/6.0f);
    mesh_dino.transform_apply_translation({x_dino,-0.0f,y_dino});


    mesh_dino.fill_color_xyz();
    mesh_dino_opengl.fill_vbo(mesh_dino);

//    //*****************************************//
//    // Generate user defined mesh              //
//    //*****************************************//

//    mesh_ground.add_vertex( {-1.0f,-0.25f,-1.0f} );
//    mesh_ground.add_vertex( {-1.0f,-0.25f, 1.0f} );
//    mesh_ground.add_vertex( { 1.0f,-0.25f, 1.0f} );
//    mesh_ground.add_vertex( { 1.0f,-0.25f,-1.0f} );
//    //note: we can use mesh.add_vertex({x,y,z})
//    //          or mesh.add_vertex(vec3(x,y,z));

//    mesh_ground.add_triangle_index({0,2,1});
//    mesh_ground.add_triangle_index({0,3,2});
//    mesh_ground.fill_empty_field_by_default();
//    mesh_ground.fill_color( {0.8,0.9,0.8} );

//    mesh_ground_opengl.fill_vbo(mesh_ground);

    //*****************************************//
    // Generate user defined mesh              //
    //*****************************************//
    //*****************************************//;
    // OBJ Mesh                                //
    //*****************************************//#ifndef MESH_HPP
#define MESH_HPP
    texture_eau=load_texture_file("data/Eau_claire.jpg");PRINT_OPENGL_ERROR();
    texture_landing=load_texture_file("data/landing.jpg");PRINT_OPENGL_ERROR();
    texture_control_tower=load_texture_file("data/gris.jpg");PRINT_OPENGL_ERROR();

    //*****************************************//
    // OFF Mesh                                //
    //*****************************************#ifndef MESH_HPP
    init_sol(x_min1,x_max1,y_min1,y_max1,Nu_1,Nv_1);PRINT_OPENGL_ERROR();
    init_landing(x_min_land, x_max_land, y_min_land, y_max_land, Nu_land, Nv_land);PRINT_OPENGL_ERROR();
    init_control_tower(r_tour, h_tour , N_tour, x0_tour, y0_tour);PRINT_OPENGL_ERROR();

}


void scene::init_sol(float xmin,float xmax,float ymin,float ymax,int Nu,int Nv){
    //*****************************************//
    // Generate user defined mesh              //
    //*****************************************//
    perlin perl=perlin();
    const float pas_u=(xmax-xmin)/Nu;PRINT_OPENGL_ERROR();
    const float pas_v=(ymax-ymin)/Nv;PRINT_OPENGL_ERROR();
    for (int kv=0; kv<Nv; ++kv){
        for (int ku=0; ku<Nu; ++ku){
            //1 et 5 dimention piste 
            //std::cout<<"hello"<<ku*pas_u+xmin<<std::endl;
            //std::cout<<"adieu"<<kv*pas_v+ymin<<std::endl;
            if(ku*pas_u+xmin>=x_min_land && ku*pas_u+xmin<=x_max_land && kv*pas_v+ymin>=y_min_land && kv*pas_v+ymin<=y_max_land){
                mesh_ground.add_vertex({ku*pas_u+xmin,-0.25,kv*pas_v+ymin});PRINT_OPENGL_ERROR();
                mesh_ground.add_texture_coord(vec2(ku,kv));
            }
            else{
                mesh_ground.add_vertex({ku*pas_u+xmin,(perl(vec2(ku*pas_u+xmin,kv*pas_v+ymin))-1.0)/2,kv*pas_v+ymin});PRINT_OPENGL_ERROR();
                mesh_ground.add_texture_coord(vec2(ku,kv));
            }
        }
    }
    for (int kv=0; kv<Nv-1; ++kv){
        for (int ku=0; ku<Nu-1; ++ku){
            mesh_ground.add_triangle_index({ku+Nu*kv,ku+Nu*kv+1,ku+Nu*kv+Nu+1});PRINT_OPENGL_ERROR();
            mesh_ground.add_triangle_index({ku+Nu*kv,ku+Nu*kv+Nu,ku+Nu*kv+Nu+1});PRINT_OPENGL_ERROR();
        }
    }
    mesh_ground.fill_empty_field_by_default(); PRINT_OPENGL_ERROR();
  //  mesh_ground.fill_color( {0,0.6,1.0} ); PRINT_OPENGL_ERROR();
    mesh_ground.fill_color_xyz();
    mesh_ground_opengl.fill_vbo(mesh_ground); PRINT_OPENGL_ERROR();

}

void scene::init_landing(float xmin, float xmax, float ymin, float ymax, int Nu, int Nv){
    const float pas_u=2*(xmax-xmin)/Nu;PRINT_OPENGL_ERROR();
    const float pas_v=2*(ymax-ymin)/Nv;PRINT_OPENGL_ERROR();
    for (int kv=0; kv<Nv; ++kv){
        for (int ku=0; ku<Nu; ++ku){
                //std::cout<<"hello2 "<<ku*pas_u+xmin<<std::endl;
                //std::cout<<"adieu2 "<<kv*pas_v+ymin<<std::endl;
                mesh_landing.add_vertex({ku*pas_u+xmin,-0.22f,kv*pas_v+ymin});PRINT_OPENGL_ERROR();
                mesh_landing.add_texture_coord(vec2(ku,kv));
        }
    }
    for (int kv=0; kv<Nv-1; ++kv){
        for (int ku=0; ku<Nu-1; ++ku){
            mesh_landing.add_triangle_index({ku+Nu*kv,ku+Nu*kv+1,ku+Nu*kv+Nu+1});PRINT_OPENGL_ERROR();
            mesh_landing.add_triangle_index({ku+Nu*kv,ku+Nu*kv+Nu,ku+Nu*kv+Nu+1});PRINT_OPENGL_ERROR();
        }
    }
    mesh_landing.fill_empty_field_by_default(); PRINT_OPENGL_ERROR();
    mesh_landing.fill_color( {0,0.6,1.0} ); PRINT_OPENGL_ERROR();
    mesh_landing_opengl.fill_vbo(mesh_landing); PRINT_OPENGL_ERROR();
}

void scene::init_control_tower(float r, float h ,int N, float x0, float y0){
    const float pas_theta=(2*M_PI)/N;PRINT_OPENGL_ERROR();
    for (int k=0;k<N;++k){
        mesh_control_tower.add_vertex({x0+r*cos(k*pas_theta),-0.25f,y0+r*sin(k*pas_theta)});PRINT_OPENGL_ERROR();
        mesh_control_tower.add_vertex({x0+(r+h/10)*cos(k*pas_theta),-0.25f+h,y0+(r+h/10)*sin(k*pas_theta)});PRINT_OPENGL_ERROR();
        if(k!=(N-1)){
            mesh_control_tower.add_triangle_index({2*k,2*k+1,2*k+2});PRINT_OPENGL_ERROR();
            mesh_control_tower.add_triangle_index({2*k+1,2*k+2,2*k+3});PRINT_OPENGL_ERROR();
        }
        else{
            mesh_control_tower.add_triangle_index({2*k,2*k+1,0});PRINT_OPENGL_ERROR();
            mesh_control_tower.add_triangle_index({2*k+1,0,1});PRINT_OPENGL_ERROR();
        }
    }
        mesh_control_tower.fill_empty_field_by_default(); PRINT_OPENGL_ERROR();
        mesh_control_tower.fill_color_xyz(); PRINT_OPENGL_ERROR();
        mesh_control_tower_opengl.fill_vbo(mesh_control_tower); PRINT_OPENGL_ERROR();
}

void scene::draw_scene()
{
    //Setup uniform parameters
    glUseProgram(shader_program_id);                                                                           PRINT_OPENGL_ERROR();

    //Get cameras parameters (modelview,projection,normal).
    camera_matrices const& cam=pwidget->camera();

    //Set Uniform data to GPU
    glUniformMatrix4fv(get_uni_loc(shader_program_id,"camera_modelview"),1,false,cam.modelview.pointer());     PRINT_OPENGL_ERROR();
    glUniformMatrix4fv(get_uni_loc(shader_program_id,"camera_projection"),1,false,cam.projection.pointer());   PRINT_OPENGL_ERROR();
    glUniformMatrix4fv(get_uni_loc(shader_program_id,"normal_matrix"),1,false,cam.normal.pointer());           PRINT_OPENGL_ERROR();


    //Draw the meshes
    glBindTexture(GL_TEXTURE_2D,texture_dinosaur); PRINT_OPENGL_ERROR();
    mesh_dinosaur_opengl.draw();PRINT_OPENGL_ERROR();

    glBindTexture(GL_TEXTURE_2D,texture_default);  PRINT_OPENGL_ERROR();
    mesh_camel_opengl.draw();PRINT_OPENGL_ERROR();


    int N_vertex = mesh_dino.size_vertex();
  

    
    compteur_dino=compteur_dino+1;

    for(int k=0;k<N_vertex;k++)
    {
        mesh_dino.vertex(k)=mesh_dino.vertex(k)+0.002*gonflement_dino*mesh_dino.normal(k);
    }

    //if(compteur_dino==6){
    if(compteur_dino==6){
        gonflement_dino=-gonflement_dino;
        compteur_dino=0;

    }


    mesh_dino_opengl.fill_vbo(mesh_dino);
    glBindTexture(GL_TEXTURE_2D,texture_default);  PRINT_OPENGL_ERROR();
    mesh_dino_opengl.draw();PRINT_OPENGL_ERROR();


    glBindTexture(GL_TEXTURE_2D,texture_eau); PRINT_OPENGL_ERROR();
    mesh_ground_opengl.draw();PRINT_OPENGL_ERROR();

    glBindTexture(GL_TEXTURE_2D,texture_landing); PRINT_OPENGL_ERROR();
    mesh_landing_opengl.draw();PRINT_OPENGL_ERROR();

    glBindTexture(GL_TEXTURE_2D,texture_control_tower); PRINT_OPENGL_ERROR();
    mesh_control_tower_opengl.draw();PRINT_OPENGL_ERROR();
}


scene::scene()
    :shader_program_id(0)
{}


GLuint scene::load_texture_file(std::string const& filename)
{
    return pwidget->load_texture_file(filename);
}

void scene::set_widget(myWidgetGL* widget_param)
{
    pwidget=widget_param;
}


