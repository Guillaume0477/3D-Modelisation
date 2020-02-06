

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

float scene::x_boule(int ku,int kv)
{
    int const Nu=50;
    int const Nv=50;


    float const u_min = -M_PI;
    float const u_max = M_PI;
    float const v_min = -M_PI/2;
    float const v_max = M_PI/2;

    float const r = 1;

    float const u_n = static_cast<float>(ku)/(Nu-1);
    float const v_n = static_cast<float>(kv)/(Nv-1);

    float const u = u_min + u_n * (u_max-u_min);
    float const v = v_min + v_n * (v_max-v_min);

    return (r*cos(u)*cos(v));

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

float scene::y_boule(int ku,int kv)
{
    int const Nu=50;
    int const Nv=50;


    float const u_min = -M_PI;
    float const u_max = M_PI;
    float const v_min = -M_PI/2;
    float const v_max = M_PI/2;

    float const r = 1;

    float const u_n = static_cast<float>(ku)/(Nu-1);
    float const v_n = static_cast<float>(kv)/(Nv-1);

    float const u = u_min + u_n * (u_max-u_min);
    float const v = v_min + v_n * (v_max-v_min);

    return (r*sin(u)*cos(v));

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

float scene::z_boule(int ku,int kv)
{
    int const Nu=50;
    int const Nv=50;


    float const u_min = -M_PI;
    float const u_max = M_PI;
    float const v_min = -M_PI/2;
    float const v_max = M_PI/2;

    float const r = 1;

    float const u_n = static_cast<float>(ku)/(Nu-1);
    float const v_n = static_cast<float>(kv)/(Nv-1);

    float const u = u_min + u_n * (u_max-u_min);
    float const v = v_min + v_n * (v_max-v_min);

    return (r*sin(v));

}


float scene::x_catenoide(int ku,int kv)
{
    int const Nu=50;
    int const Nv=50;


    float const u_min = -1.5f;
    float const u_max = 1.5f;
    float const v_min = 0.0f;
    float const v_max = 2.0*M_PI;

    float const r=1.0f;

    float const u_n = static_cast<float>(ku)/(Nu-1);
    float const v_n = static_cast<float>(kv)/(Nv-1);

    float const u = u_min + u_n * (u_max-u_min);
    float const v = v_min + v_n * (v_max-v_min);

    return (r*cosh(u)*cos(v));

}

float scene::y_catenoide(int ku,int kv)
{
    int const Nu=50;
    int const Nv=50;


    float const u_min = -1.5f;
    float const u_max = 1.5f;
    float const v_min = 0.0f;
    float const v_max = 2.0*M_PI;

    float const r=1.0f;

    float const u_n = static_cast<float>(ku)/(Nu-1);
    float const v_n = static_cast<float>(kv)/(Nv-1);

    float const u = u_min + u_n * (u_max-u_min);
    float const v = v_min + v_n * (v_max-v_min);

    return (r*cosh(u)*sin(v));

}

float scene::z_catenoide(int ku,int kv)
{
    int const Nu=50;
    int const Nv=50;


    float const u_min = -1.5f;
    float const u_max = 1.5f;
    float const v_min = 0.0f;
    float const v_max = 2.0*M_PI;

    float const r=1.0f;

    float const u_n = static_cast<float>(ku)/(Nu-1);
    float const v_n = static_cast<float>(kv)/(Nv-1);

    float const u = u_min + u_n * (u_max-u_min);
    float const v = v_min + v_n * (v_max-v_min);

    return (r*(u));
}

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


            float const x = a*u;
            float const y = b*v;
            float const z = h*(u*u-v*v);
            vec4 courb=calcul_courbure_prof(a,b,h,u,v,ku,kv);


            if(courb[3]<min)
                min=courb[3];
            if (courb[3]>max)
                max=courb[3];
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

            vec4 courb=calcul_courbure_prof(a,b,h,u,v,ku,kv);
        std::cout<<min<<",,"<<max<<std::endl;

            surface.color(ku,kv) = {(courb[3]/(max-min))-min/(max-min),0.0f,0.0f};
        }
    }

}

