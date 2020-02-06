

#include <GL/glew.h>

#include "scene.hpp"
#include "../../lib/opengl/glutils.hpp"

#include "../../lib/perlin/perlin.hpp"
#include "../../lib/interface/camera_matrices.hpp"

#include "../interface/myWidgetGL.hpp"

#include <cmath>

#include <string>
#include <sstream>
#include "../../lib/mesh/mesh_io.hpp"


using namespace cpe;


void scene::build_surface_cylindre()
{
    int const Nu=200;
    int const Nv=200;
    surface.set_plane_xy_unit(Nu,Nv);

    float const u_min = 0.0f;
    float const u_max = 2.0f*M_PI;
    float const v_min = 0.0f;
    float const v_max = 2.0f;

    float const r = 0.2f;
    float min=+1000.0f;
    float max=-1000.0f;

    for(int ku=0 ; ku<Nu ; ++ku)
    {
        for(int kv=0 ; kv<Nv ; ++kv)
        {
            float const u_n = static_cast<float>(ku)/(Nu-1);
            float const v_n = static_cast<float>(kv)/(Nv-1);

            float const u = u_min + u_n * (u_max-u_min);
            float const v = v_min + v_n * (v_max-v_min);


            float const x = r*cos(u);
            float const y = r*sin(u);
            float const z = v;
            vec4 courb=calcul_courbure_cylindre(r,u,v,ku,kv);
            if(courb[2]<min)
                min=courb[2];
            if (courb[2]>max)
                max=courb[2];
            surface.vertex(ku,kv) = {x,y,z};


        }
    }
    for(int ku=0 ; ku<Nu ; ++ku)
    {
        for(int kv=0 ; kv<Nv ; ++kv)
        {
            float const u_n = static_cast<float>(ku)/(Nu-1);
            float const v_n = static_cast<float>(kv)/(Nv-1);

            float const u = u_min + u_n * (u_max-u_min);
            float const v = v_min + v_n * (v_max-v_min);

            vec4 courb=calcul_courbure_cylindre(r,u,v,ku,kv);
            surface.color(ku,kv) = {(courb[2]/(max-min))-min/(max-min),0.0f,0.0f};
        }
    }

}


float scene::x(int ku,int kv)
{
    int const Nu=50;
    int const Nv=50;

    float const a = 1.0f;
    float const b = 1.0f;

    float const u_min = -1.0f;
    float const u_max = 1.0f;
    float const v_min = -1.0f;
    float const v_max = 1.0f;

    float const u_n = static_cast<float>(ku)/(Nu-1);
    float const v_n = static_cast<float>(kv)/(Nv-1);

    float const u = u_min + u_n * (u_max-u_min);
    float const v = v_min + v_n * (v_max-v_min);

    return (a*u);

}
float scene::y(int ku,int kv)
{   
    int const Nu=50;
    int const Nv=50;

    float const a = 1.0f;
    float const b = 1.0f;

    float const u_min = -1.0f;
    float const u_max = 1.0f;
    float const v_min = -1.0f;
    float const v_max = 1.0f;

    float const u_n = static_cast<float>(ku)/(Nu-1);
    float const v_n = static_cast<float>(kv)/(Nv-1);

    float const u = u_min + u_n * (u_max-u_min);
    float const v = v_min + v_n * (v_max-v_min);

    return (b*v);

}
float scene::z(int ku,int kv)
{   

    int const Nu=50;
    int const Nv=50;

    float const u_min = -1.0f;
    float const u_max = 1.0f;
    float const v_min = -1.0f;
    float const v_max = 1.0f;
    float const h = 0.8f;

    float const u_n = static_cast<float>(ku)/(Nu-1);
    float const v_n = static_cast<float>(kv)/(Nv-1);

    float const u = u_min + u_n * (u_max-u_min);
    float const v = v_min + v_n * (v_max-v_min);

    return h*(u*u-v*v);

}

