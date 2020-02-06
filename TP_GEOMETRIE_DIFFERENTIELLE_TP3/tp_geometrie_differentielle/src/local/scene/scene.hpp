
/** TP 4ETI - CPE Lyon - 2013/2014 */

#pragma once

#ifndef SCENE_HPP
#define SCENE_HPP

#include <GL/gl.h>
#include <GL/glew.h>

#include "../../lib/3d/mat3.hpp"
#include "../../lib/3d/mat2.hpp"
#include "../../lib/3d/vec3.hpp"
#include "../../lib/3d/vec4.hpp"
#include "../../lib/mesh/mesh_parametric.hpp"
#include "../../lib/opengl/mesh_opengl.hpp"
#include "../../lib/interface/camera_matrices.hpp"

#include <vector>


class myWidgetGL;

class scene
{
public:

    scene();

    //explicite
    void build_surface_cylindre();
    //approché
    void build_surface_prof_automatique();
    //explicite
    void build_surface_prof();



    //approché
    void build_surface_boule_automatique();
    //explicite
    void build_surface_boule();
    //approché
    void build_catenoide();
    //explicite 
    void build_surface_catenoide();


    /** \brief Method called only once at the beginning (load off files ...) */
    void load_scene();

    /** \brief Method called at every frame */
    void draw_scene();

    /** Set the pointer to the parent Widget */
    void set_widget(myWidgetGL* widget_param);

    /** Load basic data for the scene */
    void load_common_data();

    /** Calcul la courbure des points du cylindre*/
    cpe::vec4 calcul_courbure_cylindre(float r,float u,float v,int ku, int kv);
    cpe::vec4 calcul_courbure_catenoide_automatique(float u,float v,int ku, int kv);
    cpe::vec4 calcul_courbure_prof(float a, float b, float h, float u, float v, int ku, int kv);
    cpe::vec4 calcul_courbure_boule(float r,float u,float v,int ku, int kv);
    cpe::vec4 calcul_courbure_catenoide(float r,float u,float v,int ku, int kv);

    float x(int ku,int kv);
    float y(int ku,int kv);
    float z(int ku,int kv);
    float x_boule(int ku,int kv);
    float y_boule(int ku,int kv);
    float z_boule(int ku,int kv);
    float x_catenoide(int ku,int kv);
    float y_catenoide(int ku,int kv);
    float z_catenoide(int ku,int kv);


    


private:

    /** Load a texture from a given file and returns its id */
    GLuint load_texture_file(std::string const& filename);

    /** Access to the parent object */
    myWidgetGL* pwidget;

    /** Default id for the texture (white texture) */
    GLuint texture_default;

    /** The id of the shader do draw meshes */
    GLuint shader_program_id;


    cpe::mesh_parametric surface;
    cpe::mesh_opengl surface_opengl;
    cpe::mat2 Is;
    cpe::mat2 IIs;


};

#endif