void scene::build_surface_prof_automatique()
{
    int const Nu=50;
    int const Nv=50;
            
    surface.set_plane_xy_unit(Nu,Nv);

    float const u_min = -1.0f;
    float const u_max = 1.0f;
    float const v_min = -1.0f;
    float const v_max = 1.0f;

    float const a = 1.0f;
    float const b = 1.0f;
    float const h = 0.8f;
    float min=+1000.0f;
    float max=-1000.0f;

    for(int ku=0 ; ku<Nu ; ++ku)
    {
        for(int kv=0 ; kv<Nv ; ++kv)
        {
            float const u_n = static_cast<float>(ku)/(Nu-1);
            float const v_n = static_cast<float>(kv)/(Nv-1);

            float const pas_u = (u_max-u_min)/(Nu-1);
            float const pas_v = (v_max-v_min)/(Nv-1);



            float const u = u_min + u_n * (u_max-u_min);
            float const v = v_min + v_n * (v_max-v_min);


            if ((ku != 0) && (ku != Nu-1) && (kv != 0) && (kv != Nv-1)) {

            

                float const dxu = ((x(ku+1,kv) - x(ku,kv))/pas_u);
                float const dyu = ((y(ku+1,kv) - y(ku,kv))/pas_u);
                float const dzu = ((z(ku+1,kv) - z(ku,kv))/pas_u);

                vec3 Su=vec3(dxu,dyu,dzu);

                float const dxv = ((x(ku,kv+1) - x(ku,kv))/pas_u);
                float const dyv = ((y(ku,kv+1) - y(ku,kv))/pas_u);
                float const dzv = ((z(ku,kv+1) - z(ku,kv))/pas_u);

                vec3 Sv=vec3(dxv,dyv,dzv);

                float const dxuu = (x(ku+1,kv) - 2*x(ku,kv) + x(ku-1,kv)) / (pas_u*pas_u);
                float const dyuu = (y(ku+1,kv) - 2*y(ku,kv) + y(ku-1,kv)) / (pas_u*pas_u);
                float const dzuu = (z(ku+1,kv) - 2*z(ku,kv) + z(ku-1,kv)) / (pas_u*pas_u);

                vec3 Suu=vec3(dxuu,dyuu,dzuu);

                float const dxuv = ((((x(ku+1,kv+1) - x(ku,kv+1)) / (pas_u)) - ((x(ku+1,kv) - x(ku,kv)) / ((pas_u)))) / (pas_v));
                float const dyuv = ((((y(ku+1,kv+1) - y(ku,kv+1)) / (pas_u)) - ((y(ku+1,kv) - y(ku,kv)) / ((pas_u)))) / (pas_v));
                float const dzuv = ((((z(ku+1,kv+1) - z(ku,kv+1)) / (pas_u)) - ((z(ku+1,kv) - z(ku,kv)) / ((pas_u)))) / (pas_v));

                vec3 Suv=vec3(dxuv,dyuv,dzuv);

                float const dxvv = (x(ku,kv+1) - 2* x(ku,kv) + x(ku,kv-1)) / (pas_v*pas_v);
                float const dyvv = (y(ku,kv+1) - 2* y(ku,kv) + y(ku,kv-1)) / (pas_v*pas_v);
                float const dzvv = (z(ku,kv+1) - 2* z(ku,kv) + z(ku,kv-1)) / (pas_v*pas_v);

                vec3 Svv=vec3(dxvv,dyvv,dzvv);

                float const dxvu = ((((x(ku+1,kv+1) - x(ku+1,kv)) / (pas_v)) - ((x(ku,kv+1) - x(ku,kv)) / ((pas_v)))) / (pas_u));
                float const dyvu = ((((y(ku+1,kv+1) - y(ku+1,kv)) / (pas_v)) - ((y(ku,kv+1) - y(ku,kv)) / ((pas_v)))) / (pas_u));
                float const dzvu = ((((z(ku+1,kv+1) - z(ku+1,kv)) / (pas_v)) - ((z(ku,kv+1) - z(ku,kv)) / ((pas_v)))) / (pas_u));


                vec3 Svu=vec3(dxvu,dyvu,dzvu);

                mat2 Is=mat2(dot(Su,Su),-dot(Su,Sv),
                             -dot(Sv,Su),dot(Sv,Sv));

                mat2 IIs=mat2(-dot(cross(Su,Sv),Suu),-dot(cross(Su,Sv),Suv),
                              -dot(cross(Su,Sv),Suv),dot(cross(Su,Sv),Svv));

                mat2 Ws=IIs*inverse(Is);


                std::cout<<"Su"<<std::endl;
                std::cout<<Su<<std::endl;
                std::cout<<"Sv"<<std::endl;
                std::cout<<Sv<<std::endl;
                std::cout<<"Suu"<<std::endl;
                std::cout<<Suu<<std::endl;
                std::cout<<"Svv"<<std::endl;
                std::cout<<Svv<<std::endl;
                std::cout<<"Suv"<<std::endl;
                std::cout<<Suv<<std::endl;
                std::cout<<"Svu"<<std::endl;
                std::cout<<Svu<<std::endl;
                std::cout<<"Ws"<<std::endl;
                std::cout<<Ws<<std::endl;

                vec2 lambda=eigenvalue(Ws);

                std::cout<<"lambda"<<std::endl;
                std::cout<<lambda<<std::endl;

                float Ks=det(Ws);

                float Hs=(1.0f/2.0f)*(lambda[0]+lambda[1]);

                //vec4 courb=calcul_courbure_prof(a,b,h,u,v,ku,kv);
                vec4 courb = vec4(lambda[0],lambda[1],Ks,Hs);

                if(courb[3]<min)
                    min=courb[3];
                if (courb[3]>max)
                    max=courb[3];

                std::cout<<"ku"<<std::endl;
                std::cout<<ku<<"  "<<kv<<std::endl;

                std::cout<<"min"<<std::endl;
                std::cout<<min<<",,"<<max<<std::endl;

            

            }

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

            float const pas_u = (u_max-u_min)/(Nu-1);
            float const pas_v = (v_max-v_min)/(Nv-1);

            if ((ku != 0) && (ku != Nu-1) && (kv != 0) && (kv != Nv-1)) {

            

                float const dxu = ((x(ku+1,kv) - x(ku,kv))/pas_u);
                float const dyu = ((y(ku+1,kv) - y(ku,kv))/pas_u);
                float const dzu = ((z(ku+1,kv) - z(ku,kv))/pas_u);

                vec3 Su=vec3(dxu,dyu,dzu);

                float const dxv = ((x(ku,kv+1) - x(ku,kv))/pas_v);
                float const dyv = ((y(ku,kv+1) - y(ku,kv))/pas_v);
                float const dzv = abs(((z(ku,kv+1) - z(ku,kv))/pas_v));

                vec3 Sv=vec3(dxv,dyv,dzv);

                float const dxuu = (x(ku+1,kv) - 2*x(ku,kv) + x(ku-1,kv)) / (pas_u*pas_u);
                float const dyuu = (y(ku+1,kv) - 2*y(ku,kv) + y(ku-1,kv)) / (pas_u*pas_u);
                float const dzuu = (z(ku+1,kv) - 2*z(ku,kv) + z(ku-1,kv)) / (pas_u*pas_u);

                vec3 Suu=vec3(dxuu,dyuu,dzuu);

                float const dxuv = ((((x(ku+1,kv+1) - x(ku,kv+1)) / (pas_u)) - ((x(ku+1,kv) - x(ku,kv)) / ((pas_u)))) / (pas_v));
                float const dyuv = ((((y(ku+1,kv+1) - y(ku,kv+1)) / (pas_u)) - ((y(ku+1,kv) - y(ku,kv)) / ((pas_u)))) / (pas_v));
                float const dzuv = ((((z(ku+1,kv+1) - z(ku,kv+1)) / (pas_u)) - ((z(ku+1,kv) - z(ku,kv)) / ((pas_u)))) / (pas_v));

                vec3 Suv=vec3(dxuv,dyuv,dzuv);

                float const dxvv = (x(ku,kv+1) - 2* x(ku,kv) + x(ku,kv-1)) / (pas_v*pas_v);
                float const dyvv = (y(ku,kv+1) - 2* y(ku,kv) + y(ku,kv-1)) / (pas_v*pas_v);
                float const dzvv = abs((z(ku,kv+1) - 2* z(ku,kv) + z(ku,kv-1)) / (pas_v*pas_v));

                vec3 Svv=vec3(dxvv,dyvv,dzvv);

                float const dxvu = ((((x(ku+1,kv+1) - x(ku+1,kv)) / (pas_v)) - ((x(ku,kv+1) - x(ku,kv)) / ((pas_v)))) / (pas_u));
                float const dyvu = ((((y(ku+1,kv+1) - y(ku+1,kv)) / (pas_v)) - ((y(ku,kv+1) - y(ku,kv)) / ((pas_v)))) / (pas_u));
                float const dzvu = ((((z(ku+1,kv+1) - z(ku+1,kv)) / (pas_v)) - ((z(ku,kv+1) - z(ku,kv)) / ((pas_v)))) / (pas_u));


                vec3 Svu=vec3(dxvu,dyvu,dzvu);

                mat2 Is=mat2(dot(Su,Su),-dot(Su,Sv),
                             -dot(Sv,Su),dot(Sv,Sv));

                std::cout<<"Is"<<std::endl;
                std::cout<<Is<<std::endl;

                mat2 IIs=mat2((- dot(cross(Su,Sv),Suu)),(- dot(cross(Su,Sv),Suv)),
                              (- dot(cross(Su,Sv),Suv)),(- dot(cross(Su,Sv),Svv)));
                std::cout<<"IIs"<<std::endl;
                std::cout<<IIs<<std::endl;


                mat2 Ws=IIs*inverse(Is);


                std::cout<<"Su"<<std::endl;
                std::cout<<Su<<std::endl;
                std::cout<<"Sv"<<std::endl;
                std::cout<<Sv<<std::endl;
                std::cout<<"Suu"<<std::endl;
                std::cout<<Suu<<std::endl;
                std::cout<<"Svv"<<std::endl;
                std::cout<<Svv<<std::endl;
                std::cout<<"Suv"<<std::endl;
                std::cout<<Suv<<std::endl;
                std::cout<<"Svu"<<std::endl;
                std::cout<<Svu<<std::endl;
                std::cout<<"Ws"<<std::endl;
                std::cout<<Ws<<std::endl;

                vec2 lambda=eigenvalue(Ws);

                std::cout<<"lambda"<<std::endl;
                std::cout<<lambda<<std::endl;

                float Ks=det(Ws);

                float Hs=(1.0f/2.0f)*(lambda[0]+lambda[1]);

                //vec4 courb=calcul_courbure_prof(a,b,h,u,v,ku,kv);
                vec4 courb = vec4(lambda[0],lambda[1],Ks,Hs);

                if(courb[3]<min)
                    min=courb[3];
                if (courb[3]>max)
                    max=courb[3];

                std::cout<<"ku"<<std::endl;
                std::cout<<ku<<"  "<<kv<<std::endl;

                std::cout<<"min"<<std::endl;
                std::cout<<min<<",,"<<max<<std::endl;

                surface.color(ku,kv) = {(courb[3]/(max-min))-min/(max-min),0.0f,0.0f};

            }
            else {
                surface.color(ku,kv)={1.0f,0.0f,0.0f};


            }

        }
    }

}