void scene::build_surface_prof()
{
    int const Nu=50;
    int const Nv=50
            ;
    surface.set_plane_xy_unit(Nu,Nv);

    float const u_min = -1.0f;
    float const u_max = 1.0f;
    float const v_min = -1.0f;
    float const v_max = 1.0f;

    float const a = 1.0f;
    float const b = 1.0f;
    float const h = 0.8f;
    float min=+100.0f;
    float max=-100.0f;

    for(int ku=0 ; ku<Nu ; ++ku)
    {
        for(int kv=0 ; kv<Nv ; ++kv)
        {
            float const u_n = static_cast<float>(ku)/(Nu-1);
            float const v_n = static_cast<float>(kv)/(Nv-1);

            float const u = u_min + u_n * (u_max-u_min);
            float const v = v_min + v_n * (v_max-v_min);


            // float const x = a*u;
            // float const y = b*v;
            // float const z = h*(u*u-v*v);

            float const dxu = ((x(ku+1,kv) - x(ku,kv))/(u_n*(u_max-u_min)));
            float const dyu = ((y(ku+1,kv) - y(ku,kv))/(u_n*(u_max-u_min)));
            float const dzu = ((z(ku+1,kv) - z(ku,kv))/(u_n*(u_max-u_min)));

            vec3 Su=vec3(dxu,dyu,dzu);

            float const dxv = ((x(ku,kv+1) - x(ku,kv))/(v_n*(v_max-v_min)));
            float const dyv = ((y(ku,kv+1) - y(ku,kv))/(v_n*(v_max-v_min)));
            float const dzv = ((z(ku,kv+1) - z(ku,kv))/(v_n*(v_max-v_min)));

            vec3 Sv=vec3(dxv,dyv,dzv);

            float const dxuu = (x(ku+1,kv) - 2*x(ku,kv) + x(ku-1,kv)) / (u_n*(u_max-u_min)*u_n*(u_max-u_min));
            float const dyuu = (y(ku+1,kv) - 2*y(ku,kv) + y(ku-1,kv)) / (u_n*(u_max-u_min)*u_n*(u_max-u_min));
            float const dzuu = (z(ku+1,kv) - 2*z(ku,kv) + z(ku-1,kv)) / (u_n*(u_max-u_min)*u_n*(u_max-u_min));

            vec3 Suu=vec3(dxuu,dyuu,dzuu);

            float const dxuv = (((x(ku+1,kv+1) - x(ku,kv+1)) / (u_n*(u_max-u_min))) - ((x(ku+1,kv) - x(ku,kv)) / ((u_n*(u_max-u_min)))) / (v_n*(v_max-v_min)));
            float const dyuv = (((y(ku+1,kv+1) - y(ku,kv+1)) / (u_n*(u_max-u_min))) - ((y(ku+1,kv) - y(ku,kv)) / ((u_n*(u_max-u_min)))) / (v_n*(v_max-v_min)));
            float const dzuv = (((z(ku+1,kv+1) - z(ku,kv+1)) / (u_n*(u_max-u_min))) - ((z(ku+1,kv) - z(ku,kv)) / ((u_n*(u_max-u_min)))) / (v_n*(v_max-v_min)));

            vec3 Suv=vec3(dxuv,dyuv,dzuv);

            float const dxvv = (x(ku,kv+1) - 2* x(ku,kv) + x(ku,kv-1)) / (v_n*(v_max-v_min)*v_n*(v_max-v_min));
            float const dyvv = (y(ku,kv+1) - 2* y(ku,kv) + y(ku,kv-1)) / (v_n*(v_max-v_min)*v_n*(v_max-v_min));
            float const dzvv = (z(ku,kv+1) - 2* z(ku,kv) + z(ku,kv-1)) / (v_n*(v_max-v_min)*v_n*(v_max-v_min));

            vec3 Svv=vec3(dxvv,dyvv,dzvv);

            float const dxvu = (((x(ku+1,kv+1) - x(ku+1,kv)) / (v_n*(v_max-v_min))) - ((x(ku,kv+1) - x(ku,kv)) / ((v_n*(v_max-v_min)))) / (u_n*(v_max-v_min)));
            float const dyvu = (((y(ku+1,kv+1) - y(ku+1,kv)) / (v_n*(v_max-v_min))) - ((y(ku,kv+1) - z(ku,kv)) / ((v_n*(v_max-v_min)))) / (u_n*(v_max-v_min)));
            float const dzvu = (((z(ku+1,kv+1) - z(ku+1,kv)) / (v_n*(v_max-v_min))) - ((z(ku,kv+1) - z(ku,kv)) / ((v_n*(v_max-v_min)))) / (u_n*(v_max-v_min)));

            vec3 Svu=vec3(dxvu,dyvu,dzvu);

            mat2 Is=mat2(dot(Su,Su),-dot(Su,Sv),
                 -dot(Sv,Su),dot(Sv,Sv));

            mat2 IIs=mat2(-dot(cross(Su,Sv),Suu),-dot(cross(Su,Sv),Svu),
                          -dot(cross(Su,Sv),Suv),-dot(cross(Su,Sv),Svv));

            mat2 Ws=IIs*inverse(Is);

            vec2 lambda=eigenvalue(Ws);

            float Ks=det(Ws);

            float Hs=(1.0f/2.0f)*(lambda[0]+lambda[1]);

            //vec4 courb=calcul_courbure_prof(a,b,h,u,v,ku,kv);
            vec4 courb = vec4(lambda[0],lambda[1],Ks,Hs);

            if(courb[3]<min)
                min=courb[3];
            if (courb[3]>max)
                max=courb[3];
            surface.vertex(ku,kv) = {x(ku,kv),y(ku,kv),z(ku,kv)};


        }
    }
    for(int ku=0 ; ku<Nu ; ++ku)
    {
        for(int kv=0 ; kv<Nv ; ++kv)
        {
            float const u_n = static_cast<float>(ku)/(Nu-1);
            float const v_n = static_cast<float>(kv)/(Nv-1);

            float const u = u_min + u_n * (u_max-u_min);
            float const v = v_min + v_n * (v_max-v_min);

            float const dxu = ((x(ku+1,kv) - x(ku,kv))/(u_n*(u_max-u_min)));
            float const dyu = ((y(ku+1,kv) - y(ku,kv))/(u_n*(u_max-u_min)));
            float const dzu = ((z(ku+1,kv) - z(ku,kv))/(u_n*(u_max-u_min)));

            vec3 Su=vec3(dxu,dyu,dzu);

            float const dxv = ((x(ku,kv+1) - x(ku,kv))/(v_n*(v_max-v_min)));
            float const dyv = ((y(ku,kv+1) - y(ku,kv))/(v_n*(v_max-v_min)));
            float const dzv = ((z(ku,kv+1) - z(ku,kv))/(v_n*(v_max-v_min)));

            vec3 Sv=vec3(dxv,dyv,dzv);

            float const dxuu = (x(ku+1,kv) - 2*x(ku,kv) + x(ku-1,kv)) / (u_n*(u_max-u_min)*u_n*(u_max-u_min));
            float const dyuu = (y(ku+1,kv) - 2*y(ku,kv) + y(ku-1,kv)) / (u_n*(u_max-u_min)*u_n*(u_max-u_min));
            float const dzuu = (z(ku+1,kv) - 2*z(ku,kv) + z(ku-1,kv)) / (u_n*(u_max-u_min)*u_n*(u_max-u_min));

            vec3 Suu=vec3(dxuu,dyuu,dzuu);

            float const dxuv = (((x(ku+1,kv+1) - x(ku,kv+1)) / (u_n*(u_max-u_min))) - ((x(ku+1,kv) - x(ku,kv)) / ((u_n*(u_max-u_min)))) / (v_n*(v_max-v_min)));
            float const dyuv = (((y(ku+1,kv+1) - y(ku,kv+1)) / (u_n*(u_max-u_min))) - ((y(ku+1,kv) - y(ku,kv)) / ((u_n*(u_max-u_min)))) / (v_n*(v_max-v_min)));
            float const dzuv = (((z(ku+1,kv+1) - z(ku,kv+1)) / (u_n*(u_max-u_min))) - ((z(ku+1,kv) - z(ku,kv)) / ((u_n*(u_max-u_min)))) / (v_n*(v_max-v_min)));

            vec3 Suv=vec3(dxuv,dyuv,dzuv);

            float const dxvv = (x(ku,kv+1) - 2* x(ku,kv) + x(ku,kv-1)) / (v_n*(v_max-v_min)*v_n*(v_max-v_min));
            float const dyvv = (y(ku,kv+1) - 2* y(ku,kv) + y(ku,kv-1)) / (v_n*(v_max-v_min)*v_n*(v_max-v_min));
            float const dzvv = (z(ku,kv+1) - 2* z(ku,kv) + z(ku,kv-1)) / (v_n*(v_max-v_min)*v_n*(v_max-v_min));

            vec3 Svv=vec3(dxvv,dyvv,dzvv);

            float const dxvu = (((x(ku+1,kv+1) - x(ku+1,kv)) / (v_n*(v_max-v_min))) - ((x(ku,kv+1) - x(ku,kv)) / ((v_n*(v_max-v_min)))) / (u_n*(v_max-v_min)));
            float const dyvu = (((y(ku+1,kv+1) - y(ku+1,kv)) / (v_n*(v_max-v_min))) - ((y(ku,kv+1) - z(ku,kv)) / ((v_n*(v_max-v_min)))) / (u_n*(v_max-v_min)));
            float const dzvu = (((z(ku+1,kv+1) - z(ku+1,kv)) / (v_n*(v_max-v_min))) - ((z(ku,kv+1) - z(ku,kv)) / ((v_n*(v_max-v_min)))) / (u_n*(v_max-v_min)));

            vec3 Svu=vec3(dxvu,dyvu,dzvu);

            mat2 Is=mat2(dot(Su,Su),-dot(Su,Sv),
                 -dot(Sv,Su),dot(Sv,Sv));

            mat2 IIs=mat2(-dot(cross(Su,Sv),Suu),-dot(cross(Su,Sv),Svu),
                          -dot(cross(Su,Sv),Suv),-dot(cross(Su,Sv),Svv));

            mat2 Ws=IIs*inverse(Is);

            vec2 lambda=eigenvalue(Ws);

            float Ks=det(Ws);

            float Hs=(1.0f/2.0f)*(lambda[0]+lambda[1]);

            //vec4 courb=calcul_courbure_prof(a,b,h,u,v,ku,kv);
            vec4 courb = vec4(lambda[0],lambda[1],Ks,Hs);

            //vec4 courb=calcul_courbure_prof(a,b,h,u,v,ku,kv);
            surface.color(ku,kv) = {(courb[3]/(max-min))-min/(max-min),0.0f,0.0f};
        }
    }

}