void scene::build_surface_boule()
{
    int const Nu=50;
    int const Nv=50;
            
    surface.set_plane_xy_unit(Nu,Nv);

    float const u_min = -M_PI;
    float const u_max = M_PI;
    float const v_min = -M_PI/2;
    float const v_max = M_PI/2;

    float const r = 1.0f;

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


            float const x = r*cos(u)*cos(v);
            float const y = r*sin(u)*cos(v);
            float const z = r*sin(v);
            vec4 courb=calcul_courbure_boule(r,u,v,ku,kv);


            if(courb[3]<min)
                min=courb[3];
            if (courb[3]>max)
                max=courb[3];
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

            vec4 courb=calcul_courbure_boule(r,u,v,ku,kv);
        std::cout<<min<<",,"<<max<<std::endl;

            surface.color(ku,kv) = {(courb[3]/(max-min))-min/(max-min),0.0f,0.0f};
        }
    }

}


void scene::build_surface_boule_automatique()
{
    int const Nu=50;
    int const Nv=50;
            
    surface.set_plane_xy_unit(Nu,Nv);

    float const u_min = -M_PI;
    float const u_max = M_PI;
    float const v_min = -M_PI/2;
    float const v_max = M_PI/2;


    float min=+1000.0f;
    float max=-1000.0f;


    float const r = 1;


    for(int ku=0 ; ku<Nu ; ++ku)
    {
        for(int kv=0 ; kv<Nv ; ++kv)
        {
            float const u_n = static_cast<float>(ku)/(Nu-1);
            float const v_n = static_cast<float>(kv)/(Nv-1);

            float const pas_u = (u_max-u_min)/(Nu-1);
            float const pas_v = (v_max-v_min)/(Nv-1);



            float const u = u_min + u_n * (u_max-u_min);
            float const v = v_min + v_n * (v_max-v_min);


            // float const x = a*u;
            // float const y = b*v;
            // float const z = h*(u*u-v*v);

            if ((ku != 0) && (ku != Nu-1) && (kv != 0) && (kv != Nv-1)) {

            

                float const dxu = ((x_boule(ku+1,kv) - x_boule(ku,kv))/pas_u);
                float const dyu = ((y_boule(ku+1,kv) - y_boule(ku,kv))/pas_u);
                float const dzu = ((z_boule(ku+1,kv) - z_boule(ku,kv))/pas_u);

                vec3 Su=vec3(dxu,dyu,dzu);

                float const dxv = ((x_boule(ku,kv+1) - x_boule(ku,kv))/pas_u);
                float const dyv = ((y_boule(ku,kv+1) - y_boule(ku,kv))/pas_u);
                float const dzv = ((z_boule(ku,kv+1) - z_boule(ku,kv))/pas_u);

                vec3 Sv=vec3(dxv,dyv,dzv);

                float const dxuu = (x_boule(ku+1,kv) - 2*x_boule(ku,kv) + x_boule(ku-1,kv)) / (pas_u*pas_u);
                float const dyuu = (y_boule(ku+1,kv) - 2*y_boule(ku,kv) + y_boule(ku-1,kv)) / (pas_u*pas_u);
                float const dzuu = (z_boule(ku+1,kv) - 2*z_boule(ku,kv) + z_boule(ku-1,kv)) / (pas_u*pas_u);

                vec3 Suu=vec3(dxuu,dyuu,dzuu);

                float const dxuv = ((((x_boule(ku+1,kv+1) - x_boule(ku,kv+1)) / (pas_u)) - ((x_boule(ku+1,kv) - x_boule(ku,kv)) / ((pas_u)))) / (pas_v));
                float const dyuv = ((((y_boule(ku+1,kv+1) - y_boule(ku,kv+1)) / (pas_u)) - ((y_boule(ku+1,kv) - y_boule(ku,kv)) / ((pas_u)))) / (pas_v));
                float const dzuv = ((((z_boule(ku+1,kv+1) - z_boule(ku,kv+1)) / (pas_u)) - ((z_boule(ku+1,kv) - z_boule(ku,kv)) / ((pas_u)))) / (pas_v));

                vec3 Suv=vec3(dxuv,dyuv,dzuv);

                float const dxvv = (x_boule(ku,kv+1) - 2* x_boule(ku,kv) + x_boule(ku,kv-1)) / (pas_v*pas_v);
                float const dyvv = (y_boule(ku,kv+1) - 2* y_boule(ku,kv) + y_boule(ku,kv-1)) / (pas_v*pas_v);
                float const dzvv = (z_boule(ku,kv+1) - 2* z_boule(ku,kv) + z_boule(ku,kv-1)) / (pas_v*pas_v);

                vec3 Svv=vec3(dxvv,dyvv,dzvv);

                float const dxvu = ((((x_boule(ku+1,kv+1) - x_boule(ku+1,kv)) / (pas_v)) - ((x_boule(ku,kv+1) - x_boule(ku,kv)) / ((pas_v)))) / (pas_u));
                float const dyvu = ((((y_boule(ku+1,kv+1) - y_boule(ku+1,kv)) / (pas_v)) - ((y_boule(ku,kv+1) - y_boule(ku,kv)) / ((pas_v)))) / (pas_u));
                float const dzvu = ((((z_boule(ku+1,kv+1) - z_boule(ku+1,kv)) / (pas_v)) - ((z_boule(ku,kv+1) - z_boule(ku,kv)) / ((pas_v)))) / (pas_u));


                vec3 Svu=vec3(dxvu,dyvu,dzvu);

                mat2 Is=mat2(dot(Su,Su),-dot(Su,Sv),
                             -dot(Sv,Su),dot(Sv,Sv));

                mat2 IIs=mat2(-dot(cross(Su,Sv),Suu),-dot(cross(Su,Sv),Suv),
                              -dot(cross(Su,Sv),Suv),dot(cross(Su,Sv),Svv));

                mat2 Ws=IIs*inverse(Is);


                std::cout<<"Su"<<std::endl;
                std::cout<<Su<<std::endl;
                std::cout<<"Sv"<<std::endl;
                std::cout<<Sv<<std::endl;
                std::cout<<"Suu"<<std::endl;
                std::cout<<Suu<<std::endl;
                std::cout<<"Svv"<<std::endl;
                std::cout<<Svv<<std::endl;
                std::cout<<"Suv"<<std::endl;
                std::cout<<Suv<<std::endl;
                std::cout<<"Svu"<<std::endl;
                std::cout<<Svu<<std::endl;
                std::cout<<"Ws"<<std::endl;
                std::cout<<Ws<<std::endl;

                vec2 lambda=eigenvalue(Ws);

                std::cout<<"lambda"<<std::endl;
                std::cout<<lambda<<std::endl;

                float Ks=det(Ws);

                float Hs=(1.0f/2.0f)*(lambda[0]+lambda[1]);

                //vec4 courb=calcul_courbure_prof(a,b,h,u,v,ku,kv);
                vec4 courb = vec4(lambda[0],lambda[1],Ks,Hs);

                if(courb[3]<min)
                    min=courb[3];
                if (courb[3]>max)
                    max=courb[3];

                std::cout<<"ku"<<std::endl;
                std::cout<<ku<<"  "<<kv<<std::endl;

                std::cout<<"min"<<std::endl;
                std::cout<<min<<",,"<<max<<std::endl;

            

            }

        surface.vertex(ku,kv) = {x_boule(ku,kv),y_boule(ku,kv),z_boule(ku,kv)};


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

            float const pas_u = (u_max-u_min)/(Nu-1);
            float const pas_v = (v_max-v_min)/(Nv-1);

            if ((ku != 0) && (ku != Nu-1) && (kv != 0) && (kv != Nv-1)) {

            


                float const dxu = ((x_boule(ku+1,kv) - x_boule(ku,kv))/pas_u);
                float const dyu = ((y_boule(ku+1,kv) - y_boule(ku,kv))/pas_u);
                float const dzu = ((z_boule(ku+1,kv) - z_boule(ku,kv))/pas_u);

                vec3 Su=vec3(dxu,dyu,dzu);

                float const dxv = ((x_boule(ku,kv+1) - x_boule(ku,kv))/pas_u);
                float const dyv = ((y_boule(ku,kv+1) - y_boule(ku,kv))/pas_u);
                float const dzv = ((z_boule(ku,kv+1) - z_boule(ku,kv))/pas_u);

                vec3 Sv=vec3(dxv,dyv,dzv);

                float const dxuu = (x_boule(ku+1,kv) - 2*x_boule(ku,kv) + x_boule(ku-1,kv)) / (pas_u*pas_u);
                float const dyuu = (y_boule(ku+1,kv) - 2*y_boule(ku,kv) + y_boule(ku-1,kv)) / (pas_u*pas_u);
                float const dzuu = (z_boule(ku+1,kv) - 2*z_boule(ku,kv) + z_boule(ku-1,kv)) / (pas_u*pas_u);

                vec3 Suu=vec3(dxuu,dyuu,dzuu);

                float const dxuv = ((((x_boule(ku+1,kv+1) - x_boule(ku,kv+1)) / (pas_u)) - ((x_boule(ku+1,kv) - x_boule(ku,kv)) / ((pas_u)))) / (pas_v));
                float const dyuv = ((((y_boule(ku+1,kv+1) - y_boule(ku,kv+1)) / (pas_u)) - ((y_boule(ku+1,kv) - y_boule(ku,kv)) / ((pas_u)))) / (pas_v));
                float const dzuv = ((((z_boule(ku+1,kv+1) - z_boule(ku,kv+1)) / (pas_u)) - ((z_boule(ku+1,kv) - z_boule(ku,kv)) / ((pas_u)))) / (pas_v));

                vec3 Suv=vec3(dxuv,dyuv,dzuv);

                float const dxvv = (x_boule(ku,kv+1) - 2* x_boule(ku,kv) + x_boule(ku,kv-1)) / (pas_v*pas_v);
                float const dyvv = (y_boule(ku,kv+1) - 2* y_boule(ku,kv) + y_boule(ku,kv-1)) / (pas_v*pas_v);
                float const dzvv = (z_boule(ku,kv+1) - 2* z_boule(ku,kv) + z_boule(ku,kv-1)) / (pas_v*pas_v);

                vec3 Svv=vec3(dxvv,dyvv,dzvv);

                float const dxvu = ((((x_boule(ku+1,kv+1) - x_boule(ku+1,kv)) / (pas_v)) - ((x_boule(ku,kv+1) - x_boule(ku,kv)) / ((pas_v)))) / (pas_u));
                float const dyvu = ((((y_boule(ku+1,kv+1) - y_boule(ku+1,kv)) / (pas_v)) - ((y_boule(ku,kv+1) - y_boule(ku,kv)) / ((pas_v)))) / (pas_u));
                float const dzvu = ((((z_boule(ku+1,kv+1) - z_boule(ku+1,kv)) / (pas_v)) - ((z_boule(ku,kv+1) - z_boule(ku,kv)) / ((pas_v)))) / (pas_u));


                vec3 Svu=vec3(dxvu,dyvu,dzvu);

                mat2 Is=mat2(dot(Su,Su),-dot(Su,Sv),
                             -dot(Sv,Su),dot(Sv,Sv));

                std::cout<<"Is"<<std::endl;
                std::cout<<Is<<std::endl;

                mat2 IIs=mat2((- dot(cross(Su,Sv),Suu)),(- dot(cross(Su,Sv),Suv)),
                              (- dot(cross(Su,Sv),Suv)),(- dot(cross(Su,Sv),Svv)));
                std::cout<<"IIs"<<std::endl;
                std::cout<<IIs<<std::endl;


                mat2 Ws=IIs*inverse(Is);


                std::cout<<"Su"<<std::endl;
                std::cout<<Su<<std::endl;
                std::cout<<"Sv"<<std::endl;
                std::cout<<Sv<<std::endl;
                std::cout<<"Suu"<<std::endl;
                std::cout<<Suu<<std::endl;
                std::cout<<"Svv"<<std::endl;
                std::cout<<Svv<<std::endl;
                std::cout<<"Suv"<<std::endl;
                std::cout<<Suv<<std::endl;
                std::cout<<"Svu"<<std::endl;
                std::cout<<Svu<<std::endl;
                std::cout<<"Ws"<<std::endl;
                std::cout<<Ws<<std::endl;

                vec2 lambda=eigenvalue(Ws);

                std::cout<<"lambda"<<std::endl;
                std::cout<<lambda<<std::endl;

                float Ks=det(Ws);

                float Hs=(1.0f/2.0f)*(lambda[0]+lambda[1]);

                //vec4 courb=calcul_courbure_prof(a,b,h,u,v,ku,kv);
                vec4 courb = vec4(lambda[0],lambda[1],Ks,Hs);

                if(courb[3]<min)
                    min=courb[3];
                if (courb[3]>max)
                    max=courb[3];

                std::cout<<"ku"<<std::endl;
                std::cout<<ku<<"  "<<kv<<std::endl;

                std::cout<<"min"<<std::endl;
                std::cout<<min<<",,"<<max<<std::endl;

                surface.color(ku,kv) = {(courb[3]/(max-min))-min/(max-min),0.0f,0.0f};

            }
            else {
                surface.color(ku,kv)={0.8f,0.0f,0.0f}; 


            }

        }
    }

}

void scene::build_catenoide()
{
    int const Nu=50;
    int const Nv=50;
            
    surface.set_plane_xy_unit(Nu,Nv);

    float const u_min = -M_PI;
    float const u_max = M_PI;
    float const v_min = -M_PI/2;
    float const v_max = M_PI/2;

    float const r = 1;

    float min=+1000.0f;
    float max=-1000.0f;





    for(int ku=0 ; ku<Nu ; ++ku)
    {
        for(int kv=0 ; kv<Nv ; ++kv)
        {
            float const u_n = static_cast<float>(ku)/(Nu-1);
            float const v_n = static_cast<float>(kv)/(Nv-1);

            float const pas_u = (u_max-u_min)/(Nu-1);
            float const pas_v = (v_max-v_min)/(Nv-1);



            float const u = u_min + u_n * (u_max-u_min);
            float const v = v_min + v_n * (v_max-v_min);


            if ((ku != 0) && (ku != Nu-1) && (kv != 0) && (kv != Nv-1)) {


                vec4 courb=calcul_courbure_catenoide_automatique(u,v,ku,kv);


                if(courb[3]<min)
                    min=courb[3];
                if (courb[3]>max)
                    max=courb[3];

                std::cout<<"ku"<<std::endl;
                std::cout<<ku<<"  "<<kv<<std::endl;

                std::cout<<"min"<<std::endl;
                std::cout<<min<<",,"<<max<<std::endl;

            

            }

        surface.vertex(ku,kv) = {x_catenoide(ku,kv),y_catenoide(ku,kv),z_catenoide(ku,kv)};


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

            float const pas_u = (u_max-u_min)/(Nu-1);
            float const pas_v = (v_max-v_min)/(Nv-1);

            if ((ku != 0) && (ku != Nu-1) && (kv != 0) && (kv != Nv-1)) {

            

                vec4 courb=calcul_courbure_catenoide_automatique(u,v,ku,kv);

                if(courb[3]<min)
                    min=courb[3];
                if (courb[3]>max)
                    max=courb[3];

                std::cout<<"ku"<<std::endl;
                std::cout<<ku<<"  "<<kv<<std::endl;

                std::cout<<"min"<<std::endl;
                std::cout<<min<<",,"<<max<<std::endl;

                surface.color(ku,kv) = {(courb[3]/(max-min))-min/(max-min),0.0f,0.0f};

            }
            else {
                surface.color(ku,kv)={0.8f,0.0f,0.0f};


            }

        }
    }

}