void scene::load_scene()
{
    load_common_data();


    //build_surface_cylindre();
    build_surface_prof();

    surface.fill_normal();
    surface.fill_empty_field_by_default();

    surface_opengl.fill_vbo(surface);

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


    glBindTexture(GL_TEXTURE_2D,texture_default);  PRINT_OPENGL_ERROR();
    surface_opengl.draw();

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

void scene::load_common_data()
{
    texture_default=load_texture_file("data/white.jpg");
    shader_program_id = read_shader("shaders/shader_mesh.vert",
                                    "shaders/shader_mesh.frag"); PRINT_OPENGL_ERROR();
}

vec4 scene::calcul_courbure_cylindre(float r, float u, float v, int ku, int kv)
{
    vec3 Su=vec3(-r*sin(u),r*cos(u),0);
    vec3 Sv=vec3(0,0,1);
    vec3 Suu=vec3(-r*cos(u),-r*sin(u),0);
    vec3 Svv=vec3(0,0,0);
    vec3 Suv=vec3(0,0,0);
    vec3 Svu=vec3(0,0,0);
    mat2 Is=mat2(dot(Su,Su),dot(Su,Sv),
                 dot(Sv,Su),dot(Sv,Sv));
    mat2 IIs=mat2(-dot(cross(Su,Sv),Suu),-dot(cross(Su,Sv),Svu),
                  -dot(cross(Su,Sv),Suv),-dot(cross(Su,Sv),Svv));
    mat2 Ws=IIs*inverse(Is);
    vec2 lambda=eigenvalue(Ws);
    float Ks=det(Ws);
    float Hs=(1.0f/2.0f)*(lambda[0]+lambda[1]);
    std::cout<<lambda[0]<<" "<<lambda[1]<<" "<<Ks<<" "<<Hs<<std::endl;
    return vec4(lambda[0],lambda[1],Ks,Hs);
}

vec4 scene::calcul_courbure_prof(float a, float b, float h, float u, float v, int ku, int kv)
{
    vec3 Su=vec3(a,0,2*u*h);
    vec3 Sv=vec3(0,b,2*v*h);
    vec3 Suu=vec3(0,0,2*h);
    vec3 Svv=vec3(0,0,2*h);
    vec3 Suv=vec3(0,0,0);
    vec3 Svu=vec3(0,0,0);
    mat2 Is=mat2(dot(Su,Su),dot(Su,Sv),
                 dot(Sv,Su),dot(Sv,Sv));
    mat2 IIs=mat2(-dot(cross(Su,Sv),Suu),-dot(cross(Su,Sv),Svu),
                  -dot(cross(Su,Sv),Suv),-dot(cross(Su,Sv),Svv));
    mat2 Ws=IIs*inverse(Is);
    vec2 lambda=eigenvalue(Ws);
    float Ks=det(Ws);
    float Hs=(1.0f/2.0f)*(lambda[0]+lambda[1]);
    std::cout<<lambda[0]<<" "<<lambda[1]<<" "<<Ks<<" "<<Hs<<std::endl;
    return vec4(lambda[0],lambda[1],Ks,Hs);
}