void scene::build_surface_catenoide()
{
    int const Nu=50;
    int const Nv=50;
            
    surface.set_plane_xy_unit(Nu,Nv);

    float const u_min = -1.5f;
    float const u_max = 1.5f;
    float const v_min = 0.0f;
    float const v_max = 2.0*M_PI;

    float const r = 1.0f;

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


            float const x = r*cosh(u)*cos(v);
            float const y = r*cosh(u)*sin(v);
            float const z = r*u;
            vec4 courb=calcul_courbure_catenoide(r,u,v,ku,kv);


            if(courb[3]<min)
                min=courb[3];
            if (courb[3]>max)
                max=courb[3];
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

            vec4 courb=calcul_courbure_catenoide(r,u,v,ku,kv);
        std::cout<<min<<",,"<<max<<std::endl;

            surface.color(ku,kv) = {(courb[3]/(max-min))-min/(max-min),0.0f,0.0f};
        }
    }

}


void scene::load_scene()
{
    load_common_data();


    //build_surface_cylindre();
    build_surface_prof_automatique();
    //build_surface_prof();
    //build_surface_boule();
    //void build_surface_boule_automatique();
    //build_catenoide();
    //build_surface_catenoide();

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
    mat2 IIs=mat2(-dot(cross(Su,Sv),Suu),-dot(cross(Su,Sv),Suv),
                  -dot(cross(Su,Sv),Suv),-dot(cross(Su,Sv),Svv));
    mat2 Ws=IIs*inverse(Is);
    vec2 lambda=eigenvalue(Ws);
    float Ks=det(Ws);
    float Hs=(1.0f/2.0f)*(lambda[0]+lambda[1]);
    std::cout<<lambda[0]<<" "<<lambda[1]<<" "<<Ks<<" "<<Hs<<std::endl;
    return vec4(lambda[0],lambda[1],Ks,Hs);
}



vec4 scene::calcul_courbure_catenoide_automatique(float u, float v, int ku, int kv)
{

    int const Nu=50;
    int const Nv=50;

    float const u_min = -M_PI;
    float const u_max = M_PI;
    float const v_min = -M_PI/2;
    float const v_max = M_PI/2;

    float const r = 1;


    float const pas_u = (u_max-u_min)/(Nu-1);
    float const pas_v = (v_max-v_min)/(Nv-1);


    float const dxu = ((x_catenoide(ku+1,kv) - x_catenoide(ku,kv))/pas_u);
    float const dyu = ((y_catenoide(ku+1,kv) - y_catenoide(ku,kv))/pas_u);
    float const dzu = ((z_catenoide(ku+1,kv) - z_catenoide(ku,kv))/pas_u);

    vec3 Su=vec3(dxu,dyu,dzu);

    float const dxv = ((x_catenoide(ku,kv+1) - x_catenoide(ku,kv))/pas_u);
    float const dyv = ((y_catenoide(ku,kv+1) - y_catenoide(ku,kv))/pas_u);
    float const dzv = ((z_catenoide(ku,kv+1) - z_catenoide(ku,kv))/pas_u);

    vec3 Sv=vec3(dxv,dyv,dzv);

    float const dxuu = (x_catenoide(ku+1,kv) - 2*x_catenoide(ku,kv) + x_catenoide(ku-1,kv)) / (pas_u*pas_u);
    float const dyuu = (y_catenoide(ku+1,kv) - 2*y_catenoide(ku,kv) + y_catenoide(ku-1,kv)) / (pas_u*pas_u);
    float const dzuu = (z_catenoide(ku+1,kv) - 2*z_catenoide(ku,kv) + z_catenoide(ku-1,kv)) / (pas_u*pas_u);

    vec3 Suu=vec3(dxuu,dyuu,dzuu);

    float const dxuv = ((((x_catenoide(ku+1,kv+1) - x_catenoide(ku,kv+1)) / (pas_u)) - ((x_catenoide(ku+1,kv) - x_catenoide(ku,kv)) / ((pas_u)))) / (pas_v));
    float const dyuv = ((((y_catenoide(ku+1,kv+1) - y_catenoide(ku,kv+1)) / (pas_u)) - ((y_catenoide(ku+1,kv) - y_catenoide(ku,kv)) / ((pas_u)))) / (pas_v));
    float const dzuv = ((((z_catenoide(ku+1,kv+1) - z_catenoide(ku,kv+1)) / (pas_u)) - ((z_catenoide(ku+1,kv) - z_catenoide(ku,kv)) / ((pas_u)))) / (pas_v));

    vec3 Suv=vec3(dxuv,dyuv,dzuv);

    float const dxvv = (x_catenoide(ku,kv+1) - 2* x_catenoide(ku,kv) + x_catenoide(ku,kv-1)) / (pas_v*pas_v);
    float const dyvv = (y_catenoide(ku,kv+1) - 2* y_catenoide(ku,kv) + y_catenoide(ku,kv-1)) / (pas_v*pas_v);
    float const dzvv = (z_catenoide(ku,kv+1) - 2* z_catenoide(ku,kv) + z_catenoide(ku,kv-1)) / (pas_v*pas_v);

    vec3 Svv=vec3(dxvv,dyvv,dzvv);

    float const dxvu = ((((x_catenoide(ku+1,kv+1) - x_catenoide(ku+1,kv)) / (pas_v)) - ((x_catenoide(ku,kv+1) - x_catenoide(ku,kv)) / ((pas_v)))) / (pas_u));
    float const dyvu = ((((y_catenoide(ku+1,kv+1) - y_catenoide(ku+1,kv)) / (pas_v)) - ((y_catenoide(ku,kv+1) - y_catenoide(ku,kv)) / ((pas_v)))) / (pas_u));
    float const dzvu = ((((z_catenoide(ku+1,kv+1) - z_catenoide(ku+1,kv)) / (pas_v)) - ((z_catenoide(ku,kv+1) - z_catenoide(ku,kv)) / ((pas_v)))) / (pas_u));



    vec3 Svu=vec3(dxvu,dyvu,dzvu);

    mat2 Is=mat2(dot(Su,Su),dot(Su,Sv),
                 dot(Su,Sv),dot(Sv,Sv));

    std::cout<<"Is"<<std::endl;
    std::cout<<Is<<std::endl;

    mat2 IIs=mat2((- dot(cross(Su,Sv),Suu)),(- dot(cross(Su,Sv),Suv)),
                  (- dot(cross(Su,Sv),Suv)),(- dot(cross(Su,Sv),Svv)));
    std::cout<<"IIs"<<std::endl;
    std::cout<<IIs<<std::endl;


    mat2 Ws=IIs*inverse(Is);


    std::cout<<"Su"<<std::endl;
    std::cout<<Su<<std::endl;
    std::cout<<"Sv"<<std::endl;
    std::cout<<Sv<<std::endl;
    std::cout<<"Suu"<<std::endl;
    std::cout<<Suu<<std::endl;
    std::cout<<"Svv"<<std::endl;
    std::cout<<Svv<<std::endl;
    std::cout<<"Suv"<<std::endl;
    std::cout<<Suv<<std::endl;
    std::cout<<"Svu"<<std::endl;
    std::cout<<Svu<<std::endl;
    std::cout<<"Ws"<<std::endl;
    std::cout<<Ws<<std::endl;

    vec2 lambda=eigenvalue(Ws);

    std::cout<<"lambda"<<std::endl;
    std::cout<<lambda<<std::endl;

    float Ks=det(Ws);

    float Hs=(1.0f/2.0f)*(lambda[0]+lambda[1]);
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
    mat2 IIs=mat2(-dot(cross(Su,Sv),Suu),-dot(cross(Su,Sv),Suv),
                  -dot(cross(Su,Sv),Suv),-dot(cross(Su,Sv),Svv));
    mat2 Ws=IIs*inverse(Is);
    std::cout<<"Ws"<<std::endl;
    std::cout<<Ws<<std::endl;
    vec2 lambda=eigenvalue(Ws);
    std::cout<<"lambda"<<std::endl;
    std::cout<<lambda<<std::endl;
    float Ks=det(Ws);
    float Hs=(1.0f/2.0f)*(lambda[0]+lambda[1]);
    //std::cout<<lambda[0]<<" "<<lambda[1]<<" "<<Ks<<" "<<Hs<<std::endl;
    return vec4(lambda[0],lambda[1],Ks,Hs);
}



vec4 scene::calcul_courbure_boule(float r, float u, float v, int ku, int kv)
{
    vec3 Su=vec3(-r*sin(u)*cos(v),r*cos(u)*cos(v),0);

    vec3 Sv=vec3(-r*cos(u)*sin(v),-r*sin(u)*sin(v),r*cos(v));

    vec3 Suu=vec3(-r*cos(u)*cos(v),-r*sin(u)*cos(v),0);

    vec3 Suv=vec3(r*sin(u)*sin(v),-r*cos(u)*sin(v),0);

    vec3 Svu=vec3(r*sin(u)*sin(v),-r*cos(u)*sin(v),0);

    vec3 Svv=vec3(-r*cos(u)*cos(v),-r*sin(u)*cos(v),-r*sin(v));

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

vec4 scene::calcul_courbure_catenoide(float r, float u, float v, int ku, int kv)
{
    vec3 Su=vec3(r*sinh(u)*cos(v),r*sinh(u)*sin(v),r);

    vec3 Sv=vec3(-r*cosh(u)*sin(v),r*cosh(u)*cos(v),0);

    vec3 Suu=vec3(r*cosh(u)*cos(v),r*cosh(u)*sin(v),0);

    vec3 Suv=vec3(-r*sinh(u)*sin(v),r*sinh(u)*cos(v),0);

    //vec3 Svu=vec3(-r*sinh(u)*sin(v),r*sinh(u)*cos(v),0);

    vec3 Svv=vec3(-r*cosh(u)*cos(v),-r*cosh(u)*sin(v),0);

    mat2 Is=mat2(dot(Su,Su),dot(Su,Sv),
                 dot(Sv,Su),dot(Sv,Sv));
    mat2 IIs=mat2(-dot(cross(Su,Sv),Suu),-dot(cross(Su,Sv),Suv),
                  -dot(cross(Su,Sv),Suv),-dot(cross(Su,Sv),Svv));
    mat2 Ws=IIs*inverse(Is);
    vec2 lambda=eigenvalue(Ws);
    float Ks=det(Ws);
    float Hs=(1.0f/2.0f)*(lambda[0]+lambda[1]);
    std::cout<<lambda[0]<<" "<<lambda[1]<<" "<<Ks<<" "<<Hs<<std::endl;
    return vec4(lambda[0],lambda[1],Ks,Hs);
}

